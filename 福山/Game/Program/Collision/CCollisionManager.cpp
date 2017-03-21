#include "../Collision/CCollisionmanager.h"
#include "../CGame/CGame.h"
#include "../Enemy/CEnemy00.h"
#include "../Enemy/CEnemy01.h"
#include"../Enemy/CBoss.h"
#include "../Player/CPlayer.h"
#include "../MyNumber/CMyNumber.h"
#define		PL_HITBUCK	player->mAttackPoint*10.0f
#define     ALPHA		 pl->mRect.triangle1.a
CCollisionManager::CCollisionManager(){};
CCollisionManager::~CCollisionManager(){};

void CCollisionManager::EnemyAttack(CBase *pl){
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
			if (ene->mEnabledAttack){
				if (CCollision::Collision(*ene, *pl, ene->mAttackAxis)){
					pl->mHitPoint -= ene->mAttackPoint;
				}
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
				/*ヒットバック*/
				if (player->mSaveForword.x >= 0){ b->mPos.x += PL_HITBUCK; }		//右向きの場合
				else{ b->mPos.x -= PL_HITBUCK; }									//左向きの場合
				/*捕食攻撃*/
				if (b->mHitPoint <= 0 && player->mEnabledEat){
					player->mStamina += CAL_ENEMY00;
					b->mEnabledEaten = true;

				}
			}
		}
		break;
	};

}

void CCollisionManager::Update(CBase *b)
{
		if (b->mMyNumber == E_PLAYER){
			EnemyAttack(b);
		}
		else{ 
			PlayerAttack(b);
		}
	
}