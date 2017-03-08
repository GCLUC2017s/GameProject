#include "CEnemy.h"
#include "CPlayer.h"
#include "CTaskManager.h"
#include <Windows.h>
#define ENEMYE_ARRAY_SIZE 10 //エネミー数
#define PLAYER_ARRAY_SIZE 2 //プレイヤー数



int main(){


	CTask *task;
	CTaskManager taskmanger;

	for (int i = 0; i < ENEMYE_ARRAY_SIZE; i++)
	{
		task = new CEnemy;
		taskmanger.Add(task);
		if (i < 5){ task->mHitPoint = 10; }
	}

	for (int i = 0; i < PLAYER_ARRAY_SIZE; i++)
	{

		task = new CPlayer;
		task->mHitPoint = 10;
		taskmanger.Add(task);
	}






	for (int frame = 0; true; frame++) {
		task = taskmanger.mRoot;

		while (task != 0)
		{
			if (task->mHitPoint == 0) //ヒットポイントがないものを消す
			{
				taskmanger.Kill(&task);
			}
			else{ //あればアップデート
				task->Update();
			}

			task = task->next;
		}
		   printf( "%dレーム目\n", frame );
	}

	getchar();
}