/*
*エネミーのプログラム
*担当者 冨田健斗
*/
#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "CBase.h"


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


	void Render();

	void Update();

};

#endif