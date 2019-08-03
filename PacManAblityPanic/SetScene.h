#ifndef _SETSCENE_H_ 
#define _SETSCNEN_H_

SceneId SetSceneMain(Pointa* point);

void DrawSetScene(Pointa* point);

class TextureSize
{
public:
	//////////////////////////////////////////////////////////////
	float rog_s_tu = (float)   7 / 2048;
	float rog_e_tu = (float) 513 / 2048;
	float rog_s_tv = (float) 655 / 1024;
	float rog_e_tv = (float) 769 / 1024;
	//////////////////////////////////////////////////////////////
	float score_s_tu = (float)  0 / 2048;
	float score_e_tu = (float) 1024 / 2048;
	float score_s_tv = (float) 10 / 1024;;
	float score_e_tv = (float)  329 / 1024;
	//////////////////////////////////////////////////////////////
	float easy_s_tu = (float)   7 / 2048;
	float easy_e_tu = (float) 281 / 2048;
	float easy_s_tv = (float) 464 / 1024;
	float easy_e_tv = (float) 550 / 1024;
	/////////////////////////////////////////////////////////////
	float normal_s_tu = (float) 7/2048;
	float normal_e_tu = (float)10/2048;
	float normal_s_tv = (float) 10/ 1024;
	float normal_e_tv = (float)10 / 1024;
};
#endif