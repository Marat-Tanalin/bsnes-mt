/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#include <stdexcept>

#include <windows.h>

#include "utils.h"

#include "strings.h"

namespace bsnesMt::strings {

using std::wstring, std::out_of_range;

auto getLocale() -> uint8_t {
	wstring commandLine = GetCommandLineW();
	wstring paramStart  = L"--locale=";
	auto    paramPos    = commandLine.find(paramStart);

	if (string::npos != paramPos) {
		wstring value = commandLine.substr(paramPos + paramStart.size(), 2);

		if (L"ru" == value) {
			return RU;
		}
		else if (L"jp" == value) {
			return JP;
		}
		else if (L"en" == value) {
			return EN;
		}
	}

	auto lang = getUiLang();

	uint8_t locale;

	if (LANG_RUSSIAN == lang) {
		locale = RU;
	}
	else if (LANG_JAPANESE == lang) {
		locale = JP;
	}
	else {
		locale = EN;
	}

	return locale;
}

auto genericHas(const map<string, map<uint8_t, string>> &strings, const string &name) -> bool {
	try {
		auto test = strings.at(name);
	}
	catch (const out_of_range &e) {
		return false;
	}

	return true;
}

auto has(const string &name) -> bool {
	return genericHas(strings, name);
}

auto valueHasLocale(const map<uint8_t, string> &value, uint8_t locale) -> bool {
	try {
		auto test = value.at(locale);
	}
	catch (const out_of_range &e) {
		return false;
	}

	return true;
}

auto get(const map<uint8_t, string> &value) -> string {
	if (valueHasLocale(value, locale)) {
		return value.at(locale);
	}

	return valueHasLocale(value, EN) ? value.at(EN) : "";
}

auto get(const string &name) -> string {
	return has(name) ? get(strings.at(name)) : "";
}

auto hasDeviceString(const string &name) -> bool {
	return genericHas(deviceStrings, name);
}

auto getDeviceString(const string &name) -> string {
	if (hasDeviceString(name)) {
		return get(deviceStrings.at(name));
	}

	return "None" == name ? get("Common.None") : "";	
}

auto hasHotkeyString(const string &name) -> bool {
	return genericHas(hotkeyStrings, name);
}

auto getHotkeyString(const string &name) -> string {
	return hasHotkeyString(name) ? get(hotkeyStrings.at(name)) : "";
}

} // namespace bsnesMt::strings