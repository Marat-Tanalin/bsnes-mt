/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

#include <Windows.h>

namespace bsnesMt::keyboard {

auto initHook(HOOKPROC callback) -> void;

auto shutdownHook() -> bool;

auto isKeyPressed(int key) -> bool;

} // namespace bsnesMt::keyboard