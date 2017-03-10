#include "CTask.h"

CTask::CTask() : m_kill(false),m_prev(nullptr),m_next(nullptr)
{
	printf("これはCTaskクラスのコンストラクタです。\n");
}
CTask::~CTask()
{
	printf("これはCTaskクラスのデストラクタです。\n");
}
void CTask::Update()
{
	//派生先で定義
}
void CTask::Render()
{
	printf("これはCTaskクラスの描画関数です。\n");
}



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
CTask* CTaskManager::Kill(CTask *p)
{
	delete p;
	return next;
}
void CTaskManager::KillCheck()
{
	CTask *t = m_head;
	while (t)
	{
		if (t->m_kill) t=Kill(t);
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
