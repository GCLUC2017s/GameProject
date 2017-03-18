/*
@‚ ‚½‚è”»’è‚ÌŠÇ—ƒvƒƒOƒ‰ƒ€
  ’S“–Ò@ •y“cŒ’“l
*/
#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP
#include "../Collision/CCollision.h"
#include "../Player/CPlayer.h"
#include "../Enemy/CEnemy00.h"
#include "../Enemy/CEnemy01.h"
#include"../Enemy/CBoss.h"
#include "../MyNumber/CMyNumber.h"

class CCollisionManager
{
public:
	CCollisionManager();
	~CCollisionManager();
	/*ˆø”‚Ì•”•ª‚ÉUŒ‚‚µ‚½‚¢‘ÎÛ‚ğ“ü‚ê‚é*/
	void EnemyAttack(CPlayer *b);
	void PlayerAttack(CBase *b);

	void Update(CBase *b);
	
private:

};

#endif