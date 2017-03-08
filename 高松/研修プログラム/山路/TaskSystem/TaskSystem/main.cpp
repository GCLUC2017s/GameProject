/**
*@file
*@brief  メインループ
*@author 山路
*/

#include "../TaskSystem/Task/CTask.h"
#include "Player\CPlayer.h"
#include "Enemy\CEnemy.h"

void main()
{
	CTaskManager task;
	CTask           *p;
	for (int i = 0; i < 5; i++)
	{
		task.Add(new CEnemy(i));
	}
	for (int i = 0; i < 5; i++)
	{
		p = new CEnemy(i);
		task.Add(p);
	}
	for(;;)
	{
		if (flame % 10 == 0)
		{
			task.Add(new CEnemy());
		}
		task.Update();
		task.Render();
		printf("フレーム"flame);
	}


}