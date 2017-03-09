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
		mPriorityU = 0;
		mHitPoint = 10;
	}

	void Update(){

		printf("僕は悪い子です\n");
		
	};

};

#endif