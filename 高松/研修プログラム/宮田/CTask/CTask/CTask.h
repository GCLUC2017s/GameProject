/* �^�X�N�V�X�e���@�{�c*/
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
		printf("CTask�̃R���X�g���N�^\n");
	}

	~CTask() {
		printf("CTask�̃f�X�g���N�^\n");
	}



};
CTask *p = new CTask();







