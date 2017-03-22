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
#define _HP_ 0			//配列　HP
#define _ST_ 1			
#define _HIGH_ 0
#define _NORM_ 1
#define _LOW_ 2
#define ST_POSX			player->mStamina - PL_ST_X //ＳＴ　pos 調整用 足す
#define HP_POSX			player->mHitPoint -PL_HP_X+0.1f  //HP　pos 調整用 足す
#define ENE_HP_POSX		base->mHitPoint +ENE_HP_X  //HP　pos 調整用引く

#define T_ST_RIGHT		SIZE_TEX_PLAYER_FRAME_X  * (player->mStamina / PL_ST_X)
#define SPEED_COLAR		0.05f

void CUserinterface::Init(){
	/*作成*/
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
	/*テクスチャ読み込み*/
	/*プレイヤー*/
	/*ヒットポイント*/
	mPlayerGageTex[_HP_]->load(TEX_FILE"UI_player_HP_gauge.tga");
	mPlayerFrameHpTex->load(TEX_FILE"UI_player_Frame.tga");
	/*スタミナ*/
	mPlayerGageTex[_ST_]->load(TEX_FILE"UI_sutamina3.tga");
	mPlayerFrameStTex[_HIGH_]->load(TEX_FILE"UI_sutamina2.tga");
	mPlayerFrameStTex[_NORM_]->load(TEX_FILE"UI_sutamina2.tga");
	mPlayerFrameStTex[_LOW_]->load(TEX_FILE"UI_sutamina1.tga");
	//
	/*エネミー*/
	mEnemyGageTex->load(TEX_FILE"UI_Enemy_HP_gauge.tga");
	mEnemyFrameTex->load(TEX_FILE"UI_Enemy_HP_Frame.tga");
	//
	/*テクスチャを張る*/
	/*PLAYER*/
	mGaugePlayer[_HP_].SetUv(mPlayerGageTex[_HP_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	mFramePlayer[_HP_].SetUv(mPlayerFrameHpTex, 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	mGaugePlayer[_ST_].SetUv(mPlayerGageTex[_ST_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	mFramePlayer[_ST_].SetUv(mPlayerFrameStTex[_HIGH_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	//
	/*エネミー*/
	mGaugeEne.SetUv(mEnemyGageTex, 0, 0, SIZE_TEX_EN_FRAME_X, SIZE_TEX_EN_FRAME_Y);
	mFrameEne.SetUv(mEnemyFrameTex, 0, 0, SIZE_TEX_EN_FRAME_X, SIZE_TEX_EN_FRAME_Y);


}

const float arealeft_x = character_limit_left + (DISP_X / 2) - SIZE_PLAYER_X * 2;
const float arearifgt_x = character_limit_right - (DISP_X / 2) - SIZE_PLAYER_X * 3;

CUserinterface::CUserinterface() : mFlagColar(false), mHungryC(1.0f), mFlagHP(true), mFlagST(true)
{
	mPriorityR = E_UI;
	mPriorityU = E_UI;
	mMyNumber = E_UI;
	/*四角作成*/
	mFramePlayer[_HP_].SetVertex(-SIZE_PL_FRAME_X, SIZE_PL_FRAME_Y, SIZE_PL_FRAME_X, -SIZE_PL_FRAME_Y); //四角作成
	mFramePlayer[_ST_].SetVertex(-SIZE_PL_FRAME_X, SIZE_PL_FRAME_Y, SIZE_PL_FRAME_X, -SIZE_PL_FRAME_Y); //四角作成
	/*カラーを決める*/
	mGaugePlayer[_HP_].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を決める
	mFramePlayer[_HP_].SetColor(1.0f, 1.0f, 1.0f, 1.0f);//色を決める

	mGaugePlayer[_ST_].SetColor(1.0f, 1.0f, 0.0f, 1.0f); //色を決める 
	mFramePlayer[_ST_].SetColor(1.0f, 1.0f, 0.0f, 1.0f);//色を決める

	/*エネミー*/

	mFrameEne.SetVertex(-SIZE_EN_FRAME_X, SIZE_EN_FRAME_Y, SIZE_EN_FRAME_X, -SIZE_EN_FRAME_Y); //四角作成

	mGaugeEne.SetColor(0.0f, 1.0f, 1.0f, 1.0f); //色を決める
	mFrameEne.SetColor(1.0f, 1.0f, 1.0f, 1.0f);//色を決める
	savex = first_pos.x;

	/*追加したときにキャラクターがいれば && UIがついていない場合UIをつける*/
	CTask *t; //探索用
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
void CUserinterface::SetHungC(const CPlayer *player){
	/*カラー設定*/
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

	/*gauge切り替え*/
	if (player->HUNGRY_S_HIGH_IF)		{//おなかいっぱいのUI
		mGaugePlayer[_ST_].SetColor(1.0f, 1.0f, 1.0f, 1.0f);
		mGaugePlayer[_ST_].SetUv(mPlayerGageTex[_ST_], 0, 0, T_ST_RIGHT, SIZE_TEX_PLAYER_FRAME_Y);
		mFramePlayer[_ST_].SetUv(mPlayerFrameStTex[_HIGH_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);

	}
	else if (player->HUNGRY_S_LOW_IF)	{//おなか減ったのUI
		mGaugePlayer[_ST_].SetColor(mHungryC, 0.5f, 0.5f, 1.0f);
		mFramePlayer[_ST_].SetColor(mHungryC, mHungryC, mHungryC, 1.0f);
		mGaugePlayer[_ST_].SetUv(mPlayerGageTex[_ST_], 0, 0, T_ST_RIGHT, SIZE_TEX_PLAYER_FRAME_Y);
		mFramePlayer[_ST_].SetUv(mPlayerFrameStTex[_LOW_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	}
	else								{//普通の状態
		mGaugePlayer[_ST_].SetColor(0.8f, 0.8f, 0.8f, 1.0f);
		mGaugePlayer[_ST_].SetUv(mPlayerGageTex[_ST_], 0, 0, T_ST_RIGHT, SIZE_TEX_PLAYER_FRAME_Y);
		mFramePlayer[_ST_].SetUv(mPlayerFrameStTex[_HIGH_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	}
	if (player->mStamina <= 0){ //おなかが減ってHPが削れる状態
		mFlagST = false;		//ついでにレンダー表示消しておく
		mFramePlayer[_HP_].SetColor(mHungryC, mHungryC, mHungryC, 1.0f);
	}
	else{
		mFlagST = true;			//おなか復活したのでフラグを立てる
	}
	if (player->mHitPoint <= 0){
		mFlagHP = false;
	}
	else{
		mFlagHP = true;
	}
}


void CUserinterface::Update(){
	if (task != 0){
		mPriorityR = task->mPriorityR;
		switch (task->mMyNumber)
		{
			/*プレーイヤー*/
		case E_PLAYER:
			CPlayer *player;
			player = (CPlayer*)task;
			mGaugePlayer[_HP_].position = CVector2(CGame::CameraPos().x - DISP_X + HP_POSX + SIZE_PL_FRAME_X,			DISP_Y - PL_ST_Y * 2);
			mGaugePlayer[_ST_].position = CVector2(CGame::CameraPos().x - DISP_X + ST_POSX + SIZE_PL_FRAME_X,			DISP_Y - PL_ST_Y * 4);
			mFramePlayer[_HP_].position = CVector2(CGame::CameraPos().x - DISP_X + SIZE_PL_FRAME_X,						DISP_Y - PL_ST_Y * 2);
			mFramePlayer[_ST_].position = CVector2(CGame::CameraPos().x - DISP_X + SIZE_PL_FRAME_X,						DISP_Y - PL_ST_Y * 4);
			mGaugePlayer[_HP_].SetVertex(-player->mHitPoint, SIZE_PL_FRAME_Y, player->mHitPoint, -SIZE_PL_FRAME_Y); //四角作成
			mGaugePlayer[_ST_].SetVertex(-player->mStamina, SIZE_PL_FRAME_Y, player->mStamina, -SIZE_PL_FRAME_Y); //四角作成
			SetHungC(player);
			
			break;
			/*エネミー*/
		case E_ENEMY00:
		case E_BOSS:
		case E_ENEMY01:

			CBase *base;
			base = (CBase*)task;
			mGaugeEne.position = CVector2(base->mPos.x - ENE_HP_POSX, base->mPos.y + base->mRect.triangle1.y1);
			mFrameEne.position = CVector2(base->mPos.x, base->mPos.y + base->mRect.triangle1.y1);
			mGaugeEne.SetVertex(-base->mHitPoint, ENE_HP_Y, base->mHitPoint, -ENE_HP_Y); //四角
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
			mGaugeEne.Render();
			mFrameEne.Render();
		}
	}
}