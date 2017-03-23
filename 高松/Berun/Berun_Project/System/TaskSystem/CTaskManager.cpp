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
	//先頭が存在しなければ
	if (!mp_head)
	{
		//追加されたタスクを先頭に
		mp_head = p;
		//mp_head->mp_prev = nullptr;
		//mp_head->mp_next = p;
		//mp_tail = p;
	}
	//先頭が存在していれば
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
	//削除するタスクの「前タスクの次の位置」を削除するタスクの「次タスクの位置」に繋ぐ。
	if(prev)prev->mp_next = next;
	//削除するタスクの「次タスクの前の位置」を削除するタスクの「前タスクの位置」に繋ぐ。
	if(next)next->mp_prev = prev;
	//その後、指定した特定のタスクを削除し、次のタスクを返す。
	delete p;
	return next;
}
void CTaskManager::DestroyAppoint()
{
	//先頭から順に削除フラグが真のタスクを削除していく
	CTask *p = mp_head;
	while (p)
	{
		if (p->m_destroyFlg) p = Destroy(p);
		else p = p->mp_next;
	}
}

void CTaskManager::DestroyAll()
{
	//先頭からタスクを削除していく
	CTask *p = mp_head;
	while (p)
	{
		p = Destroy(p);
	}
}
void CTaskManager::UpdateAll()
{
	//先頭から順にタスクを更新していく
	CTask *p = mp_head;
	while (p)
	{
		p->Update();
		p = p->mp_next;
	}
}
void CTaskManager::DrawAll()
{
	//先頭から順にタスクを描画していく
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

	//それぞれの次のタスクを先頭に設定
	p->mp_next = mp_head;
	n->mp_next = mp_head;

	//pの次のタスクが末尾で無ければ
	while (p->mp_next != mp_tail)
	{
		//pの次のタスクをpに代入
		p = p->mp_next;
		//変更した後のpの次のタスクをnに代入
		n = p->mp_next;

		//更新順序の比較
		if (p->m_updatePrio > n->m_updatePrio)
		{
			//避難用変数
			CTask tp;
			CTask tn;
			//入れ替え
			SwapTask(&p, &n);
			//タスク避難
			tp.mp_prev = p->mp_prev;
			tp.mp_next = p->mp_next;
			tn.mp_prev = n->mp_prev;
			tn.mp_next = n->mp_next;
			//順序入れ替え
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

	//それぞれの次のタスクを先頭に設定
	p->mp_next = mp_head;
	n->mp_next = mp_head;

	//pの次のタスクが末尾で無ければ
	while (p->mp_next != mp_tail)
	{
		//pの次のタスクをpに代入
		p = p->mp_next;
		//変更した後のpの次のタスクをnに代入
		n = p->mp_next;

		//更新順序の比較
		if (p->m_drawPrio > n->m_drawPrio)
		{
			//避難用変数
			CTask tp;
			CTask tn;
			//入れ替え
			SwapTask(&p, &n);
			//タスク避難
			tp.mp_prev = p->mp_prev;
			tp.mp_next = p->mp_next;
			tn.mp_prev = n->mp_prev;
			tn.mp_next = n->mp_next;
			//順序入れ替え
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
	//引数があれば
	while (p&&id)
	{
		//idが一致していればそのタスクを返す
		if (p->m_id == id) return p;
		p = p->mp_next;
	}
	
	//以外ならnullを返す
	return nullptr;
}

int CTaskManager::GetCount(int id)
{
	int cnt = 0;
	CTask *p;
	//引数があれば
	while (id)
	{
		//idが一致していればカウントアップ
		if(p->m_id == id) cnt++;
	}
	//個数を返す
	return cnt;
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
