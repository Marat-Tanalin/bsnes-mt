/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#include "keyboard.h"

namespace bsnesMt::keyboard {

static HHOOK hook;
static hookCallbackType hookCallback;

auto CALLBACK hotkeyHookCallback(int code, WPARAM wParam, LPARAM lParam) -> LRESULT {
	auto altPressed   = isKeyPressed(VK_MENU);
	auto ctrlPressed  = isKeyPressed(VK_CONTROL);
	auto shiftPressed = isKeyPressed(VK_SHIFT);
	auto keyDown      = !(HIWORD(lParam) & 0xC000);

	if (HC_ACTION == code) {
		hookCallback(wParam, keyDown, shiftPressed, ctrlPressed, altPressed);
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