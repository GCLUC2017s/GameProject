#include "CTask.h"
#include "../CTaskManager/CTaskManager.h"

CTask::CTask() : m_destroyFlg(false),m_pauseFlg(false),m_udPriority(0),m_rdPriority(0),mp_prev(nullptr),mp_next(nullptr)
{
	//�^�X�N�쐬��A������Manager�ɓo�^
	CTaskManager::GetInstance()->Add(this);
}
CTask::~CTask()
{
	
}
void CTask::Update()
{
	//�h����Œ�`
}
void CTask::Draw()
{
	
}
