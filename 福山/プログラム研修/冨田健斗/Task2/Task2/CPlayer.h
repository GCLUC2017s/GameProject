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
		mPriorityR = 1;
		mPriorityU = 0;
		mHitPoint = 0;
	}

	void Render(){
		printf("�l�͐��`��Render()�ł�\n");
	}

	void Update(){
		printf("�l�͐��`��Update()�ł�\n");
	}

};

#endif