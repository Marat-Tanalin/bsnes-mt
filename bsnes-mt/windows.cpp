/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#include <Windows.h>
#include <Commctrl.h>

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

static bool messageBoxShown = false;

auto messageBox(const string &text, const string &title, UINT flags, HWND parentWindow) -> void {
	if (messageBoxShown) {
		return;
	}

	messageBoxShown = true;

	MessageBoxW(
		parentWindow,
		utf8ToWideString(text).data(),
		utf8ToWideString(title).data(),
		flags
	);

	messageBoxShown = false;
}

auto showMessage(const string &text, const string &title, UINT flags, HWND parentWindow) -> void {
	const UINT defaultFlags = MB_OK | MB_TOPMOST;

	messageBox(
		text,
		title,
		flags ? defaultFlags | flags : defaultFlags,
		parentWindow
	);
}

auto showError(const string &text, const string &title, HWND parentWindow) -> void {
	showMessage(text, title, MB_ICONERROR, parentWindow);
}

auto showNotice(const string &text, const string &title, HWND parentWindow) -> void {
	showMessage(text, title, MB_ICONEXCLAMATION, parentWindow);
}

auto showInfo(const string &text, const string &title, HWND parentWindow) -> void {
	showMessage(text, title, MB_ICONINFORMATION, parentWindow);
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
	const wstring windowTitleWide = utf8ToWideString(strings::get("Help.About") + " " + appTitle);
	const wstring headingWide     = utf8ToWideString(appTitle + " " + app::version);

	const wstring textWide        = utf8ToWideString(strings::get({
		{strings::EN, app::infoEn},
		{strings::RU, app::infoRu}
	}));

	config.cbSize             = sizeof(config);
	config.dwFlags            = TDF_USE_HICON_MAIN | TDF_ENABLE_HYPERLINKS | TDF_ALLOW_DIALOG_CANCELLATION;
	config.hMainIcon          = LoadIconW(GetModuleHandleW(NULL), MAKEINTRESOURCEW(2));
	config.hwndParent         = parentWindow;
	config.pszWindowTitle     = windowTitleWide.data();
	config.pszMainInstruction = headingWide.data();
	config.pszContent         = textWide.data();
	config.pfCallback         = showAboutCallback;

	TaskDialogIndirect(&config, NULL, NULL, NULL);
}

} // namespace bsnesMt::windows