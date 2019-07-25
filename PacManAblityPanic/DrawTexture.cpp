#include "class.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "DrawTexture.h"
#include <D3dx9tex.h>

static TEXTUREDATA** g_TextureList[SceneIdMax] = { nullptr };

bool IsCategoryRangeCheck(int SceneId, int 	SelectTexture);
bool CreateTexture(const char* file_name, int TextureWidth, int TextureHeight, TEXTUREDATA* texture_data);

int SceneMaxTexture[] =
{
	TitleTextureList::MaxTitleTexture,
	SetTextureList::MaxSetTexture,
	OptionTextureList::MaxOptionTexture,
	GameTextureList::MaxGameTexture,
	ResultTextureList::MaxResultTexture,
};

Pointa D;

bool LoadTexture(const char*    file_name, // ファイルの名前
	                    int       SceneId, // SceneId
	                    int SelectTexture, // MAPCHIP_TEXTURE_ID 
	                    int  TextureWidth, // textureの幅
	                    int  TextureHeight // textureの高さ
)
{
	IsCategoryRangeCheck(SceneId,SelectTexture);

	return CreateTexture(file_name,TextureWidth,TextureHeight, g_TextureList[SceneId][SelectTexture]);
}

void DrawTexture(float x, float y,float width, float height,TEXTUREDATA* texture)
{
	CUSTOMVERTEX cv[] = 
	{
		{x         ,y         ,  0.0f,  1.0f,    0xffffffff,  0.0f,  0.0f},
		{x + width ,y         ,  0.0f,  1.0f,    0xffffffff,  1.0f,  0.0f},
		{x + width ,y + height,  0.0f,  1.0f,    0xffffffff,  1.0f,  1.0f},
		{x         ,y + height,  0.0f,  1.0f,    0xffffffff,  0.0f,  1.0f}
	};								      			    

	D.pDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_TEX1);
	D.pDevice->SetTexture(0, texture->m_pTexture);
	D.pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cv, sizeof(CUSTOMVERTEX));

}

void DrawTextureEx(float x, float y, float tu, float tv, float width, float height,TEXTUREDATA* texture)
{
	CUSTOMVERTEX cv[] =
	{
		{x         ,y         ,  0.0f,  1.0f,    0xffffffff,  tu,   tv},
		{x + width ,y         ,  0.0f,  1.0f,    0xffffffff,  tu,   tv},
		{x + width ,y + height,  0.0f,  1.0f,    0xffffffff,  tu,   tv},
		{x         ,y + height,  0.0f,  1.0f,    0xffffffff,  tu,   tv}
	};

	D.pDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_TEX1);
	D.pDevice->SetTexture(0, texture->m_pTexture);
	D.pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cv, sizeof(CUSTOMVERTEX));

}

bool CreateTexture(const char* file_name,int TextureWidth, int TextureHeight, TEXTUREDATA* texture_data)
{
	// テクスチャ読み込み
	if (FAILED(D3DXCreateTextureFromFileEx(D.pDevice, file_name,
		TextureWidth, TextureHeight, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_DEFAULT, 0xff000000,
		NULL, NULL, &texture_data->m_pTexture
	)))
	{
		MessageBox(0, _T("テクスチャオブジェクトの作成に失敗しました"), NULL, MB_OK);
		//return E_FAIL;
		return false;
	}
	else
	{
		D3DSURFACE_DESC desc;


		// テクスチャ情報の取得
		if (FAILED(texture_data->m_pTexture->GetLevelDesc(0, &desc)))
		{
			// 取得に失敗したら解放して読み込みを失敗とする
			texture_data->m_pTexture->Release();
			texture_data->m_pTexture = nullptr;
			return false;
		}
		// サイズを保存
		texture_data->m_Width = TextureWidth;
		texture_data->m_Height = TextureHeight;

		return true;
	}
}

bool IsCategoryRangeCheck(int SceneId, int 	SelectTexture)
{
	
	//IDに問題があればFALSEをかえす。
	if (SceneId <= SceneId::TitleScene &&
		SceneId >= SceneId::SceneIdMax)
	{
		return false;
	}

	if (SelectTexture <= -1 ||
		SelectTexture >= SceneMaxTexture[SelectTexture])

	{
		return false;
	}

	return true;
}

TEXTUREDATA* GetTexture(int SceneId, int SelectTexture)
{
	if (IsCategoryRangeCheck(SceneId, SelectTexture) == false)
	{
		return nullptr;
	}

	return g_TextureList[SceneId][SelectTexture];
}