/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#include <filesystem>
#include <fstream>
#include <sstream>

#include <Windows.h>

#include "pizza-png/src/Image.h"

#include "app.h"
#include "strings.h"

#include "files.h"

namespace bsnesMt::files {

auto fileExists(const string &name) -> bool {
	return std::filesystem::exists(strings::utf8ToWideString(name).data());
}

auto getTextFileContents(const string &name) -> string {
	std::ifstream in(name);
	std::stringstream ss;
	ss << in.rdbuf();
	string s = ss.str();

	if (s.size() > 2 && (char)239 == s[0] && (char)187 == s[1] && (char)191 == s[2]) {
		s.erase(0, 3);
	}

	return s;
}

auto saveFile(const string &data, const string &path) -> bool {
	HANDLE handle = CreateFileW(strings::utf8ToWideString(path).data(), GENERIC_WRITE, 0,
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

	image.insertChunk(strings::ucharVectorToString(app::pngInfo));

	return saveFile(image, path);
}

} // namespace bsnesMt::files