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

Variable var;
static bool KeyFlag = false;

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
	LoadTexture("Texture/SetScene.png", &point->pTexture[TextureList::SetSceneTexture], 0, *point);

	var.SceneSelect = 1;

	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
void UpdateSetScene()
{
	if (GetKeyStatus(DIK_UP))
	{
		KeyFlag = true;
		var.SceneSelect = 0;

	}
	
	if (GetKeyStatus(DIK_LEFT))
	{
		KeyFlag = true;
		var.SceneSelect = 1;
	}

	if (GetKeyStatus(DIK_RIGHT))
	{
		KeyFlag = true;
		var.SceneSelect = 1;
	}

	if (KeyFlag == true)
	{
		if (GetKeyStatus(DIK_RETURN))
		{
			ChangeSceneStep(SceneStep::EndStep);
		}
	}

}

// 次に飛ぶシーン先の設定
SceneId FinisSetScene()
{
	switch (var.SceneSelect)
	{
	case 0:
		return SceneId::OptionScene;
		break;
	case 1:
		return SceneId::GameScene;
		break;
	}
	
}
