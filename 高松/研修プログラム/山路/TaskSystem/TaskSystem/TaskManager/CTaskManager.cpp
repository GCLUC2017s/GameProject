#include "../TaskManager/CTaskManager.h"

CTaskManager::CTaskManager() : mp_head(nullptr), mp_tail(nullptr)
{

}

void CTaskManager::ListUpdate()
{
	for (;;)
	{
		printf("リスト更新");
	}
}

void CTaskManager::ListRender()
{
	for (;;)
	{
		printf("リスト描画");
	}
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

void CTaskManager::Destroy()
{

}

void CTaskManager::ListDestroy()
{

}

void CTaskManager::Pause()
{

}