/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#include "keyboard.h"

namespace bsnesMt::keyboard {

static HHOOK hook;
static hookCallbackType hookCallback;

auto CALLBACK hotkeyHookCallback(int code, WPARAM wParam, LPARAM lParam) -> LRESULT {
	if (HC_ACTION == code) {
		hookCallback(
			wParam,
			!(HIWORD(lParam) & 0xC000), // keyDown
			isKeyPressed(VK_SHIFT),
			isKeyPressed(VK_CONTROL),
			isKeyPressed(VK_MENU) // Alt key
		);
	}

	return CallNextHookEx((HHOOK)hotkeyHookCallback, code, wParam, lParam);
}

auto initHook(hookCallbackType callback) -> void {
	hookCallback = callback;
	hook = SetWindowsHookExW(WH_KEYBOARD, hotkeyHookCallback, NULL, GetCurrentThreadId());
}

auto shutdownHook() -> bool {
	return (bool)UnhookWindowsHookEx(hook);
}

auto isKeyPressed(int key) -> bool {
	return GetKeyState(key) & 0x8000;
}

} // namespace bsnesMt::keyboard