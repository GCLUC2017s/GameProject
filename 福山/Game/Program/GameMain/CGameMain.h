#ifndef GAMEMAIN_HPP
#define GAMEMAIN_HPP
#include "../Task/CTask.h"
#include "../Player/CPlayer.h"
#include "../Enemy/CEnemy.h"
#include "../Task/CTaskManager.h"
#include "../Camera/CCamera.h"  
#include "../Map/CMap.h"
#define JUMP_FIRST_SPEED 0.2

class CGameMain{
public:

	CTaskManager taskmanger;

	enum EStatus{
		E_INIT,E_MAIN
	};
	EStatus status;



	CGameMain();
	void Init();
	void Update();
};


#endif