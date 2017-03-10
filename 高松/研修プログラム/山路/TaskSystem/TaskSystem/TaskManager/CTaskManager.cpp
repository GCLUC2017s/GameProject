#include "../TaskManager/CTaskManager.h"

CTaskManager::CTaskManager() : mp_head(nullptr), mp_tail(nullptr)
{

}

void CTaskManager::ListUpdate()
{
	for (;;)
	{
		printf("���X�g�X�V");
	}
}

void CTaskManager::ListRender()
{
	for (;;)
	{
		printf("���X�g�`��");
	}
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

void CTaskManager::Destroy()
{

}

void CTaskManager::ListDestroy()
{

}

void CTaskManager::Pause()
{

}