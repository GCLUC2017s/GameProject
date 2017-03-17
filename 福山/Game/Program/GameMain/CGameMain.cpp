#include "CGameMain.h"

CGameMain::CGameMain(){}

void CGameMain::Init(){
	CTaskManager::GetInstance()->Add(new CMap);

	CTaskManager::GetInstance()->Add(new CCamera);

	CTaskManager::GetInstance()->Add(new CPlayer);
	
	CTaskManager::GetInstance()->Add(new CEnemy00);

	CTaskManager::GetInstance()->Add(new CUserinterface);
}

void CGameMain::Update(){

	switch (status)
	{
	case E_INIT:
		Init();
		CTaskManager::GetInstance()->AllInit();
		status = E_MAIN;
		break;
	case E_MAIN:
		CTaskManager::GetInstance()->AllUpdate();
		CTaskManager::GetInstance()->AllRender();
		break;

	}

	

}