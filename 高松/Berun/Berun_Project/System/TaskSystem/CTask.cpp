#include "CTask.h"
#include "CTaskManager.h"

//�f�t�H���g�R���X�g���N�^
CTask::CTask() :
	m_destroyFlg(false),
	m_pauseFlg(false),
	m_udPriority(0),
	m_dwPriority(0),
	mp_prev(nullptr),
	mp_next(nullptr)
{
	//Manager�ɓo�^����Ȃ�
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
