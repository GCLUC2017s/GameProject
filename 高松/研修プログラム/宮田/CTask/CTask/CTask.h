/* �^�X�N�V�X�e���@�{�c*/
#include<stdio.h>
#ifndef CTask_GAURD
#define CTask_GAURD
class CTask {
public:
	
	char  m_name[32];
	int  m_type;
	CTask *m_start;//�O�̃A�h���X���q��
	CTask *m_goal;//���̃A�h���X���q��
	CTask *m_retrun;//�O�̃A�h���X�̃|�C���^�[
	CTask *m_next;//���̃A�h���X�̃|�C���^�[

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







