#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"MapLoader.h"
#include"class.h"


extern int g_SceneStep;
MapchipLoading map;
void DrawGameScene();
void InitGameScene();
void UpdateGameScene();
SceneId FinisGameScene();
static int mapdata[23][19];
static int* pMap[23];

SceneId GameSceneMain()
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep :
		
		for (int i = 0; i < 23; i++)
		{
			pMap[i] = mapdata[i];
		}
		map.mapchip("Test_CSV.csv", 22, 19, pMap);
		InitGameScene();
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
void DrawGameScene()
{
}

// テクスチャ読み込み
void InitGameScene()
{
	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
// ゲーム設定記入
void UpdateGameScene()
{
	ChangeSceneStep(SceneStep::EndStep);
}

// 次に飛ぶシーン先の設定
SceneId FinisGameScene()
{

	// 次のシーンの遷移先IDを返す
	return SceneId::ResultScene;
}

