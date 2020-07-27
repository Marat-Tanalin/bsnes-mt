/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

#include <cstdint>
#include <string>

namespace bsnesMt::windows {

using std::string;

/*
	Standard types are used instead of WinAPI-specific ones to prevent
	conflicts with bsnes internals leading to compile-time errors:

	* `HWND` => `uintptr_t` (`parentWindow`);
	* `UINT` => `uint32_t` (`flags`);
	* `NULL` => `0` (`parentWindow` default value).
*/

auto messageBox(const string &text, const string &title = "", uint32_t flags = 0, uintptr_t parentWindow = 0) -> int;

auto showMessage(const string &text, const string &title = "", uint32_t flags = 0, uintptr_t parentWindow = 0) -> void;
auto showError(const string &text, const string &title = "", uintptr_t parentWindow = 0) -> void;
auto showNotice(const string &text, const string &title = "", uintptr_t parentWindow = 0) -> void;
auto showInfo(const string &text, const string &title = "", uintptr_t parentWindow = 0) -> void;

auto confirm(const string &text, const string &title = "", uintptr_t parentWindow = 0) -> bool;
auto confirmById(const string &textId, uintptr_t parentWindow = 0) -> bool;

} // namespace bsnesMt::windows