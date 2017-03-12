/*
*エネミーのプログラム
*担当者 冨田健斗
*/
#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "CBase.h"
#include "CTaskManager.h"


class  CEnemy : public CBase
{
public:

	CEnemy(){
		mPriorityR = 0;
		mPriorityU = 1;
		count += 1;
		mBirthday_No = count;
		mHitPoint = 10;
	}


	void Render(){
		printf("僕は悪い子Render()です,僕は%d番目に生まれました\n", mBirthday_No);
	}

	void Update(){
		printf("僕は悪い子Update()です\n");

	}

};

#endif