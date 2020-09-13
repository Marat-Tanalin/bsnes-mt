/* MT. */
#include "bsnes-mt/translations.h"

namespace bmt = bsnesMt::translations;
/* /MT. */

auto EnhancementSettings::create() -> void {
	setCollapsible();
	setVisible(false);

	/* MT. */
	string framesString = bmt::get("Settings.Enhancements.RunAhead.Frames").data();
	char space = ' ';
	/* /MT. */

	runAheadLabel.setText(bmt::get("Settings.Enhancements.RunAhead").data()).setFont(Font().setBold());

	runAhead0.setText(bmt::get("Common.Disabled").data()).onActivate([&] {
		settings.emulator.runAhead.frames = 0;
	});

	runAhead1.setText({bmt::get("Settings.Enhancements.RunAhead.One").data(), space, bmt::get("Settings.Common.FrameLowercase").data()})
		.onActivate([&] {
			settings.emulator.runAhead.frames = 1;
		});

	runAhead2.setText({bmt::get("Settings.Enhancements.RunAhead.Two").data(), space, framesString})
		.onActivate([&] {
			settings.emulator.runAhead.frames = 2;
		});

	runAhead3.setText({bmt::get("Settings.Enhancements.RunAhead.Three").data(), space, framesString})
		.onActivate([&] {
			settings.emulator.runAhead.frames = 3;
		});

	runAhead4.setText({bmt::get("Settings.Enhancements.RunAhead.Four").data(), space, framesString})
		.onActivate([&] {
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

	Color spacerColor = {192, 192, 192}; // MT.

	runAheadSpacer.setColor(spacerColor);

	overclockingLabel.setText(bmt::get("Settings.Enhancements.Overclocking").data()).setFont(Font().setBold());

	overclockingLayout.setSize({3, 3});
	overclockingLayout.column(0).setAlignment(1.0);
	overclockingLayout.column(1).setAlignment(0.5);

	cpuLabel.setText("CPU:");

	cpuClock.setLength(301).setPosition((settings.emulator.hack.cpu.overclock - 100))
		.onChange([&] {
			settings.emulator.hack.cpu.overclock = cpuClock.position() + 100;
			emulator->configure("Hacks/CPU/Overclock", settings.emulator.hack.cpu.overclock);
			cpuValue.setText({settings.emulator.hack.cpu.overclock, "%"});
		})
		.doChange();

	sa1Label.setText("SA-1:");

	sa1Clock.setLength(301).setPosition((settings.emulator.hack.sa1.overclock - 100))
		.onChange([&] {
			settings.emulator.hack.sa1.overclock = sa1Clock.position() + 100;
			emulator->configure("Hacks/SA1/Overclock", settings.emulator.hack.sa1.overclock);
			sa1Value.setText({settings.emulator.hack.sa1.overclock, "%"});
		})
		.doChange();

	sfxLabel.setText("SuperFX:");

	sfxClock.setLength(141).setPosition((settings.emulator.hack.superfx.overclock - 100) / 5)
		.onChange([&] {
			settings.emulator.hack.superfx.overclock = sfxClock.position() * 5 + 100;
			emulator->configure("Hacks/SuperFX/Overclock", settings.emulator.hack.superfx.overclock);
			sfxValue.setText({settings.emulator.hack.superfx.overclock, "%"});
		})
		.doChange();

	overclockingSpacer.setColor(spacerColor);

	ppuLabel.setText({"PPU (", bmt::get("Settings.Enhancements.Ppu.Video").data(), ")"}).setFont(Font().setBold());

	fastPPU.setText(bmt::get("Settings.Enhancements.FastMode").data())
		.setChecked(settings.emulator.hack.ppu.fast)
		.onToggle([&] {
			bool checked = fastPPU.checked(); // MT.
			settings.emulator.hack.ppu.fast = checked;
	
			noSpriteLimit.setEnabled(checked);
			deinterlace.setEnabled(checked);
			mode7Layout.setEnabled(checked);
		})
		.doToggle();

	deinterlace.setText(bmt::get("Settings.Enhancements.Ppu.Deinterlace").data())
		.setChecked(settings.emulator.hack.ppu.deinterlace)
		.onToggle([&] {
			settings.emulator.hack.ppu.deinterlace = deinterlace.checked();
			emulator->configure("Hacks/PPU/Deinterlace", settings.emulator.hack.ppu.deinterlace);
		});

	noSpriteLimit.setText(bmt::get("Settings.Enhancements.Ppu.NoSpriteLimit").data())
		.setChecked(settings.emulator.hack.ppu.noSpriteLimit)
		.onToggle([&] {
			settings.emulator.hack.ppu.noSpriteLimit = noSpriteLimit.checked();
		});

	mode7Label.setText({"HD Mode 7 (", bmt::get("Settings.Enhancements.hdMode7.FastPpuOnly").data(), ")"}).setFont(Font().setBold());
	mode7ScaleLabel.setText({bmt::get("Settings.Enhancements.hdMode7.Scale").data(), ':'});

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

	mode7Perspective.setText(bmt::get("Settings.Enhancements.hdMode7.PerspectiveCorrection").data())
		.setChecked(settings.emulator.hack.ppu.mode7.perspective)
		.onToggle([&] {
			settings.emulator.hack.ppu.mode7.perspective = mode7Perspective.checked();
			emulator->configure("Hacks/PPU/Mode7/Perspective", settings.emulator.hack.ppu.mode7.perspective);
		});

	mode7Supersample.setText(bmt::get("Settings.Enhancements.hdMode7.Supersampling").data())
		.setChecked(settings.emulator.hack.ppu.mode7.supersample)
		.onToggle([&] {
			settings.emulator.hack.ppu.mode7.supersample = mode7Supersample.checked();
			emulator->configure("Hacks/PPU/Mode7/Supersample", settings.emulator.hack.ppu.mode7.supersample);
		});

	mode7Mosaic.setText(bmt::get("Settings.Enhancements.hdMode7.HdToSdMosaic").data())
		.setChecked(settings.emulator.hack.ppu.mode7.mosaic)
		.onToggle([&] {
			settings.emulator.hack.ppu.mode7.mosaic = mode7Mosaic.checked();
			emulator->configure("Hacks/PPU/Mode7/Mosaic", settings.emulator.hack.ppu.mode7.mosaic);
		});

	dspLabel.setText({"DSP (", bmt::get("Settings.Enhancements.Dsp.Audio").data(), ")"}).setFont(Font().setBold());

	fastDSP.setText(bmt::get("Settings.Enhancements.FastMode").data())
		.setChecked(settings.emulator.hack.dsp.fast)
		.onToggle([&] {
			settings.emulator.hack.dsp.fast = fastDSP.checked();
			emulator->configure("Hacks/DSP/Fast", settings.emulator.hack.dsp.fast);
		});

	cubicInterpolation.setText(bmt::get("Settings.Enhancements.Dsp.CubicInterpolation").data())
		.setChecked(settings.emulator.hack.dsp.cubic)
		.onToggle([&] {
			settings.emulator.hack.dsp.cubic = cubicInterpolation.checked();
			emulator->configure("Hacks/DSP/Cubic", settings.emulator.hack.dsp.cubic);
		});

	coprocessorLabel.setText(bmt::get("Settings.Enhancements.Coprocessors").data()).setFont(Font().setBold());

	coprocessorDelayedSyncOption.setText(bmt::get("Settings.Enhancements.FastMode").data())
		.setChecked(settings.emulator.hack.coprocessor.delayedSync)
		.onToggle([&] {
			settings.emulator.hack.coprocessor.delayedSync = coprocessorDelayedSyncOption.checked();
		});

	coprocessorPreferHLEOption.setText(bmt::get("Settings.Enhancements.Coprocessors.PreferHle").data())
		.setChecked(settings.emulator.hack.coprocessor.preferHLE)
		.setToolTip(bmt::get("Settings.Enhancements.Coprocessors.PreferHle.tooltip").data())
		.onToggle([&] {
			settings.emulator.hack.coprocessor.preferHLE = coprocessorPreferHLEOption.checked();
		});

	coprocessorSpacer.setColor(spacerColor);

	gameLabel.setText(bmt::get("Settings.Enhancements.GameEnhancements").data()).setFont(Font().setBold());

	hotfixes.setText(bmt::get("Settings.Enhancements.GameEnhancements.Hotfixes").data())
		.setToolTip(bmt::get("Settings.Enhancements.GameEnhancements.Hotfixes.tooltip").data())
		.setChecked(settings.emulator.hack.hotfixes).onToggle([&] {
			settings.emulator.hack.hotfixes = hotfixes.checked();
		});

	note.setText(bmt::get("Settings.noteGameRestart").data());
}