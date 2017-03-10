#include "../Task/CTask.h"

CTask::CTask() : mp_prev(nullptr), mp_next(nullptr), m_udPriority(0), m_rdPriority(0)
{
	printf("CTaskコンストラクタ呼び出し\n");
}

CTask::~CTask()
{
	printf("CTaskデストラクタ呼び出し\n");
}

void CTask::Update()
{
	//継承先で定義
}
