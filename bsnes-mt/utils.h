/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

#include <string>

namespace bsnesMt {

using std::string, std::wstring;

struct time {
	uint16_t year, month, day, hours, minutes, seconds, ms;
};

auto getTime() -> time;

auto open(const wstring &path) -> void;
auto open(const string  &path) -> void;

} // namespace bsnesMt