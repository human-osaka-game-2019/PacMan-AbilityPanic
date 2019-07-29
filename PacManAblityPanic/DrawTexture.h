﻿#ifndef DRAWTEXTURE
#define DRAWTEXTURE

//const int MAX_TEXTURE = 10;
//TEXTUREDATA texture[MAX_TEXTURE];

// #include <D3dx9tex.h>

#include "class.h"

void Draw(float x, float y, float z, float rhw, DWORD color, float tu, float tv, float width, float height, float tu_width, float tv_height, LPDIRECT3DTEXTURE9* texture, int texture_number, Pointa point);

void DrawEx(float x, float y,float width, float height, LPDIRECT3DTEXTURE9* Texture, Pointa point);

void LoadTexture(const char* file_name, LPDIRECT3DTEXTURE9* texture, int texture_number, Pointa point);

// void DrawMapChip(D3DXVECTOR2 draw_pos, D3DXVECTOR2 texture_pos, D3DXVECTOR2 sprite_size, Pointa point, TEXTUREDATA* Texture);

#endif // !1

