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
#include "../CScene.h"

class CCharaSelect : public CScene
{
	CImage *m_black;
	CImage *m_charaSelectBackGround;
	CImage *m_charaSelectLogo;
	CImage *m_playerMLogoWord1;
	CImage *m_playerMLogoWord2;
	CImage *m_playerMLogoWord3;
	CImage *m_playerMLogoWord4;
	CImage *m_playerWLogoWord1;
	CImage *m_playerWLogoWord2;
	CImage *m_playerWLogoWord3;
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
	//以下、キャラクターMのWord1の移動前の座標を格納する変数
	int m_beforePlayerMLogoWord1X;
	int m_beforePlayerMLogoWord1Y;
	//以下、キャラクターMのWord1の目的地の座標を格納する変数
	int m_afterPlayerMLogoWord1X;
	int m_afterPlayerMLogoWord1Y;
	//以下、キャラクターMのWord2の移動前の座標を格納する変数
	int m_beforePlayerMLogoWord2X;
	int m_beforePlayerMLogoWord2Y;
	//以下、キャラクターMのWord2の目的地の座標を格納する変数
	int m_afterPlayerMLogoWord2X;
	int m_afterPlayerMLogoWord2Y;
	//以下、キャラクターMのWord3の移動前の座標を格納する変数
	int m_beforePlayerMLogoWord3X;
	int m_beforePlayerMLogoWord3Y;
	//以下、キャラクターMのWord3の目的地の座標を格納する変数
	int m_afterPlayerMLogoWord3X;
	int m_afterPlayerMLogoWord3Y;
	//以下、キャラクターMのWord4の移動前の座標を格納する変数
	int m_beforePlayerMLogoWord4X;
	int m_beforePlayerMLogoWord4Y;
	//以下、キャラクターMのWord4の目的地の座標を格納する変数
	int m_afterPlayerMLogoWord4X;
	int m_afterPlayerMLogoWord4Y;
	//以下、キャラクターWのWord1の移動前の座標を格納する変数
	int m_beforePlayerWLogoWord1X;
	int m_beforePlayerWLogoWord1Y;
	//以下、キャラクターWのWord1の目的地の座標を格納する変数
	int m_afterPlayerWLogoWord1X;
	int m_afterPlayerWLogoWord1Y;
	//以下、キャラクターWのWord2の移動前の座標を格納する変数
	int m_beforePlayerWLogoWord2X;
	int m_beforePlayerWLogoWord2Y;
	//以下、キャラクターWのWord2の目的地の座標を格納する変数
	int m_afterPlayerWLogoWord2X;
	int m_afterPlayerWLogoWord2Y;
	//以下、キャラクターWのWord3の移動前の座標を格納する変数
	int m_beforePlayerWLogoWord3X;
	int m_beforePlayerWLogoWord3Y;
	//以下、キャラクターWのWord3の目的地の座標を格納する変数
	int m_afterPlayerWLogoWord3X;
	int m_afterPlayerWLogoWord3Y;
	//以下、キャラクターロゴの大きさを格納する変数
	int m_playerLogoWordWidth;
	int m_playerLogoWordHeight;
	//以下、キャラクターロゴ2の大きさを格納する変数
	int m_playerLogoWord2Width;
	int m_playerLogoWord2Height;
	//以下、キャラクターロゴ3の大きさを格納する変数
	int m_playerLogoWord3Width;
	int m_playerLogoWord3Height;
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
	//男主人公ロゴ文字1の移動前の座標を纏める変数
	CVector2D m_beforePlayerMLogoWord1Pos;
	//男主人公ロゴ文字1の目的地の座標を纏める変数
	CVector2D m_afterPlayerMLogoWord1Pos;
	//男主人公ロゴ文字2の移動前の座標を纏める変数
	CVector2D m_beforePlayerMLogoWord2Pos;
	//男主人公ロゴ文字2の目的地の座標を纏める変数
	CVector2D m_afterPlayerMLogoWord2Pos;
	//男主人公ロゴ文字3の移動前の座標を纏める変数
	CVector2D m_beforePlayerMLogoWord3Pos;
	//男主人公ロゴ文字3の目的地の座標を纏める変数
	CVector2D m_afterPlayerMLogoWord3Pos;
	//男主人公ロゴ文字4の移動前の座標を纏める変数
	CVector2D m_beforePlayerMLogoWord4Pos;
	//男主人公ロゴ文字4の目的地の座標を纏める変数
	CVector2D m_afterPlayerMLogoWord4Pos;
	//女主人公ロゴ文字1の移動前の座標を纏める変数
	CVector2D m_beforePlayerWLogoWord1Pos;
	//女主人公ロゴ文字1の目的地の座標を纏める変数
	CVector2D m_afterPlayerWLogoWord1Pos;
	//女主人公ロゴ文字2の移動前の座標を纏める変数
	CVector2D m_beforePlayerWLogoWord2Pos;
	//女主人公ロゴ文字2の目的地の座標を纏める変数
	CVector2D m_afterPlayerWLogoWord2Pos;
	//女主人公ロゴ文字3の移動前の座標を纏める変数
	CVector2D m_beforePlayerWLogoWord3Pos;
	//女主人公ロゴ文字3の目的地の座標を纏める変数
	CVector2D m_afterPlayerWLogoWord3Pos;
	//主人公ロゴ文字の大きさを纏める変数
	CVector2D m_playerLogoWord1Size;
	//主人公ロゴ文字2の大きさを纏める変数
	CVector2D m_playerLogoWord2Size;
	//主人公ロゴ文字3の大きさを纏める変数
	CVector2D m_playerLogoWord3Size;
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
	void Draw();
};

#endif
