#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"
#include"DrawTexture.h"
#include"Device.h"
#include"ResultScene.h"

void InitResultScene(Pointa* point);
void UpdateResultScene();
SceneId FinisResultScene();
void DrawResultScene(Pointa* point,Count* count);

TEXTUREDATA ResultTextureData;
ResultTextureSize rts;

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
void DrawResultScene(Pointa* point,Count* count)
{
	DrawEx(0, 0, 1920, 1080, &ResultTextureData.m_pTexture[ResultTextureList::BackResultTexture], *point);
	DrawTest(325, 0, 1238, 219, rts.Result_s_tu, rts.Result_s_tv, rts.Result_e_tu, rts.Result_e_tv, &ResultTextureData.m_pTexture[ResultTextureList::Sabtexture], *point);
	DrawTest(0, 240, 1109, 170, rts.HighScore_s_tu, rts.HighScore_s_tv, rts.HighScore_e_tu, rts.HighScore_e_tv, &ResultTextureData.m_pTexture[ResultTextureList::Sabtexture], *point);
	DrawTest(0, 500, 1109, 170, rts.Score_s_tu, rts.Score_s_tv, rts.Score_e_tu, rts.Score_e_tv, &ResultTextureData.m_pTexture[ResultTextureList::Sabtexture], *point);
	if (count->Frame < 20)
	{
		point->a = 1;
	}
	if (20 < count->Frame && count->Frame < 40)
	{
		point->a = 0;
	}
	if (point->a == 0)
	{
		DrawTest(1178, 830, 698, 147, rts.Level_s_tu, rts.Level_s_tv, rts.Level_e_tu, rts.Level_e_tv, &ResultTextureData.m_pTexture[ResultTextureList::SelectTexture], *point);
	}
	if (point->a == 1)
	{
		DrawTest(1178, 830, 698, 147, rts.Level_s_tu2, rts.Level_s_tv, rts.Level_e_tu2, rts.Level_e_tv, &ResultTextureData.m_pTexture[ResultTextureList::SelectTexture], *point);
	}
	if (count->Frame > 40)
	{
		count->Frame = 0;
	}
}

void InitResultScene(Pointa* point)
{
	LoadTexture("Texture/help_tougou.png", &ResultTextureData.m_pTexture[ResultTextureList::SelectTexture], 0, point);
	LoadTexture("Texture/result_file.png", &ResultTextureData.m_pTexture[ResultTextureList::Sabtexture], 0, point);
	LoadTexture("Texture/bg1.png", &ResultTextureData.m_pTexture[ResultTextureList::BackResultTexture], 0, point);

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
	for (int a = 0; a < ResultTextureList::MaxResultTexture; a++)
	{
		ResultTextureData.m_pTexture[a]->Release();
		ResultTextureData.m_pTexture[a] = nullptr;
	}
	// 次のシーンの遷移先IDを返す
	return SceneId::SetScene;
}


