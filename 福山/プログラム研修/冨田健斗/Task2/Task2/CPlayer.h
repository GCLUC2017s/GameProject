/*
*�v���C���[�̃v���O����
*�S���ҁ@�y�c���l
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

		printf("�l�͐��`�ł�\n");
	}

};

#endif