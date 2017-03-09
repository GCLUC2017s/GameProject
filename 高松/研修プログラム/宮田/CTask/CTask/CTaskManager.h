#ifndef CTASK_EGAURD
#define CTASK_EGAURD
#include<stdio.h>
#include"CTask.h"

class CTaskManeger:public CTask {
	
	void Add(CTask * p);
	void Kill();

	CTaskManeger();

	~CTaskManeger();
	void Update();
	void Draw();

	
	void Kill(CTask *p) {
		if (p != m_start) {
			delete p;
		}
	}
}; 
#endif // !INCLUDEGAURD