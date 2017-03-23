#include "CTaskManager.h"

CTaskManager* CTaskManager::mp_instance = nullptr;
CTaskManager::CTaskManager() : mp_head(nullptr), mp_tail(nullptr)
{
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
		//mp_head->mp_prev = nullptr;
		//mp_head->mp_next = p;
		//mp_tail = p;
	}
	//�擪�����݂��Ă����
	else
	{
		p->mp_prev = mp_tail;
		mp_tail->mp_next = p;
		/*
		CTask temp;
		CTask *t = &temp;
		t->mp_next = mp_head;

		while (t != mp_tail)
		{
			t = t->mp_next;

			if (t == mp_head && t->m_drawPrio > t->m_drawPrio) 
			{ 
				mp_head = t;
				mp_head->mp_prev = nullptr;
				t->mp_prev = t;
				if (!t->mp_next) mp_tail = t;
				break;
			}
			else if (t == mp_tail) 
			{
				t->mp_prev = mp_tail;
				mp_tail->mp_next = t;
				mp_tail = t;
				mp_tail->mp_next = nullptr;
				break;
			}
			else if (t->m_drawPrio <= p->m_drawPrio && p->m_drawPrio <= t->mp_next->m_drawPrio) 
			{ 
				p->mp_next = t->mp_next;
				p->mp_prev = t;
				t->mp_next->mp_prev = p;
				t->mp_next = p;
				break;
			}
		}*/
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
void CTaskManager::DestroyAppoint()
{
	//�擪���珇�ɍ폜�t���O���^�̃^�X�N���폜���Ă���
	CTask *p = mp_head;
	while (p)
	{
		if (p->m_destroyFlg) p = Destroy(p);
		else p = p->mp_next;
	}
}

void CTaskManager::DestroyAll()
{
	//�擪����^�X�N���폜���Ă���
	CTask *p = mp_head;
	while (p)
	{
		p = Destroy(p);
	}
}
void CTaskManager::UpdateAll()
{
	//�擪���珇�Ƀ^�X�N���X�V���Ă���
	CTask *p = mp_head;
	while (p)
	{
		p->Update();
		p = p->mp_next;
	}
}
void CTaskManager::DrawAll()
{
	//�擪���珇�Ƀ^�X�N��`�悵�Ă���
	CTask *p = mp_head;
	while (p)
	{
		p->Draw();
		p = p->mp_next;
	}
}

void CTaskManager::SwapTask(CTask **p, CTask **n)
{
	CTask *t = *n;
	*n = *p;
	*p = t;
}

void CTaskManager::SortAscUpdate()
{
	CTask temp;
	CTask *p = &temp;
	CTask *n = &temp;

	//���ꂼ��̎��̃^�X�N��擪�ɐݒ�
	p->mp_next = mp_head;
	n->mp_next = mp_head;

	//p�̎��̃^�X�N�������Ŗ������
	while (p->mp_next != mp_tail)
	{
		//p�̎��̃^�X�N��p�ɑ��
		p = p->mp_next;
		//�ύX�������p�̎��̃^�X�N��n�ɑ��
		n = p->mp_next;

		//�X�V�����̔�r
		if (p->m_updatePrio > n->m_updatePrio)
		{
			//���p�ϐ�
			CTask tp;
			CTask tn;
			//����ւ�
			SwapTask(&p, &n);
			//�^�X�N���
			tp.mp_prev = p->mp_prev;
			tp.mp_next = p->mp_next;
			tn.mp_prev = n->mp_prev;
			tn.mp_next = n->mp_next;
			//��������ւ�
			p->mp_prev = tn.mp_prev;
			p->mp_next = tp.mp_prev;
			n->mp_next = tp.mp_next;
			n->mp_prev = tn.mp_next;

			if (!p->mp_prev) mp_head = p;
			if (!n->mp_next) mp_tail = n;
			if (p->mp_prev) p->mp_prev->mp_next = p;
			if (p->mp_next) p->mp_next->mp_prev = p;
			if (n->mp_prev) n->mp_prev->mp_next = n;
			if (n->mp_next) n->mp_next->mp_prev = n;
			
			p = mp_head;
		}
	}
}

void CTaskManager::SortAscDraw()
{
	CTask temp;
	CTask *p = &temp;
	CTask *n = &temp;

	//���ꂼ��̎��̃^�X�N��擪�ɐݒ�
	p->mp_next = mp_head;
	n->mp_next = mp_head;

	//p�̎��̃^�X�N�������Ŗ������
	while (p->mp_next != mp_tail)
	{
		//p�̎��̃^�X�N��p�ɑ��
		p = p->mp_next;
		//�ύX�������p�̎��̃^�X�N��n�ɑ��
		n = p->mp_next;

		//�X�V�����̔�r
		if (p->m_drawPrio > n->m_drawPrio)
		{
			//���p�ϐ�
			CTask tp;
			CTask tn;
			//����ւ�
			SwapTask(&p, &n);
			//�^�X�N���
			tp.mp_prev = p->mp_prev;
			tp.mp_next = p->mp_next;
			tn.mp_prev = n->mp_prev;
			tn.mp_next = n->mp_next;
			//��������ւ�
			p->mp_prev = tn.mp_prev;
			p->mp_next = tp.mp_prev;
			n->mp_next = tp.mp_next;
			n->mp_prev = tn.mp_next;

			if (!p->mp_prev) mp_head = p;
			if (!n->mp_next) mp_tail = n;
			if (p->mp_prev) p->mp_prev->mp_next = p;
			if (p->mp_next) p->mp_next->mp_prev = p;
			if (n->mp_prev) n->mp_prev->mp_next = n;
			if (n->mp_next) n->mp_next->mp_prev = n;

			p = mp_head;
		}
	}
}

CTask* CTaskManager::GetTask(int id)
{
	CTask *p;
	//�����������
	while (p&&id)
	{
		//id����v���Ă���΂��̃^�X�N��Ԃ�
		if (p->m_id == id) return p;
		p = p->mp_next;
	}
	
	//�ȊO�Ȃ�null��Ԃ�
	return nullptr;
}

int CTaskManager::GetCount(int id)
{
	int cnt = 0;
	CTask *p;
	//�����������
	while (id)
	{
		//id����v���Ă���΃J�E���g�A�b�v
		if(p->m_id == id) cnt++;
	}
	//����Ԃ�
	return cnt;
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
