#ifndef DRAWTEXTURE
#define DRAWTEXTURE

//const int MAX_TEXTURE = 10;
//TEXTUREDATA texture[MAX_TEXTURE];

// #include <D3dx9tex.h>

#include "class.h"


void Draw(float x, float y, float width, float height, float tu, float tv, float tu_width, float tv_height, LPDIRECT3DTEXTURE9* Texture, Pointa point);

void DrawEx(float x, float y,float width, float height, LPDIRECT3DTEXTURE9* Texture, Pointa point);

void LoadTexture(const char* file_name, LPDIRECT3DTEXTURE9* Texture, int texture_number, Pointa* point);

void DrawMapChip(Pointa* point,MapChipData MapData, LPDIRECT3DTEXTURE9* Texture,int apChipList[][19]);

void DrawMap(MapChipData MapData, Pointa* point, LPDIRECT3DTEXTURE9* Texture);


#endif // !1

