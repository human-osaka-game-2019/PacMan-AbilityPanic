#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"

void InitTitleScene();
void UpdateTitleScene();
SceneId FinisTitleScene();

SceneId OptionSceneMain()
{
	switch (GetCurrentSceneStep())
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
	return SceneId::OptionScene;
}

// 描画設定等
void DrawOptionScene()
{

}

// テクスチャ読み込み
void InitOptionScene()
{
	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
void UpdateOptionScene()
{
	ChangeSceneStep(SceneStep::EndStep);
}

// 次に飛ぶシーン先の設定
SceneId FinisOptionScene()
{
	// 次のシーンの遷移先IDを返す
	return SceneId::SetScene;
}

