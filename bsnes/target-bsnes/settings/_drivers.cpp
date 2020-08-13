/* MT. */
#include "bsnes-mt/strings.h"
#include "bsnes-mt/messagebox.h"

namespace bms = bsnesMt::strings;
namespace bmw = bsnesMt::windows;
/* /MT. */

auto DriverSettings::create() -> void {
	setCollapsible();
	setVisible(false);

	/* MT. */
	char colon = ':';
	const string driverString = {bms::get("Settings.Drivers.Driver").data(), colon};
	const string changeString = bms::get("Settings.Drivers.Change").data();
	/* /MT. */

	videoLabel.setText(bms::get("Common.Video").data()).setFont(Font().setBold());
	videoDriverLabel.setText(driverString);

	videoDriverOption.onChange([&] {
		/* MT. */
		// Crashes (without `.data()`) or works incorrectly (with `.data()`) with prepared "Change", "Reload", "None", and translated "None" strings.
		string driverTranslated = videoDriverOption.selected().text();
		string driver           = driverTranslated == bms::get("Common.None").data() ? "None" : driverTranslated;
		/* /MT. */

		videoDriverUpdate.setText(driver == video.driver() ? bms::get("Settings.Drivers.Reload").data() : bms::get("Settings.Drivers.Change").data());
	});

	videoDriverUpdate.setText(changeString).onActivate([&] {
		videoDriverChange();
	});

	videoMonitorLabel.setText({bms::get("Settings.Drivers.Video.FullScreenMonitor").data(), colon})
		.setToolTip(bms::get("Settings.Drivers.Video.FullScreenMonitor.tooltip").data());

	videoMonitorOption.onChange([&] {
		videoMonitorChange();
	});

	videoFormatLabel.setText({bms::get("Settings.Drivers.Video.Format").data(), colon});

	videoFormatOption.onChange([&] {
		videoFormatChange();
	});

	videoExclusiveToggle.setText(bms::get("Settings.Drivers.ExclusiveMode").data())
		.setToolTip(bms::get("Settings.Drivers.Video.ExclusiveMode.tooltip").data())
		.onToggle([&] {
			settings.video.exclusive = videoExclusiveToggle.checked();
			program.updateVideoExclusive();
		});

	videoBlockingToggle.setText(bms::get("Settings.Drivers.Synchronize").data())
		.setToolTip(bms::get("Settings.Drivers.Video.Synchronize.tooltip").data())
		.onToggle([&] {
			settings.video.blocking = videoBlockingToggle.checked();
			program.updateVideoBlocking();
			presentation.speedMenu.setEnabled(!videoBlockingToggle.checked() && audioBlockingToggle.checked());
		});

	videoFlushToggle.setText(bms::get("Settings.Drivers.Video.GpuSync").data())
		.setToolTip(bms::get("Settings.Drivers.Video.GpuSync.tooltip").data())
		.onToggle([&] {
			settings.video.flush = videoFlushToggle.checked();
			program.updateVideoFlush();
		});

	Color spacerColor = {192, 192, 192}; // MT.

	videoSpacer.setColor(spacerColor);

	audioLabel.setText(bms::get("Common.Audio").data()).setFont(Font().setBold());
	audioDriverLabel.setText(driverString);

	audioDriverOption.onChange([&] {
		/* MT. */
		string driverTranslated = audioDriverOption.selected().text();
		string driver           = driverTranslated == bms::get("Common.None").data() ? "None" : driverTranslated;
		/* /MT. */

		audioDriverUpdate.setText(driver == audio.driver() ? bms::get("Settings.Drivers.Reload").data() : bms::get("Settings.Drivers.Change").data());
	});

	audioDriverUpdate.setText(changeString).onActivate([&] {
		audioDriverChange();
	});

	audioDeviceLabel.setText({bms::get("Settings.Drivers.Audio.OutputDevice").data(), colon});

	audioDeviceOption.onChange([&] {
		audioDeviceChange();
	});

	audioFrequencyLabel.setText({bms::get("Settings.Drivers.Audio.SampleRate").data(), colon});

	audioFrequencyOption.onChange([&] {
		audioFrequencyChange();
	});

	audioLatencyLabel.setText({bms::get("Settings.Drivers.Audio.Latency").data(), colon});

	audioLatencyOption.onChange([&] {
		audioLatencyChange();
	});

	audioExclusiveToggle.setText(bms::get("Settings.Drivers.ExclusiveMode").data())
		.setToolTip(bms::get("Settings.Drivers.Audio.ExclusiveMode.tooltip").data())
		.onToggle([&] {
			settings.audio.exclusive = audioExclusiveToggle.checked();
			program.updateAudioExclusive();
		});

	audioBlockingToggle.setText(bms::get("Settings.Drivers.Synchronize").data())
		.setToolTip(bms::get("Settings.Drivers.Audio.Synchronize.tooltip").data())
		.onToggle([&] {
			settings.audio.blocking = audioBlockingToggle.checked();
			program.updateAudioBlocking();
			presentation.speedMenu.setEnabled(!videoBlockingToggle.checked() && audioBlockingToggle.checked());
		});

	audioDynamicToggle.setText(bms::get("Settings.Drivers.Audio.DynamicRate").data())
		.setToolTip(bms::get("Settings.Drivers.Audio.DynamicRate.tooltip").data())
		.onToggle([&] {
			settings.audio.dynamic = audioDynamicToggle.checked();
			program.updateAudioDynamic();
		});

	audioSpacer.setColor(spacerColor);

	inputLabel.setText(bms::get("Settings.Input").data()).setFont(Font().setBold());
	inputDriverLabel.setText(driverString);

	inputDriverOption.onChange([&] {
		/* MT. */
		string driverTranslated = inputDriverOption.selected().text();
		string driver           = driverTranslated == bms::get("Common.None").data() ? "None" : driverTranslated;
		/* /MT. */

		inputDriverUpdate.setText(driver == input.driver() ? bms::get("Settings.Drivers.Reload").data() : bms::get("Settings.Drivers.Change").data());
	});

	inputDriverUpdate.setText(changeString)
		.setToolTip(bms::get("Settings.Drivers.Input.Reload.tooltip").data())
		.onActivate([&] {
			inputDriverChange();
		});

	inputSpacer.setColor(spacerColor);

	syncModeLabel.setText({bms::get("Settings.Drivers.syncModePresets").data(), colon}).setFont(Font().setBold());

	syncModeRequirements.setText(
		bms::get("Settings.Drivers.syncModePresets.requirements").data()
	);

	adaptiveSyncMode.setText(bms::get("Settings.Drivers.syncModePresets.AdaptiveSync").data()).onActivate([&] {
		if (!audioBlockingToggle.enabled()) {
			/* // Commented-out by MT.
			return (void)MessageDialog().setAlignment(settingsWindow).setTitle(bms::get("Common.Failure").data()).setText({
				bms::get("Settings.Drivers.syncModePresets.AdaptiveSync.failure").data()
			}).error();
			*/

			/* MT. */
			bmw::showError(
				bms::get("Settings.Drivers.syncModePresets.AdaptiveSync.failure"),
				bms::get("Common.Failure"),
				settingsWindow.handle()
			);

			return;
			/* /MT. */
		}

		if (videoExclusiveToggle.enabled() && !videoExclusiveToggle.checked()) {
			videoExclusiveToggle.setChecked(true).doToggle();
		}

		if (videoBlockingToggle.enabled()  && videoBlockingToggle.checked()) {
			videoBlockingToggle.setChecked(false).doToggle();
		}

		if (audioBlockingToggle.enabled()  && !audioBlockingToggle.checked()) {
			audioBlockingToggle.setChecked(true).doToggle();
		}

		if (audioDynamicToggle.enabled()   && audioDynamicToggle.checked()) {
			audioDynamicToggle.setChecked(false).doToggle();
		}

		/* // Commented-out by MT.
		MessageDialog().setAlignment(settingsWindow).setTitle(bms::get("Common.Success").data()).setText({
			bms::get("Settings.Drivers.syncModePresets.AdaptiveSync.success").data()
		}).information();
		*/

		/* MT. */
		bmw::showInfo(
			bms::get("Settings.Drivers.syncModePresets.AdaptiveSync.success"),
			bms::get("Common.Success"),
			settingsWindow.handle()
		);
		/* /MT. */
	});

	dynamicRateControlMode.setText(bms::get("Settings.Drivers.syncModePresets.DynamicRateControl").data()).onActivate([&] {
		if (!videoBlockingToggle.enabled() || !audioDynamicToggle.enabled()) {
			/* // Commented-out by MT.
			return (void)MessageDialog().setAlignment(settingsWindow).setTitle(bms::get("Common.Failure").data()).setText({
				bms::get("Settings.Drivers.syncModePresets.DynamicRateControl.failure").data()
			}).error();
			*/

			/* MT. */
			bmw::showError(
				bms::get("Settings.Drivers.syncModePresets.DynamicRateControl.failure"),
				bms::get("Common.Failure"),
				settingsWindow.handle()
			);

			return;
			/* /MT. */
		}

		if (videoBlockingToggle.enabled()  && !videoBlockingToggle.checked()) {
			videoBlockingToggle.setChecked(true).doToggle();
		}

		if (audioExclusiveToggle.enabled() && !audioExclusiveToggle.checked()) {
			audioExclusiveToggle.setChecked(true).doToggle();
		}

		if (audioBlockingToggle.enabled()  && audioBlockingToggle.checked()) {
			audioBlockingToggle.setChecked(false).doToggle();
		}

		if (audioDynamicToggle.enabled()   && !audioDynamicToggle.checked()) {
			audioDynamicToggle.setChecked(true).doToggle();
		}

		/* // Commented-out by MT.
		MessageDialog().setAlignment(settingsWindow).setTitle(bms::get("Common.Success").data()).setText({
			bms::get("Settings.Drivers.syncModePresets.DynamicRateControl.success").data()
		}).information();
		*/

		/* MT. */
		bmw::showInfo(
			bms::get("Settings.Drivers.syncModePresets.DynamicRateControl.success"),
			bms::get("Common.Success"),
			settingsWindow.handle()
		);
		/* /MT. */
	});
}

