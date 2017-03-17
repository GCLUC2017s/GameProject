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
#define _HP_ 0
#define _ST_ 1
CUserinterface::CUserinterface()
{
	mPriorityR = E_UI;
	mPriorityU = E_UI;
	mMyNumber = E_UI;

	mPlayerGageTex[_HP_] = new CTexture();
	mPlayerGageTex[_ST_] = new CTexture();
	mPlayerFrameTex[_HP_] = new CTexture();
	mPlayerFrameTex[_ST_] = new CTexture();

	mEnemyGageTex = new CTexture();
	mEnemyFrameTex = new CTexture();

	/*�v���C���[*/
	/*�e�N�X�`���ǂݍ���*/
	mPlayerGageTex[_HP_]->load(TEX_FILE"UI_player_HP_gauge.tga");
	mPlayerFrameTex[_HP_]->load(TEX_FILE"UI_player_Frame.tga");
	mPlayerGageTex[_ST_]->load(TEX_FILE"UI_player_HP_gauge.tga");
	mPlayerFrameTex[_ST_]->load(TEX_FILE"UI_player_Frame.tga");
	/*�l�p�쐬*/
	mFramePlayer[_HP_].SetVertex(-SIZE_PL_FRAME_X, SIZE_PL_FRAME_Y, SIZE_PL_FRAME_X, -SIZE_PL_FRAME_Y); //�l�p�쐬
	mFramePlayer[_ST_].SetVertex(-SIZE_PL_FRAME_X, SIZE_PL_FRAME_Y, SIZE_PL_FRAME_X, -SIZE_PL_FRAME_Y); //�l�p�쐬
	/*�J���[�����߂�*/
	mGaugePlayer[_HP_].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F�����߂�
	mFramePlayer[_HP_].SetColor(1.0f, 1.0f, 1.0f, 1.0f);//�F�����߂�

	mGaugePlayer[_ST_].SetColor(1.0f, 1.0f, 0.0f, 1.0f); //�F�����߂� 
	mFramePlayer[_ST_].SetColor(1.0f, 1.0f, 0.0f, 1.0f);//�F�����߂�
	/*�e�N�X�`���𒣂�*/
	mGaugePlayer[_HP_].SetUv(mPlayerGageTex[_HP_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	mFramePlayer[_HP_].SetUv(mPlayerFrameTex[_HP_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	mGaugePlayer[_ST_].SetUv(mPlayerGageTex[_ST_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	mFramePlayer[_ST_].SetUv(mPlayerFrameTex[_ST_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	/*�G�l�~�[*/
	mEnemyGageTex->load(TEX_FILE"UI_Enemy_HP_gauge.tga");
	mEnemyFrameTex->load(TEX_FILE"UI_Enemy_HP_Frame.tga");
	
	mGaugeEne.SetVertex(-SIZE_PL_FRAME_X, SIZE_PL_FRAME_Y, SIZE_PL_FRAME_X, -SIZE_PL_FRAME_Y); //�l�p�쐬

	mGaugeEne.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F�����߂�
	mFrameEne.SetColor(1.0f, 1.0f, 1.0f, 1.0f);//�F�����߂�

	mGaugeEne.SetUv(mEnemyGageTex, 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	mFrameEne.SetUv(mEnemyFrameTex, 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
}

CUserinterface::~CUserinterface()
{
}

void CUserinterface::Update(){

	CTask *task;
	task = CTaskManager::GetInstance()->mRoot;
	/*�n�܂�*/
	while (task != 0)
	{
		switch (task->mMyNumber)
		{
		case E_PLAYER:
			CPlayer *player;
			player = (CPlayer*)CGame::getStatus(E_PLAYER);
			//�\������G���A���w��
			if (-area_x <= -DISP_X + CPlayer::camera_x + SIZE_PLAYER_X &&
				area_x >= DISP_X + CPlayer::camera_x + SIZE_PLAYER_X){

				savex = CPlayer::camera_x + SIZE_PLAYER_X;

				mGaugePlayer[_HP_].position = CVector2(player->mPos.x - DISP_X / 2, DISP_Y - SIZE_PL_FRAME_Y * 2);
				mFramePlayer[_HP_].position = CVector2(player->mPos.x - DISP_X / 2, DISP_Y - SIZE_PL_FRAME_Y * 2);
				mGaugePlayer[_ST_].position = CVector2(player->mPos.x - DISP_X / 2, DISP_Y - SIZE_PL_FRAME_Y * 4);
				mFramePlayer[_ST_].position = CVector2(player->mPos.x - DISP_X / 2, DISP_Y - SIZE_PL_FRAME_Y * 4);
			}
			else{
				mGaugePlayer[_HP_].position = CVector2(savex - DISP_X + SIZE_PL_FRAME_X, DISP_Y - SIZE_PL_FRAME_Y * 2);
				mFramePlayer[_HP_].position = CVector2(savex - DISP_X + SIZE_PL_FRAME_X, DISP_Y - SIZE_PL_FRAME_Y * 2);
				mGaugePlayer[_ST_].position = CVector2(savex - DISP_X + SIZE_PL_FRAME_X, DISP_Y - SIZE_PL_FRAME_Y * 4);
				mFramePlayer[_ST_].position = CVector2(savex - DISP_X + SIZE_PL_FRAME_X, DISP_Y - SIZE_PL_FRAME_Y * 4);
			}

			mGaugePlayer[_HP_].SetVertex(-player->mHitPoint, SIZE_PL_FRAME_Y, player->mHitPoint, -SIZE_PL_FRAME_Y); //�l�p�쐬
			mGaugePlayer[_ST_].SetVertex(-player->mStamina, SIZE_PL_FRAME_Y, player->mStamina, -SIZE_PL_FRAME_Y); //�l�p�쐬
			

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


			mGaugeEne.SetVertex(-ene00->mHitPoint, SIZE_PL_FRAME_Y, ene00->mHitPoint, -SIZE_PL_FRAME_Y); //�l�p�쐬
			
		



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

			mGaugeEne.SetVertex(-ene01->mHitPoint, SIZE_PL_FRAME_Y, ene01->mHitPoint, -SIZE_PL_FRAME_Y); //�l�p�쐬

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

			mGaugeEne.SetVertex(-boss->mHitPoint, SIZE_PL_FRAME_Y, boss->mHitPoint, -SIZE_PL_FRAME_Y); //�l�p�쐬

			
			break;
		}
		task = task->next;

	}

}

void CUserinterface::Render(){
	mFramePlayer[_HP_].Render();
	mGaugePlayer[_HP_].Render();
	mFramePlayer[_ST_].Render();
	mGaugePlayer[_ST_].Render();

	mFrameEne.Render();
	mGaugeEne.Render();


}