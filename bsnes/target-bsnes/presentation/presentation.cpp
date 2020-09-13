#include <cstdint> // MT.

#include "../bsnes.hpp"

/* MT. */
#include "bsnes-mt/app.h"
#include "bsnes-mt/messagebox.h"
#include "bsnes-mt/scaling.h"
#include "bsnes-mt/translations.h"
#include "bsnes-mt/utils.h"
#include "bsnes-mt/windows.h"

namespace bma = bsnesMt::app;
namespace bmt = bsnesMt::translations;
namespace bmw = bsnesMt::windows;
/* /MT. */

namespace Instances { Instance<Presentation> presentation; }
Presentation& presentation = Instances::presentation();

auto Presentation::create() -> void {
	auto ellipsis = "..."; // MT.

	fileMenu.setText(bmt::get("Menu.File").data()); // MT.

	loadGame.setIcon(Icon::Action::Open).setText({bmt::get("Menu.File.OpenGame").data(), ellipsis, "\tCtrl+O"}).onActivate([&] {
		program.load();
	});

	loadRecentGame.setIcon(Icon::Action::Open).setText(bmt::get("Menu.File.OpenRecentGame").data());
	updateRecentGames();

	unloadGame.setIcon(Icon::Action::Remove).setText({bmt::get("Menu.File.CloseGame").data(), "\tCtrl+W, Ctrl+F4"}).setEnabled(false).onActivate([&] {
		program.unload();
	});

	quit.setIcon(Icon::Action::Quit).setText({bmt::get("Menu.File.Exit").data(), "\tAlt+F4"}).onActivate([&] {
		program.quit();
	});

	systemMenu.setText(bmt::get("Menu.System").data());

	resetSystem.setIcon(Icon::Action::Refresh).setText({bmt::get("Common.Reset").data(), "\tF5"}).setEnabled(false).onActivate([&] {
		program.reset();
	});

	controllerPort1.setIcon(Icon::Device::Joypad).setText({bmt::get("Menu.System.ControllerPort").data(), " 1"});
	controllerPort2.setIcon(Icon::Device::Joypad).setText({bmt::get("Menu.System.ControllerPort").data(), " 2"});

	expansionPort.setIcon(Icon::Device::Storage).setText(bmt::get("Menu.System.ExpansionPort").data());
	updateDeviceMenu();

	settingsMenu.setText(bmt::get("Settings").data());

	sizeMenu.setIcon(Icon::Emblem::Image).setText(bmt::get("Menu.Settings.Size").data());

	updateSizeMenu();

	outputMenu.setIcon(Icon::Emblem::Image).setText(bmt::get("Menu.Settings.Output").data());

	centerViewport.setText(bmt::get("Menu.Settings.Output.Center").data()).onActivate([&] {
		settings.video.output = "Center";
		video.clear();
	});

	/* MT */
	perfectViewport.setText(bmt::get("Menu.Settings.Output.PixelPerfect").data()).onActivate([&] {
		settings.video.output = "Pixel-Perfect";
		video.clear();
	});
	/* /MT */

	scaleViewport.setText(bmt::get("Menu.Settings.Output.Scale").data()).onActivate([&] {
		settings.video.output = "Scale";
		video.clear();
	});

	stretchViewport.setText(bmt::get("Menu.Settings.Output.Stretch").data()).onActivate([&] {
		settings.video.output = "Stretch";
		video.clear();
	});

	auto output = settings.video.output; // MT.

	if (output == "Center") {
		centerViewport.setChecked();
	}
	/* MT. */
	else if (output == "Pixel-Perfect") {
		perfectViewport.setChecked();
	}
	/* /MT. */
	else if (output == "Scale") {
		scaleViewport.setChecked();
	}
	else if (output == "Stretch") {
		stretchViewport.setChecked();
	}

	aspectCorrection.setText(bmt::get("Menu.Settings.Output.AspectRatioCorrection").data())
		.setChecked(settings.video.aspectCorrection)
		.onToggle([&] {
			settings.video.aspectCorrection = aspectCorrection.checked();
			video.clear(); // MT.
			//resizeWindow(); // Commented-out by MT.
		});

	/* MT. */
	parInsteadOfAr.setText(bmt::get("Menu.Settings.Output.parInsteadOfAr").data())
		.setChecked(settings.video.parInsteadOfAr)
		.onToggle([&] {
			settings.video.parInsteadOfAr = parInsteadOfAr.checked();
			video.clear(); // MT.
		});
	/* /MT. */

	showOverscanArea.setText(bmt::get("Menu.Settings.Output.ShowOverscanArea").data())
		.setChecked(settings.video.overscan)
		.onToggle([&] {
			settings.video.overscan = showOverscanArea.checked();
			video.clear(); // MT.
			//resizeWindow(); // Commented-out by MT.
		});

	/* MT. */
	scalingInfo.setText(bmt::get("Menu.Settings.Output.scalingInfo").data())
		.setChecked(settings.video.scalingInfo)
		.onToggle([&] {
			settings.video.scalingInfo = scalingInfo.checked();
		});
	/* /MT. */

	blurEmulation.setText(bmt::get("Menu.Settings.Output.HiresBlurEmulation").data())
		.setChecked(settings.video.blur)
		.onToggle([&] {
			settings.video.blur = blurEmulation.checked();
			emulator->configure("Video/BlurEmulation", settings.video.blur);
		})
		.doToggle();

	filterMenu.setIcon(Icon::Emblem::Image).setText(bmt::get("Menu.Settings.Filter").data());

	filterNone.setText(bmt::get("Common.None").data()).onActivate([&] {
		settings.video.filter = "None";
	});

	filterScanlinesLight.setText("Scanlines (66%)").onActivate([&] {
		settings.video.filter = "Scanlines (66%)";
	});

	filterScanlinesDark.setText("Scanlines (33%)").onActivate([&] {
		settings.video.filter = "Scanlines (33%)";
	});

	filterScanlinesBlack.setText("Scanlines (0%)").onActivate([&] {
		settings.video.filter = "Scanlines (0%)";
	});

	filterPixellate2x.setText("Pixellate2x").onActivate([&] {
		settings.video.filter = "Pixellate2x";
	});

	filterScale2x.setText("Scale2x").onActivate([&] {
		settings.video.filter = "Scale2x";
	});

	filter2xSaI.setText("2xSaI").onActivate([&] {
		settings.video.filter = "2xSaI";
	});

	filterSuper2xSaI.setText("Super 2xSaI").onActivate([&] {
		settings.video.filter = "Super 2xSaI";
	});

	filterSuperEagle.setText("Super Eagle").onActivate([&] {
		settings.video.filter = "Super Eagle";
	});

	filterLQ2x.setText("LQ2x").onActivate([&] {
		settings.video.filter = "LQ2x";
	});

	filterHQ2x.setText("HQ2x").onActivate([&] {
		settings.video.filter = "HQ2x";
	});

	filterNTSC_RF.setText("NTSC (RF)").onActivate([&] {
		settings.video.filter = "NTSC (RF)";
	});

	filterNTSC_Composite.setText("NTSC (Composite)").onActivate([&] {
		settings.video.filter = "NTSC (Composite)";
	});

	filterNTSC_SVideo.setText("NTSC (S-Video)").onActivate([&] {
		settings.video.filter = "NTSC (S-Video)";
	});

	filterNTSC_RGB.setText("NTSC (RGB)").onActivate([&] {
		settings.video.filter = "NTSC (RGB)";
	});

	auto filter = settings.video.filter; // MT.

	if (filter == "None") {
		filterNone.setChecked();
	}
	else if (filter == "Scanlines (66%)") {
		filterScanlinesLight.setChecked();
	}
	else if (filter == "Scanlines (33%)") {
		filterScanlinesDark.setChecked();
	}
	else if (filter == "Scanlines (0%)") {
		filterScanlinesBlack.setChecked();
	}
	else if (filter == "Pixellate2x") {
		filterPixellate2x.setChecked();
	}
	else if (filter == "Scale2x") {
		filterScale2x.setChecked();
	}
	else if (filter == "2xSaI") {
		filter2xSaI.setChecked();
	}
	else if (filter == "Super 2xSaI") {
		filterSuper2xSaI.setChecked();
	}
	else if (filter == "Super Eagle") {
		filterSuperEagle.setChecked();
	}
	else if (filter == "LQ2x") {
		filterLQ2x.setChecked();
	}
	else if (filter == "HQ2x") {
		filterHQ2x.setChecked();
	}
	else if (filter == "NTSC (RF)") {
		filterNTSC_RF.setChecked();
	}
	else if (filter == "NTSC (Composite)") {
		filterNTSC_Composite.setChecked();
	}
	else if (filter == "NTSC (S-Video)") {
		filterNTSC_SVideo.setChecked();
	}
	else if (filter == "NTSC (RGB)") {
		filterNTSC_RGB.setChecked();
	}

	shaderMenu.setIcon(Icon::Emblem::Image).setText(bmt::get("Menu.Settings.Shader").data());

	muteAudio.setText(bmt::get("Menu.Settings.MuteAudio").data())
		.setChecked(settings.audio.mute)
		.onToggle([&] {
			settings.audio.mute = muteAudio.checked();
	
			if (settings.audio.mute) {
				program.mute |= Program::Mute::Always;
			}
			else {
				program.mute &= ~Program::Mute::Always;
			}
		})
		.doToggle();  //set initial mute state flag

	showStatusBar.setText(bmt::get("Menu.Settings.ShowStatusBar").data())
		.setChecked(settings.general.statusBar)
		.onToggle([&] {
			settings.general.statusBar = showStatusBar.checked();
	
			if (showStatusBar.checked()) {
				layout.append(statusLayout, Size{~0, StatusHeight});
			}
			else {
				layout.remove(statusLayout);
			}
	
			//if (visible()) resizeWindow(); // Commented-out by MT.
		});

	videoSettings.setIcon(Icon::Device::Display).setText({bmt::get("Common.Video").data(), ellipsis}).onActivate([&] {
		settingsWindow.show(0);
	});

	audioSettings.setIcon(Icon::Device::Speaker).setText({bmt::get("Common.Audio").data(), ellipsis}).onActivate([&] {
		settingsWindow.show(1);
	});

	inputSettings.setIcon(Icon::Device::Joypad).setText({bmt::get("Settings.Input").data(), ellipsis}).onActivate([&] {
		settingsWindow.show(2);
	});

	hotkeySettings.setIcon(Icon::Device::Keyboard).setText({bmt::get("Settings.Hotkeys").data(), ellipsis}).onActivate([&] {
		settingsWindow.show(3);
	});

	pathSettings.setIcon(Icon::Emblem::Folder).setText({bmt::get("Settings.Paths").data(), ellipsis}).onActivate([&] {
		settingsWindow.show(4);
	});

	emulatorSettings.setIcon(Icon::Action::Settings).setText({bmt::get("Settings.Emulator").data(), ellipsis}).onActivate([&] {
		settingsWindow.show(5);
	});

	enhancementSettings.setIcon(Icon::Action::Add).setText({bmt::get("Settings.Enhancements").data(), ellipsis}).onActivate([&] {
		settingsWindow.show(6);
	});

	compatibilitySettings.setIcon(Icon::Action::Remove).setText({bmt::get("Settings.Compatibility").data(), ellipsis}).onActivate([&] {
		settingsWindow.show(7);
	});

	driverSettings.setIcon(Icon::Place::Settings).setText({bmt::get("Settings.Drivers").data(), ellipsis}).onActivate([&] {
		settingsWindow.show(8);
	});

	/* MT. */
	settingsFolder.setIcon(Icon::Emblem::Folder).setText(bmt::get("Menu.Settings.OpenSettingsFolder").data()).onActivate([&] {
		string path = nall::Location::path(locate("bsnes-mt-settings.bml"));
		bsnesMt::open(path.get());
	});
	/* /MT. */

	char space = ' '; // MT.

	toolsMenu.setText(bmt::get("Tools").data()).setVisible(false);

	saveState.setIcon(Icon::Media::Record).setText(bmt::get("Tools.SaveState").data());

	for (uint index : range(QuickStates)) {
		MenuItem item{&saveState};

		item.setAttribute("name", {"Quick/Slot ", 1 + index});
		item.setAttribute("title", {bmt::get("Tools.SaveState.Slot").data(), space, 1 + index});
		item.setText({bmt::get("Tools.SaveState.Slot").data(), space, 1 + index});

		item.onActivate([=] {
			program.saveState({"Quick/Slot ", 1 + index});
		});
	}

	loadState.setIcon(Icon::Media::Rewind).setText(bmt::get("Tools.LoadState").data());

	for (uint index : range(QuickStates)) {
		MenuItem item{&loadState};

		item.setAttribute("name", {"Quick/Slot ", 1 + index});
		item.setAttribute("title", {bmt::get("Tools.SaveState.Slot").data(), space, 1 + index});
		item.setText({bmt::get("Tools.SaveState.Slot").data(), space, 1 + index});

		item.onActivate([=] {
			program.loadState({"Quick/Slot ", 1 + index});
		});
	}

	loadState.append(MenuSeparator());

	loadState.append(MenuItem()
		.setAttribute("name", "Quick/Undo")
		.setAttribute("title", bmt::get("Tools.LoadState.UndoLastSave").data())
		.setIcon(Icon::Edit::Undo).setText(bmt::get("Tools.LoadState.UndoLastSave").data()).onActivate([&] {
			program.loadState("Quick/Undo");
		}));

	loadState.append(MenuItem()
		.setAttribute("name", "Quick/Redo")
		.setAttribute("title", bmt::get("Tools.LoadState.RedoLastUndo").data())
		.setIcon(Icon::Edit::Redo).setText(bmt::get("Tools.LoadState.RedoLastUndo").data()).onActivate([&] {
			program.loadState("Quick/Redo");
		}));

	loadState.append(MenuItem().setIcon(Icon::Edit::Clear)
		.setText(bmt::get("Tools.LoadState.RemoveAllStates").data())
		.onActivate([&] {
			/* // Commented-out by MT.
			if (MessageDialog(bmt::get("Tools.LoadState.RemoveAllStates.confirm").data()).setAlignment(*this)
			.question({bmt::get("Common.Yes").data(), bmt::get("Common.No").data()}) == bmt::get("Common.Yes").data())
			{
			*/
	
			if (bmw::confirmById("Tools.LoadState.RemoveAllStates.confirm", handle())) {
				for (uint index : range(QuickStates)) {
					program.removeState({"Quick/Slot ", 1 + index});
				}

				program.removeState("Quick/Undo");
				program.removeState("Quick/Redo");
			}
		}));

	speedMenu.setIcon(Icon::Device::Clock).setText(bmt::get("Tools.Speed").data()).setEnabled(!settings.video.blocking && settings.audio.blocking);

	speedSlowest.setText({"50% (", bmt::get("Tools.Speed.Slowest").data(), ")"}).setAttribute("multiplier", "2.0").onActivate([&] {
		program.updateAudioFrequency();
	});

	speedSlow.setText({"75% (", bmt::get("Tools.Speed.Slow").data(), ")"}).setAttribute("multiplier", "1.333").onActivate([&] {
		program.updateAudioFrequency();
	});

	speedNormal.setText({"100% (", bmt::get("Tools.Speed.Normal").data(), ")"}).setAttribute("multiplier", "1.0").onActivate([&] {
		program.updateAudioFrequency();
	});

	speedFast.setText({"150% (", bmt::get("Tools.Speed.Fast").data(), ")"}).setAttribute("multiplier", "0.667").onActivate([&] {
		program.updateAudioFrequency();
	});

	speedFastest.setText({"200% (", bmt::get("Tools.Speed.Fastest").data(), ")"}).setAttribute("multiplier", "0.5").onActivate([&] {
		program.updateAudioFrequency();
	});

	runMenu.setIcon(Icon::Media::Play).setText(bmt::get("Tools.RunMode").data());

	runEmulation.setText(bmt::get("Tools.RunMode.Normal").data()).onActivate([&] {});

	pauseEmulation.setText({bmt::get("Tools.RunMode.PauseEmulation").data(), "\tPause/Break"}).onActivate([&] {
		audio.clear();
	});

	frameAdvance.setText(bmt::get("Tools.RunMode.FrameAdvance").data()).onActivate([&] {
		audio.clear();
		program.frameAdvanceLock = true;
	});

	movieMenu.setIcon(Icon::Emblem::Video).setText(bmt::get("Tools.Movie").data());

	moviePlay.setIcon(Icon::Media::Play).setText(bmt::get("Tools.Movie.Play").data()).onActivate([&] {
		program.moviePlay();
	});

	movieRecord.setIcon(Icon::Media::Record).setText(bmt::get("Tools.Movie.Record").data()).onActivate([&] {
		program.movieRecord(false);
	});

	movieRecordFromBeginning.setIcon(Icon::Media::Record).setText(bmt::get("Tools.Movie.ResetAndRecord").data()).onActivate([&] {
		program.movieRecord(true);
	});

	movieStop.setIcon(Icon::Media::Stop).setText(bmt::get("Tools.Movie.Stop").data()).onActivate([&] {
		program.movieStop();
	});

	captureScreenshot.setIcon(Icon::Emblem::Image).setText({bmt::get("Tools.TakeScreenshot").data(), "\tF9, PrintScreen"}).onActivate([&] {
		program.captureScreenshot();
	});

	cheatFinder.setIcon(Icon::Action::Search).setText({bmt::get("Tools.CheatFinder").data(), ellipsis}).onActivate([&] {
		toolsWindow.show(0);
	});

	cheatEditor.setIcon(Icon::Edit::Replace).setText({bmt::get("Tools.CheatEditor").data(), ellipsis}).onActivate([&] {
		toolsWindow.show(1);
	});

	stateManager.setIcon(Icon::Application::FileManager).setText({bmt::get("Tools.StateManager").data(), ellipsis}).onActivate([&] {
		toolsWindow.show(2);
	});

	manifestViewer.setIcon(Icon::Emblem::Text).setText({bmt::get("Tools.ManifestViewer").data(), ellipsis}).onActivate([&] {
		toolsWindow.show(3);
	});

	helpMenu.setText(bmt::get("Menu.Help").data());

	string aboutString = bmt::get("Menu.Help.About").data(); // MT.

	aboutSameBoy.setIcon(Icon::Prompt::Question)
		.setText({string(aboutString).replace('|', Emulator::SameBoyName), ellipsis})
		.onActivate([&] {
			AboutDialog()
				.setName(Emulator::SameBoyName)
				.setLogo(Resource::SameBoy)
				.setDescription(bmt::get("About.SameBoy.description").data())
				.setVersion("0.12.1")
				.setCopyright("Lior Halphon")
				.setLicense("MIT")
				.setWebsite("https://sameboy.github.io")
				.setAlignment(*this)
				.show();
		});

	aboutBsnes.setIcon(Icon::Prompt::Question)
		.setText({string(aboutString).replace('|', Emulator::Name), ellipsis})
		.onActivate([&] {
			AboutDialog()
				.setName(Emulator::Name)
				.setLogo(Resource::Logo)
				.setDescription(bmt::get("About.Bsnes.description").data())
				.setVersion(Emulator::Version)
				.setCopyright(bmt::get("About.Bsnes.copyright").data())
				.setLicense(bmt::get("About.Bsnes.license").data())
				.setWebsite(Emulator::Website)
				.setAlignment(*this)
				.show();
		});

	/* MT. */
	aboutBsnesMt.setIcon(Icon::Prompt::Question)
		.setText({string(aboutString).replace('|', bma::title.data()), ellipsis})
		.onActivate([&] {
			bmw::showAbout((HWND)presentation.handle());
		});
	/* /MT. */

	viewport.setFocusable(false);  //true would also capture Alt, which breaks keyboard menu navigation
	viewport.setDroppable();

	viewport.onDrop([&](auto locations) {
		onDrop(locations);
	});

	iconSpacer.setColor({0, 0, 0});
	iconSpacer.setDroppable();

	iconSpacer.onDrop([&](auto locations) {
		onDrop(locations);
	});

	iconLayout.setAlignment(0.0).setCollapsible();
	image icon{Resource::Icon};
	icon.alphaBlend(0x000000);
	iconCanvas.setIcon(icon);
	iconCanvas.setDroppable();

	iconCanvas.onDrop([&](auto locations) {
		onDrop(locations);
	});

	if (!settings.general.statusBar) {
		layout.remove(statusLayout);
	}

	auto font = Font().setBold();
	auto back = Color{ 32,  32,  32};
	auto fore = Color{255, 255, 255};

	updateProgramIcon();
	updateStatusIcon();

	spacerIcon.setBackgroundColor(back).setForegroundColor(fore);

	spacerLeft.setBackgroundColor(back).setForegroundColor(fore);

	statusLeft.setFont(font);
	statusLeft.setAlignment(0.0);
	statusLeft.setBackgroundColor(back);
	statusLeft.setForegroundColor(fore);

	statusRight.setFont(font);
	statusRight.setAlignment(1.0);
	statusRight.setBackgroundColor(back);
	statusRight.setForegroundColor(fore);

	spacerRight.setBackgroundColor(back).setForegroundColor(fore);

	program.updateStatus();

	onClose([&] {
		program.quit();
	});

	setTitle(bma::windowTitle.data());
	setBackgroundColor({0, 0, 0});
	resizeWindow();
	setAlignment(Alignment::Center);

	#if defined(PLATFORM_MACOS)
	Application::Cocoa::onAbout([&] {
		aboutBsnes.doActivate();
	});

	Application::Cocoa::onActivate([&] {
		setFocused();
	});

	Application::Cocoa::onPreferences([&] {
		settingsWindow.show(2);
	});

	Application::Cocoa::onQuit([&] {
		doClose();
	});
	#endif
}

