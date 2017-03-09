#include "CTask.h"

CTask::CTask()
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
		//先頭の位置を「p」、つまり先ほど作成したオブジェクトのアドレスに設定する。
		m_head = p;
	}
	else
	{
		//下で格納したアドレス(つまり、一つ前に呼ばれた時の位置を持つ変数)の「next」に次のアドレス(この条件文に入った時は関数が呼び出された2回目以降なので、その位置を格納する)
		m_tail->m_next = p;
	}
	//メンバー変数「tail」に、現在のListのアドレスを格納しておく。
	m_tail = p;
}
void CTaskManager::Kill()
{

}
void CTaskManager::AllUpdate()
{
	
}
void CTaskManager::AllRender()
{
	printf("これはCTaskManagerクラスの描画処理です。\n");
}
