﻿#ifndef DEVICE_H
#define DEVICE_H

#include "class.h"

HRESULT BuildDxDevice(HWND hInst);

void UpdateKeyStatus();

bool GetKeyStatus(int KeyNumber);

#endif // !1