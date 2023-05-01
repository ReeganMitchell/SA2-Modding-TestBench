#pragma once
#include "SA2ModLoader.h"

extern HelperFunctions HelperFunctionsGlobal;

void InitSkybox(const HelperFunctions& helperFunctions);
void __cdecl DrawSkyBox(ObjectMaster* obj);
LoopHead** GetPaths();