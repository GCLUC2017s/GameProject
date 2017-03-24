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

#define SIZE_TEX_PLAYER_HP_X 700
#define SIZE_TEX_PLAYER_HP_Y 50
#define SIZE_TEX_PLAYER_ST_X 600
#define SIZE_TEX_PLAYER_ST_Y 100
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
#define ST_POSX			player->mStamina - PL_ST_X //�r�s�@pos �����p ����
#define HP_POSX			player->mHitPoint/10 -PL_HP_X  //HP�@pos �����p ����
#define ENE_HP_POSX		base->mHitPoint +ENE_HP_X  //HP�@pos �����p����

#define T_ST_RIGHT		SIZE_TEX_PLAYER_ST_X  *( player->mStamina / PL_ST_X*0.6)
#define SPEED_COLAR		0.05f

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
	mPlayerGageTex[_HP_]->load(TEX_FILE"UI_player_HP_gauge .tga");
	mPlayerFrameHpTex->load(TEX_FILE"UI_player_HP_Frame.tga");
	/*�X�^�~�i*/
	mPlayerGageTex[_ST_]->load(TEX_FILE"UI_sutamina3.tga");
	mPlayerFrameStTex[_HIGH_]->load(TEX_FILE"UI_sutamina2.tga");
	mPlayerFrameStTex[_NORM_]->load(TEX_FILE"UI_sutamina1.tga");
	mPlayerFrameStTex[_LOW_]->load(TEX_FILE"UI_sutamina1.tga");
	//
	/*�G�l�~�[*/
	mEnemyGageTex->load(TEX_FILE"UI_Enemy_HP_gauge.tga");
	mEnemyFrameTex->load(TEX_FILE"UI_Enemy_HP_Frame.tga");
	//
	/*�e�N�X�`���𒣂�*/
	/*PLAYER*/
	mGaugePlayer[_HP_].SetUv(mPlayerGageTex[_HP_], 0, 0, SIZE_TEX_PLAYER_HP_X, SIZE_TEX_PLAYER_HP_Y);
	mFramePlayer[_HP_].SetUv(mPlayerFrameHpTex, 0, 0, SIZE_TEX_PLAYER_HP_X, SIZE_TEX_PLAYER_HP_Y);
	mGaugePlayer[_ST_].SetUv(mPlayerGageTex[_ST_], 0, 0, SIZE_TEX_PLAYER_ST_X, SIZE_TEX_PLAYER_ST_Y);
	mFramePlayer[_ST_].SetUv(mPlayerFrameStTex[_HIGH_], 0, 0, SIZE_TEX_PLAYER_ST_X, SIZE_TEX_PLAYER_ST_Y);
	//
	/*�G�l�~�[*/
	mGaugeEne.SetUv(mEnemyGageTex, 0, 0, SIZE_TEX_EN_FRAME_X, SIZE_TEX_EN_FRAME_Y);
	mFrameEne.SetUv(mEnemyFrameTex, 0, 0, SIZE_TEX_EN_FRAME_X, SIZE_TEX_EN_FRAME_Y);


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
}

const float arealeft_x = character_limit_left + (DISP_X / 2) - SIZE_PLAYER_X * 2;
const float arearifgt_x = character_limit_right - (DISP_X / 2) - SIZE_PLAYER_X * 3;

