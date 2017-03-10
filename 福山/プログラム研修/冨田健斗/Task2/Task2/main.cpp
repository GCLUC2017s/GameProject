#include "CEnemy.h"
#include "CPlayer.h"
#include "CTaskManager.h"
#include <Windows.h>
#define ENEMYE_ARRAY_SIZE 10 //�G�l�~�[��
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
		taskmanger.Add(task);
		if (i == 1){ task->mHitPoint = 0; }//�͂��߈ȊO�̓q�b�g�|�C���g��0�ɂ���

	}






	for (int frame = 0; true; frame++) {
		task = taskmanger.mRoot;
		taskmanger.AbsR();

		if (frame % 10 == 0) { //�t���[�����ƂɈ�̑��₷
			task = new CPlayer;
			taskmanger.Add(task);
			task = new CEnemy;
			taskmanger.Add(task);
		}
		while (task != 0)
		{
			if (task->mHitPoint == 0){ //HP��0�̎�����
				taskmanger.Kill(&task);
			}
			else{
				task->Render();
			}

			task = task->next;
		}
		   printf( "%d���[����\n", frame );
	}

	getchar();
}