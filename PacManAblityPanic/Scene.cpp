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

Pointa point;

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

void UpdateScene()
{
	int current_scene_id = SceneId::TitleScene;

	while (true)
	{
		SceneId result_id = g_CurrentSceneId;

		switch (g_CurrentSceneId)
		{
			// タイトルシーン
		case SceneId::TitleScene:
			result_id = TitleSceneMain();
			break;
			// 難易度設定シーン
		case SceneId::SetScene:
			result_id = SetSceneMain();
			break;
			// 設定、ヘルプシーン
		case SceneId::OptionScene:
			result_id = OptionSceneMain();
			break;
			// メインゲームシーン
		case SceneId::GameScene:
			result_id = GameSceneMain();
			break;
			// リザルトシーン
		case SceneId::ResultScene:
			result_id = ResultSceneMain();
			break;

		}

		DrawScene(point);

		if (result_id != g_CurrentSceneId)
		{
			g_CurrentSceneId = result_id;
			ChangeSceneStep(SceneStep::InitStep);
		}
	}
}

void DrawScene(Pointa point)
{
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


	point.pDevice->EndScene();
	point.pDevice->Present(NULL, NULL, NULL, NULL);
}
