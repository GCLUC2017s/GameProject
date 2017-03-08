#include "CEnemy.h"
#include "CPlayer.h"
#include "CTaskManager.h"

int main(){

	
		CTask *task;
		CTaskManager taskmanger;

		task = new CEnemy;
		taskmanger.Abb(task);

		task = new CPlayer;
		taskmanger.Abb(task);



		while (task != 0)
		{
			task->Update();
			task = task->next;
		}
	

	getchar();
}