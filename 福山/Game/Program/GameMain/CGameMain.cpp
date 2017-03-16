#include "CGameMain.h"

CGameMain::CGameMain(){}

void CGameMain::Init(){
	taskmanger.Add(new CMap);

	taskmanger.Add(new CCamera);

	taskmanger.Add(new CPlayer);
	
	taskmanger.Add(new CEnemy00);

	taskmanger.Add(new CCollisionManager);

}

void CGameMain::Update(){

	switch (status)
	{
	case E_INIT:
		Init();
		taskmanger.AllInit();
		status = E_MAIN;
		break;
	case E_MAIN:
		taskmanger.AllUpdate();
		taskmanger.AllRender();
		break;

	}

	

}