/*! PizzaPNG by Marat Tanalin | http://tanalin.com/en/projects/pizza-png/ */

#include "Chunk.h"

namespace MaratTanalin::PizzaPNG {

Chunk::Chunk(const string &fileData, const uint32_t offset) {
	init(fileData, offset);
}

auto Chunk::init(const string &fileData, const uint32_t offset) -> void {
	length = fileData.substr(offset, 4);

	uint32_t lengthNumber = getFourBytesAsNumber(length);

	type = fileData.substr(4 + offset, 4);
	data = lengthNumber ? fileData.substr(8 + offset, lengthNumber) : "";
	hash = fileData.substr(8 + offset + lengthNumber, 4);
}

auto Chunk::size() -> uint32_t {
	return data.size() + 12;
}

auto Chunk::isCritical() -> bool {
	return isHeader() || isEnd() || type == "PLTE" || type == "IDAT";
}

auto Chunk::isHeader() -> bool {
	return type == "IHDR";
}

auto Chunk::isEnd() -> bool {
	return type == "IEND";
}

auto Chunk::toString() const -> string {
	return length + type + data + hash;
}

auto Chunk::getFourBytesAsNumber(const string &bytes, uint32_t offset) -> uint32_t {
	return ((uint8_t)bytes[offset]     << 24) |
	       ((uint8_t)bytes[offset + 1] << 16) |
	       ((uint8_t)bytes[offset + 2] << 8)  |
	       ((uint8_t)bytes[offset + 3]);
};

} // namespace MaratTanalin::PizzaPNG