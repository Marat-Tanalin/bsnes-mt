/* MT. */
#include "bsnes-mt/translations.h"

namespace bmt = bsnesMt::translations;
/* /MT. */

auto InputSettings::create() -> void {
	setCollapsible();
	setVisible(false);

	char colon = ':';

	inputFocusLabel.setText({bmt::get("Settings.Input.WhenFocusIsLost").data(), colon});

	pauseEmulation.setText(bmt::get("Settings.Input.WhenFocusIsLost.PauseEmulation").data()).onActivate([&] {
		settings.input.defocus = "Pause";
	});

	blockInput.setText(bmt::get("Settings.Input.WhenFocusIsLost.BlockInput").data()).onActivate([&] {
		settings.input.defocus = "Block";
	});

	allowInput.setText(bmt::get("Settings.Input.WhenFocusIsLost.AllowInput").data()).onActivate([&] {
		settings.input.defocus = "Allow";
	});

	auto defocus = settings.input.defocus;

	if (defocus == "Pause") {
		pauseEmulation.setChecked();
	}
	else if (defocus == "Block") {
		blockInput.setChecked();
	}
	else if (defocus == "Allow") {
		allowInput.setChecked();
	}

	separator.setColor({192, 192, 192});

	portLabel.setText({bmt::get("Settings.Input.Port").data(), colon});

	portList.onChange([&] {
		reloadDevices();
	});

	deviceLabel.setText({bmt::get("Settings.Input.Device").data(), colon});

	deviceList.onChange([&] {
		reloadMappings();
	});

	turboLabel.setText({bmt::get("Settings.Input.TurboRate").data(), colon})
		.setToolTip(bmt::get("Settings.Input.TurboRate.tooltip").data());

	for (uint frequency : range(1, 9)) {
		ComboButtonItem item{&turboList};
		item.setText(frequency);

		if (frequency == settings.input.turbo.frequency) {
			item.setSelected();
		}
	}

	turboList.setToolTip(turboLabel.toolTip()).onChange([&] {
		uint frequency = turboList.selected().text().natural();
		settings.input.turbo.frequency = frequency;
		inputManager.turboCounter = 0;
		inputManager.turboFrequency = frequency;
	});

	mappingList.setBatchable();
	mappingList.setHeadered();

	mappingList.onActivate([&](auto cell) {
		assignMapping(cell);
	});

	mappingList.onChange([&] {
		updateControls();
	});

	mappingList.onSize([&] {
		mappingList.resizeColumns();
	});

	inputSink.setFocusable();

	assignMouse1.onActivate([&] {
		assignMouseInput(0);
	});

	assignMouse2.onActivate([&] {
		assignMouseInput(1);
	});

	assignMouse3.onActivate([&] {
		assignMouseInput(2);
	});

	assignButton.setText(bmt::get("Settings.Common.Assign").data()).onActivate([&] {
		clearButton.doActivate();
		assignMapping(mappingList.selected().cell(0));
	});

	clearButton.setText(bmt::get("Common.Clear").data()).onActivate([&] {
		cancelMapping();

		for (auto mapping : mappingList.batched()) {
			for (uint index : range(BindingLimit)) {
				activeDevice().mappings[mapping.offset()].unbind(index);
			}
		}

		refreshMappings();
	});
}

auto InputSettings::updateControls() -> void {
	auto batched = mappingList.batched();
	assignButton.setEnabled(batched.size() == 1);
	clearButton.setEnabled(batched.size() >= 1);
	assignMouse1.setVisible(false);
	assignMouse2.setVisible(false);
	assignMouse3.setVisible(false);

	if (activeMapping) {
		auto& input = activeDevice().mappings[batched.left().offset()];

		if (input.isDigital()) {
			assignMouse1.setVisible().setText(bmt::get("Settings.Input.MouseLeft").data());
			assignMouse2.setVisible().setText(bmt::get("Settings.Input.MouseMiddle").data());
			assignMouse3.setVisible().setText(bmt::get("Settings.Input.MouseRight").data());
		}
		else if (input.isAnalog()) {
			assignMouse1.setVisible().setText(bmt::get("Settings.Input.MouseXAxis").data());
			assignMouse2.setVisible().setText(bmt::get("Settings.Input.MouseYAxis").data());
		}
	}

	controlLayout.resize();
}

auto InputSettings::activePort() -> InputPort& {
	return inputManager.ports[portList.selected().offset()];
}

auto InputSettings::activeDevice() -> InputDevice& {
	auto index = deviceList.selected().attribute("index").natural();
	return activePort().devices[index];
}

