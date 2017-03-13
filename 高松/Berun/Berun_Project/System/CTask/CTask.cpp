#include "CTask.h"
#include "../CTaskManager/CTaskManager.h"

//デフォルトコンストラクタ
CTask::CTask()
{
	//Managerに登録されない
}
CTask::CTask(int priority) : 
	m_destroyFlg(false), 
	m_pauseFlg(false), 
	m_udPriority(0), 
	m_rdPriority(0), 
	mp_prev(nullptr),
	mp_next(nullptr)
{
	m_udPriority = priority;
	m_rdPriority = priority;
	//タスク作成後、自動でManagerに登録
	CTaskManager::GetInstance()->Add(this);
}
CTask::~CTask()
{
	
}
void CTask::Update()
{
	//派生先で定義
}
void CTask::Draw()
{
	
}
