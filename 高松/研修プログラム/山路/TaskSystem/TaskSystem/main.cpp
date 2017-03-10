/**
*@file
*@brief  メインループ
*@author 山路
*/

#include "../TaskSystem/Task/CTask.h"
#include "../TaskSystem/TaskManager/CTaskManager.h"
#include "Player\CPlayer.h"
#include "Enemy\CEnemy.h"

void main()
{
	//ループさせる！
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
	
	for (;;)
	{
		task.ListUpdate();
		task.ListRender();
	}
}