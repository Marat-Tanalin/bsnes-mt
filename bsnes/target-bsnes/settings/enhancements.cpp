/* MT. */
#include "bsnes-mt/strings.h"

namespace bms = bsnesMt::strings;
/* /MT. */

auto EnhancementSettings::create() -> void {
	setCollapsible();
	setVisible(false);

	/* MT. */
	string framesString = bms::get("Settings.Enhancements.RunAhead.Frames").data();
	char space = ' ';
	/* /MT. */

	runAheadLabel.setText(bms::get("Settings.Enhancements.RunAhead").data()).setFont(Font().setBold());
		// "Run-Ahead"
		runAhead0.setText(bms::get("Common.Disabled").data()).onActivate([&] { // "Disabled"
		settings.emulator.runAhead.frames = 0;
	});

	runAhead1.setText({bms::get("Settings.Enhancements.RunAhead.One").data(), space, bms::get("Settings.Common.FrameLowercase").data()}).onActivate([&] {
		// "One Frame"
		settings.emulator.runAhead.frames = 1;
	});

	runAhead2.setText({bms::get("Settings.Enhancements.RunAhead.Two").data(), space, framesString}).onActivate([&] {
		// "Two Frames"
		settings.emulator.runAhead.frames = 2;
	});

	runAhead3.setText({bms::get("Settings.Enhancements.RunAhead.Three").data(), space, framesString}).onActivate([&] {
		// "Three Frames"
		settings.emulator.runAhead.frames = 3;
	});

	runAhead4.setText({bms::get("Settings.Enhancements.RunAhead.Four").data(), space, framesString}).onActivate([&] {
		// "Four Frames"
		settings.emulator.runAhead.frames = 4;
	});

	auto frames = settings.emulator.runAhead.frames; // MT.

	if (frames == 0) {
		runAhead0.setChecked();
	}
	else if (frames == 1) {
		runAhead1.setChecked();
	}
	else if (frames == 2) {
		runAhead2.setChecked();
	}
	else if (frames == 3) {
		runAhead3.setChecked();
	}
	else if (frames == 4) {
		runAhead4.setChecked();
	}

	runAheadSpacer.setColor({192, 192, 192});

	overclockingLabel.setText(bms::get("Settings.Enhancements.Overclocking").data()).setFont(Font().setBold()); // "Overclocking"

	overclockingLayout.setSize({3, 3});
	overclockingLayout.column(0).setAlignment(1.0);
	overclockingLayout.column(1).setAlignment(0.5);

	cpuLabel.setText("CPU:");

	cpuClock.setLength(301).setPosition((settings.emulator.hack.cpu.overclock - 100)).onChange([&] {
		settings.emulator.hack.cpu.overclock = cpuClock.position() + 100;
		emulator->configure("Hacks/CPU/Overclock", settings.emulator.hack.cpu.overclock);
		cpuValue.setText({settings.emulator.hack.cpu.overclock, "%"});
	}).doChange();

	sa1Label.setText("SA-1:");

	sa1Clock.setLength(301).setPosition((settings.emulator.hack.sa1.overclock - 100)).onChange([&] {
		settings.emulator.hack.sa1.overclock = sa1Clock.position() + 100;
		emulator->configure("Hacks/SA1/Overclock", settings.emulator.hack.sa1.overclock);
		sa1Value.setText({settings.emulator.hack.sa1.overclock, "%"});
	}).doChange();

	sfxLabel.setText("SuperFX:");

	sfxClock.setLength(141).setPosition((settings.emulator.hack.superfx.overclock - 100) / 5).onChange([&] {
		settings.emulator.hack.superfx.overclock = sfxClock.position() * 5 + 100;
		emulator->configure("Hacks/SuperFX/Overclock", settings.emulator.hack.superfx.overclock);
		sfxValue.setText({settings.emulator.hack.superfx.overclock, "%"});
	}).doChange();

	overclockingSpacer.setColor({192, 192, 192});

	ppuLabel.setText({"PPU (", bms::get("Settings.Enhancements.Ppu.Video").data(), ")"}).setFont(Font().setBold()); // "PPU (video)"

	fastPPU.setText(bms::get("Settings.Enhancements.FastMode").data()).setChecked(settings.emulator.hack.ppu.fast).onToggle([&] {
		// "Fast mode"
		settings.emulator.hack.ppu.fast = fastPPU.checked();

		if (!fastPPU.checked()) {
			noSpriteLimit.setEnabled(false);
			deinterlace.setEnabled(false);
			mode7Layout.setEnabled(false);
		}
		else {
			noSpriteLimit.setEnabled(true);
			deinterlace.setEnabled(true);
			mode7Layout.setEnabled(true);
		}
	}).doToggle();

	deinterlace.setText(bms::get("Settings.Enhancements.Ppu.Deinterlace").data()).setChecked(settings.emulator.hack.ppu.deinterlace).onToggle([&] {
		// "Deinterlace"
		settings.emulator.hack.ppu.deinterlace = deinterlace.checked();
		emulator->configure("Hacks/PPU/Deinterlace", settings.emulator.hack.ppu.deinterlace);
	});

	noSpriteLimit.setText(bms::get("Settings.Enhancements.Ppu.NoSpriteLimit").data()).setChecked(settings.emulator.hack.ppu.noSpriteLimit).onToggle([&] {
		// "No sprite limit"
		settings.emulator.hack.ppu.noSpriteLimit = noSpriteLimit.checked();
	});

	mode7Label.setText({"HD Mode 7 (", bms::get("Settings.Enhancements.hdMode7.FastPpuOnly").data(), ")"}).setFont(Font().setBold()); // "HD Mode 7 (fast PPU only)"
	mode7ScaleLabel.setText({bms::get("Settings.Enhancements.hdMode7.Scale").data(), ':'}); // "Scale:"

	/* // Commented-out by MT.
	mode7Scale.append(ComboButtonItem().setText( "240p").setAttribute("multiplier", 1));
	mode7Scale.append(ComboButtonItem().setText( "480p").setAttribute("multiplier", 2));
	mode7Scale.append(ComboButtonItem().setText( "720p").setAttribute("multiplier", 3));
	mode7Scale.append(ComboButtonItem().setText( "960p").setAttribute("multiplier", 4));
	mode7Scale.append(ComboButtonItem().setText("1200p").setAttribute("multiplier", 5));
	mode7Scale.append(ComboButtonItem().setText("1440p").setAttribute("multiplier", 6));
	mode7Scale.append(ComboButtonItem().setText("1680p").setAttribute("multiplier", 7));
	mode7Scale.append(ComboButtonItem().setText("1920p").setAttribute("multiplier", 8));
	*/

	/* MT. */
	for (uint8_t i = 1; i < 9; i++) {
		mode7Scale.append(ComboButtonItem().setText({240 * i, "p"}).setAttribute("multiplier", i));
	}
	/* /MT. */

	for (uint n = 1; n <= 8; n++) {
		if (settings.emulator.hack.ppu.mode7.scale == n) {
			mode7Scale.item(n - 1).setSelected();
		}
	}

	mode7Scale.onChange([&] {
		settings.emulator.hack.ppu.mode7.scale = mode7Scale.selected().attribute("multiplier").natural();
		emulator->configure("Hacks/PPU/Mode7/Scale", settings.emulator.hack.ppu.mode7.scale);
	});

	mode7Perspective.setText(bms::get("Settings.Enhancements.hdMode7.PerspectiveCorrection").data()).setChecked(settings.emulator.hack.ppu.mode7.perspective).onToggle([&] {
		// "Perspective correction"
		settings.emulator.hack.ppu.mode7.perspective = mode7Perspective.checked();
		emulator->configure("Hacks/PPU/Mode7/Perspective", settings.emulator.hack.ppu.mode7.perspective);
	});

	mode7Supersample.setText(bms::get("Settings.Enhancements.hdMode7.Supersampling").data()).setChecked(settings.emulator.hack.ppu.mode7.supersample).onToggle([&] {
		// "Supersampling"
		settings.emulator.hack.ppu.mode7.supersample = mode7Supersample.checked();
		emulator->configure("Hacks/PPU/Mode7/Supersample", settings.emulator.hack.ppu.mode7.supersample);
	});

	mode7Mosaic.setText(bms::get("Settings.Enhancements.hdMode7.HdToSdMosaic").data()).setChecked(settings.emulator.hack.ppu.mode7.mosaic).onToggle([&] {
		// "HD->SD Mosaic"
		settings.emulator.hack.ppu.mode7.mosaic = mode7Mosaic.checked();
		emulator->configure("Hacks/PPU/Mode7/Mosaic", settings.emulator.hack.ppu.mode7.mosaic);
	});

	dspLabel.setText({"DSP (", bms::get("Settings.Enhancements.Dsp.Audio").data(), ")"}).setFont(Font().setBold()); // "DSP (audio)"

	fastDSP.setText(bms::get("Settings.Enhancements.FastMode").data()).setChecked(settings.emulator.hack.dsp.fast).onToggle([&] {
		// "Fast mode"
		settings.emulator.hack.dsp.fast = fastDSP.checked();
		emulator->configure("Hacks/DSP/Fast", settings.emulator.hack.dsp.fast);
	});

	cubicInterpolation.setText(bms::get("Settings.Enhancements.Dsp.CubicInterpolation").data()).setChecked(settings.emulator.hack.dsp.cubic).onToggle([&] {
		// "Cubic interpolation"
		settings.emulator.hack.dsp.cubic = cubicInterpolation.checked();
		emulator->configure("Hacks/DSP/Cubic", settings.emulator.hack.dsp.cubic);
	});

	coprocessorLabel.setText(bms::get("Settings.Enhancements.Coprocessors").data()).setFont(Font().setBold()); // "Coprocessors"

	coprocessorDelayedSyncOption.setText(bms::get("Settings.Enhancements.FastMode").data()).setChecked(settings.emulator.hack.coprocessor.delayedSync).onToggle([&] {
		// "Fast mode"
		settings.emulator.hack.coprocessor.delayedSync = coprocessorDelayedSyncOption.checked();
	});

	coprocessorPreferHLEOption.setText(bms::get("Settings.Enhancements.Coprocessors.PreferHle").data()).setChecked(settings.emulator.hack.coprocessor.preferHLE).setToolTip(
		// "Prefer HLE"
		bms::get("Settings.Enhancements.Coprocessors.PreferHle.tooltip").data()
	).onToggle([&] {
		settings.emulator.hack.coprocessor.preferHLE = coprocessorPreferHLEOption.checked();
	});

	coprocessorSpacer.setColor({192, 192, 192});

	gameLabel.setText(bms::get("Settings.Enhancements.GameEnhancements").data()).setFont(Font().setBold()); // "Game Enhancements"

	hotfixes.setText(bms::get("Settings.Enhancements.GameEnhancements.Hotfixes").data()).setToolTip({ // "Hotfixes"
		bms::get("Settings.Enhancements.GameEnhancements.Hotfixes.tooltip").data()
	}).setChecked(settings.emulator.hack.hotfixes).onToggle([&] {
		settings.emulator.hack.hotfixes = hotfixes.checked();
	});

	note.setText(bms::get("Settings.noteGameRestart").data()); // "Note: some settings do not take effect until after reloading games."
}