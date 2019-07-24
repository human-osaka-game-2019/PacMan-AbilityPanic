#include <stdio.h>
#include <windows.h>
#include <d3d9.h>

#include "Main.h"
#include "Scene.h"
#include "TitleScene.h"
#include "SetScene.h"
#include "Option.h"
#include "GameScene.h"
#include "ResultScene.h"

/*
Sceneの流れ
Title -> Set -> Option -> Set -> Game -> Result
 or Game -> Re
*/

int g_SceneStep = 0;

void UpdateScene()
{
	int current_scene_id = TITLE_SCENE_ID;

	while (true)
	{
		int result_id = current_scene_id;

		switch (current_scene_id)
		{
		case TITLE_SCENE_ID:
			result_id = TitleSceneMain();
			break;
		case SET_SCENE_ID:
			result_id = SetSceneMain();
			break;
		case GAME_SCENE_ID:
			result_id = GameSceneMain();
			break;
		case RESULT_SCENE_ID:
			result_id = ResultSceneMain();
			break;
		case OPTION_SCENE_ID:
			result_id = OptionSceneMain();
		}

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
		case 0:
			DrawGameScene();
			break;
		case 1:
			DrawGameClearScene();
			break;
		case 2:
			DrawGameOverScene();
			break;
		case 3:
			DrawHelpScene();
			break;
		}
	}


	pDinput->EndScene();
	pDinput->Present(NULL, NULL, NULL, NULL);
}
