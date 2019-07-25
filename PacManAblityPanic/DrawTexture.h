#ifndef DRAWTEXTURE
#define DRAWTEXTURE
bool LoadTexture(char* file_name, MAPCHIP_TEXTURE_ID mapchipnumber);
void DrawTexture(FLOAT x, FLOAT y, FLOAT z, FLOAT rhw, DWORD color, FLOAT tu, FLOAT tv,
	FLOAT width, FLOAT height, FLOAT w_tu, FLOAT h_tv, INT texture);




#endif // !1

