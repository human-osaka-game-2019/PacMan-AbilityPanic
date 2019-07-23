#ifndef SCENE_H_
#define SCENE_H_

#define TITLE_SCENE_ID (0)
#define GAME_SCENE_ID (1)
#define RESULT_SCENE_ID (2)
#define OPTION_SCENE_ID (3)
void DrawScene();

enum SceneStep
{
	InitStep,			// 初期化
	MainStep,			// メイン
	EndStep,			// 終了
};

#endif // !
