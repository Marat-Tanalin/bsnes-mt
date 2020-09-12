/*! PizzaPNG by Marat Tanalin | http://tanalin.com/en/projects/pizza-png/ */

#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "Chunk.h"
#include "Pixel.h"

namespace MaratTanalin::PizzaPNG {

using std::string, std::vector;

class Image {
public:
	Image(uint16_t aWidth, uint16_t aHeight);

	auto getWidth()  -> uint16_t;
	auto getHeight() -> uint16_t;

	auto isTransparent() -> bool;

	auto addPixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) -> void;
	auto getPixel(uint32_t index) const -> Pixel;

	auto insertChunk(const Chunk  &chunk) -> void;
	auto insertChunk(const string &chunk) -> void;

	operator string() {
		return toString();
	}

protected:
	uint16_t width, height;
	bool transparent = false;
	vector<Pixel> pixels;
	string signature, header, end;
	vector<Chunk> chunks, extraChunks;
	vector<string> extraBinaryChunks;

	auto addChunk(const Chunk &chunk) -> void;
	auto toPngString() -> string;
	auto toString() -> string;
	auto commit() -> void;
	auto getPixel(uint16_t x, uint16_t y) const -> Pixel;
};

} // namespace MaratTanalin::PizzaPNG