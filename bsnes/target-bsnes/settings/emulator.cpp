/* MT. */
#include "bsnes-mt/strings.h"

namespace bms = bsnesMt::strings;
/* /MT. */

auto EmulatorSettings::create() -> void {
	setCollapsible();
	setVisible(false);

	optionsLabel.setText(bms::get("Settings.Emulator.General").data()).setFont(Font().setBold()); // "Options"

	warnOnUnverifiedGames.setText(bms::get("Settings.Emulator.General.warnOnUnverifiedGames").data()).setChecked(settings.emulator.warnOnUnverifiedGames).onToggle([&] {
		// "Warn when loading games that have not been verified"
		settings.emulator.warnOnUnverifiedGames = warnOnUnverifiedGames.checked();
	});

	autoSaveMemory.setText(bms::get("Settings.Emulator.General.autoSaveMemory").data()).setChecked(settings.emulator.autoSaveMemory.enable).onToggle([&] {
		// "Auto-save memory periodically"
		settings.emulator.autoSaveMemory.enable = autoSaveMemory.checked();
	});

	autoSaveStateOnUnload.setText(bms::get("Settings.Emulator.General.autoSaveStateOnUnload").data()).setChecked(settings.emulator.autoSaveStateOnUnload).onToggle([&] {
		// "Auto-save undo state when unloading games"
		settings.emulator.autoSaveStateOnUnload = autoSaveStateOnUnload.checked();

		if (!autoSaveStateOnUnload.checked()) {
			autoLoadStateOnLoad.setEnabled(false).setChecked(false).doToggle();
		}
		else {
			autoLoadStateOnLoad.setEnabled(true);
		}
	}).doToggle();

	autoLoadStateOnLoad.setText(bms::get("Settings.Emulator.General.AutoResumeOnLoad").data()).setChecked(settings.emulator.autoLoadStateOnLoad).onToggle([&] {
		// "Auto-resume on load"
		settings.emulator.autoLoadStateOnLoad = autoLoadStateOnLoad.checked();
	});

	nativeFileDialogs.setText(bms::get("Settings.Emulator.General.UseNativeFileDialogs").data()).setChecked(settings.general.nativeFileDialogs).onToggle([&] {
		// "Use native file dialogs"
		settings.general.nativeFileDialogs = nativeFileDialogs.checked();
	});

	Color spacerColor = {192, 192, 192}; // MT.

	optionsSpacer.setColor(spacerColor);

	fastForwardLabel.setText(bms::get("Settings.Emulator.FastForward").data()).setFont(Font().setBold()); // "Fast Forward"

	char colon = ':';

	frameSkipLabel.setText({bms::get("Settings.Emulator.FastForward.FrameSkip").data(), colon}).setToolTip( // "Frame skip:"
		bms::get("Settings.Emulator.FastForward.FrameSkip.tooltip").data()
	);

	/* MT. */
	string noneString       = bms::get("Common.None").data();
	string framesString     = bms::get("Settings.Emulator.FastForward.FrameSkip.Frames").data();
	string frames2to4String = bms::get("Settings.Emulator.FastForward.FrameSkip.Frames2to4").data();
	/* /MT. */

	frameSkipAmount.append(ComboButtonItem().setText(noneString)); // "None"
	frameSkipAmount.append(ComboButtonItem().setText({"1 ", bms::get("Settings.Common.FrameLowercase").data()})); // frame

	/* MT. */
	for (uint8_t i = 2; i < 5; i++) {
		frameSkipAmount.append(ComboButtonItem().setText(string(frames2to4String).replace('|', i))); // frames
	}

	for (uint8_t i = 5; i < 10; i++) {
		frameSkipAmount.append(ComboButtonItem().setText(string(framesString).replace('|', i))); // frames
	}
	/* /MT. */

	frameSkipAmount.item(settings.fastForward.frameSkip).setSelected();

	frameSkipAmount.onChange([&] {
		settings.fastForward.frameSkip = frameSkipAmount.selected().offset();
	});

	limiterLabel.setText({bms::get("Settings.Emulator.FastForward.Limiter").data(), colon}).setToolTip({ // "Limiter:"
		bms::get("Settings.Emulator.FastForward.Limiter.tooltip").data() // "Set the maximum speed when fast forwarding."
	});

	limiterAmount.append(ComboButtonItem().setText(noneString)); // "None"

	/* // Commented-out by MT.
	limiterAmount.append(ComboButtonItem().setText("200%"));
	limiterAmount.append(ComboButtonItem().setText("300%"));
	limiterAmount.append(ComboButtonItem().setText("400%"));
	limiterAmount.append(ComboButtonItem().setText("500%"));
	limiterAmount.append(ComboButtonItem().setText("600%"));
	limiterAmount.append(ComboButtonItem().setText("700%"));
	limiterAmount.append(ComboButtonItem().setText("800%"));
	*/

	/* MT. */
	for (uint8_t i = 2; i < 9; i++) {
		limiterAmount.append(ComboButtonItem().setText({100 * i, '%'}));
	}
	/* /MT. */

	auto limiter = settings.fastForward.limiter; // MT.

	if (limiter == 0) {
		limiterAmount.item(0).setSelected();
	}
	else if (limiter == 2) {
		limiterAmount.item(1).setSelected();
	}
	else if (limiter == 3) {
		limiterAmount.item(2).setSelected();
	}
	else if (limiter == 4) {
		limiterAmount.item(3).setSelected();
	}
	else if (limiter == 5) {
		limiterAmount.item(4).setSelected();
	}
	else if (limiter == 6) {
		limiterAmount.item(5).setSelected();
	}
	else if (limiter == 7) {
		limiterAmount.item(6).setSelected();
	}
	else if (limiter == 8) {
		limiterAmount.item(7).setSelected();
	}

	limiterAmount.onChange([&] {
		auto index = limiterAmount.selected().offset();

		if (index == 0) {
			settings.fastForward.limiter = 0;
		}
		else if (index == 1) {
			settings.fastForward.limiter = 2;
		}
		else if (index == 2) {
			settings.fastForward.limiter = 3;
		}
		else if (index == 3) {
			settings.fastForward.limiter = 4;
		}
		else if (index == 4) {
			settings.fastForward.limiter = 5;
		}
		else if (index == 5) {
			settings.fastForward.limiter = 6;
		}
		else if (index == 6) {
			settings.fastForward.limiter = 7;
		}
		else if (index == 7) {
			settings.fastForward.limiter = 8;
		}
	});

	fastForwardMute.setText(bms::get("Settings.Emulator.FastForward.mute").data()).setChecked(settings.fastForward.mute).onToggle([&] { // "Mute while fast forwarding"
		settings.fastForward.mute = fastForwardMute.checked();
	});

	fastForwardSpacer.setColor(spacerColor);

	rewindLabel.setText(bms::get("Settings.Emulator.Rewind").data()).setFont(Font().setBold()); // "Rewind"

	string everyString = bms::get("Settings.Emulator.Rewind.Frequency.everyFrames").data(); // MT.

	rewindFrequencyLabel.setText({bms::get("Settings.Emulator.Rewind.Frequency").data(), colon}); // "Frequency:"
	rewindFrequencyOption.append(ComboButtonItem().setText(bms::get("Common.Disabled").data())); // "Disabled"

	/* // Commented-out by MT.
	rewindFrequencyOption.append(ComboButtonItem().setText(string(everyString).replace('|', "10"))); // "Every 10 frames"
	rewindFrequencyOption.append(ComboButtonItem().setText(string(everyString).replace('|', "20"))); // "Every 20 frames"
	rewindFrequencyOption.append(ComboButtonItem().setText(string(everyString).replace('|', "30"))); // "Every 30 frames"
	rewindFrequencyOption.append(ComboButtonItem().setText(string(everyString).replace('|', "40"))); // "Every 40 frames"
	rewindFrequencyOption.append(ComboButtonItem().setText(string(everyString).replace('|', "50"))); // "Every 50 frames"
	rewindFrequencyOption.append(ComboButtonItem().setText(string(everyString).replace('|', "60"))); // "Every 60 frames"
	*/

	/* MT. */
	for (uint8_t number = 10; number < 70; number += 10) {
		rewindFrequencyOption.append(ComboButtonItem().setText(string(everyString).replace('|', number))); // "Every 10 frames"
	}
	/* /MT. */

	auto frequency = settings.rewind.frequency; // MT.

	if (frequency ==  0) {
		rewindFrequencyOption.item(0).setSelected();
	}
	else if (frequency == 10) {
		rewindFrequencyOption.item(1).setSelected();
	}
	else if (frequency == 20) {
		rewindFrequencyOption.item(2).setSelected();
	}
	else if (frequency == 30) {
		rewindFrequencyOption.item(3).setSelected();
	}
	else if (frequency == 40) {
		rewindFrequencyOption.item(4).setSelected();
	}
	else if (frequency == 50) {
		rewindFrequencyOption.item(5).setSelected();
	}
	else if (frequency == 60) {
		rewindFrequencyOption.item(6).setSelected();
	}

	rewindFrequencyOption.onChange([&] {
		settings.rewind.frequency = rewindFrequencyOption.selected().offset() * 10;
		program.rewindReset();
	});

	string statesString = bms::get("Settings.Emulator.Rewind.Length.states").data(); // MT.

	rewindLengthLabel.setText({bms::get("Settings.Emulator.Rewind.Length").data(), colon}); // "Length:"

	/* // Commented-out by MT.
	rewindLengthOption.append(ComboButtonItem().setText(string(statesString).replace('|',  "10"))); //  "10 states"
	rewindLengthOption.append(ComboButtonItem().setText(string(statesString).replace('|',  "20"))); //  "20 states"
	rewindLengthOption.append(ComboButtonItem().setText(string(statesString).replace('|',  "40"))); //  "40 states"
	rewindLengthOption.append(ComboButtonItem().setText(string(statesString).replace('|',  "80"))); //  "80 states"
	rewindLengthOption.append(ComboButtonItem().setText(string(statesString).replace('|', "160"))); // "160 states"
	rewindLengthOption.append(ComboButtonItem().setText(string(statesString).replace('|', "320"))); // "320 states"
	*/

	/* MT. */
	for (uint8_t i = 0, j = 1; i < 6; i++) {
		rewindLengthOption.append(ComboButtonItem().setText(string(statesString).replace('|', j * 10))); //  "10 states"
		j *= 2;
	}
	/* /MT. */

	auto length = settings.rewind.length; // MT.

	if (length ==  10) {
		rewindLengthOption.item(0).setSelected();
	}
	else if (length ==  20) {
		rewindLengthOption.item(1).setSelected();
	}
	else if (length ==  40) {
		rewindLengthOption.item(2).setSelected();
	}
	else if (length ==  80) {
		rewindLengthOption.item(3).setSelected();
	}
	else if (length == 160) {
		rewindLengthOption.item(4).setSelected();
	}
	else if (length == 320) {
		rewindLengthOption.item(5).setSelected();
	}

	rewindLengthOption.onChange([&] {
		settings.rewind.length = 10 << rewindLengthOption.selected().offset();
		program.rewindReset();
	});

	rewindMute.setText(bms::get("Settings.Emulator.Rewind.mute").data()).setChecked(settings.rewind.mute).onToggle([&] { // "Mute while rewinding"
		settings.rewind.mute = rewindMute.checked();
	});
}