#include "CTaskManager.h"

CTaskManager::CTaskManager() : mp_head(nullptr), mp_tail(nullptr)
{
	CTaskManager* mp_instance = nullptr;
}
CTaskManager::~CTaskManager()
{
	
}
void CTaskManager::Add(CTask *p)
{
	//�擪�����݂��Ȃ����
	if (!mp_head)
	{
		//�ǉ����ꂽ�^�X�N��擪��
		mp_head = p;
	}
	//�擪�����݂��Ă����
	else
	{
		//
		p->mp_prev = mp_tail;
		mp_tail->mp_next = p;
	}

	mp_tail = p;
}
CTask* CTaskManager::Destroy(CTask *p)
{
	CTask *next = p->mp_next;
	CTask *prev = p->mp_prev;
	//�폜����^�X�N�́u�O�^�X�N�̎��̈ʒu�v���폜����^�X�N�́u���^�X�N�̈ʒu�v�Ɍq���B
	if(prev)prev->mp_next = next;
	//�폜����^�X�N�́u���^�X�N�̑O�̈ʒu�v���폜����^�X�N�́u�O�^�X�N�̈ʒu�v�Ɍq���B
	if(next)next->mp_prev = prev;
	//���̌�A�w�肵������̃^�X�N���폜���A���̃^�X�N��Ԃ��B
	delete p;
	return next;
}
void CTaskManager::AllDestroy()
{
	//�擪���珇�ɍ폜�t���O���^�̃^�X�N���폜���Ă���
	CTask *p = mp_head;
	while (p)
	{
		if (p->m_destroyFlg) Destroy(p);
		else p = p->mp_next;
	}
}
void CTaskManager::AllUpdate()
{
	//�擪���珇�Ƀ^�X�N���X�V���Ă���
	CTask *p = mp_head;
	while (p)
	{
		p->Update();
		p = p->mp_next;
	}
}
void CTaskManager::AllRender()
{
	//�擪���珇�Ƀ^�X�N��`�悵�Ă���
	CTask *p = mp_head;
	while (p)
	{
		p->Render();
		p = p->mp_next;
	}
}

CTaskManager* CTaskManager::GetInstance()
{
	//CTaskManager����x�̂݁i�V���O���g���j�������Ċi�[
	if (mp_instance == nullptr)
	{
		mp_instance = new CTaskManager();
	}
	//�����Ԃ�
	return mp_instance;
}

void CTaskManager::ClearInstance()
{
	//���������[�N���
	if (mp_instance != nullptr) delete mp_instance;
}
