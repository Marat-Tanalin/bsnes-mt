/* MT. */
#include "bsnes-mt/messagebox.h"
#include "bsnes-mt/strings.h"
#include "bsnes-mt/app.h"

namespace bms = bsnesMt::strings;
namespace bmw = bsnesMt::windows;
namespace bma = bsnesMt::app;
/* /MT. */

auto Program::load() -> void {
	unload();

	emulator->configure("System/Serialization/Method",   settings.emulator.serialization.method);
	emulator->configure("Hacks/Hotfixes",                settings.emulator.hack.hotfixes);
	emulator->configure("Hacks/Entropy",                 settings.emulator.hack.entropy);
	emulator->configure("Hacks/CPU/Overclock",           settings.emulator.hack.cpu.overclock);
	emulator->configure("Hacks/CPU/FastMath",            settings.emulator.hack.cpu.fastMath);
	emulator->configure("Hacks/PPU/Fast",                settings.emulator.hack.ppu.fast);
	emulator->configure("Hacks/PPU/Deinterlace",         settings.emulator.hack.ppu.deinterlace);
	emulator->configure("Hacks/PPU/NoSpriteLimit",       settings.emulator.hack.ppu.noSpriteLimit);
	emulator->configure("Hacks/PPU/NoVRAMBlocking",      settings.emulator.hack.ppu.noVRAMBlocking);
	emulator->configure("Hacks/PPU/Mode7/Scale",         settings.emulator.hack.ppu.mode7.scale);
	emulator->configure("Hacks/PPU/Mode7/Perspective",   settings.emulator.hack.ppu.mode7.perspective);
	emulator->configure("Hacks/PPU/Mode7/Supersample",   settings.emulator.hack.ppu.mode7.supersample);
	emulator->configure("Hacks/PPU/Mode7/Mosaic",        settings.emulator.hack.ppu.mode7.mosaic);
	emulator->configure("Hacks/DSP/Fast",                settings.emulator.hack.dsp.fast);
	emulator->configure("Hacks/DSP/Cubic",               settings.emulator.hack.dsp.cubic);
	emulator->configure("Hacks/DSP/EchoShadow",          settings.emulator.hack.dsp.echoShadow);
	emulator->configure("Hacks/Coprocessor/DelayedSync", settings.emulator.hack.coprocessor.delayedSync);
	emulator->configure("Hacks/Coprocessor/PreferHLE",   settings.emulator.hack.coprocessor.preferHLE);
	emulator->configure("Hacks/SuperFX/Overclock",       settings.emulator.hack.superfx.overclock);

	if (!emulator->load()) {
		return;
	}

	gameQueue  = {};
	screenshot = {};

	if (!verified() && emulatorSettings.warnOnUnverifiedGames.checked()) {
		//Emulator::loaded() is true at this point:
		//prevent Program::main() from calling Emulator::run() during this dialog window
		auto lock = acquire();

		/* // Commented-out by MT.
		string alwaysString = bms::get("Common.Always").data(); // MT.
		string noString     = bms::get("Common.No").data();     // MT.

		auto response = MessageDialog(bms::get("Game.unverifiedGameWarning").data()).setAlignment(*presentation)
			.question({alwaysString, bms::get("Common.Yes").data(), noString});

		if (response == noString) {
			emulator->unload();
			return showMessage(bms::get("Game.GameOpeningCancelled").data());
		}

		if (response == alwaysString) {
			emulatorSettings.warnOnUnverifiedGames.setChecked(false).doToggle();
		}
		*/

		/* MT. */
		auto windowId = presentation->handle();

		if (bmw::confirmById("Game.unverifiedGameWarning", windowId)) {
			if (bmw::confirmById("Game.unverifiedGameWarning.alwaysQuestion", windowId)) {
				emulatorSettings.warnOnUnverifiedGames.setChecked(false).doToggle();
			}
		}
		else {
			emulator->unload();
			return showMessage(bms::get("Game.GameOpeningCancelled").data());
		}
		/* /MT. */
	}

	hackCompatibility();
	emulator->power();

	if (emulatorSettings.autoLoadStateOnLoad.checked()) {
		program.loadState("Quick/Undo");
	}

	presentation.setFocused();
	presentation.setTitle({emulator->title(), " — ", bma::windowTitle.data()}); // Added emulator title and version by MT.
	presentation.resetSystem.setEnabled(true);
	presentation.unloadGame.setEnabled(true);
	presentation.toolsMenu.setVisible(true);
	presentation.updateStateMenus();
	presentation.speedNormal.setChecked();
	presentation.runEmulation.setChecked().doActivate();
	presentation.updateProgramIcon();
	presentation.updateStatusIcon();
	rewindReset();  //starts rewind state recording
	movieMode(Movie::Mode::Inactive);  //to set initial movie menu state
	cheatFinder.restart();  //clear any old cheat search results
	cheatEditor.loadCheats();
	stateManager.loadStates();
	manifestViewer.loadManifest();

	string games;

	/* MT. */
	bool   snesGame   = false;
	string gameRegion = "";
	/* /MT. */

	if (auto& game = superFamicom) {
		games.append(game.option, ";", game.location, "|");

		/* MT. */
		snesGame   = true;
		gameRegion = game.region;
		/* /MT. */
	}

	if (auto& game = gameBoy) {
		games.append(game.option, ";", game.location, "|");
	}

	if (auto& game = bsMemory) {
		games.append(game.option, ";", game.location, "|");
	}

	if (auto& game = sufamiTurboA) {
		games.append(game.option, ";", game.location, "|");
	}

	if (auto& game = sufamiTurboB) {
		games.append(game.option, ";", game.location, "|");
	}

	// Moved down by MT.
	showMessage({
		verified() ? bms::get("Game.VerifiedGameOpened").data() : bms::get("Game.GameOpened").data(),
		appliedPatch() ? bms::get("Game.AndPatchApplied").data() : "",
		snesGame ? string({" [", gameRegion, "]"}) : "" // MT.
	});

	presentation.addRecentGame(games.trimRight("|", 1L));

	updateVideoPalette();
	updateVideoEffects();
	updateAudioEffects();
	updateAudioFrequency();
}

