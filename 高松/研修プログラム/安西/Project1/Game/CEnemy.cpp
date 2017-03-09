#include"CEnemy.h"

CEnemy::CEnemy()
{
	printf("これはCEnemyクラスのコンストラクタです。\n");
}
CEnemy::~CEnemy()
{
	printf("これはCEnemyクラスのデストラクタです。\n");
}
void CEnemy::Update()
{

}
void CEnemy::Render()
{
	printf("これはCEnemyクラスの描画関数です。\n");
}