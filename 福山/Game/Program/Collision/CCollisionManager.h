/*
@‚ ‚½‚è”»’è‚ÌŠÇ—ƒvƒƒOƒ‰ƒ€
  ’S“–Ò@ •y“cŒ’“l
*/
#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP
#include "../Collision/CCollision.h"
#include "../Task/CTaskManager.h"

class CCollisionManager : public CTask
{
public:
	CCollisionManager();
	~CCollisionManager();
	/*ˆø”‚Ì•”•ª‚ÉUŒ‚‚µ‚½‚¢‘ÎÛ‚ğ“ü‚ê‚é*/
	void EnemyAttack(CBase *b);
	void PlayerAttack(CBase *b);

	void Update(CBase *b);
	
private:

};

#endif