CUserinterface::CUserinterface() : mFlagColar(false), mHungryC(1.0f), mFlagHP(true), mFlagST(true), task(0)
{
	Init();
	mPriorityR = E_UI;
	mPriorityU = E_UI;
	mMyNumber = E_UI;
	/*�l�p�쐬*/
	mFramePlayer[_HP_].SetVertex(-SIZE_PL_FRAME_X, SIZE_PL_FRAME_Y, SIZE_PL_FRAME_X, -SIZE_PL_FRAME_Y); //�l�p�쐬
	mFramePlayer[_ST_].SetVertex(-PL_ST_X, PL_ST_Y, PL_ST_X, -PL_ST_Y); //�l�p�쐬
	/*�J���[�����߂�*/
	mGaugePlayer[_HP_].SetColor(0.4f, 1.0f, 0.4f, 1.0f); //�F�����߂�
	mFramePlayer[_HP_].SetColor(1.0f, 1.0f, 1.0f, 1.0f);//�F�����߂�

	mGaugePlayer[_ST_].SetColor(1.0f, 1.0f, 0.0f, 1.0f); //�F�����߂� 
	mFramePlayer[_ST_].SetColor(1.0f, 1.0f, 0.0f, 1.0f);//�F�����߂�

	/*�G�l�~�[*/

	mFrameEne.SetVertex(-SIZE_EN_FRAME_X, SIZE_EN_FRAME_Y, SIZE_EN_FRAME_X, -SIZE_EN_FRAME_Y); //�l�p�쐬

	mGaugeEne.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F�����߂�
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
void CUserinterface::SetHungC(const CPlayer *player){
	/*�J���[�ݒ�*/
	if (mFlagColar){
		mHungryC -= SPEED_COLAR;
		if (mHungryC <= 0.0f){
			mFlagColar = false;
		}
	}
	else{
		mHungryC += SPEED_COLAR;
		if (mHungryC >= 1.0f){ 
			mFlagColar = true;

		}
	}

	/*gauge�؂�ւ�*/
	if (player->mStamina >= HUNGRY_EX01)		{//�K�E�Z���g����Ƃ���STGage
		mGaugePlayer[_ST_].SetColor(1.0f, 1.0f, 1.0f, 1.0f);
		mGaugePlayer[_ST_].SetUv(mPlayerGageTex[_ST_], 0, 0, T_ST_RIGHT, SIZE_TEX_PLAYER_ST_Y);
		mFramePlayer[_ST_].SetUv(mPlayerFrameStTex[_HIGH_], 0, 0, SIZE_TEX_PLAYER_ST_X, SIZE_TEX_PLAYER_ST_Y);

	}
	else if (player->HUNGRY_S_LOW_IF)	{//���Ȃ���������STGage
		mFramePlayer[_ST_].SetColor(mHungryC, mHungryC, mHungryC, mHungryC + 0.5f);
		mGaugePlayer[_ST_].SetUv(mPlayerGageTex[_ST_], 0, 0, T_ST_RIGHT, SIZE_TEX_PLAYER_ST_Y);
		mFramePlayer[_ST_].SetUv(mPlayerFrameStTex[_LOW_], 0, 0, SIZE_TEX_PLAYER_ST_X, SIZE_TEX_PLAYER_ST_Y);
	}
	else								{//�K�E�Z���g���Ȃ��Ƃ�
		mGaugePlayer[_ST_].SetColor(0.4f, 0.4f, 0.4f, 1.0f);
		mGaugePlayer[_ST_].SetUv(mPlayerGageTex[_ST_], 0, 0, T_ST_RIGHT, SIZE_TEX_PLAYER_ST_Y);
		mFramePlayer[_ST_].SetUv(mPlayerFrameStTex[_NORM_], 0, 0, SIZE_TEX_PLAYER_ST_X, SIZE_TEX_PLAYER_ST_Y);
	}
	if (player->mStamina <= 0){ //���Ȃ���������HP��������
		mFlagST = false;		//���łɃ����_�[�\�������Ă���
		mFramePlayer[_HP_].SetColor(mHungryC, mHungryC, mHungryC, 1.0f);
	}
	else{
		mFlagST = true;			//���Ȃ����������̂Ńt���O�𗧂Ă�
	}
	if (player->mHitPoint <= 0){
		mFlagHP = false;
	}
	else{
		mFlagHP = true;
	}
}


void CUserinterface::Update(){
	/*�ǉ������Ƃ��ɃL�����N�^�[������� && UI�����Ă��Ȃ��ꍇUI������*/
	CTask *t; //�T���p
	t = CTaskManager::GetInstance()->mRoot;
	while (t != 0)
	{
		if (t->mCharaFlag && !t->mUiFlag){
			t->mUiFlag = true;
			CUserinterface *SaveUI = new CUserinterface;
			CTaskManager::GetInstance()->Add(SaveUI);
			SaveUI->task = t;
			break;
		}
		t = t->next;
	}

	if (task != 0){
		mPriorityR = task->mPriorityR;
		switch (task->mMyNumber)
		{
			/*�v���[�C���[*/
		case E_PLAYER:
			CPlayer *player;
			player = (CPlayer*)task;
			mGaugePlayer[_HP_].position = CVector2(CGame::CameraPos().x - DISP_X + HP_POSX + SIZE_PL_FRAME_X, DISP_Y - SIZE_PL_FRAME_Y*0.5);
			mGaugePlayer[_ST_].position = CVector2(CGame::CameraPos().x - DISP_X + ST_POSX + PL_ST_X, DISP_Y - PL_ST_Y * 2);
			mFramePlayer[_HP_].position = CVector2(CGame::CameraPos().x - DISP_X + PL_HP_X, DISP_Y - SIZE_PL_FRAME_Y*0.5 );
			mFramePlayer[_ST_].position = CVector2(CGame::CameraPos().x - DISP_X + PL_ST_X, DISP_Y - PL_ST_Y *2);
			mGaugePlayer[_HP_].SetVertex(-player->mHitPoint*0.1f, SIZE_PL_FRAME_Y, player->mHitPoint*0.1f, -SIZE_PL_FRAME_Y); //�l�p�쐬
			mGaugePlayer[_ST_].SetVertex(-player->mStamina, PL_ST_Y, player->mStamina, -PL_ST_Y); //�l�p�쐬
			SetHungC(player);
			
			break;
			/*�G�l�~�[*/
		case E_ENEMY00:
		case E_BOSS:
		case E_ENEMY01:
		case E_LOWBOSS:

			CBase *base;
			base = (CBase*)task;
			mGaugeEne.position = CVector2(base->mPos.x - ENE_HP_POSX, base->mPos.y + base->mRect.triangle1.y1);
			mFrameEne.position = CVector2(base->mPos.x, base->mPos.y + base->mRect.triangle1.y1);
			mGaugeEne.SetVertex(-base->mHitPoint, ENE_HP_Y, base->mHitPoint, -ENE_HP_Y); //�l�p
			if (base->mHitPoint <= 0){
				mKillFlag = true;
			}
			break;
		}

	}
}

void CUserinterface::Render(){
	if (task != 0){
		if (task->mMyNumber == E_PLAYER){

			mFramePlayer[_ST_].Render();
			mFramePlayer[_HP_].Render();
			if (mFlagHP){
				mGaugePlayer[_HP_].Render();
			}
			if (mFlagST){
				mGaugePlayer[_ST_].Render();
			}
		}
		else{
			mFrameEne.Render();
			mGaugeEne.Render();
		}
	}
}