#include "CUserInterface.h"
#include "../Player\CPlayer.h"
#include "../Enemy\CEnemy00.h"
#include "../Enemy\CEnemy01.h"
#include "../Enemy\CBoss.h"
#include "../Task\CTaskManager.h"
#include "../MyNumber\CMyNumber.h"
#include "../CGame/CGame.h"
#include "../Camera/CCamera.h"
#include "../Task/CTaskManager.h"
#include "../Camera/CCamera.h"

#define SIZE_TEX_PLAYER_FRAME_X 1000
#define SIZE_TEX_PLAYER_FRAME_Y 100
#define SIZE_TEX_BOSS_FRAME_X	  500
#define SIZE_TEX_BOSS_FRAME_Y   100
#define SIZE_TEX_EN_FRAME_X     500
#define SIZE_TEX_EN_FRAME_Y	  100

#define TEX_FILE "../CG/UI/"
CUserinterface::CUserinterface()
{
	mPriorityR = E_UI;
	mPriorityU = E_UI;
	mMyNumber = E_UI;

	mPlayerGageTex = new CTexture();
	mEnemyGageTex = new CTexture();
	mEnemyFrameTex = new CTexture();
	mPlyerFrameTex = new CTexture();


	mPlayerGageTex->load(TEX_FILE"UI_player_HP_gauge.tga");
	mPlyerFrameTex->load(TEX_FILE"UI_player_Frame.tga");
	mEnemyGageTex->load(TEX_FILE"UI_Enemy_HP_gauge.tga");
	mEnemyFrameTex->load(TEX_FILE"UI_Enemy_HP_Frame.tga");

	mFramePl.SetVertex(-SIZE_PL_FRAME_X, SIZE_PL_FRAME_Y, SIZE_PL_FRAME_X, -SIZE_PL_FRAME_Y); //四角作成
	mGaugeEne.SetVertex(-SIZE_PL_FRAME_X, SIZE_PL_FRAME_Y, SIZE_PL_FRAME_X, -SIZE_PL_FRAME_Y); //四角作成

	mGaugePl.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を決める
	mFramePl.SetColor(1.0f, 1.0f, 1.0f, 1.0f);//色を決める
	mGaugeEne.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を決める
	mFrameEne.SetColor(1.0f, 1.0f, 1.0f, 1.0f);//色を決める

	mGaugeEne.SetUv(mEnemyGageTex, 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	mFrameEne.SetUv(mEnemyFrameTex, 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	mGaugePl.SetUv(mPlayerGageTex, 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	mFramePl.SetUv(mPlyerFrameTex, 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
}

CUserinterface::~CUserinterface()
{
}

void CUserinterface::Update(){

	CTask *task;
	task = CTaskManager::GetInstance()->mRoot;
	/*始まり*/
	while (task != 0)
	{
		switch (task->mMyNumber)
		{
		case E_PLAYER:
			CPlayer *player;
			player = (CPlayer*)CGame::getStatus(E_PLAYER);
			//表示するエリアを指定
			if (-area_x <= -DISP_X + CPlayer::camera_x + SIZE_PLAYER_X &&
				area_x >= DISP_X + CPlayer::camera_x + SIZE_PLAYER_X){

				savex = CPlayer::camera_x + SIZE_PLAYER_X;

				mGaugePl.position = CVector2(player->mPos.x - DISP_X / 2, DISP_Y - SIZE_PL_FRAME_Y * 2);
				mFramePl.position = CVector2(player->mPos.x - DISP_X / 2, DISP_Y - SIZE_PL_FRAME_Y * 2);
			}
			else{
				mGaugePl.position = CVector2(savex - DISP_X + SIZE_PL_FRAME_X , DISP_Y - SIZE_PL_FRAME_Y * 2);
				mFramePl.position = CVector2(savex - DISP_X + SIZE_PL_FRAME_X, DISP_Y - SIZE_PL_FRAME_Y * 2);
			}

			mGaugePl.SetVertex(-player->mHitPoint, SIZE_PL_FRAME_Y, player->mHitPoint, -SIZE_PL_FRAME_Y); //四角作成
			

			break;
		case E_ENEMY00:
			CEnemy00 *ene00;
			ene00 = (CEnemy00*)CGame::getStatus(E_ENEMY00);

			if (!ene00->mEnabledUi){ 
				CTaskManager::GetInstance()->Add(this); 
				ene00->mEnabledUi = true;
			}
			mGaugeEne.position = ene00->mPos;
			mFrameEne.position = ene00->mPos;


			mGaugeEne.SetVertex(-ene00->mHitPoint, SIZE_PL_FRAME_Y, ene00->mHitPoint, -SIZE_PL_FRAME_Y); //四角作成
			
		



			break;
		case E_ENEMY01:
			CEnemy01 *ene01;
			ene01 = (CEnemy01*)CGame::getStatus(E_ENEMY01);
			if (!ene01->mEnabledUi){
			CTaskManager::GetInstance()->Add(this);
			ene01->mEnabledUi = true;
			}
			mGaugeEne.position = ene01->mPos;
			mFrameEne.position = ene01->mPos;

			mGaugeEne.SetVertex(-ene01->mHitPoint, SIZE_PL_FRAME_Y, ene01->mHitPoint, -SIZE_PL_FRAME_Y); //四角作成

			break;
		case E_BOSS:
			CTaskManager::GetInstance()->Add(this);
			CBoss *boss;
			boss = (CBoss*)CGame::getStatus(E_BOSS);
			if (!boss->mEnabledUi){
			CTaskManager::GetInstance()->Add(this);
			boss->mEnabledUi = true;
			}
			mGaugeEne.position = boss->mPos;
			mFrameEne.position = boss->mPos;

			mGaugeEne.SetVertex(-boss->mHitPoint, SIZE_PL_FRAME_Y, boss->mHitPoint, -SIZE_PL_FRAME_Y); //四角作成

			
			break;
		}
		task = task->next;

	}

}

void CUserinterface::Render(){
	mFramePl.Render();
	mGaugePl.Render();

	mFrameEne.Render();
	mGaugeEne.Render();


}