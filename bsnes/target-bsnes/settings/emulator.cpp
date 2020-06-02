#include "bsnes-mt/strings.h" // MT.

namespace bms = bsnesMt::strings; // MT.

auto EmulatorSettings::create() -> void {
  setCollapsible();
  setVisible(false);

  optionsLabel.setText(bms::get("Settings.Emulator.Options").data()).setFont(Font().setBold()); // "Options"
  warnOnUnverifiedGames.setText(bms::get("Settings.Emulator.warnOnUnverifiedGames").data()).setChecked(settings.emulator.warnOnUnverifiedGames).onToggle([&] { // "Warn when loading games that have not been verified"
    settings.emulator.warnOnUnverifiedGames = warnOnUnverifiedGames.checked();
  });
  autoSaveMemory.setText(bms::get("Settings.Emulator.autoSaveMemory").data()).setChecked(settings.emulator.autoSaveMemory.enable).onToggle([&] { // "Auto-save memory periodically"
    settings.emulator.autoSaveMemory.enable = autoSaveMemory.checked();
  });
  autoSaveStateOnUnload.setText(bms::get("Settings.Emulator.autoSaveStateOnUnload").data()).setChecked(settings.emulator.autoSaveStateOnUnload).onToggle([&] { // "Auto-save undo state when unloading games"
    settings.emulator.autoSaveStateOnUnload = autoSaveStateOnUnload.checked();
    if(!autoSaveStateOnUnload.checked()) {
      autoLoadStateOnLoad.setEnabled(false).setChecked(false).doToggle();
    } else {
      autoLoadStateOnLoad.setEnabled(true);
    }
  }).doToggle();
  autoLoadStateOnLoad.setText(bms::get("Settings.Emulator.AutoResumeOnLoad").data()).setChecked(settings.emulator.autoLoadStateOnLoad).onToggle([&] { // "Auto-resume on load"
    settings.emulator.autoLoadStateOnLoad = autoLoadStateOnLoad.checked();
  });
  nativeFileDialogs.setText(bms::get("Settings.Emulator.UseNativeFileFialogs").data()).setChecked(settings.general.nativeFileDialogs).onToggle([&] { // "Use native file dialogs"
    settings.general.nativeFileDialogs = nativeFileDialogs.checked();
  });
  optionsSpacer.setColor({192, 192, 192});

  fastForwardLabel.setText(bms::get("Settings.Emulator.FastForward").data()).setFont(Font().setBold()); // "Fast Forward"

  char colon = ':';

  frameSkipLabel.setText({bms::get("Settings.Emulator.FastForward.FrameSkip").data(), colon}).setToolTip({ // "Frame skip:"
    bms::get("Settings.Emulator.FastForward.FrameSkip.tooltip").data()
  });

  string noneString   = bms::get("Common.None").data(); // MT.
  string framesString = bms::get("Common.Frames").data(); // MT.

  frameSkipAmount.append(ComboButtonItem().setText(noneString)); // "None"
  frameSkipAmount.append(ComboButtonItem().setText({"1 ", bms::get("Common.Frame").data()})); // frame
  frameSkipAmount.append(ComboButtonItem().setText({"2 ", framesString})); // frames
  frameSkipAmount.append(ComboButtonItem().setText({"3 ", framesString})); // frames
  frameSkipAmount.append(ComboButtonItem().setText({"4 ", framesString})); // frames
  frameSkipAmount.append(ComboButtonItem().setText({"5 ", framesString})); // frames
  frameSkipAmount.append(ComboButtonItem().setText({"6 ", framesString})); // frames
  frameSkipAmount.append(ComboButtonItem().setText({"7 ", framesString})); // frames
  frameSkipAmount.append(ComboButtonItem().setText({"8 ", framesString})); // frames
  frameSkipAmount.append(ComboButtonItem().setText({"9 ", framesString})); // frames
  frameSkipAmount.item(settings.fastForward.frameSkip).setSelected();
  frameSkipAmount.onChange([&] {
    settings.fastForward.frameSkip = frameSkipAmount.selected().offset();
  });

  limiterLabel.setText({bms::get("Settings.Emulator.FastForward.Limiter").data(), colon}).setToolTip({ // "Limiter:"
    bms::get("Settings.Emulator.FastForward.Limiter.tooltip").data() // "Set the maximum speed when fast forwarding."
  });

  limiterAmount.append(ComboButtonItem().setText(noneString)); // "None"
  limiterAmount.append(ComboButtonItem().setText("200%"));
  limiterAmount.append(ComboButtonItem().setText("300%"));
  limiterAmount.append(ComboButtonItem().setText("400%"));
  limiterAmount.append(ComboButtonItem().setText("500%"));
  limiterAmount.append(ComboButtonItem().setText("600%"));
  limiterAmount.append(ComboButtonItem().setText("700%"));
  limiterAmount.append(ComboButtonItem().setText("800%"));
  if(settings.fastForward.limiter == 0) limiterAmount.item(0).setSelected();
  if(settings.fastForward.limiter == 2) limiterAmount.item(1).setSelected();
  if(settings.fastForward.limiter == 3) limiterAmount.item(2).setSelected();
  if(settings.fastForward.limiter == 4) limiterAmount.item(3).setSelected();
  if(settings.fastForward.limiter == 5) limiterAmount.item(4).setSelected();
  if(settings.fastForward.limiter == 6) limiterAmount.item(5).setSelected();
  if(settings.fastForward.limiter == 7) limiterAmount.item(6).setSelected();
  if(settings.fastForward.limiter == 8) limiterAmount.item(7).setSelected();
  limiterAmount.onChange([&] {
    auto index = limiterAmount.selected().offset();
    if(index == 0) settings.fastForward.limiter = 0;
    if(index == 1) settings.fastForward.limiter = 2;
    if(index == 2) settings.fastForward.limiter = 3;
    if(index == 3) settings.fastForward.limiter = 4;
    if(index == 4) settings.fastForward.limiter = 5;
    if(index == 5) settings.fastForward.limiter = 6;
    if(index == 6) settings.fastForward.limiter = 7;
    if(index == 7) settings.fastForward.limiter = 8;
  });

  fastForwardMute.setText(bms::get("Settings.Emulator.FastForward.fastForwardMute").data()).setChecked(settings.fastForward.mute).onToggle([&] { // "Mute while fast forwarding"
    settings.fastForward.mute = fastForwardMute.checked();
  });

  fastForwardSpacer.setColor({192, 192, 192});

  rewindLabel.setText(bms::get("Settings.Emulator.Rewind").data()).setFont(Font().setBold()); // "Rewind"

  string everyString = bms::get("Settings.Emulator.Rewind.Frequency.Every").data(); // MT.

  rewindFrequencyLabel.setText({bms::get("Settings.Emulator.Rewind.Frequency").data(), colon}); // "Frequency:"
  rewindFrequencyOption.append(ComboButtonItem().setText(bms::get("Common.Disabled").data())); // "Disabled"
  rewindFrequencyOption.append(ComboButtonItem().setText({everyString, " 10 ", framesString})); // "Every 10 frames"
  rewindFrequencyOption.append(ComboButtonItem().setText({everyString, " 20 ", framesString})); // "Every 20 frames"
  rewindFrequencyOption.append(ComboButtonItem().setText({everyString, " 30 ", framesString})); // "Every 30 frames"
  rewindFrequencyOption.append(ComboButtonItem().setText({everyString, " 40 ", framesString})); // "Every 40 frames"
  rewindFrequencyOption.append(ComboButtonItem().setText({everyString, " 50 ", framesString})); // "Every 50 frames"
  rewindFrequencyOption.append(ComboButtonItem().setText({everyString, " 60 ", framesString})); // "Every 60 frames"
  if(settings.rewind.frequency ==  0) rewindFrequencyOption.item(0).setSelected();
  if(settings.rewind.frequency == 10) rewindFrequencyOption.item(1).setSelected();
  if(settings.rewind.frequency == 20) rewindFrequencyOption.item(2).setSelected();
  if(settings.rewind.frequency == 30) rewindFrequencyOption.item(3).setSelected();
  if(settings.rewind.frequency == 40) rewindFrequencyOption.item(4).setSelected();
  if(settings.rewind.frequency == 50) rewindFrequencyOption.item(5).setSelected();
  if(settings.rewind.frequency == 60) rewindFrequencyOption.item(6).setSelected();
  rewindFrequencyOption.onChange([&] {
    settings.rewind.frequency = rewindFrequencyOption.selected().offset() * 10;
    program.rewindReset();
  });

  string statesString = bms::get("Settings.Emulator.Rewind.States").data(); // MT.

  rewindLengthLabel.setText({bms::get("Settings.Emulator.Rewind.Length").data(), colon}); // "Length:"
  rewindLengthOption.append(ComboButtonItem().setText({ "10 ", statesString})); //  "10 states"
  rewindLengthOption.append(ComboButtonItem().setText({ "20 ", statesString})); //  "20 states"
  rewindLengthOption.append(ComboButtonItem().setText({ "40 ", statesString})); //  "40 states"
  rewindLengthOption.append(ComboButtonItem().setText({ "80 ", statesString})); //  "80 states"
  rewindLengthOption.append(ComboButtonItem().setText({"160 ", statesString})); // "160 states"
  rewindLengthOption.append(ComboButtonItem().setText({"320 ", statesString})); // "320 states"
  if(settings.rewind.length ==  10) rewindLengthOption.item(0).setSelected();
  if(settings.rewind.length ==  20) rewindLengthOption.item(1).setSelected();
  if(settings.rewind.length ==  40) rewindLengthOption.item(2).setSelected();
  if(settings.rewind.length ==  80) rewindLengthOption.item(3).setSelected();
  if(settings.rewind.length == 160) rewindLengthOption.item(4).setSelected();
  if(settings.rewind.length == 320) rewindLengthOption.item(5).setSelected();
  rewindLengthOption.onChange([&] {
    settings.rewind.length = 10 << rewindLengthOption.selected().offset();
    program.rewindReset();
  });

  rewindMute.setText(bms::get("Settings.Emulator.Rewind.mute").data()).setChecked(settings.rewind.mute).onToggle([&] { // "Mute while rewinding"
    settings.rewind.mute = rewindMute.checked();
  });
}
