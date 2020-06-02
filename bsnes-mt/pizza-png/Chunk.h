/*! PizzaPNG by Marat Tanalin | http://tanalin.com/en/projects/pizza-png/ */

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace MaratTanalin::PizzaPNG {

using std::string, std::vector;

class Chunk {
protected:
	auto init(const string &fileData, const uint32_t offset = 0) -> void;
	auto getFourBytesAsNumber(const string &bytes, uint32_t offset = 0) -> uint32_t;
	auto toString() const -> string;

public:
	string length, type, data, hash;

	Chunk(const string &fileData, const uint32_t offset = 0);

	auto size() -> uint32_t;
	auto isCritical() -> bool;
	auto isHeader() -> bool;
	auto isEnd() -> bool;

	operator string() const {
		return toString();
	}
};

} // namespace MaratTanalin::PizzaPNG