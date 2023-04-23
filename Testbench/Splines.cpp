#include "pch.h"

ObjectFunc(RailController, 0x4980C0);
ObjectFunc(LoopController, 0x497B50);

LoopPoint Path_0_Entries[] = {
	{ 0, 0, 3.129295f, { 67.27341f, 0, -0 } },
	{ 0, 0, 8.582993f, { 70.4027f, 0, -0.00023f } },
	{ 0, 0, 13.359673f, { 78.985695f, 0, -0.00087f } },
	{ 0, 0, 17.459328f, { 92.34537f, 0, -0.000184f } },
	{ 0, 0, 20.881966f, { 109.804695f, 0, -0.000305f } },
	{ 0, 0, 23.627594f, { 130.68666f, 0, -0.000443f } },
	{ 0, 0, 25.696198f, { 154.31425f, 0, -0.000588f } },
	{ 0, 0, 27.087784f, { 180.01045f, 0, -0.000734f } },
	{ 0, 0, 27.802338f, { 207.09824f, 0, -0.000872f } },
	{ 0, 0, 27.839905f, { 234.90057f, 0, -0.000993f } },
	{ 0, 0, 27.200409f, { 262.74048f, 0, -0.00109f } },
	{ 0, 0, 25.88388f, { 289.9409f, 0, -0.001154f } },
	{ 1, 0x44, 25.69322f, { 315.82477f, 0, -0.001177f } },
	{ 0x17, 0xFE, 27.260866f, { 341.4021f, 0.340637f, -2.414817f } },
	{ 0x4B, 0x1CF, 28.75619f, { 367.7531f, 1.312368f, -9.33108f } },
	{ 0x8D, 0x273, 29.979204f, { 394.30643f, 2.839929f, -20.262981f } },
	{ 0xD6, 0x2F7, 30.812267f, { 420.49063f, 4.84805f, -34.723534f } },
	{ 0x122, 0x366, 31.19298f, { 445.7343f, 7.261467f, -52.225754f } },
	{ 0x174, 0x3C8, 31.09891f, { 469.46606f, 10.00491f, -72.28266f } },
	{ 0x1CE, 0x420, 30.54177f, { 491.1145f, 13.003116f, -94.407265f } },
	{ 0x235, 0x473, 29.569902f, { 510.1082f, 16.180815f, -118.11258f } },
	{ 0x2B0, 0x4C3, 28.278906f, { 525.87573f, 19.462742f, -142.91162f } },
	{ 0x349, 0x50B, 26.83256f, { 537.8457f, 22.773628f, -168.31741f } },
	{ 0x40A, 0x545, 25.493114f, { 545.4467f, 26.038208f, -193.84296f } },
	{ 0x4E6, 0x55F, 25.500862f, { 548.10736f, 29.181223f, -219.00128f } },
	{ 0x5B3, 0x552, 26.699778f, { 545.7747f, 32.224228f, -244.21225f } },
	{ 0x664, 0x528, 27.889458f, { 539.0817f, 35.236607f, -269.8834f } },
	{ 0x706, 0x4E9, 28.88856f, { 528.4858f, 38.214787f, -295.50912f } },
	{ 0x79F, 0x496, 29.585098f, { 514.4444f, 41.155197f, -320.58386f } },
	{ 0x833, 0x431, 29.91677f, { 497.415f, 44.05427f, -344.60205f } },
	{ 0x8C6, 0x3B2, 29.858755f, { 477.85507f, 46.90844f, -367.05814f } },
	{ 0x95E, 0x314, 29.418705f, { 456.22205f, 49.714134f, -387.4465f } },
	{ 0x9FA, 0x249, 28.637943f, { 432.9734f, 52.467785f, -405.2616f } },
	{ 0xA98, 0x142, 27.599262f, { 408.56653f, 55.16582f, -419.99786f } },
	{ 0xB30, 0xFFEA, 26.441895f, { 383.45892f, 57.804676f, -431.14972f } },
	{ 0xBA9, 0xFE25, 25.381786f, { 358.10803f, 60.38078f, -438.21158f } },
	{ 0xB9D, 0xFC34, 24.242449f, { 332.97134f, 62.89057f, -440.67795f } },
	{ 0xACB, 0xFAA6, 22.974228f, { 308.88492f, 65.34681f, -439.45023f } },
	{ 0x996, 0xF989, 22.04789f, { 286.32333f, 67.74488f, -435.83923f } },
	{ 0x84D, 0xF8B4, 21.456537f, { 265.20163f, 70.055176f, -429.9532f } },
	{ 0x700, 0xF833, 21.179197f, { 245.43484f, 72.24806f, -421.90033f } },
	{ 0x5C0, 0xF808, 21.182037f, { 226.93806f, 74.293915f, -411.78885f } },
	{ 0x49E, 0xF82F, 21.422081f, { 209.62634f, 76.1631f, -399.72696f } },
	{ 0x3A6, 0xF89D, 21.852154f, { 193.41472f, 77.826004f, -385.82288f } },
	{ 0x2DD, 0xF945, 22.42569f, { 178.21826f, 79.253f, -370.18484f } },
	{ 0x245, 0xFA19, 23.099997f, { 163.95204f, 80.41445f, -352.92108f } },
	{ 0x1DB, 0xFB0E, 23.837887f, { 150.5311f, 81.28074f, -334.13977f } },
	{ 0x19B, 0xFC19, 24.608402f, { 137.8705f, 81.82224f, -313.94916f } },
	{ 0x185, 0xFCA3, 0, { 125.885284f, 82.00931f, -292.45746f } }
};

