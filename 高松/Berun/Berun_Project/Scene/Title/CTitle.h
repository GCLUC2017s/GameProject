/*
* @file		CTitle.h
* @brief	タイトル画面
*
* @author	Ryoji Anzai
*/

#ifndef CTITLE_INCLUDE_GUARD
#define CTITLE_INCLUDE_GUARD
#include "../GLLibrary/CImage.h"
#include "../Global.h"
#include "../CScene.h"

class CTitle : public CScene
{
	CImage *m_black;
	CImage *m_titleImage;
	CImage *m_pushEnter;
	CImage *m_logo;
	CImage *m_logoKnife;
	CImage *m_logoFork;
	CImage *m_logoBerun;
	CImage *m_start;
	CImage *m_exit;
	CImage *m_playerM;
	CImage *m_playerW;

	//タイトルロゴのX座標を格納する変数
	int m_titleLogoX;
	//タイトルロゴのY座標の初期値を格納する変数
	int m_beforeTitleLogoY;
	//タイトルロゴのY座標の目的地を格納する変数
	int m_afterTitleLogoY;
	//以下、タイトルロゴの大きさを格納する変数
	int m_titleLogoWidth;
	int m_titleLogoHeight;
	//タイトルロゴの描写演出で、初期の大きさを何倍にするかを格納する変数
	int m_titleLogoVolume;
	//タイトルロゴの描写演出で、表示のスピードをいくつにするかを格納する変数
	int m_titleLogoSpeed;
	//以下、ナイフの座標の初期値を格納する変数
	int m_beforeKnifeX;
	int m_beforeKnifeY;
	//以下、ナイフの座標の目的地を格納する変数
	int m_afterKnifeX;
	int m_afterKnifeY;
	//以下、ナイフ(画像)の大きさを格納する変数
	int m_knifeWidth;
	int m_knifeHeight;
	//以下、フォークの座標の初期値を格納する変数
	int m_beforeForkX;
	int m_beforeForkY;
	//以下、フォークの座標の目的地を格納する変数
	int m_afterForkX;
	int m_afterForkY;
	//以下、フォーク(画像)の大きさを格納する変数
	int m_forkWidth;
	int m_forkHeight;
	//以下、バラン(画像)の座標を格納する変数
	int m_berunX;
	int m_berunY;
	//以下、バラン(画像)の大きさを格納する変数
	int m_berunWidth;
	int m_berunHeight;
	//以下、ENTERKEY TAPの文字の座標を格納する変数
	int m_pushEnterX;
	int m_pushEnterY;
	//以下、ENTERKEY TAPの文字の大きさを格納する変数
	int m_pushEnterWidth;
	int m_pushEnterHeight;
	//以下、STARTの文字の座標を格納する変数
	int m_startX;
	int m_startY;
	//以下、STARTの文字の大きさを格納する変数
	int m_startWidth;
	int m_startHeight;
	//以下、EXITの文字の座標を格納する変数
	int m_exitX;
	int m_exitY;
	//以下、EXITの文字の大きさを格納する変数
	int m_exitWidth;
	int m_exitHeight;
	//以下、男主人公の座標の初期値を格納する変数
	int m_beforePlayerMX;
	int m_beforePlayerMY;
	//以下、男主人公の座標の目的地を格納する変数
	int m_afterPlayerMX;
	int m_afterPlayerMY;
	//以下、男主人公の大きさを格納する変数
	int m_playerMWidth;
	int m_playerMHeight;
	//以下、女主人公の座標の初期値を格納する変数
	int m_beforePlayerWX;
	int m_beforePlayerWY;
	//以下、女主人公の座標の目的地を格納する変数
	int m_afterPlayerWX;
	int m_afterPlayerWY;
	//以下、女主人公の大きさを格納する変数
	int m_playerWWidth;
	int m_playerWHeight;
	//タイトル背景の透明度を格納する変数
	float m_alphaTitleImage;
	//タイトル文字の透明度を格納する変数
	float m_alphaWord;
	//バラン(画像)の透明度を格納する変数
	float m_alphaBerun;
	//STARTの透明度を格納する変数
	float m_alphaStart;
	//EXITの透明度を格納する変数
	float m_alphaExit;
	//タイトルロゴ移動のための時間を格納する変数
	float m_titleLogoMoveTime;
	//ナイフ(画像)の時間を格納する変数
	float m_knifeMoveTime;
	//フォーク(画像)移動のための時間を格納する変数
	float m_forkMoveTime;
	//男主人公移動のための時間を格納する変数
	float m_playerMMoveTime;
	//女主人公移動のための時間を格納する変数
	float m_playerWMoveTime;
	//タイトルロゴの移動前の座標を纏める変数
	CVector2D m_beforeTitleLogoPos;
	//タイトルロゴの移動後の座標を纏める変数
	CVector2D m_afterTitleLogoPos;
	//タイトルロゴの大きさを纏める変数
	CVector2D m_titleLogoSize;
	//ナイフ(画像)の移動前の座標を纏める変数
	CVector2D m_beforeKnifePos;
	//ナイフ(画像)の移動後の座標を纏める変数
	CVector2D m_afterKnifePos;
	//ナイフ(画像)の大きさを纏める変数
	CVector2D m_knifeSize;
	//フォーク(画像)の移動前の座標を纏める変数
	CVector2D m_beforeForkPos;
	//フォーク(画像)の移動後の座標を纏める変数
	CVector2D m_afterForkPos;
	//フォーク(画像)の大きさを纏める変数
	CVector2D m_forkSize;
	//バラン(画像)の移動後の座標を纏める変数
	CVector2D m_berunPos;
	//バラン(画像)の大きさを纏める変数
	CVector2D m_berunSize;
	//ENTERKEY TAPの座標を纏める変数
	CVector2D m_enterWordPos;
	//ENTERKEY TAPの大きさを纏める変数
	CVector2D m_enterWordSize;
	//STARTの座標を纏める変数
	CVector2D m_startPos;
	//STARTの大きさを纏める変数
	CVector2D m_startSize;
	//EXITの座標を纏める変数
	CVector2D m_exitPos;
	//EXITの大きさを纏める変数
	CVector2D m_exitSize;
	//男主人公の移動前の座標を纏める変数
	CVector2D m_beforePlayerMPos;
	//男主人公の移動後の座標を纏める変数
	CVector2D m_afterPlayerMPos;
	//男主人公の大きさを纏める変数
	CVector2D m_playerMSize;
	//女主人公の移動前の座標を纏める変数
	CVector2D m_beforePlayerWPos;
	//女主人公の移動後の座標を纏める変数
	CVector2D m_afterPlayerWPos;
	//女主人公の大きさを纏める変数
	CVector2D m_playerWSize;
	//タイトルロゴの移動が完了したかどうかを判定するフラグ
	bool m_moveTitleLogo;
	//ナイフの移動が完了したかどうかを判定するフラグ
	bool m_moveKnife;
	//フォークの移動が完了したかどうかを判定するフラグ
	bool m_moveFork;
	//男主人公の移動が完了したかどうかを判定するフラグ
	bool m_movePlayerM;
	//女主人公の移動が完了したかどうかを判定するフラグ
	bool m_movePlayerW;
	//バランの表示が完了したかどうかを判定するフラグ
	bool m_drawBerun;
	//タイトルが全て表示し終わったかどうかを判定するフラグ
	bool m_drawTitle;
	//ENTERKEY TAPの表示を最初のタイミングのみ加速させるためのフラグ
	bool m_enterTapFlag;
	//ENTERKEY TAP透明度の加算減算を切り替えるためのフラグ
	bool m_alphaEnterTapSwich;
	//タイトルの状態を格納するフラグ(false = 未入力状態(ロゴとENTERKEY TAP表示),true = 入力状態(メニュー))
	bool m_titleState;
	//一度でもメニュー状態に入ったかどうかのフラグ
	bool m_firstMenu;
	//一度でもキャラを表示したかどうかのフラグ
	bool m_firstChara;
	//メニューのどちら側(START/EXIT)を選択しているかを格納するフラグ(false = START,true = EXIT)
	bool m_titleMenu;
public:

	CTitle();
	~CTitle();
	void Update();
	void Draw();
};

#endif