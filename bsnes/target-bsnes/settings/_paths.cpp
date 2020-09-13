/* MT. */
#include "bsnes-mt/translations.h"

namespace bmt = bsnesMt::translations;
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

	gamesLabel.setText({bmt::get("Settings.Paths.Games").data(), colon});
	gamesPath.setEditable(false);

	gamesAssign.setText({bmt::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] {
		if (auto location = program.selectPath()) {
			settings.path.games = location;
			refreshPaths();
		}
	});

	gamesReset.setText(bmt::get("Common.Reset").data()).onActivate([&] {
		settings.path.games = "";
		refreshPaths();
	});

	patchesLabel.setText({bmt::get("Settings.Paths.Patches").data(), colon});
	patchesPath.setEditable(false);

	patchesAssign.setText({bmt::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] {
		if (auto location = program.selectPath()) {
			settings.path.patches = location;
			refreshPaths();
		}
	});

	patchesReset.setText(bmt::get("Common.Reset").data()).onActivate([&] {
		settings.path.patches = "";
		refreshPaths();
	});

	savesLabel.setText({bmt::get("Settings.Paths.Saves").data(), colon});
	savesPath.setEditable(false);

	savesAssign.setText({bmt::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] {
		if (auto location = program.selectPath()) {
			settings.path.saves = location;
			refreshPaths();
		}
	});

	savesReset.setText(bmt::get("Common.Reset").data()).onActivate([&] {
		settings.path.saves = "";
		refreshPaths();
	});

	cheatsLabel.setText({bmt::get("Settings.Paths.Cheats").data(), colon});
	cheatsPath.setEditable(false);

	cheatsAssign.setText({bmt::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] {
		if (auto location = program.selectPath()) {
			settings.path.cheats = location;
			refreshPaths();
		}
	});

	cheatsReset.setText(bmt::get("Common.Reset").data()).onActivate([&] {
		settings.path.cheats = "";
		refreshPaths();
	});

	statesLabel.setText({bmt::get("Settings.Paths.States").data(), colon});
	statesPath.setEditable(false);

	statesAssign.setText({bmt::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] {
		if (auto location = program.selectPath()) {
			settings.path.states = location;
			refreshPaths();
		}
	});

	statesReset.setText(bmt::get("Common.Reset").data()).onActivate([&] {
		settings.path.states = "";
		refreshPaths();
	});

	screenshotsLabel.setText({bmt::get("Settings.Paths.Screenshots").data(), colon});
	screenshotsPath.setEditable(false);

	screenshotsAssign.setText({bmt::get("Settings.Common.Assign").data(), ellipsis}).onActivate([&] {
		if (auto location = program.selectPath()) {
			settings.path.screenshots = location;
			refreshPaths();
		}
	});

	screenshotsReset.setText(bmt::get("Common.Reset").data()).onActivate([&] {
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
		gamesPath.setText({"(", bmt::get("Settings.Paths.LastRecentlyUsed").data(), ")"}).setForegroundColor(textColor);
	}

	if (auto location = settings.path.patches) {
		patchesPath.setText(location).setForegroundColor();
	}
	else {
		patchesPath.setText({"(", bmt::get("Settings.Paths.SameAsLoadedGame").data(), ")"}).setForegroundColor(textColor);
	}

	if (auto location = settings.path.saves) {
		savesPath.setText(location).setForegroundColor();
	}
	else {
		savesPath.setText({"(", bmt::get("Settings.Paths.SameAsLoadedGame").data(), ")"}).setForegroundColor(textColor);
	}

	if (auto location = settings.path.cheats) {
		cheatsPath.setText(location).setForegroundColor();
	}
	else {
		cheatsPath.setText({"(", bmt::get("Settings.Paths.SameAsLoadedGame").data(), ")"}).setForegroundColor(textColor);
	}

	if (auto location = settings.path.states) {
		statesPath.setText(location).setForegroundColor();
	}
	else {
		statesPath.setText({"(", bmt::get("Settings.Paths.SameAsLoadedGame").data(), ")"}).setForegroundColor(textColor);
	}

	if (auto location = settings.path.screenshots) {
		screenshotsPath.setText(location).setForegroundColor();
	}
	else {
		screenshotsPath.setText({"(", bmt::get("Settings.Paths.SameAsLoadedGame").data(), ")"}).setForegroundColor(textColor);
	}
}