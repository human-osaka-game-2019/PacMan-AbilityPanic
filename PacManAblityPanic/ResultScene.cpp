#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"
#include"DrawTexture.h"
#include"Device.h"

void InitResultScene(Pointa* point);
void UpdateResultScene();
SceneId FinisResultScene();
void DrawResultScene(Pointa* point);

SceneId ResultSceneMain(Pointa* point)
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep:
		InitResultScene(point);
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
void DrawResultScene(Pointa* point)
{
	DrawEx(0, 0, 1920, 1080, &point->pTexture[TextureList::GameSceneTexture], *point);
}


void InitResultScene(Pointa* point)
{
	LoadTexture("Texture/ResultScene.png", &point->pTexture[TextureList::GameSceneTexture], 0, *point);

	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
void UpdateResultScene()
{
	if (GetKeyStatus(DIK_RETURN))
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
}

// 次に飛ぶシーン先の設定
SceneId FinisResultScene()
{
	// 次のシーンの遷移先IDを返す
	return SceneId::SetScene;
}


