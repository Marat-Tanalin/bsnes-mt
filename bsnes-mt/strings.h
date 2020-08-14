/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

#include <cstdint>
#include <map>
#include <string>

#include "translations.h"

namespace bsnesMt::strings {

using std::map, std::string;

auto getLocale() -> uint8_t;

static uint8_t locale = getLocale();

auto genericHas(const map<string, map<uint8_t, string>> &items, const string &key) -> bool;
auto genericHas(const map<string, string>               &items, const string &key) -> bool;

auto has(const string &id) -> bool;

auto valueHasLocale(const map<uint8_t, string> &value, uint8_t locale) -> bool;

auto get(const map<uint8_t, string> &value) -> string;
auto get(const string &id) -> string;

auto getStringOrId(const map<string, map<uint8_t, string>> &values, const string &id) -> string;

auto getDedicatedString(
	const map<string, map<uint8_t, string>> &values,
	const map<string, string> &dedicatedToRegularStrings,
	const string &id
) -> string;

auto getDeviceString(const string &id) -> string;
auto getHotkeyString(const string &id) -> string;

} // namespace bsnesMt::strings