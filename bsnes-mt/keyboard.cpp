/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#include "keyboard.h"

namespace bsnesMt::keyboard {

static HHOOK hook;

auto initHook(HOOKPROC callback) -> void {
	hook = SetWindowsHookExW(WH_KEYBOARD, callback, NULL, GetCurrentThreadId());
}

auto shutdownHook() -> bool {
	return (bool)UnhookWindowsHookEx(hook);
}

auto isKeyPressed(int key) -> bool {
	return GetKeyState(key) & 0x8000;
}

} // namespace bsnesMt::keyboard