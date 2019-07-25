#ifndef SCENE_H_
#define SCENE_H_

#include "class.h"

SceneId GetCurrentSceneId();

SceneStep GetCurrentSceneStep();

void ChangeSceneStep(SceneStep next_step);

void UpdateScene();

void DrawScene(Pointa point);

#endif // !
