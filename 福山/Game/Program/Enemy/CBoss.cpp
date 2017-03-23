#include "CBoss.h"
#include "../MyNumber/CMyNumber.h"
#include "../CGame/CGame.h"
#include <cstdlib>
#include <stdio.h>
#include<time.h>
#include<iostream>
#include "../Load/CLoadBoss.h"
#include "../Load/CLoadPlayer.h"
#include "../CGame/CGame.h"
#include"CEnemybasetest.h"
/*

CKeyを使っている条件文は今後別の処理になります。

高橋弘樹

*/

#define FIRST_R_NO_BOSS 1						//初めのレンダーのポイント
#define FIRST_U_NO_BOSS 1						//初めのアップデートのポイント
#define SIZE_TEX_BOSS_STAY_X 360			//エネミーの待ち姿テクスチャサイズ X
#define SIZE_TEX_BOSS_STAY_Y 360			//エネミーの待ち姿テクスチャサイズ Y
#define SIZE_TEX_BOSS_WALK_X 800			//エネミーの歩くテクスチャサイズ Y
#define SIZE_TEX_BOSS_WALK_Y 800			//エネミーの歩く姿テクスチャサイズ Y
#define SIZE_SHADOW							//影の表示
#define WALK_SPEED 0.04						//歩くスピード
#define WALK_X 2							//歩くベクトルX
#define WALK_Y 1							//歩くベクトルY

#define ANIME_TIME_BASE				 6
#define ANIME_TIME_HATTACK			12

#define BOSS_STAY 	 "../CG\\BOSS\\stay\\"
#define BOSS_WALK	 "../CG\\BOSS\\walk\\"
#define BOSS_ATTACK	 "../CG\\BOSS\\Attack\\"
#define BOSS_HATTACK "../CG\\BOSS\\HAttack\\"
#define BOSS_DIE	 "../CG\\BOSS\\die\\"

#define LOW_AT		mForward.x, SIZE_BOSS_X*1.5f, SIZE_BOSS_Y,1.445f, mPos      	//攻撃範囲
#define HIGH_AT		mForward.x, SIZE_BOSS_X*2.5f, SIZE_BOSS_Y,2.5f, mPos      	//攻撃範囲
#define MOVE_AT		mForward.x, SIZE_BOSS_X*1.25f, SIZE_BOSS_Y,1.345f, mPos      	//攻撃範囲


void CBoss::SetPos(){
	mPos = Boss_first_pos;
	mAxis = mPos.y;
};

