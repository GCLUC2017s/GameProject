#include "CGameScene.h"
#include "../Task/CTask.h"
#include "../Player/CPlayer.h"
#include "../Enemy/CEnemy00.h"
#include "../Task/CTaskManager.h"
#include "../Camera/CCamera.h"  
#include "../Map/CMap.h"
#include "../UserInterface/CUserInterface.h"
#include "../Enemy/CEnemy01.h"
#include "../Enemy/CBoss.h"
#include "../Result/CResult.h"
#include "../CGame/CGame.h"
#include "../Enemy/CLowBoss.h"
#define ADD_TIME 20.0f//“GoŒ»ƒtƒ‰ƒO

CGameScene::CGameScene():status(E_INIT){}
enum eAddEnemyNonber
{
	E_ADD_ENE00,
	E_ADD_ENE01,
	E_ADD_BOSS
};

void CGameScene::Init(){
	CTaskManager::GetInstance()->Add(new CMap);

	CTaskManager::GetInstance()->Add(new CCamera);

	for (int i = 0; i < 5; i++)
	{

		CTaskManager::GetInstance()->Add(new CEnemy00);

		CTaskManager::GetInstance()->Add(new CEnemy01);
	}
	CTaskManager::GetInstance()->Add(new CPlayer);
	CTaskManager::GetInstance()->Add(new CLowBoss);
	
	CTaskManager::GetInstance()->Add(new CBoss);
	CTaskManager::GetInstance()->Add(new CClear);
	CTaskManager::GetInstance()->Add(new CUserinterface);
	
}

void CGameScene::Update(){

	switch (status)
	{
	case E_INIT:
		Init();
		CTaskManager::GetInstance()->AllInit();
		status = E_MAIN;
		break;
	case E_MAIN:

		if (CGame::FlagTime(ADD_TIME, FPS, &mSaveTime)){
			switch ((int)rand() % 10)
			{
			case E_ADD_ENE00:
				CTaskManager::GetInstance()->Add(new CEnemy00);
				break;
			case E_ADD_ENE01:

				CTaskManager::GetInstance()->Add(new CEnemy01);
				break;
			case E_ADD_BOSS:

				CTaskManager::GetInstance()->Add(new CBoss);
				break;
			}
		}
		CTaskManager::GetInstance()->AllUpdate();
		CTaskManager::GetInstance()->AllRender();
		break;

	}

	

}