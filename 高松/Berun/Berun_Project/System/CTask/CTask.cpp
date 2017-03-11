#include "CTask.h"
#include "../CTaskManager/CTaskManager.h"

CTask::CTask() : m_kill(false),mp_prev(nullptr),mp_next(nullptr)
{
	printf("これはCTaskクラスのコンストラクタです。\n");
}
CTask::~CTask()
{
	printf("これはCTaskクラスのデストラクタです。\n");
}
void CTask::Update()
{
	//派生先で定義
}
void CTask::Render()
{
	printf("これはCTaskクラスの描画関数です。\n");
}
