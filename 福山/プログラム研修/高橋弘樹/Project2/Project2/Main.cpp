//メイン処理
//高橋弘樹
#include <stdio.h>
#include "Taskmanager.h"
#include "Task.h"
#include "Text.h"
#include "Text2.h"

Taskmanager *taskmanager;

void main(){
	Task *n;//場所


	while (n != 0)//始まり番地が０以外の時
	{
		n->Update();

		n = n->mNext;
	}

	if (GetKeyState('A') & 0x8000){
		Task *p = new Task();


		p->mPrev = taskmanager->mTail;

		taskmanager->mTail->mNext = p;

		taskmanager->mTail = p;




	}




	getchar();
}



