/*
　あたり判定の管理プログラム
  担当者　 冨田健斗
*/
#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP
#include "../Collision/CCollision.h"
#include "../Player/CPlayer.h"
#include "../Enemy/CEnemy00.h"
#include "../Enemy/CEnemy01.h"
#include"../Enemy/CBoss.h"
#include "../MyNumber/CMyNumber.h"

class CCollisionManager : public CBase
{
public:
	CCollisionManager();
	~CCollisionManager();
	/*引数の部分に攻撃したい対象を入れる*/
	void EnemyAttack(CPlayer *b);
	void PlayerAttack(CBase *b);

	void Update(CBase *b);
	
private:

};

#endif