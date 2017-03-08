#include "../Task/CTask.h"
#include "../Enemy/CEnemy.h"
#include "../Player/CPlayer.h"


CTask::CTask() : mp_head(nullptr), mp_tail(nullptr), mp_prev(nullptr), mp_next(nullptr)
{
	printf("CTaskコンストラクタ呼び出し\n");
}

CTask::~CTask()
{
	printf("CTaskデストラクタ呼び出し\n");
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
	//要素が存在していれば
	if (p)
	{
		delete p;
	}
}
