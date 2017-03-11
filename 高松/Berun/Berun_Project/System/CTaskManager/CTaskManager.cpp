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
	//先頭が存在しなければ
	if (!mp_head)
	{
		//追加されたタスクを先頭に
		mp_head = p;
	}
	//先頭が存在していれば
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
	//削除するタスクの「前タスクの次の位置」を削除するタスクの「次タスクの位置」に繋ぐ。
	if(prev)prev->mp_next = next;
	//削除するタスクの「次タスクの前の位置」を削除するタスクの「前タスクの位置」に繋ぐ。
	if(next)next->mp_prev = prev;
	//その後、指定した特定のタスクを削除し、次のタスクを返す。
	delete p;
	return next;
}
void CTaskManager::AllDestroy()
{
	//先頭から順に削除フラグが真のタスクを削除していく
	CTask *p = mp_head;
	while (p)
	{
		if (p->m_destroyFlg) Destroy(p);
		else p = p->mp_next;
	}
}
void CTaskManager::AllUpdate()
{
	//先頭から順にタスクを更新していく
	CTask *p = mp_head;
	while (p)
	{
		p->Update();
		p = p->mp_next;
	}
}
void CTaskManager::AllRender()
{
	//先頭から順にタスクを描画していく
	CTask *p = mp_head;
	while (p)
	{
		p->Render();
		p = p->mp_next;
	}
}

CTaskManager* CTaskManager::GetInstance()
{
	//CTaskManagerを一度のみ（シングルトン）生成して格納
	if (mp_instance == nullptr)
	{
		mp_instance = new CTaskManager();
	}
	//それを返す
	return mp_instance;
}

void CTaskManager::ClearInstance()
{
	//メモリリーク回避
	if (mp_instance != nullptr) delete mp_instance;
}
