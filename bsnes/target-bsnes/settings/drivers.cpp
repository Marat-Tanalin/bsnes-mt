#include "bsnes-mt/strings.h" // MT.

namespace bms = bsnesMt::strings; // MT.

auto DriverSettings::create() -> void {
  setCollapsible();
  setVisible(false);

  const char   colon        = ':';
  const string driverString = {bms::get("Settings.Drivers.Driver").data(), colon}; // MT.
  const string changeString = bms::get("Settings.Drivers.Change").data(); // MT.

  videoLabel.setText(bms::get("Settings.Drivers.Video").data()).setFont(Font().setBold()); // "Video"
  videoDriverLabel.setText(driverString); // "Driver:"
  videoDriverOption.onChange([&] {
    // Crashes (without `.data()`) or works incorrectly (with `.data()`) with prepared "Change" and "Reload" strings.
    videoDriverUpdate.setText(videoDriverOption.selected().text() != video.driver() ? bms::get("Settings.Drivers.Change").data() : bms::get("Settings.Drivers.Reload").data());
  });
  videoDriverUpdate.setText(changeString).onActivate([&] { videoDriverChange(); }); // "Change"
  videoMonitorLabel.setText({bms::get("Settings.Drivers.Video.FullscreenMonitor").data(), colon}).setToolTip( // "Fullscreen monitor:"
    bms::get("Settings.Drivers.Video.FullscreenMonitor.tooltip").data()
  );
  videoMonitorOption.onChange([&] { videoMonitorChange(); });
  videoFormatLabel.setText({bms::get("Settings.Drivers.Video.Format").data(), colon}); // "Format:"
  videoFormatOption.onChange([&] { videoFormatChange(); });
  videoExclusiveToggle.setText(bms::get("Settings.Drivers.ExclusiveMode").data()).setToolTip( // "Exclusive mode"
    bms::get("Settings.Drivers.Video.ExclusiveMode.tooltip").data()
  ).onToggle([&] {
    settings.video.exclusive = videoExclusiveToggle.checked();
    program.updateVideoExclusive();
  });
  videoBlockingToggle.setText(bms::get("Settings.Drivers.Synchronize").data()).setToolTip( // "Synchronize"
    bms::get("Settings.Drivers.Video.Synchronize.tooltip").data()
  ).onToggle([&] {
    settings.video.blocking = videoBlockingToggle.checked();
    program.updateVideoBlocking();
    presentation.speedMenu.setEnabled(!videoBlockingToggle.checked() && audioBlockingToggle.checked());
  });
  videoFlushToggle.setText(bms::get("Settings.Drivers.Video.GpuSync").data()).setToolTip( // "GPU sync"
    bms::get("Settings.Drivers.Video.GpuSync.tooltip").data()
  ).onToggle([&] {
    settings.video.flush = videoFlushToggle.checked();
    program.updateVideoFlush();
  });
  videoSpacer.setColor({192, 192, 192});

  audioLabel.setText(bms::get("Settings.Drivers.Audio").data()).setFont(Font().setBold()); // "Audio"
  audioDriverLabel.setText(driverString); // "Driver:"
  audioDriverOption.onChange([&] {
    audioDriverUpdate.setText(audioDriverOption.selected().text() != audio.driver() ? bms::get("Settings.Drivers.Change").data() : bms::get("Settings.Drivers.Reload").data());
  });
  audioDriverUpdate.setText(changeString).onActivate([&] { audioDriverChange(); }); // "Change"
  audioDeviceLabel.setText({bms::get("Settings.Drivers.Audio.OutputDevice").data(), colon}); // "Output device:"
  audioDeviceOption.onChange([&] { audioDeviceChange(); });
  audioFrequencyLabel.setText({bms::get("Settings.Drivers.Audio.Frequency").data(), colon}); // "Frequency:"
  audioFrequencyOption.onChange([&] { audioFrequencyChange(); });
  audioLatencyLabel.setText({bms::get("Settings.Drivers.Audio.Latency").data(), colon}); // "Latency:"
  audioLatencyOption.onChange([&] { audioLatencyChange(); });
  audioExclusiveToggle.setText(bms::get("Settings.Drivers.ExclusiveMode").data()).setToolTip( // "Exclusive mode"
    bms::get("Settings.Drivers.Audio.ExclusiveMode.tooltip").data()
  ).onToggle([&] {
    settings.audio.exclusive = audioExclusiveToggle.checked();
    program.updateAudioExclusive();
  });
  audioBlockingToggle.setText(bms::get("Settings.Drivers.Synchronize").data()).setToolTip( // "Synchronize"
    bms::get("Settings.Drivers.Audio.Synchronize.tooltip").data()
  ).onToggle([&] {
    settings.audio.blocking = audioBlockingToggle.checked();
    program.updateAudioBlocking();
    presentation.speedMenu.setEnabled(!videoBlockingToggle.checked() && audioBlockingToggle.checked());
  });
  audioDynamicToggle.setText(bms::get("Settings.Drivers.Audio.DynamicRate").data()).setToolTip( // "Dynamic rate"
    bms::get("Settings.Drivers.Audio.DynamicRate.tooltip").data()
  ).onToggle([&] {
    settings.audio.dynamic = audioDynamicToggle.checked();
    program.updateAudioDynamic();
  });
  audioSpacer.setColor({192, 192, 192});

  inputLabel.setText(bms::get("Settings.Drivers.Input").data()).setFont(Font().setBold()); // "Input"
  inputDriverLabel.setText(driverString);
  inputDriverOption.onChange([&] {
    inputDriverUpdate.setText(inputDriverOption.selected().text() != input.driver() ? bms::get("Settings.Drivers.Change").data() : bms::get("Settings.Drivers.Reload").data());
  });
  inputDriverUpdate.setText(changeString).setToolTip(
    bms::get("Settings.Drivers.Input.Reload.tooltip").data()
  ).onActivate([&] { inputDriverChange(); });
  inputSpacer.setColor({192, 192, 192});

  syncModeLabel.setText({bms::get("Settings.Drivers.syncModePresets").data(), colon}).setFont(Font().setBold()); // "Synchronization Mode Presets:"
  syncModeRequirements.setText(
    bms::get("Settings.Drivers.syncModePresets.requirements").data()
  );
  adaptiveSyncMode.setText(bms::get("Settings.Drivers.syncModePresets.AdaptiveSync").data()).onActivate([&] { // "Adaptive Sync"
    if(!audioBlockingToggle.enabled()) {
      return (void)MessageDialog().setAlignment(settingsWindow).setTitle(bms::get("Common.Failure").data()).setText({ // "Failure"
        bms::get("Settings.Drivers.syncModePresets.AdaptiveSync.Failure.tooltip").data()
      }).error();
    }

    if(videoExclusiveToggle.enabled() && !videoExclusiveToggle.checked()) videoExclusiveToggle.setChecked(true).doToggle();
    if(videoBlockingToggle.enabled() && videoBlockingToggle.checked()) videoBlockingToggle.setChecked(false).doToggle();
    if(audioBlockingToggle.enabled() && !audioBlockingToggle.checked()) audioBlockingToggle.setChecked(true).doToggle();
    if(audioDynamicToggle.enabled() && audioDynamicToggle.checked()) audioDynamicToggle.setChecked(false).doToggle();

    MessageDialog().setAlignment(settingsWindow).setTitle(bms::get("Common.Success").data()).setText({ // "Success"
      bms::get("Settings.Drivers.syncModePresets.AdaptiveSync.Success.tooltip").data()
    }).information();
  });
  dynamicRateControlMode.setText(bms::get("Settings.Drivers.syncModePresets.DynamicRateControl").data()).onActivate([&] { // "Dynamic Rate Control"
    if(!videoBlockingToggle.enabled() || !audioDynamicToggle.enabled()) {
      return (void)MessageDialog().setAlignment(settingsWindow).setTitle(bms::get("Common.Failure").data()).setText({ // "Failure"
        bms::get("Settings.Drivers.syncModePresets.DynamicRateControl.Failure.tooltip").data()
      }).error();
    }

    if(videoBlockingToggle.enabled() && !videoBlockingToggle.checked()) videoBlockingToggle.setChecked(true).doToggle();
    if(audioExclusiveToggle.enabled() && !audioExclusiveToggle.checked()) audioExclusiveToggle.setChecked(true).doToggle();
    if(audioBlockingToggle.enabled() && audioBlockingToggle.checked()) audioBlockingToggle.setChecked(false).doToggle();
    if(audioDynamicToggle.enabled() && !audioDynamicToggle.checked()) audioDynamicToggle.setChecked(true).doToggle();

    MessageDialog().setAlignment(settingsWindow).setTitle(bms::get("Common.Success").data()).setText({ // "Success"
      bms::get("Settings.Drivers.syncModePresets.DynamicRateControl.Success.tooltip").data()
    }).information();
  });
}

