#pragma once
#include "DXEditor.h"

#define DllExport extern "C" _declspec(dllexport)
DllExport void  EditorMain(int* instancePtrAddress, int* hPrevInstancePtrAddress, int* hWndPtrAddress, int nCmdShow, int screenWidth, int screenHeight);

DllExport void WndProc(int* hWndPtrAddress, int msg, int wParam, int lParam);
DllExport void RenderFrame();
