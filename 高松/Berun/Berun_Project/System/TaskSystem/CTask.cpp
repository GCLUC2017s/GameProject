#include "CTask.h"
#include "CTaskManager.h"

//デフォルトコンストラクタ
CTask::CTask() :
	m_destroyFlg(false),
	m_pauseFlg(false),
	m_udPriority(0),
	m_dwPriority(0),
	mp_prev(nullptr),
	mp_next(nullptr)
{
	//Managerに登録されない
}
CTask::CTask(unsigned int udpriority, unsigned int dwpriority) :
	m_destroyFlg(false), 
	m_pauseFlg(false), 
	m_udPriority(udpriority),
	m_dwPriority(dwpriority),
	mp_prev(nullptr),
	mp_next(nullptr)
{
	m_udPriority = udpriority;
	m_dwPriority = dwpriority;
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
