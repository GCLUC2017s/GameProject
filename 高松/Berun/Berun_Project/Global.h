#pragma once
#include "stdafx.h"
/**
* @file		Global.h
* @brief	共通データ
*
* @author	shinya nagakawa
*/

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define SCREEN_SIZE CVector2D(SCREEN_WIDTH,SCREEN_HEIGHT)


#define GRAVITY	-0.98f
#define TUTORIAL_MAX 2
#define FILE_NAME 32

//チュートリアルデータパス
extern char g_tutorialDataPath[TUTORIAL_MAX][FILE_NAME];
//現在のチュートリアルナンバー
extern int  g_tutorialNo;

//サウンド　マクロの定義
#define TITLE_BGM	"TITLE_BGM"
#define CHARASELECT_BGM	"CHARASELECT_BGM"
#define AREA_M_BGM	"AREA_M_BGM"
#define AREA_N_BGM	"AREA_N_BGM"
#define AREA_E_BGM	"AREA_E_BGM"
#define AREA_NI_BGM	"AREA_NI_BGM"
#define RESULT_BGM	"RESULT_BGM"
#define GAMEOVER_BGM	"GAMEOVER_BGM"
