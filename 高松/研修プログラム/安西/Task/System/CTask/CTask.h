/**
* @file		CTask.h
* @brief	TaskSystem
*
* @author	ryoji anzai
*/

#ifndef TASK_GUARD
#define TASK_GUARD

#include<stdio.h>

class CTask
{
protected:
	bool m_kill;
	CTask *m_prev;					//�O�̃A�h���X���i�[����|�C���^�[
	CTask *m_next;					//���̃A�h���X���i�[����|�C���^�[
public:
	CTask();						//CTask�N���X�̃R���X�g���N�^
	virtual ~CTask();						//CTask�N���X�̃f�X�g���N�^
	virtual void Update();			//�h����N���X�ł̍X�V���s���֐�
	virtual void Render();			//�h����N���X�ł̕`�ʂ��s���֐�
	friend class CTaskManager;
};

class CTaskManager
{
protected:
	CTask *m_head;				
	CTask *m_tail;				
public:
	CTaskManager();
	~CTaskManager();
	void Add(CTask *p);
	void Kill(CTask *p);
	void KillCheck();
	void AllUpdate();
	void AllRender();
};

#endif // !TASK_GUARD