/* タスクシステム　宮田*/
#ifndef INCLUDEGAURD
#define INCLUDEGAURD
#include<stdio.h>
#endif // !INCLUDEGAURD
class CTask {
public:
	virtual void Update() {};
	char  m_name;
	int  m_type;
	CTask *m_next;
	virtual void Print() {
		printf("%s");
	}
	CTask() :m_name(0), m_type(0), m_next() {
		printf("CTaskのコンストラクタ\n");
	}

	~CTask() {
		printf("CTaskのデストラクタ\n");
	}



};
CTask *p = new CTask();