//

auto DriverSettings::videoDriverChanged() -> void {
	videoDriverOption.reset();

	/* MT. */
	string none                   = "None";
	string noneTranslated         = bms::get("Common.None").data();
	string activeDriver           = video.driver();
	string activeDriverTranslated = activeDriver == none ? noneTranslated : activeDriver;
	/* /MT. */

	for (auto& driver : video.hasDrivers()) {
		ComboButtonItem item{&videoDriverOption};
		item.setText(driver == none ? noneTranslated : driver);

		if (driver == activeDriver) {
			item.setSelected();
		}
	}

	videoDriverActive.setText({bms::get("Settings.Drivers.ActiveDriver").data(), ": ", activeDriverTranslated});
	videoDriverOption.doChange();
	videoMonitorChanged();
	videoFormatChanged();
	videoExclusiveToggle.setChecked(video.exclusive()).setEnabled(video.hasExclusive());
	videoBlockingToggle.setChecked(video.blocking()).setEnabled(video.hasBlocking());
	videoFlushToggle.setChecked(video.flush()).setEnabled(video.hasFlush());
	setGeometry(geometry());
}

auto DriverSettings::videoDriverChange() -> void {
	auto   item     = videoDriverOption.selected();

	/* MT. */
	string itemText = item.text();
	bool   isNone   = itemText == bms::get("Common.None").data();
	/* /MT. */

	settings.video.driver = isNone ? "None" : itemText;

	/* // Commented-out by MT.
	if (!emulator->loaded() || isNone || MessageDialog(
		bms::get("Settings.Drivers.changeConfirm").data()
	).setAlignment(*settingsWindow).question({bms::get("Common.Yes").data(), bms::get("Common.No").data()}) == bms::get("Common.Yes").data()) {
	*/

	if (!emulator->loaded() || isNone || bmw::confirmById("Settings.Drivers.changeConfirm", settingsWindow->handle())) { // MT.
		program.save();
		program.saveUndoState();
		//settings.general.crashed = true;
		//settings.save();
		program.updateVideoDriver(settingsWindow);
		//settings.general.crashed = false;
		settings.save();
		videoDriverChanged();
	}
}

