#ifndef DEVICE_H
#define DEVICE_H

#include "class.h"

HRESULT BuildDxDevice(HWND hInst, Pointa* point);

void UpdateKeyStatus();

bool GetKeyStatus(int KeyNumber);

#endif // !1