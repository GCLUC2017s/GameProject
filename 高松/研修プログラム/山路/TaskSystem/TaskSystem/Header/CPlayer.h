/**
*@file
*@brief  �v���C���[�N���X
*@author �R�H
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