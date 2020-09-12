/*! PizzaPNG by Marat Tanalin | http://tanalin.com/en/projects/pizza-png/ */

#include <cstdint>

#include "Pixel.h"

namespace MaratTanalin::PizzaPNG {

Pixel::Pixel(uint8_t aR, uint8_t aG, uint8_t aB, uint8_t aA) {
	r = aR;
	g = aG;
	b = aB;
	a = aA;
}

} // namespace MaratTanalin::PizzaPNG