auto Presentation::onDrop(vector<string> locations) -> void {
	if (!locations) {
		return;
	}

	program.gameQueue = {};
	program.gameQueue.append({"Auto;", locations.first()});
	program.load();
	setFocused();
}

auto Presentation::updateProgramIcon() -> void {
	presentation.iconLayout.setVisible(!emulator->loaded() && !settings.video.snow);
	presentation.layout.resize();

	//todo: video.clear() is not working on macOS/OpenGL 3.2
	if (auto [output, length] = video.acquire(1, 1); output) {
		*output = 0;
		video.release();
		video.output();
	}
}

auto Presentation::updateStatusIcon() -> void {
	image icon;
	icon.allocate(16, StatusHeight);
	icon.fill(0xff202020);

	if (emulator->loaded() && program.verified()) {
		image emblem{Icon::Emblem::Program};
		icon.impose(image::blend::sourceAlpha, 0, (StatusHeight - 16) / 2, emblem, 0, 0, 16, 16);
		statusIcon.setIcon(icon).setToolTip(bmt::get("StatusIcon.verifiedRom.tooltip").data());
	}
	else if (emulator->loaded()) {
		image emblem{Icon::Emblem::Binary};
		icon.impose(image::blend::sourceAlpha, 0, (StatusHeight - 16) / 2, emblem, 0, 0, 16, 16);
		statusIcon.setIcon(icon).setToolTip(bmt::get("StatusIcon.unverifiedRom.tooltip").data());
	}
	else {
		statusIcon.setIcon(icon).setToolTip();
	}
}

