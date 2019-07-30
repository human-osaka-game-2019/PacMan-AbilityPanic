#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"
#include"DrawTexture.h"
#include"Device.h"
// #include"MapLoader.h"

extern int g_SceneStep;
void DrawGameScene(Pointa* point);
void InitGameScene(Pointa*point);
void UpdateGameScene();
SceneId FinisGameScene();

// static int mapdata[23][19];
// static int* pMap[23];
// MapchipLoading map;
SceneId GameSceneMain(Pointa* point)
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep :
	/*	
		for (int i = 0; i < 23; i++)
		{
			pMap[i] = mapdata[i];
		}
		map.mapchip("Test_CSV.csv", 22, 19, pMap);
		map.textureprint(pMap,22,19);*/
		InitGameScene(point);
		break;
		// 本編
	case SceneStep::MainStep:
		UpdateGameScene();
		break;
		// 終了
	case SceneStep::EndStep:
		return FinisGameScene();
	}
	return SceneId::GameScene;
}

// 描画設定等
void DrawGameScene(Pointa* point)
{
	DrawEx(0, 0, 1920, 1080, &point->pTexture[TextureList::GameSceneTexture], *point);
}

// テクスチャ読み込み
void InitGameScene(Pointa* point)
{
	LoadTexture("Texture/GameScene.png", &point->pTexture[TextureList::GameSceneTexture], 0, *point);

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
	// 次のシーンの遷移先IDを返す
	return SceneId::ResultScene;
}

