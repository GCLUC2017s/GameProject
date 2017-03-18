#include "CGameMain.h"
#include "../Task/CTask.h"
#include "../Player/CPlayer.h"
#include "../Enemy/CEnemy00.h"
#include "../Task/CTaskManager.h"
#include "../Camera/CCamera.h"  
#include "../Map/CMap.h"
#include "../UserInterface/CUserInterface.h"
#include "../Enemy/CEnemy01.h"
#include "../Enemy/CBoss.h"

CGameMain::CGameMain():status(E_INIT){}

void CGameMain::Init(){
	CTaskManager::GetInstance()->Add(new CMap);

	CTaskManager::GetInstance()->Add(new CCamera);

	CTaskManager::GetInstance()->Add(new CPlayer);
	
	CTaskManager::GetInstance()->Add(new CEnemy00);
	CTaskManager::GetInstance()->Add(new CEnemy00);
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