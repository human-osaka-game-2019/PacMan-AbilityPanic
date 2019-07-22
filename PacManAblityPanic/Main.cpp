#include <stdio.h>
#include <windows.h>

#include "Main.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ResultScene.h"

int g_SceneStep = 0;

void main()
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
		case GAME_SCENE_ID:
			result_id = GameSceneMain();
			break;
		case RESULT_SCENE_ID:
			result_id = ResultSceneMain();
			break;
		}

		if (current_scene_id != result_id)
		{
			current_scene_id = result_id;

			g_SceneStep = 0;
		}
		Sleep(1000);
	}
}