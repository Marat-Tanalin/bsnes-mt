/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

#include <Windows.h>

namespace bsnesMt::keyboard {

typedef void (*hookCallbackType)(WPARAM keyCode, bool keyDown, bool shiftPressed, bool ctrlPressed, bool altPressed);

auto initHook(hookCallbackType callback) -> void;

auto shutdownHook() -> bool;

auto isKeyPressed(int key) -> bool;

} // namespace bsnesMt::keyboard