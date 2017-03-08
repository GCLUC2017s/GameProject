/* タスクシステム　宮田*/
#include<stdio.h>

class CTask {
public:
	virtual void Update() {};
	char  m_name[32];
	int  m_type;
	CTask *m_next;

	virtual void Print() {
		printf("%s,%d",m_name,m_type);
	}
	CTask() :m_name(), m_type(0), m_next() {
		printf("CTaskのコンストラクタ\n");
	}

	~CTask() {
		printf("CTaskのデストラクタ\n");
	}

	friend class CtaskManager;

};








