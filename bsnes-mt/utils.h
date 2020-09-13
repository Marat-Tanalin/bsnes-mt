/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

#include <string>

#include <Windows.h>

namespace bsnesMt {

using std::string, std::wstring;

auto getTime() -> SYSTEMTIME;

auto open(const wstring &path) -> void;
auto open(const string  &path) -> void;

} // namespace bsnesMt