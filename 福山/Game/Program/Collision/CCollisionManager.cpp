#include "../Collision/CCollisionmanager.h"
#include "../CGame/CGame.h"


CCollisionManager::CCollisionManager(){};
CCollisionManager::~CCollisionManager(){};

void CCollisionManager::EnemyAttack(CPlayer *pl){
	CTask *task;
	task = CTaskManager::GetInstance()->mRoot;
	/*Žn‚Ü‚è*/
	while (task != 0)
	{
		switch (task->mMyNumber)
		{
		case E_ENEMY00:
			CEnemy00 *ene00;
			ene00 = (CEnemy00*)CGame::getStatus(E_ENEMY00);
			if (CCollision::Collision(*(CBase*)ene00, *(CBase*)pl, ene00->mAttackAxis) && ene00->mEnabledAttack){
				pl->mHitPoint -= ene00->mAttackPoint;
			}
			break;
		case E_ENEMY01:
			CEnemy01 *ene01;
			ene01 = (CEnemy01*)CGame::getStatus(E_ENEMY01);
			if (CCollision::Collision(*(CBase*)ene01, *(CBase*)pl, ene01->mAttackAxis) && ene01->mEnabledAttack){
				pl->mHitPoint -= ene01->mAttackPoint;
			}
			break;
		case E_BOSS:
			CBoss *boss;
			boss = (CBoss*)CGame::getStatus(E_BOSS);
			if (CCollision::Collision(*(CBase*)boss, *(CBase*)pl, boss->mAttackAxis) && boss->mEnabledAttack){
				pl->mHitPoint -= boss->mAttackPoint;
			}
			break;
		}
		task = task->next;

	}
}
void CCollisionManager::PlayerAttack(CBase *b){

	CPlayer *player;
	player = (CPlayer*)CGame::getStatus(E_PLAYER);

	switch (b->mMyNumber)
	{
	case E_ENEMY00:
		if (CCollision::Collision(*(CBase*)player, *b, player->mAttackAxis) && player->mEnabledAttack){
			b->mHitPoint -= player->mAttackPoint;
			/*•ßHUŒ‚*/
			if (b->mHitPoint <= 0 && player->mEnabledEat){
				player->mStamina += CAL_ENEMY00; 
				b->mKillFlag = true;
			}
		}
		break;
	case E_ENEMY01:
		if (CCollision::Collision(*(CBase*)player, *b, player->mAttackAxis) && player->mEnabledAttack){
			b->mHitPoint -= player->mAttackPoint;
			/*•ßHUŒ‚*/
			if (b->mHitPoint <= 0 && player->mEnabledEat){
				player->mStamina += CAL_ENEMY00;
				b->mKillFlag = true;
			}
		}
		break;
	case E_BOSS:
		if (CCollision::Collision(*(CBase*)player, *b, player->mAttackAxis) && player->mEnabledAttack){
			b->mHitPoint -= player->mAttackPoint;
			/*•ßHUŒ‚*/
			if (b->mHitPoint <= 0 && player->mEnabledEat){
				player->mStamina += CAL_ENEMY00;
				b->mKillFlag = true;
			}
		}
		break;
	}

}

void CCollisionManager::Update(CBase *b)
{
		if (b->mMyNumber == E_PLAYER){
			EnemyAttack((CPlayer*)b);
		}
		else{ 
			PlayerAttack(b);
		}
	
}