auto Presentation::resizeWindow() -> void {
	if (fullScreen()) {
		return;
	}

	if (maximized()) {
		setMaximized(false);
	}

	/*uint width = 256 * (settings.video.aspectCorrection ? 8.0 / 7.0 : 1.0);*/ // Commented-out by MT.
	uint width        = bsnesMt::scaling::getWidth(settings.video.aspectCorrection); // MT.
	uint height       = settings.video.overscan ? 240 : 224;
	uint multiplier   = max(1, settings.video.multiplier);
	uint statusHeight = settings.general.statusBar ? StatusHeight : 0;

	setMinimumSize({width, height + statusHeight});
	setSize({width * multiplier, height * multiplier + statusHeight});
}

auto Presentation::updateDeviceMenu() -> void {
	controllerPort1.reset();
	controllerPort2.reset();
	expansionPort.reset();

	auto information = emulator->information();

	for (auto& port : emulator->ports()) {
		Menu* menu = nullptr;
		auto  name = port.name; // MT.

		if (name == "Controller Port 1") {
			menu = &controllerPort1;
		}
		else if (name == "Controller Port 2") {
			menu = &controllerPort2;
		}
		else if (name == "Expansion Port") {
			menu = &expansionPort;
		}

		if (!menu) {
			continue;
		}

		auto path       = string{information.name, "/", port.name}.replace(" ", "");
		auto deviceName = settings(path).text();
		auto deviceID   = emulator->connected(port.id);

		Group devices;

		for (auto& device : emulator->devices(port.id)) {
			if (port.name == "Expansion Port" && device.name == "21fx") {
				continue;
			}

			MenuRadioItem item{menu};
			item.setAttribute("deviceID", device.id);
			item.setText(bmt::getDeviceString(device.name.data()).data());

			item.onActivate([=] {
				settings(path).setValue(device.name);
				emulator->connect(port.id, device.id);
				updateDeviceSelections();
			});

			devices.append(item);

			if (deviceName == device.name) {
				item.doActivate();
			}

			if (!deviceName && deviceID == device.id) {
				item.doActivate();
			}
		}
	}

	updateDeviceSelections();
}

