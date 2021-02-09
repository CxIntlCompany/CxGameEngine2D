#include <Windows.h>

#ifndef CXGAMEENGINE2DDLL
	#define CXGAMEENGINE2DDLL

#ifdef _DECLSPEC
	#define DECLSPEC extern "C" __declspec(dllexport)
#else
	#define DECLSPEC extern "C" __declspec(dllexport)
#endif

//Pre Defined
PAINTSTRUCT paintStruct;
HDC hdc;

int _rect_left, _rect_top, _rect_right, _rect_bottom;
bool bool_message;

//SetWindowData
DECLSPEC int set_style(const char* style);
DECLSPEC int set_hIcon(const char* hIcon_path);
DECLSPEC int set_windowBackground(const char* bg_type);
DECLSPEC int set_hCursor(const char* hCursor_type);
DECLSPEC int set_cbClsExtra(int cbClsExtra);
DECLSPEC int set_cbWndExtra(int cbWndExtra);

//CreateWindow
DECLSPEC int createNewWindow(const char* szWindowClass, const char* szTitle, const char* lpszClassName, const char* lpszMenuName);

//Pre Defined Function
DECLSPEC int createRect(int left, int top, int right, int bottom);
#endif