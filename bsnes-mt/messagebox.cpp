/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#include <Windows.h>
#include <Commctrl.h>

#include "strings.h"
#include "utils.h"

#include "messagebox.h"

namespace bsnesMt::windows {

using std::wstring;

auto messageBox(const string &text, const string &title, uint32_t flags, uintptr_t parentWindow) -> int {
	return MessageBoxW(
		reinterpret_cast<HWND>(parentWindow),
		utf8ToWideString(text).data(),
		utf8ToWideString(title).data(),
		flags
	);
}

auto showMessage(const string &text, const string &title, uint32_t flags, uintptr_t parentWindow) -> void {
	const UINT defaultFlags = MB_OK | MB_TOPMOST;

	messageBox(
		text,
		title,
		flags ? defaultFlags | flags : defaultFlags,
		parentWindow
	);
}

auto showError(const string &text, const string &title, uintptr_t parentWindow) -> void {
	showMessage(
		text,
		"" == title ? strings::get("Common.Error") : title,
		MB_ICONERROR,
		parentWindow
	);
}

auto showNotice(const string &text, const string &title, uintptr_t parentWindow) -> void {
	showMessage(text, title, MB_ICONEXCLAMATION, parentWindow);
}

auto showInfo(const string &text, const string &title, uintptr_t parentWindow) -> void {
	showMessage(text, title, MB_ICONINFORMATION, parentWindow);
}

auto confirm(const string &text, const string &title, uintptr_t parentWindow) -> bool {
	return IDYES == messageBox(
		text,
		"" == title ? strings::get("Common.AreYouSure") : title,
		MB_ICONQUESTION | MB_YESNO | MB_DEFBUTTON2,
		parentWindow
	);
}

auto confirmById(const string &textId, uintptr_t parentWindow) -> bool {
	string titleId = textId + ".title";

	return confirm(
		strings::get(textId),
		strings::has(titleId) ? strings::get(titleId) : strings::get("Common.AreYouSure"),
		parentWindow
	);
}

} // namespace bsnesMt::windows