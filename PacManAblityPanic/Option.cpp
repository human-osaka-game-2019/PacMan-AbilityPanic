#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"
#include"DrawTexture.h"
#include"Device.h"

void InitOptionScene(Pointa* point);
void UpdateOptionScene();
SceneId FinisOptionScene();

SceneId OptionSceneMain(Pointa* point)
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep:
		InitOptionScene(point);
		break;

		// 本編
	case SceneStep::MainStep:
		UpdateOptionScene();
		break;
		// 終了
	case SceneStep::EndStep:
		return FinisOptionScene();
		break;
	}
	return SceneId::OptionScene;
}

// 描画設定等
void DrawOptionScene(Pointa* point)
{
	DrawEx(0, 0, 1920, 1080, &point->pTexture[TextureList::OptionSceneTexture], *point);
}

// テクスチャ読み込み
void InitOptionScene(Pointa* point)
{
	LoadTexture("Texture/OptionScene.png", &point->pTexture[TextureList::OptionSceneTexture], 0, *point);

	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
void UpdateOptionScene()
{
	if (GetKeyStatus(DIK_RETURN))
	{
		ChangeSceneStep(SceneStep::EndStep);
	}

}

// 次に飛ぶシーン先の設定
SceneId FinisOptionScene()
{
	// 次のシーンの遷移先IDを返す
	return SceneId::SetScene;
}

