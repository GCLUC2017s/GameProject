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
	if (!m_head)
	{
		//�擪�̈ʒu���up�v�A�܂��قǍ쐬�����I�u�W�F�N�g�̃A�h���X�ɐݒ肷��B
		m_head = p;
	}
	else
	{
		//���Ŋi�[�����A�h���X(�܂�A��O�ɌĂ΂ꂽ���̈ʒu�����ϐ�)�́unext�v�Ɏ��̃A�h���X(���̏������ɓ��������͊֐����Ăяo���ꂽ2��ڈȍ~�Ȃ̂ŁA���̈ʒu���i�[����)
		m_tail->m_next = p;
	}
	//�����o�[�ϐ��utail�v�ɁA���݂�List�̃A�h���X���i�[���Ă����B
	m_tail = p;
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
