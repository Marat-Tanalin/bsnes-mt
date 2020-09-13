/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

#include <map>
#include <string>
#include <vector>

namespace bsnesMt {

using std::map, std::string, std::wstring, std::vector;

struct time {
	uint16_t year, month, day, hours, minutes, seconds, ms;
};

auto getTime() -> time;

auto open(const wstring &path) -> void;
auto open(const string  &path) -> void;

auto generateMenuItemHotkey(map<string, bool> hotkeys) -> string;

auto inArray(const vector<string> &items, const string &search) -> bool;

} // namespace bsnesMt