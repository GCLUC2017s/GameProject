/*
*�v���C���[�̃v���O����
*�S���ҁ@�y�c���l
*/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "CTask.h"

class  CPlayer : public CTask{
public:
	CPlayer(){}
	void Update(){
		printf("player�̃A�h���X%p�ł�\n",this);
	}

};

#endif