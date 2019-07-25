#include "class.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "DrawTexture.h"
#include <D3dx9tex.h>

TEXTUREDATA g_TextureList[MaxTextureId] = { 0 };

Pointa D;

bool LoadTexture(char* file_name, MAPCHIP_TEXTURE_ID mapchipnumber)
{
	//IDに問題があればFALSEをかえす。
	if (mapchipnumber <= MAPCHIP_TEXTURE_ID::Non &&
		mapchipnumber >= MAPCHIP_TEXTURE_ID::MaxTextureId)
	{
		return false;
	}

	if (g_TextureList[mapchipnumber].m_pTexture != nullptr)
	{
		return true;
	}

	// テクスチャ読み込み
	if (FAILED(D3DXCreateTextureFromFileEx(D.pDevice, file_name, 450, 351, 0, 0, D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_DEFAULT,
		0xff000000, NULL, NULL, &g_TextureList[mapchipnumber].m_pTexture)))
	{
		MessageBox(0, _T("テクスチャオブジェクトの作成に失敗しました"), NULL, MB_OK);
		//return E_FAIL;
		return false;
	}
	else
	{
		D3DSURFACE_DESC desc;


		// テクスチャ情報の取得
		if (FAILED(g_TextureList[mapchipnumber].m_pTexture->GetLevelDesc(0, &desc)))
		{
			// 取得に失敗したら解放して読み込みを失敗とする
			g_TextureList[mapchipnumber].m_pTexture->Release();
			g_TextureList[mapchipnumber].m_pTexture = nullptr;
			return false;
		}
		// サイズを保存
		g_TextureList[mapchipnumber].m_Width = (float)desc.Width;
		g_TextureList[mapchipnumber].m_Height = (float)desc.Height;
	}

	return true;
}

void DrawTexture(FLOAT x, FLOAT y, FLOAT z ,FLOAT rhw,DWORD color , FLOAT tu , FLOAT tv,
	FLOAT width, FLOAT height, FLOAT w_tu , FLOAT h_tv, INT texture)
{
	CUSTOMVERTEX cv[] = {
		{x,y,z,rhw,color,tu,tv},
		{x + width ,y,z,rhw,color,tu,tv},
		{x + width,y + height,z,rhw,color,tu,tv},
		{x,y + height,z,rhw,color,tu,tv}
	};

	D.pDevice->SetTexture(0, g_TextureList[texture].m_pTexture);
	D.pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cv, sizeof(CUSTOMVERTEX));

}