//

auto DriverSettings::videoDriverChanged() -> void {
  videoDriverOption.reset();
  for(auto& driver : video.hasDrivers()) {
    ComboButtonItem item{&videoDriverOption};
    item.setText(driver);
    if(driver == video.driver()) item.setSelected();
  }
  videoDriverActive.setText({bms::get("Settings.Drivers.ActiveDriver").data(), ": ", video.driver()}); // "Active driver"
  videoDriverOption.doChange();
  videoMonitorChanged();
  videoFormatChanged();
  videoExclusiveToggle.setChecked(video.exclusive()).setEnabled(video.hasExclusive());
  videoBlockingToggle.setChecked(video.blocking()).setEnabled(video.hasBlocking());
  videoFlushToggle.setChecked(video.flush()).setEnabled(video.hasFlush());
  setGeometry(geometry());
}

auto DriverSettings::videoDriverChange() -> void {
  auto item = videoDriverOption.selected();
  settings.video.driver = item.text();
  if(!emulator->loaded() || item.text() == "None" || MessageDialog(
    bms::get("Settings.Drivers.changeConfirm").data()
  ).setAlignment(*settingsWindow).question() == "Yes") {
    program.save();
    program.saveUndoState();
    settings.general.crashed = true;
    settings.save();
    program.updateVideoDriver(settingsWindow);
    settings.general.crashed = false;
    settings.save();
    videoDriverChanged();
  }
}

