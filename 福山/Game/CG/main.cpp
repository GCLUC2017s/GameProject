#include "CEnemy.h"
#include "CPlayer.h"
#include "CTaskManager.h"
#include <Windows.h>
#define ENEMYE_ARRAY_SIZE 10 //�G�l�~�[��
#define PLAYER_ARRAY_SIZE 2 //�v���C���[��



int main(){


	CTask *taskR;
	CTask *taskU;
	CTaskManager taskmanger;

	for (int i = 0; i < ENEMYE_ARRAY_SIZE; i++)
	{
		taskR = new CEnemy;
		taskmanger.Add(taskR);
	}

	for (int i = 0; i < PLAYER_ARRAY_SIZE; i++)
	{

		taskR = new CPlayer;
		taskmanger.Add(taskR);
		if (i == 1){ taskR->mHitPoint = 0; }//�͂��߈ȊO�̓q�b�g�|�C���g��0�ɂ���

	}






	for (int frame = 0; true; frame++) {
		taskR = taskmanger.mRoot;

		if (frame % 10 == 0) { //�t���[�����ƂɈ�̑��₷
			taskR = new CPlayer;
			taskmanger.Add(taskR);
			taskR = new CEnemy;
			taskmanger.Add(taskR);
		}
		while (taskR != 0)
		{
			if (taskR->mHitPoint == 0){ //HP��0�̎�����
				taskmanger.Kill(&taskR);
			}
			else{
				taskR->Update();
			}

			taskR = taskR->next;
		}
		   printf( "%d���[����\n", frame );
	}

	getchar();
}