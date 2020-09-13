#include <algorithm>
#include <string>

namespace bms = bsnesMt::strings;

auto addMenuItemHotkey(std::string itemText, const std::string &hotkey) -> std::string {
	std::string tab   = "\t";
	std::string separ = ", ";

	auto tabPos = itemText.find(tab);
	auto hotkeysString = itemText.substr(tabPos + 1);

	if (hotkeysString == hotkey) {
		return itemText;
	}

	auto hotkeysItems = bms::split(hotkeysString, separ);

	if (bsnesMt::inArray(hotkeysItems, hotkey)) {
		return itemText;
	}

	return itemText + (std::string::npos == tabPos ? tab : separ) + hotkey;
}

auto addMenuItemHotkey(hiro::MenuItem &item, const std::string &hotkey) -> void {
	item.setText(addMenuItemHotkey(item.text().data(), hotkey).data());
}

auto addMenuItemHotkey(hiro::MenuRadioItem &item, const std::string &hotkey) -> void {
	item.setText(addMenuItemHotkey(item.text().data(), hotkey).data());
}

auto removeMenuItemHotkey(std::string itemText, const std::string &hotkey) -> std::string {
	std::string tab   = "\t";
	std::string separ = ", ";

	auto tabPos = itemText.find(tab);

	if (std::string::npos == tabPos) {
		return itemText;
	}

	auto hotkeysString = itemText.substr(tabPos + 1);
	auto hotkeysItems  = bms::split(hotkeysString, separ);
	auto hotkeyPos     = std::find(std::begin(hotkeysItems), std::end(hotkeysItems), hotkey);

	if (std::end(hotkeysItems) == hotkeyPos) {
		return itemText;
	}

	hotkeysItems.erase(hotkeyPos);
	hotkeysString = bms::join(hotkeysItems, separ);
	std::string trailing = hotkeysString.size() ? tab + hotkeysString : "";

	return itemText.substr(0, tabPos) + trailing;
}

auto removeMenuItemHotkey(hiro::MenuItem &item, const std::string &hotkey) -> void {
	item.setText(removeMenuItemHotkey(item.text().data(), hotkey).data());
}

auto removeMenuItemHotkey(hiro::MenuRadioItem &item, const std::string &hotkey) -> void {
	item.setText(removeMenuItemHotkey(item.text().data(), hotkey).data());
}

auto addOrRemoveMenuItemHotkey(hiro::MenuItem &item, const std::string &hotkey, bool checked) -> void {
	if (checked) {
		addMenuItemHotkey(item, hotkey);
	}
	else {
		removeMenuItemHotkey(item, hotkey);
	}
}

auto addOrRemoveMenuItemHotkey(hiro::MenuRadioItem &item, const std::string &hotkey, bool checked) -> void {
	if (checked) {
		addMenuItemHotkey(item, hotkey);
	}
	else {
		removeMenuItemHotkey(item, hotkey);
	}
}

auto checkAndToggle(hiro::CheckLabel label) -> void {
	label.setChecked().doToggle();
}

auto uncheckAndToggle(hiro::CheckLabel label) -> void {
	label.setChecked(false).doToggle();
}

auto BuiltinHotkeysSettings::allChecked() -> bool {
	for (auto &label : labels) {
		if (!label.checked()) {
			return false;
		}
	}

	return true;
}

auto BuiltinHotkeysSettings::allUnchecked() -> bool {
	for (auto &label : labels) {
		if (label.checked()) {
			return false;
		}
	}

	return true;
}

auto BuiltinHotkeysSettings::enableDisableButtons() -> void {
	checkAll.setEnabled(!allChecked());
	uncheckAll.setEnabled(!allUnchecked());
}

