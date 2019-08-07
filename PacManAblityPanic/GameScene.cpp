#include<stdio.h>
#include<time.h>
#include<random>
#include"Main.h"
#include"Scene.h"
#include"class.h"
#include"DrawTexture.h"
#include"Device.h"
#include"GameScene.h"
#include"GameSystem.h"
#include"GhostAi.h"
#include"CollisionDetection.h"


// #include"MapLoader.h"
WATERY_GHOST watery;
PINK_GHOST pink;
ORANGE_GHOST orange;
RED_GHOST red;
// 描画設定等
PLAYER Pac_man;

extern int g_SceneStep;
void DrawGameScene(Pointa* point, MapChipData MapData);
void InitGameScene(Pointa*point);
void AllCoordinatesInput();
void UpdateGameScene();
void ResetGameScene(Count* count, VariableNumber* var);
void MainGameScene( Count* count,VariableNumber* var,PLAYER* Pac_man);
void KeyCondition( Count* count,VariableNumber* var, PLAYER* Pac_man);
SceneId FinisGameScene();
int* MAPR[22];

TEXTUREDATA GameTextureData;

#define MAP_SIZE_WIDTH (19)	
#define MAP_SIZE_HEIGHT (22)

int MapChipList[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH]
{
	{  5, 23, 23, 23, 23, 23, 23, 23, 23, 34, 23, 23, 23, 23, 23, 23, 23, 23,  4},
	{ 18, 12, 12, 12, 12, 12, 12, 12, 12, 18, 12, 12, 12, 12, 12, 12, 12, 12, 18},
	{ 18, 12, 19, 21, 12, 19, 26, 21, 12, 18, 12, 19, 26, 21, 12, 19, 21, 12, 18},
	{ 18, 12, 22, 20, 12, 22, 25, 20, 12, 14, 12, 22, 25, 20, 12, 22, 20, 12, 18},
	{ 18, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 18},
	{ 18, 12, 17, 15, 12, 16, 12, 17, 23, 34, 23, 15, 12, 16, 12, 17, 15, 12, 18},
	{ 18, 12, 12, 12, 12, 18, 12, 12, 12, 18, 12, 12, 12, 18, 12, 12, 12, 12, 18},
	{ 18, 12, 19, 21, 12, 33, 23, 15,  0, 14,  0, 17, 23, 32, 12, 19, 21, 12, 18},
	{ 18, 12, 24, 27, 12, 18,  0,  0,  0,  0,  0,  0,  0, 18, 12, 24, 27, 12, 18},
	{ 18, 12, 22, 20, 12, 14,  0,  6,  2,  1,  3,  9,  0, 14, 12, 22, 20, 12, 18},
	{ 18, 12, 12, 12, 12,  0,  0, 11,  0,  0,  0, 11,  0,  0, 12, 12, 12, 12, 18},
	{ 18, 12, 19, 21, 12, 16,  0,  8, 10, 10, 10,  7,  0, 16, 12, 19, 21, 12, 18},
	{ 18, 12, 24, 27, 12, 18,  0,  0,  0,  0,  0,  0,  0, 18, 12, 24, 27, 12, 18},
	{ 18, 12, 22, 20, 12, 14,  0, 17, 23, 34, 23, 15,  0, 14, 12, 22, 20, 12, 18},
	{ 18, 12, 12, 12, 12, 12, 12, 12, 12, 18, 12, 12, 12, 12, 12, 12, 12, 12, 18},
	{ 18, 12, 17,  4, 12, 17, 23, 15, 12, 14, 12, 17, 23, 15, 12,  5, 15, 12, 18},
	{ 18, 12, 12, 18, 12, 12, 12, 12, 12,  0, 12, 12, 12, 12, 12, 18, 12, 12, 18},
	{ 33, 15, 12, 14, 12, 16, 12, 17, 23, 34, 23, 15, 12, 16, 12, 14, 12, 17, 32},
	{ 18, 12, 12, 12, 12, 18, 12, 12, 12, 18, 12, 12, 12, 18, 12, 12, 12, 12, 18},
	{ 18, 12, 17, 23, 23, 28, 23, 15, 12, 14, 12, 17, 23, 28, 23, 23, 15, 12, 18},
	{ 18, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 18},
	{  8, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  7},
};



SceneId GameSceneMain(Pointa* point, VariableNumber* var,Count* count)
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep :
		AllCoordinatesInput();
		InitGameScene(point);
		break;
		// 本編
	case SceneStep::MainStep:
		KeyCondition(count,var,&Pac_man);
		MainGameScene(count, var,&Pac_man);
		UpdateGameScene();
		break;
		// 終了
	case SceneStep::EndStep:
		ResetGameScene(count,var);
		return FinisGameScene();
	}
	return SceneId::GameScene;
}



GameTextureSize gts;

