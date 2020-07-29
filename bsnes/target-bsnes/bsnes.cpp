#include "bsnes.hpp"
#include <sfc/interface/interface.hpp>

/* MT. */
#include "bsnes-mt/keyboard.h"

namespace bmk = bsnesMt::keyboard;
/* /MT. */

Video video;
Audio audio;
Input input;
unique_pointer<Emulator::Interface> emulator;

/* MT. */
auto CALLBACK hotkeyHookCallback(int code, WPARAM wParam, LPARAM lParam) -> LRESULT {
	auto altPressed   = bmk::isKeyPressed(VK_MENU);
	auto ctrlPressed  = bmk::isKeyPressed(VK_CONTROL);
	auto shiftPressed = bmk::isKeyPressed(VK_SHIFT);
	auto keyDown      = !(HIWORD(lParam) & 0xC000);

	if (HC_ACTION == code && keyDown) {
		if (VK_RETURN == wParam) {
			if (shiftPressed) {
				program.toggleVideoPseudoFullScreen();
			}
			else if (altPressed) {
				program.toggleVideoFullScreen();
			}
		}
		else if (VK_F4 == wParam && altPressed) {
			program.quit();
		}
		else if (ctrlPressed && 0x4F == wParam && GetActiveWindow() == (HWND)presentation.handle()) {
			program.load();
		}
	}

	return CallNextHookEx((HHOOK)hotkeyHookCallback, code, wParam, lParam);
}
/* /MT. */

auto locate(string name) -> string {
	string location = {Path::program(), name};

	if (inode::exists(location)) {
		return location;
	}

	const string dir = "bsnes-mt/";

	location = {Path::userData(), dir, name};

	if (inode::exists(location)) {
		return location;
	}

	const string settings = Path::userSettings();

	directory::create({settings, dir});

	return {settings, dir, name};
}

#include <nall/main.hpp>

auto nall::main(Arguments arguments) -> void {
	settings.location = locate("bsnes-mt-settings.bml");

	for (auto argument : arguments) {
		if (argument == "--fullscreen") {
			program.startFullScreen = true;
		}
		/* MT. */
		else if (argument == "--resetdrivers") {
			program.resetDrivers = true;
		}
		/* /MT. */
		/*else if(argument.beginsWith("--locale=")) {
			Application::locale().scan(locate("Locale/"));
			Application::locale().select(argument.trimLeft("--locale=", 1L));
		}*/ // Commented-out by MT.
		else if (argument.beginsWith("--settings=")) {
			settings.location = argument.trimLeft("--settings=", 1L);
		}
		else if (inode::exists(argument)) {
			//game without option
			program.gameQueue.append({"Auto;", argument});
		}
		else if (argument.find(";")) {
			//game with option
			auto game = argument.split(";", 1L);

			if (inode::exists(game.last())) {
				program.gameQueue.append(argument);
			}
		}
	}

	settings.load();

	Application::setName("bsnes");
	Application::setScreenSaver(settings.general.screenSaver);
	Application::setToolTips(settings.general.toolTips);

	Instances::presentation.construct();
	Instances::settingsWindow.construct();
	Instances::cheatDatabase.construct();
	Instances::cheatWindow.construct();
	Instances::stateWindow.construct();
	Instances::toolsWindow.construct();

	emulator = new SuperFamicom::Interface;
	program.create();

	bmk::initHook(hotkeyHookCallback); // MT.

	Application::run();

	Instances::presentation.destruct();
	Instances::settingsWindow.destruct();
	Instances::cheatDatabase.destruct();
	Instances::cheatWindow.destruct();
	Instances::stateWindow.destruct();
	Instances::toolsWindow.destruct();

	bmk::shutdownHook(); // MT.
}