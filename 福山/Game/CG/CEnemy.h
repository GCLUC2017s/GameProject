/*
*�G�l�~�[�̃v���O����
*�S���� �y�c���l
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
		printf("�l�͈����qRender()�ł�,�l��%d�Ԗڂɐ��܂�܂���\n", mBirthday_No);
	}

	void Update(){
		printf("�l�͈����qUpdate()�ł�\n");

	}

};

#endif