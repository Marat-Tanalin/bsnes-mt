/*! PizzaPNG by Marat Tanalin | http://tanalin.com/en/projects/pizza-png/ */

#include <memory>

#include "Image.h"

namespace MaratTanalin::PizzaPNG {

using std::make_unique;

Image::Image(uint16_t aWidth, uint16_t aHeight) {
	width  = aWidth;
	height = aHeight;
}

auto Image::addPixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a) -> void {
	if (255 == a) {
		pixels.push_back(Color(r, g, b));
	}
	else {
		pixels.push_back(Color(a, r, g, b));
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

auto Image::getImageEncoderId(const wstring &type) const -> CLSID {
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

auto Image::toBitmap(Bitmap* &bitmap) -> void {
	for (uint16_t y = 0; y < height; y++) {
		uint32_t startIndex = width * y;

		for (uint16_t x = 0; x < width;  x++) {
			bitmap->SetPixel(x, y, getPixel(startIndex + x));
		}
	}
}

auto Image::bitmapToPngStream(Bitmap* &bitmap, IStream* &stream) -> void {
	CLSID id = getImageEncoderId(L"png");
	CreateStreamOnHGlobal(NULL, true, &stream);
	bitmap->Save(stream, &id, NULL);
}

auto Image::toPngStream(IStream* &stream) -> void {
	Gdiplus::GdiplusStartupInput input;
	ULONG_PTR token;
	Gdiplus::GdiplusStartup(&token, &input, NULL);

	INT stride = (width * 3 + 3) / 4 * 4;
	Bitmap* bitmap = new Bitmap(width, height);
	BYTE*   bytes  = new BYTE[stride * height];

	if (!transparent) {
		bitmap = new Bitmap(width, height, stride, PixelFormat24bppRGB, bytes);
	}

	toBitmap(bitmap);
	bitmapToPngStream(bitmap, stream);

	delete bitmap;
	delete[] bytes;

	Gdiplus::GdiplusShutdown(token);
}

auto Image::getStreamSize(IStream* &stream) -> ULONG {
	STATSTG stat;
	stream->Stat(&stat, STATFLAG_DEFAULT);
	return stat.cbSize.LowPart;
}

auto Image::streamToString(IStream* &stream) -> string {
	ULONG size = getStreamSize(stream);
	auto  data = make_unique<char[]>(size);

	LARGE_INTEGER li = {0};
	ULONG bytesRead;

	stream->Seek(li, STREAM_SEEK_SET, NULL);
	stream->Read(data.get(), size, &bytesRead);

	return string(data.get(), (int)size);
}

auto Image::toPngString() -> string {
	IStream* stream;
	toPngStream(stream);
	string pngString = streamToString(stream);
	stream->Release();

	return pngString;
}

auto Image::getPixel(uint16_t x, uint16_t y) const -> Color {
	return pixels[(uint32_t)width * (uint32_t)y + (uint32_t)x];
}

auto Image::getPixel(uint32_t index) const -> Color {
	return pixels[index];
}

} // namespace MaratTanalin::PizzaPNG