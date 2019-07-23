#include <Windows.h>
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmpLine,
	INT       nCmdShow)
{
	// エンジンの初期化
	if (InitEngine(640, 480, "前期課題") == false)
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