#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"
#include"DrawTexture.h"
#include"Device.h"
// #include"MapLoader.h"

extern int g_SceneStep;
void DrawGameScene(Pointa* point, MapChipData MapData);
void InitGameScene(Pointa*point);
void UpdateGameScene();
void MainGameScene();
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
	{ 18, 12, 12, 18, 12, 12, 12, 12, 12, 40, 12, 12, 12, 12, 12, 18, 12, 12, 18},
	{ 33, 15, 12, 14, 12, 16, 12, 17, 23, 34, 23, 15, 12, 16, 12, 14, 12, 17, 32},
	{ 18, 12, 12, 12, 12, 18, 12, 12, 12, 18, 12, 12, 12, 18, 12, 12, 12, 12, 18},
	{ 18, 12, 17, 23, 23, 28, 23, 15, 12, 14, 12, 17, 23, 28, 23, 23, 15, 12, 18},
	{ 18, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 18},
	{  8, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  7},
};



SceneId GameSceneMain(Pointa* point)
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep :
		InitGameScene(point);
		break;
		// 本編
	case SceneStep::MainStep:
		MainGameScene();
		UpdateGameScene();
		break;
		// 終了
	case SceneStep::EndStep:
		return FinisGameScene();
	}
	return SceneId::GameScene;
}

// 描画設定等
void DrawGameScene(Pointa* point, MapChipData MapData)
{

	DrawMapChip(point, MapData, &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], MapChipList);
	//DrawEx(0, 0, 1920, 1080, &GameTextureData.m_pTexture[GameTextureList::MainGameTexture], *point);
	
}

// テクスチャ読み込み
void InitGameScene(Pointa* point)
{
	LoadTexture("Texture/MapChipTEST2.png", &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], 0, point);
	LoadTexture("Texture/GameScene.png", &GameTextureData.m_pTexture[GameTextureList::MainGameTexture], 0, point);

	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
// ゲーム設定記入
void UpdateGameScene()
{
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

void MainGameScene()
{

}
