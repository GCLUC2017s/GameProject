/**
*@file
*@brief  エネミークラス
*@author 山路
*/

#ifndef INCLUDE_GURAD_TASK
#include "CTask.h"
#endif  INCLUDE_GURAD_TASK

class CEnemy : public CTask
{
private:
	int m_defense;
public:
	CEnemy();
	~CEnemy();
	void Update();
	void Print();
};