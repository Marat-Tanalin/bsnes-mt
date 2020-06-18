#include <cstdint> // MT.

#include "../bsnes.hpp"

#include "bsnes-mt/app.h"     // MT.
#include "bsnes-mt/scaling.h" // MT.
#include "bsnes-mt/strings.h" // MT.
#include "bsnes-mt/utils.h"   // MT.
#include "bsnes-mt/windows.h" // MT.

namespace bms = bsnesMt::strings; // MT.

namespace Instances { Instance<Presentation> presentation; }
Presentation& presentation = Instances::presentation();

auto Presentation::create() -> void {
  auto ellipsis = "..."; // MT.

  fileMenu.setText(bms::get("Menu.File").data()); // MT.
  loadGame.setIcon(Icon::Action::Open).setText({bms::get("Menu.File.LoadGame").data(), ellipsis}).onActivate([&] { // tr("Load Game")
    program.load();
  });
  loadRecentGame.setIcon(Icon::Action::Open).setText(bms::get("Menu.File.LoadRecentGame").data()); // tr("Load Recent Game")
  updateRecentGames();
  unloadGame.setIcon(Icon::Action::Remove).setText(bms::get("Menu.File.UnloadGame").data()).setEnabled(false).onActivate([&] { // tr("Unload Game")
    program.unload();
  });
  quit.setIcon(Icon::Action::Quit).setText(bms::get("Menu.File.Quit").data()).onActivate([&] { program.quit(); }); // tr("Quit")

  systemMenu.setText(bms::get("Menu.System").data()); // tr("System")
  resetSystem.setIcon(Icon::Action::Refresh).setText(bms::get("Common.Reset").data()).setEnabled(false).onActivate([&] { // tr("Reset System")
    program.reset();
  });
  controllerPort1.setIcon(Icon::Device::Joypad).setText({bms::get("Menu.System.ControllerPort").data(), " 1"}); // tr("Controller Port 1")
  controllerPort2.setIcon(Icon::Device::Joypad).setText({bms::get("Menu.System.ControllerPort").data(), " 2"}); // tr("Controller Port 2")
  expansionPort.setIcon(Icon::Device::Storage).setText(bms::get("Menu.System.ExpansionPort").data()); // tr("Expansion Port")
  updateDeviceMenu();

  settingsMenu.setText(bms::get("Settings").data()); // tr("Settings")
  sizeMenu.setIcon(Icon::Emblem::Image).setText(bms::get("Menu.Settings.Size").data()); // "Size"
  updateSizeMenu();
  outputMenu.setIcon(Icon::Emblem::Image).setText(bms::get("Menu.Settings.Output").data()); // "Output"
  centerViewport.setText(bms::get("Menu.Settings.Output.Center").data()).onActivate([&] { // "Center"
    settings.video.output = "Center";
    video.clear();
  });

	/* MT */
	perfectViewport.setText(bms::get("Menu.Settings.Output.PixelPerfect").data()).onActivate([&] {//"Pixel-Perfect"
		settings.video.output = "Pixel-Perfect";
		video.clear();
	});
	/* /MT */

  scaleViewport.setText(bms::get("Menu.Settings.Output.Scale").data()).onActivate([&] { // "Scale"
    settings.video.output = "Scale";
    video.clear();
  });
  stretchViewport.setText(bms::get("Menu.Settings.Output.Stretch").data()).onActivate([&] { // "Stretch"
    settings.video.output = "Stretch";
    video.clear();
  });
  if(settings.video.output == "Center") centerViewport.setChecked();
  if(settings.video.output == "Pixel-Perfect") perfectViewport.setChecked(); // MT.
  if(settings.video.output == "Scale") scaleViewport.setChecked();
  if(settings.video.output == "Stretch") stretchViewport.setChecked();

  // "Aspect-Ratio Correction"
	aspectCorrection.setText(bms::get("Menu.Settings.Output.AspectRatioCorrection").data()).setChecked(settings.video.aspectCorrection).onToggle([&] {
		settings.video.aspectCorrection = aspectCorrection.checked();
		video.clear(); // MT.
		//resizeWindow(); // Commented-out by MT.
	});

  // "Show Overscan Area"
	showOverscanArea.setText(bms::get("Menu.Settings.Output.ShowOverscanArea").data()).setChecked(settings.video.overscan).onToggle([&] {
		settings.video.overscan = showOverscanArea.checked();
		video.clear(); // MT.
		//resizeWindow(); // Commented-out by MT.
	});

  // "Hires Blur Emulation"
  blurEmulation.setText(bms::get("Menu.Settings.Output.HiresBlurEmulation").data()).setChecked(settings.video.blur).onToggle([&] {
    settings.video.blur = blurEmulation.checked();
    emulator->configure("Video/BlurEmulation", settings.video.blur);
  }).doToggle();
  filterMenu.setIcon(Icon::Emblem::Image).setText(bms::get("Menu.Settings.Filter").data()); // "Filter"
  filterNone.setText(bms::get("Common.None").data()).onActivate([&] { settings.video.filter = "None"; }); // "None"
  filterScanlinesLight.setText("Scanlines (66%)").onActivate([&] { settings.video.filter = "Scanlines (66%)"; });
  filterScanlinesDark.setText("Scanlines (33%)").onActivate([&] { settings.video.filter = "Scanlines (33%)"; });
  filterScanlinesBlack.setText("Scanlines (0%)").onActivate([&] { settings.video.filter = "Scanlines (0%)"; });
  filterPixellate2x.setText("Pixellate2x").onActivate([&] { settings.video.filter = "Pixellate2x"; });
  filterScale2x.setText("Scale2x").onActivate([&] { settings.video.filter = "Scale2x"; });
  filter2xSaI.setText("2xSaI").onActivate([&] { settings.video.filter = "2xSaI"; });
  filterSuper2xSaI.setText("Super 2xSaI").onActivate([&] { settings.video.filter = "Super 2xSaI"; });
  filterSuperEagle.setText("Super Eagle").onActivate([&] { settings.video.filter = "Super Eagle"; });
  filterLQ2x.setText("LQ2x").onActivate([&] { settings.video.filter = "LQ2x"; });
  filterHQ2x.setText("HQ2x").onActivate([&] { settings.video.filter = "HQ2x"; });
  filterNTSC_RF.setText("NTSC (RF)").onActivate([&] { settings.video.filter = "NTSC (RF)"; });
  filterNTSC_Composite.setText("NTSC (Composite)").onActivate([&] { settings.video.filter = "NTSC (Composite)"; });
  filterNTSC_SVideo.setText("NTSC (S-Video)").onActivate([&] { settings.video.filter = "NTSC (S-Video)"; });
  filterNTSC_RGB.setText("NTSC (RGB)").onActivate([&] { settings.video.filter = "NTSC (RGB)"; });
  if(settings.video.filter == "None") filterNone.setChecked();
  if(settings.video.filter == "Scanlines (66%)") filterScanlinesLight.setChecked();
  if(settings.video.filter == "Scanlines (33%)") filterScanlinesDark.setChecked();
  if(settings.video.filter == "Scanlines (0%)") filterScanlinesBlack.setChecked();
  if(settings.video.filter == "Pixellate2x") filterPixellate2x.setChecked();
  if(settings.video.filter == "Scale2x") filterScale2x.setChecked();
  if(settings.video.filter == "2xSaI") filter2xSaI.setChecked();
  if(settings.video.filter == "Super 2xSaI") filterSuper2xSaI.setChecked();
  if(settings.video.filter == "Super Eagle") filterSuperEagle.setChecked();
  if(settings.video.filter == "LQ2x") filterLQ2x.setChecked();
  if(settings.video.filter == "HQ2x") filterHQ2x.setChecked();
  if(settings.video.filter == "NTSC (RF)") filterNTSC_RF.setChecked();
  if(settings.video.filter == "NTSC (Composite)") filterNTSC_Composite.setChecked();
  if(settings.video.filter == "NTSC (S-Video)") filterNTSC_SVideo.setChecked();
  if(settings.video.filter == "NTSC (RGB)") filterNTSC_RGB.setChecked();
  shaderMenu.setIcon(Icon::Emblem::Image).setText(bms::get("Menu.Settings.Shader").data()); // "Shader"
  muteAudio.setText(bms::get("Menu.Settings.MuteAudio").data()).setChecked(settings.audio.mute).onToggle([&] { // "Mute Audio"
    settings.audio.mute = muteAudio.checked();
    if(settings.audio.mute) {
      program.mute |= Program::Mute::Always;
    } else {
      program.mute &= ~Program::Mute::Always;
    }
  }).doToggle();  //set initial mute state flag

  // "Show Status Bar"
  showStatusBar.setText(bms::get("Menu.Settings.ShowStatusBar").data()).setChecked(settings.general.statusBar).onToggle([&] {
    settings.general.statusBar = showStatusBar.checked();
    if(!showStatusBar.checked()) {
      layout.remove(statusLayout);
    } else {
      layout.append(statusLayout, Size{~0, StatusHeight});
    }
    //if(visible()) resizeWindow(); // Commented-out by MT.
  });

  videoSettings.setIcon(Icon::Device::Display).setText({bms::get("Settings.Video").data(), ellipsis}).onActivate([&] { settingsWindow.show(0); }); // "Video..."
  audioSettings.setIcon(Icon::Device::Speaker).setText({bms::get("Settings.Audio").data(), ellipsis}).onActivate([&] { settingsWindow.show(1); }); // "Audio..."
  inputSettings.setIcon(Icon::Device::Joypad).setText({bms::get("Settings.Input").data(), ellipsis}).onActivate([&] { settingsWindow.show(2); }); // "Input..."
  hotkeySettings.setIcon(Icon::Device::Keyboard).setText({bms::get("Settings.Hotkeys").data(), ellipsis}).onActivate([&] { settingsWindow.show(3); }); // "Hotkeys..."
  pathSettings.setIcon(Icon::Emblem::Folder).setText({bms::get("Settings.Paths").data(), ellipsis}).onActivate([&] { settingsWindow.show(4); }); // "Paths..."
  emulatorSettings.setIcon(Icon::Action::Settings).setText({bms::get("Settings.Emulator").data(), ellipsis}).onActivate([&] { settingsWindow.show(5); }); // "Emulator..."
  enhancementSettings.setIcon(Icon::Action::Add).setText({bms::get("Settings.Enhancements").data(), ellipsis}).onActivate([&] { settingsWindow.show(6); }); // "Enhancements..."
  compatibilitySettings.setIcon(Icon::Action::Remove).setText({bms::get("Settings.Compatibility").data(), ellipsis}).onActivate([&] { settingsWindow.show(7); }); // "Compatibility..."
  driverSettings.setIcon(Icon::Place::Settings).setText({bms::get("Settings.Drivers").data(), ellipsis}).onActivate([&] { settingsWindow.show(8); }); // "Drivers..."
  
	/* MT. */
	settingsFolder.setIcon(Icon::Emblem::Folder).setText(bms::get("Menu.Settings.OpenSettingsFolder").data()).onActivate([&] { // "Open Settings Folder"
		string path = nall::Location::path(locate("bsnes-mt-settings.bml"));
		bsnesMt::open(path.get());
	});
	/* /MT. */

  toolsMenu.setText(bms::get("Tools").data()).setVisible(false); // tr("Tools")
  saveState.setIcon(Icon::Media::Record).setText(bms::get("Tools.SaveState").data()); // "Save State"
  for(uint index : range(QuickStates)) {
    MenuItem item{&saveState};
    item.setAttribute("name", {"Quick/Slot ", 1 + index});
    item.setAttribute("title", {bms::get("Tools.SaveState.Slot").data(), " ", 1 + index}); // "Slot "
    item.setText({bms::get("Tools.SaveState.Slot").data(), " ", 1 + index}); // "Slot "
    item.onActivate([=] { program.saveState({"Quick/Slot ", 1 + index}); });
  }
  loadState.setIcon(Icon::Media::Rewind).setText(bms::get("Tools.LoadState").data()); // "Load State"
  for(uint index : range(QuickStates)) {
    MenuItem item{&loadState};
    item.setAttribute("name", {"Quick/Slot ", 1 + index});
    item.setAttribute("title", {bms::get("Tools.SaveState.Slot").data(), " ", 1 + index}); // "Slot "
    item.setText({bms::get("Tools.SaveState.Slot").data(), " ", 1 + index}); // "Slot "
    item.onActivate([=] { program.loadState({"Quick/Slot ", 1 + index}); });
  }
  loadState.append(MenuSeparator());
  loadState.append(MenuItem()
  .setAttribute("name", "Quick/Undo")
  .setAttribute("title", bms::get("Tools.LoadState.UndoLastSave").data()) // "Undo Last Save"
  .setIcon(Icon::Edit::Undo).setText(bms::get("Tools.LoadState.UndoLastSave").data()).onActivate([&] {// "Undo Last Save"
    program.loadState("Quick/Undo");
  }));
  loadState.append(MenuItem()
  .setAttribute("name", "Quick/Redo")
  .setAttribute("title", bms::get("Tools.LoadState.RedoLastUndo").data()) // "Redo Last Undo"
  .setIcon(Icon::Edit::Redo).setText(bms::get("Tools.LoadState.RedoLastUndo").data()).onActivate([&] { // "Redo Last Undo"
    program.loadState("Quick/Redo");
  }));

  // "Remove All States"
  loadState.append(MenuItem().setIcon(Icon::Edit::Clear).setText(bms::get("Tools.LoadState.RemoveAllStates").data()).onActivate([&] {
    // Line break was added into message by MT because it’s cropped otherwise.
    if(MessageDialog("Are you sure you want to permanently\nremove all quick states for this game?").setAlignment(*this).question() == "Yes") {
      for(uint index : range(QuickStates)) program.removeState({"Quick/Slot ", 1 + index});
      program.removeState("Quick/Undo");
      program.removeState("Quick/Redo");
    }
  }));
  speedMenu.setIcon(Icon::Device::Clock).setText(bms::get("Tools.Speed").data()).setEnabled(!settings.video.blocking && settings.audio.blocking); // "Speed"
  speedSlowest.setText("50% (Slowest)").setAttribute("multiplier", "2.0").onActivate([&] { program.updateAudioFrequency(); });
  speedSlow.setText("75% (Slow)").setAttribute("multiplier", "1.333").onActivate([&] { program.updateAudioFrequency(); });
  speedNormal.setText("100% (Normal)").setAttribute("multiplier", "1.0").onActivate([&] { program.updateAudioFrequency(); });
  speedFast.setText("150% (Fast)").setAttribute("multiplier", "0.667").onActivate([&] { program.updateAudioFrequency(); });
  speedFastest.setText("200% (Fastest)").setAttribute("multiplier", "0.5").onActivate([&] { program.updateAudioFrequency(); });

  runMenu.setIcon(Icon::Media::Play).setText(bms::get("Tools.RunMode").data()); // "Run Mode"
  runEmulation.setText(bms::get("Tools.RunMode.Normal").data()).onActivate([&] { // "Normal"
  });
  pauseEmulation.setText(bms::get("Tools.RunMode.PauseEmulation").data()).onActivate([&] { // "Pause Emulation"
    audio.clear();
  });
  frameAdvance.setText(bms::get("Tools.RunMode.FrameAdvance").data()).onActivate([&] { // "Frame Advance"
    audio.clear();
    program.frameAdvanceLock = true;
  });
  movieMenu.setIcon(Icon::Emblem::Video).setText(bms::get("Tools.Movie").data()); // "Movie"
  moviePlay.setIcon(Icon::Media::Play).setText(bms::get("Tools.Movie.Play").data()).onActivate([&] { program.moviePlay(); }); // "Play"
  movieRecord.setIcon(Icon::Media::Record).setText(bms::get("Tools.Movie.Record").data()).onActivate([&] { program.movieRecord(false); }); // "Record"
  movieRecordFromBeginning.setIcon(Icon::Media::Record).setText(bms::get("Tools.Movie.ResetAndRecord").data()).onActivate([&] { program.movieRecord(true); }); // "Reset and Record"
  movieStop.setIcon(Icon::Media::Stop).setText(bms::get("Tools.Movie.Stop").data()).onActivate([&] { program.movieStop(); }); // "Stop"
  captureScreenshot.setIcon(Icon::Emblem::Image).setText(bms::get("Tools.CaptureScreenshot").data()).onActivate([&] { // "Capture Screenshot"
    program.captureScreenshot();
  });
  cheatFinder.setIcon(Icon::Action::Search).setText({bms::get("Tools.CheatFinder").data(), ellipsis}).onActivate([&] { toolsWindow.show(0); }); // "Cheat Finder..."
  cheatEditor.setIcon(Icon::Edit::Replace).setText({bms::get("Tools.CheatEditor").data(), ellipsis}).onActivate([&] { toolsWindow.show(1); }); // "Cheat Editor..."
  stateManager.setIcon(Icon::Application::FileManager).setText({bms::get("Tools.StateManager").data(), ellipsis}).onActivate([&] { toolsWindow.show(2); }); // "State Manager..."
  manifestViewer.setIcon(Icon::Emblem::Text).setText({bms::get("Tools.ManifestViewer").data(), ellipsis}).onActivate([&] { toolsWindow.show(3); }); // "Manifest Viewer..."

  helpMenu.setText(bms::get("Menu.Help").data()); // tr("Help")

  std::string aboutPrefix = bms::get("Help.About");

  aboutSameBoy.setIcon(Icon::Prompt::Question).setText({aboutPrefix.data(), " SameBoy", ellipsis}).onActivate([&] { // tr("About SameBoy")
    AboutDialog()
    .setName("SameBoy")
    .setLogo(Resource::SameBoy)
    .setDescription("Super Game Boy emulator")
    .setVersion("0.12.1")
    .setCopyright("Lior Halphon")
    .setLicense("MIT")
    .setWebsite("https://sameboy.github.io")
    .setAlignment(*this)
    .show();
  });
  aboutBsnes.setIcon(Icon::Prompt::Question).setText({aboutPrefix.data(), " bsnes", ellipsis}).onActivate([&] { // tr("About bsnes")
    AboutDialog()
    .setName(Emulator::Name)
    .setLogo(Resource::Logo)
    .setDescription("Super Nintendo emulator")
    .setVersion(Emulator::Version)
    .setCopyright(Emulator::Copyright)
    .setLicense(Emulator::License)
    .setWebsite(Emulator::Website)
    .setAlignment(*this)
    .show();
  });

	/* MT. */
	aboutBsnesMt.setIcon(Icon::Prompt::Question).setText({aboutPrefix.data(), " ", bsnesMt::app::title.data(), ellipsis}).onActivate([&] { // tr("About ")
		bsnesMt::windows::showAbout((HWND)presentation.handle());
	});
	/* /MT. */

  viewport.setFocusable(false);  //true would also capture Alt, which breaks keyboard menu navigation
  viewport.setDroppable();
  viewport.onDrop([&](auto locations) { onDrop(locations); });

  iconSpacer.setColor({0, 0, 0});
  iconSpacer.setDroppable();
  iconSpacer.onDrop([&](auto locations) { onDrop(locations); });

  iconLayout.setAlignment(0.0).setCollapsible();
  image icon{Resource::Icon};
  icon.alphaBlend(0x000000);
  iconCanvas.setIcon(icon);
  iconCanvas.setDroppable();
  iconCanvas.onDrop([&](auto locations) { onDrop(locations); });

  if(!settings.general.statusBar) layout.remove(statusLayout);

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

  setTitle(bsnesMt::app::windowTitle.data()); // {"bsnes v", Emulator::Version} // MT.
  setBackgroundColor({0, 0, 0});
  resizeWindow();
  setAlignment(Alignment::Center);

  #if defined(PLATFORM_MACOS)
  Application::Cocoa::onAbout([&] { aboutBsnes.doActivate(); });
  Application::Cocoa::onActivate([&] { setFocused(); });
  Application::Cocoa::onPreferences([&] { settingsWindow.show(2); });
  Application::Cocoa::onQuit([&] { doClose(); });
  #endif
}

