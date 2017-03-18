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

void CUserinterface::Init(){
	mPlayerGageTex[_HP_] = new CTexture();
	mPlayerGageTex[_ST_] = new CTexture();
	mPlayerFrameTex[_HP_] = new CTexture();
	mPlayerFrameTex[_ST_] = new CTexture();

	mEnemyGageTex = new CTexture();
	mEnemyFrameTex = new CTexture();

	/*テクスチャ読み込み*/
	mPlayerGageTex[_HP_]->load(TEX_FILE"UI_player_HP_gauge.tga");
	mPlayerFrameTex[_HP_]->load(TEX_FILE"UI_player_Frame.tga");
	mPlayerGageTex[_ST_]->load(TEX_FILE"UI_player_HP_gauge.tga");
	mPlayerFrameTex[_ST_]->load(TEX_FILE"UI_player_Frame.tga");
	mEnemyGageTex->load(TEX_FILE"UI_Enemy_HP_gauge.tga");
	mEnemyFrameTex->load(TEX_FILE"UI_Enemy_HP_Frame.tga");

	/*テクスチャを張る*/
	mGaugePlayer[_HP_].SetUv(mPlayerGageTex[_HP_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	mFramePlayer[_HP_].SetUv(mPlayerFrameTex[_HP_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	mGaugePlayer[_ST_].SetUv(mPlayerGageTex[_ST_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
	mFramePlayer[_ST_].SetUv(mPlayerFrameTex[_ST_], 0, 0, SIZE_TEX_PLAYER_FRAME_X, SIZE_TEX_PLAYER_FRAME_Y);
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
	CGame::Delete(&mPlayerFrameTex[_HP_]);
	CGame::Delete(&mPlayerFrameTex[_ST_]);

	CGame::Delete(&mEnemyGageTex);
	CGame::Delete(&mEnemyFrameTex);

}



void CUserinterface::Update(){
	if (task != 0){
		switch (task->mMyNumber)
		{
		case E_PLAYER:
			CPlayer *player;
			player = (CPlayer*)task;
			//表示するエリアを指定

			//表示するエリアを指定
			if (arealeft_x <= CPlayer::camera_x&& arearifgt_x >= CPlayer::camera_x){

				savex = CPlayer::camera_x;

				mGaugePlayer[_HP_].position = CVector2(player->mPos.x - SIZE_PL_FRAME_X * 2, DISP_Y - SIZE_PL_FRAME_Y * 2);
				mFramePlayer[_HP_].position = CVector2(player->mPos.x - SIZE_PL_FRAME_X * 2, DISP_Y - SIZE_PL_FRAME_Y * 2);
				mGaugePlayer[_ST_].position = CVector2(player->mPos.x - SIZE_PL_FRAME_X * 2, DISP_Y - SIZE_PL_FRAME_Y * 4);
				mFramePlayer[_ST_].position = CVector2(player->mPos.x - SIZE_PL_FRAME_X * 2, DISP_Y - SIZE_PL_FRAME_Y * 4);
			}
			else{

				mGaugePlayer[_HP_].position = CVector2(savex - SIZE_PL_FRAME_X * 2, DISP_Y - SIZE_PL_FRAME_Y * 2);
				mFramePlayer[_HP_].position = CVector2(savex - SIZE_PL_FRAME_X * 2, DISP_Y - SIZE_PL_FRAME_Y * 2);
				mGaugePlayer[_ST_].position = CVector2(savex - SIZE_PL_FRAME_X * 2, DISP_Y - SIZE_PL_FRAME_Y * 4);
				mFramePlayer[_ST_].position = CVector2(savex - SIZE_PL_FRAME_X * 2, DISP_Y - SIZE_PL_FRAME_Y * 4);
			}

			mGaugePlayer[_HP_].SetVertex(-player->mHitPoint, SIZE_PL_FRAME_Y, player->mHitPoint, -SIZE_PL_FRAME_Y); //四角作成
			mGaugePlayer[_ST_].SetVertex(-player->mStamina, SIZE_PL_FRAME_Y, player->mStamina, -SIZE_PL_FRAME_Y); //四角作成

			break;
		case E_ENEMY00:

			CEnemy00 *ene00;
			ene00 = (CEnemy00*)task;
			mGaugeEne.position = CVector2(ene00->mPos.x, ene00->mPos.y + SIZE_ENEMY00_Y);
			mFrameEne.position = CVector2(ene00->mPos.x, ene00->mPos.y + SIZE_ENEMY00_Y);
			mGaugeEne.SetVertex(-ene00->mHitPoint, ENE_HP_Y, ene00->mHitPoint, -ENE_HP_Y); //四角
			if (ene00->mHitPoint <= 0){
				mKillFlag = true;
			}
			break;
		case E_ENEMY01:
			CEnemy01 *ene01;
			ene01 = (CEnemy01*)task;
			mGaugeEne.position = CVector2(ene01->mPos.x, ene01->mPos.y + SIZE_ENEMY01_Y);
			mFrameEne.position = CVector2(ene01->mPos.x, ene01->mPos.y + SIZE_ENEMY01_Y);
			mGaugeEne.SetVertex(-ene01->mHitPoint, SIZE_EN_FRAME_Y, ene01->mHitPoint, -SIZE_EN_FRAME_Y); //四角作成
			if (ene01->mHitPoint <= 0){
				mKillFlag = true;
			}
			break;
		case E_BOSS:
			CBoss *boss;
			boss = (CBoss*)task;
			mGaugeEne.position = CVector2(boss->mPos.x, boss->mPos.y + SIZE_BOSS_Y);
			mFrameEne.position = CVector2(boss->mPos.x, boss->mPos.y + SIZE_BOSS_Y);
			mGaugeEne.SetVertex(-boss->mHitPoint, SIZE_BOSS_FRAME_Y, boss->mHitPoint, -SIZE_BOSS_FRAME_Y); //四角作成
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