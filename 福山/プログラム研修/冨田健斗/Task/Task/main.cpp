#include "CEnemy.h"
#include "CPlayer.h"
#include "CTaskManager.h"
#include <Windows.h>


int main(){

	
		CTask *task;
		CTaskManager taskmanger;

		for (int i = 0; i < 10; i++)
		{
			task = new CEnemy;
			taskmanger.Add(task);
		}

		
		CTask *delete_task; //Á‚µ‚½‚¢ƒ^ƒXƒN‚ð“ü‚ê‚é 
		delete_task = taskmanger.root;
		printf("%p\n", delete_task);

		taskmanger.Kill(delete_task);
		taskmanger.Kill(delete_task);
		taskmanger.Kill(delete_task);
		taskmanger.Kill(delete_task);
		printf("%p\n", delete_task);
		
		


		task = new CPlayer;
		taskmanger.Add(task);


		task = taskmanger.root;

		while (task != 0)
		{
			task->Update();
			task = task->next;
		}
	

	getchar();
}