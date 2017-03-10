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
	}

	for (int i = 0; i < PLAYER_ARRAY_SIZE; i++)
	{

		task = new CPlayer;
		taskmanger.Add(task);
		if (i == 1){ task->mHitPoint = 0; }//はじめ以外はヒットポイントを0にする

	}






	for (int frame = 0; true; frame++) {
		task = taskmanger.mRoot;
		taskmanger.AbsR();

		if (frame % 10 == 0) { //フレームごとに一体増やす
			task = new CPlayer;
			taskmanger.Add(task);
			task = new CEnemy;
			taskmanger.Add(task);
		}
		while (task != 0)
		{
			if (task->mHitPoint == 0){ //HPが0の時消す
				taskmanger.Kill(&task);
			}
			else{
				task->Render();
			}

			task = task->next;
		}
		   printf( "%dレーム目\n", frame );
	}

	getchar();
}