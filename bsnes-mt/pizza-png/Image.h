/*! PizzaPNG by Marat Tanalin | http://tanalin.com/en/projects/pizza-png/ */

#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include <Windows.h>
#include <gdiplus.h>

#include "Chunk.h"

#pragma comment(lib, "gdiplus.lib")

namespace MaratTanalin::PizzaPNG {

using Gdiplus::Bitmap, Gdiplus::Color;
using std::string, std::wstring, std::vector;

class Image {
protected:
	uint16_t width, height;
	bool transparent = false;
	vector<Color> pixels;
	string signature, header, end;
	vector<Chunk> chunks, extraChunks;
	vector<string> extraBinaryChunks;

	auto addChunk(const Chunk &chunk) -> void;
	auto getImageEncoderId(const wstring &type) const -> CLSID;
	auto toBitmap(Bitmap* &bitmap) -> void;
	auto bitmapToPngStream(Bitmap* &bitmap, IStream* &stream) -> void;
	auto toPngStream(IStream* &stream) -> void;
	auto getStreamSize(IStream* &stream) -> ULONG;
	auto streamToString(IStream* &stream) -> string;
	auto toPngString() -> string;
	auto toString() -> string;
	auto commit() -> void;
	auto getPixel(uint16_t x, uint16_t y) const -> Color;
	auto getPixel(uint32_t index) const -> Color;

public:
	Image(uint16_t width, uint16_t height);

	auto addPixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) -> void;

	auto insertChunk(const Chunk  &chunk) -> void;
	auto insertChunk(const string &chunk) -> void;

	operator string() {
		return toString();
	}
};

} // namespace MaratTanalin::PizzaPNG