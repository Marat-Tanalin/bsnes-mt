/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#include <stdexcept>
#include <vector>

#include <Windows.h>

#include <target-bsnes/resource/resources.h>

#include "files.h"
#include "strings.h"

#include "translations.h"

namespace bsnesMt::translations {

using std::wstring, std::vector, std::out_of_range;
using namespace strings;

string locale;

auto getSystemLocale() -> string {
	wchar_t buffer[LOCALE_NAME_MAX_LENGTH];

	auto length = GetUserDefaultLocaleName(buffer, LOCALE_NAME_MAX_LENGTH);
	auto locale = toLowerCase(wideStringToUtf8String(wstring(buffer).substr(0, length - (size_t)1)));

	return locale;
}

auto getShortSystemLocale() -> string {
	auto locale = getSystemLocale();
	auto sepPos = locale.find('-');

	return string::npos == sepPos ? locale : locale.substr(0, sepPos);
}

auto getFileDataFromResource(int name, int type, DWORD &size, const char* &data) -> void {
	HMODULE handle = GetModuleHandle(NULL);
	HRSRC   rc     = FindResource(handle, MAKEINTRESOURCE(name), MAKEINTRESOURCE(type));
	HGLOBAL rcData = LoadResource(handle, rc);

	size = SizeofResource(handle, rc);
	data = static_cast<const char*>(LockResource(rcData));
}

auto parseTranslation(const string &code, map<string, string> &strings) -> void {
	auto size   = code.size();
	auto idPos  = 0;
	auto sepPos = code.find('=');
	char quote  = '"';

	while (true) {
		if (string::npos == sepPos) {
			break;
		}

		auto id = trim(code.substr(idPos, sepPos - idPos));

		if (isWhiteSpace(id)) {
			break;
		}

		auto afterSepPos   = sepPos + 1;
		auto startQuotePos = code.find(quote, afterSepPos);

		if (string::npos == startQuotePos || !isWhiteSpace(code.substr(afterSepPos, startQuotePos - afterSepPos))) {
			break;
		}

		auto afterStartQuotePos = startQuotePos + 1;
		auto endQuotePos        = code.find(quote, afterStartQuotePos);

		if (string::npos == endQuotePos) {
			break;
		}

		auto value = trim(code.substr(afterStartQuotePos, endQuotePos - afterStartQuotePos));

		if ("" != value) {
			strings[id] = value;
		}

		auto afterEndQuotePos = endQuotePos + 1;
		idPos = code.find('\n', afterEndQuotePos);

		if (string::npos == idPos || !isWhiteSpace(code.substr(afterEndQuotePos, idPos - afterEndQuotePos))) {
			break;
		}

		sepPos = code.find('=', idPos);
	}
}

auto getLocalePath(const string &locale) -> string {
	static string folder    = "translations/",
	              extension = ".txt";

	return folder + locale + extension;
}

auto localeFileExists(const string &locale) -> bool {
	return files::fileExists(getLocalePath(locale));
}

auto getAvailableLocaleSlice(const string &locale) -> string {
	if (localeFileExists(locale)) {
		return locale;
	}

	auto parts = strings::split(locale, "-");
	auto count = parts.size();

	for (auto i = 1; i < count; i++) {
		auto curLocale = join(vector<string>(parts.begin(), parts.end() - i), "-");

		if (localeFileExists(curLocale)) {
			return curLocale;
		}
	}

	return "";
}

auto initInternalStrings() -> void {
	DWORD size = 0;
	const char* data = NULL;
	string code;
	
	getFileDataFromResource(IDR_EN_STRINGS, TEXTFILE, size, data);
	code.assign(data, size);
	parseTranslation(code, strings);
}

auto getCommandLineLocale() -> string {
	string commandLine = wideStringToUtf8String(GetCommandLineW());
	auto   params      = split(commandLine, " ");
	string paramStart  = "--locale=";
	auto   valuePos    = paramStart.size();

	for (auto &param : params) {
		if (param.substr(0, valuePos) == paramStart) {
			string locale = param.substr(valuePos);
			return "jp" == locale ? "ja" : locale;
		}
	}

	return "";
}

auto initLocale() -> void {
	initInternalStrings();

	auto commandLineLocale = getCommandLineLocale();
	auto curLocale = getAvailableLocaleSlice(commandLineLocale);

	if ("" == curLocale) {
		if ("en" == commandLineLocale) {
			locale = commandLineLocale;
			return;
		}

		curLocale = getAvailableLocaleSlice(getSystemLocale());
	}

	if ("" == curLocale) {
		curLocale = getShortSystemLocale();
	}
	else {
		auto path = getLocalePath(curLocale);
		auto code = files::getTextFileContents(path);
		parseTranslation(code, strings);
	}

	locale = curLocale;
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

auto get(const map<string, string> &value) -> string {
	if (genericHas(value, locale)) {
		return value.at(locale);
	}

	return genericHas(value, "en") ? value.at("en") : "";
}

auto get(const string &id) -> string {
	return has(id) ? strings.at(id) : "";
}

auto getDedicatedStringId(const map<string, string> &dedicatedStrings, const string &id) -> string {
	return genericHas(dedicatedStrings, id)
	     ? dedicatedStrings.at(id)
	     : id;
}

auto getDeviceString(const string &id) -> string {
	auto regularId = getDedicatedStringId(deviceStrings, id);
	return has(regularId) ? get(regularId) : id;
}

auto getHotkeyString(const string &id) -> string {
	auto regularId = getDedicatedStringId(hotkeyStrings, id);
	return has(regularId) ? get(regularId) : id;
}

} // namespace bsnesMt::translations