auto Presentation::updateDeviceSelections() -> void {
	for (auto& port : emulator->ports()) {
		Menu* menu = nullptr;
		auto  name = port.name; // MT.

		if (name == "Controller Port 1") {
			menu = &controllerPort1;
		}
		else if (name == "Controller Port 2") {
			menu = &controllerPort2;
		}
		else if (name == "Expansion Port") {
			menu = &expansionPort;
		}

		if (!menu) {
			continue;
		}

		auto deviceID = emulator->connected(port.id);

		for (auto& action : menu->actions()) {
			if (auto item = action.cast<MenuRadioItem>()) {
				if (item.attribute("deviceID").natural() == deviceID) {
					item.setChecked();
					break;
				}
			}
		}
	}
}

//generate a list of size multipliers
auto Presentation::updateSizeMenu() -> void {
	assert(sizeMenu.actionCount() == 0);  //should only be called once

	//determine the largest multiplier that can be used by the largest monitor found
	uint height = 1;

	for (uint monitor : range(Monitor::count())) {
		height = max(height, Monitor::workspace(monitor).height());
	}

	uint multipliers = max(1, height / 240);

	for (uint multiplier : range(1, multipliers + 1)) {
		MenuRadioItem item{&sizeMenu};
		item.setAttribute("multiplier", multiplier);
		item.setText({multiplier, "x (", 240 * multiplier, "p)"});

		item.onActivate([=] {
			settings.video.multiplier = multiplier;
			resizeWindow();
		});

		sizeGroup.append(item);
	}

	for (auto item : sizeGroup.objects<MenuRadioItem>()) {
		if (settings.video.multiplier == item.attribute("multiplier").natural()) {
			item.setChecked();
		}
	}

	sizeMenu.append(MenuSeparator());

	sizeMenu.append(MenuItem().setIcon(Icon::Action::Remove).setText(bmt::get("Menu.Settings.Size.ShrinkWindowToSize").data()).onActivate([&] {
		resizeWindow();
	}));

	sizeMenu.append(MenuItem().setIcon(Icon::Place::Settings).setText(bmt::get("Menu.Settings.Size.CenterWindow").data()).onActivate([&] {
		setAlignment(Alignment::Center);
	}));

	/* MT. */
	sizeMenu.append(MenuItem().setIcon(Icon::Device::Display).setText({bmt::get("Menu.Settings.Size.FullScreenMode").data(), "\tF11, Alt+Enter"}).onActivate([&] {
		program.toggleVideoFullScreen();
	}));
	/* /MT. */

	/* MT. */
	sizeMenu.append(MenuItem().setIcon(Icon::Device::Display).setText({bmt::get("Menu.Settings.Size.PseudoFullScreenMode").data(), "\tShift+Enter"}).onActivate([&] {
		program.toggleVideoPseudoFullScreen();
	}));
	/* /MT. */
}

