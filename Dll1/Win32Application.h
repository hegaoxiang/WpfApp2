#pragma once
#include <windows.h>
class DXSample;

class Win32Application
{
public:
	static int Run(DXSample* pSample, HINSTANCE hInstance, int nCmdShow,HWND hWnd = nullptr);
	static HWND GetHwnd() { return m_hwnd; }
	static void SetHwnd(HWND hWnd) { m_hwnd = hWnd; }
public:
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	static HWND m_hwnd;
};

