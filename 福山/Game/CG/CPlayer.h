/*
*�v���C���[�̃v���O����
*�S���ҁ@�y�c���l
*/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "CBase.h"
#include "CTaskManager.h"
#include"CBase.h"
#include "CRectangle.h"
#include "define.h"
#define JUMP_FIRST_SPEED 0.2

class  CPlayer : public CBase{
public:
	CPlayer(){
		mPriorityR = 1;
		mPriorityU = 0;
		mHitPoint = 10;
		count += 1;
		mBirthday_No = count;
	}

	void Update(){
		printf("�l�͐��`��Update()�ł�\n");
	}

	void Render(){
		printf("�l�͐��`��Render()�ł�,�l��%d�Ԗڂɐ��܂�܂���\n", mBirthday_No);
	}

};

#endif