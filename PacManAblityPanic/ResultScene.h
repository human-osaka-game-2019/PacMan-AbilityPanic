#ifndef _RESULTSCENE_H_ 
#define _RESULTSCNEN_H_

SceneId ResultSceneMain(Pointa* point);

void DrawResultScene(Pointa* point,Count* count);

class ResultTextureSize
{
public:
	//////////////////////////////////////////
	float Score_s_tu  = (float)      5 / 2048;
	float Score_e_tu  = (float)    945 / 2048;
	float Score_s_tv  = (float)    820 / 1024;
	float Score_e_tv  = (float)    990 / 1024;
	//////////////////////////////////////////
	float HighScore_s_tu = (float) 680 / 2048;
	float HighScore_e_tu = (float) 1789/ 2048;
	float HighScore_s_tv = (float) 360 / 1024;
	float HighScore_e_tv = (float) 530 / 1024;
	//////////////////////////////////////////
	float Result_s_tu  = (float)   565 / 2048;
	float Result_e_tu  = (float)  1803 / 2048;
	float Result_s_tv  = (float)   560 / 1024;
	float Result_e_tv  = (float)   779 / 1024;
	//////////////////////////////////////////
	float Level_s_tu  = (float)      0 / 2048;
	float Level_e_tu  = (float)    322 / 2048;
	float Level_s_tv  = (float)    160 / 1024;
	float Level_e_tv  = (float)    221 / 1024;
	float Level_s_tu2 = (float)    322 / 2048;
	float Level_e_tu2 = (float)    644 / 2048;
	//////////////////////////////////////////
};

#endif 