/*
* @file		CCharaSelect.h
* @brief	キャラセレクト画面
*
* @author	Ryoji Anzai
*/

#ifndef CCHARASELECT_INCLUDE_GUARD
#define CCHARASELECT_INCLUDE_GUARD
#include "../GLLibrary/CImage.h"
#include "../Global.h"

class CCharaSelect
{
	CImage *m_black;
	CImage *m_charaSelectBackGround;
	CImage *m_charaSelectLogo;
	CImage *m_playerMLogo;
	CImage *m_playerWLogo;
	CImage *m_playerM;
	CImage *m_playerW;
	CImage *m_playerMShadow;
	CImage *m_playerWShadow;

	//以下、キャラセレクト画面のロゴ座標を格納する変数
	int m_charaSelectLogoX;
	int m_charaSelectLogoY;
	//以下、キャラセレクト画面のロゴサイズを格納する変数
	int m_charaSelectLogoWidth;
	int m_charaSelectLogoHeight;
	//以下、男主人公ロゴの座標の初期値を格納する変数
	int m_beforePlayerMLogoX;
	int m_beforePlayerMLogoY;
	//以下、男主人公ロゴの座標の目的地を格納する変数
	int m_afterPlayerMLogoX;
	int m_afterPlayerMLogoY;
	//以下、男主人公ロゴの大きさを格納する変数
	int m_playerMLogoWidth;
	int m_playerMLogoHeight;
	//以下、女主人公ロゴの座標の初期値を格納する変数
	int m_beforePlayerWLogoX;
	int m_beforePlayerWLogoY;
	//以下、女主人公ロゴの座標の目的地を格納する変数
	int m_afterPlayerWLogoX;
	int m_afterPlayerWLogoY;
	//以下、女主人公ロゴの大きさを格納する変数
	int m_playerWLogoWidth;
	int m_playerWLogoHeight;
	//以下、男主人公の座標の初期値を格納する変数
	int m_beforePlayerMX;
	int m_beforePlayerMY;
	//以下、男主人公の座標の目的地を格納する変数
	int m_afterPlayerMX;
	int m_afterPlayerMY;
	//以下、男主人公の大きさを格納する変数
	int m_playerMWidth;
	int m_playerMHeight;
	//以下、男主人公の座標の初期値を格納する変数
	int m_beforePlayerWX;
	int m_beforePlayerWY;
	//以下、男主人公の座標の目的地を格納する変数
	int m_afterPlayerWX;
	int m_afterPlayerWY;
	//以下、女主人公の大きさを格納する変数
	int m_playerWWidth;
	int m_playerWHeight;
	//キャラセレクト画面背景、ロゴの透明度を格納する変数
	float m_alphaCharaSelect;
	//完全表示時の透明度を格納する変数
	float m_alphaMax;
	//キャラセレクトで選択時のRGB値を格納する変数
	float m_normalRGB;
	//キャラセレクトで非選択時のRGB値を格納する変数
	float m_shadowRGB;
	//男主人公ロゴ移動のための時間を格納する変数
	float m_playerMLogoMoveTime;
	//女主人公ロゴ移動のための時間を格納する変数
	float m_playerWLogoMoveTime;
	//男主人公移動のための時間を格納する変数
	float m_playerMMoveTime;
	//女主人公移動のための時間を格納する変数
	float m_playerWMoveTime;
	//キャラセレクト画面のロゴ座標を纏める変数
	CVector2D m_charaSelectLogoPos;
	//キャラセレクト画面のロゴサイズを纏める変数
	CVector2D m_charaSelectLogoSize;
	//男主人公ロゴの移動前の座標を纏める変数
	CVector2D m_beforePlayerMLogoPos;
	//男主人公ロゴの目的地の座標を纏める変数
	CVector2D m_afterPlayerMLogoPos;
	//男主人公ロゴの大きさを纏める変数
	CVector2D m_playerMLogoSize;
	//女主人公ロゴの移動前の座標を纏める変数
	CVector2D m_beforePlayerWLogoPos;
	//女主人公ロゴの目的地の座標を纏める変数
	CVector2D m_afterPlayerWLogoPos;
	//女主人公ロゴの大きさを纏める変数
	CVector2D m_playerWLogoSize;
	//男主人公の移動前の座標を纏める変数
	CVector2D m_beforePlayerMPos;
	//男主人公の目的地の座標を纏める変数
	CVector2D m_afterPlayerMPos;
	//男主人公の大きさを纏める変数
	CVector2D m_playerMSize;
	//女主人公の移動前の座標を纏める変数
	CVector2D m_beforePlayerWPos;
	//女主人公の目的地の座標を纏める変数
	CVector2D m_afterPlayerWPos;
	//女主人公の大きさを纏める変数
	CVector2D m_playerWSize;
	//男主人公ロゴの移動が完了したかどうかを判定するフラグ
	bool m_movePlayerMLogo;
	//女主人公ロゴの移動が完了したかどうかを判定するフラグ
	bool m_movePlayerWLogo;
	//男主人公の移動が完了したかどうかを判定するフラグ
	bool m_movePlayerM;
	//女主人公の移動が完了したかどうかを判定するフラグ
	bool m_movePlayerW;
	//キャラセレクト画面の表示が完了したかどうかを判定するフラグ
	bool m_drawCharaSelectBackGround;
	//どちらのキャラを選択しているかを格納するフラグ(false = M,true = W)
	bool m_chara;

public:
	CCharaSelect();
	~CCharaSelect();
	void Update();
	void Render();
};

#endif
