#include "CTask.h"

CTask::CTask()
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



CTaskManager::CTaskManager()
{
	printf("これはCTaskManagerクラスのコンストラクタです。\n");
}
CTaskManager::~CTaskManager()
{
	printf("これはCTaskManagerクラスのデストラクタです。\n");
}
void CTaskManager::Add(CTask *p)
{
	
}
void CTaskManager::Kill()
{

}
void CTaskManager::AllUpdate()
{
	
}
void CTaskManager::AllRender()
{
	printf("これはCTaskManagerクラスの描画処理です。\n");
}
