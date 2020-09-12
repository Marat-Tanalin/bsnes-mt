/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#include <memory>

#include "pizza-png/src/Image.h"

#include "app.h"
#include "windows.h"

#include "utils.h"

namespace bsnesMt {

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

auto getTime() -> SYSTEMTIME {
	SYSTEMTIME time;
	GetLocalTime(&time);
	return time;
}

auto open(const wstring &path) -> void {
	ShellExecuteW(NULL, L"open", path.data(), NULL, NULL, SW_SHOWNORMAL);
}

auto open(const string &path) -> void {
	open(utf8ToWideString(path));
}

auto saveFile(const string &data, const string &path) -> bool {
	HANDLE handle = CreateFileW(utf8ToWideString(path).data(), GENERIC_WRITE, 0,
		                        NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == handle) {
		return false;
	}

	DWORD bytesToWrite = data.size();
	DWORD bytesWritten = 0;
	BOOL  errorFlag    = WriteFile(handle, data.data(), bytesToWrite, &bytesWritten, NULL);

	if (FALSE == errorFlag || bytesWritten != bytesToWrite) {
		return false;
	}

	CloseHandle(handle);

	return true;
}

auto saveBgraArrayAsPngImage(uint8_t* data, uint16_t width, uint16_t height, const string &path) -> bool {
	MaratTanalin::PizzaPNG::Image image(width, height);

	size_t pixelCount = width * height;

	for (size_t i = 0; i < pixelCount; i++) {
		size_t blueIndex = i << 2;
		image.addPixel(data[blueIndex + 2], data[blueIndex + 1], data[blueIndex]);
	}

	image.insertChunk(ucharVectorToString(app::pngInfo));

	return saveFile(image, path);
}

auto ucharVectorToString(const vector<unsigned char> &data) -> string {
	string dataString;

	for (auto &byte : data) {
		dataString += byte;
	}

	return dataString;
}

auto getUiLang() -> BYTE {
	return LOBYTE(GetUserDefaultUILanguage());
}

auto replace(const string &s, char search, const string replace) -> string {
	auto pos = s.find(search);

	if (string::npos == pos) {
		return s;
	}

	return s.substr(0, pos) + replace + s.substr(pos + 1);
}

} // namespace bsnesMt