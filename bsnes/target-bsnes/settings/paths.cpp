#include "bsnes-mt/strings.h" // MT.

namespace bms = bsnesMt::strings; // MT.

auto PathSettings::create() -> void {
  setCollapsible();
  setVisible(false);

  layout.setSize({4, 6});
  layout.column(0).setAlignment(1.0);

  auto colon    = ":"; // MT.
  auto ellipsis = "..."; // MT.

  gamesLabel.setText({bms::get("Paths.Games").data(), colon}); // "Games:"
  gamesPath.setEditable(false);
  gamesAssign.setText({bms::get("Paths.Assign").data(), ellipsis}).onActivate([&] { // "Assign..."
    if(auto location = program.selectPath()) {
      settings.path.games = location;
      refreshPaths();
    }
  });
  gamesReset.setText(bms::get("Common.Reset").data()).onActivate([&] { // "Reset"
    settings.path.games = "";
    refreshPaths();
  });

  patchesLabel.setText({bms::get("Paths.Patches").data(), colon}); // "Patches:"
  patchesPath.setEditable(false);
  patchesAssign.setText({bms::get("Paths.Assign").data(), ellipsis}).onActivate([&] { // "Assign..."
    if(auto location = program.selectPath()) {
      settings.path.patches = location;
      refreshPaths();
    }
  });
  patchesReset.setText(bms::get("Common.Reset").data()).onActivate([&] { // "Reset"
    settings.path.patches = "";
    refreshPaths();
  });

  savesLabel.setText({bms::get("Paths.Saves").data(), colon}); // "Saves:"
  savesPath.setEditable(false);
  savesAssign.setText({bms::get("Paths.Assign").data(), ellipsis}).onActivate([&] { // "Assign..."
    if(auto location = program.selectPath()) {
      settings.path.saves = location;
      refreshPaths();
    }
  });
  savesReset.setText(bms::get("Common.Reset").data()).onActivate([&] { // "Reset"
    settings.path.saves = "";
    refreshPaths();
  });

  cheatsLabel.setText({bms::get("Paths.Cheats").data(), colon}); // "Cheats:"
  cheatsPath.setEditable(false);
  cheatsAssign.setText({bms::get("Paths.Assign").data(), ellipsis}).onActivate([&] { // "Assign..."
    if(auto location = program.selectPath()) {
      settings.path.cheats = location;
      refreshPaths();
    }
  });
  cheatsReset.setText(bms::get("Common.Reset").data()).onActivate([&] { // "Reset"
    settings.path.cheats = "";
    refreshPaths();
  });

  statesLabel.setText({bms::get("Paths.States").data(), colon}); // "States:"
  statesPath.setEditable(false);
  statesAssign.setText({bms::get("Paths.Assign").data(), ellipsis}).onActivate([&] { // "Assign..."
    if(auto location = program.selectPath()) {
      settings.path.states = location;
      refreshPaths();
    }
  });
  statesReset.setText(bms::get("Common.Reset").data()).onActivate([&] { // "Reset"
    settings.path.states = "";
    refreshPaths();
  });

  screenshotsLabel.setText({bms::get("Paths.Screenshots").data(), colon}); // "Screenshots:"
  screenshotsPath.setEditable(false);
  screenshotsAssign.setText({bms::get("Paths.Assign").data(), ellipsis}).onActivate([&] { // "Assign..."
    if(auto location = program.selectPath()) {
      settings.path.screenshots = location;
      refreshPaths();
    }
  });
  screenshotsReset.setText(bms::get("Common.Reset").data()).onActivate([&] { // "Reset"
    settings.path.screenshots = "";
    refreshPaths();
  });

  refreshPaths();
}

auto PathSettings::refreshPaths() -> void {
  if(auto location = settings.path.games) {
    gamesPath.setText(location).setForegroundColor();
  } else {
    gamesPath.setText({'(', bms::get("Paths.LastRecentlyUsed").data(), ')'}).setForegroundColor({128, 128, 128}); // "(last recently used)"
  }
  if(auto location = settings.path.patches) {
    patchesPath.setText(location).setForegroundColor();
  } else {
    patchesPath.setText({'(', bms::get("Paths.SameAsLoadedGame").data(), ')'}).setForegroundColor({128, 128, 128}); // "(same as loaded game)"
  }
  if(auto location = settings.path.saves) {
    savesPath.setText(location).setForegroundColor();
  } else {
    savesPath.setText({'(', bms::get("Paths.SameAsLoadedGame").data(), ')'}).setForegroundColor({128, 128, 128}); // "(same as loaded game)"
  }
  if(auto location = settings.path.cheats) {
    cheatsPath.setText(location).setForegroundColor();
  } else {
    cheatsPath.setText({'(', bms::get("Paths.SameAsLoadedGame").data(), ')'}).setForegroundColor({128, 128, 128}); // "(same as loaded game)"
  }
  if(auto location = settings.path.states) {
    statesPath.setText(location).setForegroundColor();
  } else {
    statesPath.setText({'(', bms::get("Paths.SameAsLoadedGame").data(), ')'}).setForegroundColor({128, 128, 128}); // "(same as loaded game)"
  }
  if(auto location = settings.path.screenshots) {
    screenshotsPath.setText(location).setForegroundColor();
  } else {
    screenshotsPath.setText({'(', bms::get("Paths.SameAsLoadedGame").data(), ')'}).setForegroundColor({128, 128, 128}); // "(same as loaded game)"
  }
}
