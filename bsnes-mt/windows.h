/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

#include <Windows.h>

namespace bsnesMt::windows {

auto getWorkAreaSize() -> SIZE;

auto isTopLevelWindow(HWND window) -> bool;

auto showAboutCallback(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, LONG_PTR lpRefData) -> HRESULT;
auto showAbout(HWND parentWindow) -> void;

} // namespace bsnesMt::windows