/* MT. */
auto Presentation::findState(vector<Program::State> &states, const string &name) -> maybe<uint64_t> {
	return states.find([&](auto& state) {
		return state.name == name;
	});
}
/* /MT. */

auto Presentation::updateStateMenus() -> void {
	auto states = program.availableStates("Quick/");

	string emptySlotString = bmt::get("Tools.SaveState.Slot.Empty").data(); // MT.

	for (auto& action : saveState.actions()) {
		if (auto item = action.cast<MenuItem>()) {
			if (auto name = item.attribute("name")) {
				string suffix; // MT.

				if (auto offset = findState(states, name)) {
					suffix = chrono::local::datetime(states[*offset].date);
				}
				else {
					suffix = emptySlotString;
				}

				item.setText({item.attribute("title"), " (", suffix, ")"}); // MT.
			}
		}
	}

	for (auto& action : loadState.actions()) {
		if (auto item = action.cast<MenuItem>()) {
			if (auto name = item.attribute("name")) {
				/* MT. */
				string suffix; // MT.
				bool enabled;
				/* /MT. */

				if (auto offset = findState(states, name)) {
					enabled = true;
					suffix  = chrono::local::datetime(states[*offset].date);
				}
				else {
					enabled = false;
					suffix  = emptySlotString;
				}

				/* MT. */
				item.setText({item.attribute("title"), " (", suffix, ")"});
				item.setEnabled(enabled);
				/* /MT. */
			}
		}
	}
}

