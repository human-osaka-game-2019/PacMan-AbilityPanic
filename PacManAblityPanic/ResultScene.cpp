#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include "class.h"

void InitResultScene();
void UpdateResultScene();
SceneId FinisResultScene();
void DrawResultScene();

SceneId ResultSceneMain()
{
	switch (GetCurrentSceneStep())
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
	return SceneId::ResultScene;
}

// 描画設定等
void DrawResultScene()
{

}


void InitResultScene()
{
	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
void UpdateResultScene()
{
	ChangeSceneStep(SceneStep::MainStep);
}

// 次に飛ぶシーン先の設定
SceneId FinisResultScene()
{
	// 次のシーンの遷移先IDを返す
	return SceneId::SetScene;
}


