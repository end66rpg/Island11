#pragma once
#include "SimpleMath.h"

using namespace DirectX;
using namespace SimpleMath;

struct CBuffer
{
	// rendering control variables
	float		g_RenderCaustics;//HeightFieldPatchDS
	float		g_UseDynamicLOD;//PatchConstantHS,HeightFieldPatchDS, WaterPatchDS
	float		g_FrustumCullInHS;//PatchConstantHS
	float       g_DynamicTessFactor;//PatchConstantHS,HeightFieldPatchDS, WaterPatchDS

	float       g_StaticTessFactor;//PatchConstantHS,HeightFieldPatchDS, WaterPatchDS
	float		g_TerrainBeingRendered;//PatchConstantHS
	float		g_HalfSpaceCullSign;//HeightFieldPatchPS, 
	float		g_HalfSpaceCullPosition;//HeightFieldPatchPS

	// view/time dependent variables
	XMFLOAT4X4  g_ModelViewMatrix;//WaterPatchPS

	XMFLOAT4X4  g_ModelViewProjectionMatrix;//HeightFieldPatchDS,WaterPatchDS,PatchConstantHS,WaterPatchPS,SkyVS

	XMFLOAT4X4	g_ModelViewProjectionMatrixInv;//�� ������������?

	XMFLOAT4X4  g_LightModelViewProjectionMatrix;//HeightFieldPatchPS,WaterPatchPS

	XMFLOAT4X4  g_LightModelViewProjectionMatrixInv;//�� ������������?

	XMFLOAT3    g_CameraPosition;//HeightFieldPatchDS,WaterPatchDS,PatchConstantHS,HeightFieldPatchPS,WaterNormalmapCombinePS,SkyPS,WaterPatchPS
	float		g_SkipCausticsCalculation;//HeightFieldPatchDS

	XMFLOAT3    g_CameraDirection;//PatchConstantHS
	int			g_MSSamples;//�� ������������?

	XMFLOAT3    g_LightPosition;//HeightFieldPatchDS,HeightFieldPatchPS,SkyPS,WaterPatchPS
	float	    g_MainBufferSizeMultiplier;//MainToBackBufferPS

	XMFLOAT2    g_WaterBumpTexcoordShift;//WaterPatchDS,WaterNormalmapCombinePS,WaterPatchPS
	XMFLOAT2    g_ScreenSizeInv;//WaterPatchPS

	float		g_ZNear;//WaterPatchPS
	float		g_ZFar;//WaterPatchPS
	// constants defining visual appearance
	XMFLOAT2	g_DiffuseTexcoordScale = { 130.0, 130.0 };//HeightFieldPatchDS

	XMFLOAT2	g_RockBumpTexcoordScale = { 10.0, 10.0 };//HeightFieldPatchDS
	XMFLOAT2	g_SandBumpTexcoordScale = { 3.5, 3.5 };//HeightFieldPatchDS

	float		g_RockBumpHeightScale = 3.0;//HeightFieldPatchDS
	float		g_SandBumpHeightScale = 0.5;//HeightFieldPatchDS
	float       g_TerrainSpecularIntensity = 0.5;//�� ������������?
	float		g_WaterHeightBumpScale = 1.0f;//HeightFieldPatchDS,WaterPatchDS

	XMFLOAT2	g_WaterMicroBumpTexcoordScale = { 225, 225 };//WaterPatchDS
	XMFLOAT2	g_WaterBumpTexcoordScale = { 7, 7 };//WaterPatchDS,WaterNormalmapCombinePS

	XMFLOAT3    g_WaterDeepColor = { 0.1, 0.4, 0.7 };//WaterPatchPS
	float       g_WaterSpecularIntensity = 350.0;//WaterPatchPS
	XMFLOAT3    g_WaterScatterColor = { 0.3, 0.7, 0.6 };//WaterPatchPS
	float       g_WaterSpecularPower = 1000;//WaterPatchPS

	XMFLOAT3    g_WaterSpecularColor = { 1, 1, 1 };//WaterPatchPS
	float		g_FogDensity = 1.0f / 700.0f;//HeightFieldPatchPS,WaterPatchPS

	XMFLOAT2    g_WaterColorIntensity = { 0.1, 0.2 };//WaterPatchPS
	XMFLOAT2	g_HeightFieldOrigin = XMFLOAT2(0, 0);//�� ������������?

	XMFLOAT3    g_AtmosphereBrightColor = { 1.0, 1.1, 1.4 };//HeightFieldPatchPS, SkyPS,WaterPatchPS
	float		g_HeightFieldSize = 512;//HeightFieldPatchDS,WaterPatchDS,PatchHS(PatchConstantHS),WaterNormalmapCombinePS

	XMFLOAT3    g_AtmosphereDarkColor = { 0.6, 0.6, 0.7 };//HeightFieldPatchPS,SkyPS,WaterPatchPS
	float       unuse = 0;
};
