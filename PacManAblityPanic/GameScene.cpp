#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"
#include"DrawTexture.h"
#include"Device.h"
#include"GameScene.h"
#include"GameSystem.h"
#include"GhostAi.h"


// #include"MapLoader.h"
WATERY_GHOST watery;
PINK_GHOST pink;
ORANGE_GHOST orange;
RED_GHOST red;

extern int g_SceneStep;
void DrawGameScene(Pointa* point, MapChipData MapData);
void InitGameScene(Pointa*point);
void UpdateGameScene();
void ResetGameScene(Count* count);
void MainGameScene( Count* count,VariableNumber* var);
void KeyCondition( Count* count,VariableNumber* var);
SceneId FinisGameScene();

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
	{ 18, 12, 24, 27, 12, 18,  0,  0,  0, 77,  0,  0,  0, 18, 12, 24, 27, 12, 18},
	{ 18, 12, 22, 20, 12, 14,  0,  6,  2,  1,  3,  9,  0, 14, 12, 22, 20, 12, 18},
	{ 18, 12, 12, 12, 12,  0,  0, 11, 65, 41, 89, 11,  0,  0, 12, 12, 12, 12, 18},
	{ 18, 12, 19, 21, 12, 16,  0,  8, 10, 10, 10,  7,  0, 16, 12, 19, 21, 12, 18},
	{ 18, 12, 24, 27, 12, 18,  0,  0,  0,  0,  0,  0,  0, 18, 12, 24, 27, 12, 18},
	{ 18, 12, 22, 20, 12, 14,  0, 17, 23, 34, 23, 15,  0, 14, 12, 22, 20, 12, 18},
	{ 18, 12, 12, 12, 12, 12, 12, 12, 12, 18, 12, 12, 12, 12, 12, 12, 12, 12, 18},
	{ 18, 12, 17,  4, 12, 17, 23, 15, 12, 14, 12, 17, 23, 15, 12,  5, 15, 12, 18},
	{ 18, 12, 12, 18, 12, 12, 12, 12, 12, 36, 12, 12, 12, 12, 12, 18, 12, 12, 18},
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
		InitGameScene(point);
		break;
		// 本編
	case SceneStep::MainStep:
		KeyCondition(count,var);
		MainGameScene(count, var);
		UpdateGameScene();
		break;
		// 終了
	case SceneStep::EndStep:
		ResetGameScene(count);
		return FinisGameScene();
	}
	return SceneId::GameScene;
}

// 描画設定等
PLAYER Pac_man;



void DrawGameScene(Pointa* point, MapChipData MapData)
{


	DrawMapChip(point, MapData, &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], MapChipList);
	Draw(Pac_man.pos_X, Pac_man.pos_Y, 40, 40, 0.0312500000, 0.265625000, 0.0781250000, 0.0781250000, &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], *point);//パックマン
	Draw(red.pos_X, red.pos_Y, 40, 40, 0.4218750000, 0.500000000, 0.0781250000, 0.0781250000, &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], *point);
	Draw(watery.pos_X, watery.pos_Y, 40, 40, 0.4218750000, 0.578125000, 0.0781250000, 0.0781250000, &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], *point);
	Draw(orange.pos_X, orange.pos_Y, 40, 40, 0.4218750000, 0.421875000, 0.0781250000, 0.0781250000, &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], *point);
	Draw(pink.pos_X, pink.pos_Y, 40, 40, 0.4218750000, 0.265625000, 0.0781250000, 0.0781250000, &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], *point);

	//DrawEx(0, 0, 1920, 1080, &GameTextureData.m_pTexture[GameTextureList::MainGameTexture], *point);
	
}

// テクスチャ読み込み
void InitGameScene(Pointa* point)
{
	LoadTexture("Texture/MapChipTEST2.png", &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], 0, point);
	LoadTexture("Texture/GameScene.png", &GameTextureData.m_pTexture[GameTextureList::MainGameTexture], 0, point);
	red.pos_X = 40;
	red.pos_Y = 0;
	watery.pos_X = 80;
	watery.pos_Y = 0;
	orange.pos_X = 120;
	orange.pos_Y = 0;
	pink.pos_X = 160;
	pink.pos_Y = 0;
	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
// ゲーム設定記入
void UpdateGameScene()
{
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
void ResetGameScene(Count* count)
{

}

// 各行動時のテクスチャ切り替え
void KeyCondition(Count* count, VariableNumber* var)
{
	if (GetKeyStatus(DIK_UP))
	{
		var->Keystate = UP;
	}else
		if (GetKeyStatus(DIK_DOWN))
		{
			var->Keystate = DOWN;
		}else
			if (GetKeyStatus(DIK_RIGHT))
			{
				var->Keystate = RIGHT;
			}else
				if (GetKeyStatus(DIK_LEFT))
				{
					var->Keystate = LEFT;
				}

			CharTextureMove(count, var, MapChipList);

			if (count->Frame >= 20)
			{
				count->Frame = 0;
			}
}

void MainGameScene(Count* count, VariableNumber* var)
{

	

}