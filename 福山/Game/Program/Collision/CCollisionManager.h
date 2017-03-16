#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP
#include "../Collision/CCollision.h"
#include "../Player/CPlayer.h"
#include "../Enemy/CEnemy00.h"
#include "../MyNumber/CMyNumber.h"

class CCollisionManager : public CBase
{
public:
	CCollisionManager();
	~CCollisionManager();

	void Update(CEnemy00 *ENE)
	{
	
		CTask *task;
		CPlayer *player;

		task = CTaskManager::GetInstance()->mRoot; 
		/*�n�܂�*/
		while (task != 0)
		{
			if (task->mMyNumber == E_PLAYER){
				player = (CPlayer*)task;

				if (CCollision::Collision(player->mRect, ENE->mRect)){

					player->mHitPoint = 0;

				}
				
			}
			task = task->next;
			
		}
		/*�I���*/

	}
	
private:

};

#endif