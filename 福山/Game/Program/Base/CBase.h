/*
担当者　冨田健斗　&&
*/
#ifndef BASE_HPP
#define BASE_HPP

#define SIZE_PLAYER_Y 1 * 2									//プレイヤーのサイズ_Y
#define SIZE_PLAYER_X 0.5 * 2								//プレイヤーのサイズ_X
#define SIZE_SHADOW_X 0.4									//影のサイズX
#define SIZE_SHADOW_Y 0.4									//影のサイズY
#define SHADOW_TEX_X			70							//影のテクスチャのX
#define SHADOW_TEX_Y			20							//影のテクスチャのY
#define TEX_FILE_SHADOW		"../CG/shadow/"					//影のファイル場所
#define FRAME_LIMIT 6										//フレーム数の上限
#include "../Task/CTask.h"
#include "../Vector/CVector2.h"
#include "../Define/define.h"

const float character_limit_left = -MAP_LIMIT_X / 2;		//進める上限(左)
const float character_limit_top = MAP_LIMIT_Y / 4;		    //進める上限(上)
const float character_limit_right = MAP_LIMIT_X / 2;	    //進める上限(右)
const float character_limit_bottom = -MAP_LIMIT_Y / 2;		//進める上限(下)



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
	CBase *mpPlayer;					//あたり判定判断用
	CVector2 mPos;						//位置
	CVector2 mForward;					//向き
	bool mEnabled;						//有効フラグ
	float mAxis;						//軸　使い方　mPosの'Y'を代入する(ジャンプの時など，移動以外の'Y'は代入しない)
	float mHitPoint;					//ヒットポイント
	int mSaveAnime;						//直前のアニメが何か判断用
	int mFlameCount;					//フレーム数カウント用
	int mAnimeFrame;					//アニメーションのフレーム数

	CBase() : mEnabled(true), mpPlayer(0),mAxis(0),mHitPoint(0),mFlameCount(0) {

	}
	/*あたり判定*/
	virtual void Collision(CBase *b1, CBase *b2) {}


	
};
#endif
