#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"
#include"DrawTexture.h"
#include"Device.h"
// #include"MapLoader.h"

extern int g_SceneStep;
void DrawGameScene(Pointa* point, MapChipData MapData);
void InitGameScene(Pointa*point);
void UpdateGameScene();
SceneId FinisGameScene();


TEXTUREDATA GameTextureData;

SceneId GameSceneMain(Pointa* point)
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep :
		InitGameScene(point);
		break;
		// 本編
	case SceneStep::MainStep:
		UpdateGameScene();
		break;
		// 終了
	case SceneStep::EndStep:
		return FinisGameScene();
	}
	return SceneId::GameScene;
}

// 描画設定等
void DrawGameScene(Pointa* point, MapChipData MapData)
{

	DrawMapChip(point, MapData, &GameTextureData.m_pTexture[GameTextureList::MapChipTexture]);
	//DrawEx(0, 0, 1920, 1080, &GameTextureData.m_pTexture[GameTextureList::MainGameTexture], *point);
	
}

// テクスチャ読み込み
void InitGameScene(Pointa* point)
{
	LoadTexture("Texture/MapChipTEST2.png", &GameTextureData.m_pTexture[GameTextureList::MapChipTexture], 0, point);
	LoadTexture("Texture/GameScene.png", &GameTextureData.m_pTexture[GameTextureList::MainGameTexture], 0, point);

	ChangeSceneStep(SceneStep::MainStep);
}

// 次のシーンに行くための条件記入
// ゲーム設定記入
void UpdateGameScene()
{
	if (GetKeyStatus(DIK_RETURN))
	{
		ChangeSceneStep(SceneStep::EndStep);
	}
	
}

// 次に飛ぶシーン先の設定
SceneId FinisGameScene()
{
	for (int a = 0; a < GameTextureList::MaxGameTexture; a++)
	{
		GameTextureData.m_pTexture[a]->Release();
		GameTextureData.m_pTexture[a] = nullptr;
	}
	// 次のシーンの遷移先IDを返す
	return SceneId::ResultScene;

}

