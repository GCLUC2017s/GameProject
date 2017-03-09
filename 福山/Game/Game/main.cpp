#include "CEnemy.h"
#include "CPlayer.h"
#include "CTaskManager.h"
#include <Windows.h>
#define ENEMYE_ARRAY_SIZE 10 //エネミー数
#define PLAYER_ARRAY_SIZE 2 //プレイヤー数



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
		if (i == 1){ taskR->mHitPoint = 0; }//はじめ以外はヒットポイントを0にする

	}






	for (int frame = 0; true; frame++) {
		taskR = taskmanger.mRoot;

		if (frame % 10 == 0) { //フレームごとに一体増やす
			taskR = new CPlayer;
			taskmanger.Add(taskR);
			taskR = new CEnemy;
			taskmanger.Add(taskR);
		}
		while (taskR != 0)
		{
			if (taskR->mHitPoint == 0){ //HPが0の時消す
				taskmanger.Kill(&taskR);
			}
			else{
				taskR->Update();
			}

			taskR = taskR->next;
		}
		   printf( "%dレーム目\n", frame );
	}

	getchar();
}