#ifndef DRAWTEXTURE
#define DRAWTEXTURE

//const int MAX_TEXTURE = 10;
//TEXTUREDATA texture[MAX_TEXTURE];

void Draw(float x, float y, float z, float rhw, DWORD color, float tu, float tv, float width, float height, float tu_width, float tv_height, LPDIRECT3DTEXTURE9* texture, int texture_number, Pointa point);

void DrawEx(float x, float y,float width, float height, LPDIRECT3DTEXTURE9* Texture, Pointa point);

void LoadTexture(const char* file_name, LPDIRECT3DTEXTURE9* texture, int texture_number, Pointa point);

#endif // !1

