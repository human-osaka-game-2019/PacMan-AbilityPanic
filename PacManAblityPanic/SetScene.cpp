﻿#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"

extern int g_SceneStep;

void DrawSetScene();
void InitTitleScene();
void UpdateTitleScene();
SceneId FinisTitleScene();

SceneId SetSceneMain()
{
	switch (g_SceneStep)
	{
		// 初期化
	case SceneStep::InitStep:
		InitTitleScene();
		break;
		// 本編
	case SceneStep::MainStep:
		UpdateTitleScene();
		break;
		// 終了
	case SceneStep::EndStep:
		return FinisTitleScene();
		break;
	}
	return SceneId::SetScene;
}

// 描画設定等
void DrawSetScene()
{

}


void InitSetScene()
{
	g_SceneStep = SceneStep::MainStep;
}

// 次のシーンに行くための条件記入
void UpdateSetScene()
{

	g_SceneStep = SceneStep::EndStep;
}

// 次に飛ぶシーン先の設定
SceneId FinisSetScene()
{
	// 次のシーンの遷移先IDを返す
	// return OPTION_SCENE_ID;

	return SceneId::GameScene;
}
