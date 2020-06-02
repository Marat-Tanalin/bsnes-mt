/*! IntegerScaling by Marat Tanalin | http://tanalin.com/en/projects/integer-scaling/ */

#pragma once

#include <cstdint>

namespace MaratTanalin {

	class IntegerScaling
	{
	public:
		struct Ratios {
			uint32_t x, y;
		};

		struct Size {
			uint32_t width, height;
		};

		static auto calculateRatio(uint32_t areaWidth, uint32_t areaHeight,
			uint32_t imageWidth, uint32_t imageHeight) -> uint32_t;

		static auto calculateRatios(uint32_t areaWidth, uint32_t areaHeight,
			uint32_t imageWidth, uint32_t imageHeight,
			double aspectX, double aspectY) -> Ratios;

		static auto calculateSize(uint32_t areaWidth, uint32_t areaHeight,
			uint32_t imageWidth, uint32_t imageHeight) -> Size;

		static auto calculateSizeCorrected(uint32_t areaWidth, uint32_t areaHeight,
			uint32_t imageWidth, uint32_t imageHeight,
			double aspectX, double aspectY) -> Size;

		static auto calculateSizeCorrectedPerfectY(
			uint32_t areaWidth,  uint32_t areaHeight,
			uint32_t imageHeight,
			double aspectX, double aspectY) -> Size;
	};

}