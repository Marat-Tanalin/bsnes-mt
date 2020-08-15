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
		else if (L"it" == value) {
			return IT;
		}
		else if (L"ja" == value || L"jp" == value) { // `jp` for backward compatibility.
			return JA;
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
	else if (LANG_ITALIAN == lang) {
		locale = IT;
	}
	else if (LANG_JAPANESE == lang) {
		locale = JA;
	}
	else {
		locale = EN;
	}

	return locale;
}

auto genericHas(const map<string, map<uint8_t, string>> &items, const string &key) -> bool {
	try {
		auto test = items.at(key);
	}
	catch (const out_of_range &e) {
		return false;
	}

	return true;
}

auto genericHas(const map<string, string> &items, const string &key) -> bool {
	try {
		auto test = items.at(key);
	}
	catch (const out_of_range &e) {
		return false;
	}

	return true;
}

auto has(const string &id) -> bool {
	return genericHas(strings, id);
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

auto get(const string &id) -> string {
	return has(id) ? get(strings.at(id)) : "";
}

auto getStringOrId(const map<string, map<uint8_t, string>> &values, const string &id) -> string {
	auto value = values.at(id);

	if (valueHasLocale(value, locale)) {
		return value.at(locale);
	}

	return valueHasLocale(value, EN) ? value.at(EN) : id;
}

auto getDedicatedString(
	const map<string, map<uint8_t, string>> &values,
	const map<string, string> &dedicatedToRegularStrings,
	const string &id
) -> string
{
	if (genericHas(values, id)) {
		return getStringOrId(values, id);
	}

	return genericHas(dedicatedToRegularStrings, id)
	     ? get(dedicatedToRegularStrings.at(id))
	     : id;
}

auto getDeviceString(const string &id) -> string {
	return getDedicatedString(deviceStrings, deviceStringsToRegularStrings, id);
}

auto getHotkeyString(const string &id) -> string {
	return getDedicatedString(hotkeyStrings, hotkeyStringsToRegularStrings, id);
}

} // namespace bsnesMt::strings