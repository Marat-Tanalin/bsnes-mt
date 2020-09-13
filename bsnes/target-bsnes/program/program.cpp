/* MT. */
#include "bsnes-mt/translations.h"
#include "bsnes-mt/messagebox.h"

namespace bmt = bsnesMt::translations;
namespace bmw = bsnesMt::windows;
/* /MT. */

#include "../bsnes.hpp"

#include "_platform.cpp"
#include "_game.cpp"
#include "_game-pak.cpp"
#include "_game-rom.cpp"
#include "_paths.cpp"
#include "_states.cpp"
#include "_movies.cpp"
#include "_rewind.cpp"
#include "_video.cpp"
#include "_audio.cpp"
#include "_input.cpp"
#include "_utility.cpp"
#include "_patch.cpp"
#include "_hacks.cpp"
#include "_filter.cpp"
#include "_viewport.cpp"

Program program;

static bool quitInProgress = false; // Used in `Program::quit()`. // MT.

auto Program::create() -> void {
	Emulator::platform = this;

	presentation.create();
	presentation.setVisible();
	presentation.viewport.setFocused();

	settingsWindow.create();
	videoSettings.create();
	audioSettings.create();
	inputSettings.create();
	hotkeySettings.create();
	builtinHotkeysSettings.create(); // MT.
	pathSettings.create();
	emulatorSettings.create();
	enhancementSettings.create();
	compatibilitySettings.create();
	driverSettings.create();

	toolsWindow.create();
	cheatFinder.create();
	cheatDatabase.create();
	cheatWindow.create();
	cheatEditor.create();
	stateWindow.create();
	stateManager.create();
	manifestViewer.create();

	/* // Commented-out by MT.
	if (settings.general.crashed) {
		MessageDialog(
			"Driver crash detected. Hardware drivers have been disabled.\n"
			"Please reconfigure drivers in the advanced settings panel."
		).setAlignment(*presentation).information();

		settings.video.driver = "None";
		settings.audio.driver = "None";
		settings.input.driver = "None";
	}

	settings.general.crashed = true;
	settings.save();
	*/

	/* MT. */
	if (resetDrivers) {
		bmw::showNotice(
			bmt::get("ResetDrivers.message"),
			bmt::get("ResetDrivers.message.title"),
			presentation.handle()
		);

		auto none = "None";

		settings.video.driver = none;
		settings.audio.driver = none;
		settings.input.driver = none;
	}
	/* /MT. */

	updateVideoDriver(presentation);
	updateAudioDriver(presentation);
	updateInputDriver(presentation);

	// Commented-out by MT.
	/*
	settings.general.crashed = false;
	settings.save();
	*/

	driverSettings.videoDriverChanged();
	driverSettings.audioDriverChanged();
	driverSettings.inputDriverChanged();

	if (gameQueue) {
		load();
	}

	if (startFullScreen && emulator->loaded()) {
		toggleVideoFullScreen();
	}

	Application::onMain({&Program::main, this});

	/* MT. */
	if (resetDrivers) {
		settingsWindow.show(8);
	}
	/* /MT. */
}

auto Program::main() -> void {
	updateStatus();
	video.poll();

	if (Application::modal()) {
		audio.clear();
		return;
	}

	inputManager.poll();
	inputManager.pollHotkeys();

	if (inactive()) {
		audio.clear();
		usleep(20 * 1000);

		if (settings.emulator.runAhead.frames == 0) {
			viewportRefresh();
		}

		return;
	}

	rewindRun();

	if (!settings.emulator.runAhead.frames || fastForwarding || rewinding) {
		emulator->run();
	}
	else {
		emulator->setRunAhead(true);
		emulator->run();

		auto state = emulator->serialize(0);

		if (settings.emulator.runAhead.frames >= 2) {
			emulator->run();
		}

		if (settings.emulator.runAhead.frames >= 3) {
			emulator->run();
		}

		if (settings.emulator.runAhead.frames >= 4) {
			emulator->run();
		}

		emulator->setRunAhead(false);
		emulator->run();
		state.setMode(serializer::Mode::Load);
		emulator->unserialize(state);
	}

	if (emulatorSettings.autoSaveMemory.checked()) {
		auto currentTime = chrono::timestamp();

		if (currentTime - autoSaveTime >= settings.emulator.autoSaveMemory.interval) {
			autoSaveTime = currentTime;
			emulator->save();
		}
	}
}

auto Program::quit() -> void {
	/* MT. */
	if (quitInProgress) {
		return;
	}

	quitInProgress = true;
	/* /MT. */

	//make closing the program feel more responsive
	presentation.setVisible(false);
	Application::processEvents();

	//in case the emulator was closed prior to initialization completing:
	settings.general.crashed = false;

	unload();
	settings.save();
	video.reset();
	audio.reset();
	input.reset();

	#if defined(PLATFORM_WINDOWS)
	//in rare cases, when Application::exit() calls exit(0), a crash will occur.
	//this seems to be due to the internal state of certain ruby drivers.
	auto processID = GetCurrentProcessId();
	auto handle    = OpenProcess(SYNCHRONIZE | PROCESS_TERMINATE, true, processID);
	TerminateProcess(handle, 0);
	#endif

	Application::exit();
}