/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

#include <map>
#include <string>

namespace bsnesMt::translations {

using std::map, std::string;

static map<string, string> strings;

static map<string, string> deviceStrings = {
	{"None",           "Common.None"},
	{"Gamepad",        "Devices.Gamepad"},
	{"Mouse",          "Devices.Mouse"},
	{"Super Multitap", "Devices.SuperMultitap"},
	{"Super Scope",    "Devices.SuperScope"},
	{"Justifier",      "Devices.Justifier"},
	{"Justifiers",     "Devices.Justifiers"},
	{"Satellaview",    "Devices.Satellaview"}
};

static map<string, string> hotkeyStrings = {
	{"Toggle Mouse Capture",     "Hotkeys.ToggleMouseCapture"},
	{"Toggle Cheat Codes",       "Hotkeys.ToggleCheatCodes"},
	{"Rewind",                   "Hotkeys.Rewind"},
	{"Load Undo State",          "Hotkeys.LoadUndoState"},
	{"Load Redo State",          "Hotkeys.LoadRedoState"},
	{"Decrement State Slot",     "Hotkeys.DecrementStateSlot"},
	{"Increment State Slot",     "Hotkeys.IncrementStateSlot"},
	{"Fast Forward",             "Hotkeys.FastForward"},
	{"Frame Advance",            "Hotkeys.FrameAdvance"},
	{"Decrease HD Mode 7",       "Hotkeys.DecreaseHDMode7"},
	{"Increase HD Mode 7",       "Hotkeys.IncreaseHDMode7"},
	{"Toggle Supersampling",     "Hotkeys.ToggleSupersampling"},
	{"Reset Emulation",          "Hotkeys.ResetEmulation"},
	{"Quit Emulator",            "Hotkeys.QuitEmulator"},
	{"Toggle Fullscreen",        "Menu.Settings.Size.FullScreenMode"},
	{"Toggle Pseudo-Fullscreen", "Menu.Settings.Size.PseudoFullScreenMode"},
	{"Toggle Mute",              "Menu.Settings.MuteAudio"},
	{"Save State",               "Tools.SaveState"},
	{"Load State",               "Tools.LoadState"},
	{"Capture Screenshot",       "Tools.TakeScreenshot"},
	{"Pause Emulation",          "Tools.RunMode.PauseEmulation"}
};

auto initLocale() -> void;

auto genericHas(const map<string, string> &items, const string &key) -> bool;

auto has(const string &id) -> bool;

auto get(const map<string, string> &value) -> string;
auto get(const string &id) -> string;

auto getDedicatedStringId(const map<string, string> &dedicatedStrings, const string &id) -> string;

auto getDeviceString(const string &id) -> string;
auto getHotkeyString(const string &id) -> string;

} // namespace bsnesMt::translations