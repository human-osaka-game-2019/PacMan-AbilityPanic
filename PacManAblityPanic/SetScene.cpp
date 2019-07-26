#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"

void DrawSetScene();
void InitSetScene();
void UpdateSetScene();
SceneId FinisSetScene();

SceneId SetSceneMain()
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep:
		InitSetScene();
		break;
		// 本編
	case SceneStep::MainStep:
		UpdateSetScene();
		break;
		// 終了
	case SceneStep::EndStep:
		return FinisSetScene();
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
	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
void UpdateSetScene()
{
	ChangeSceneStep(SceneStep::EndStep);
}

// 次に飛ぶシーン先の設定
SceneId FinisSetScene()
{
	// 次のシーンの遷移先IDを返す
	// return SceneId::GameScene;

	return SceneId::GameScene;
}
