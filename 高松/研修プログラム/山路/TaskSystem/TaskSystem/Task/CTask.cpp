#include "../Task/CTask.h"

CTask::CTask() : mp_prev(nullptr), mp_next(nullptr), m_udPriority(0), m_rdPriority(0)
{
	printf("CTask�R���X�g���N�^�Ăяo��\n");
}

CTask::~CTask()
{
	printf("CTask�f�X�g���N�^�Ăяo��\n");
}

void CTask::Update()
{
	//�p����Œ�`
}
