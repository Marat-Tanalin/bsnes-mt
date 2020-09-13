/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#include <algorithm>
#include <vector>

#include <Windows.h>

#include "strings.h"

#include "utils.h"

namespace bsnesMt {

using std::vector;

auto getTime() -> time {
	SYSTEMTIME value;
	GetLocalTime(&value);

	return {
		value.wYear,
		value.wMonth,
		value.wDay,
		value.wHour,
		value.wMinute,
		value.wSecond,
		value.wMilliseconds
	};
}

auto open(const wstring &path) -> void {
	ShellExecuteW(NULL, L"open", path.data(), NULL, NULL, SW_SHOWNORMAL);
}

auto open(const string &path) -> void {
	open(strings::utf8ToWideString(path));
}

auto generateMenuItemHotkey(map<string, bool> hotkeys) -> string {
	vector<string> enabledHotkeys;

	for (auto const& [hotkey, enabled] : hotkeys) {
		if (enabled) {
			enabledHotkeys.push_back(hotkey);
		}
	}

	return enabledHotkeys.size() ? string("\t") + strings::join(enabledHotkeys, ", ") : "";
}

auto inArray(const vector<string> &items, const string &search) -> bool {
	return end(items) != std::find(begin(items), end(items), search);
}

} // namespace bsnesMt