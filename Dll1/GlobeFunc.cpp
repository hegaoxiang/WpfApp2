#include "pch.h"
#include "GlobeFunc.h"
#if 1
DXEditor* g_sample;
void  EditorMain(int* instancePtrAddress, int* hPrevInstancePtrAddress, int* hWndPtrAddress, int nCmdShow, int screenWidth, int screenHeight)
{
	HINSTANCE hInstance = (HINSTANCE)instancePtrAddress;
	HINSTANCE hPrevInstance = (HINSTANCE)hPrevInstancePtrAddress;
	HWND hWnd = (HWND)hWndPtrAddress;

	Win32Application::SetHwnd(hWnd);

	g_sample = new DXEditor(screenWidth, screenHeight, L"D3D12 Hello Window");

	g_sample->OnInit();
	
}

void WndProc(int* hWndPtrAddress, int msg, int wParam, int lParam)
{
	HWND hWnd = (HWND)hWndPtrAddress;
}

void RenderFrame()
{
	g_sample->OnRender();
}

#endif

#if 0
_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	DXEditor sample(1280, 720, L"D3D12 Hello Window");
	return Win32Application::Run(&sample, hInstance, nCmdShow);
}
#endif

