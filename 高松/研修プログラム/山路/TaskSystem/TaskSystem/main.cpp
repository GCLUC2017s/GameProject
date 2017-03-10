/**
*@file
*@brief  ���C�����[�v
*@author �R�H
*/

#include "../TaskSystem/Task/CTask.h"
#include "../TaskSystem/TaskManager/CTaskManager.h"
#include "Player\CPlayer.h"
#include "Enemy\CEnemy.h"

void main()
{
	//���[�v������I
	CTaskManager task;

	for (int i = 0; i < 5; i++)
	{
		//�G�l�~�[�I�u�W�F�N�g�ǉ�
		task.Add(new CEnemy());
	}
	for (int i = 0; i < 5; i++)
	{
		//�v���C���[�I�u�W�F�N�g�ǉ�
		task.Add(new CPlayer());
	}
	
	for (;;)
	{
		task.ListUpdate();
		task.ListRender();
	}
}