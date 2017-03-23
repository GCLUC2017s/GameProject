#include "CollisionManager.h"

CCollisionManager* CCollisionManager::mp_instance = nullptr;
CCollisionManager::CCollisionManager() :	mp_head(nullptr), 
											mp_tail(nullptr)
{

}

CCollisionManager::~CCollisionManager()
{

}

void CCollisionManager::Regist(CCollisionA *p)
{
	//�擪�����݂��Ȃ����
	if (!mp_head)
	{
		//�ǉ����ꂽ�^�X�N��擪��
		mp_head = p;
		mp_tail = p;
	}
	//�擪�����݂��Ă����
	else
	{
		p->mp_prev = mp_tail;
		mp_tail->mp_next = p;
		p->mp_next = nullptr;
		mp_tail = p;
	}
}

CCollisionA *CCollisionManager::UnRegist(CCollisionA *p)
{
	CCollisionA *next = p->mp_next;
	CCollisionA *prev = p->mp_prev;
	if (p == mp_head) mp_head = next;
	if (p == mp_tail) mp_tail = prev;
	//�폜����^�X�N�́u�O�^�X�N�̎��̈ʒu�v���폜����^�X�N�́u���^�X�N�̈ʒu�v�Ɍq���B
	if (prev)prev->mp_next = next;
	//�폜����^�X�N�́u���^�X�N�̑O�̈ʒu�v���폜����^�X�N�́u�O�^�X�N�̈ʒu�v�Ɍq���B
	if (next)next->mp_prev = prev;
	p->mp_next = nullptr;
	p->mp_prev = nullptr;
	return next;
}
void CCollisionManager::UnRegistAll()
{
	//�擪��������Ă���
	CCollisionA *p = mp_head;
	while (p)
	{
		p = UnRegist(p);
	}
	mp_head = nullptr;
	mp_tail = nullptr;

}
void CCollisionManager::CheckHitAll()
{
	CCollisionA *p = mp_head;
	while (p)
	{
		CCollisionA *q = mp_head;
		while (q)
		{
			if(p != q) p->CheckHit(q);
			q = q->mp_next;
		}
		p = p->mp_next;
	}
}

CCollisionManager* CCollisionManager::GetInstance()
{
	//CCollisionManager����x�̂݁i�V���O���g���j�������Ċi�[
	if (mp_instance == nullptr)
	{
		mp_instance = new CCollisionManager();
	}
	//�����Ԃ�
	return mp_instance;
}

void CCollisionManager::ClearInstance()
{
	//���������[�N���
	if (mp_instance != nullptr) delete mp_instance;
}