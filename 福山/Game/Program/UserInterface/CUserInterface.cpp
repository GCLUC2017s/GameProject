#include "CUserInterface.h"
#include "Player\CPlayer.h"
#include "Enemy\CEnemy00.h"
#include "Enemy\CEnemy01.h"
#include "Enemy\CBoss.h"
#include "Task\CTaskManager.h"
#include "MyNumber\CMyNumber.h"
#define SIZE_PL_BAR_X 2.0f			//PLAYER�̃o�[
#define SIZE_PL_BAR_Y0 0.2f			//PLAYER�̃o�[

#define SIZE_EN_BAR_X 1.0f			//�G�l�~�[�̃o�[
#define SIZE_EN_BAR_Y 0.5f			//�G�l�~�[�̃o�[

#define SIZE_BOSS_BAR_X	2.0f			//�{�X�̃o�[
#define SIZE_BOSS_BAR_Y	0.2f			//�{�X�̃o�[

#define SIZE_TEX_PLAYER_BAR_X 1000
#define SIZE_TEX_PLAYER_BAR_Y 100
#define SIZE_TEX_BOSS_BAR_X	  500
#define SIZE_TEX_BOSS_BAR_Y   100
#define SIZE_TEX_EN_BAR_X     500
#define SIZE_TEX_EN_BAR_Y	  100


CUserinterface::CUserinterface()
{
}

CUserinterface::~CUserinterface()
{
}

void CUserinterface::Update(){
	CTask *t;
	t = CTaskManager::GetInstance()->mRoot;
	switch (t->mMyNumber)
	{
	case E_PLAYER:

		break;
	case E_ENEMY00:
		break;
	case E_ENEMY01:
		break;
	case E_BOSS:
		break;
	}

}

void CUserinterface::Render(){

}