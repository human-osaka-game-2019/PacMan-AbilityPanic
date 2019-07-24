#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"MapLoader.h"


extern int g_SceneStep;
MapchipLoading map;
void DrawGameClearScene();
void InitGameScene();
void UpdateGameScene();
int FinisGameScene();
static int mapdata[23][19];
static int* pMap[23];

int GameSceneMain()
{
	switch (g_SceneStep)
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
	return GAME_SCENE_ID;
}

// 描画設定等
void DrawGameClearScene()
{
}

// テクスチャ読み込み
void InitGameScene()
{
	g_SceneStep = SceneStep::MainStep;
}

// 次のシーンに行くための条件記入
// ゲーム設定記入
void UpdateGameScene()
{

	g_SceneStep = SceneStep::EndStep;
}

// 次に飛ぶシーン先の設定
int FinisGameScene()
{

	// 次のシーンの遷移先IDを返す
	return RESULT_SCENE_ID;
}

