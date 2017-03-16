#ifndef GAMEMAIN_HPP
#define GAMEMAIN_HPP
#include "../Task/CTask.h"
#include "../Player/CPlayer.h"
#include "../Enemy/CEnemy00.h"
#include "../Task/CTaskManager.h"
#include "../Camera/CCamera.h"  
#include "../Map/CMap.h"
#include "../Collision/CCollision.h"

#define JUMP_FIRST_SPEED 0.2

class CGameMain{
public:

	enum EStatus{
		E_INIT,E_MAIN
	};
	EStatus status;

	CGameMain();
	void Init();
	void Update();
	
};


#endif