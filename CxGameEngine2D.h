#include <Windows.h>

#ifndef CXGAMEENGINE2DDLL
	#define CXGAMEENGINE2DDLL

#ifdef _DECLSPEC
	#define DECLSPEC extern "C" __declspec(dllexport)
#else
	#define DECLSPEC extern "C" __declspec(dllexport)
#endif

DECLSPEC LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

//SetWindowData
DECLSPEC int set_style(const char* style);
DECLSPEC int set_hIcon(const char* hIcon_path);
DECLSPEC int set_windowBackground(const char* bg_type);
DECLSPEC int set_hCursor(const char* hCursor_type);
DECLSPEC int set_cbClsExtra(int cbClsExtra);
DECLSPEC int set_cbWndExtra(int cbWndExtra);

//CreateWindow
DECLSPEC int createNewWindow(const char* szWindowClass, const char* szTitle, const char* lpszClassName, const char* lpszMenuName);
#endif