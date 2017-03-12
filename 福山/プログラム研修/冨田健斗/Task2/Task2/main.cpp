#include "CEnemy.h"
#include "CPlayer.h"
#include "CTaskManager.h"
#include <Windows.h>
#define ENEMYE_ARRAY_SIZE 10 //�G�l�~�[��
#define PLAYER_ARRAY_SIZE 10 //�v���C���[��



int main(){


	
	CTaskManager taskmanger;
	CTask *task = taskmanger.mRoot;
	

	for (int frame = 0; true; frame++) {
		task = taskmanger.mRoot;

		if (frame % 10 == 0) { //�t���[�����ƂɈ�̑��₷
			taskmanger.Add(new CPlayer);
			taskmanger.Add(new CEnemy);

		}

		taskmanger.AbsR();

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