void DrawGameScene(Pointa* point, MapChipData MapData)
{

	DrawMapChip(point, MapData, &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], MapChipList);
	Draw(Pac_man.pos_X, Pac_man.pos_Y, Pac_man.TextureSize, Pac_man.TextureSize, Pac_man.pos_Tu, Pac_man.pos_Tv, Pac_man.TuTvSize, Pac_man.TuTvSize, &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], *point);//パックマン
	Draw(red.pos_X, red.pos_Y, 40, 40, 0.4218750000, 0.500000000, 0.0781250000, 0.0781250000, &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], *point);
	Draw(watery.pos_X, watery.pos_Y, 40, 40, 0.4218750000, 0.578125000, 0.0781250000, 0.0781250000, &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], *point);
	Draw(orange.pos_X, orange.pos_Y, 40, 40, 0.4218750000, 0.421875000, 0.0781250000, 0.0781250000, &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], *point);
	Draw(pink.pos_X, pink.pos_Y, 40, 40, 0.4218750000, 0.265625000, 0.0781250000, 0.0781250000, &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], *point);
	
	DrawTest( 104, 290, 300, 300,gts.AbilityFlame_s_tu, gts.AbilityFlame_s_tv, gts.AbilityFlame_e_tu, gts.AbilityFlame_e_tv, &GameTextureData.m_pTexture[GameTextureList::UITexture], *point);
	DrawTest( 194, 380, 120, 120,  gts.AbilityRog_s_tu,   gts.AbilityRog_s_tv,   gts.AbilityRog_e_tu,   gts.AbilityRog_e_tv, &GameTextureData.m_pTexture[GameTextureList::UITexture], *point);
	DrawTest( 458, 856, 102, 102, gts.InitAbility_s_tu,  gts.InitAbility_s_tv,  gts.InitAbility_e_tu,  gts.InitAbility_e_tv, &GameTextureData.m_pTexture[GameTextureList::UITexture], *point);
	DrawTest(1458, 206, 400, 400,        gts.move_s_tu,         gts.move_s_tv,         gts.move_e_tu,         gts.move_e_tv, &GameTextureData.m_pTexture[GameTextureList::UITexture], *point);
	DrawTest(  32,  32, 540, 146,        gts.Test_s_tu,         gts.Test_s_tv,         gts.Test_e_tu,         gts.Test_e_tv, &GameTextureData.m_pTexture[GameTextureList::UITexture], *point);
	DrawTest( 660,  30, 254,  52,        gts.Test_s_tu,         gts.Test_s_tv,         gts.Test_e_tu,         gts.Test_e_tv, &GameTextureData.m_pTexture[GameTextureList::UITexture], *point);
	DrawTest(1554,  20, 346,  70,        gts.Test_s_tu,         gts.Test_s_tv,         gts.Test_e_tu,         gts.Test_e_tv, &GameTextureData.m_pTexture[GameTextureList::UITexture], *point);
	DrawTest(  64, 802, 356,  70,        gts.Test_s_tu,         gts.Test_s_tv,         gts.Test_e_tu,         gts.Test_e_tv, &GameTextureData.m_pTexture[GameTextureList::UITexture], *point);
	DrawTest(  64, 918, 356,  70,        gts.Test_s_tu,         gts.Test_s_tv,         gts.Test_e_tu,         gts.Test_e_tv, &GameTextureData.m_pTexture[GameTextureList::UITexture], *point);
	DrawTest(1458, 666, 398, 398,        gts.Test_s_tu,         gts.Test_s_tv,         gts.Test_e_tu,         gts.Test_e_tv, &GameTextureData.m_pTexture[GameTextureList::UITexture], *point);

	DrawTest(1598, 266, 120, 120,    gts.Up_s_tu,    gts.Up_s_tv,    gts.Up_e_tu,    gts.Up_e_tv, &GameTextureData.m_pTexture[GameTextureList::UITexture], *point);
	DrawTest(1598, 386, 120, 120,  gts.Down_s_tu,  gts.Down_s_tv,  gts.Down_e_tu,  gts.Down_e_tv, &GameTextureData.m_pTexture[GameTextureList::UITexture], *point);
	DrawTest(1478, 386, 120, 120, gts.Right_s_tu, gts.Right_s_tv, gts.Right_e_tu, gts.Right_e_tv, &GameTextureData.m_pTexture[GameTextureList::UITexture], *point);
	DrawTest(1718, 386, 120, 120,  gts.Left_s_tu,  gts.Left_s_tv,  gts.Left_e_tu,  gts.Left_e_tv, &GameTextureData.m_pTexture[GameTextureList::UITexture], *point);

}
  

void AllCoordinatesInput()
{
	Pac_man.Initialize();
	red.CoordinatesInput(958, 440);
	watery.CoordinatesInput(998, 520);
	orange.CoordinatesInput(918, 520);
	pink.CoordinatesInput(958, 520);
}

