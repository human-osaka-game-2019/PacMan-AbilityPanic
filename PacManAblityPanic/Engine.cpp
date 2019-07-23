#include "class.h"
#include "window.h"
#include "Device.h"

bool InitEngine(int width, int height, HINSTANCE hInst)
{
	//	window生成
	HWND wind_handle = Make_WndFull(hInst,width,height);

	BuildDxDevice(wind_handle);

	return false;
}

void EndEngine()
{

}