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
	if (!mp_head)
	{
		mp_head = p;
	}
	else
	{
		p->mp_prev = mp_tail;
		mp_tail->mp_next = p;
	}

	mp_tail = p;
}
CTask* CTaskManager::Kill(CTask *p)
{
	CTask *next = p->mp_next;
	CTask *prev = p->mp_prev;
	//�폜����^�X�N�́u�O�^�X�N�̎��̈ʒu�v���폜����^�X�N�́u���^�X�N�̈ʒu�v�Ɍq���B
	if(prev)prev->mp_next = next;
	//�폜����^�X�N�́u���^�X�N�̑O�̈ʒu�v���폜����^�X�N�́u�O�^�X�N�̈ʒu�v�Ɍq���B
	if(next)next->mp_prev = prev;
	//���̌�A�w�肵������̃^�X�N���폜����B
	delete p;
	return next;
}
void CTaskManager::KillCheck()
{
	CTask *t = mp_head;
	while (t)
	{
		if (t->m_kill) Kill(t);
		else t = t->mp_next;
	}
}
void CTaskManager::AllUpdate()
{
	CTask *t = mp_head;
	while (t)
	{
		t->Update();
		t = t->mp_next;
	}

}
void CTaskManager::AllRender()
{
	CTask *t = mp_head;
	while (t)
	{
		t->Render();
		t = t->mp_next;
	}
	printf("�����CTaskManager�N���X�̕`�揈���ł��B\n");
}