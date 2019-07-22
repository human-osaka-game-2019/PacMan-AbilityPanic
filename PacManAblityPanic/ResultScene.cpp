#include<stdio.h>
#include"Scene.h"

extern int g_SceneStep;

void InitResultScene();
void UpdateResultScene();
int FinisResultScene();

void InitResultScene()
{
	printf("リザルトシーンの初期化 \n");

	g_SceneStep = 1;
}

void UpdateResultScene()
{
	printf("リザルトシーンの本編 \n");

	g_SceneStep = 2;
}

int FinisResultScene()
{
	printf("リザルトシーンの終了 \n");

	// 次のシーンの遷移先IDを返す
	return TITLE_SCENE_ID;
}

int ResultSceneMain()
{
	switch (g_SceneStep)
	{
		// 初期化
	case 0:
		InitResultScene();
		break;

		// 本編
	case 1:
		UpdateResultScene();
		break;
		// 終了
	case 2:
		return FinisResultScene();
	}
	return RESULT_SCENE_ID;
}
