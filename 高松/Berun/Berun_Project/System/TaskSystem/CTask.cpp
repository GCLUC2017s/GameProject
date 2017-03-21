#include "CTask.h"
#include "CTaskManager.h"

//デフォルトコンストラクタ
CTask::CTask() :
	m_destroyFlg(false),
	m_pauseFlg(false),
	m_updatePrio(eUDP_Null),
	m_drawPrio(eDWP_Null),
	mp_prev(nullptr),
	mp_next(nullptr)
{
	//Managerに登録されない
}
CTask::CTask(int id, unsigned int updatePrio, unsigned int drawPrio) :
	m_destroyFlg(false), 
	m_pauseFlg(false), 
	m_updatePrio(updatePrio),
	m_drawPrio(drawPrio),
	m_id(id),
	mp_prev(nullptr),
	mp_next(nullptr)
{
	m_updatePrio = updatePrio;
	m_drawPrio = drawPrio;
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
