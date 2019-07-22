#include<stdio.h>
#include"Main.h"

extern int g_SceneStep;

void InitGameScene();
void UpdateGameScene();
int FinisGameScene();

void InitGameScene()
{
	printf("ゲームシーンの初期化 \n");

	g_SceneStep = 1;
}

void UpdateGameScene()
{
	printf("ゲームシーンの本編 \n");

	g_SceneStep = 2;
}

int FinisGameScene()
{
	printf("ゲームシーンの終了 \n");

	// 次のシーンの遷移先IDを返す
	return RESULT_SCENE_ID;
}

int GameSceneMain()
{
	switch (g_SceneStep)
	{
		// 初期化
	case 0:
		InitGameScene();
		break;

		// 本編
	case 1:
		UpdateGameScene();
		break;
		// 終了
	case 2:
		return FinisGameScene();
	}
	return GAME_SCENE_ID;
}