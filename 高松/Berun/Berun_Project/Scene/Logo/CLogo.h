/*
* @file		CLogo.h
* @brief	ロゴ画面
*
* @author	Ryoji Anzai
*/

#ifndef CLOGO_INCLUDE_GUARD
#define CLOGO_INCLUDE_GUARD
#include "../GLLibrary/CImage.h"
#include "../Global.h"
#include "../CScene.h"

class CLogo : public CScene
{
	CImage *m_black;
	CImage *m_blackSecond;
	CImage *m_logo;
	CImage *m_charaM;
	CImage *m_charaW;

	//ずらす用黒味のX座標を格納する変数
	int m_blackPosX;
	//黒味をずらす速度を格納する変数
	int m_xSpeed;
	//以下、ロゴの座標を格納する変数
	int m_logoX;
	int m_logoY;
	//以下、ロゴの大きさを格納する変数
	int m_logoWidth;
	int m_logoHeight;
	//黒味の透明度を格納する変数
	float m_alphaBlack;
	//ロゴの座標を纏める変数
	CVector2D m_logoPoint;
	//ロゴの大きさを纏める変数
	CVector2D m_logoSize;
public:
	//簡易的に接続するためのフラグ
	bool flag;
	CLogo();
	~CLogo();
	void Update();
	void Draw();
};

#endif