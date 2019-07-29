#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"
#include"DrawTexture.h"
#include"Device.h"

void DrawSetScene(Pointa* point);
void InitSetScene(Pointa* point);
void UpdateSetScene();
SceneId FinisSetScene();

SceneId SetSceneMain(Pointa* point)
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep:
		InitSetScene(point);
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
void DrawSetScene(Pointa* point)
{

	DrawEx(0, 0, 1920, 1080, &point->pTexture[TextureList::SetSceneTexture], *point);

}


void InitSetScene(Pointa* point)
{
	LoadTexture("SetScene.png", &point->pTexture[TextureList::SetSceneTexture], 0, *point);

	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
void UpdateSetScene()
{
	if (GetKeyState(DIK_UP))
	{
		ChangeSceneStep(SceneStep::EndStep);
	}

}

// 次に飛ぶシーン先の設定
SceneId FinisSetScene()
{
	
	return SceneId::GameScene;
}
