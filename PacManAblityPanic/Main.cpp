#include <Windows.h>
#include "window.h"
#include "Engine.h"
#include "Scene.h"
#include "class.h"


int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInstance,
	LPSTR lpCmpLine,INT nCmdShow)
{
Pointa point;
Count cn;
	if (InitEngine(1920, 1080, hInst, &point) == false)
	{
		return 0;
	}
	
	while (true)
	{
		bool message_ret = false;
		MSG msg;

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
				break;
			}
			else
			{

			UpdateScene(&point);

			}
		}
		
	}

	// エンジン終了
	EndEngine(point);

	return 0;
}