LoopPoint Path_1_Entries[] = {
	{ 8, 0xF4, 0.526666f, { -341.86792f, 36.782333f, 0.000005f } },
	{ 8, 0x105, 1.227125f, { -342.39444f, 36.769917f, 0.000244f } },
	{ 8, 0x109, 1.928423f, { -343.62112f, 36.737045f, 0.000401f } },
	{ 8, 0xE8, 2.630622f, { -345.54898f, 36.69029f, 0.000485f } },
	{ 8, 0xC0, 3.333734f, { -348.17905f, 36.636208f, 0.000511f } },
	{ 8, 0x94, 4.037804f, { -351.51233f, 36.581367f, 0.000489f } },
	{ 8, 0x66, 4.742909f, { -355.54984f, 36.532333f, 0.000431f } },
	{ 8, 0x38, 5.449034f, { -360.2926f, 36.495674f, 0.00035f } },
	{ 8, 9, 6.156316f, { -365.7416f, 36.47795f, 0.000257f } },
	{ 8, 0xFFDC, 6.864709f, { -371.89792f, 36.485733f, 0.000164f } },
	{ 8, 0xFFAC, 7.57432f, { -378.7625f, 36.52558f, 0.000083f } },
	{ 9, 0xFF7D, 8.285133f, { -386.33643f, 36.604065f, 0.000026f } },
	{ 0x4A, 0xFDFE, 8.516409f, { -394.62064f, 36.727745f, 0.000005f } },
	{ 0xF4, 0xF9DD, 8.336993f, { -403.10532f, 37.436745f, 0.191691f } },
	{ 0x1A8, 0xF46E, 8.226306f, { -411.23166f, 39.21461f, 0.745945f } },
	{ 0x222, 0xEF0E, 8.166318f, { -418.92734f, 41.983063f, 1.631561f } },
	{ 0x26C, 0xE9C5, 8.141804f, { -426.12003f, 45.663815f, 2.817335f } },
	{ 0x28D, 0xE491, 8.14125f, { -432.7374f, 50.178585f, 4.27206f } },
	{ 0x289, 0xDF6D, 8.157454f, { -438.7071f, 55.44909f, 5.964534f } },
	{ 0x265, 0xDA50, 8.187577f, { -443.95682f, 61.397045f, 7.86355f } },
	{ 0x224, 0xD52E, 8.233266f, { -448.41425f, 67.94417f, 9.937902f } },
	{ 0x1C9, 0xCFFF, 8.300493f, { -452.00705f, 75.01218f, 12.156388f } },
	{ 0x157, 0xCABA, 8.399338f, { -454.66287f, 82.52279f, 14.487801f } },
	{ 0xD5, 0xC55C, 8.543429f, { -456.30942f, 90.39772f, 16.900936f } },
	{ 0x5F, 0xBFD8, 8.551626f, { -456.87433f, 98.55869f, 19.36459f } },
	{ 0x16, 0xBA37, 8.433617f, { -456.28918f, 106.73625f, 21.796759f } },
	{ 0xFFF6, 0xB4AB, 8.368859f, { -454.59024f, 114.65561f, 24.146921f } },
	{ 0xFFEB, 0xAF4F, 8.337596f, { -451.86215f, 122.23043f, 26.431087f } },
	{ 0xFFF3, 0xAA20, 8.324485f, { -448.1896f, 129.3744f, 28.665264f } },
	{ 7, 0xA50F, 8.31931f, { -443.6573f, 136.00119f, 30.86546f } },
	{ 0x23, 0xA00E, 8.317054f, { -438.34985f, 142.02448f, 33.047684f } },
	{ 0x40, 0x9B0C, 8.318129f, { -432.35202f, 147.35794f, 35.227943f } },
	{ 0x55, 0x95F6, 8.328266f, { -425.74844f, 151.91525f, 37.422245f } },
	{ 0x5C, 0x90BF, 8.35849f, { -418.6238f, 155.61009f, 39.646603f } },
	{ 0x4F, 0x8B59, 8.424899f, { -411.0628f, 158.35614f, 41.91702f } },
	{ 0x17, 0x8574, 8.539805f, { -403.1501f, 160.06708f, 44.249504f } },
	{ 0x10E, 0x8574, 8.549031f, { -394.97037f, 160.52496f, 46.66007f } },
	{ 0xFFD3, 0x7A90, 8.450557f, { -386.78546f, 160.06558f, 49.085396f } },
	{ 0xFF8D, 0x74B1, 8.397091f, { -378.85846f, 158.35045f, 51.458763f } },
	{ 0xFF72, 0x6F54, 8.375956f, { -371.27585f, 155.5981f, 53.791084f } },
	{ 0xFF68, 0x6A27, 8.371092f, { -364.12415f, 151.89543f, 56.093266f } },
	{ 0xFF6B, 0x651C, 8.371582f, { -357.48984f, 147.32933f, 58.376217f } },
	{ 0xFF75, 0x6024, 8.371933f, { -351.45944f, 141.9867f, 60.65085f } },
	{ 0xFF7E, 0x5B2C, 8.372105f, { -346.11948f, 135.95442f, 62.928066f } },
	{ 0xFF81, 0x5623, 8.377452f, { -341.55643f, 129.31941f, 65.21878f } },
	{ 0xFF75, 0x50F8, 8.398744f, { -337.8568f, 122.16856f, 67.533905f } },
	{ 0xFF58, 0x4B9E, 8.451935f, { -335.10712f, 114.588745f, 69.88434f } },
	{ 0xFF25, 0x460F, 8.557662f, { -333.39386f, 106.66688f, 72.281f } },
	{ 0xFEE3, 0x4064, 8.604269f, { -332.8036f, 98.48983f, 74.73478f } },
	{ 0xFE99, 0x3AD6, 8.573542f, { -333.37335f, 90.31882f, 77.369804f } },
	{ 0xFE40, 0x357D, 8.565829f, { -335.03326f, 82.4136f, 80.24345f } },
	{ 0xFDDD, 0x304C, 8.560599f, { -337.70935f, 74.85894f, 83.26655f } },
	{ 0xFD7A, 0x2B39, 8.544429f, { -341.32758f, 67.73961f, 86.34996f } },
	{ 0xFD20, 0x2633, 8.511088f, { -345.8139f, 61.14038f, 89.40452f } },
	{ 0xFCD5, 0x2127, 8.461435f, { -351.09433f, 55.14602f, 92.34107f } },
	{ 0xFCA2, 0x1C04, 8.403603f, { -357.09485f, 49.841293f, 95.07046f } },
	{ 0xFC91, 0x16B9, 8.35335f, { -363.74142f, 45.310974f, 97.50352f } },
	{ 0xFCB2, 0x113D, 8.334196f, { -370.96005f, 41.63983f, 99.551094f } },
	{ 0xFD1B, 0xB92, 8.376992f, { -378.67673f, 38.912636f, 101.12404f } },
	{ 0xFDE4, 0x5C7, 8.51824f, { -386.8174f, 37.214153f, 102.13319f } },
	{ 0xFEBF, 0x16E, 7.793365f, { -395.30807f, 36.62917f, 102.48938f } },
	{ 0xFF19, 0, 6.26181f, { -403.10144f, 36.62917f, 102.48938f } },
	{ 0xFF1A, 0, 4.975891f, { -409.36325f, 36.62917f, 102.48938f } },
	{ 0xFF1A, 0, 3.935577f, { -414.33914f, 36.62917f, 102.48938f } },
	{ 0xFF1A, 0, 3.1409f, { -418.27472f, 36.62917f, 102.48938f } },
	{ 0xFF1A, 0, 2.591858f, { -421.41562f, 36.62917f, 102.48938f } },
	{ 0xFF1A, 0, 2.288452f, { -424.00748f, 36.62917f, 102.48938f } },
	{ 0xFF1A, 0, 2.230652f, { -426.29593f, 36.62917f, 102.48938f } },
	{ 0xFF1A, 0, 2.418488f, { -428.52658f, 36.62917f, 102.48938f } },
	{ 0xFF1A, 0, 2.851959f, { -430.94507f, 36.62917f, 102.48938f } },
	{ 0xFF1A, 0, 3.531036f, { -433.79703f, 36.62917f, 102.48938f } },
	{ 0xFF1A, 0, 4.45578f, { -437.32806f, 36.62917f, 102.48938f } },
	{ 0xFF1A, 0, 0, { -441.78384f, 36.62917f, 102.48938f } }
};

LoopHead Path_0 = { 1, LengthOfArray<int16_t>(Path_0_Entries), 1200.2086f, Path_0_Entries, RailController };
LoopHead Path_1 = { 1, LengthOfArray<int16_t>(Path_1_Entries), 502.05804f, Path_1_Entries, LoopController };

LoopHead* CityEscapePaths[] = {
	&Path_0,
	&Path_1,
	NULL
};

LoopHead** GetPaths()
{
	return CityEscapePaths;
}