/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#include <cmath>

#include "scaling.h"

namespace bsnesMt::scaling {

static constexpr uint32_t origWidth            = 256,
                          origHeight           = 224,
                          origOverHeight       = 240,
                          origDoubleHeight     = origHeight     << 1, // 448
                          origDoubleOverHeight = origOverHeight << 1; // 480

static constexpr double overscanRatio = (double)origOverHeight / origHeight;

static constexpr double defaultAspectX = 4.0,
                        defaultAspectY = 3.0,
                        defaultAspect  = defaultAspectX / defaultAspectY;

static constexpr double par           = 8.0 / 7.0,
                        parAspect     = par * origWidth / origHeight,
                        parOverAspect = par * origWidth / origOverHeight;

auto getWidth(bool aspectCorrection) -> uint32_t {
	return aspectCorrection ? std::round(origHeight * defaultAspect) : origWidth;
}

auto getWidth(bool aspectCorrection, uint32_t width) -> uint32_t {
	return aspectCorrection ? std::round(origHeight * (width / origWidth) * defaultAspect) : width;
}

auto getHeight(bool showOverscan, uint32_t height) -> uint32_t {
	return showOverscan ? std::round(height * overscanRatio) : height;
}

auto getAspectY(bool showOverscan) -> double {
	return showOverscan ? defaultAspectY * overscanRatio : defaultAspectY;
}

auto getParAspect(bool showOverscan) -> double {
	return showOverscan ? parOverAspect : parAspect;
}

auto getHeightForPar1(uint32_t width, uint32_t height) -> uint32_t {
	return (height == origHeight || height == origOverHeight)
	     ? (width == origWidth ? origHeight : origDoubleHeight)
	     : origDoubleHeight;
}

auto calculateScaledSizeScale(
	uint32_t areaWidth, uint32_t areaHeight,
	bool aspectCorrection, bool showOverscan,
	bool parInsteadOfAr
) -> is::Size
{
	double aspect = aspectCorrection
	              ? (parInsteadOfAr ? parAspect : defaultAspect)
	              : (double)origWidth / origHeight;

	if (showOverscan) {
		aspect /= overscanRatio;
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

	return {width, height};
}

auto calculateScaledSizeCenter(
	uint32_t areaWidth,  uint32_t areaHeight,
	uint32_t imageWidth, uint32_t imageHeight,
	bool aspectCorrection, bool showOverscan,
	bool parInsteadOfAr
) -> is::Size
{
	if (!aspectCorrection) {
		return is::calculateSize(
			areaWidth, areaHeight,
			imageWidth, getHeightForPar1(imageWidth, imageHeight)
		);
	}

	double aspectX, aspectY;

	if (parInsteadOfAr) {
		aspectX = getParAspect(showOverscan);
		aspectY = 1.0;
	}
	else {
		aspectX = defaultAspectX;
		aspectY = getAspectY(showOverscan);
	}

	return is::calculateSizeCorrectedPerfectY(
		areaWidth, areaHeight,
		imageHeight,
		aspectX, aspectY
	);
}

auto calculateScaledSizePerfect(
	uint32_t areaWidth,  uint32_t areaHeight,
	uint32_t imageWidth, uint32_t imageHeight,
	bool aspectCorrection, bool showOverscan,
	bool parInsteadOfAr
) -> is::Size
{
	if (!aspectCorrection) {
		uint32_t imageHeightForPar1     = getHeightForPar1(imageWidth, imageHeight);
		uint32_t imageOverHeightForPar1 = imageHeightForPar1 == origHeight ? origOverHeight : origDoubleOverHeight;	

		return is::calculateSize(
			areaWidth, areaHeight,
			imageWidth,
			showOverscan ? imageOverHeightForPar1 : imageHeightForPar1
		);
	}

	double aspectX, aspectY;

	if (parInsteadOfAr) {
		aspectX = getParAspect(showOverscan);
		aspectY = 1.0;
	}
	else {
		aspectX = defaultAspectX;
		aspectY = getAspectY(showOverscan);
	}

	return is::calculateSizeCorrected(
		areaWidth,  areaHeight,
		imageWidth, imageHeight,
		aspectX, aspectY
	);
};

} // namespace bsnesMt::scaling