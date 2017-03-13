#ifndef BASE_HPP
#define BASE_HPP
#include "CTask.h"
#include "CTexture.h"
#include "CRectangle.h"
#include "CVector2.h"


/*
使い方

CTaskにある書いてある

int mPriorityR; //Rander()のナンバー
int mPriorityU;//Update()のナンバー

CBase を継承するものには必ず入れること
数字が小さいものほど

*/


class CBase : public CTask{
public:
	CVector2 mPos;		//位置
	CVector2 mRot;		//回転
	CVector2 mForward;	//向き
	float mAxis;			//軸　使い方　mPosの'Y'を代入する(ジャンプの時など，移動以外の'Y'は代入しない)
	bool mEnabled;		//有効フラグ
	CBase *mpPlayer;
	float mHitPoint; //ヒットポイント

	int mAlertCnt;

	CBase() : mEnabled(true), mpPlayer(0), mAlertCnt(0),mAxis(0),mHitPoint(0) {}
	virtual void Collision(CBase *b1, CBase *b2) {}

	
};
#endif
