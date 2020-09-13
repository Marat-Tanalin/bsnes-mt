/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#include <Windows.h>
#include <Commctrl.h>

#include <target-bsnes/resource/resources.h>

#include "app.h"
#include "strings.h"
#include "utils.h"

#include "windows.h"

namespace bsnesMt::windows {

using std::wstring;

auto getWorkAreaSize() -> SIZE {
	RECT rect;
	SIZE size;

	SystemParametersInfoW(SPI_GETWORKAREA, 0, &rect, 0);

	size.cx = rect.right  - rect.left;
	size.cy = rect.bottom - rect.top;

	return size;
}

auto isTopLevelWindow(HWND window) -> bool {
	return window == GetAncestor(window, GA_ROOT);
}

auto showAboutCallback(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, LONG_PTR lpRefData) -> HRESULT {
	if (TDN_HYPERLINK_CLICKED == msg) {
		open((wchar_t*)lParam);
	}

	return S_OK;
}

auto showAbout(HWND parentWindow) -> void {
	const string appTitle = app::title;

	TASKDIALOGCONFIG config{};

	// Variables are needed, otherwise `TaskDialogIndirect()` may display random garbage.
	const wstring windowTitleWide = utf8ToWideString(replace(strings::get("Menu.Help.About"), '|', appTitle));
	const wstring headingWide     = utf8ToWideString(appTitle + " " + app::version);

	const wstring textWide        = utf8ToWideString(strings::get({
		{strings::EN, app::infoEn},
		{strings::RU, app::infoRu}
	}));

	config.cbSize             = sizeof(config);
	config.dwFlags            = TDF_USE_HICON_MAIN | TDF_ENABLE_HYPERLINKS | TDF_ALLOW_DIALOG_CANCELLATION;
	config.hMainIcon          = LoadIconW(GetModuleHandleW(NULL), MAKEINTRESOURCEW(IDI_APPICON));
	config.hwndParent         = parentWindow;
	config.pszWindowTitle     = windowTitleWide.data();
	config.pszMainInstruction = headingWide.data();
	config.pszContent         = textWide.data();
	config.pfCallback         = showAboutCallback;

	TaskDialogIndirect(&config, NULL, NULL, NULL);
}

} // namespace bsnesMt::windows