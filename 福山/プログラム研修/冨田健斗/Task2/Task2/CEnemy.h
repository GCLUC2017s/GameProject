/*
*エネミーのプログラム
*担当者 冨田健斗
*/
#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "CTask.h"
#include "CTaskManager.h"


class  CEnemy : public CTask
{
public:

	CEnemy(){
		mPriorityR = 0;
		mPriorityU = 1;
		mHitPoint = 10;
	}

	void Update(){
		printf("僕は悪い子Update()です\n");
		
	}
	void Render(){
		printf("僕は悪い子Render()です\n");
	}

};

#endif