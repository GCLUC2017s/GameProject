#pragma once
#include "stdafx.h"
/**
* @file		Global.h
* @brief	ã§í ÉfÅ[É^
*
* @author	shinya nagakawa
*/

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define SCREEN_SIZE CVector2D(SCREEN_WIDTH,SCREEN_HEIGHT)


#define GRAVITY	0.98f

extern char giPAddress[128];
extern int gserver;

#define SE_SLASH	"SE_SLASH"
#define SE_SLASH_S	"SE_SLASH_S"
#define SE_GUN		"SE_GUN"
#define BGM_BATTLE	"BGM_BATTLE"

void Shake(int cnt, CVector3D pow);

void DrawLine(CVector2D &s, CVector2D &e, CVector4D &color);

void DrawLine(CVector3D &s, CVector3D &e, CVector4D &color);
void DrawSphere(CVector3D &p, float radius, CVector4D &color);