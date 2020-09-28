/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#include <algorithm>
#include <locale>
#include <memory>
#include <sstream>

#include <Windows.h>

#include "strings.h"

namespace bsnesMt::strings {

using std::make_unique;

auto utf8ToWideString(const string &utf8) -> wstring {
	wstring wide;

	auto utf8c = utf8.data();
	int  size  = MultiByteToWideChar(CP_UTF8, 0, utf8c, -1, 0, 0);

	if (size > 0) {
		auto buffer = make_unique<wchar_t[]>(size);
		MultiByteToWideChar(CP_UTF8, 0, utf8c, -1, buffer.get(), size);
		wide = buffer.get();
	}

	return wide;
}

auto wideStringToUtf8String(const wstring &wide) -> string {
	string utf8;

	auto widec = wide.data();
	int  size  = WideCharToMultiByte(CP_UTF8, 0, widec, -1, 0, 0, 0, 0);

	if (size > 0) {
		auto buffer = std::make_unique<char[]>(size);
		WideCharToMultiByte(CP_UTF8, 0, widec, -1, buffer.get(), size, 0, 0);
		utf8 = buffer.get();
	}

	return utf8;
}

auto toLowerCase(string str) -> string {
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
};

auto replaceByRef(string &str, const string &search, const string &replacement) -> void {
	if (search.empty()) {
		return;
	}

	const auto searchLength  = search.length();
	const auto replaceLength = replacement.length();

	string::size_type pos = 0;

	while ((pos = str.find(search, pos)) != string::npos) {
		str.replace(pos, searchLength, replacement);
		pos += replaceLength;
	}
}

auto replace(string str, const string &search, const string &replacement) -> string {
	replaceByRef(str, search, replacement);
	return str;
}

auto replace(const string &str, const string &search, char replacement) -> string {
	return replace(str, search, string(1, replacement));
}

auto replace(const string &s, char search, char replacement) -> string {
	return replace(s, string(1, search), string(1, replacement));
}

auto replaceOnce(const string &s, char search, const string &replacement) -> string {
	auto pos = s.find(search);

	if (string::npos == pos) {
		return s;
	}

	return s.substr(0, pos) + replacement + s.substr(pos + 1);
}

auto replaceOnce(const string &s, const string &search, const string &replacement) -> string {
	auto pos = s.find(search);

	if (string::npos == pos) {
		return s;
	}

	return s.substr(0, pos) + replacement + s.substr(pos + search.size());
}

auto unifyLineFeeds(string text) -> string {
	text = replace(text, "\r\n", '\n');
	text = replace(text, '\r', '\n');

	return text;
}

auto trimByRef(string &s, const string &chars) -> void {
	string::size_type pos = s.find_last_not_of(chars);

	if (pos != string::npos) {
		s.erase(pos + 1);
		pos = s.find_first_not_of(chars);

		if (pos != string::npos) {
			s.erase(0, pos);
		}
	}
	else {
		s.erase(s.begin(), s.end());
	}
}

auto trim(string s, const string &chars) -> string {
	trimByRef(s, chars);
	return s;
}

auto trim(const string &s) -> string {
	return trim(s, " \t\r\n");
}

auto isWhiteSpace(const string &s) -> bool {
	return "" == trim(s);
}

auto ucharVectorToString(const vector<unsigned char> &data) -> string {
	string dataString;

	for (auto &byte : data) {
		dataString += byte;
	}

	return dataString;
}

auto split(string s, const string &delim) -> vector<string> {
	s += delim;
	vector<string> elems;
	string::size_type delimLen = delim.length();
	string::size_type pos = 0;
	string elem;

	while ((pos = s.find(delim)) != string::npos) {
		elem = s.substr(0, pos);
		elems.push_back(elem);
		s.erase(0, pos + delimLen);
	}

	return elems;
}

auto join(const vector<string> &v, const string &delim) -> string {
	std::stringstream ss;
	vector<string>::size_type count = v.size();

	for (vector<string>::size_type i = 0; i < count; i++) {
		if (i != 0) {
			ss << delim;
		}

		ss << v[i];
	}

	return ss.str();
}

} // namespace bsnesMt::strings