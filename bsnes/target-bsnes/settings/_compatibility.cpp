/* MT. */
#include "bsnes-mt/translations.h"

namespace bmt = bsnesMt::translations;
/* /MT. */

auto CompatibilitySettings::create() -> void {
	setCollapsible();
	setVisible(false);

	entropyLabel.setText(bmt::get("Settings.Compatibility.entropy").data()).setFont(Font().setBold());

	entropyNone.setText(bmt::get("Common.None").data())
		.setToolTip(bmt::get("Settings.Compatibility.entropy.None.tooltip").data())
		.onActivate([&] {
			settings.emulator.hack.entropy = "None";
		});

	entropyLow.setText(bmt::get("Settings.Compatibility.entropy.Low").data())
		.setToolTip(bmt::get("Settings.Compatibility.entropy.Low.tooltip").data())
		.onActivate([&] {
			settings.emulator.hack.entropy = "Low";
		});

	entropyHigh.setText(bmt::get("Settings.Compatibility.entropy.High").data())
		.setToolTip(bmt::get("Settings.Compatibility.entropy.High.tooltip").data())
		.onActivate([&] {
			settings.emulator.hack.entropy = "High";
		});

	auto entropy = settings.emulator.hack.entropy;

	if (entropy == "None") {
		entropyNone.setChecked();
	}
	else if (entropy == "Low" ) {
		entropyLow.setChecked();
	}
	else if (entropy == "High") {
		entropyHigh.setChecked();
	}

	cpuLabel.setFont(Font().setBold()).setText({"CPU (", bmt::get("Settings.Compatibility.cpu.Processor").data(), ")"});

	fastMath.setText(bmt::get("Settings.Compatibility.cpu.FastMath").data())
		.setToolTip(bmt::get("Settings.Compatibility.cpu.FastMath.tooltip").data())
		.setChecked(settings.emulator.hack.cpu.fastMath).onToggle([&] {
			settings.emulator.hack.cpu.fastMath = fastMath.checked();
			emulator->configure("Hacks/CPU/FastMath", settings.emulator.hack.cpu.fastMath);
		});

	ppuLabel.setFont(Font().setBold()).setText({"PPU (", bmt::get("Settings.Compatibility.ppu.Video").data(), ")"});

	noVRAMBlocking.setText(bmt::get("Settings.Compatibility.ppu.NoVramBlocking").data())
		.setToolTip(bmt::get("Settings.Compatibility.ppu.NoVramBlocking.tooltip").data())
		.setChecked(settings.emulator.hack.ppu.noVRAMBlocking).onToggle([&] {
			settings.emulator.hack.ppu.noVRAMBlocking = noVRAMBlocking.checked();
			emulator->configure("Hacks/PPU/NoVRAMBlocking", settings.emulator.hack.ppu.noVRAMBlocking);
		});

	dspLabel.setFont(Font().setBold()).setText({"DSP (", bmt::get("Settings.Compatibility.dsp.Audio").data(), ")"});

	echoShadow.setText(bmt::get("Settings.Compatibility.dsp.EchoShadowRam").data())
		.setToolTip(bmt::get("Settings.Compatibility.dsp.EchoShadowRam.tooltip").data())
		.setChecked(settings.emulator.hack.dsp.echoShadow).onToggle([&] {
			settings.emulator.hack.dsp.echoShadow = echoShadow.checked();
			//not a run-time setting: do not call emulator->configure() here.
		});

	note.setText(bmt::get("Settings.noteGameRestart").data());
}