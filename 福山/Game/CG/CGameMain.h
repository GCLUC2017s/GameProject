#ifndef GAMEMAIN_HPP
#define GAMEMAIN_HPP
#include "CTask.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CTaskManager.h"
#include "CCamera.h"  
#include "CMap.h"
#define JUMP_FIRST_SPEED 0.2

class CGameMain{
public:
	CTaskManager taskmanger;
	CTask *task = taskmanger.mRoot;

	enum EStatus{
		E_INIT,E_MAIN
	};
	EStatus status;

	CGameMain();

	void Init();
	void Update();
};


#endif