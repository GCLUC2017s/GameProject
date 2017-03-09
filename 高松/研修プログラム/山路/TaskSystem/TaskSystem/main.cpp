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

	for (int i = 0; i < 5; i++)
	{
		//エネミーオブジェクト追加
		task.Add(new CEnemy());
	}
	for (int i = 0; i < 5; i++)
	{
		//プレイヤーオブジェクト追加
		task.Add(new CPlayer());
	}
	
	getchar();
	//task.ListUpdate();
	//task.ListRender();
}