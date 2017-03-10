#include "CTask.h"

CTask::CTask() : m_kill(false),m_prev(nullptr),m_next(nullptr)
{
	printf("�����CTask�N���X�̃R���X�g���N�^�ł��B\n");
}
CTask::~CTask()
{
	printf("�����CTask�N���X�̃f�X�g���N�^�ł��B\n");
}
void CTask::Update()
{
	//�h����Œ�`
}
void CTask::Render()
{
	printf("�����CTask�N���X�̕`��֐��ł��B\n");
}



CTaskManager::CTaskManager()
{
	printf("�����CTaskManager�N���X�̃R���X�g���N�^�ł��B\n");
}
CTaskManager::~CTaskManager()
{
	printf("�����CTaskManager�N���X�̃f�X�g���N�^�ł��B\n");
}
void CTaskManager::Add(CTask *p)
{
	if (!m_head)
	{
		m_head = p;
	}
	else
	{
		p->m_prev = m_tail;
		m_tail->m_next = p;
	}

	m_tail = p;
}
CTask* CTaskManager::Kill(CTask *p)
{
	delete p;
	return next;
}
void CTaskManager::KillCheck()
{
	CTask *t = m_head;
	while (t)
	{
		if (t->m_kill) t=Kill(t);
		else t = t->m_next;
	}
}
void CTaskManager::AllUpdate()
{
	CTask *t = m_head;
	while (t)
	{
		t->Update();
		t = t->m_next;
	}
	
}
void CTaskManager::AllRender()
{
	CTask *t = m_head;
	while (t)
	{
		t->Render();
		t = t->m_next;
	}
	printf("�����CTaskManager�N���X�̕`�揈���ł��B\n");
}
