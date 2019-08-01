#ifndef _SETSCENE_H_ 
#define _SETSCNEN_H_

SceneId SetSceneMain(Pointa* point);

void DrawSetScene(Pointa* point);

class TextureSize
{
private:
	float tex_h = 2048;
	float tex_w = 1024;
	///////////////////////////////
	float rog_s_x = 7;
	float rog_s_y = 655;
	float rog_siz_h = 513;
	float rog_siz_w = 769;
	//////////////////////////////
	float score_s_x = 0;
	float score_e_y = 10;
	float score_siz_h = 1024;
	float score_siz_w = 339;

public:
	float rog_s_tu = rog_s_x / tex_h;  
	float rog_e_tu = rog_siz_h / tex_h;  
	float rog_s_tv = rog_s_y / tex_w;  
	float rog_e_tv = rog_siz_w / tex_w;  

};
#endif