/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

#include <cstdint>

#include "integer-scaling/IntegerScaling.h"

namespace bsnesMt::scaling {

using is = MaratTanalin::IntegerScaling;

auto getWidth(bool aspectCorrection) -> uint32_t;
auto getWidth(bool aspectCorrection, uint32_t width) -> uint32_t;

auto getHeight(bool showOverscan, uint32_t height) -> uint32_t;

auto getAspectY(bool showOverscan) -> double;
auto getParAspect(bool showOverscan) -> double;

auto getHeightForPar1(uint32_t width, uint32_t height) -> uint32_t;

auto calculateScaledSizeScale(
	uint32_t areaWidth, uint32_t areaHeight,
	bool aspectCorrection, bool showOverscan,
	bool parInsteadOfAr
) -> is::Size;

auto calculateScaledSizeCenter(
	uint32_t areaWidth,  uint32_t areaHeight,
	uint32_t imageWidth, uint32_t imageHeight,
	bool aspectCorrection, bool showOverscan,
	bool parInsteadOfAr
) -> is::Size;

auto calculateScaledSizePerfect(
	uint32_t areaWidth,  uint32_t areaHeight,
	uint32_t imageWidth, uint32_t imageHeight,
	bool aspectCorrection, bool showOverscan,
	bool parInsteadOfAr
) -> is::Size;

} // namespace bsnesMt::scaling