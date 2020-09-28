/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

#include <string>
#include <vector>

namespace bsnesMt::strings {

using std::string, std::wstring, std::vector;

auto utf8ToWideString(const string &utf8) -> wstring;
auto wideStringToUtf8String(const wstring &wide) -> string;

auto toLowerCase(string str) -> string;

auto replaceByRef(string &str, const string &search, const string &replacement) -> void;
auto replace(string str, const string &search, const string &replacement) -> string;
auto replace(const string &str, const string &search, char replacement) -> string;
auto replace(const string &s, char search, char replacement) -> string;
auto replaceOnce(const string &s, char search, const string &replacement) -> string;
auto replaceOnce(const string &s, const string &search, const string &replacement) -> string;

auto unifyLineFeeds(string text) -> string;

auto trimByRef(string &s, const string &chars) -> void;
auto trim(string s, const string &chars) -> string;
auto trim(const string &s) -> string;

auto isWhiteSpace(const string &s) -> bool;

auto ucharVectorToString(const vector<unsigned char> &data) -> string;

auto split(string s, const string &delim) -> vector<string>;
auto join(const vector<string> &v, const string &delim) -> string;

} // namespace bsnesMt::strings