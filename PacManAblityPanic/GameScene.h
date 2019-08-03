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

	float pos_X;
	float pos_Y;

};

class ENEMY : public PLAYER 
{
public:

};

#endif