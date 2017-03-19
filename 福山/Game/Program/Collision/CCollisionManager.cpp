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
		case E_ENEMY01:
		case E_BOSS:
			CBase *ene;
			ene = (CBase*)task;
			if (CCollision::Collision(*ene, *(CBase*)pl, ene->mAttackAxis) && ene->mEnabledAttack){
				/*アラート*/
				pl->mRect.SetColor(1.0f, 0.2f, 0.2f, 1.0f);
				pl->mHitPoint -= ene->mAttackPoint;
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
	case E_ENEMY01:
	case E_BOSS:
		if (player->mEnabledAttack){
			if (CCollision::Collision(*(CBase*)player, *b, player->mAttackAxis)){
				b->mHitPoint -= player->mAttackPoint;
				/*アラート*/
				b->mRect.SetColor(1.0f, 0.2f, 0.2f, 1.0f);
				/*捕食攻撃*/
				if (b->mHitPoint <= 0 && player->mEnabledEat){
					player->mStamina += CAL_ENEMY00;
				}
			}
		}
		else{
			b->mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
		}
		break;
	};

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