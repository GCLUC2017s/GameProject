#include "../Collision/CCollisionmanager.h"
#include "../CGame/CGame.h"


CCollisionManager::CCollisionManager(){};
CCollisionManager::~CCollisionManager(){};

void CCollisionManager::EnemyAttack(CPlayer *pl){
	CTask *task;
	task = CTaskManager::GetInstance()->mRoot;
	/*始まり*/
	while (task != 0)
	{
		switch (task->mMyNumber)
		{
		case E_ENEMY00:
			CEnemy00 *ene00;
			ene00 = (CEnemy00*)CGame::getStatus(E_ENEMY00);
			if (CCollision::Collision(*(CBase*)ene00, *(CBase*)pl, ene00->mAttackAxis) && ene00->mEnabledAttack){
				/*アラート*/
				pl->mRect.SetColor(1.0f, 0.2f, 0.2f, 1.0f);
				pl->mHitPoint -= ene00->mAttackPoint;
			}
			else{
				pl->mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
			}
			break;
		case E_ENEMY01:
			CEnemy01 *ene01;
			ene01 = (CEnemy01*)CGame::getStatus(E_ENEMY01);
			if (CCollision::Collision(*(CBase*)ene01, *(CBase*)pl, ene01->mAttackAxis) && ene01->mEnabledAttack){
				/*アラート*/
				pl->mRect.SetColor(1.0f, 0.2f, 0.2f, 1.0f);
				pl->mHitPoint -= ene01->mAttackPoint;
			}
			else{
				pl->mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
			}
			break;
		case E_BOSS:
			CBoss *boss;
			boss = (CBoss*)CGame::getStatus(E_BOSS);
			if (CCollision::Collision(*(CBase*)boss, *(CBase*)pl, boss->mAttackAxis) && boss->mEnabledAttack){
				/*アラート*/
				pl->mRect.SetColor(1.0f, 0.2f, 0.2f, 1.0f);
				pl->mHitPoint -= boss->mAttackPoint;
			}
			else{
				pl->mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
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
			/*アラート*/
			b->mRect.SetColor(1.0f, 0.2f, 0.2f, 1.0f);
			/*捕食攻撃*/
			if (b->mHitPoint <= 0 && player->mEnabledEat){
				player->mStamina += CAL_ENEMY00; 
				b->mKillFlag = true;
			}
		}
		else{
			b->mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
		}
		break;
	case E_ENEMY01:
		if (CCollision::Collision(*(CBase*)player, *b, player->mAttackAxis) && player->mEnabledAttack){
			b->mHitPoint -= player->mAttackPoint;
			/*アラート*/
			b->mRect.SetColor(1.0f, 0.2f, 0.2f, 1.0f);
			/*捕食攻撃*/
			if (b->mHitPoint <= 0 && player->mEnabledEat){
				player->mStamina += CAL_ENEMY00;
				b->mKillFlag = true;
			}
		}
		else
		{
			b->mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
		}
		break;
	case E_BOSS:
		if (CCollision::Collision(*(CBase*)player, *b, player->mAttackAxis) && player->mEnabledAttack){
			b->mHitPoint -= player->mAttackPoint;
			/*アラート*/
			b->mRect.SetColor(1.0f, 0.2f, 0.2f, 1.0f);
			/*捕食攻撃*/
			if (b->mHitPoint <= 0 && player->mEnabledEat){
				player->mStamina += CAL_ENEMY00;
				b->mKillFlag = true;
			}
		}
		else
		{
			b->mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
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