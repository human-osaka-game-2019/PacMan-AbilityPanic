#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"
#include"DrawTexture.h"
#include"Device.h"

void DrawTitleScene(Pointa* point,Count* count);
void InitTitleScene(Pointa* point,Count* count);
void UpdateTitleScene(Pointa* n);
SceneId FinisTitleScene();

TEXTUREDATA TitleTextureData;



SceneId TitleSceneMain(Pointa* point,Count* count)
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep:
		InitTitleScene(point,count);
		break;
		// 本編
	case SceneStep::MainStep:
		
			UpdateTitleScene(point);
		break;
		// 終了
	case SceneStep::EndStep:
		return FinisTitleScene();
		break;
	}

	return SceneId::TitleScene;
}

void DrawTitleScene(Pointa* point,Count* count)
{
	if (60 < count->Frame)
	{
		count->Frame = 0;
	}

	if (count->Frame < 30)
	{
		point->a = 1;
	}
	if (30 < count->Frame && count->Frame < 60)
	{
		point->a = 0;
	}

	if (point->a == 0)
	{
		DrawEx(0, 0, 1920, 1080, &TitleTextureData.m_pTexture[TitleTextureList::MainTitleTexture], *point);
	}
	if (point->a == 1)
	{
		DrawEx(0, 0, 1920, 1080, &TitleTextureData.m_pTexture[TitleTextureList::SabTitleTexture], *point);
	}
	
}

// 描画設定等
void InitTitleScene(Pointa* point,Count* count)
{

	LoadTexture("Texture/taitorunasi.png", &TitleTextureData.m_pTexture[TitleTextureList::MainTitleTexture], 0, point );
	LoadTexture("Texture/Title.png", &TitleTextureData.m_pTexture[TitleTextureList::SabTitleTexture], 0, point);

	count->Frame = 0;

	ChangeSceneStep(SceneStep::MainStep);

}

// 次のシーンに行くための条件記入
void UpdateTitleScene(Pointa* n )
{
	if (GetKeyStatus(DIK_UP))
	{
		n->a = 1;
	}

	if (GetKeyStatus(DIK_DOWN))
	{
		n->a = 0;
	}
	

	if (GetKeyStatus(DIK_RETURN))
	{
		
		ChangeSceneStep(SceneStep::EndStep);
	}
}

// 次に飛ぶシーン先の設定
SceneId FinisTitleScene()
{
	for (int a = 0; a < TitleTextureList::MaxTitleTexture; a++)
	{
		TitleTextureData.m_pTexture[a]->Release();
		TitleTextureData.m_pTexture[a] = nullptr;
	}

// 次のシーンの遷移先IDを返す
	return SceneId::SetScene;
}

