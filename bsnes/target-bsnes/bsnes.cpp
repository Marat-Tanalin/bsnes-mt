#include "bsnes.hpp"
#include <sfc/interface/interface.hpp>

/* MT. */
#include "bsnes-mt/keyboard.h"
#include "bsnes-mt/translations.h"

namespace bmk = bsnesMt::keyboard;
namespace bmt = bsnesMt::translations;
/* /MT. */

Video video;
Audio audio;
Input input;
unique_pointer<Emulator::Interface> emulator;

/* MT. */
auto isMainWindowActive() -> bool {
	return GetActiveWindow() == (HWND)presentation.handle();
}

auto hotkeyHookCallback(WPARAM keyCode, bool keyDown, bool shiftPressed, bool ctrlPressed, bool altPressed) -> void {
	if (!keyDown) {
		if (VK_SNAPSHOT == keyCode) {
			program.captureScreenshot();
		}

		return;
	}

	if (VK_F9 == keyCode) {
		program.captureScreenshot();
	}
	else if (VK_RETURN == keyCode) {
		if (shiftPressed) {
			program.toggleVideoPseudoFullScreen();
		}
		else if (altPressed) {
			program.toggleVideoFullScreen();
		}
	}
	else if (VK_F11 == keyCode) {
		program.toggleVideoFullScreen();
	}
	else if (altPressed && VK_F4 == keyCode) {
		program.quit();
	}
	else if (ctrlPressed && 0x4F == keyCode && isMainWindowActive() && !video.fullScreen()) {
		program.load();
	}
	else if (ctrlPressed && 0x57 == keyCode && isMainWindowActive()) {
		program.unload();
	}
	else if (ctrlPressed && VK_F4 == keyCode && isMainWindowActive()) {
		program.unload();
	}
	else if (VK_F5 == keyCode && (isMainWindowActive() || video.fullScreen())) {
		program.reset();
	}
	else if (VK_ESCAPE == keyCode) {
		if (video.fullScreen()) {
			program.disableVideoFullScreen();
		}
		else if (presentation.fullScreen() && isMainWindowActive()) {
			program.disableVideoPseudoFullScreen();
		}
	}
	else if (VK_PAUSE == keyCode) {
		if (presentation.runEmulation.checked()) {
			presentation.pauseEmulation.setChecked().doActivate();
		}
		else {
			presentation.runEmulation.setChecked().doActivate();
		}
	}
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
	bmt::initLocale(); // MT.

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
		/*else if (argument.beginsWith("--locale=")) {
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