﻿#ifndef ENGINE_H
#define ENGINE_H

#include "class.h"

//Pointa Point;

bool InitEngine(int width, int height, HINSTANCE hInst, Pointa* point);

void EndEngine(Pointa point);

bool DrawStart(Pointa* point);

#endif // !1