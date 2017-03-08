/*
*エネミーのプログラム
*担当者 冨田健斗
*/
#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "CTask.h"


class  CEnemy : public CTask
{
public:

	void Update(){
		printf("enemyのアドレス%pです\n",this);
	};

};

#endif