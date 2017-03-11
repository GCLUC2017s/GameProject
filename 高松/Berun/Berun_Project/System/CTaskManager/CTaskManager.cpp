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
	//削除するタスクの「前タスクの次の位置」を削除するタスクの「次タスクの位置」に繋ぐ。
	if(prev)prev->mp_next = next;
	//削除するタスクの「次タスクの前の位置」を削除するタスクの「前タスクの位置」に繋ぐ。
	if(next)next->mp_prev = prev;
	//その後、指定した特定のタスクを削除する。
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
	printf("これはCTaskManagerクラスの描画処理です。\n");
}