auto InputSettings::reloadPorts() -> void {
	portList.reset();

	for (auto& port : inputManager.ports) {
		if (port.name == "Expansion Port") {
			continue;
		}

		string portText;
		auto portName = port.name;

		if (portName == "Controller Port 1") {
			portText = {bmt::get("Menu.System.ControllerPort").data(), " 1"};
		}
		else if (portName == "Controller Port 2") {
			portText = {bmt::get("Menu.System.ControllerPort").data(), " 2"};
		}
		else {
			portText = bmt::getDeviceString(port.name.data()).data();
		}

		portList.append(ComboButtonItem().setText(portText));
	}

	reloadDevices();
}

auto InputSettings::reloadDevices() -> void {
	deviceList.reset();
	uint index = 0;

	for (auto& device : activePort().devices) {
		if (device.mappings) { // only display devices that have configurable inputs
			auto item = ComboButtonItem().setText(bmt::getDeviceString(device.name.data()).data())
			                             .setAttribute("index", index);

			deviceList.append(item);
		}

		index++;
	}

	reloadMappings();
}

auto InputSettings::reloadMappings() -> void {
	mappingList.reset();
	mappingList.append(TableViewColumn().setText(bmt::get("Common.Name").data()));

	/* MT. */
	char space = ' ';
	const string mappingTextPrefix = {bmt::get("Settings.Common.Mapping").data(), space, bmt::get("Common.number").data(), space};
	/* /MT. */

	for (uint n : range(BindingLimit)) {
		mappingList.append(TableViewColumn().setText({mappingTextPrefix, 1 + n}).setExpandable());
	}

	for (auto& mapping : activeDevice().mappings) {
		TableViewItem item{&mappingList};
		item.append(TableViewCell().setText(mapping.name).setFont(Font().setBold()));

		for (uint n : range(BindingLimit)) {
			item.append(TableViewCell());
		}
	}

	refreshMappings();

	/* MT. */
	if (activeMapping) {
		cancelMapping();
	}
	else {
	/* /MT. */
		updateControls();
	/* MT. */
	}
	/* /MT. */
}

auto InputSettings::refreshMappings() -> void {
	uint item = 0;

	for (auto& mapping : activeDevice().mappings) {
		for (uint index : range(BindingLimit)) {
			auto cell = mappingList.item(item).cell(1 + index);
			auto& binding = mapping.bindings[index];
			cell.setIcon(binding.icon());
			cell.setText(binding.name());
		}

		item++;
	}

	Application::processEvents();
	mappingList.resizeColumns();
}

auto InputSettings::assignMapping(TableViewCell cell) -> void {
	inputManager.poll();  //clear any pending events first

	/* MT. */
	char space = ' ';
	string statusPrefix   = {bmt::get("Settings.Common.PressKeyOrButtonForMapping").data(), space, bmt::get("Common.number").data(), space};
	string awaitingString = {"(", bmt::get("Settings.Common.AssignLowercase").data(), " ...)"};
	/* /MT. */

	for (auto mapping : mappingList.batched()) {
		activeMapping = activeDevice().mappings[mapping.offset()];
		activeBinding = max(0, (int)cell.offset() - 1);
		mappingList.item(mapping.offset()).cell(1 + activeBinding).setIcon(Icon::Go::Right).setText(awaitingString);
		settingsWindow.statusBar.setText({statusPrefix, 1 + activeBinding, " [", activeMapping->name, "] ..."});
		settingsWindow.setDismissable(false);
		updateControls();
		Application::processEvents();
		inputSink.setFocused();
		return;  //map only one input at a time
	}
}

auto InputSettings::cancelMapping() -> void {
	activeMapping.reset();
	settingsWindow.statusBar.setText();
	settingsWindow.doSize();
	settingsWindow.setDismissable(true);
	mappingList.setFocused();
	updateControls();
}

auto InputSettings::assignMouseInput(uint id) -> void {
	if (!activeMapping) {
		return;
	}

	if (auto mouse = inputManager.findMouse()) {
		if (activeMapping->isDigital()) {
			return inputEvent(mouse, HID::Mouse::GroupID::Button, id, 0, 1, true);
		}

		if (activeMapping->isAnalog()) {
			return inputEvent(mouse, HID::Mouse::GroupID::Axis, id, 0, +32767, true);
		}
	}
}

auto InputSettings::inputEvent(shared_pointer<HID::Device> device, uint group, uint input, int16 oldValue, int16 newValue, bool allowMouseInput) -> void {
	if (!activeMapping || device->isMouse() && !allowMouseInput) {
		return;
	}

	if (activeMapping->bind(device, group, input, oldValue, newValue, activeBinding)) {
		activeMapping.reset();
		settingsWindow.statusBar.setText(bmt::get("Settings.Common.MappingAssigned").data());
		refreshMappings();

		timer.onActivate([&] {
			timer.setEnabled(false);
			cancelMapping();
		}).setInterval(200).setEnabled();
	}
}