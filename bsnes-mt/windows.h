/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

#include <string>

#include <Windows.h>

namespace bsnesMt::windows {

using std::string;

auto getWorkAreaSize() -> SIZE;

auto isTopLevelWindow(HWND window) -> bool;

auto messageBox(const string &text, const string &title, UINT flags = 0, HWND parentWindow = NULL) -> void;

auto showMessage(const string &text, const string &title, UINT flags = 0, HWND parentWindow = NULL) -> void;
auto showError(const string &text, const string &title, HWND parentWindow = NULL) -> void;
auto showNotice(const string &text, const string &title, HWND parentWindow = NULL) -> void;
auto showInfo(const string &text, const string &title, HWND parentWindow = NULL) -> void;

auto showAboutCallback(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, LONG_PTR lpRefData) -> HRESULT;
auto showAbout(HWND parentWindow) -> void;

} // namespace bsnesMt::windows