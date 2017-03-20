/*
　あたり判定の管理プログラム
  担当者　 冨田健斗
*/
#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP
#include "../Collision/CCollision.h"

class CCollisionManager
{
public:
	CCollisionManager();
	~CCollisionManager();
	/*引数の部分に攻撃したい対象を入れる*/
	void EnemyAttack(CBase *b);
	void PlayerAttack(CBase *b);

	void Update(CBase *b);
	
private:

};

#endif