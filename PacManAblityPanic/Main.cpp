

#include <Windows.h>
#include "window.h"

int WINAPI WinMain(HINSTANCE hInst,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmpLine,
	INT       nCmdShow)
{
	//	window生成
	HWND wind_handle = Make_WndFull(hInst, 640, 480);

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