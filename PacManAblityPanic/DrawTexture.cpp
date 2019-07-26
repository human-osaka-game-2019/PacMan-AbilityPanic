#include "class.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "DrawTexture.h"
#include <D3dx9tex.h>

const int D3DFVF_CUSTOMVERTEX(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

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

void LoadTexture(const char* file_name, LPDIRECT3DTEXTURE9* Texture, int texture_number,Pointa point) {
	D3DXCreateTextureFromFileEx(point.pDevice, file_name, 1920, 1080, 0, 0, D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_DEFAULT,
		0xff000000, NULL, NULL, Texture);
}