void CBoss::Init(){
	SetPos();
	/*テクスチャを張る*/
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mRect.SetUv(CLoadBoss::GetInstance()->mStay_tex[0], 0, 0, -SIZE_TEX_BOSS_STAY_X, SIZE_TEX_BOSS_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

}

//BOSS描画
CBoss::CBoss() : mVelocity(0), mFrameCount(0), actionflag(false), motion(0), direction(0){

	/*テクスチャを張る*/
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mRect.SetUv(CLoadBoss::GetInstance()->mStay_tex[0], 0, 0, -SIZE_TEX_BOSS_STAY_X, SIZE_TEX_BOSS_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);
	mPriorityR = E_BOSS;			//Renderのナンバー 
	mPriorityU = E_BOSS;			//Updateのナンバー
	mHitPoint = ENE_HP_X;		//ＨＰ
	mMyNumber = E_BOSS;
	mStatus = E_STAY_L;

	//四角形の頂点設定
	mRect.SetVertex(-SIZE_BOSS_X, SIZE_BOSS_Y, SIZE_BOSS_X, -SIZE_BOSS_Y);
	mShadow.SetVertex(-SIZE_SHADOW_X, SIZE_SHADOW_Y, SIZE_SHADOW_X, -SIZE_SHADOW_Y);
	//四角形の色を設定
	mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
}

CBoss::~CBoss(){


}

void CBoss::AnimeScene(){
	/*アニメーションのステータス*/
	switch (mStatus)
	{
		/*待機中*/
	case E_STAY_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mStay_tex[mAnimeFrame], 0, 0, SIZE_TEX_BOSS_STAY_X, SIZE_TEX_BOSS_STAY_Y);
		break;
	case E_STAY_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mStay_tex[mAnimeFrame], SIZE_TEX_BOSS_STAY_X, 0, 0, SIZE_TEX_BOSS_STAY_Y);
		break;
		/*歩き中*/
	case E_WALK_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mWalk_tex[mAnimeFrame], 0, 0, SIZE_TEX_BOSS_WALK_X, SIZE_TEX_BOSS_WALK_Y);
		break;
	case E_WALK_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mWalk_tex[mAnimeFrame], SIZE_TEX_BOSS_WALK_X, 0, 0, SIZE_TEX_BOSS_WALK_Y);
		break;
		/*攻撃*/
	case E_ATTACK_L:
		AnimeFrame(false, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mAttack_tex[mAnimeFrame], 0, 0, SIZE_TEX_BOSS_WALK_X, SIZE_TEX_BOSS_WALK_Y);
		break;
	case E_ATTACK_R:
		AnimeFrame(false, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mAttack_tex[mAnimeFrame], SIZE_TEX_BOSS_WALK_X, 0, 0, SIZE_TEX_BOSS_WALK_Y);
		break;
		/*強攻撃*/
	case E_HATTACK_L:
		AnimeFrame(false, ANIME_TIME_HATTACK);
		mRect.SetUv(CLoadBoss::GetInstance()->mHattack_tex[mAnimeFrame], 0, 0, SIZE_TEX_BOSS_WALK_X, SIZE_TEX_BOSS_WALK_Y);
		break;
	case E_HATTACK_R:
		AnimeFrame(false, ANIME_TIME_HATTACK);
		mRect.SetUv(CLoadBoss::GetInstance()->mHattack_tex[mAnimeFrame], SIZE_TEX_BOSS_WALK_X, 0, 0, SIZE_TEX_BOSS_WALK_Y);
		break;
		/*死亡*/
	case E_DIE_L:
		AnimeFrame(false, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mDie_tex[mAnimeFrame], 0, 0, SIZE_TEX_BOSS_WALK_X, SIZE_TEX_BOSS_WALK_Y);
		break;
	case E_DIE_R:
		AnimeFrame(false, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mDie_tex[mAnimeFrame], SIZE_TEX_BOSS_WALK_X, 0, 0, SIZE_TEX_BOSS_WALK_Y);
		break;

	}
}

