#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"
#include"DrawTexture.h"
#include"Device.h"
#include"SetScene.h"

void DrawSetScene(Pointa* point,Count* count, VariableNumber* var);
void SetTexture(Pointa* point, Count* count, VariableNumber* var);
void InitSetScene(Pointa* point);
void ResetSetScene(Count* count ,VariableNumber* var);
void UpdateSetScene();
SceneId FinisSetScene();

VariableNumber var;
static bool KeyFlag = false;

TEXTUREDATA SetTextureData;

SceneId SetSceneMain(Pointa* point,Count* count, VariableNumber* var)
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep:
		InitSetScene(point);
		break;
		// 本編
	case SceneStep::MainStep:
		SetTexture(point, count, var);
		UpdateSetScene();
		break;
		// 終了
	case SceneStep::EndStep:
		ResetSetScene(count, var);
		return FinisSetScene();
		break;
	}
	return SceneId::SetScene;
}

void SetTexture(Pointa* point, Count* count, VariableNumber* var)
{
	if (count->Frame < 20)
	{
		point->a = 1;
	}else
		if (20 < count->Frame && count->Frame < 40)
		{
			point->a = 0;
		}
	if (count->Frame > 40)
	{
		count->Frame = 0;
	}

	if (GetKeyStatus(DIK_RIGHT))
	{
		var->Keystate = 0;
	}else
		if (GetKeyStatus(DIK_LEFT))
		{
			var->Keystate = 1;
		}else
			if (GetKeyStatus(DIK_UP))
			{
				var->Keystate = 2;
			}

}

// 描画設定等
void DrawSetScene(Pointa* point,Count* count, VariableNumber* var)
{
	TextureSize size;
	
	/*背景*/          Draw(   0 ,   0 ,        1920 ,      1080 ,   0 ,  0 , 1 , 1 , &SetTextureData.m_pTexture[SetTextureList::BackTexture], *point);
	/*難易度選択ロゴ*/DrawTest( 723 , 142 ,  506 , 114 ,    size.rog_s_tu ,    size.rog_s_tv ,    size.rog_e_tu ,    size.rog_e_tv , &SetTextureData.m_pTexture[SetTextureList::levelselectTexture]  , *point);
	/*スコアボックス*/DrawTest( 464 , 336 , 1024 , 329 ,  size.score_s_tu ,  size.score_s_tv ,  size.score_e_tu ,  size.score_e_tv , &SetTextureData.m_pTexture[SetTextureList::levelselectTexture]  , *point);
	
	DrawTest(1092, 816, 274, 86, size.normal_s_tu2, size.normal_s_tv, size.normal_e_tu2, size.normal_e_tv, &SetTextureData.m_pTexture[SetTextureList::levelselectTexture], *point);
	DrawTest(586, 816, 274, 86, size.easy_s_tu2, size.easy_s_tv, size.easy_e_tu2, size.easy_e_tv, &SetTextureData.m_pTexture[SetTextureList::levelselectTexture], *point);
	DrawTest(1551, 55, 274, 86, size.help_s_tu2, size.help_s_tv, size.help_e_tu2, size.help_e_tv, &SetTextureData.m_pTexture[SetTextureList::levelselectTexture], *point);
	
	switch (var->Keystate)
	{
	case 0:/*ノーマル*/ 
		if (point->a == 0)
		{
			DrawTest(1092, 816, 274, 86, size.normal_s_tu, size.normal_s_tv, size.normal_e_tu, size.normal_e_tv, &SetTextureData.m_pTexture[SetTextureList::levelselectTexture], *point);
		}
			
		break;

	case 1:/*イージー*/
		if (point->a == 0)
		{
			DrawTest(586, 816, 274, 86, size.easy_s_tu, size.easy_s_tv, size.easy_e_tu, size.easy_e_tv, &SetTextureData.m_pTexture[SetTextureList::levelselectTexture], *point);
		}

	break;
	
	case 2:/*ヘルプ*/
		if (point->a == 0)
		{
			DrawTest(1551, 55, 274, 86, size.help_s_tu, size.help_s_tv, size.help_e_tu, size.help_e_tv, &SetTextureData.m_pTexture[SetTextureList::levelselectTexture], *point);
		}
		break;
	}

}
void ResetSetScene(Count* count, VariableNumber* var)
{
	var->Keystate = 0;
};

void InitSetScene(Pointa* point)
{
	LoadTexture("Texture/bg1.png", &SetTextureData.m_pTexture[SetTextureList::BackTexture], 0, point);
	LoadTexture("Texture/result_file.png", &SetTextureData.m_pTexture[SetTextureList::levelselectTexture], 0, point);

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
