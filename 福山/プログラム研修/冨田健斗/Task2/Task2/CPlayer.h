/*
*プレイヤーのプログラム
*担当者　冨田健斗
*/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "CTask.h"

class  CPlayer : public CTask{
public:
	CPlayer(){}
	void Update(){
		printf("playerのアドレス%pです\n",this);
	}

};

#endif