auto Program::loadFile(string location) -> vector<uint8_t> {
	if (Location::suffix(location).downcase() == ".zip") {
		Decode::ZIP archive;

		if (archive.open(location)) {
			for (auto& file : archive.file) {
				auto type = Location::suffix(file.name).downcase();

				if (type == ".sfc" || type == ".smc" || type == ".gb" || type == ".gbc" || type == ".bs" || type == ".st") {
					return archive.extract(file);
				}
			}
		}

		return {};
	}

	if (Location::suffix(location).downcase() == ".7z") {
		return LZMA::extract(location);
	}

	return file::read(location);
}

auto Program::loadSuperFamicom(string location) -> bool {
	string manifest;
	vector<uint8_t> rom;

	if (location.endsWith("/")) {
		manifest = file::read({location, "manifest.bml"});

		rom.append(file::read({location, "program.rom"}));
		rom.append(file::read({location, "data.rom"}));
		rom.append(file::read({location, "expansion.rom"}));

		for (auto& filename : directory::files(location, "*.boot.rom")) {
			rom.append(file::read({location, filename}));
		}

		for (auto& filename : directory::files(location, "*.program.rom")) {
			rom.append(file::read({location, filename}));
		}

		for (auto& filename : directory::files(location, "*.data.rom")) {
			rom.append(file::read({location, filename}));
		}
	}
	else {
		manifest = file::read({Location::notsuffix(location), ".bml"});
		rom      = loadFile(location);
	}

	if (rom.size() < 0x8000) {
		return false;
	}

	if ((rom.size() & 0x7fff) == 512) {
		//remove copier header
		memory::move(&rom[0], &rom[512], rom.size() - 512);
		rom.resize(rom.size() - 512);
	}

	if (!superFamicom.patched) {
		superFamicom.patched = applyPatchIPS(rom, location);
	}

	if (!superFamicom.patched) {
		superFamicom.patched = applyPatchBPS(rom, location);
	}

	auto heuristics = Heuristics::SuperFamicom(rom, location);
	auto sha256     = Hash::SHA256(rom).digest();

	superFamicom.title  = heuristics.title();
	superFamicom.region = heuristics.videoRegion();

	if (auto document = BML::unserialize(string::read(locate("Database/Super Famicom.bml")))) {
		if (auto game = document[{"game(sha256=", sha256, ")"}]) {
			manifest = BML::serialize(game);
			//the internal ROM header title is not present in the database, but is needed for internal core overrides
			manifest.append("  title: ", superFamicom.title, "\n");
			superFamicom.verified = true;
		}
	}

	superFamicom.manifest = manifest ? manifest : heuristics.manifest();
	hackPatchMemory(rom);
	superFamicom.document = BML::unserialize(superFamicom.manifest);
	superFamicom.location = location;

	uint offset = 0;

	if (auto size = heuristics.programRomSize()) {
		superFamicom.program.resize(size);
		memory::copy(&superFamicom.program[0], &rom[offset], size);
		offset += size;
	}

	if (auto size = heuristics.dataRomSize()) {
		superFamicom.data.resize(size);
		memory::copy(&superFamicom.data[0], &rom[offset], size);
		offset += size;
	}

	if (auto size = heuristics.expansionRomSize()) {
		superFamicom.expansion.resize(size);
		memory::copy(&superFamicom.expansion[0], &rom[offset], size);
		offset += size;
	}

	if (auto size = heuristics.firmwareRomSize()) {
		superFamicom.firmware.resize(size);
		memory::copy(&superFamicom.firmware[0], &rom[offset], size);
		offset += size;
	}

	return true;
}

