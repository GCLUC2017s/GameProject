#ifndef INCLUDEGAURD
#define INCLUDEGAURD
#include<stdio.h>
#include"CTask.h"

class CTaskManeger:public CTask {
	CTask *m_start;
	CTask *m_goal;

	CTaskManeger(){}

	~CTaskManeger() {
		CTask *p;
		p = m_start;
	}
	void Add(CTask *p) {
		if (!m_start) {
			m_start = p;
		} else{
			CTask *t = m_start;
			while (t->m_next)
			{
				t = t->m_next;
			}
			t->m_next = p;
		}
	}
	void Kill(CTask *p) {
		CTask *t=
		while (p)
		{

		}
	}
}; 
#endif // !INCLUDEGAURD