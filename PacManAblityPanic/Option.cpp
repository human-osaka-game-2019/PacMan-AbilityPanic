#include<stdio.h>
#include"Main.h"
#include"Scene.h"

extern int g_SceneStep;

void InitTitleScene();
void UpdateTitleScene();
int FinisTitleScene();

int OptionSceneMain()
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
	return OPTION_SCENE_ID;
}

// 描画設定等
void DrawOptionClearScene()
{

}

// テクスチャ読み込み
void OptionScene()
{
	g_SceneStep = SceneStep::MainStep;
}

// 次のシーンに行くための条件記入
void UpdateOptionScene()
{
	g_SceneStep = SceneStep::EndStep;
}

// 次に飛ぶシーン先の設定
int FinisOptionScene()
{
	// 次のシーンの遷移先IDを返す
	return SET_SCENE_ID;
}

