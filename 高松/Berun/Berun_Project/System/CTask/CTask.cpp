#include "CTask.h"

CTask::CTask() : m_kill(false),m_prev(nullptr),m_next(nullptr)
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
