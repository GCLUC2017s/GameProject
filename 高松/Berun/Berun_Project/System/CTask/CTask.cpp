#include "CTask.h"
#include "../CTaskManager/CTaskManager.h"

//�f�t�H���g�R���X�g���N�^
CTask::CTask()
{
	//Manager�ɓo�^����Ȃ�
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