void CBoss::Walk(){
	//（ターゲットが右にいる場合）
	if (RIGHT_PTT) {
		direction = 0;
		mStatus = E_WALK_R;
		mVelocity = WALK_SPEED;
		mForward = CVector2(WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}
	//（ターゲットが左にいる場合）
	if (LEFT_PTT) {
		direction = 1;
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

void CBoss::Motion(){

	switch (motion)
	{
	case EM_STAY://待機
		if (direction == 0){	//右向き
			mStatus = E_STAY_R;
		}
		else if (direction = 1){	//左向き

			mStatus = E_STAY_L;
		}
		if (ENEMY_VISI)		//視界内にとらえたら追ってくる
		{
			motion = EM_WALK;
		}
		break;
	case EM_WALK://歩き	
		Walk();
		if (ATTACK_PTTX){//攻撃モーションに変更
			actionflag = false;
			motion = EM_RANGE;
		}
		if (HATTACK_PTT){
			actionflag = false;
			motion = EM_RANGE;
		}

		break;
	case EM_RANGE://攻撃範囲内に入った時
		if (ATTACK_PTTX){
			if (!actionflag){
				pattern = rand() % 6; //0~2の中でランダムでパターンを選択する。
			}
			if (pattern == 0){
				motion = EM_ATTACK;
			}
			else if (pattern == 1){
				actionflag = true;
				motion = EM_BACK_X;
			}
			else{
				motion = EM_ATTACK;
			}
		}

		////強攻撃の範囲内(未実装)ブラッシュアップ
		//if (HATTACK_PTT){
		//	if (!actionflag){
		//		pattern = rand() % 3; //0~2の中でランダムでパターンを選択する。
		//	}
		//	if (pattern == 0){
		//		motion = EM_HIGH_AT;
		//	}
		//	else if (pattern == 1){
		//		actionflag = true;
		//		motion = EM_BACK_X;
		//	}
		//	else if (pattern == 2){
		//		motion = EM_ATTCK;
		//	}
		//}
		if (NO_ATTACK_PTTX){
			actionflag = false;
			motion = EM_WALK;
		}
		break;
	case EM_DIE://死亡
		if (direction == 0) {
			mStatus = E_DIE_R;
		}
		else if (direction == 1){
			mStatus = E_DIE_L;
		}
		break;

	case EM_BACK_X://後ろに逃げる。
		if (direction == 1) {
			direction = 1;
			mVelocity = WALK_SPEED * 3;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;

		}
		else if (direction == 0){
			direction = 0;
			mVelocity = -WALK_SPEED * 3;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;
		}

		if (ENEMY_ESCAPE){	//一定距離離れると再度こちらに向かってくる
			actionflag = false; //actionflagをfalseにする。
			motion = EM_WALK;
		}

		break;
	case EM_ATTACK:		//攻撃中
		/*モーション設定*/
		if (RIGHT_PTT) {
			mStatus = E_ATTACK_R;
		}
		else{
			mStatus = E_ATTACK_L;
		}
		/*範囲*/
		Attack(LOW_AT);
		///パンチの最後にあたり判定
		mEnabledAttack = true;
		/*範囲内に近づく*/
		if (rulerR > 2 || rulerL > 2){
			actionflag = false;
			mEnabledAttack = false;
			motion = EM_WALK;
		}
		break;

	case EM_HIGH_AT:
		/*モーション設定*/
		if (RIGHT_PTT) {
			mStatus = E_HATTACK_R;
		}
		else{
			mStatus = E_HATTACK_L;
		}
		/*範囲設定*/
		Attack(HIGH_AT);
		if (mAnimeFrame == FRAME_LIMIT - 1){	//パンチの最後にあたり判定
			mEnabledAttack = true;//攻撃終了
			motion = EM_RANGE;				//索敵
		}
		else{
			mEnabledAttack = false;
		}
		break;


	}
}

void CBoss::Update(){
	mRect.position = mPos;

	mTargetP = CGame::mGetPlayerPos();
	getAxis = CGame::GetPlayerAxis();

	rulerR = mTargetP.x - mPos.x;	//プレイヤーとの距離を出す
	rulerL = mPos.x - mTargetP.x;
	if (rulerL<0){				//絶対値にする
		rulerL = rulerL * -1;
	}
	if (rulerR<0){
		rulerR = rulerR * -1;
	}

	upruler = mTargetP.y - mPos.y;
	downruler = mPos.y - mTargetP.y;
	if (upruler<0){				//絶対値にする
		upruler = upruler * -1;
	}
	if (downruler<0){
		downruler = downruler * -1;
	}

	if (mHitPoint <= 0){
		motion = EM_DIE;		//体力が０ならDIEする
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
	Motion();

	AlertHPRect(&mRect, mHitPoint);	//アラートメソッド(HP変化によるもの)
	/*軸の設定*/
	mAxis = mPos.y - SIZE_BOSS_Y;
	mAttackRange.position = mPos;
	/*範囲外調整*/
	LimitDisp(SIZE_BOSS_X, SIZE_BOSS_Y);
	/*レンダー順番設定*/
	mPriorityR = -mAxis;
	LimitDisp(SIZE_BOSS_X, SIZE_BOSS_Y);	//当たり判定
	AnimeScene();
	mShadow.position = CVector2(mPos.x, mAxis);

	mRect.position = mPos;
}

void CBoss::Render(){

	mShadow.Render();
	mRect.Render();
}
