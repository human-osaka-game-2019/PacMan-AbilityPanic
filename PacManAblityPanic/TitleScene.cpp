#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"

void DrawTitleScene();
void InitTitleScene();
void UpdateTitleScene();
SceneId FinisTitleScene();

SceneId TitleSceneMain()
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
	return SceneId::TitleScene;
}

void DrawTitleScene()
{

}

// 描画設定等
void InitTitleScene()
{
	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
void UpdateTitleScene()
{
	ChangeSceneStep(SceneStep::EndStep);
}

// 次に飛ぶシーン先の設定
SceneId FinisTitleScene()
{
	// 次のシーンの遷移先IDを返す
	return SceneId::SetScene;
}

