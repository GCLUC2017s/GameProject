//���C������
//�����O��
#include <stdio.h>
#include "Taskmanager.h"
#include "Task.h"
#include "Text.h"
#include "Text2.h"

Taskmanager *taskmanager;

void main(){
	Task *n;//�ꏊ


	while (n != 0)//�n�܂�Ԓn���O�ȊO�̎�
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



