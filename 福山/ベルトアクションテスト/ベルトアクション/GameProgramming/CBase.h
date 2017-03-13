#pragma once

#include "CVector2.h"

class CBase {
public:
	CVector2 mPos;		//位置
	float axis;			//軸　使い方　mPosの'Y'を代入する(ジャンプの時など，移動以外の'Y'は代入しない)

	CVector2 mRot;		//回転
	
	CVector2 mForward;	//向き


	bool mEnabled;		//有効フラグ
	CBase *mpPlayer;

	int mAlertCnt;

	CBase() : mEnabled(true), mpPlayer(0), mAlertCnt(0) {}
	virtual void init() {}
	virtual void update() {}
	virtual void render() {}
	virtual void collision(CBase *b1, CBase *b2) {}

	/* setPos(int row, int col)
	row:行の指定
	col:列の指定
	行と列から座標上の座標を設定し、移動上方向を設定する
	*/
	virtual void setPos(int row, int col);
	/* setPos(int row, int col, CVector2 fwd)
	row:行の指定
	col:列の指定
	fwd:移動方向（正規化されたベクトル）
	行と列から座標上の座標を設定し、移動方向を設定する
	*/
	virtual void setPos(int row, int col, CVector2 fwd);
};
