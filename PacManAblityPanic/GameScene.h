#ifndef _GAMESCENE_H_ 
#define _GAMESCENE_H_


SceneId GameSceneMain(Pointa* point, VariableNumber* var, Count* count);

void DrawGameScene(Pointa* point,MapChipData Mapdata);

enum 
{
	KeyStatus,
	UP,
	DOWN,
	RIGHT,
	LEFT,
};

class PLAYER
{
public:

	float pos_X; // 描画のX座標
	float pos_Y; // 描画のY座標

	float pos_Tu; // 統合画像から切り取った時のX座標
	float pos_Tv; // 統合画像から切り取った時のY座標

	float TextureSize; // テクスチャの大きさ
	float TuTvSize  = 0.078125;    // 統合画像から切り取った時の大きさ


	void CoordinatesInput(float x, float y)
	{
		pos_X = x;
		pos_Y = y;
	};

	void Initialize()
	{
	
		pos_X = 958;
		pos_Y = 760;
		pos_Tu = 0.03125;
		pos_Tv = 0.265625;

		TextureSize = 40;
		TuTvSize = 0.078125;
	}

};

class ENEMY : public PLAYER
{
public:

};

class GameTextureSize
{
public:
	////////////////////////////////////////////
	float AbilityFlame_s_tu = (float)   0 / 1024;
	float AbilityFlame_e_tu = (float) 296 / 1024;
	float AbilityFlame_s_tv = (float) 415 / 1024;
	float AbilityFlame_e_tv = (float) 711 / 1024;
	////////////////////////////////////////////
	float AbilityRog_s_tu   = (float)   0 / 1024;
	float AbilityRog_e_tu   = (float) 120 / 1024;
	float AbilityRog_s_tv   = (float) 725 / 1024;
	float AbilityRog_e_tv   = (float) 845 / 1024;
	float AbilityRog_s_tu2  = (float) 120 / 1024;
	float AbilityRog_e_tu2  = (float) 240 / 1024;
	////////////////////////////////////////////
	float move_s_tu         = (float)   0 / 1024;
	float move_e_tu         = (float) 402 / 1024;
	float move_s_tv         = (float)   0 / 1024;
	float move_e_tv         = (float) 402 / 1024;
	////////////////////////////////////////////
	float InitAbility_s_tu  = (float) 410 / 1024;
	float InitAbility_e_tu  = (float) 512 / 1024;
	float InitAbility_s_tv  = (float)   0 / 1024;
	float InitAbility_e_tv  = (float) 102 / 1024;
	////////////////////////////////////////////
	float Up_s_tu           = (float) 535 / 1024;
	float Up_e_tu           = (float) 655 / 1024;
	float Up_s_tv           = (float) 360 / 1024;
	float Up_e_tv           = (float) 480 / 1024;
	float Up_s_tu2          = (float) 655 / 1024;
	float Up_e_tu2          = (float) 775 / 1024;
	////////////////////////////////////////////
	float Down_s_tu         = (float) 535 / 1024;
	float Down_e_tu         = (float) 655 / 1024;
	float Down_s_tv         = (float) 120 / 1024;
	float Down_e_tv         = (float) 240 / 1024;
	float Down_s_tu2        = (float) 655 / 1024;
	float Down_e_tu2        = (float) 775 / 1024;
	////////////////////////////////////////////
	float Right_s_tu        = (float) 535 / 1024; 
	float Right_e_tu        = (float) 655 / 1024; 
	float Right_s_tv        = (float)   0 / 1024; 
	float Right_e_tv        = (float) 120 / 1024; 
	float Right_s_tu2       = (float) 655 / 1024;
	float Right_e_tu2       = (float) 775 / 1024;
	////////////////////////////////////////////
	float Left_s_tu         = (float) 535 / 1024;
	float Left_e_tu         = (float) 655 / 1024;
	float Left_s_tv         = (float) 240 / 1024;
	float Left_e_tv         = (float) 360 / 1024;
	float Left_s_tu2        = (float) 655 / 1024;
	float Left_e_tu2        = (float) 775 / 1024;
	////////////////////////////////////////////
	float Test_s_tu         = (float) 900 / 1024;
	float Test_e_tu         = (float) 900 / 1024;
	float Test_s_tv         = (float) 900 / 1024;
	float Test_e_tv         = (float) 900 / 1024;
};
#endif