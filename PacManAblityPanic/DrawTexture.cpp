
#include <d3d9.h>
#include <d3dx9.h>
#include <D3dx9tex.h>

#include "DrawTexture.h"
#include "class.h"
const int D3DFVF_CUSTOMVERTEX(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

//struct TEXTUREDATA
//{
//
//	LPDIRECT3DTEXTURE9 m_pTexture;  // テクスチャ情報
//	float m_Width;					// テクスチャの幅
//	float m_Height;					// テクスチャの高さ
//
//};
//
//TEXTUREDATA Texture;

void Draw(float x ,float y,float z,float rhw ,DWORD color ,float tu ,float tv,float width,float height,float tu_width,float tv_height, LPDIRECT3DTEXTURE9* Texture,int texture_number,Pointa point)
{
	
	CUSTOMVERTEX customvertex[4] = {
	{x        ,y         ,z,rhw,color,tu           ,tv            },
	{x + width,y         ,z,rhw,color,tu + tu_width,tv            },
	{x + width,y + height,z,rhw,color,tu + tu_width,tv + tv_height},
	{x        ,y + height,z,rhw,color,tu           ,tv + tv_height},
	};

	point.pDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	point.pDevice->SetTexture(0, *Texture);
	point.pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, customvertex, sizeof(CUSTOMVERTEX));

}

void DrawEx(float x, float y,float width, float height,LPDIRECT3DTEXTURE9* Texture, Pointa point)
{

	CUSTOMVERTEX customvertex[4] = {
	{x        ,y         ,  0, 1.0f, 0xffffffff,  0.0f, 0.0f},
	{x + width,y         ,  0, 1.0f, 0xffffffff,  1.0f, 0.0f},
	{x + width,y + height,  0, 1.0f, 0xffffffff,  1.0f, 1.0f},
	{x        ,y + height,  0, 1.0f, 0xffffffff,  0.0f, 1.0f},
	};

	point.pDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	point.pDevice->SetTexture(0, *Texture);
	point.pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, customvertex, sizeof(CUSTOMVERTEX));

}

void LoadTexture(const char* file_name, LPDIRECT3DTEXTURE9* Texture, int texture_number,Pointa point) {
	HRESULT result = D3DXCreateTextureFromFileEx(point.pDevice, file_name, 1920, 1080, 0, 0, D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_DEFAULT,
		0xff000000, NULL, NULL, Texture);

	if ((_D3DXERR)result == D3DXERR_INVALIDDATA)
	{
		OutputDebugString(TEXT("\nテクスチャファイルが見つかりません\n"));
	}
}

/*
void DrawMapChip(D3DXVECTOR2 draw_pos, D3DXVECTOR2 texture_pos, D3DXVECTOR2 sprite_size, Pointa point, TEXTUREDATA *Texture)
{
	D3DXVECTOR2 uv = D3DXVECTOR2(texture_pos.x / Texture->m_Width , texture_pos.y / Texture->m_Height);
	D3DXVECTOR2 uv_size = D3DXVECTOR2(sprite_size.x / Texture->m_Width, sprite_size.y / Texture->m_Height);

	CUSTOMVERTEX sprite[] =
	{
		{ draw_pos.x, draw_pos.y, 0.0f, 1.0f, uv.x, uv.y },
		{ draw_pos.x + sprite_size.x, draw_pos.y, 0.0f, 1.0f, uv.x + uv_size.x, uv.y },
		{ draw_pos.x + sprite_size.x, draw_pos.y + sprite_size.y, 0.0f, 1.0f, uv.x + uv_size.x, uv.y + uv_size.y },
		{ draw_pos.x, draw_pos.y + sprite_size.y, 0.0f, 1.0f, uv.x, uv.y + uv_size.y },
	};

	point.pDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	point.pDevice->SetTexture(0, Texture->m_pTexture);
	point.pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, sprite, sizeof(CUSTOMVERTEX));
}
*/