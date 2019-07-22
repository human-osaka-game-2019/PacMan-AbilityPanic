#include<stdio.h>
#include"Main.h"

extern int g_SceneStep;

void InitTitleScene();
void UpdateTitleScene();
int FinisTitleScene();

void InitTitleScene()
{
	printf("タイトルシーンの初期化 \n");

	g_SceneStep = 1;
}

void UpdateTitleScene()
{
	printf("タイトルシーンの本編 \n");

	g_SceneStep = 2;
}

int FinisTitleScene()
{
	printf("タイトルシーンの終了 \n");

	// 次のシーンの遷移先IDを返す
	return GAME_SCENE_ID;
}


int TitleSceneMain()
{
	switch (g_SceneStep)
	{
		// 初期化
	case 0:
		InitTitleScene();
		break;

		// 本編
	case 1:
		UpdateTitleScene();
		break;
		// 終了
	case 2:
		return FinisTitleScene();
		break;
	}
	return TITLE_SCENE_ID;
}
