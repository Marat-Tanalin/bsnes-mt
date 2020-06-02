#include "bsnes-mt/strings.h" // MT.

namespace bms = bsnesMt::strings; // MT.

auto CompatibilitySettings::create() -> void {
  setCollapsible();
  setVisible(false);

  entropyLabel.setText(bms::get("Settings.Compatibility.entropy").data()).setFont(Font().setBold()); // "Entropy (randomization)"
  entropyNone.setText(bms::get("Common.None").data()).setToolTip( // "None"
    bms::get("Settings.Compatibility.entropy.None.tooltip").data()
  ).onActivate([&] {
    settings.emulator.hack.entropy = "None";
  });
  entropyLow.setText(bms::get("Settings.Compatibility.entropy.Low").data()).setToolTip( // "Low"
    bms::get("Settings.Compatibility.entropy.Low.tooltip").data()
  ).onActivate([&] {
    settings.emulator.hack.entropy = "Low";
  });
  entropyHigh.setText(bms::get("Settings.Compatibility.entropy.High").data()).setToolTip( // "High"
    bms::get("Settings.Compatibility.entropy.High.tooltip").data()
  ).onActivate([&] {
    settings.emulator.hack.entropy = "High";
  });
  if(settings.emulator.hack.entropy == "None") entropyNone.setChecked();
  if(settings.emulator.hack.entropy == "Low" ) entropyLow.setChecked();
  if(settings.emulator.hack.entropy == "High") entropyHigh.setChecked();

  cpuLabel.setFont(Font().setBold()).setText({"CPU (", bms::get("Settings.Compatibility.cpu.processor").data(), ')'}); // "CPU (processor)"
  fastMath.setText(bms::get("Settings.Compatibility.cpu.FastMath").data()).setToolTip( // "Fast math"
    bms::get("Settings.Compatibility.cpu.FastMath.tooltip").data()
  ).setChecked(settings.emulator.hack.cpu.fastMath).onToggle([&] {
    settings.emulator.hack.cpu.fastMath = fastMath.checked();
    emulator->configure("Hacks/CPU/FastMath", settings.emulator.hack.cpu.fastMath);
  });

  ppuLabel.setFont(Font().setBold()).setText({"PPU (", bms::get("Settings.Compatibility.ppu.video").data(), ')'}); // "PPU (video)"
  noVRAMBlocking.setText(bms::get("Settings.Compatibility.ppu.NoVramBlocking").data()).setToolTip( // "No VRAM blocking"
    bms::get("Settings.Compatibility.ppu.NoVramBlocking.tooltip").data()
  ).setChecked(settings.emulator.hack.ppu.noVRAMBlocking).onToggle([&] {
    settings.emulator.hack.ppu.noVRAMBlocking = noVRAMBlocking.checked();
    emulator->configure("Hacks/PPU/NoVRAMBlocking", settings.emulator.hack.ppu.noVRAMBlocking);
  });

  dspLabel.setFont(Font().setBold()).setText({"DSP (", bms::get("Settings.Compatibility.dsp.audio").data(), ')'}); // "DSP (audio)"
  echoShadow.setText(bms::get("Settings.Compatibility.dsp.EchoShadowRam").data()).setToolTip( // "Echo shadow RAM"
    bms::get("Settings.Compatibility.dsp.EchoShadowRam.tooltip").data()
  ).setChecked(settings.emulator.hack.dsp.echoShadow).onToggle([&] {
    settings.emulator.hack.dsp.echoShadow = echoShadow.checked();
    //not a run-time setting: do not call emulator->configure() here.
  });

  note.setText(bms::get("Settings.noteGameRestart").data()); // "Note: some settings do not take effect until after reloading games."
}
