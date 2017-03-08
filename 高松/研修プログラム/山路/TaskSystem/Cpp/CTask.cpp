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
	//継承先で定義
}

void CTaskManager::Add(CTask *p)
{
	//先頭要素が存在しなければ
	if (!mp_head)
	{
		//追加されたオブジェクトを先頭に
		mp_head = p;
	}
	//末尾要素が存在しなければ
	else if (!mp_tail)
	{
		//追加されたオブジェクトを末尾に
		mp_tail = p;
	}
	//それ以外なら
	else
	{
		CTask *tail = mp_tail;
		while (tail->mp_next)
		{
			tail = tail->mp_next;
		}
		//二回目以降の追加はこちらの処理
		//末尾の次の要素は新しく追加されたオブジェクトを指す
		tail->mp_next = p;
	}
}

void CTaskManager::Destroy(CTask *p)
{
}

void CTask::Print()
{
	printf("名前%s\n", m_name);
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
