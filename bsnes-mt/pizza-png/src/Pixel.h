/*! PizzaPNG by Marat Tanalin | http://tanalin.com/en/projects/pizza-png/ */

#pragma once

#include <cstdint>

namespace MaratTanalin::PizzaPNG {

class Pixel {
public:
	uint8_t r, g, b, a;

	Pixel(uint8_t aR, uint8_t aG, uint8_t aB, uint8_t aA = 255);
};

} // namespace MaratTanalin::PizzaPNG