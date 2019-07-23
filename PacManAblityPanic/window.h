#ifndef WINDOW_H
#define WINDOW_H

#include<windows.h>

LRESULT CALLBACK wndProc(HWND, UINT, WPARAM, LPARAM);
HWND Make_Wnd(HINSTANCE, int, int);
HWND Make_Full(HINSTANCE, int, int);
#endif