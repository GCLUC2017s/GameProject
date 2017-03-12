#include "CEnemy.h"
#include "CPlayer.h"
#include "CTaskManager.h"
#include <Windows.h>
#define ENEMYE_ARRAY_SIZE 10 //エネミー数
#define PLAYER_ARRAY_SIZE 10 //プレイヤー数



int main(){


	
	CTaskManager taskmanger;
	CTask *task = taskmanger.mRoot;
	

	for (int frame = 0; true; frame++) {
		task = taskmanger.mRoot;

		if (frame % 10 == 0) { //フレームごとに一体増やす
			taskmanger.Add(new CPlayer);
			taskmanger.Add(new CEnemy);

		}

		taskmanger.AbsR();

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