#include <stdio.h>
#include <math.h>
#include "System\CTask.h"
#include "Game\CPlayer.h"



void main()
{
	CTaskManager l_taskManager;

	l_taskManager.Add(new CTask());
	l_taskManager.Add(new CPlayer());

	for (;true;)
	{
		l_taskManager.AllUpdate();
	}
	

	getchar();
}