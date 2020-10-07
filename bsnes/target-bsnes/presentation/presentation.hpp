/* MT. */
#include "bsnes-mt/app.h"

namespace bma = bsnesMt::app;
/* /MT. */

struct Presentation : Window {
	// Application::Namespace tr{"Presentation"}; // Commented-out by MT.
	auto create() -> void;

	enum : uint { RecentGames = bma::recentGamesNumber, QuickStates = bma::quickStatesNumber }; // Changed from 9 to 25 by MT.
	enum : uint { StatusHeight = 24 };

	auto onDrop(vector<string> locations) -> void;
	auto updateProgramIcon() -> void;
	auto updateStatusIcon() -> void;
	auto resizeWindow() -> void;
	auto updateStatus() -> void;
	auto updateDeviceMenu() -> void;
	auto updateDeviceSelections() -> void;
	auto updateSizeMenu() -> void;
	auto findState(vector<Program::State> &states, const string &name) -> maybe<uint64_t>; // MT.
	auto updateStateMenus() -> void;
	auto clearRecentGames() -> void;
	auto updateRecentGames() -> void;
	auto addRecentGame(string location) -> void;
	auto updateShaders() -> void;

	MenuBar menuBar{this};
	Menu fileMenu{&menuBar}; // MT.
		MenuItem openGame{&fileMenu};           // `systemMenu` => `fileMenu` by MT.
		Menu openRecentGame{&fileMenu};         // `systemMenu` => `fileMenu` by MT.
		MenuItem closeGame{&fileMenu};          // `systemMenu` => `fileMenu` by MT.
		MenuSeparator quitSeparator{&fileMenu}; // `systemMenu` => `fileMenu` by MT.
		MenuItem quit{&fileMenu};               // `systemMenu` => `fileMenu` by MT.
	Menu systemMenu{&menuBar};
		MenuItem resetSystem{&systemMenu};
		MenuSeparator portSeparator{&systemMenu};
		Menu controllerPort1{&systemMenu};
		Menu controllerPort2{&systemMenu};
		Menu expansionPort{&systemMenu};
	Menu settingsMenu{&menuBar};
		Menu sizeMenu{&settingsMenu};
			MenuItem fullScreenMenuItem; // MT.
			MenuItem pseudoFullScreenMenuItem; // MT.
		Group sizeGroup;
		Menu outputMenu{&settingsMenu};
			MenuRadioItem centerViewport{&outputMenu};
			MenuRadioItem perfectViewport{&outputMenu}; // MT.
			MenuRadioItem scaleViewport{&outputMenu};
			MenuRadioItem stretchViewport{&outputMenu};
			Group outputGroup{&centerViewport, &perfectViewport, &scaleViewport, &stretchViewport}; // `&perfectViewport,` added by MT.
			MenuSeparator outputSeparator{&outputMenu};
			MenuCheckItem aspectCorrection{&outputMenu};
			MenuCheckItem parInsteadOfAr{&outputMenu};
			MenuCheckItem showOverscanArea{&outputMenu};
			MenuCheckItem scalingInfo{&outputMenu}; // MT.
			MenuCheckItem blurEmulation{&outputMenu};
		Menu filterMenu{&settingsMenu};
			MenuRadioItem filterNone{&filterMenu};
			MenuRadioItem filterScanlinesLight{&filterMenu};
			MenuRadioItem filterScanlinesDark{&filterMenu};
			MenuRadioItem filterScanlinesBlack{&filterMenu};
			MenuRadioItem filterPixellate2x{&filterMenu};
			MenuRadioItem filterScale2x{&filterMenu};
			MenuRadioItem filter2xSaI{&filterMenu};
			MenuRadioItem filterSuper2xSaI{&filterMenu};
			MenuRadioItem filterSuperEagle{&filterMenu};
			MenuRadioItem filterLQ2x{&filterMenu};
			MenuRadioItem filterHQ2x{&filterMenu};
			MenuRadioItem filterNTSC_RF{&filterMenu};
			MenuRadioItem filterNTSC_Composite{&filterMenu};
			MenuRadioItem filterNTSC_SVideo{&filterMenu};
			MenuRadioItem filterNTSC_RGB{&filterMenu};
			Group filterGroup{
				&filterNone,
				&filterScanlinesLight,
				&filterScanlinesDark,
				&filterScanlinesBlack,
				&filterPixellate2x,
				&filterScale2x,
				&filter2xSaI,
				&filterSuper2xSaI,
				&filterSuperEagle,
				&filterLQ2x,
				&filterHQ2x,
				&filterNTSC_RF,
				&filterNTSC_Composite,
				&filterNTSC_SVideo,
				&filterNTSC_RGB
			};
		Menu shaderMenu{&settingsMenu};
		MenuSeparator settingsSeparatorA{&settingsMenu};
		MenuCheckItem muteAudio{&settingsMenu};
		MenuCheckItem showStatusBar{&settingsMenu};
		MenuSeparator settingsSeparatorB{&settingsMenu};
		MenuItem videoSettings{&settingsMenu};
		MenuItem audioSettings{&settingsMenu};
		MenuItem inputSettings{&settingsMenu};
		MenuItem hotkeySettings{&settingsMenu};
		MenuItem builtinHotkeysSettings{&settingsMenu}; // MT.
		MenuItem pathSettings{&settingsMenu};
		MenuItem emulatorSettings{&settingsMenu};
		MenuItem enhancementSettings{&settingsMenu};
		MenuItem compatibilitySettings{&settingsMenu};
		MenuItem driverSettings{&settingsMenu};
		MenuItem settingsFolder{&settingsMenu}; // MT.
	Menu toolsMenu{&menuBar};
		Menu saveState{&toolsMenu};
		Menu loadState{&toolsMenu};
		MenuSeparator toolsSeparatorB{&toolsMenu};
		Menu speedMenu{&toolsMenu};
			MenuRadioItem speedSlowest{&speedMenu};
			MenuRadioItem speedSlow{&speedMenu};
			MenuRadioItem speedNormal{&speedMenu};
			MenuRadioItem speedFast{&speedMenu};
			MenuRadioItem speedFastest{&speedMenu};
			Group speedGroup{&speedSlowest, &speedSlow, &speedNormal, &speedFast, &speedFastest};
		Menu runMenu{&toolsMenu};
			MenuRadioItem runEmulation{&runMenu};
			MenuRadioItem pauseEmulation{&runMenu};
			MenuRadioItem frameAdvance{&runMenu};
			Group runGroup{&runEmulation, &pauseEmulation, &frameAdvance};
		Menu movieMenu{&toolsMenu};
			MenuItem moviePlay{&movieMenu};
			MenuItem movieRecord{&movieMenu};
			MenuItem movieRecordFromBeginning{&movieMenu};
			MenuItem movieStop{&movieMenu};
		MenuItem captureScreenshot{&toolsMenu};
		MenuSeparator toolsSeparatorC{&toolsMenu};
		MenuItem cheatFinder{&toolsMenu};
		MenuItem cheatEditor{&toolsMenu};
		MenuItem stateManager{&toolsMenu};
		MenuItem manifestViewer{&toolsMenu};
	Menu helpMenu{&menuBar};
		MenuItem aboutSameBoy{&helpMenu};
		MenuItem aboutBsnes{&helpMenu};
		MenuItem aboutBsnesMt{&helpMenu}; // MT.

	VerticalLayout layout{this};
		HorizontalLayout viewportLayout{&layout, Size{~0, ~0}, 0};
			Viewport viewport{&viewportLayout, Size{~0, ~0}, 0};
			VerticalLayout iconLayout{&viewportLayout, Size{0, ~0}, 0};
				Canvas iconSpacer{&iconLayout, Size{144, ~0}, 0};
				Canvas iconCanvas{&iconLayout, Size{128, 128}, 0};
		HorizontalLayout statusLayout{&layout, Size{~0, StatusHeight}, 0};
			Label spacerIcon{&statusLayout, Size{8, ~0}, 0};
			Canvas statusIcon{&statusLayout, Size{16, ~0}, 0};
			Label spacerLeft{&statusLayout, Size{4, ~0}, 0};
			Label statusLeft{&statusLayout, Size{~0, ~0}, 0};
			Label statusRight{&statusLayout, Size{100, ~0}, 0};
			Label spacerRight{&statusLayout, Size{8, ~0}, 0};
};

namespace Instances {
	extern Instance<Presentation> presentation;
}

extern Presentation& presentation;