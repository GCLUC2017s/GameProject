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
	//先頭が存在しなければ
	if (!mp_head)
	{
		//追加されたタスクを先頭に
		mp_head = p;
	}
	//先頭が存在していれば
	else
	{
		p->mp_prev = mp_tail;
		mp_tail->mp_next = p;
	}
	mp_tail = p;
}
CCollisionA *CCollisionManager::UnRegist(CCollisionA *p)
{
	CCollisionA *next = p->mp_next;
	CCollisionA *prev = p->mp_prev;
	//削除するタスクの「前タスクの次の位置」を削除するタスクの「次タスクの位置」に繋ぐ。
	if (prev)prev->mp_next = next;
	//削除するタスクの「次タスクの前の位置」を削除するタスクの「前タスクの位置」に繋ぐ。
	if (next)next->mp_prev = prev;
	p->mp_next = nullptr;
	p->mp_prev = nullptr;
	return next;
}
void CCollisionManager::UnRegistAll()
{
	//先頭から消していく
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

	//先頭から順にタスクを描画していく
	CCollisionA *p = mp_head;
	while (p)
	{
		CCollisionA *q = p->mp_next;
		while (q)
		{
			//pとqのタイプが違う時のみ当たり判定を行う処理
			if(p->m_type != q->m_type)	p->CheckHit(q);
			q = q->mp_next;
		}
		p = p->mp_next;
	}
}

CCollisionManager* CCollisionManager::GetInstance()
{
	//CCollisionManagerを一度のみ（シングルトン）生成して格納
	if (mp_instance == nullptr)
	{
		mp_instance = new CCollisionManager();
	}
	//それを返す
	return mp_instance;
}

void CCollisionManager::ClearInstance()
{
	//メモリリーク回避
	if (mp_instance != nullptr) delete mp_instance;
}