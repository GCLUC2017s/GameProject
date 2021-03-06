#include "CEnemy00.h"
#include "../MyNumber/CMyNumber.h"
#include "../CGame/CGame.h"
#include "stdio.h"
#include <cstdlib>
#include<time.h>
#include<iostream>
#include "CEnemybasetest.h"
#include "../Load/CLoadEnemy00.h"
#include "../Base/CBase.h"
/*

高橋弘樹

*/
#define FIRST_R_NO_ENEMY00 1						//初めのレンダーのポイント
#define FIRST_U_NO_ENEMY00 1						//初めのアップデートのポイント
#define SIZE_TEX_ENEMY00_STAY_X 160			//エネミーの待ち姿テクスチャサイズ X
#define SIZE_TEX_ENEMY00_STAY_Y 160		//エネミーの待ち姿テクスチャサイズ Y
#define SIZE_TEX_ENEMY00_WALK_X 160		//エネミーの歩くテクスチャサイズ Y
#define SIZE_TEX_ENEMY00_WALK_Y 160		//エネミーの歩く姿テクスチャサイズ Y
#define SIZE_SHADOW							//影の表示
#define PATTERN_R 1							//PATTERNの右
#define PATTERN_L 2							//PATTERNの左

#define ANIME_TIME_BASE						6							//アニメのループ時間 継続的なもの
#define ANIME_TIME_ATTACK					6							//アニメのループ時間 攻撃のもの

#define WALK_SPEED 0.02f				//歩くスピード
#define WALK_X 2						//歩くベクトルX
#define WALK_Y 1						//歩くベクトルY

#define AT_RANGE00		mForward.x, SIZE_ENEMY00_X*1.5, SIZE_ENEMY00_Y,2, CVector2(mPos.x+mForward.x*0.1,mPos.y) 

#define ENEMY00_STAY "../CG\\enemy00\\enemy00_stay\\"
#define ENEMY00_WALK "../CG\\enemy00\\enemy00_walk\\"
#define ENEMY00_ATTACK "../CG\\enemy00\\enemy00_attack\\"
#define ENEMY00_DIE "../CG\\enemy00\\enemy00_dai\\"
#include "../Load/CLoadPlayer.h"


void CEnemy00::Init(){
	RandPos(SIZE_ENEMY00_X, SIZE_ENEMY00_Y, &mPos,  DISP_X*4, DISP_X*6);
	/*テクスチャを張る*/
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mRect.SetUv(CLoadEnemy00::GetInstance()->mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);
	//RandPos(SIZE_ENEMY00_X, SIZE_ENEMY00_Y, &mPos,  DISP_X*3, DISP_X * 10);
	///*テクスチャを張る*/
	//mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	//mRect.SetUv(CLoadEnemy00::GetInstance()->mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	//mForward = CVector2(1.0f, 0.0f);

	//srand((unsigned int)time(NULL));

}



