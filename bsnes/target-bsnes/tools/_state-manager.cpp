#include <nall/encode/bmp.hpp>

auto StateWindow::create() -> void {
	layout.setPadding(5_sx);
	nameLabel.setText({bms::get("Common.Name").data(), ':'});

	nameValue.onActivate([&] {
		if (acceptButton.enabled()) {
			acceptButton.doActivate();
		}
	});

	nameValue.onChange([&] {
		doChange();
	});

	acceptButton.onActivate([&] {
		doAccept();
	});

	cancelButton.setText(bms::get("Common.Cancel").data()).onActivate([&] {
		setVisible(false);
	});

	setSize({400_sx, layout.minimumSize().height()});
	setDismissable();
}

auto StateWindow::show(string name) -> void {
	setAttribute("type", {name.split("/").first(), "/"});
	setAttribute("name", {name.split("/").last()});
	nameValue.setText(attribute("name"));
	doChange();
	setTitle(!attribute("name") ? bms::get("Tools.StateManager.AddState").data() : bms::get("Tools.StateManager.RenameState").data());
	setAlignment(*toolsWindow);
	setVisible();
	setFocused();
	nameValue.setFocused();
	acceptButton.setText(!attribute("name") ? bms::get("Common.Add").data() : bms::get("Common.Rename").data());
}

auto StateWindow::doChange() -> void {
	auto name  = nameValue.text().strip();
	bool valid = name && !name.contains("\\\"\t/:*?<>|");

	if (attribute("name") && name != attribute("name")) {
		//don't allow a state to be renamed to the same name as an existing state (as this would overwrite it)
		if (program.hasState({attribute("type"), name})) {
			valid = false;
		}
	}

	nameValue.setBackgroundColor(valid ? Color{} : Color{255, 224, 224});
	acceptButton.setEnabled(valid);
}

auto StateWindow::doAccept() -> void {
	string name = {attribute("type"), nameValue.text().strip()};

	if (acceptButton.text() == bms::get("Common.Add").data()) {
		stateManager.createState(name);
	}
	else {
		stateManager.modifyState(name);
	}

	setVisible(false);
}

auto StateManager::create() -> void {
	setCollapsible();
	setVisible(false);

	stateLayout.setAlignment(0.0);
	stateList.setBatchable();
	stateList.setHeadered();
	stateList.setSortable();

	stateList.onActivate([&](auto cell) {
		loadButton.doActivate();
	});

	stateList.onChange([&] {
		updateSelection();
	});

	stateList.onSort([&](TableViewColumn column) {
		column.setSorting(column.sorting() == Sort::Ascending ? Sort::Descending : Sort::Ascending);
		stateList.sort();
	});

	stateList.onSize([&] {
		stateList.resizeColumns();
	});

	categoryLabel.setText({bms::get("Tools.StateManager.Category").data(), ':'});

	auto managedItem = ComboButtonItem().setText(bms::get("Tools.StateManager.Category.ManagedStates").data())
	                                    .setAttribute("type", "Managed/");

	auto quickItem   = ComboButtonItem().setText(bms::get("Tools.StateManager.Category.QuickStates").data())
	                                    .setAttribute("type", "Quick/");

	categoryOption.append(managedItem);
	categoryOption.append(quickItem);

	categoryOption.onChange([&] {
		loadStates();
	});

	Color separatorColor = {192, 192, 192}; // MT.

	statePreviewSeparator1.setColor(separatorColor);
	statePreviewLabel.setFont(Font().setBold()).setText(bms::get("Tools.StateManager.Preview").data());
	statePreviewSeparator2.setColor(separatorColor);

	loadButton.setText(bms::get("Common.Load").data()).onActivate([&] {
		if (auto item = stateList.selected()) {
			program.loadState(item.attribute("name"));
		}
	});

	saveButton.setText(bms::get("Common.Save").data()).onActivate([&] {
		if (auto item = stateList.selected()) {
			program.saveState(item.attribute("name"));
		}
	});

	addButton.setText(bms::get("Common.Add").data()).onActivate([&] {
		stateWindow.show(type());
	});

	editButton.setText(bms::get("Common.Rename").data()).onActivate([&] {
		if (auto item = stateList.selected()) {
			stateWindow.show(item.attribute("name"));
		}
	});

	removeButton.setText(bms::get("Common.Remove").data()).onActivate([&] {
		removeStates();
	});
}

auto StateManager::type() const -> string {
	return categoryOption.selected().attribute("type");
}

