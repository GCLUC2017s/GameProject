//ƒƒCƒ“ˆ—
//‚‹´O÷
#include <stdio.h>
#include <Windows.h>
#include "Taskmanager.h"
#include "Task.h"
#include "Text.h"
#include "Text2.h"


int main(){
	Task *task;
	Taskmanager taskmanger;
	for (int i = 0; i < 10; i++)
	{
	task = new Text;
	taskmanger.Add(task);


	}
	for (int i = 0; i < 10; i++)
	{
	task = new Text2;
	taskmanger.Add(task);

	}
	
	for (int i = 0; true; i++) {
		int v=0;

			task = taskmanger.mRoot;
			if (i % 60 == 0) {
				task = new Text;
				taskmanger.Add(task);
				task->Update();
				task = new Text2;
				taskmanger.Add(task);
				task->Update();
			}
			while (task != 0)
			{
				printf("%d\n", i);
			
			}

		

			if (i > 50){
				break;
			}

		}
	
	getchar();
}




