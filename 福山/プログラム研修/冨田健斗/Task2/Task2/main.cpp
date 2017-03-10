#include "CEnemy.h"
#include "CPlayer.h"
#include "CTaskManager.h"
#include <Windows.h>
#define ENEMYE_ARRAY_SIZE 10 //�G�l�~�[��
#define PLAYER_ARRAY_SIZE 2 //�v���C���[��



int main(){


	
	CTaskManager taskmanger;
	CTask *task = taskmanger.mRoot;

	for (int i = 0; i < ENEMYE_ARRAY_SIZE; i++)
	{
		taskmanger.Add(new CPlayer);
	}

	for (int i = 0; i < PLAYER_ARRAY_SIZE; i++)
	{
		task = new CPlayer;
		taskmanger.Add(task);
		if (i == 0){ task->mHitPoint = 10; }//�͂��߈ȊO�̓q�b�g�|�C���g��0�ɂ���

	}



	for (int frame = 0; true; frame++) {
		task = taskmanger.mRoot;

		if (frame % 10 == 0) { //�t���[�����ƂɈ�̑��₷
			taskmanger.Add(new CPlayer);
			taskmanger.Add(new CEnemy);
		}
		while (task != 0)
		{
			if (task->mHitPoint == 0){ //HP��0�̎�����
				taskmanger.Kill(&task);
			}
			else{

			//	taskmanger.AbsR(&task);

				task->Render();
			}

			task = task->next;
		}
		   printf( "%d���[����\n", frame );
	}

	getchar();
}