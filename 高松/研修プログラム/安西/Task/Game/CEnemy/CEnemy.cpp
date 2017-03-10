#include"CEnemy.h"

CEnemy::CEnemy()
{
	printf("これはCEnemyクラスのコンストラクタです。\n");
}
CEnemy::CEnemy(int i)
{
	printf("これはCEnemyクラスのコンストラクタです。\n");
}
CEnemy::~CEnemy()
{
	printf("これはCEnemyクラスのデストラクタです。\n");
}
void CEnemy::Update()
{
	m_kill = true;
}
void CEnemy::Render()
{
	printf("これはCEnemyクラスの描画関数です。\n");
}