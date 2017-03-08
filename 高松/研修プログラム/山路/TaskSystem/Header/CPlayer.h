/**
*@file
*@brief  プレイヤークラス
*@author 山路
*/

#ifndef INCLUDE_GURAD_TASK
#include "CTask.h"
#endif  INCLUDE_GURAD_TASK

class CPlayer : public CTask
{
private:
	int m_power;
public:
	CPlayer();
	~CPlayer();
	void Update();
	void Print();
};