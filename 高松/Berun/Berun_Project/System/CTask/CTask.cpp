#include "CTask.h"
#include "../CTaskManager/CTaskManager.h"

CTask::CTask() : m_kill(false),mp_prev(nullptr),mp_next(nullptr)
{
	printf("�����CTask�N���X�̃R���X�g���N�^�ł��B\n");
}
CTask::~CTask()
{
	printf("�����CTask�N���X�̃f�X�g���N�^�ł��B\n");
}
void CTask::Update()
{
	//�h����Œ�`
}
void CTask::Render()
{
	printf("�����CTask�N���X�̕`��֐��ł��B\n");
}
