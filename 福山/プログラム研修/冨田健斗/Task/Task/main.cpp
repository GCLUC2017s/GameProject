#include "CEnemy.h"
#include "CPlayer.h"
#include "CTaskManager.h"
#include <Windows.h>
#define ENEMYE_ARRAY_SIZE 5 //�G�l�~�[��
#define PLAYER_ARRAY_SIZE 2 //�v���C���[��



int main(){

	
		CTask *task;
		CTaskManager taskmanger;

		for (int i = 0; i < ENEMYE_ARRAY_SIZE; i++)
		{
			task = new CEnemy;
			taskmanger.Add(task);
		}

		for (int i = 0; i < PLAYER_ARRAY_SIZE; i++)
		{
			
			task = new CPlayer;
			task->mHitPoint = 10;
			taskmanger.Add(task);
		}



	

		task = taskmanger.mRoot;

		while (task != 0)
		{
			if (task->mHitPoint == 0) //�q�b�g�|�C���g���Ȃ����̂�����
			{
				taskmanger.Kill(&task);
			}
			else{ //����΃A�b�v�f�[�g
				task->Update();
			}
			
			task = task->next;
		}
	

	getchar();
}