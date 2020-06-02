/*! IntegerScaling by Marat Tanalin | http://tanalin.com/en/projects/integer-scaling/ */

#include <cmath>

#include "IntegerScaling.h"

namespace MaratTanalin {

	/**
	 * Calculates an integer scaling ratio common for X/Y axes (square pixels).
	 */
	auto IntegerScaling::calculateRatio(uint32_t areaWidth, uint32_t areaHeight,
		uint32_t imageWidth, uint32_t imageHeight) -> uint32_t
	{
		uint32_t areaSize, imageSize;

		if (areaHeight * imageWidth < areaWidth * imageHeight) {
			areaSize  = areaHeight;
			imageSize = imageHeight;
		}
		else {
			areaSize  = areaWidth;
			imageSize = imageWidth;
		}

		uint32_t ratio = areaSize / imageSize;

		if (ratio < 1) {
			ratio = 1;
		}

		return ratio;
	}

	/**
	 * Calculates integer scaling ratios potentially different for X/Y axes
	 * as a result of aspect-ratio correction (rectangular pixels).
	 */
	auto IntegerScaling::calculateRatios(uint32_t areaWidth, uint32_t areaHeight, 
		uint32_t imageWidth, uint32_t imageHeight,
		double aspectX, double aspectY) -> Ratios
	{
		if (imageWidth * aspectY == imageHeight * aspectX) {
			auto ratio = calculateRatio(areaWidth, areaHeight, imageWidth, imageHeight);
			return {ratio, ratio};
		}

		uint32_t maxRatioX = areaWidth  / imageWidth,
		         maxRatioY = areaHeight / imageHeight,
		         maxWidth  = imageWidth  * maxRatioX,
		         maxHeight = imageHeight * maxRatioY;

		double maxWidthAspectY  = maxWidth  * aspectY,
		       maxHeightAspectX = maxHeight * aspectX;

		uint32_t ratioX, ratioY;

		if (maxWidthAspectY == maxHeightAspectX) {
			ratioX = maxRatioX;
			ratioY = maxRatioY;
		}
		else {
			bool maxAspectLessThanTarget = maxWidthAspectY < maxHeightAspectX;

			uint32_t ratioA, maxSizeA, imageSizeB;
			double aspectA, aspectB;

			if (maxAspectLessThanTarget) {
				ratioA     = maxRatioX;
				maxSizeA   = maxWidth;
				imageSizeB = imageHeight;
				aspectA    = aspectX;
				aspectB    = aspectY;
			}
			else {
				ratioA     = maxRatioY;
				maxSizeA   = maxHeight;
				imageSizeB = imageWidth;
				aspectA    = aspectY;
				aspectB    = aspectX;
			}

			double ratioBFract = maxSizeA * aspectB / aspectA / imageSizeB,
			       ratioBFloor = std::floor(ratioBFract),
			       ratioBCeil  = std::ceil(ratioBFract),
			       parFloor    = ratioBFloor / ratioA,
			       parCeil     = ratioBCeil  / ratioA;

			if (maxAspectLessThanTarget) {
				parFloor = 1.0 / parFloor;
				parCeil  = 1.0 / parCeil;
			}

			double commonFactor = imageWidth * aspectY / aspectX / imageHeight,
			       errorFloor   = std::abs(1.0 - commonFactor * parFloor),
			       errorCeil    = std::abs(1.0 - commonFactor * parCeil);

			uint32_t ratioB;

			if (std::abs(errorFloor - errorCeil) < .001) {
				ratioB = std::abs(ratioA - ratioBFloor) < std::abs(ratioA - ratioBCeil)
				       ? ratioBFloor
				       : ratioBCeil;
			}
			else {
				ratioB = errorFloor < errorCeil
				       ? ratioBFloor
				       : ratioBCeil;
			}

			if (maxAspectLessThanTarget) {
				ratioX = ratioA;
				ratioY = ratioB;
			}
			else {
				ratioX = ratioB;
				ratioY = ratioA;
			}
		}

		if (ratioX < 1) {
			ratioX = 1;
		}

		if (ratioY < 1) {
			ratioY = 1;
		}

		return {
			ratioX,
			ratioY
		};
	}

	/**
	 * Calculates size (width and height) of scaled image
	 * without aspect-ratio correction (square pixels).
	 */
	auto IntegerScaling::calculateSize(uint32_t areaWidth, uint32_t areaHeight,
		uint32_t imageWidth, uint32_t imageHeight) -> Size
	{
		uint32_t ratio = calculateRatio(areaWidth, areaHeight, imageWidth, imageHeight);

		return {
			imageWidth  * ratio,
			imageHeight * ratio
		};
	}

	/**
	 * Calculates size (width and height) of scaled image
	 * with aspect-ratio correction (rectangular pixels).
	 */
	auto IntegerScaling::calculateSizeCorrected(uint32_t areaWidth, uint32_t areaHeight,
		uint32_t imageWidth, uint32_t imageHeight,
		double aspectX, double aspectY) -> Size
	{
		auto ratios = calculateRatios(areaWidth, areaHeight, imageWidth, imageHeight, aspectX, aspectY);

		return {
			imageWidth  * ratios.x,
			imageHeight * ratios.y
		};
	}

	/**
	 * Calculates size (width and height) of scaled image with aspect-ratio
	 * correction with integer vertical scaling ratio, but fractional horizontal
	 * scaling ratio for the purpose of achieving precise aspect ratio while
	 * still having integer vertical scaling e.g. for uniform scanlines.
	 */
	auto IntegerScaling::calculateSizeCorrectedPerfectY(
		uint32_t areaWidth,  uint32_t areaHeight,
		uint32_t imageHeight,
		double aspectX, double aspectY) -> Size
	{
		double imageWidth = imageHeight * aspectX / aspectY;
		double imageSize;
		uint32_t areaSize;

		if (areaHeight * imageWidth < (double)areaWidth * imageHeight) {
			areaSize  = areaHeight;
			imageSize = imageHeight;
		}
		else {
			areaSize  = areaWidth;
			imageSize = imageWidth;
		}

		uint32_t ratio = areaSize / imageSize;

		if (ratio < 1) {
			ratio = 1;
		}

		uint32_t width = std::round(imageWidth * ratio);

		if (width > areaWidth) {
			width--;
		}

		return {width, imageHeight * ratio};
	}
}