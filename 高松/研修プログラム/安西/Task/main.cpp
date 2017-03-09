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
		//10�t���[����1��AEnemy�𑝂₷�B
		if (frame % 10 == 0)
		{
			//l_taskManager.Add(new );
		}
		g_taskManager.AllUpdate();	//�o�^�ς݂̃^�X�N�̑S���s
		g_taskManager.AllRender();	//�o�^�ς݂̃^�X�N�̑S�`��
		printf("%d�t���[����\n", frame);
	}
	

	getchar();
}