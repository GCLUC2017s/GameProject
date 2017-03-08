/**
*@file
*@brief  ���C�����[�v
*@author �R�H
*/

#include "../TaskSystem/Task/CTask.h"
#include "Player\CPlayer.h"
#include "Enemy\CEnemy.h"

void main()
{
	CTaskManager task;
	for (;;)
	{
		task.Add(new CPlayer());
		task.Add(new CEnemy());
		//task.Destroy(delete CPlayer());
		//task.Destroy(delete CEnemy());
	}
}