auto DriverSettings::videoMonitorChanged() -> void {
  videoMonitorOption.reset();
  for(auto& monitor : Video::hasMonitors()) {
    ComboButtonItem item{&videoMonitorOption};
    item.setText(monitor.name);
    if(monitor.name == video.monitor()) item.setSelected();
  }
  videoMonitorOption.setEnabled(videoMonitorOption.itemCount() > 1);
  setGeometry(geometry());
  videoMonitorChange();
}

auto DriverSettings::videoMonitorChange() -> void {
  auto item = videoMonitorOption.selected();
  settings.video.monitor = item.text();
  program.updateVideoMonitor();
}

auto DriverSettings::videoFormatChanged() -> void {
  videoFormatOption.reset();
  for(auto& format : video.hasFormats()) {
    ComboButtonItem item{&videoFormatOption};
    item.setText(format);
    if(format == video.format()) item.setSelected();
  }
  videoFormatOption.setEnabled(videoFormatOption.itemCount() > 1);
  setGeometry(geometry());
  videoFormatChange();
}

auto DriverSettings::videoFormatChange() -> void {
  auto item = videoFormatOption.selected();
  settings.video.format = item.text();
  program.updateVideoFormat();
}

//

auto DriverSettings::audioDriverChanged() -> void {
  audioDriverOption.reset();
  for(auto& driver : audio.hasDrivers()) {
    ComboButtonItem item{&audioDriverOption};
    item.setText(driver);
    if(driver == audio.driver()) item.setSelected();
  }
  audioDriverActive.setText({bms::get("Settings.Drivers.ActiveDriver").data(), ": ", audio.driver()}); // "Active driver: "
  audioDriverOption.doChange();
  audioDeviceChanged();
  audioFrequencyChanged();
  audioLatencyChanged();
  audioExclusiveToggle.setChecked(audio.exclusive()).setEnabled(audio.hasExclusive());
  audioBlockingToggle.setChecked(audio.blocking()).setEnabled(audio.hasBlocking());
  audioDynamicToggle.setChecked(audio.dynamic()).setEnabled(audio.hasDynamic());
  setGeometry(geometry());
}

