/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#include <cmath>

#include "integer-scaling/IntegerScaling.h"

#include "scaling.h"

using namespace MaratTanalin;

namespace bsnesMt::scaling {

auto getWidth(bool aspectCorrection) -> uint32_t {
	return aspectCorrection ? std::round(origHeight * defaultAspectX / defaultAspectY) : origWidth;
}

auto getHeight(bool showOverscan) -> uint32_t {
	return showOverscan ? origOverHeight : origHeight;
}

auto getAspectYOverscanRatio() -> double {
	return (double)origOverHeight / origHeight;
}

auto getAspectY(bool showOverscan) -> double {
	double aspectY = defaultAspectY;

	if (showOverscan) {
		aspectY *= getAspectYOverscanRatio();
	}

	return aspectY;
}

auto calculateScaledSizeScale(
	uint32_t areaWidth, uint32_t areaHeight,
	bool aspectCorrection, bool showOverscan
) -> pair<uint32_t, uint32_t>
{
	double aspect = aspectCorrection
	              ? defaultAspectX / defaultAspectY
	              : (double)origWidth / origHeight;

	if (showOverscan) {
		aspect *= (double)origHeight / origOverHeight;
	}

	uint32_t width, height;

	if (aspect < (double)areaWidth / areaHeight) {
		height = areaHeight;
		width  = std::round(areaHeight * aspect);

		if (width > areaWidth) {
			width--;
		}
	}
	else {
		width  = areaWidth;
		height = std::round(areaWidth / aspect);

		if (height > areaHeight) {
			height--;
		}
	}

	return make_pair(width, height);
}

auto calculateScaledSizeCenter(
	uint32_t areaWidth,  uint32_t areaHeight,
	uint32_t imageWidth, uint32_t imageHeight,
	bool aspectCorrection, bool showOverscan
) -> pair<uint32_t, uint32_t>
{
	auto size = aspectCorrection
		? IntegerScaling::calculateSizeCorrectedPerfectY(
			areaWidth,  areaHeight,
			imageHeight,
			defaultAspectX, getAspectY(showOverscan)
		)
		: IntegerScaling::calculateSize(areaWidth, areaHeight, imageWidth, imageHeight);

	return make_pair(size.width, size.height);
}

auto calculateScaledSizePerfect(
	uint32_t areaWidth, uint32_t areaHeight,
	uint32_t imageHeight,
	bool aspectCorrection, bool showOverscan
) -> pair<uint32_t, uint32_t>
{
	auto size = aspectCorrection
		? IntegerScaling::calculateSizeCorrected(
			areaWidth, areaHeight,
			origWidth, imageHeight,
			defaultAspectX, getAspectY(showOverscan)
		)
		: IntegerScaling::calculateSize(areaWidth, areaHeight, origWidth, imageHeight);

	return make_pair(size.width, size.height);
}

} // namespace bsnesMt::scaling