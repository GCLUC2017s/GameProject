#include "CEnemy.h"

CEnemy::CEnemy()
{
	printf("CEnemyコンストラクタ呼び出し\n");
}

CEnemy::~CEnemy()
{
	printf("CEnemyデストラクタ呼び出し\n");
}

void CEnemy::Update()
{
	if (m_life <= 0)
	{
		Destroy();
		return;
	}
}