//エネミー00描画
CEnemy00::CEnemy00() : mVelocity(0), mFrameCount(0), actionflag(false), motion(EM_STAY), direction(E_LEFT), escapetime(0), attacktime(0) {

	Init();

	RandPos(SIZE_ENEMY00_X, SIZE_ENEMY00_Y, &mPos, DISP_X * 3, DISP_X * 10);
	/*テクスチャを張る*/
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mRect.SetUv(CLoadEnemy00::GetInstance()->mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

	srand((unsigned int)time(NULL));

	mPriorityR = E_ENEMY00;			//Renderのナンバー 
	mPriorityU = E_ENEMY00;			//Updateのナンバー
	mHitPoint = ENE_HP_X;		//ＨＰ
	mMyNumber = E_ENEMY00;
	mStatus=E_STAY_L;

	//四角形の頂点設定
	mRect.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	mShadow.SetVertex(-SIZE_SHADOW_X, SIZE_SHADOW_Y, SIZE_SHADOW_X, -SIZE_SHADOW_Y);
	//四角形の色を設定
	mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	
}

CEnemy00::~CEnemy00(){
}

void CEnemy00::AnimeScene(){

	/*アニメーションのステータス*/
	switch (mStatus)
	{
		/*待機中*/
	case E_STAY_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mStay_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_STAY_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mStay_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*歩き中*/
	case E_WALK_L:
		AnimeFrame(true, ANIME_TIME_BASE);
			mRect.SetUv(CLoadEnemy00::GetInstance()->mWalk_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	case E_WALK_R:
		AnimeFrame(true, ANIME_TIME_BASE);
			mRect.SetUv(CLoadEnemy00::GetInstance()->mWalk_tex[mAnimeFrame], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
		break;
		/*攻撃中*/
	case E_ATTACK_R:
		AnimeFrame(true, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mAttack_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_ATTACK_L:
		AnimeFrame(true, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mAttack_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*死亡*/
	case E_DIE_R:
		AnimeFrame(false, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mDie_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_DIE_L:
		AnimeFrame(false, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mDie_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;

	}
}

void CEnemy00::Walk(){

	//（ターゲットが右にいる場合）
	if (RIGHT_PTT) {
		direction = E_RIGHT;
		mStatus = E_WALK_R;
		mVelocity = WALK_SPEED;
		mForward = CVector2(WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}
	
	//（ターゲットが左にいる場合）
	if (LEFT_PTT) {
		direction = E_LEFT;
		mStatus = E_WALK_L;
		mVelocity = WALK_SPEED;
		mForward = CVector2(-WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}
	//（ターゲットが上にいる場合）
	if ((CGame::GetPlayerAxis() + CGame::mGetPlayerPos().y) / 2 > mAxis) {
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;
	}
	//（ターゲットが下にいる場合）
	if ((CGame::GetPlayerAxis() + CGame::mGetPlayerPos().y) / 2 < mAxis) {
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, -WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;
	}


}

void CEnemy00::Motion(){

	switch (motion)
	{
	case EM_STAY://待機
	{
		pattern = rand() % 4;//初回行動を4択から出す
		
		if (direction == E_RIGHT){	//右向き
			mStatus = E_STAY_R;
		}
		else if (direction = E_LEFT){	//左向き

			mStatus = E_STAY_L;
		}

		if (ENEMY_VISI)		//視界内にとらえたら追ってくる(実質的な初回行動の開始)
		
			if (pattern == 0){
				motion = EM_WALK;	//通常のウォーク分岐に入る
			
			}
			if (pattern == 1){
				motion = EM_BACK_Y;
			
			}
			if (pattern == 2){
				motion = EM_Slanting;
			
			}
			if (pattern == 3){
				motion = EM_BACK_X;
		
			}
	
	
		}

		break;
	case EM_WALK://歩き	
		Walk();

		if (ATTACK_PTTX&&ATTACK_PTTY){//攻撃モーションに変更
			actionflag = false;
			motion = EM_RANGE;
		}

		break;
	case EM_RANGE://攻撃範囲内に入った時

			if (!actionflag){
				pattern = rand() % 3; //0~2の中でランダムでパターンを選択する。

				if (pattern == 0 && ATTACK_PTTY){
					motion = EM_ATTACK;
					delay = 0;
				}
				else if (pattern == 1){
					actionflag = true;
					motion = EM_BACK_X;
					delay = 0;
				}
				else if (pattern == 2){
					motion = EM_BACK_Y;
					delay = 0;
				}

				if (NO_ATTACK_PTTX&&NO_ATTACK_PTTY){
					actionflag = false;
					motion = EM_WALK;
					delay = 0;
				}
			
		}

		break;

	case EM_DIE://死亡
		if (direction == E_RIGHT) {
			mStatus = E_DIE_R;
			mEnabledAttack = false;
		}
		else if (direction == E_LEFT){
			mStatus = E_DIE_L;
			mEnabledAttack = false;
		}
		break;

	case EM_BACK_X://後ろに逃げる。
		escapetime += ESCAPE_TIME / FPS;
		

		if (direction == E_LEFT) {
			direction = E_LEFT;
			mVelocity = WALK_SPEED * 3;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;

		}
		else if (direction == E_RIGHT){
			direction = E_RIGHT;
			mVelocity = -WALK_SPEED * 3;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;
		}

		if (escapetime>=ESCAPE_TIME){	//一定距離離れると再度こちらに向かってくる
			escapetime = 0;
			motion = EM_WALK;
		}

		break;
	case EM_BACK_Y:		//上下に逃げる
	
	
		if (mAxis < getAxis){
			mVelocity = WALK_SPEED * 3;
			mForward = CVector2(0.0f, -WALK_Y);
			mPos += mForward * mVelocity;
			mAxis += mForward.y * mVelocity;
			if (mAxis == character_limit_bottom){
				motion = EM_WALK;
				actionflag = false;
				break;
			}
		}
		else if (mAxis >= getAxis){
			mVelocity = WALK_SPEED * 3;
			mForward = CVector2(0.0f, WALK_Y);
			mPos += mForward * mVelocity;
			mAxis += mForward.y * mVelocity;
			if (mAxis == character_limit_top){
				motion = EM_WALK;
				actionflag = false;
				break;
			}
		}

	case EM_ATTACK:		//攻撃中
		attacktime += ENEMY00_INTERVAL / FPS;

		if (attacktime < ENEMY00_INTERVAL){
			if (RIGHT_PTT&&mHitPoint>0) {
				actionflag = true;
				mEnabledAttack = true;
				mStatus = E_ATTACK_R;
			}
			else if (LEFT_PTT&&mHitPoint>0){
				actionflag = true;
				mEnabledAttack = true;
				mStatus = E_ATTACK_L;
			}
		}
		//攻撃範囲とあたり判定フラグ

		if (NO_ATTACK_PTTX){
			actionflag = false;
			motion = EM_WALK;
			mEnabledAttack = false;
		}
		if (NO_ATTACK_PTTY || attacktime >= ENEMY00_INTERVAL + ENEMY00_DELAY){
			attacktime = 0;
			actionflag = false;
			motion = EM_RANGE;
			mEnabledAttack = false;
		}
		Attack(AT_RANGE00);
		break;

	case EM_Slanting:
		escapetime += ESCAPE_TIME / FPS;

		if (direction == E_LEFT) {
			direction = E_LEFT;
			mVelocity = WALK_SPEED * 1.5f;
			mForward = CVector2(WALK_X, WALK_Y);
			mPos += mForward * mVelocity;

		}
		else if (direction == E_RIGHT){
			direction = E_RIGHT;
			mVelocity = -WALK_SPEED * 1.5f;
			mForward = CVector2(WALK_X, -WALK_Y);
			mPos += mForward * mVelocity;
		}

		if (ENEMY_ESCAPE || escapetime >= ESCAPE_TIME){	//一定距離離れると再度こちらに向かってくる
			escapetime = 0;
			motion = EM_WALK;
		}





		break;
	}

}

void CEnemy00::Update(){
	mRect.position = mPos;
	//mTargetPをplayerにする
	mTargetP = CGame::mGetPlayerPos();
	getAxis = CGame::GetPlayerAxis();
	
	rulerR = mTargetP.x - mPos.x;	//プレイヤーとの距離を出す		//このあたりの処理は全エネミー共通なのでどこかに移したい。
	rulerL = mPos.x- mTargetP.x;
	if (rulerL<0){				//絶対値にする
		rulerL = rulerL * -1;
	}
	if (rulerR<0){
		rulerR = rulerR * -1;
	}
	
	upruler = mTargetP.y-mPos.y;
	downruler = mPos.y - mTargetP.y;
	if (upruler<0){				//絶対値にする
		upruler = upruler * -1;
	}
	if (downruler<0){
		downruler = downruler * -1;
	}

	if (mHitPoint <= 0){
		motion = EM_DIE;
		mEnabledAttack = false;		//体力が０ならDIEする
	}
	if (mEnabledEaten){		//食べられたら消す
		//演出加えてもいいかも(例)拡大縮小してif(サイズが0以下の時killFlagを立てるなど)
		mKillFlag = true;
	}

	switch (direction)
	{
	case E_RIGHT:	//右向き
		break;
			case E_LEFT:	//左向き
		break;
	}

	mAttackRange.position = mPos;

	AlertHPRect(&mRect, mHitPoint);	//アラートメソッド(HP変化によるもの)
	//軸の設定
	mAxis = mPos.y - SIZE_ENEMY00_Y;
	//範囲外調整
	LimitDisp(SIZE_ENEMY00_X, SIZE_ENEMY00_Y);
	//レンダー順番設定
	mPriorityR = -mAxis;
	AnimeScene();
	mRect.position = mPos;
	mShadow.position = CVector2(mPos.x, mAxis);


	Motion();		//モーション呼び出し。

}

void CEnemy00::Render(){

	mShadow.Render();
	mRect.Render();
}