auto Presentation::onDrop(vector<string> locations) -> void {
  if(!locations) return;
  program.gameQueue = {};
  program.gameQueue.append({"Auto;", locations.first()});
  program.load();
  setFocused();
}

auto Presentation::updateProgramIcon() -> void {
  presentation.iconLayout.setVisible(!emulator->loaded() && !settings.video.snow);
  presentation.layout.resize();
  //todo: video.clear() is not working on macOS/OpenGL 3.2
  if(auto [output, length] = video.acquire(1, 1); output) {
    *output = 0;
    video.release();
    video.output();
  }
}

auto Presentation::updateStatusIcon() -> void {
  image icon;
  icon.allocate(16, StatusHeight);
  icon.fill(0xff202020);

  if(emulator->loaded() && program.verified()) {
    image emblem{Icon::Emblem::Program};
    icon.impose(image::blend::sourceAlpha, 0, (StatusHeight - 16) / 2, emblem, 0, 0, 16, 16);
    statusIcon.setIcon(icon).setToolTip(
      "This is a known clean game image.\n"
      "PCB emulation is 100% accurate."
    );
  } else if(emulator->loaded()) {
    image emblem{Icon::Emblem::Binary};
    icon.impose(image::blend::sourceAlpha, 0, (StatusHeight - 16) / 2, emblem, 0, 0, 16, 16);
    statusIcon.setIcon(icon).setToolTip(
      "This is not a verified game image.\n"
      "PCB emulation is relying on heuristics."
    );
  } else {
    statusIcon.setIcon(icon).setToolTip();
  }
}

