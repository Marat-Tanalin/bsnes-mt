/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include <Windows.h>

namespace bsnesMt {

using std::string, std::wstring, std::vector;

auto utf8ToWideString(const string &utf8) -> wstring;

auto getTime() -> SYSTEMTIME;

auto open(const wstring &path) -> void;
auto open(const string  &path) -> void;

auto saveFile(const string &data, const string &path) -> bool;

auto saveBgraArrayAsPngImage(uint8_t* data, uint16_t width, uint16_t height, const string &path) -> bool;

auto ucharVectorToString(const vector<unsigned char> &data) -> string;

auto getUiLang() -> BYTE;

auto replace(const string &s, char search, const string replace) -> string;

} // namespace bsnesMt