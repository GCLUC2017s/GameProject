#include "CTaskManager.h"

CTaskManager::CTaskManager()
{
	printf("これはCTaskManagerクラスのコンストラクタです。\n");
}
CTaskManager::~CTaskManager()
{
	printf("これはCTaskManagerクラスのデストラクタです。\n");
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
	//削除するタスクの「前タスクの次の位置」を削除するタスクの「次タスクの位置」に繋ぐ。
	p->m_prev->m_next = p->m_next;
	//削除するタスクの「次タスクの前の位置」を削除するタスクの「前タスクの位置」に繋ぐ。
	p->m_next->m_prev = p->m_prev;
	//その後、指定した特定のタスクを削除する。
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
	printf("これはCTaskManagerクラスの描画処理です。\n");
}