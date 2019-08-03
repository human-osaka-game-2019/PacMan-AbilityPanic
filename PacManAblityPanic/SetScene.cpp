#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"
#include"DrawTexture.h"
#include"Device.h"
#include"SetScene.h"

void DrawSetScene(Pointa* point);
void InitSetScene(Pointa* point);
void UpdateSetScene();
SceneId FinisSetScene();

VariableNumber var;
static bool KeyFlag = false;

TEXTUREDATA SetTextureData;

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
	TextureSize size;

	/*背景*/          Draw(   0 ,   0 ,        1920 ,      1080 ,   0 ,  0 , 1 , 1 , &SetTextureData.m_pTexture[SetTextureList::BackTexture], *point);
	/*難易度選択ロゴ*/Draw( 723 , 142 ,  506 , 114 ,    size.rog_s_tu ,   size.rog_s_tv ,   size.rog_e_tu ,   size.rog_e_tv , &SetTextureData.m_pTexture[SetTextureList::levelselectTexture], *point);
	/*スコアボックス*/Draw( 464 , 336 , 1024 , 329 ,  size.score_s_tu , size.score_s_tv , size.score_e_tu , size.score_e_tv , &SetTextureData.m_pTexture[SetTextureList::levelselectTexture]  , *point);
	/*イージー*/      Draw( 586 , 716 ,  274 , 786 ,   size.easy_s_tu ,  size.easy_s_tv ,  size.easy_e_tu ,  size.easy_e_tv , &SetTextureData.m_pTexture[SetTextureList::levelselectTexture]  , *point);
	/*ノーマル*/      Draw(1092 , 716 ,  586 +  274 , 716 +  86 ,   0 ,  0 , 0 , 0 ,  &SetTextureData.m_pTexture[SetTextureList::levelselectTexture]  , *point);
	/*ヘルプ*/        Draw(1551 ,  55 , 1551 +  274 ,  55 +  86 ,   0 ,  0 , 0 , 0 ,  &SetTextureData.m_pTexture[SetTextureList::levelselectTexture]  , *point);
}


void InitSetScene(Pointa* point)
{
	LoadTexture("Texture/bg1.png", &SetTextureData.m_pTexture[SetTextureList::BackTexture], 0, point);
	LoadTexture("Texture/levelselect.png", &SetTextureData.m_pTexture[SetTextureList::levelselectTexture], 0, point);

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

	for (int a = 0; a < SetTextureList::MaxSetTexture; a++)
	{
		SetTextureData.m_pTexture[a]->Release();
		SetTextureData.m_pTexture[a] = nullptr;
	}

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