auto Presentation::updateRecentGames() -> void {
	loadRecentGame.reset();

	static string gameRecentPrefix = "Game/Recent/"; // MT.

	//remove missing games from list
	for (uint index = 0; index < RecentGames;) {
		auto games   = settings[{gameRecentPrefix, 1 + index}].text();
		bool missing = false;

		if (games) {
			for (auto& game : games.split("|")) {
				if (!inode::exists(game.split(";").last())) {
					missing = true;
				}
			}
		}

		if (missing) {
			//will read one past the end of Games/Recent[RecentGames] by design:
			//this will always return an empty string to clear the last item in the list
			for (uint offset = index; offset < RecentGames; offset++) {
				settings[{gameRecentPrefix, 1 + offset}].setValue(
					settings[{gameRecentPrefix, 2 + offset}].text()
				);
			}
		}
		else {
			index++;
		}
	}

	//update list
	uint8_t recentGamesCount = 0; // MT.

	for (auto index : range(RecentGames)) {
		if (auto game = settings[{gameRecentPrefix, 1 + index}].text()) {
			MenuItem item{&loadRecentGame}; // Moved inside `if` block by MT.
			string displayName;
			auto games = game.split("|");

			for (auto& game : games) {
				displayName.append(Location::prefix(game.split(";", 1L).last()), " + ");
			}

			displayName.trimRight(" + ", 1L);
			item.setIcon(games(0).endsWith("/") ? (image)Icon::Action::Open : (image)Icon::Emblem::File);
			item.setText(displayName);

			item.onActivate([=] {
				program.gameQueue = games;
				program.load();
			});

			recentGamesCount++; // MT.
		}
		/* // Commented-out by MT.
		else {
			item.setText({"(", tr("empty"), ")"});
			item.setEnabled(false);
		}
		*/
	}

	if (recentGamesCount) { // MT.
		loadRecentGame.append(MenuSeparator());

		loadRecentGame.append(MenuItem().setIcon(Icon::Edit::Clear)
			.setText(bmt::get("Menu.File.OpenRecentGame.ClearList").data())
			.onActivate([&] {
				if (bmw::confirmById("Menu.File.OpenRecentGame.ClearList.confirm", handle())) {
					for (auto index : range(RecentGames)) {
						settings({gameRecentPrefix, 1 + index}).setValue("");
					}
		
					updateRecentGames();
				}
			}));
	} // MT.
	/* MT. */
	else {
		loadRecentGame.append(MenuItem().setIcon(Icon::Emblem::File).setEnabled(false)
			.setText({"(", bmt::get("Menu.File.OpenRecentGame.NoRecentGames").data(), ")"}));
	}
	/* /MT. */
}