auto Presentation::resizeWindow() -> void {
  if(fullScreen()) return;
  if(maximized()) setMaximized(false);

  /*uint width = 256 * (settings.video.aspectCorrection ? 8.0 / 7.0 : 1.0);*/ // Commented-out by MT.
  uint width  = bsnesMt::scaling::getWidth(settings.video.aspectCorrection); // MT.
  uint height = (settings.video.overscan ? 240.0 : 224.0);
  uint multiplier = max(1, settings.video.multiplier);
  uint statusHeight = settings.general.statusBar ? StatusHeight : 0;

  setMinimumSize({width, height + statusHeight});
  setSize({width * multiplier, height * multiplier + statusHeight});
}

auto Presentation::updateDeviceMenu() -> void {
  controllerPort1.reset();
  controllerPort2.reset();
  expansionPort.reset();

  auto information = emulator->information();
  for(auto& port : emulator->ports()) {
    Menu* menu = nullptr;
    if(port.name == "Controller Port 1") menu = &controllerPort1;
    if(port.name == "Controller Port 2") menu = &controllerPort2;
    if(port.name == "Expansion Port") menu = &expansionPort;
    if(!menu) continue;

    auto path = string{information.name, "/", port.name}.replace(" ", "");
    auto deviceName = settings(path).text();
    auto deviceID = emulator->connected(port.id);

    Group devices;
    for(auto& device : emulator->devices(port.id)) {
      if(port.name == "Expansion Port" && device.name == "21fx") continue;

      MenuRadioItem item{menu};
      item.setAttribute("deviceID", device.id);
      item.setText(bms::getDeviceString(device.name.data()).data()); // tr(device.name)
      item.onActivate([=] {
        settings(path).setValue(device.name);
        emulator->connect(port.id, device.id);
        updateDeviceSelections();
      });
      devices.append(item);

      if(deviceName == device.name) item.doActivate();
      if(!deviceName && deviceID == device.id) item.doActivate();
    }
  }

  updateDeviceSelections();
}

