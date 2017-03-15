#ifndef BASE_HPP
#define BASE_HPP
#define SIZE_PLAYER_Y 1  //プレイヤーのサイズ_Y
#define SIZE_PLAYER_X 0.5 //プレイヤーのサイズ_X
#define SIZE_SHADOW_X 0.4 //影のサイズX
#define SIZE_SHADOW_Y 0.4 //影のサイズY
#include "../Task/CTask.h"
#include "../Vector/CVector2.h"


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
	CVector2 mForward;	//向き
	float mAxis;			//軸　使い方　mPosの'Y'を代入する(ジャンプの時など，移動以外の'Y'は代入しない)
	bool mEnabled;		//有効フラグ
	CBase *mpPlayer;
	float mHitPoint; //ヒットポイント

	int mAlertCnt;

	CBase() : mEnabled(true), mpPlayer(0), mAlertCnt(0),mAxis(0),mHitPoint(0) {

	}
	virtual void Collision(CBase *b1, CBase *b2) {}

	
};
#endif
