/*
*�G�l�~�[�̃v���O����
*�S���� �y�c���l
*/
#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "CTask.h"


class  CEnemy : public CTask
{
public:

	void Update(){
		printf("enemy�̃A�h���X%p�ł�\n",this);
	};

};

#endif