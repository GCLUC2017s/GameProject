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
	printf("エネミー更新");
}

void CEnemy::Render()
{
	printf("エネミー描画");
}