auto Program::loadGameBoy(string location) -> bool {
	string manifest;
	vector<uint8_t> rom;

	if (location.endsWith("/")) {
		manifest = file::read({location, "manifest.bml"});
		rom.append(file::read({location, "program.rom"}));
	}
	else {
		manifest = file::read({Location::notsuffix(location), ".bml"});
		rom      = loadFile(location);
	}

	if (rom.size() < 0x4000) {
		return false;
	}

	gameBoy.patched = applyPatchIPS(rom, location) || applyPatchBPS(rom, location);

	auto heuristics = Heuristics::GameBoy(rom, location);
	auto sha256     = Hash::SHA256(rom).digest();

	if (auto document = BML::unserialize(string::read(locate("Database/Game Boy.bml")))) {
		if (auto game = document[{"game(sha256=", sha256, ")"}]) {
			manifest = BML::serialize(game);
			gameBoy.verified = true;
		}
	}

	if (auto document = BML::unserialize(string::read(locate("Database/Game Boy Color.bml")))) {
		if (auto game = document[{"game(sha256=", sha256, ")"}]) {
			manifest = BML::serialize(game);
			gameBoy.verified = true;
		}
	}

	gameBoy.manifest = manifest ? manifest : heuristics.manifest();
	gameBoy.document = BML::unserialize(gameBoy.manifest);
	gameBoy.location = location;
	gameBoy.program  = rom;

	return true;
}

auto Program::loadBSMemory(string location) -> bool {
	string manifest;
	vector<uint8_t> rom;

	if (location.endsWith("/")) {
		manifest = file::read({location, "manifest.bml"});
		rom.append(file::read({location, "program.rom"}));
		rom.append(file::read({location, "program.flash"}));
	}
	else {
		manifest = file::read({Location::notsuffix(location), ".bml"});
		rom      = loadFile(location);
	}

	if (rom.size() < 0x8000) {
		return false;
	}

	bsMemory.patched = applyPatchIPS(rom, location) || applyPatchBPS(rom, location);

	auto heuristics = Heuristics::BSMemory(rom, location);
	auto sha256     = Hash::SHA256(rom).digest();

	if (auto document = BML::unserialize(string::read(locate("Database/BS Memory.bml")))) {
		if (auto game = document[{"game(sha256=", sha256, ")"}]) {
			manifest = BML::serialize(game);
			bsMemory.verified = true;
		}
	}

	bsMemory.manifest = manifest ? manifest : heuristics.manifest();
	bsMemory.document = BML::unserialize(bsMemory.manifest);
	bsMemory.location = location;
	bsMemory.program  = rom;

	return true;
}

