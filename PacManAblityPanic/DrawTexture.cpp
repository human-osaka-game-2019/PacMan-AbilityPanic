﻿
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
//TEXTUREDATA pTexture;

void Draw(float x ,float y,float width,float height,float tu ,float tv , float tu_width,float tv_height, LPDIRECT3DTEXTURE9* Texture,Pointa point)
{
	
	CUSTOMVERTEX customvertex[4] = {
	{x        ,y         ,0,1,0xffffffff,tu           ,tv            },
	{x + width,y         ,0,1,0xffffffff,tu + tu_width,tv            },
	{x + width,y + height,0,1,0xffffffff,tu + tu_width,tv + tv_height},
	{x        ,y + height,0,1,0xffffffff,tu           ,tv + tv_height},
	};

	point.pDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	point.pDevice->SetTexture(0, *Texture);
	point.pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, customvertex, sizeof(CUSTOMVERTEX));

}


void DrawEx(float x, float y,float width, float height, LPDIRECT3DTEXTURE9* Texture ,Pointa point)
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

void LoadTexture(const char* file_name, LPDIRECT3DTEXTURE9* Texture, int texture_number,Pointa* point) {
	HRESULT result = D3DXCreateTextureFromFileEx(point->pDevice, file_name, 1920, 1080, 0, 0, D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_DEFAULT,
		0xff000000, NULL, NULL, Texture);

	if ((_D3DXERR)result == D3DXERR_INVALIDDATA)
	{
		OutputDebugString(TEXT("\nテクスチャファイルが見つかりません\n"));
	}
}

///////////////////////////////////////////////////////////////////////////////////////




#define MAP_SIZE_WIDTH (19)	
#define MAP_SIZE_HEIGHT (22)

int MapChipList[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH]
{
	{  5, 23, 23, 23, 23, 23, 23, 23, 23, 34, 23, 23, 23, 23, 23, 23, 23, 23,  4},
	{ 18, 12, 12, 12, 12, 12, 12, 12, 12, 18, 12, 12, 12, 12, 12, 12, 12, 12, 18},
	{ 18, 12, 19, 21, 12, 19, 26, 21, 12, 18, 12, 19, 26, 21, 12, 19, 21, 12, 18},
	{ 18, 12, 22, 20, 12, 22, 25, 20, 12, 14, 12, 22, 25, 20, 12, 22, 20, 12, 18},
	{ 18, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 18},
	{ 18, 12, 17, 15, 12, 16, 12, 17, 23, 34, 23, 15, 12, 16, 12, 17, 15, 12, 18},
	{ 18, 12, 12, 12, 12, 18, 12, 12, 12, 18, 12, 12, 12, 18, 12, 12, 12, 12, 18},
	{ 18, 12, 19, 21, 12, 33, 23, 15,  0, 14,  0, 17, 23, 32, 12, 19, 21, 12, 18},
	{ 18, 12, 24, 27, 12, 18,  0,  0,  0, 77,  0,  0,  0, 18, 12, 24, 27, 12, 18},
	{ 18, 12, 22, 20, 12, 14,  0,  6,  2,  1,  3,  9,  0, 14, 12, 22, 20, 12, 18},
	{ 18, 12, 12, 12, 12,  0,  0, 11, 65, 41, 89, 11,  0,  0, 12, 12, 12, 12, 18},
	{ 18, 12, 19, 21, 12, 16,  0,  8, 10, 10, 10,  7,  0, 16, 12, 19, 21, 12, 18},
	{ 18, 12, 24, 27, 12, 18,  0,  0,  0,  0,  0,  0,  0, 18, 12, 24, 27, 12, 18},
	{ 18, 12, 22, 20, 12, 14,  0, 17, 23, 34, 23, 15,  0, 14, 12, 22, 20, 12, 18},
	{ 18, 12, 12, 12, 12, 12, 12, 12, 12, 18, 12, 12, 12, 12, 12, 12, 12, 12, 18},
	{ 18, 12, 17,  4, 12, 17, 23, 15, 12, 14, 12, 17, 23, 15, 12,  5, 15, 12, 18},
	{ 18, 12, 12, 18, 12, 12, 12, 12, 12, 40, 12, 12, 12, 12, 12, 18, 12, 12, 18},
	{ 33, 15, 12, 14, 12, 16, 12, 17, 23, 34, 23, 15, 12, 16, 12, 14, 12, 17, 32},
	{ 18, 12, 12, 12, 12, 18, 12, 12, 12, 18, 12, 12, 12, 18, 12, 12, 12, 12, 18},
	{ 18, 12, 17, 23, 23, 28, 23, 15, 12, 14, 12, 17, 23, 28, 23, 23, 15, 12, 18},
	{ 18, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 18},
	{  8, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  7},
};



void DrawMap(MapChipData MapData,Pointa* point, LPDIRECT3DTEXTURE9* Texture)
{
	float cv = MapData.chip_x / MapData.Texture_Height;
	float cu = MapData.chip_y / MapData.Texture_Widht;
	float cv_size = MapData.MapChipWidht  / MapData.Texture_Height;
	float cu_size = MapData.MapChipHeight / MapData.Texture_Widht;

	CUSTOMVERTEX sprite[] =
	{ 
		{ MapData.x                       , MapData.y                        , 0.0f, 1.0f,0xffffffff, cv          , cu           },
		{ MapData.x + MapData.MapChipWidht, MapData.y                        , 0.0f, 1.0f,0xffffffff, cv + cv_size, cu           },
		{ MapData.x + MapData.MapChipWidht, MapData.y + MapData.MapChipHeight, 0.0f, 1.0f,0xffffffff, cv + cv_size, cu + cu_size },
		{ MapData.x                       , MapData.y + MapData.MapChipHeight, 0.0f, 1.0f,0xffffffff, cv          , cu + cu_size },
	};

	point->pDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	point->pDevice->SetTexture(0, *Texture);
	point->pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, sprite, sizeof(CUSTOMVERTEX));
}

void DrawMapChip(Pointa* point, MapChipData MapData,LPDIRECT3DTEXTURE9* Texture)
{
	for (int i = 0; i < MapData.Map_HeigjtNumber; i++)
	{
		for (int j = 0; j < MapData.Map_WidhtNumber; j++)
		{
			int chip_id = MapChipList[i][j];
			if (chip_id == 0)
			{
				continue;
			}
			int width_num = MapData.Texture_Height / MapData.MapChipHeight;

			int height_num = MapData.Texture_Widht / MapData.MapChipWidht;
			
			float chip_pos_x = (float)((chip_id % width_num) * MapData.MapChipWidht) + 16;
			float chip_pos_y = (float)((chip_id / height_num) * MapData.MapChipHeight) + 16;
			
			MapData.chip_x = chip_pos_x;
			MapData.chip_y = chip_pos_y;
			MapData.x = MapData.MapChipWidht * j;
			MapData.y = MapData.MapChipHeight * i;

			DrawMap(MapData, point, Texture);
		}
	}
}

