#include "pch.h"

ModelInfo* skybox = nullptr;

NJS_TEXNAME PAST01BG_TEXNAME[6]{};
NJS_TEXLIST PAST01BG_TEXLIST = { arrayptrandlength(PAST01BG_TEXNAME, Uint32) };

const char* ModelFormatStrings[]
{
	"collision",
	"chunk",
	"battle"
};

ModelInfo* LoadMDL(const char* name, ModelFormat format) {
	std::string fullPath;

	if (format == ModelFormat_Chunk || format == ModelFormat_SA2B)
	{
		fullPath = "resource\\gd_PC\\Models\\";
	}


	if (format == ModelFormat_Basic)
	{
		fullPath = "resource\\gd_PC\\Collisions\\";
	}

	fullPath += name;

	switch (format)
	{
	case ModelFormat_Basic:
		fullPath += ".sa1mdl";
		break;
	case ModelFormat_Chunk:
		fullPath += ".sa2mdl";
		break;
	case ModelFormat_SA2B:
		fullPath += ".sa2bmdl";
		break;
	}

	const char* foo = fullPath.c_str();

	ModelInfo* temp = new ModelInfo(HelperFunctionsGlobal.GetReplaceablePath(foo));

	if (temp->getformat() == format)
	{
		PrintDebug("[Past Garden] Loaded %s model: %s. at %s", ModelFormatStrings[(int)format - 1], name, HelperFunctionsGlobal.GetReplaceablePath(foo));
	}
	else {
		PrintDebug("[Past Garden] Failed loading %s model: %s. at %s", ModelFormatStrings[(int)format - 1], name, HelperFunctionsGlobal.GetReplaceablePath(foo));
	}

	return temp;
}

NJS_VECTOR Skybox_Scale = { 10.0f, 10.0f, 10.0f };
void __cdecl DrawSkyBox(ObjectMaster* obj) {
	SaveControl3D();
	OnControl3D(NJD_CONTROL_3D_NO_CLIP_CHECK);
	OffControl3D(NJD_CONTROL_3D_DEPTH_QUEUE);

	njPushMatrix(0);
	njTranslateV(0, &pCameraLocations[CurrentScreen]->pos);
	njScale(0, 2.0, 2.0, 2.0);
	njSetTexture(&PAST01BG_TEXLIST);
	njScaleV_(&Skybox_Scale);
	DrawObject(skybox->getmodel());
	njScale(0, 1.0, 1.0, 1.0);
	njPopMatrix(1u);

	LoadControl3D();
}


void InitSkybox(const HelperFunctions& helperFunctions) {
	LoadTextureList("skybox", &PAST01BG_TEXLIST);
	WriteJump((ObjectFuncPtr*)0x5DD213, DrawSkyBox);
	skybox = LoadMDL("sky", ModelFormat_Chunk);
	LoadObject((LoadObj)0, "object_00170858", DrawSkyBox, 1)->DisplaySub = DrawSkyBox;
}