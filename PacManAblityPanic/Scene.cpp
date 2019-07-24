#include <stdio.h>
#include <windows.h>
#include <d3d9.h>

#include "Engine.h"
#include "class.h"

#include "Main.h"
#include "Scene.h"
#include "TitleScene.h"
#include "SetScene.h"
#include "Option.h"
#include "GameScene.h"
#include "ResultScene.h"

/*
Sceneの流れ
Title -> Set -> Option -> Set -> Game -> Result -> Set

*/

static SceneId g_CurrentSceneId = SceneId::TitleScene;		// 動作中シーンID
static SceneStep g_CurrentSceneStep = SceneStep::InitStep;	// 動作中シーンのステップ

SceneId GetCurrentSceneId()
{
	return g_CurrentSceneId;
}

SceneStep GetCurrentSceneStep()
{
	return g_CurrentSceneStep;
}

void ChangeSceneStep(SceneStep next_step)
{
	g_CurrentSceneStep = next_step;
}

int g_SceneStep = 0;

void UpdateScene()
{
	int current_scene_id = TITLE_SCENE_ID;

	while (true)
	{
		int result_id = current_scene_id;

		switch (current_scene_id)
		{
			// タイトルシーン
		case TITLE_SCENE_ID:
			result_id = TitleSceneMain();
			break;
			// 難易度設定シーン
		case SET_SCENE_ID:
			result_id = SetSceneMain();
			break;
			// 設定、ヘルプシーン
		case OPTION_SCENE_ID:
			result_id = OptionSceneMain();
			break;
			// メインゲームシーン
		case GAME_SCENE_ID:
			result_id = GameSceneMain();
			break;
			// リザルトシーン
		case RESULT_SCENE_ID:
			result_id = ResultSceneMain();
			break;

		}

		DrawScene();

		if (current_scene_id != result_id)
		{
			current_scene_id = result_id;
			g_SceneStep = SceneStep::InitStep;
		}
	}
}

void DrawScene()
{
	LPDIRECT3DDEVICE9 pDinput;
	if (DrawStart() == false)
	{
		return;
	}
	if (g_CurrentSceneStep == SceneStep::MainStep)
	{
		switch (g_CurrentSceneId)
		{
		case SceneId::TitleScene:
			DrawTitleScene();
			break;
		case SceneId::SetScene:
			DrawSetScene();
			break;
		case SceneId::OptionScene:
			DrawOptionScene();
			break;
		case SceneId::GameScene:
			DrawGameScene();
			break;
		case SceneId::ResultScene:
			DrawResultScene();
			break;
		}
	}


	pDinput->EndScene();
	pDinput->Present(NULL, NULL, NULL, NULL);
}
