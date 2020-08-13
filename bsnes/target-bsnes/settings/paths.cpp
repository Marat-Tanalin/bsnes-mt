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

	gamesLabel.setText({bms::get("Settings.Paths.Games").data(), colon});
	gamesPath.setEditable(false);

	gamesAssign.setText({bms::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] {
		if (auto location = program.selectPath()) {
			settings.path.games = location;
			refreshPaths();
		}
	});

	gamesReset.setText(bms::get("Common.Reset").data()).onActivate([&] {
		settings.path.games = "";
		refreshPaths();
	});

	patchesLabel.setText({bms::get("Settings.Paths.Patches").data(), colon});
	patchesPath.setEditable(false);

	patchesAssign.setText({bms::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] {
		if (auto location = program.selectPath()) {
			settings.path.patches = location;
			refreshPaths();
		}
	});

	patchesReset.setText(bms::get("Common.Reset").data()).onActivate([&] {
		settings.path.patches = "";
		refreshPaths();
	});

	savesLabel.setText({bms::get("Settings.Paths.Saves").data(), colon});
	savesPath.setEditable(false);

	savesAssign.setText({bms::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] {
		if (auto location = program.selectPath()) {
			settings.path.saves = location;
			refreshPaths();
		}
	});

	savesReset.setText(bms::get("Common.Reset").data()).onActivate([&] {
		settings.path.saves = "";
		refreshPaths();
	});

	cheatsLabel.setText({bms::get("Settings.Paths.Cheats").data(), colon});
	cheatsPath.setEditable(false);

	cheatsAssign.setText({bms::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] {
		if (auto location = program.selectPath()) {
			settings.path.cheats = location;
			refreshPaths();
		}
	});

	cheatsReset.setText(bms::get("Common.Reset").data()).onActivate([&] {
		settings.path.cheats = "";
		refreshPaths();
	});

	statesLabel.setText({bms::get("Settings.Paths.States").data(), colon});
	statesPath.setEditable(false);

	statesAssign.setText({bms::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] {
		if (auto location = program.selectPath()) {
			settings.path.states = location;
			refreshPaths();
		}
	});

	statesReset.setText(bms::get("Common.Reset").data()).onActivate([&] {
		settings.path.states = "";
		refreshPaths();
	});

	screenshotsLabel.setText({bms::get("Settings.Paths.Screenshots").data(), colon});
	screenshotsPath.setEditable(false);

	screenshotsAssign.setText({bms::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] {
		if (auto location = program.selectPath()) {
			settings.path.screenshots = location;
			refreshPaths();
		}
	});

	screenshotsReset.setText(bms::get("Common.Reset").data()).onActivate([&] {
		settings.path.screenshots = "";
		refreshPaths();
	});

	refreshPaths();
}

auto PathSettings::refreshPaths() -> void {
	Color textColor = {128, 128, 128}; // MT.

	if (auto location = settings.path.games) {
		gamesPath.setText(location).setForegroundColor();
	}
	else {
		gamesPath.setText({"(", bms::get("Settings.Paths.LastRecentlyUsed").data(), ")"}).setForegroundColor(textColor);
	}

	if (auto location = settings.path.patches) {
		patchesPath.setText(location).setForegroundColor();
	}
	else {
		patchesPath.setText({"(", bms::get("Settings.Paths.SameAsLoadedGame").data(), ")"}).setForegroundColor(textColor);
	}

	if (auto location = settings.path.saves) {
		savesPath.setText(location).setForegroundColor();
	}
	else {
		savesPath.setText({"(", bms::get("Settings.Paths.SameAsLoadedGame").data(), ")"}).setForegroundColor(textColor);
	}

	if (auto location = settings.path.cheats) {
		cheatsPath.setText(location).setForegroundColor();
	}
	else {
		cheatsPath.setText({"(", bms::get("Settings.Paths.SameAsLoadedGame").data(), ")"}).setForegroundColor(textColor);
	}

	if (auto location = settings.path.states) {
		statesPath.setText(location).setForegroundColor();
	}
	else {
		statesPath.setText({"(", bms::get("Settings.Paths.SameAsLoadedGame").data(), ")"}).setForegroundColor(textColor);
	}

	if (auto location = settings.path.screenshots) {
		screenshotsPath.setText(location).setForegroundColor();
	}
	else {
		screenshotsPath.setText({"(", bms::get("Settings.Paths.SameAsLoadedGame").data(), ")"}).setForegroundColor(textColor);
	}
}