auto DriverSettings::videoMonitorChanged() -> void {
	videoMonitorOption.reset();

	for (auto& monitor : Video::hasMonitors()) {
		ComboButtonItem item{&videoMonitorOption};
		item.setText(monitor.name);

		if (monitor.name == video.monitor()) {
			item.setSelected();
		}
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

	for (auto& format : video.hasFormats()) {
		ComboButtonItem item{&videoFormatOption};
		item.setText(format);

		if (format == video.format()) {
			item.setSelected();
		}
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

	/* MT. */
	string none                   = "None";
	string noneTranslated         = bms::get("Common.None").data();
	string activeDriver           = audio.driver();
	string activeDriverTranslated = activeDriver == none ? noneTranslated : activeDriver;
	/* /MT. */

	for (auto& driver : audio.hasDrivers()) {
		ComboButtonItem item{&audioDriverOption};
		item.setText(driver == none ? noneTranslated : driver);

		if (driver == activeDriver) {
			item.setSelected();
		}
	}

	audioDriverActive.setText({bms::get("Settings.Drivers.ActiveDriver").data(), ": ", activeDriverTranslated});
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
	auto   item     = audioDriverOption.selected();

	/* MT. */
	string itemText = item.text();
	bool   isNone   = itemText == bms::get("Common.None").data();
	/* /MT. */

	settings.audio.driver = isNone ? "None" : itemText;

	/* // Commented-out by MT.
	if (!emulator->loaded() || isNone || MessageDialog(
		bms::get("Settings.Drivers.changeConfirm").data()
	).setAlignment(*settingsWindow).question({bms::get("Common.Yes").data(), bms::get("Common.No").data()}) == bms::get("Common.Yes").data()) {
	*/

	if (!emulator->loaded() || isNone || bmw::confirmById("Settings.Drivers.changeConfirm", settingsWindow->handle())) { // MT.
		program.save();
		program.saveUndoState();
		//settings.general.crashed = true;
		//settings.save();
		program.updateAudioDriver(settingsWindow);
		//settings.general.crashed = false;
		settings.save();
		audioDriverChanged();
	}
}

auto DriverSettings::audioDeviceChanged() -> void {
	audioDeviceOption.reset();

	/* MT. */
	string defaultString          = "Default";
	string defaultTranslated      = bms::get("Common.Default").data();
	string activeDevice           = audio.device();
	string activeDeviceTranslated = activeDevice == defaultString ? defaultTranslated : activeDevice;
	/* /MT. */

	for (auto& device : audio.hasDevices()) {
		ComboButtonItem item{&audioDeviceOption};
		item.setText(device == defaultString ? defaultTranslated : device);

		if (device == activeDevice) {
			item.setSelected();
		}
	}

	//audioDeviceOption.setEnabled(audio->hasDevice());
	setGeometry(geometry());
}

auto DriverSettings::audioDeviceChange() -> void {
	auto item = audioDeviceOption.selected();

	/* MT. */
	string defaultString     = "Default";
	string defaultTranslated = bms::get("Common.Default").data();
	string itemText          = item.text();
	/* /MT. */

	settings.audio.device = itemText == defaultTranslated ? defaultString : itemText;
	program.updateAudioDevice();
	audioFrequencyChanged();
	audioLatencyChanged();
}

auto DriverSettings::audioFrequencyChanged() -> void {
	audioFrequencyOption.reset();

	for (auto& frequency : audio.hasFrequencies()) {
		ComboButtonItem item{&audioFrequencyOption};
		item.setText({frequency, ' ', bms::get("Common.Hz").data()});

		if (frequency == audio.frequency()) {
			item.setSelected();
		}
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

	for (auto& latency : audio.hasLatencies()) {
		ComboButtonItem item{&audioLatencyOption};
		item.setText(latency);

		if (latency == audio.latency()) {
			item.setSelected();
		}
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

	/* MT. */
	string none                   = "None";
	string noneTranslated         = bms::get("Common.None").data();
	string activeDriver           = input.driver();
	string activeDriverTranslated = activeDriver == none ? noneTranslated : activeDriver;
	/* /MT. */

	for (auto& driver : input.hasDrivers()) {
		ComboButtonItem item{&inputDriverOption};
		item.setText(driver == none ? noneTranslated : driver);

		if (driver == activeDriver) {
			item.setSelected();
		}
	}

	inputDriverActive.setText({bms::get("Settings.Drivers.ActiveDriver").data(), ": ", activeDriverTranslated});
	inputDriverOption.doChange();
	setGeometry(geometry());
}

auto DriverSettings::inputDriverChange() -> void {
	auto   item     = inputDriverOption.selected();

	/* MT. */
	string itemText = item.text();
	bool   isNone   = itemText == bms::get("Common.None").data();
	/* /MT. */

	settings.input.driver = isNone ? "None" : itemText;

	/* // Commented-out by MT.
	if (!emulator->loaded() || isNone || MessageDialog(
		bms::get("Settings.Drivers.changeConfirm").data()
	).setAlignment(*settingsWindow).question({bms::get("Common.Yes").data(), bms::get("Common.No").data()}) == bms::get("Common.Yes").data()) {
	*/

	if (!emulator->loaded() || isNone || bmw::confirmById("Settings.Drivers.changeConfirm", settingsWindow->handle())) { // MT.
		program.save();
		program.saveUndoState();
		//settings.general.crashed = true;
		//settings.save();
		program.updateInputDriver(settingsWindow);
		//settings.general.crashed = false;
		settings.save();
		inputDriverChanged();
	}
}