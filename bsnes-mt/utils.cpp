/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#include <Windows.h>

#include "strings.h"

#include "utils.h"

namespace bsnesMt {

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

} // namespace bsnesMt