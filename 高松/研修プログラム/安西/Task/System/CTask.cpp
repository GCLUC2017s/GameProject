#include "CTask.h"

CTask::CTask()
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



CTaskManager::CTaskManager()
{
	printf("�����CTaskManager�N���X�̃R���X�g���N�^�ł��B\n");
}
CTaskManager::~CTaskManager()
{
	printf("�����CTaskManager�N���X�̃f�X�g���N�^�ł��B\n");
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
	printf("�����CTaskManager�N���X�̕`�揈���ł��B\n");
}
