#include "CTask.h"
#include "../CTaskManager/CTaskManager.h"

CTask::CTask() : m_destroyFlg(false),m_pauseFlg(false),m_udPriority(0),m_rdPriority(0),mp_prev(nullptr),mp_next(nullptr)
{
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