auto StateManager::loadStates() -> void {
	stateList.reset();
	stateList.append(TableViewColumn().setText(bms::get("Common.Name").data()).setSorting(Sort::Ascending).setExpandable());
	stateList.append(TableViewColumn().setText(bms::get("Common.Date").data()).setForegroundColor({160, 160, 160}));

	auto type = this->type();

	/* MT. */
	string redoTranslated = bms::get("Tools.StateManager.QuickStates.Redo").data();
	string undoTranslated = bms::get("Tools.StateManager.QuickStates.Undo").data();
	string slotTranslated = bms::get("Tools.SaveState.Slot").data();
	/* /MT. */

	for (auto& state : program.availableStates(type)) {
		TableViewItem item{&stateList};
		item.setAttribute("name", state.name);

		/* MT. */
		string stateName = state.name.trimLeft(type, 1L);

		if (type == "Quick/") {
			stateName = stateName == "Undo"
			          ? undoTranslated
			          : (stateName == "Redo" ? redoTranslated : stateName.replace("Slot", slotTranslated));
		}
		/* /MT. */

		item.append(TableViewCell().setText(stateName)); // `state.name.trimLeft(type, 1L)` => `stateName` by MT.
		item.append(TableViewCell().setText(chrono::local::datetime(state.date)));
	}

	stateList.resizeColumns().doChange();
}

auto StateManager::createState(string name) -> void {
	for (auto& item : stateList.items()) {
		item.setSelected(false);
	}

	program.saveState(name);

	for (auto& item : stateList.items()) {
		item.setSelected(item.attribute("name") == name);
	}

	stateList.doChange();
}

auto StateManager::modifyState(string name) -> void {
	if (auto item = stateList.selected()) {
		string from = item.attribute("name");
		string to   = name;

		if (from != to) {
			program.renameState(from, to);

			for (auto& item : stateList.items()) {
				item.setSelected(item.attribute("name") == to);
			}

			stateList.doChange();
		}
	}
}

auto StateManager::removeStates() -> void {
	if (auto batched = stateList.batched()) {
		/* // Commented-out by MT.
		if (MessageDialog(bms::get("Tools.StateManager.remove.confirm").data())
			.setAlignment(*toolsWindow).question({bms::get("Common.Yes").data(), bms::get("Common.No").data()}) == bms::get("Common.Yes").data()) {
		*/

		if (bmw::confirmById("Tools.StateManager.remove.confirm"), toolsWindow->handle()) { // MT.
			auto lock = acquire();

			for (auto& item : batched) {
				program.removeState(item.attribute("name"));
			}

			loadStates();
		}
	}
}

auto StateManager::updateSelection() -> void {
	auto batched  = stateList.batched();
	auto notQuick = type() != "Quick/"; // MT.

	statePreview.setVisible(batched.size() == 1);
	loadButton.setEnabled(batched.size() == 1);
	saveButton.setEnabled(batched.size() == 1);
	addButton.setVisible(notQuick);
	editButton.setEnabled(batched.size() == 1);
	editButton.setVisible(notQuick);
	removeButton.setEnabled(batched.size() >= 1);

	statePreview.setColor({0, 0, 0});

	if (batched.size() == 1) {
		if (auto saveState = program.loadStateData(batched.first().attribute("name"))) {
			if (saveState.size() >= 3 * sizeof(uint)) {
				uint signature  = memory::readl<sizeof(uint)>(saveState.data() + 0 * sizeof(uint));
				uint serializer = memory::readl<sizeof(uint)>(saveState.data() + 1 * sizeof(uint));
				uint preview    = memory::readl<sizeof(uint)>(saveState.data() + 2 * sizeof(uint));

				if (signature == Program::State::Signature && preview) {
					uint offset  = 3 * sizeof(uint) + serializer;
					auto preview = Decode::RLE<2>({saveState.data() + offset, max(offset, saveState.size()) - offset});

					image icon{0, 16, 0x8000, 0x7c00, 0x03e0, 0x001f};

					icon.copy(preview.data(), 256 * sizeof(uint16_t), 256, 240);
					icon.transform();

					//restore the missing alpha channel
					for (uint y : range(icon.height())) {
						auto data = icon.data() + y * icon.pitch();

						for (uint x : range(icon.width())) {
							auto pixel = icon.read(data);
							icon.write(data, 0xff000000 | pixel);
							data += icon.stride();
						}
					}

					statePreview.setIcon(icon);
				}
			}
		}
	}
}

auto StateManager::stateEvent(string name) -> void {
	if (locked() || !name.beginsWith(type())) {
		return;
	}

	auto selected = stateList.selected().attribute("name");
	loadStates();

	for (auto& item : stateList.items()) {
		item.setSelected(item.attribute("name") == selected);
	}

	stateList.doChange();
}