#include "CTaskManager.h"

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
void CTaskManager::Kill(CTask *p)
{
	//�폜����^�X�N�́u�O�^�X�N�̎��̈ʒu�v���폜����^�X�N�́u���^�X�N�̈ʒu�v�Ɍq���B
	p->m_prev->m_next = p->m_next;
	//�폜����^�X�N�́u���^�X�N�̑O�̈ʒu�v���폜����^�X�N�́u�O�^�X�N�̈ʒu�v�Ɍq���B
	p->m_next->m_prev = p->m_prev;
	//���̌�A�w�肵������̃^�X�N���폜����B
	delete p;
}
void CTaskManager::AllKill(CTask * p)
{
}
void CTaskManager::KillCheck()
{
	CTask *t = m_head;
	while (t)
	{
		if (t->m_kill) Kill(t);
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