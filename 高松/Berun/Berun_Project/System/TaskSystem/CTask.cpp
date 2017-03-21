#include "CTask.h"
#include "CTaskManager.h"

//�f�t�H���g�R���X�g���N�^
CTask::CTask() :
	m_destroyFlg(false),
	m_pauseFlg(false),
	m_updatePrio(eUDP_Null),
	m_drawPrio(eDWP_Null),
	mp_prev(nullptr),
	mp_next(nullptr)
{
	//Manager�ɓo�^����Ȃ�
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
