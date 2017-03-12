/*
*プレイヤーのプログラム
*担当者　冨田健斗
*/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "CBase.h"
#include "CTaskManager.h"
#include"CBase.h"
#include "CRectangle.h"
#include "define.h"
#define JUMP_FIRST_SPEED 0.2

class  CPlayer : public CBase{
public:
	CPlayer(){
		mPriorityR = 1;
		mPriorityU = 0;
		mHitPoint = 10;
		count += 1;
		mBirthday_No = count;
	}

	void Update(){
		printf("僕は正義のUpdate()です\n");
	}

	void Render(){
		printf("僕は正義のRender()です,僕は%d番目に生まれました\n", mBirthday_No);
	}

};

#endif