// テクスチャ読み込み
void InitGameScene(Pointa* point)
{
	srand((unsigned int)time(NULL));
	
	LoadTexture("Texture/MapChipTEST2.png", &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], 0, point);
	LoadTexture("Texture/GameScene.png", &GameTextureData.m_pTexture[GameTextureList::MainGameTexture], 0, point);
	LoadTexture("Texture/maingame.png", &GameTextureData.m_pTexture[GameTextureList::UITexture], 0, point);

	red.Direction_of_travel = 4;
	pink.Direction_of_travel = 3;
	watery.Direction_of_travel = 3;
	orange.Direction_of_travel = 4;
	for (int i = 0; i < 22; i++)
	{
		MAPR[i] = MapChipList[i];
	}
	
	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
// ゲーム設定記入


void UpdateGameScene()
{
	/*
	if (0 > red.pos_X )
	{
		red.pos_X += 1.2;
		MODE = rand() % 4;

	}

	if (0 > red.pos_Y )
	{
		red.pos_Y += 1.2;

		MODE = rand() % 4;
	}
	if (1900 < red.pos_X)
	{
		red.pos_X -= 1.2;
		MODE = rand() % 4;

	}

	if (1060 < red.pos_Y)
	{
		red.pos_Y -= 1.2;
		MODE = rand() % 4;
	}

	if (GetKeyStatus(DIK_W))
	{

		red.pos_Y -= 5;

	}
	if (GetKeyStatus(DIK_S))
	{

		red.pos_Y += 5;
		
	}
	if (GetKeyStatus(DIK_A))
	{

		red.pos_X -= 5;

	}
	if (GetKeyStatus(DIK_D))
	{

		red.pos_X += 5;

	}

	if (GetKeyStatus(DIK_RETURN))
	{
		ChangeSceneStep(SceneStep::EndStep);
	}

	//red.Direction_of_travel = MODE;
	//red.RedGhostUpdate(&red);
	//red.RedNormalMoving(&red);
	if (Pac_man.pos_X <= red.pos_X && Pac_man.pos_Y <= red.pos_Y && Pac_man.pos_X + 40 >= red.pos_X + 40 && Pac_man.pos_Y + 40 >= red.pos_Y + 40)
	{
		ChangeSceneStep(SceneStep::EndStep);
		
	}*/
	
	int RAMD = rand() % 4 + 1;
	
}

// 次に飛ぶシーン先の設定
SceneId FinisGameScene()
{
	for (int a = 0; a < GameTextureList::MaxGameTexture; a++)
	{
		GameTextureData.m_pTexture[a]->Release();
		GameTextureData.m_pTexture[a] = nullptr;
	}
	// 次のシーンの遷移先IDを返す
	return SceneId::ResultScene;

}

// ゲーム内で使用した変数のリセット
void ResetGameScene(Count* count, VariableNumber* var)
{

	var->Keystate = 0;

}

// 各行動時のテクスチャ切り替え
void KeyCondition(Count* count, VariableNumber* var, PLAYER* pac_man)
{
	if ((int)(pac_man->pos_X - 598) % WIDTH_POS == 0 && (int)(pac_man->pos_Y - 120) % HEIGHT_POS == 0)
	{
		if (GetKeyStatus(DIK_UP))
		{

			var->PreviousKeyState = var->Keystate;
			var->Keystate = UP;


		}
		else
			if (GetKeyStatus(DIK_DOWN))
			{

				var->PreviousKeyState = var->Keystate;
				var->Keystate = DOWN;

			}
			else
				if (GetKeyStatus(DIK_RIGHT))
				{

					var->PreviousKeyState = var->Keystate;
					var->Keystate = RIGHT;

				}
				else
					if (GetKeyStatus(DIK_LEFT))
					{
						var->PreviousKeyState = var->Keystate;
						var->Keystate = LEFT;

					}
	}
	EatCookie(var, &Pac_man, MapChipList);
		CharTextureMove(count, var, MapChipList, &Pac_man);
		/*
		int a = (Pac_man.pos_X - 598) / 40;
		int b = ((Pac_man.pos_Y - 120) / 40);
		*/
		if (count->Frame >= 20)
		{
			count->Frame = 0;
		}
	
}

void MainGameScene(Count* count, VariableNumber* var,PLAYER * pac_man)
{
	int RAMD = rand() % 4 + 1;

	Pac_Mon_Move(var, pac_man, MapChipList);
	red.RedGhostUpdate(&red, MAPR, RAMD);
	pink.PinkGhostUpdate(&pink, MAPR, RAMD);
	watery.WateryGhostUpdate(&watery, MAPR, RAMD);
	orange.OrangeGhostUpdate(&orange, MAPR, RAMD);
	
	if (red.pos_X + 10 <= Pac_man.pos_X + 30 && red.pos_Y - 10 < Pac_man.pos_Y + 30 && red.pos_X + 30 >= Pac_man.pos_X +10 && red.pos_Y + 30 >= Pac_man.pos_Y - 10)
	{
		ChangeSceneStep(SceneStep::EndStep);
	}

	if(GetKeyStatus(DIK_P))
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
}