#include<stdio.h>
#include"Main.h"
#include"Scene.h"
#include"class.h"
#include"DrawTexture.h"
#include "Device.h"

void DrawTitleScene(Pointa* point);
void InitTitleScene(Pointa* point);
void UpdateTitleScene();
SceneId FinisTitleScene();

const int MAX_TEXTURE = 10;
TEXTUREDATA texture;
LPDIRECT3DTEXTURE9 pTexture;

SceneId TitleSceneMain(Pointa* point)
{
	switch (GetCurrentSceneStep())
	{
		// 初期化
	case SceneStep::InitStep:
		InitTitleScene(point);
		break;
		// 本編
	case SceneStep::MainStep:
		
			UpdateTitleScene();
		
		break;
		// 終了
	case SceneStep::EndStep:
		return FinisTitleScene();
		break;
	}

	return SceneId::TitleScene;
}

void DrawTitleScene(Pointa* point)
{
	
	//Draw(0, 0, 0, 1, 0xffffffff, 0.0f, 0.0f, 1920, 1080, 0.2f, 0.2f, &pTexture, 0, *point);
	DrawEx(0, 0, 1920, 1080, &pTexture, *point);

}

// 描画設定等
void InitTitleScene(Pointa* point)
{

	LoadTexture("test.png", &pTexture , 0, *point );

	ChangeSceneStep(SceneStep::MainStep);

}

// 次のシーンに行くための条件記入
void UpdateTitleScene()
{

	if (GetKeyStatus(DIK_UP)){
		ChangeSceneStep(SceneStep::EndStep);
	}
}

// 次に飛ぶシーン先の設定
SceneId FinisTitleScene()
{
	// 次のシーンの遷移先IDを返す
	return SceneId::SetScene;
}

