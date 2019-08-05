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

#endif