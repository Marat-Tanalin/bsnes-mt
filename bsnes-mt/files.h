/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

#include <cstdint>
#include <string>

namespace bsnesMt::files {

using std::string;

auto fileExists(const string &name) -> bool;

auto getTextFileContents(const string &name) -> string;

auto saveFile(const string &data, const string &path) -> bool;

auto saveBgraArrayAsPngImage(uint8_t* data, uint16_t width, uint16_t height, const string &path) -> bool;

} // namespace bsnesMt::files