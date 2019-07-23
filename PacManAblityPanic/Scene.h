#ifndef SCENE_H_
#define SCENE_H_

#define TITLE_SCENE_ID (0)
#define SET_SCENE_ID (1)
#define GAME_SCENE_ID (2)
#define RESULT_SCENE_ID (3)
#define OPTION_SCENE_ID (4)

void DrawScene();

enum SceneStep
{
	InitStep,			// 初期化
	MainStep,			// メイン
	EndStep,			// 終了
};

#endif // !
