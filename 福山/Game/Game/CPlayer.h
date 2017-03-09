/*
*プレイヤーのプログラム
*担当者　冨田健斗
*/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "CTask.h"
#include "CTaskManager.h"

class  CPlayer : public CTask{
public:
	CPlayer(){
		mPriorityR = 0;
		mPriorityU = 0;
		mHitPoint = 10;
	}

	void Update(){

		printf("僕は正義です\n");
	}

};

#endif