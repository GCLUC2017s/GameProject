#include <stdio.h>
#include <math.h>
#include "System\CTask.h"
#include "Game\CPlayer.h"
#include "Game\CEnemy.h"

CTaskManager g_taskManager;

void main()
{

	g_taskManager.Add(new CTask());
	g_taskManager.Add(new CPlayer());
	for (int i = 0; i < 5; i++)
	{
		g_taskManager.Add(new CEnemy());
	}

	for (int frame;true;frame++)
	{
		//10フレームに1回、Enemyを増やす。
		if (frame % 10 == 0)
		{
			//l_taskManager.Add(new );
		}
		g_taskManager.AllUpdate();	//登録済みのタスクの全実行
		g_taskManager.AllRender();	//登録済みのタスクの全描画
		printf("%dフレーム目\n", frame);
	}
	

	getchar();
}