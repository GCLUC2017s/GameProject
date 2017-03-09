/* タスクシステム　宮田*/
#include<stdio.h>
#ifndef CTask_GAURD
#define CTask_GAURD
class CTask {
public:
	
	char  m_name[32];
	int  m_type;
	CTask *m_start;//前のアドレスを繋ぐ
	CTask *m_goal;//次のアドレスを繋ぐ
	CTask *m_retrun;//前のアドレスのポインター
	CTask *m_next;//次のアドレスのポインター

	virtual void Print() {
		printf("%s,%d",m_name,m_type);
	}
	CTask();

	~CTask();
	virtual void Add(CTask *p);
	virtual void Update();
	virtual void Draw();
	friend class CtaskManager;

};
#endif // !INCLUDEGAURD







