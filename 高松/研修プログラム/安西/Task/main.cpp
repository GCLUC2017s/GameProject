#include <stdio.h>
#include <math.h>
#include "System\CTask.h"
#include "Game\CPlayer.h"
#include "Game\CEnemy.h"

CTask *p;
CTaskManager g_taskManager;

void main()
{

	p = new CPlayer();
	g_taskManager.Add(p);
	g_taskManager.Add(new CEnemy());
	for (int i = 0; i < 5; i++)
	{
		g_taskManager.Add(new CTask());
	}

			g_taskManager.AllUpdate();	//�o�^�ς݂̃^�X�N�̑S���s
			g_taskManager.KillCheck();
			g_taskManager.AllRender();	//�o�^�ς݂̃^�X�N�̑S�`��
		
	

	getchar();
}