/* MT. */
#include <string>

#include <Windows.h>

#include "bsnes-mt/utils.h"
/* /MT. */

// Refactored by MT.
auto Program::path(string type, string location, string extension) -> string {
	auto s = settings.path;

	string path;

	if (type == "Games") {
		path = s.games;
	}
	else if (type == "Patches") {
		path = s.patches;
	}
	else if (type == "Saves") {
		path = s.saves;
	}
	else if (type == "Cheats") {
		path = s.cheats;
	}
	else if (type == "States") {
		path = s.states;
	}
	else if (type == "Screenshots") {
		path = s.screenshots;
	}

	if (!path) {
		path = Location::path(location);
	}

	return {path, Location::prefix(Location::file(location)), extension};
}

auto Program::gamePath() -> string {
	if (!emulator->loaded()) {
		return "";
	}

	if (gameBoy.location) {
		return gameBoy.location;
	}

	return superFamicom.location;
}

auto Program::cheatPath() -> string {
	if (!emulator->loaded()) {
		return "";
	}

	auto location = gamePath();

	if (location.endsWith("/")) {
		return {location, "cheats.bml"};
	}

	return path("Cheats", location, ".cht");
}

auto Program::statePath() -> string {
	if (!emulator->loaded()) {
		return "";
	}

	auto location = gamePath();

	if (location.endsWith("/")) {
		return {location, "bsnes/states/"};
	}

	return path("States", location, ".bsz");
}

// Modified by MT.
auto Program::screenshotPath() -> string {
	if (!emulator->loaded()) {
		return "";
	}

	auto location = gamePath();

	if (location.endsWith("/")) {
		location = {location, "bsnes/screenshots/"};
	}
	else {
		location = {path("Screenshots", location), "/"};
	}

	directory::create(location);

	auto ext  = ".png";
	auto time = bsnesMt::getTime();

	string basePath = {
		location,
		time.year, '-',
		pad(time.month,  2, '0'), '-',
		pad(time.day,    2, '0'), ' ',
		pad(time.hours,   2, '0'), '-',
		pad(time.minutes, 2, '0'), '-',
		pad(time.seconds, 2, '0')
	};

	string filePath = {basePath, ext};

	if (file::exists(filePath)) {
		string msSuffix = {'-', pad(time.ms, 3, '0')};

		filePath = {basePath, msSuffix, ext};

		uint i = 2;
	
		while (file::exists(filePath)) {
			filePath = {basePath, msSuffix, '_', i, ext};
			i++;
		}
	}

	return filePath;
}