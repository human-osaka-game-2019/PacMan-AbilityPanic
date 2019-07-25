#ifndef DRAWTEXTURE
#define DRAWTEXTURE

bool LoadTexture(const char* file_name, int SceneId , int mapchipnumber,int TextureWidth ,int TextureHeight);

void DrawTexture(float x, float y,float width, float height,TEXTUREDATA* texture);

void DrawTextureEx(float x, float y, float tu, float tv, float width, float height, TEXTUREDATA* texture);

TEXTUREDATA* GetTexture(int SceneId, int SelectTexture);

#endif // !1

