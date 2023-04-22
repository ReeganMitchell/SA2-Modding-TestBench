#include "pch.h"

HelperFunctions HelperFunctionsGlobal;

LandTableInfo* CurrentLandTableInfo = nullptr;

NJS_TEXNAME customlevel_texnames[1];
NJS_TEXLIST customlevel_texlist = { arrayptrandlength(customlevel_texnames) };

NJS_TEXNAME PAST01BG_TEXNAME[9]{};
NJS_TEXLIST PAST01BG_TEXLIST = { arrayptrandlength(PAST01BG_TEXNAME, Uint32) };

ModelInfo* skybox = nullptr;
NJS_OBJECT* skybox_top;
NJS_OBJECT* skybox_bottom;

void LoadLevelMusic(char* name) {
	char character;
	int c = 0;

	do {
		character = name[c];
		CurrentSongName[c++] = character;
	} while (character);

	PlayMusic(name);
	ResetMusic();
}

void LoadLandTable(const char* path, LandTableFormat format, NJS_TEXLIST* texlist, const char* texname) {

	CurrentLandTableInfo = new LandTableInfo(HelperFunctionsGlobal.GetReplaceablePath(path));
	LandTable* landtable = CurrentLandTableInfo->getlandtable();

	if (landtable == nullptr) {
		PrintDebug("bad path");
		PrintDebug(path);
	}
	landtable->TextureList = texlist;
	landtable->TextureName = (char*)texname;


	LoadLandManager(landtable);

	LandTableSA2BModels = format == LandTableFormat_SA2B ? true : false;
}

void UnloadLandTable() {
	if (CurrentLandTableInfo) {
		delete CurrentLandTableInfo;
		CurrentLandTableInfo = nullptr;
		CurrentLandTable = nullptr;
	}
}

NJS_VECTOR Skybox_Scale = { 1.4f, 1.4f, 1.4f };
DataPointer(int, playerNum, 0x1DD92A0);
DataArray(NJS_VECTOR*, CameraPosPtrs, 0x1DD92B0, 2);
void __cdecl DrawSkyBox(NJS_VECTOR* position) {
	NJS_VECTOR* v2 = CameraPosPtrs[playerNum];
	SaveControl3D();
	OnControl3D(NJD_CONTROL_3D_NO_CLIP_CHECK);
	OffControl3D(NJD_CONTROL_3D_DEPTH_QUEUE);

	njPushMatrix(0);
	njTranslate(0, v2->x, 0.0, v2->z);
	njScale(0, 2.0, 2.0, 2.0);
	njSetTexture(&PAST01BG_TEXLIST);
	njScaleV_(&Skybox_Scale);
	DrawObject(skybox->getmodel());
	njScale(0, 1.0, 1.0, 1.0);
	njPopMatrix(1u);

	LoadControl3D();
}

void RumbleRallyStageInit() {

	LoadTexPacks((TexPackInfo*)0x109E810, (NJS_TEXLIST***)0x109E748);

	PrintDebug("Textures_Loaded");

	LoadLandTable("resource\\gd_PC\\level.sa2blvl", LandTableFormat_SA2B, &customlevel_texlist, "textures");

	PrintDebug("LandTable_Loaded");

	//LoadSetObject(&CityEscape_ObjectList, LoadStageSETFile(NULL, 2048)); // 2048 is the buffer, make it higher if there is a huge lot of objects in your level
	
	//PrintDebug("Set_Loaded");
	LoadStageLight("stg13_light.bin");
	LoadLevelMusic((char*)"r_hwy.adx");
	LoadFogData_Fogtask("stg13_fog.bin", (FogData*)0x1A280C8);
	//LoadStageSounds("se_ac_gf.mlt", (void*)0x8A0F60);

	PrintDebug("OtherShit_Loaded");

	//LoadStagePaths(PathList);
	//LoadDeathZones(Deathzones);

	// SA2 allows you to change what happens when rings are lost or itembox are triggered, we use the default ones here
	DropRingsFunc_ptr = DropRings;
	DisplayItemBoxItemFunc_ptr = DisplayItemBoxItem;

	// Chaos Drives to use for this level, we use the default ones here
	*(void**)0x1DE4680 = (void*)0x6B6C20;
	*(void**)0x1DE4684 = (void*)0x6BBAE0;
	*(void**)0x1DE4688 = (void*)0x6BC450;
	*(void**)0x1DE468C = (void*)0x6BC4A0;

	PrintDebug("OtherShit_Setup");
	PrintDebug("Init_Done");
}

void RumbleRallyStageDelete() {
	FreeTexPacks((NJS_TEXLIST***)0x109E748, (TexPackInfo*)0x109E810);

	UnloadLandTable(); // This unloads your level when the level is exited, saving memory.

	DropRingsFunc_ptr = nullptr;
	DisplayItemBoxItemFunc_ptr = nullptr;

	*(void**)0x1DE4680 = nullptr;
	*(void**)0x1DE4684 = nullptr;
	*(void**)0x1DE4688 = nullptr;
	*(void**)0x1DE468C = nullptr;

	DeleteObject_(LandManagerPtr);
	DeleteObject_(SetObject_ptr);
}

void RumbleRallyStageOnFrame(ObjectMaster* obj) {
	EntityData1* data = obj->Data1.Entity;

	// Runs every frame in your level, contain a few variables you can use in "data".

	DrawSkyBox(&data->Position);
}

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




extern "C"
{
	// Optional.
	// This function runs code one time when the game starts up. Great for loading assets and setting things up.
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		HelperFunctionsGlobal = helperFunctions;

		CityEscapeHeader.Init = RumbleRallyStageInit; // Runs when the level is loading
		CityEscapeHeader.Free = RumbleRallyStageDelete; // Runs when the level is exited //Free = anonymous_2?
		CityEscapeHeader.subprgmanager = RumbleRallyStageOnFrame; // Object that is loaded when your level loads, and destroyed when stage exit is called

		StartPosition startPos = { LevelIDs_CityEscape, 0, 0, 0, { 0,0,0 }, { 0,0,0 }, { 0,0,0 } };

		for (int i = Characters_Sonic; i != Characters_Chaos + 1; i++) {
			HelperFunctionsGlobal.RegisterStartPosition(i, startPos);
			//end position also
		}

		LoadTextureList("MR_SKY00_DC", &PAST01BG_TEXLIST);
		WriteJump((void*)0x5DD213, DrawSkyBox);
		skybox = LoadMDL("past-skybox", ModelFormat_Chunk);
		
	}

	// Optional.
	// This function runs code on every frame of the game, INCLUDING being in menus, cutscenes, etc.
	// It is recommended to test for game state so that you only run code at a specific time.
	NJS_VECTOR* pos = new NJS_VECTOR{ 0.0,0.0,0.0 };
	__declspec(dllexport) void __cdecl OnFrame()
	{
		// For every frame that you're in a level, add 100 points.
		if (GameState == GameStates_Ingame) {
			ScoreP1 += 100;
		}
	}

	// Optional.
	// This function runs code every time the player inputs. Good for adding custom inputs / overriding events.
	__declspec(dllexport) void __cdecl OnInput()
	{
	}

	// Optional.
	// This function runs while the game processes input.
	__declspec(dllexport) void __cdecl OnControl()
	{
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}