auto Presentation::addRecentGame(string location) -> void {
	static string gameRecentPrefix = "Game/Recent/"; // MT.

	for (uint index : range(RecentGames + 1)) {
		auto value = settings[{gameRecentPrefix, 1 + index}].text();

		if (!value || value == location) {
			for (uint n : reverse(range(index + 1))) {
				if (1 + n > RecentGames) {
					continue;
				}

				settings({gameRecentPrefix, 1 + n}).setValue(settings[{gameRecentPrefix, n}].text());
			}

			break;
		}
	}

	settings({gameRecentPrefix, "1"}).setValue(location);
	updateRecentGames();
}

auto Presentation::updateShaders() -> void {
	shaderMenu.reset();
	shaderMenu.setEnabled(video.hasShader());

	if (!video.hasShader()) {
		return;
	}

	Group shaders;
	MenuRadioItem none{&shaderMenu};

	none.setText(bmt::get("Common.None").data()).onActivate([&] {
		settings.video.shader = "None";
		program.updateVideoShader();
	});

	shaders.append(none);

	MenuRadioItem blur{&shaderMenu};

	blur.setText(bmt::get("Menu.Settings.Shader.Blur").data()).onActivate([&] {
		settings.video.shader = "Blur";
		program.updateVideoShader();
	});

	shaders.append(blur);

	auto location = locate("Shaders/");

	if (settings.video.driver == "OpenGL 3.2") {
		for (auto shader : directory::folders(location, "*.shader")) {
			if (shaders.objectCount() == 2) {
				shaderMenu.append(MenuSeparator());
			}

			MenuRadioItem item{&shaderMenu};

			item.setText(string{shader}.trimRight(".shader/", 1L)).onActivate([=] {
				settings.video.shader = {location, shader};
				program.updateVideoShader();
			});

			shaders.append(item);
		}
	}

	auto shader = settings.video.shader;

	if (shader == "None") {
		none.setChecked();
	}
	else if (shader == "Blur") {
		blur.setChecked();
	}
	else {
		for (auto item : shaders.objects<MenuRadioItem>()) {
			if (shader == string{location, item.text(), ".shader/"}) {
				item.setChecked();
			}
		}
	}
}