/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

#include <cstdint>
#include <utility>

namespace bsnesMt::scaling {

using std::pair;

static const uint32_t origWidth      = 256,
                      origHeight     = 224,
                      origOverHeight = 240;

static const double defaultAspectX = 4.0,
                    defaultAspectY = 3.0;

auto getWidth(bool aspectCorrection) -> uint32_t;
auto getHeight(bool showOverscan)    -> uint32_t;

auto getAspectYOverscanRatio() -> double;
auto getAspectY(bool showOverscan) -> double;

auto calculateScaledSizeScale(
	uint32_t areaWidth, uint32_t areaHeight,
	bool aspectCorrection, bool showOverscan
) -> pair<uint32_t, uint32_t>;

auto calculateScaledSizeCenter(
	uint32_t areaWidth,  uint32_t areaHeight,
	uint32_t imageWidth, uint32_t imageHeight,
	bool aspectCorrection, bool showOverscan
) -> pair<uint32_t, uint32_t>;

auto calculateScaledSizePerfect(
	uint32_t areaWidth, uint32_t areaHeight,
	uint32_t imageHeight,
	bool aspectCorrection, bool showOverscan
) -> pair<uint32_t, uint32_t>;

} // namespace bsnesMt::scaling