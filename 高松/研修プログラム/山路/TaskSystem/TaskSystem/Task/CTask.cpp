#include "../Task/CTask.h"
#include "../Enemy/CEnemy.h"
#include "../Player/CPlayer.h"


CTask::CTask() : mp_head(nullptr), mp_tail(nullptr), mp_prev(nullptr), mp_next(nullptr)
{
	printf("CTask�R���X�g���N�^�Ăяo��\n");
}

CTask::~CTask()
{
	printf("CTask�f�X�g���N�^�Ăяo��\n");
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
	//�v�f�����݂��Ă����
	if (p)
	{
		delete p;
	}
}
