//CxGameEngine2D.dll
//Made by Xiaojun Chen

#include "CxGameEngine2D.h"
#include <Windows.h>
#include <stdio.h>

WNDCLASS wc;
HINSTANCE hInstance;

DECLSPEC LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_DESTROY:
		DestroyWindow(hWnd);
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
};

DECLSPEC int set_style(const char* style_type) {
	if (style_type == "default") {
		wc.style = CS_HREDRAW | CS_VREDRAW;
	}
	return 0;
};

DECLSPEC int set_windowBackground(const char* bg_type) {
	if (bg_type == "white") {
		wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	}
	return 0;
}

DECLSPEC int set_hIcon(const char* hIcon_path) {
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	return 0;
};

DECLSPEC int set_hCursor(const char* hCursor_type) {
	if (hCursor_type == "default") {
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	}
	return 0;
};

DECLSPEC int set_cbClsExtra(int cbClsExtra) {
	wc.cbClsExtra = cbClsExtra;
	return 0;
};

DECLSPEC int set_cbWndExtra(int cbWndExtra) {
	wc.cbWndExtra = cbWndExtra;
	return 0;
};

//CreateWindow
DECLSPEC int createNewWindow(const char* lpClassName, const char* lpWindowName, const char* lpszClassName, const char* lpszMenuName) {
	//Default init
	if (wc.style == NULL) {
		set_style("default");
	}
	wc.lpfnWndProc = WndProc;
	if (wc.cbClsExtra == NULL) {
		set_cbClsExtra(0);
	}
	else if (wc.cbWndExtra == NULL) {
		set_cbWndExtra(0);
	}
	wc.hInstance = hInstance;
	if (wc.hIcon == NULL) {
		set_hIcon("0");
		//Õ¼Î» ´ýÐÞ¸Ä
	}
	else if (wc.hCursor == NULL) {
		set_hCursor("default");
	}
	else if (wc.hbrBackground == NULL) {
		set_windowBackground("white");
	}
	if (lpszMenuName == "NULL") {
		wc.lpszMenuName = NULL;
	}
	else {
		wc.lpszMenuName = (LPCSTR)lpszMenuName;
	}
	wc.lpszClassName = (LPCSTR)lpszClassName;

	if (!RegisterClass(&wc)) {
		MessageBox(NULL, "Call to RegisterClassEx failed!", "Windows Desktop Guided Tour", NULL);
		return 1;
	}
	
	HWND hWnd = CreateWindow(wc.lpszClassName, (PCHAR)lpWindowName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	if (!hWnd) {
		MessageBox(NULL, "Call to CreateWindow failed!", "Windows Desktop Guided Tour", NULL);
		return 1;
	}

	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	MSG msg;
	while (TRUE) {	
		if (GetMessage(&msg, NULL, 0, 0) == FALSE) {
			break;
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}


BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	switch (fdwReason) {
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}