auto DriverSettings::audioDriverChange() -> void {
  auto item = audioDriverOption.selected();
  settings.audio.driver = item.text();
  if(!emulator->loaded() || item.text() == "None" || MessageDialog(
    bms::get("Settings.Drivers.changeConfirm").data()
  ).setAlignment(*settingsWindow).question() == "Yes") {
    program.save();
    program.saveUndoState();
    settings.general.crashed = true;
    settings.save();
    program.updateAudioDriver(settingsWindow);
    settings.general.crashed = false;
    settings.save();
    audioDriverChanged();
  }
}

auto DriverSettings::audioDeviceChanged() -> void {
  audioDeviceOption.reset();
  for(auto& device : audio.hasDevices()) {
    ComboButtonItem item{&audioDeviceOption};
    item.setText(device);
    if(device == audio.device()) item.setSelected();
  }
//audioDeviceOption.setEnabled(audio->hasDevice());
  setGeometry(geometry());
}

auto DriverSettings::audioDeviceChange() -> void {
  auto item = audioDeviceOption.selected();
  settings.audio.device = item.text();
  program.updateAudioDevice();
  audioFrequencyChanged();
  audioLatencyChanged();
}

auto DriverSettings::audioFrequencyChanged() -> void {
  audioFrequencyOption.reset();
  for(auto& frequency : audio.hasFrequencies()) {
    ComboButtonItem item{&audioFrequencyOption};
    item.setText({frequency, " Hz"});
    if(frequency == audio.frequency()) item.setSelected();
  }
//audioFrequencyOption.setEnabled(audio->hasFrequency());
  setGeometry(geometry());
}

auto DriverSettings::audioFrequencyChange() -> void {
  auto item = audioFrequencyOption.selected();
  settings.audio.frequency = item.text().natural();
  program.updateAudioFrequency();
}

auto DriverSettings::audioLatencyChanged() -> void {
  audioLatencyOption.reset();
  for(auto& latency : audio.hasLatencies()) {
    ComboButtonItem item{&audioLatencyOption};
    item.setText(latency);
    if(latency == audio.latency()) item.setSelected();
  }
//audioLatencyOption.setEnabled(audio->hasLatency());
  setGeometry(geometry());
}

auto DriverSettings::audioLatencyChange() -> void {
  auto item = audioLatencyOption.selected();
  settings.audio.latency = item.text().natural();
  program.updateAudioLatency();
}

//

auto DriverSettings::inputDriverChanged() -> void {
  inputDriverOption.reset();
  for(auto& driver : input.hasDrivers()) {
    ComboButtonItem item{&inputDriverOption};
    item.setText(driver);
    if(driver == input.driver()) item.setSelected();
  }
  inputDriverActive.setText({bms::get("Settings.Drivers.ActiveDriver").data(), ": ", input.driver()}); // "Active driver: "
  inputDriverOption.doChange();
  setGeometry(geometry());
}

auto DriverSettings::inputDriverChange() -> void {
  auto item = inputDriverOption.selected();
  settings.input.driver = item.text();
  if(!emulator->loaded() || item.text() == "None" || MessageDialog(
    bms::get("Settings.Drivers.changeConfirm").data()
  ).setAlignment(*settingsWindow).question() == "Yes") {
    program.save();
    program.saveUndoState();
    settings.general.crashed = true;
    settings.save();
    program.updateInputDriver(settingsWindow);
    settings.general.crashed = false;
    settings.save();
    inputDriverChanged();
  }
}
