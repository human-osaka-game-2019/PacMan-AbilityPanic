#include <Windows.h>
#include "window.h"
#include "Engine.h"
#include "Scene.h"

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInstance,
	LPSTR lpCmpLine,INT nCmdShow)
{
	if (InitEngine(1920, 1080, hInst) == false)
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
				break;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			// シーンの更新
			UpdateScene();
		}
	}

	// エンジン終了
	EndEngine();

	return 0;
}