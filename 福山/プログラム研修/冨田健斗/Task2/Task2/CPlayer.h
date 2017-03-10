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
		mPriorityR = 1;
		mPriorityU = 0;
		mHitPoint = 0;
	}

	void Render(){
		printf("僕は正義のRender()です\n");
	}

	void Update(){
		printf("僕は正義のUpdate()です\n");
	}

};

#endif