#ifndef INCLUDEGAURD
#define INCLUDEGAURD
#include<stdio.h>
#endif // !INCLUDEGAURD
class CTask {
public:
	virtual void Update();
	CTask  *m_pos;
	CTask *m_type;
	bool m_isActive;
	char m_name[32];
	int m_tensuu;
	float m_point;
	
	CTask()  {
		printf("CTask�̃R���X�g���N�^\n");
	}
	
	~CTask() {
		printf("CTask�̃f�X�g���N�^\n");
	}
	


};
CTask *p = new CTask();


void CTask::Update()
{
	
}

class CPlayerTask:public CTask {
	
	

	CPlayerTask();
	~CPlayerTask();

	void Update();

	

};


class CTaskManeger {
	

};

