#include "class.h"
#include "window.h"
#include "Device.h"

// ポインタ宣言をまとめたクラス
Pointa point;

bool InitEngine(int width, int height, HINSTANCE hInst)
{
	//	window生成
	HWND wind_handle = Make_WndFull(hInst,width,height);

	BuildDxDevice(wind_handle);

	return false;
}

void EndEngine()
{
	// テクスチャの開放もする

	if (point.pDinput != nullptr)
	{
		point.pDinput->Release();
		point.pDinput = nullptr;
	}

	if (point.pkey != nullptr)
	{
		point.pkey->Release();
		point.pkey = nullptr;
	}
}

bool DrawStart()
{
	point.pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 0.0f, 0);

	point.pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	point.pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	point.pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	if (D3D_OK == point.pDevice->BeginScene())
	{
		return true;
	}

	return false;
}

void UpdateInput()
{
	// ここにキーボードの設定を書く
}