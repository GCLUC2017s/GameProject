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
#define _HP_ 0			//�z��@HP
#define _ST_ 1			
#define _HIGH_ 0
#define _NORM_ 1
#define _LOW_ 2
#define ST_POS			player->mStamina - PL_ST_X //�r�s�@pos �����p �����Z�Ŏg��
#define HP_POS			player->mHitPoint -PL_HP_X  //�r�s�@pos �����p �����Z�Ŏg��
void CUserinterface::Init(){
	/*�쐬*/
	mPlayerGageTex[_HP_] = new CTexture();
	mPlayerGageTex[_ST_] = new CTexture();
	mPlayerFrameHpTex = new CTexture();
	for (int i = 0; i < HUNG_HLN; i++)
	{
		mPlayerFrameStTex[i] = new CTexture();
	}
	mEnemyGageTex = new CTexture();
	mEnemyFrameTex = new CTexture();
	//
	/*�e�N�X�`���ǂݍ���*/
	/*�v���C���[*/
	/*�q�b�g�|�C���g*/
	mPlayerGageTex[_HP_]->load(TEX_FILE"UI_player_HP_gauge.tga");
	mPlayerFrameHpTex->load(TEX_FILE"UI_player_Frame.tga");
	/*�X�^�~�i*/
	mPlayerGageTex[_ST_]->load(TEX_FILE"UI_player_HP_gauge.tga");
	mPlayerFrameStTex[_HIGH_]->load(TEX_FILE"UI_player_Frame.tga");
	mPlayerFrameStTex[_NORM_]->load(TEX_FILE"UI_player_Frame.tga");
	mPlayerFrameStTex[_LOW_]->load(TEX_FILE"UI_player_Frame.tga");
	//
	/*�G�l�~�[*/
	mEnemyGageTex->load(TEX_FILE"UI_Enemy_HP_gauge.tga");
	mEnemyFrameTex->load(TEX_FILE"UI_Enemy_HP_Frame.tga");
	//
	/*�e�N�X�`���𒣂�*/
	/*PLAYER*/
	mGaugePlayer[_HP_].SetUv(mPlayerGageTex[_HP_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	mFramePlayer[_HP_].SetUv(mPlayerFrameHpTex, 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	mGaugePlayer[_ST_].SetUv(mPlayerGageTex[_ST_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	mFramePlayer[_ST_].SetUv(mPlayerFrameStTex[_HIGH_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	//
	/*�G�l�~�[*/
	mGaugeEne.SetUv(mPlayerGageTex[_HP_], 0, 0, SIZE_TEX_EN_FRAME_X, SIZE_TEX_EN_FRAME_Y);
	mFrameEne.SetUv(mEnemyFrameTex, 0, 0, SIZE_TEX_EN_FRAME_X, SIZE_TEX_EN_FRAME_Y);


}

const float arealeft_x = character_limit_left + (DISP_X / 2) - SIZE_PLAYER_X * 2;
const float arearifgt_x = character_limit_right - (DISP_X / 2) - SIZE_PLAYER_X * 3;

CUserinterface::CUserinterface()
{
	mPriorityR = E_UI;
	mPriorityU = E_UI;
	mMyNumber = E_UI;
	/*�l�p�쐬*/
	mFramePlayer[_HP_].SetVertex(-SIZE_PL_FRAME_X, SIZE_PL_FRAME_Y, SIZE_PL_FRAME_X, -SIZE_PL_FRAME_Y); //�l�p�쐬
	mFramePlayer[_ST_].SetVertex(-SIZE_PL_FRAME_X, SIZE_PL_FRAME_Y, SIZE_PL_FRAME_X, -SIZE_PL_FRAME_Y); //�l�p�쐬
	/*�J���[�����߂�*/
	mGaugePlayer[_HP_].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F�����߂�
	mFramePlayer[_HP_].SetColor(1.0f, 1.0f, 1.0f, 1.0f);//�F�����߂�

	mGaugePlayer[_ST_].SetColor(1.0f, 1.0f, 0.0f, 1.0f); //�F�����߂� 
	mFramePlayer[_ST_].SetColor(1.0f, 1.0f, 0.0f, 1.0f);//�F�����߂�

	/*�G�l�~�[*/

	mFrameEne.SetVertex(-SIZE_EN_FRAME_X, SIZE_EN_FRAME_Y, SIZE_EN_FRAME_X, -SIZE_EN_FRAME_Y); //�l�p�쐬

	mGaugeEne.SetColor(0.0f, 1.0f, 1.0f, 1.0f); //�F�����߂�
	mFrameEne.SetColor(1.0f, 1.0f, 1.0f, 1.0f);//�F�����߂�
	savex = first_pos.x;

	/*�ǉ������Ƃ��ɃL�����N�^�[������� && UI�����Ă��Ȃ��ꍇUI������*/
	CTask *t; //�T���p
	t = CTaskManager::GetInstance()->mRoot;
	while (t != 0)
	{
		if (t->mCharaFlag && !t->mUiFlag){
			t->mUiFlag = true;
			task = t;
			CTaskManager::GetInstance()->Add(new CUserinterface);
			break;
		}
		t = t->next;
	}
	if (t == 0){
		delete t;
	}

}

	

CUserinterface::~CUserinterface()
{
	CGame::Delete(&mPlayerGageTex[_HP_]);
	CGame::Delete(&mPlayerGageTex[_ST_]);
	CGame::Delete(&mPlayerFrameHpTex);
	for (int i = 0; i < HUNG_HLN; i++){
		CGame::Delete(&mPlayerFrameStTex[i]);
	}
	CGame::Delete(&mEnemyGageTex);
	CGame::Delete(&mEnemyFrameTex);

}



void CUserinterface::Update(){
	if (task != 0){
		mPriorityR = task->mPriorityR;
		switch (task->mMyNumber)
		{
			/*�v���[�C���[*/
		case E_PLAYER:
			CPlayer *player;
			player = (CPlayer*)task;
			//�\������G���A���w��

			//�\������G���A���w��
			if (arealeft_x <= CPlayer::camera_x&& arearifgt_x >= CPlayer::camera_x){

				savex = CPlayer::camera_x;

				mGaugePlayer[_HP_].position = CVector2(player->mPos.x - SIZE_PL_FRAME_X * 2 +HP_POS, DISP_Y - SIZE_PL_FRAME_Y * 2);
				mFramePlayer[_HP_].position = CVector2(player->mPos.x - SIZE_PL_FRAME_X * 2, DISP_Y - SIZE_PL_FRAME_Y * 2);
				mGaugePlayer[_ST_].position = CVector2(player->mPos.x - SIZE_PL_FRAME_X * 2 +ST_POS, DISP_Y - SIZE_PL_FRAME_Y * 4);
				mFramePlayer[_ST_].position = CVector2(player->mPos.x - SIZE_PL_FRAME_X * 2, DISP_Y - SIZE_PL_FRAME_Y * 4);
			}
			else{

				mGaugePlayer[_HP_].position = CVector2(savex - SIZE_PL_FRAME_X * 2 +HP_POS, DISP_Y - SIZE_PL_FRAME_Y * 2);
				mFramePlayer[_HP_].position = CVector2(savex - SIZE_PL_FRAME_X * 2, DISP_Y - SIZE_PL_FRAME_Y * 2);
				mGaugePlayer[_ST_].position = CVector2(savex - SIZE_PL_FRAME_X * 2 +ST_POS, DISP_Y - SIZE_PL_FRAME_Y * 4);
				mFramePlayer[_ST_].position = CVector2(savex - SIZE_PL_FRAME_X * 2, DISP_Y - SIZE_PL_FRAME_Y * 4);
			}

			mGaugePlayer[_HP_].SetVertex(-player->mHitPoint, SIZE_PL_FRAME_Y, player->mHitPoint, -SIZE_PL_FRAME_Y); //�l�p�쐬
			mGaugePlayer[_ST_].SetVertex(-player->mStamina, SIZE_PL_FRAME_Y, player->mStamina, -SIZE_PL_FRAME_Y); //�l�p�쐬
			if (player->HUNGRY_S_HIGH_IF)		{//���Ȃ������ς���UI
				mGaugePlayer[_ST_].SetUv(mPlayerGageTex[_ST_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
				mFramePlayer[_ST_].SetUv(mPlayerFrameStTex[_HIGH_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);

			}
			else if (player->HUNGRY_S_LOW_IF)	{//���Ȃ���������UI
				mGaugePlayer[_ST_].SetUv(mPlayerGageTex[_ST_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
				mFramePlayer[_ST_].SetUv(mPlayerFrameStTex[_HIGH_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);

			
			}
			else								{//���ʂ̏��
				mGaugePlayer[_ST_].SetUv(mPlayerGageTex[_ST_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
				mFramePlayer[_ST_].SetUv(mPlayerFrameStTex[_HIGH_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
			
			
			}
			
			break;
			/*�G�l�~�[*/
		case E_ENEMY00:

			CEnemy00 *ene00;
			ene00 = (CEnemy00*)task;
			mGaugeEne.position = CVector2(ene00->mPos.x, ene00->mPos.y + SIZE_ENEMY00_Y);
			mFrameEne.position = CVector2(ene00->mPos.x, ene00->mPos.y + SIZE_ENEMY00_Y);
			mGaugeEne.SetVertex(-ene00->mHitPoint, ENE_HP_Y, ene00->mHitPoint, -ENE_HP_Y); //�l�p
			if (ene00->mHitPoint <= 0){
				mKillFlag = true;
			}
			break;
		case E_ENEMY01:
			CEnemy01 *ene01;
			ene01 = (CEnemy01*)task;
			mGaugeEne.position = CVector2(ene01->mPos.x, ene01->mPos.y + SIZE_ENEMY01_Y);
			mFrameEne.position = CVector2(ene01->mPos.x, ene01->mPos.y + SIZE_ENEMY01_Y);
			mGaugeEne.SetVertex(-ene01->mHitPoint, SIZE_EN_FRAME_Y, ene01->mHitPoint, -SIZE_EN_FRAME_Y); //�l�p�쐬
			if (ene01->mHitPoint <= 0){
				mKillFlag = true;
			}
			break;
		case E_BOSS:
			CBoss *boss;
			boss = (CBoss*)task;
			mGaugeEne.position = CVector2(boss->mPos.x, boss->mPos.y + SIZE_BOSS_Y);
			mFrameEne.position = CVector2(boss->mPos.x, boss->mPos.y + SIZE_BOSS_Y);
			mGaugeEne.SetVertex(-boss->mHitPoint, SIZE_BOSS_FRAME_Y, boss->mHitPoint, -SIZE_BOSS_FRAME_Y); //�l�p�쐬
			if (boss->mHitPoint <= 0){
				mKillFlag = true;
			}
			break;
		}

	}
}

void CUserinterface::Render(){
	if (task != 0){
		if (task->mMyNumber == E_PLAYER){

			mFramePlayer[_HP_].Render();
			mGaugePlayer[_HP_].Render();
			mFramePlayer[_ST_].Render();
			mGaugePlayer[_ST_].Render();
		}
		else{
			mGaugeEne.Render();
			mFrameEne.Render();
		}
	}
}