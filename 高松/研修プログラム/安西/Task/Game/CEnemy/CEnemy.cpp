#include"CEnemy.h"

CEnemy::CEnemy()
{
	printf("�����CEnemy�N���X�̃R���X�g���N�^�ł��B\n");
}
CEnemy::CEnemy(int i)
{
	printf("�����CEnemy�N���X�̃R���X�g���N�^�ł��B\n");
}
CEnemy::~CEnemy()
{
	printf("�����CEnemy�N���X�̃f�X�g���N�^�ł��B\n");
}
void CEnemy::Update()
{
	m_kill = true;
}
void CEnemy::Render()
{
	printf("�����CEnemy�N���X�̕`��֐��ł��B\n");
}