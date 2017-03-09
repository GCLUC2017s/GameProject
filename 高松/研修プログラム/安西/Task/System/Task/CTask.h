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
	CTask *m_prev;					//�O�̃A�h���X���i�[����|�C���^�[
	CTask *m_next;					//���̃A�h���X���i�[����|�C���^�[
public:
	CTask();						//CTask�N���X�̃R���X�g���N�^
	~CTask();						//CTask�N���X�̃f�X�g���N�^
	virtual void Update();			//�h����N���X�ł̍X�V���s���֐�
	virtual void Render();			//�h����N���X�ł̕`�ʂ��s���֐�
	friend class CTaskManager;
};

class CTaskManager
{
protected:
	CTask *m_head;					//���݂̃A�h���X�ƑO�̃A�h���X���q�����߂̃|�C���^�[
	CTask *m_tail;					//���݂̃A�h���X�Ǝ��̃A�h���X���q�����߂̃|�C���^�[
public:
	CTaskManager();
	~CTaskManager();
	void Add(CTask *p);
	void Kill();
	void AllUpdate();
	void AllRender();
};

#endif // !TASK_GUARD