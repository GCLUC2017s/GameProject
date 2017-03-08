#ifndef INCLUDE_GURAD_TASK
#include "../Header/CTask.h"
#endif  INCLUDE_GURAD_TASK

CTask::CTask(char *name): mp_head(nullptr), mp_tail(nullptr), mp_next(nullptr), mp_prev(nullptr)
{
	strcpy_s(m_name, name);
}

CTask::~CTask()
{
}

void CTask::Update()
{
	//�p����Œ�`
}

void CTaskManager::Add(CTask *p)
{
	//�擪�v�f�����݂��Ȃ����
	if (!mp_head)
	{
		//�ǉ����ꂽ�I�u�W�F�N�g��擪��
		mp_head = p;
	}
	//�����v�f�����݂��Ȃ����
	else if (!mp_tail)
	{
		//�ǉ����ꂽ�I�u�W�F�N�g�𖖔���
		mp_tail = p;
	}
	//����ȊO�Ȃ�
	else
	{
		CTask *tail = mp_tail;
		while (tail->mp_next)
		{
			tail = tail->mp_next;
		}
		//���ڈȍ~�̒ǉ��͂�����̏���
		//�����̎��̗v�f�͐V�����ǉ����ꂽ�I�u�W�F�N�g���w��
		tail->mp_next = p;
	}
}

void CTaskManager::Destroy(CTask *p)
{
}

void CTask::Print()
{
	printf("���O%s\n", m_name);
}

void CTaskManager::DrawList()
{	
	CTask *head = mp_head;
	CTask *tail = mp_tail;
	CTask *next = mp_next;

	while (tail->mp_next)
	{
		head->Print();
		head = head->mp_next;
	}
}
