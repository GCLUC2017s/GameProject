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
#define ARRAY_SIZE(a)(sizeof(a)/sizeof(a[0]))
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

//キー入力の定義
#define PUSH_KEY_ENTER		CInput::GetState(0, CInput::ePush, CInput::eButton10)		//決定・攻撃キー
#define HOLD_KEY_ENTER		CInput::GetState(0, CInput::eHold, CInput::eButton10)		//決定・攻撃キー
#define PUSH_KEY_SPASE		CInput::GetState(0, CInput::ePush, CInput::eButton5)		//スキップ・ジャンプキー
#define HOLD_KEY_SHIFT		CInput::GetState(0, CInput::eHold, CInput::eButton6)		//ダッシュキー
#define PUSH_KEY_UP			CInput::GetState(0, CInput::ePush, CInput::eUp)				//上キープッシュ
#define HOLD_KEY_UP			CInput::GetState(0, CInput::eHold, CInput::eUp)				//上キーホールド
#define PUSH_KEY_DOWN		CInput::GetState(0, CInput::ePush, CInput::eDown)			//下キープッシュ
#define HOLD_KEY_DOWN		CInput::GetState(0, CInput::eHold, CInput::eDown)			//下キーホールド
#define PUSH_KEY_RIGHT		CInput::GetState(0, CInput::ePush, CInput::eRight)			//右キープッシュ
#define HOLD_KEY_RIGHT		CInput::GetState(0, CInput::eHold, CInput::eRight)			//右キーホールド
#define PUSH_KEY_LEFT		CInput::GetState(0, CInput::ePush, CInput::eLeft)			//左キープッシュ
#define HOLD_KEY_LEFT		CInput::GetState(0, CInput::eHold, CInput::eLeft)			//左キーホールド


