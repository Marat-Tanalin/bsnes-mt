/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#include "strings.h"

#include "utils.h"

namespace bsnesMt {

auto getTime() -> SYSTEMTIME {
	SYSTEMTIME time;
	GetLocalTime(&time);
	return time;
}

auto open(const wstring &path) -> void {
	ShellExecuteW(NULL, L"open", path.data(), NULL, NULL, SW_SHOWNORMAL);
}

auto open(const string &path) -> void {
	open(strings::utf8ToWideString(path));
}

} // namespace bsnesMt