auto BuiltinHotkeysSettings::create() -> void {
	setCollapsible();
	setVisible(false);

	string dash = u8" — ";

	string closeGamePrefix  = {bmt::get("Menu.File.CloseGame").data(), dash};
	string fullScreenPrefix = {bmt::get("Menu.Settings.Size.FullScreenMode").data(), dash};
	string screenshotPrefix = {bmt::get("Tools.TakeScreenshot").data(), dash};

	static string ctrlO       = "Ctrl+O";
	static string ctrlW       = "Ctrl+W";
	static string ctrlF4      = "Ctrl+F4";
	static string f11         = "F11";
	static string altEnter    = "Alt+Enter";
	static string shiftEnter  = "Shift+Enter";
	static string printScreen = "PrintScreen";
	static string f9          = "F9";
	static string f5          = "F5";
	static string pauseBreak  = "Pause/Break";

	static auto p = presentation;

	openGame_CtrlO.setText({bmt::get("Menu.File.OpenGame").data(), dash, ctrlO})
		.setChecked(settings.builtinHotkeys.openGame_CtrlO)
		.onToggle([&] {
			bool checked = openGame_CtrlO.checked();
			settings.builtinHotkeys.openGame_CtrlO = checked;
			addOrRemoveMenuItemHotkey(p.openGame, ctrlO.data(), checked);
			enableDisableButtons();
		});

	closeGame_CtrlW.setText({closeGamePrefix, ctrlW})
		.setChecked(settings.builtinHotkeys.closeGame_CtrlW)
		.onToggle([&] {
			bool checked = closeGame_CtrlW.checked();
			settings.builtinHotkeys.closeGame_CtrlW = checked;
			addOrRemoveMenuItemHotkey(p.closeGame, ctrlW.data(), checked);
			enableDisableButtons();
		});

	closeGame_CtrlF4.setText({closeGamePrefix, ctrlF4})
		.setChecked(settings.builtinHotkeys.closeGame_CtrlF4)
		.onToggle([&] {
			bool checked = closeGame_CtrlF4.checked();
			settings.builtinHotkeys.closeGame_CtrlF4 = checked;
			addOrRemoveMenuItemHotkey(p.closeGame, ctrlF4.data(), checked);
			enableDisableButtons();
		});

	fullScreen_F11.setText({fullScreenPrefix, f11})
		.setChecked(settings.builtinHotkeys.fullScreen_F11)
		.onToggle([&] {
			bool checked = fullScreen_F11.checked();
			settings.builtinHotkeys.fullScreen_F11 = checked;
			addOrRemoveMenuItemHotkey(p.fullScreenMenuItem, f11.data(), checked);
			enableDisableButtons();
		});

	fullScreen_AltEnter.setText({fullScreenPrefix, altEnter})
		.setChecked(settings.builtinHotkeys.fullScreen_AltEnter)
		.onToggle([&] {
			bool checked = fullScreen_AltEnter.checked();
			settings.builtinHotkeys.fullScreen_AltEnter = checked;
			addOrRemoveMenuItemHotkey(p.fullScreenMenuItem, altEnter.data(), checked);
			enableDisableButtons();
		});

	pseudoFullScreen_ShiftEnter.setText({bmt::get("Menu.Settings.Size.PseudoFullScreenMode").data(), dash, shiftEnter})
		.setChecked(settings.builtinHotkeys.pseudoFullScreen_ShiftEnter)
		.onToggle([&] {
			bool checked = pseudoFullScreen_ShiftEnter.checked();
			settings.builtinHotkeys.pseudoFullScreen_ShiftEnter = checked;
			addOrRemoveMenuItemHotkey(p.pseudoFullScreenMenuItem, shiftEnter.data(), checked);
			enableDisableButtons();
		});

	takeScreenshot_PrintScreen.setText({screenshotPrefix, printScreen})
		.setChecked(settings.builtinHotkeys.takeScreenshot_PrintScreen)
		.onToggle([&] {
			bool checked = takeScreenshot_PrintScreen.checked();
			settings.builtinHotkeys.takeScreenshot_PrintScreen = checked;
			addOrRemoveMenuItemHotkey(p.captureScreenshot, printScreen.data(), checked);
			enableDisableButtons();
		});

	takeScreenshot_F9.setText({screenshotPrefix, f9})
		.setChecked(settings.builtinHotkeys.takeScreenshot_F9)
		.onToggle([&] {
			bool checked = takeScreenshot_F9.checked();
			settings.builtinHotkeys.takeScreenshot_F9 = checked;
			addOrRemoveMenuItemHotkey(p.captureScreenshot, f9.data(), checked);
			enableDisableButtons();
		});

	resetEmulation_F5.setText({bmt::get("Hotkeys.ResetEmulation").data(), dash, f5})
		.setChecked(settings.builtinHotkeys.resetEmulation_F5)
		.onToggle([&] {
			bool checked = resetEmulation_F5.checked();
			settings.builtinHotkeys.resetEmulation_F5 = checked;
			addOrRemoveMenuItemHotkey(p.resetSystem, f5.data(), checked);
			enableDisableButtons();
		});

	pauseEmulation_PauseBreak.setText({bmt::get("Tools.RunMode.PauseEmulation").data(), dash, pauseBreak})
		.setChecked(settings.builtinHotkeys.pauseEmulation_PauseBreak)
		.onToggle([&] {
			bool checked = pauseEmulation_PauseBreak.checked();
			settings.builtinHotkeys.pauseEmulation_PauseBreak = checked;
			addOrRemoveMenuItemHotkey(p.pauseEmulation, pauseBreak.data(), checked);
			enableDisableButtons();
		});

	checkAll.setText(bmt::get("Settings.BuiltinHotkeys.CheckAll").data()).onActivate([&] {
		for (auto &label : labels) {
			checkAndToggle(label);
		}
	});

	uncheckAll.setText(bmt::get("Settings.BuiltinHotkeys.UncheckAll").data()).onActivate([&] {
		for (auto &label : labels) {
			uncheckAndToggle(label);
		}
	});

	enableDisableButtons();
}