auto Program::loadSufamiTurboA(string location) -> bool {
	string manifest;
	vector<uint8_t> rom;

	if (location.endsWith("/")) {
		manifest = file::read({location, "manifest.bml"});
		rom.append(file::read({location, "program.rom"}));
	}
	else {
		manifest = file::read({Location::notsuffix(location), ".bml"});
		rom      = loadFile(location);
	}

	if (rom.size() < 0x20000) {
		return false;
	}

	sufamiTurboA.patched = applyPatchIPS(rom, location) || applyPatchBPS(rom, location);

	auto heuristics = Heuristics::SufamiTurbo(rom, location);
	auto sha256     = Hash::SHA256(rom).digest();

	if (auto document = BML::unserialize(string::read(locate("Database/Sufami Turbo.bml")))) {
		if (auto game = document[{"game(sha256=", sha256, ")"}]) {
			manifest = BML::serialize(game);
			sufamiTurboA.verified = true;
		}
	}

	sufamiTurboA.manifest = manifest ? manifest : heuristics.manifest();
	sufamiTurboA.document = BML::unserialize(sufamiTurboA.manifest);
	sufamiTurboA.location = location;
	sufamiTurboA.program  = rom;

	return true;
}

auto Program::loadSufamiTurboB(string location) -> bool {
	string manifest;
	vector<uint8_t> rom;

	if (location.endsWith("/")) {
		manifest = file::read({location, "manifest.bml"});
		rom.append(file::read({location, "program.rom"}));
	}
	else {
		manifest = file::read({Location::notsuffix(location), ".bml"});
		rom      = loadFile(location);
	}

	if (rom.size() < 0x20000) {
		return false;
	}

	sufamiTurboB.patched = applyPatchIPS(rom, location) || applyPatchBPS(rom, location);

	auto heuristics = Heuristics::SufamiTurbo(rom, location);
	auto sha256     = Hash::SHA256(rom).digest();

	if (auto document = BML::unserialize(string::read(locate("Database/Sufami Turbo.bml")))) {
		if (auto game = document[{"game(sha256=", sha256, ")"}]) {
			manifest = BML::serialize(game);
			sufamiTurboB.verified = true;
		}
	}

	sufamiTurboB.manifest = manifest ? manifest : heuristics.manifest();
	sufamiTurboB.document = BML::unserialize(sufamiTurboB.manifest);
	sufamiTurboB.location = location;
	sufamiTurboB.program  = rom;

	return true;
}

auto Program::save() -> void {
	if (!emulator->loaded()) {
		return;
	}

	emulator->save();
}

auto Program::reset() -> void {
	if (!emulator->loaded()) {
		return;
	}

	rewindReset();  //don't allow rewinding past a reset point
	hackCompatibility();
	emulator->reset();
	showMessage(bms::get("Game.GameReset").data());
}

auto Program::unload() -> void {
	if (!emulator->loaded()) {
		return;
	}

	//todo: video.clear() is not working on macOS/OpenGL 3.2
	if (auto [output, length] = video.acquire(1, 1); output) {
		*output = 0;
		video.release();
		video.output();
	}

	audio.clear();
	rewindReset();  //free up memory that is no longer needed
	movieStop();  //in case a movie is currently being played or recorded
	cheatEditor.saveCheats();
	toolsWindow.setVisible(false);

	if (emulatorSettings.autoSaveStateOnUnload.checked()) {
		saveUndoState();
	}

	emulator->unload();
	showMessage(bms::get("Game.GameClosed").data());

	superFamicom = {};
	gameBoy      = {};
	bsMemory     = {};
	sufamiTurboA = {};
	sufamiTurboB = {};

	presentation.setTitle(bma::windowTitle.data());
	presentation.resetSystem.setEnabled(false);
	presentation.unloadGame.setEnabled(false);
	presentation.toolsMenu.setVisible(false);
	presentation.updateProgramIcon();
	presentation.updateStatusIcon();
}

// Refactored by MT.
//a game is considered verified if the game plus its slot(s) are found in the games database
auto Program::verified() const -> bool {
	return emulator->loaded() &&
		(
			superFamicom && superFamicom.verified ||
			gameBoy      && gameBoy.verified      ||
			bsMemory     && bsMemory.verified     ||
			sufamiTurboA && sufamiTurboA.verified ||
			sufamiTurboB && sufamiTurboB.verified
		);
}