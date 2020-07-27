/* MT. */
#include "bsnes-mt/strings.h"

namespace bms = bsnesMt::strings;
/* /MT. */

auto PathSettings::create() -> void {
	setCollapsible();
	setVisible(false);

	layout.setSize({4, 6});
	layout.column(0).setAlignment(1.0);

	/* MT. */
	auto colon    = ":";
	auto ellipsis = "...";
	/* /MT. */

	gamesLabel.setText({bms::get("Settings.Paths.Games").data(), colon}); // "Games:"
	gamesPath.setEditable(false);

	gamesAssign.setText({bms::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] { // "Assign..."
		if (auto location = program.selectPath()) {
			settings.path.games = location;
			refreshPaths();
		}
	});

	gamesReset.setText(bms::get("Common.Reset").data()).onActivate([&] { // "Reset"
		settings.path.games = "";
		refreshPaths();
	});

	patchesLabel.setText({bms::get("Settings.Paths.Patches").data(), colon}); // "Patches:"
	patchesPath.setEditable(false);

	patchesAssign.setText({bms::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] { // "Assign..."
		if (auto location = program.selectPath()) {
			settings.path.patches = location;
			refreshPaths();
		}
	});

	patchesReset.setText(bms::get("Common.Reset").data()).onActivate([&] { // "Reset"
		settings.path.patches = "";
		refreshPaths();
	});

	savesLabel.setText({bms::get("Settings.Paths.Saves").data(), colon}); // "Saves:"
	savesPath.setEditable(false);

	savesAssign.setText({bms::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] { // "Assign..."
		if (auto location = program.selectPath()) {
			settings.path.saves = location;
			refreshPaths();
		}
	});

	savesReset.setText(bms::get("Common.Reset").data()).onActivate([&] { // "Reset"
		settings.path.saves = "";
		refreshPaths();
	});

	cheatsLabel.setText({bms::get("Settings.Paths.Cheats").data(), colon}); // "Cheats:"
	cheatsPath.setEditable(false);

	cheatsAssign.setText({bms::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] { // "Assign..."
		if (auto location = program.selectPath()) {
			settings.path.cheats = location;
			refreshPaths();
		}
	});

	cheatsReset.setText(bms::get("Common.Reset").data()).onActivate([&] { // "Reset"
		settings.path.cheats = "";
		refreshPaths();
	});

	statesLabel.setText({bms::get("Settings.Paths.States").data(), colon}); // "States:"
	statesPath.setEditable(false);

	statesAssign.setText({bms::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] { // "Assign..."
		if (auto location = program.selectPath()) {
			settings.path.states = location;
			refreshPaths();
		}
	});

	statesReset.setText(bms::get("Common.Reset").data()).onActivate([&] { // "Reset"
		settings.path.states = "";
		refreshPaths();
	});

	screenshotsLabel.setText({bms::get("Settings.Paths.Screenshots").data(), colon}); // "Screenshots:"
	screenshotsPath.setEditable(false);

	screenshotsAssign.setText({bms::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] { // "Assign..."
		if (auto location = program.selectPath()) {
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
	if (auto location = settings.path.games) {
		gamesPath.setText(location).setForegroundColor();
	}
	else {
		gamesPath.setText({"(", bms::get("Settings.Paths.LastRecentlyUsed").data(), ")"}).setForegroundColor({128, 128, 128}); // "(last recently used)"
	}

	if (auto location = settings.path.patches) {
		patchesPath.setText(location).setForegroundColor();
	}
	else {
		patchesPath.setText({"(", bms::get("Settings.Paths.SameAsLoadedGame").data(), ")"}).setForegroundColor({128, 128, 128}); // "(same as loaded game)"
	}

	if (auto location = settings.path.saves) {
		savesPath.setText(location).setForegroundColor();
	}
	else {
		savesPath.setText({"(", bms::get("Settings.Paths.SameAsLoadedGame").data(), ")"}).setForegroundColor({128, 128, 128}); // "(same as loaded game)"
	}

	if (auto location = settings.path.cheats) {
		cheatsPath.setText(location).setForegroundColor();
	}
	else {
		cheatsPath.setText({"(", bms::get("Settings.Paths.SameAsLoadedGame").data(), ")"}).setForegroundColor({128, 128, 128}); // "(same as loaded game)"
	}

	if (auto location = settings.path.states) {
		statesPath.setText(location).setForegroundColor();
	}
	else {
		statesPath.setText({"(", bms::get("Settings.Paths.SameAsLoadedGame").data(), ")"}).setForegroundColor({128, 128, 128}); // "(same as loaded game)"
	}

	if (auto location = settings.path.screenshots) {
		screenshotsPath.setText(location).setForegroundColor();
	}
	else {
		screenshotsPath.setText({"(", bms::get("Settings.Paths.SameAsLoadedGame").data(), ")"}).setForegroundColor({128, 128, 128}); // "(same as loaded game)"
	}
}