auto Presentation::updateDeviceSelections() -> void {
  for(auto& port : emulator->ports()) {
    Menu* menu = nullptr;
    if(port.name == "Controller Port 1") menu = &controllerPort1;
    if(port.name == "Controller Port 2") menu = &controllerPort2;
    if(port.name == "Expansion Port") menu = &expansionPort;
    if(!menu) continue;

    auto deviceID = emulator->connected(port.id);
    for(auto& action : menu->actions()) {
      if(auto item = action.cast<MenuRadioItem>()) {
        if(item.attribute("deviceID").natural() == deviceID) {
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
  for(uint monitor : range(Monitor::count())) {
    height = max(height, Monitor::workspace(monitor).height());
  }

  uint multipliers = max(1, height / 240);
  for(uint multiplier : range(1, multipliers + 1)) {
    MenuRadioItem item{&sizeMenu};
    item.setAttribute("multiplier", multiplier);
    item.setText({multiplier, "x (", 240 * multiplier, "p)"});
    item.onActivate([=] {
      settings.video.multiplier = multiplier;
      resizeWindow();
    });
    sizeGroup.append(item);
  }
  for(auto item : sizeGroup.objects<MenuRadioItem>()) {
    if(settings.video.multiplier == item.attribute("multiplier").natural()) {
      item.setChecked();
    }
  }

  sizeMenu.append(MenuSeparator());
  sizeMenu.append(MenuItem().setIcon(Icon::Action::Remove).setText(bms::get("Menu.Settings.Size.ShrinkWindowToSize").data()).onActivate([&] { // "Shrink Window To Size"
    resizeWindow();
  }));
  sizeMenu.append(MenuItem().setIcon(Icon::Place::Settings).setText(bms::get("Menu.Settings.Size.CenterWindow").data()).onActivate([&] { // "Center Window"
    setAlignment(Alignment::Center);
  }));
}

auto Presentation::updateStateMenus() -> void {
  auto states = program.availableStates("Quick/");

  for(auto& action : saveState.actions()) {
    if(auto item = action.cast<MenuItem>()) {
      if(auto name = item.attribute("name")) {
        if(auto offset = states.find([&](auto& state) { return state.name == name; })) {
          item.setText({item.attribute("title"), " (", chrono::local::datetime(states[*offset].date), ")"});
        } else {
          item.setText({item.attribute("title"), " (", bms::get("Tools.SaveState.Empty").data(), ")"}); // empty
        }
      }
    }
  }

  for(auto& action : loadState.actions()) {
    if(auto item = action.cast<MenuItem>()) {
      if(auto name = item.attribute("name")) {
        if(auto offset = states.find([&](auto& state) { return state.name == name; })) {
          item.setEnabled(true);
          item.setText({item.attribute("title"), " (", chrono::local::datetime(states[*offset].date), ")"});
        } else {
          item.setEnabled(false);
          item.setText({item.attribute("title"), " (", bms::get("Tools.SaveState.Empty").data(), ")"}); // empty
        }
      }
    }
  }
}

auto Presentation::updateRecentGames() -> void {
  loadRecentGame.reset();

  //remove missing games from list
  for(uint index = 0; index < RecentGames;) {
    auto games = settings[{"Game/Recent/", 1 + index}].text();
    bool missing = false;
    if(games) {
      for(auto& game : games.split("|")) {
        if(!inode::exists(game.split(";").last())) missing = true;
      }
    }
    if(missing) {
      //will read one past the end of Games/Recent[RecentGames] by design:
      //this will always return an empty string to clear the last item in the list
      for(uint offset = index; offset < RecentGames; offset++) {
        settings[{"Game/Recent/", 1 + offset}].setValue(
          settings[{"Game/Recent/", 2 + offset}].text()
        );
      }
    } else {
      index++;
    }
  }

  //update list
  uint8_t recentGamesCount = 0; // MT.

  for(auto index : range(RecentGames)) {
    if(auto game = settings[{"Game/Recent/", 1 + index}].text()) {
      MenuItem item{&loadRecentGame}; // Moved inside `if` block by MT.
      string displayName;
      auto games = game.split("|");
      for(auto& game : games) {
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
    }/* else {
      item.setText({"(", tr("empty"), ")"});
      item.setEnabled(false);
    }*/ // Commented-out by MT.
  }

  if (recentGamesCount) { // MT.
    loadRecentGame.append(MenuSeparator());

    loadRecentGame.append(MenuItem().setIcon(Icon::Edit::Clear).setText(bms::get("Menu.File.LoadRecentGame.ClearList").data()).onActivate([&] { // tr("Clear List")
      for(auto index : range(RecentGames)) {
        settings({"Game/Recent/", 1 + index}).setValue("");
      }
      updateRecentGames();
    }));
  } // MT.
  /* MT. */
  else {
    loadRecentGame.append(MenuItem().setIcon(Icon::Emblem::File).setText({'(', bms::get("Menu.File.LoadRecentGame.NoRecentGames").data(), ')'})); // "(No recent games)"
  }
  /* /MT. */
}

auto Presentation::addRecentGame(string location) -> void {
  for(uint index : range(RecentGames + 1)) {
    auto value = settings[{"Game/Recent/", 1 + index}].text();
    if(!value || value == location) {
      for(uint n : reverse(range(index + 1))) {
        if(1 + n > RecentGames) continue;
        settings({"Game/Recent/", 1 + n}).setValue(settings[{"Game/Recent/", n}].text());
      }
      break;
    }
  }
  settings("Game/Recent/1").setValue(location);
  updateRecentGames();
}

auto Presentation::updateShaders() -> void {
  shaderMenu.reset();
  shaderMenu.setEnabled(video.hasShader());
  if(!video.hasShader()) return;

  Group shaders;

  MenuRadioItem none{&shaderMenu};
  none.setText(bms::get("Common.None").data()).onActivate([&] { // "None"
    settings.video.shader = "None";
    program.updateVideoShader();
  });
  shaders.append(none);

  MenuRadioItem blur{&shaderMenu};
  blur.setText(bms::get("Menu.Settings.Shader.Blur").data()).onActivate([&] { // "Blur"
    settings.video.shader = "Blur";
    program.updateVideoShader();
  });
  shaders.append(blur);

  auto location = locate("Shaders/");

  if(settings.video.driver == "OpenGL 3.2") {
    for(auto shader : directory::folders(location, "*.shader")) {
      if(shaders.objectCount() == 2) shaderMenu.append(MenuSeparator());
      MenuRadioItem item{&shaderMenu};
      item.setText(string{shader}.trimRight(".shader/", 1L)).onActivate([=] {
        settings.video.shader = {location, shader};
        program.updateVideoShader();
      });
      shaders.append(item);
    }
  }

  if(settings.video.shader == "None") none.setChecked();
  if(settings.video.shader == "Blur") blur.setChecked();
  for(auto item : shaders.objects<MenuRadioItem>()) {
    if(settings.video.shader == string{location, item.text(), ".shader/"}) {
      item.setChecked();
    }
  }
}
