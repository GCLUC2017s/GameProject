/*
*�G�l�~�[�̃v���O����
*�S���� �y�c���l
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

		printf("�l�͈����q�ł�\n");
		
	};

};

#endif