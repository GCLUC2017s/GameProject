//ƒƒCƒ“ˆ—
//‚‹´O÷
#include <stdio.h>
#include <Windows.h>
#include "Taskmanager.h"
#include "Task.h"
#include "Text.h"
#include "Text2.h"

Taskmanager *taskmanager;



void main(){
	Task *n;
	n = taskmanager->mRoot;
	while (n != 0)
	{
		n->Update();

		n = n->mNext;
	}

Task *p = new Task();


		p->mPrev = taskmanager->mTail;

		taskmanager->mTail->mNext = p;

		taskmanager->mTail = p;
	

	getchar();
}


