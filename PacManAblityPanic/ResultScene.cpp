#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include "class.h"

extern int g_SceneStep;

void InitResultScene();
void UpdateResultScene();
int FinisResultScene();
void DrawResultScene();

int ResultSceneMain()
{
	switch (g_SceneStep)
	{
		// 初期化
	case SceneStep::InitStep:
		InitResultScene();
		break;

		// 本編
	case SceneStep::MainStep:
		UpdateResultScene();
		break;
		// 終了
	case SceneStep::EndStep:
		return FinisResultScene();
	}
	return RESULT_SCENE_ID;
}

// 描画設定等
void DrawResultScene()
{

}


void InitResultScene()
{
	g_SceneStep = SceneStep::MainStep;
}

// 次のシーンに行くための条件記入
void UpdateResultScene()
{
	g_SceneStep = SceneStep::EndStep;
}

// 次に飛ぶシーン先の設定
int FinisResultScene()
{
	// 次のシーンの遷移先IDを返す
	return SET_SCENE_ID;
}


