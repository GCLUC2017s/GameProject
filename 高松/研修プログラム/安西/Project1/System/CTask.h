#include<stdio.h>

class CTask
{
protected:
	CTask *m_prev;	//�O�̃A�h���X���i�[����|�C���^�[
	CTask *m_next;	//���̃A�h���X���i�[����|�C���^�[
public:
	CTask();		//CTask�N���X�̃R���X�g���N�^
	~CTask();		//CTask�N���X�̃f�X�g���N�^
	virtual void Update();	//�h����N���X�ł̍X�V���s���֐�
	virtual void Render();	//�h����N���X�ł̕`�ʂ��s���֐�
	friend class CTaskManager;
};

class CTaskManager
{
protected:
public:
	CTaskManager();
	~CTaskManager();
	void Update();
	void Render();
	void Add(CTask *p);
};