/**
*@file
*@brief  �G�l�~�[�N���X
*@author �R�H
*/

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "../Task/CTask.h"

class CEnemy : public CTask
{
public:
	CEnemy();
	~CEnemy();
	void Update();
	void Render();
};

#endif