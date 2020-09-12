/*! PizzaPNG by Marat Tanalin | http://tanalin.com/en/projects/pizza-png/ */

#include <memory>

#include <Windows.h>
#include <gdiplus.h>

#include "Image.h"

#pragma comment(lib, "gdiplus.lib")

namespace MaratTanalin::PizzaPNG {

using std::make_unique, std::wstring;
using Gdiplus::Bitmap, Gdiplus::Color;

inline auto getImageEncoderId(const wstring &type) -> CLSID {
	UINT count = 0,
	     size  = 0;

	Gdiplus::GetImageEncodersSize(&count, &size);

	if (size == 0) {
		return {};
	}

	auto info = make_unique<Gdiplus::ImageCodecInfo[]>(size);

	if (info == NULL) {
		return {};
	}

	Gdiplus::GetImageEncoders(count, size, info.get());

	wstring mime = L"image/" + type;

	for (size_t i = 0; i < count; i++) {
		auto infoItem = info[i];

		if (wstring(infoItem.MimeType) == mime) {
			return infoItem.Clsid;
		}
	}

	return {};
}

inline auto bitmapToPngStream(Bitmap* &bitmap, IStream* &stream) -> void {
	CLSID id = getImageEncoderId(L"png");
	CreateStreamOnHGlobal(NULL, true, &stream);
	bitmap->Save(stream, &id, NULL);
}

inline auto getStreamSize(IStream* &stream) -> ULONG {
	STATSTG stat;
	stream->Stat(&stat, STATFLAG_DEFAULT);
	return stat.cbSize.LowPart;
}

inline auto streamToString(IStream* &stream) -> string {
	ULONG size = getStreamSize(stream);
	auto  data = make_unique<char[]>(size);

	LARGE_INTEGER li = {0};
	ULONG bytesRead;

	stream->Seek(li, STREAM_SEEK_SET, NULL);
	stream->Read(data.get(), size, &bytesRead);

	return string(data.get(), (int)size);
}

inline auto imageToBitmap(Image* image, Bitmap* &bitmap) -> void {
	auto height = image->getHeight();

	for (uint16_t y = 0; y < height; y++) {
		auto width = image->getWidth();
		uint32_t startIndex = width * y;

		for (uint16_t x = 0; x < width;  x++) {
			auto px = image->getPixel(startIndex + x);
			bitmap->SetPixel(x, y, Color(px.a, px.r, px.g, px.b));
		}
	}
}

inline auto imageToPngStream(Image* image, IStream* &stream) -> void {
	Gdiplus::GdiplusStartupInput input;
	ULONG_PTR token;
	Gdiplus::GdiplusStartup(&token, &input, NULL);

	auto    width  = image->getWidth();
	auto    height = image->getHeight();
	INT     stride = (width * 3 + 3) / 4 * 4;
	Bitmap* bitmap = new Bitmap(width, height);
	BYTE*   bytes  = new BYTE[stride * height];

	if (!image->isTransparent()) {
		bitmap = new Bitmap(width, height, stride, PixelFormat24bppRGB, bytes);
	}

	imageToBitmap(image, bitmap);
	bitmapToPngStream(bitmap, stream);

	delete bitmap;
	delete[] bytes;

	Gdiplus::GdiplusShutdown(token);
}

Image::Image(uint16_t aWidth, uint16_t aHeight) {
	width  = aWidth;
	height = aHeight;
}

auto Image::getWidth()  -> uint16_t {
	return width;
}

auto Image::getHeight() -> uint16_t {
	return height;
}

auto Image::isTransparent() -> bool {
	return transparent;
}

auto Image::addPixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a) -> void {
	pixels.push_back(Pixel(r, g, b, a));

	if (255 != a) {
		transparent = true;
	}
}

auto Image::addChunk(const Chunk &chunk) -> void {
	chunks.push_back(chunk);
}

auto Image::insertChunk(const Chunk  &chunk) -> void {
	extraChunks.push_back(chunk);
}

auto Image::insertChunk(const string &chunk) -> void {
	extraBinaryChunks.push_back(chunk);
}

auto Image::toString() -> string {
	commit();

	string data = signature + header;

	for (auto &extraChunk : extraChunks) {
		data += extraChunk;
	}

	for (auto &extraChunk : extraBinaryChunks) {
		data += extraChunk;
	}

	for (auto &chunk : chunks) {
		data += chunk;
	}

	data += end;

	return data;
}

auto Image::commit() -> void {
	chunks.clear();

	auto pngString = toPngString();

	uint32_t offset    = 8;
	uint32_t maxOffset = pngString.size() - 11;

	signature = pngString.substr(0, offset);

	while (offset < maxOffset) {
		Chunk chunk(pngString, offset);

		if (chunk.isCritical()) {
			if (chunk.isHeader()) {
				header = chunk;
			}
			else if (chunk.isEnd()) {
				end = chunk;
			}
			else {
				addChunk(chunk);
			}
		}

		offset += chunk.size();
	}
}

auto Image::toPngString() -> string {
	IStream* stream;
	imageToPngStream(this, stream);
	string pngString = streamToString(stream);
	stream->Release();

	return pngString;
}

auto Image::getPixel(uint16_t x, uint16_t y) const -> Pixel {
	return pixels[(uint32_t)width * (uint32_t)y + (uint32_t)x];
}

auto Image::getPixel(uint32_t index) const -> Pixel {
	return pixels[index];
}

} // namespace MaratTanalin::PizzaPNG