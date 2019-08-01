#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"
#include"DrawTexture.h"
#include"Device.h"

void InitOptionScene(Pointa* point);
void UpdateOptionScene();
SceneId FinisOptionScene();

TEXTUREDATA OptionTextureData;

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
	DrawEx(0, 0, 1920, 1080, &OptionTextureData.m_pTexture[OptionTextureList::MainOptionTexture], *point);
}

// テクスチャ読み込み
void InitOptionScene(Pointa* point)
{
	LoadTexture("Texture/OptionScene.png", &OptionTextureData.m_pTexture[SetTextureList::BackTexture], 0, point);

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
	for (int a = 0; a < OptionTextureList::MaxOptionTexture; a++)
	{
		OptionTextureData.m_pTexture[a]->Release();
		OptionTextureData.m_pTexture[a] = nullptr;
	}
	// 次のシーンの遷移先IDを返す
	return SceneId::SetScene;
}

