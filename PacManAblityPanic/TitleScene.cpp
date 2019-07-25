﻿#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"

extern int g_SceneStep;
void DrawTitleScene();
void InitTitleScene();
void UpdateTitleScene();
SceneId FinisTitleScene();

SceneId TitleSceneMain()
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
	return SceneId::TitleScene;
}

void DrawTitleScene()
{

}

// 描画設定等
void InitTitleScene()
{
	g_SceneStep = SceneStep::MainStep;
}

// 次のシーンに行くための条件記入
void UpdateTitleScene()
{

	g_SceneStep = SceneStep::EndStep;
}

// 次に飛ぶシーン先の設定
SceneId FinisTitleScene()
{
	// 次のシーンの遷移先IDを返す
	return SceneId::SetScene;
}

