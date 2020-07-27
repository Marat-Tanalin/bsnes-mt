/* MT. */
#include "bsnes-mt/strings.h"

namespace bms = bsnesMt::strings;
/* /MT. */

auto HotkeySettings::create() -> void {
	setCollapsible();
	setVisible(false);

	mappingList.setBatchable();
	mappingList.setHeadered();
	mappingList.onActivate([&](auto cell) { assignMapping(cell); });

	mappingList.onChange([&] {
		auto batched = mappingList.batched();
		assignButton.setEnabled(batched.size() == 1);
		clearButton.setEnabled(batched.size() >= 1);
	});

	mappingList.onSize([&] {
		mappingList.resizeColumns();
	});

	logicLabel.setText({bms::get("Settings.Hotkeys.CombinationalLogic").data(), ':'}).setToolTip( // "Combinational logic:"
		bms::get("Settings.Hotkeys.CombinationalLogic.tooltip").data()
	);

	logicAND.setText(bms::get("Settings.Hotkeys.CombinationalLogic.And").data()).setToolTip( // "And"
		bms::get("Settings.Hotkeys.CombinationalLogic.And.tooltip").data() // "Every mapping must be pressed to activate a given hotkey."
	).onActivate([&] {
		settings.input.hotkey.logic = "and";
		inputManager.hotkeyLogic = InputMapping::Logic::AND;
	});

	logicOR.setText(bms::get("Settings.Hotkeys.CombinationalLogic.Or").data()).setToolTip(
		bms::get("Settings.Hotkeys.CombinationalLogic.Or.tooltip").data() // "Any mapping can be pressed to activate a given hotkey."
	).onActivate([&] { // "Or"
		settings.input.hotkey.logic = "or";
		inputManager.hotkeyLogic = InputMapping::Logic::OR;
	});

	auto logic = settings.input.hotkey.logic; // MT.

	if (logic == "and") {
		logicAND.setChecked().doActivate();
	}
	else if (logic == "or") {
		logicOR.setChecked().doActivate();
	}

	inputSink.setFocusable();

	assignButton.setText(bms::get("Settings.Common.Assign").data()).onActivate([&] { // "Assign"
		clearButton.doActivate();
		assignMapping(mappingList.selected().cell(0));
	});

	clearButton.setText(bms::get("Common.Clear").data()).onActivate([&] { // "Clear"
		cancelMapping();

		for (auto mapping : mappingList.batched()) {
			auto& hotkey = inputManager.hotkeys[mapping.offset()];

			for (uint index : range(BindingLimit)) {
				hotkey.unbind(index);
			}
		}

		refreshMappings();
	});
}

auto HotkeySettings::reloadMappings() -> void {
	mappingList.reset();
	mappingList.append(TableViewColumn().setText(bms::get("Common.Name").data())); // "Name"

	/* MT. */
	char space = ' ';
	string mappingTextPrefix = {bms::get("Settings.Common.Mapping").data(), space, bms::get("Common.number").data(), space};
	/* /MT. */

	for (uint index : range(BindingLimit)) {
		mappingList.append(TableViewColumn().setText({mappingTextPrefix, 1 + index}).setExpandable()); // Mapping
	}

	for (auto& hotkey : inputManager.hotkeys) {
		TableViewItem item{&mappingList};
		item.append(TableViewCell().setText(bms::getHotkeyString(hotkey.name.data()).data()).setFont(Font().setBold())); // hotkey.name

		for (uint index : range(BindingLimit)) {
			item.append(TableViewCell());
		}
	}

	refreshMappings();
	mappingList.doChange();
}

auto HotkeySettings::refreshMappings() -> void {
	uint item = 0;

	for (auto& hotkey : inputManager.hotkeys) {
		for (uint index : range(BindingLimit)) {
			auto cell = mappingList.item(item).cell(1 + index);
			auto& binding = hotkey.bindings[index];
			cell.setIcon(binding.icon());
			cell.setText(binding.name());
		}

		item++;
	}

	Application::processEvents();
	mappingList.resizeColumns();
}

auto HotkeySettings::assignMapping(TableViewCell cell) -> void {
	inputManager.poll();  //clear any pending events first

	/* MT. */
	char space = ' ';
	string statusPrefix   = {bms::get("Settings.Common.PressKeyOrButtonForMapping").data(), space, bms::get("Common.number").data(), space};
	string awaitingString = {"(", bms::get("Settings.Common.AssignLowercase").data(), " ...)"};
	/* /MT. */

	for (auto mapping : mappingList.batched()) {
		activeMapping = inputManager.hotkeys[mapping.offset()];
		activeBinding = max(0, (int)cell.offset() - 1);
		mappingList.item(mapping.offset()).cell(1 + activeBinding).setIcon(Icon::Go::Right).setText(awaitingString); // "(assign ...)"
		settingsWindow.statusBar.setText({statusPrefix, 1 + activeBinding, " [", activeMapping->name, "] ..."}); // "Press a key or button for mapping# "
		settingsWindow.setDismissable(false);
		inputSink.setFocused();
		return; //map only one input at a time
	}
}

auto HotkeySettings::cancelMapping() -> void {
	activeMapping.reset();
	settingsWindow.statusBar.setText();
	settingsWindow.doSize();
	settingsWindow.setDismissable(true);
	mappingList.setFocused();
}

auto HotkeySettings::inputEvent(shared_pointer<HID::Device> device, uint group, uint input, int16 oldValue, int16 newValue) -> void {
	if (!activeMapping || device->isMouse()) {
		return;
	}

	if (activeMapping->bind(device, group, input, oldValue, newValue, activeBinding)) {
		activeMapping.reset();
		settingsWindow.statusBar.setText(bms::get("Settings.Common.MappingAssigned").data()); // "Mapping assigned."
		refreshMappings();

		timer.onActivate([&] {
			timer.setEnabled(false);
			cancelMapping();
		}).setInterval(200).setEnabled();
	}
}