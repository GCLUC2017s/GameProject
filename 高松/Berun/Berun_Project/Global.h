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


#define GRAVITY	-0.98f
#define TUTORIAL_MAX 2
#define FILE_NAME 32


extern char g_tutorialDataPath[TUTORIAL_MAX][FILE_NAME];
extern int  g_tutorialNo;

#define BGM_BATTLE	"BGM_BATTLE"