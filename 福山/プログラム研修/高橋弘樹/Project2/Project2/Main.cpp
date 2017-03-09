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
	task = taskmanger.mRoot;
		if (i % 10 == 0) {
		task = new Text;
		taskmanger.Add(task);

		task = new Text2;
		taskmanger.Add(task);
		
		}
		while (task != 0)
		{
		task->Update();
		task = task->mNext;
		}
		printf("%d\n", i);
	}

	getchar();
}




