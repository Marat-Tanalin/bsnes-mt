/* MT. */
#include "bsnes-mt/strings.h"

namespace bms = bsnesMt::strings;
/* /MT. */

auto EmulatorSettings::create() -> void {
	setCollapsible();
	setVisible(false);

	optionsLabel.setText(bms::get("Settings.Emulator.General").data()).setFont(Font().setBold());

	warnOnUnverifiedGames.setText(bms::get("Settings.Emulator.General.warnOnUnverifiedGames").data())
		.setChecked(settings.emulator.warnOnUnverifiedGames)
		.onToggle([&] {
			settings.emulator.warnOnUnverifiedGames = warnOnUnverifiedGames.checked();
		});

	autoSaveMemory.setText(bms::get("Settings.Emulator.General.autoSaveMemory").data())
		.setChecked(settings.emulator.autoSaveMemory.enable)
		.onToggle([&] {
			settings.emulator.autoSaveMemory.enable = autoSaveMemory.checked();
		});

	autoSaveStateOnUnload.setText(bms::get("Settings.Emulator.General.autoSaveStateOnUnload").data())
		.setChecked(settings.emulator.autoSaveStateOnUnload)
		.onToggle([&] {
			settings.emulator.autoSaveStateOnUnload = autoSaveStateOnUnload.checked();
	
			if (autoSaveStateOnUnload.checked()) {
				autoLoadStateOnLoad.setEnabled(true);
			}
			else {
				autoLoadStateOnLoad.setEnabled(false).setChecked(false).doToggle();
			}
		})
		.doToggle();

	autoLoadStateOnLoad.setText(bms::get("Settings.Emulator.General.AutoResumeOnLoad").data())
		.setChecked(settings.emulator.autoLoadStateOnLoad)
		.onToggle([&] {
			settings.emulator.autoLoadStateOnLoad = autoLoadStateOnLoad.checked();
		});

	nativeFileDialogs.setText(bms::get("Settings.Emulator.General.UseNativeFileDialogs").data())
		.setChecked(settings.general.nativeFileDialogs)
		.onToggle([&] {
			settings.general.nativeFileDialogs = nativeFileDialogs.checked();
		});

	Color spacerColor = {192, 192, 192}; // MT.

	optionsSpacer.setColor(spacerColor);

	fastForwardLabel.setText(bms::get("Settings.Emulator.FastForward").data()).setFont(Font().setBold());

	char colon = ':';

	frameSkipLabel.setText({bms::get("Settings.Emulator.FastForward.FrameSkip").data(), colon})
		.setToolTip(bms::get("Settings.Emulator.FastForward.FrameSkip.tooltip").data());

	/* MT. */
	string noneString       = bms::get("Common.None").data();
	string framesString     = bms::get("Settings.Emulator.FastForward.FrameSkip.Frames").data();
	string frames2to4String = bms::get("Settings.Emulator.FastForward.FrameSkip.Frames2to4").data();
	/* /MT. */

	frameSkipAmount.append(ComboButtonItem().setText(noneString));
	frameSkipAmount.append(ComboButtonItem().setText({"1 ", bms::get("Settings.Common.FrameLowercase").data()}));

	/* MT. */
	for (uint8_t i = 2; i < 5; i++) {
		frameSkipAmount.append(ComboButtonItem().setText(string(frames2to4String).replace('|', i)));
	}

	for (uint8_t i = 5; i < 10; i++) {
		frameSkipAmount.append(ComboButtonItem().setText(string(framesString).replace('|', i)));
	}
	/* /MT. */

	frameSkipAmount.item(settings.fastForward.frameSkip).setSelected();

	frameSkipAmount.onChange([&] {
		settings.fastForward.frameSkip = frameSkipAmount.selected().offset();
	});

	limiterLabel.setText({bms::get("Settings.Emulator.FastForward.Limiter").data(), colon})
		.setToolTip(bms::get("Settings.Emulator.FastForward.Limiter.tooltip").data());

	limiterAmount.append(ComboButtonItem().setText(noneString));

	/* MT. */
	for (uint8_t i = 2; i < 9; i++) {
		limiterAmount.append(ComboButtonItem().setText({100 * i, '%'}));
	}
	/* /MT. */

	auto limiter = settings.fastForward.limiter; // MT.

	limiterAmount.item(limiter == 0 ? 0 : limiter - 1).setSelected(); // MT.

	limiterAmount.onChange([&] {
		auto index = limiterAmount.selected().offset();
		settings.fastForward.limiter = index == 0 ? 0 : index + 1; // MT.
	});

	fastForwardMute.setText(bms::get("Settings.Emulator.FastForward.mute").data())
		.setChecked(settings.fastForward.mute)
		.onToggle([&] {
			settings.fastForward.mute = fastForwardMute.checked();
		});

	fastForwardSpacer.setColor(spacerColor);

	rewindLabel.setText(bms::get("Settings.Emulator.Rewind").data()).setFont(Font().setBold());

	string everyString = bms::get("Settings.Emulator.Rewind.Frequency.everyFrames").data(); // MT.

	rewindFrequencyLabel.setText({bms::get("Settings.Emulator.Rewind.Frequency").data(), colon});
	rewindFrequencyOption.append(ComboButtonItem().setText(bms::get("Common.Disabled").data()));

	/* MT. */
	for (uint8_t number = 10; number < 70; number += 10) {
		rewindFrequencyOption.append(ComboButtonItem().setText(string(everyString).replace('|', number)));
	}
	/* /MT. */

	auto frequency = settings.rewind.frequency; // MT.

	rewindFrequencyOption.item(frequency == 0 ? 0 : frequency / 10).setSelected(); // MT.

	rewindFrequencyOption.onChange([&] {
		settings.rewind.frequency = rewindFrequencyOption.selected().offset() * 10;
		program.rewindReset();
	});

	string statesString = bms::get("Settings.Emulator.Rewind.Length.states").data(); // MT.

	rewindLengthLabel.setText({bms::get("Settings.Emulator.Rewind.Length").data(), colon});

	auto length = settings.rewind.length; // MT.

	/* MT. */
	for (uint8_t i = 0, j = 1; i < 6; i++) {
		auto curLength = j * 10;
		auto item      = ComboButtonItem().setText(string(statesString).replace('|', curLength));

		if (curLength == length) {
			item.setSelected();
		}

		rewindLengthOption.append(item);
		j *= 2;
	}
	/* /MT. */

	rewindLengthOption.onChange([&] {
		settings.rewind.length = 10 << rewindLengthOption.selected().offset();
		program.rewindReset();
	});

	rewindMute.setText(bms::get("Settings.Emulator.Rewind.mute").data())
		.setChecked(settings.rewind.mute)
		.onToggle([&] {
			settings.rewind.mute = rewindMute.checked();
		});
}