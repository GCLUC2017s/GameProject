#include "CBoss.h"
#include "../MyNumber/CMyNumber.h"
#include "../CGame/CGame.h"
#include <cstdlib>
#include <stdio.h>
#include<time.h>
#include<iostream>
#include "CEnemybasetest.h"
#include "../Load/CLoadBoss.h"
#include "../Load/CLoadPlayer.h"

/*


CKeyを使っている条件文は今後別の処理になります。

高橋弘樹

*/

#define SIZE_BOSS_Y 1  //BOSSのサイズ_Y
#define SIZE_BOSS_X 1 //BOSSのサイズ_X

#define HITPOINT_BOSS 5					//BOSSの体力
#define FIRST_R_NO_BOSS 1						//初めのレンダーのポイント
#define FIRST_U_NO_BOSS 1						//初めのアップデートのポイント
#define SIZE_TEX_BOSS_STAY_X 800			//エネミーの待ち姿テクスチャサイズ X
#define SIZE_TEX_BOSS_STAY_Y 800			//エネミーの待ち姿テクスチャサイズ Y
#define SIZE_TEX_BOSS_WALK_X 800			//エネミーの歩くテクスチャサイズ Y
#define SIZE_TEX_BOSS_WALK_Y 800			//エネミーの歩く姿テクスチャサイズ Y
#define SIZE_SHADOW							//影の表示
#define WALK_SPEED 0.04						//歩くスピード
#define WALK_X 2							//歩くベクトルX
#define WALK_Y 1							//歩くベクトルY

#define ANIME_TIME_BASE 6

#define BOSS_STAY 	 "../CG\\BOSS\\stay\\"
#define BOSS_WALK	 "../CG\\BOSS\\walk\\"
#define BOSS_ATTACK	 "../CG\\BOSS\\Attack\\"
#define BOSS_HATTACK "../CG\\BOSS\\HAttack\\"
#define BOSS_DIE	 "../CG\\BOSS\\die\\"


inline void InitRand(){
	srand((unsigned int)time(NULL));
}

void CBoss::SetPos(){
	mPos = Boss_first_pos;
	mAxis = mPos.y;
};


void CBoss::Init(){
	SetPos();

	
	/*テクスチャを張る*/
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mRect.SetUv(CLoadBoss::GetInstance()->mStay_tex[0], 0, 0, SIZE_TEX_BOSS_STAY_X, SIZE_TEX_BOSS_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

}


//BOSS描画
CBoss::CBoss() : mVelocity(0), mFlameCount(0), actionflag(false), motion(0), direction(1){

	mPriorityR = E_BOSS;			//Renderのナンバー 
	mPriorityU = E_BOSS;			//Updateのナンバー
	mHitPoint = HITPOINT_BOSS;		//ＨＰ
	mMyNumber = E_BOSS;
	mStatus = E_STAY_L;

	//四角形の頂点設定
	mRect.SetVertex(SIZE_BOSS_X, SIZE_BOSS_Y, -SIZE_BOSS_X, -SIZE_BOSS_Y);
	mShadow.SetVertex(SIZE_BOSS_X, SIZE_BOSS_Y, -SIZE_BOSS_X, -SIZE_BOSS_Y);

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
		mRect.SetUv(CLoadBoss::GetInstance()->mStay_tex[mAnime], SIZE_TEX_BOSS_STAY_X, 0, 0, SIZE_TEX_BOSS_STAY_Y);
		break;
	case E_STAY_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mStay_tex[mAnime], 0, 0, SIZE_TEX_BOSS_STAY_X, SIZE_TEX_BOSS_STAY_Y);
		break;
		/*歩き中*/
	case E_WALK_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mWalk_tex[mAnime], SIZE_TEX_BOSS_WALK_X, 0, 0, SIZE_TEX_BOSS_WALK_Y);
		break;
	case E_WALK_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mWalk_tex[mAnime], 0, 0, SIZE_TEX_BOSS_WALK_X, SIZE_TEX_BOSS_WALK_Y);
		break;
		/*攻撃*/
	case E_ATTACK_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mAttack_tex[mAnime], SIZE_TEX_BOSS_WALK_X, 0, 0, SIZE_TEX_BOSS_WALK_Y);
		break;
	case E_ATTACK_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mAttack_tex[mAnime], 0, 0, SIZE_TEX_BOSS_WALK_X, SIZE_TEX_BOSS_WALK_Y);
		break;
		/*強攻撃*/
	case E_HATTACK_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mHattack_tex[mAnime], SIZE_TEX_BOSS_WALK_X, 0, 0, SIZE_TEX_BOSS_WALK_Y);
		break;
	case E_HATTACK_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mHattack_tex[mAnime], 0, 0, SIZE_TEX_BOSS_WALK_X, SIZE_TEX_BOSS_WALK_Y);
		break;
		/*死亡*/
	case E_DIE_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mDie_tex[mAnime], SIZE_TEX_BOSS_WALK_X, 0, 0, SIZE_TEX_BOSS_WALK_Y);
		break;
	case E_DIE_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mDie_tex[mAnime], 0, 0, SIZE_TEX_BOSS_WALK_X, SIZE_TEX_BOSS_WALK_Y);
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

void CBoss::Update(){
	assert(mAnime <= FLAME_LIMIT); //フレーム数が七を超えるとダメ
	mRect.position = mPos;

	InitRand();
	mTargetP = CGame::mGetPlayerPos();
	float getAxis = CGame::GetPlayerAxis();

	mPriorityR = -mAxis;

	rulerR = mTargetP.x - mPos.x;	//プレイヤーとの距離を出す
	rulerL = mPos.x - mTargetP.x;

	if (rulerL < 0){				//絶対値にする
		rulerL = rulerL * -1;
	}
	if (rulerR < 0){
		rulerR = rulerR * -1;
	}

	if (mHitPoint <= 0){
		motion = 2;		//体力が０ならDIEする
	}

	switch (motion)
	{
	case 0://待機
		if (direction == 0){	//右向き
			mStatus = E_STAY_R;
		}
		else if (direction = 1){	//左向き

			mStatus = E_STAY_L;
		}

		if (ENEMY_VISI)		//視界内にとらえたら追ってくる
		{
			motion = 1;
		}
		break;
	case 1://歩き	
		Walk();
		if (ATTACK_PTT){//攻撃モーションに変更
			actionflag = false;
			motion = 2;
		}
		if (HATTACK_PTT){
			actionflag = false;
			motion = 2;
		}

		break;
	case 2://攻撃範囲内に入った時
		if (ATTACK_PTT){
			if (!actionflag){
				pattern = rand() % 6; //0~2の中でランダムでパターンを選択する。
			}
			if (pattern == 0){
				mEnabledAttack = true;
				motion = 6;
			}
			else if (pattern == 1){
				actionflag = true;
				motion = 4;
			}
			else if (pattern == 2){
				motion = 6;
			}
			else if (pattern == 3){
				motion = 4;
			}
			else if (pattern == 4){
				motion = 6;
			}
			else if (pattern == 5){
				motion = 6;
			}
		}

		//強攻撃の範囲内
		if (HATTACK_PTT){
			if (!actionflag){
				pattern = rand() % 3; //0~2の中でランダムでパターンを選択する。
			}
			if (pattern == 0){
				mEnabledAttack = true;
				motion = 7;
			}
			else if (pattern == 1){
				actionflag = true;
				motion = 4;
			}
			else if (pattern == 2){
				mEnabledAttack = true;
				motion = 6;
			}
		}


		if (NO_ATTACK_PTT){
			actionflag = false;
			motion = 1;
		}
		break;
	case 3://死亡
		if (direction == 0) {
			mStatus = E_DIE_R;
		}
		else if (direction == 1){
			mStatus = E_DIE_L;
		}
		break;

	case 4://後ろに逃げる。
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
			motion = 1;
		}

		break;
	case 5:		//攻撃をしながら近づいてくる
		Walk();
		if (RIGHT_PTT && !mEnabledAttack) {
			mStatus = E_ATTACK_R;
		}
		else if (LEFT_PTT && !mEnabledAttack){
			mStatus = E_ATTACK_L;
		}
		/*範囲*/
		if (mEnabledAttack){
			mAttackRange.SetVertex(-SIZE_PLAYER_X, SIZE_PLAYER_Y, SIZE_PLAYER_X, -SIZE_PLAYER_Y);
			mAttackRange.SetColor(1.0f, 1.0f, 0.0f, 1.0f);
			if (RIGHT_PTT)mAttackRange.position = CVector2(mPos.x + 1, mPos.y);
			if (LEFT_PTT)mAttackRange.position = CVector2(mPos.x - 1, mPos.y);
			mAttackAxis = 2.0f;
		}
		if (mAnimeFrame == FRAME_LIMIT - 1){
			mEnabledAttack = false;//攻撃終了
		}
		if (rulerR > 2 || rulerL > 2){
			actionflag = false;
			motion = 1;
		}
		break;

	case 6:		//攻撃中

		if (RIGHT_PTT && !mEnabledAttack) {
			mStatus = E_ATTACK_R;
		}
		else if (LEFT_PTT && !mEnabledAttack){
			mStatus = E_ATTACK_L;
		}
		/*範囲*/
		if (mEnabledAttack){
			mAttackRange.SetVertex(-SIZE_PLAYER_X, SIZE_PLAYER_Y, SIZE_PLAYER_X, -SIZE_PLAYER_Y);
			mAttackRange.SetColor(1.0f, 1.0f, 0.0f, 1.0f);
			if (RIGHT_PTT)mAttackRange.position = CVector2(mPos.x + 1, mPos.y);
			if (LEFT_PTT)mAttackRange.position = CVector2(mPos.x - 1, mPos.y);
			mAttackAxis = 2.0f;
		}
		if (mAnimeFrame == FRAME_LIMIT - 1){
			mEnabledAttack = false;//攻撃終了
		}
		if (rulerR > 2 || rulerL > 2){
			actionflag = false;
			motion = 1;
		}
		break;
	case 7:
		if (RIGHT_PTT && !mEnabledAttack) {
			mStatus = E_HATTACK_R;
		}
		else if (LEFT_PTT && !mEnabledAttack){
			mStatus = E_HATTACK_L;
		}
		/*範囲*/
		if (mEnabledAttack){
			mAttackRange.SetVertex(-SIZE_PLAYER_X, SIZE_PLAYER_Y, SIZE_PLAYER_X, -SIZE_PLAYER_Y);
			mAttackRange.SetColor(1.0f, 1.0f, 0.0f, 1.0f);
			if (RIGHT_PTT)mAttackRange.position = CVector2(mPos.x + 1, mPos.y);
			if (LEFT_PTT)mAttackRange.position = CVector2(mPos.x - 1, mPos.y);
			mAttackAxis = 4.0f;
		}
		if (mAnimeFrame == FRAME_LIMIT - 1){
			mEnabledAttack = false;//攻撃終了
		}
		if (rulerR > 2 || rulerL > 2){
			actionflag = false;
			motion = 1;
		}

		break;
	}
	switch (direction)
	{
	case 0:	//右向き
		break;
	case 1:	//左向き
		break;
	}
	LimitDisp(SIZE_BOSS_X, SIZE_BOSS_Y);	//当たり判定
	AnimeScene();
	if (mHitPoint == 0)mKillFlag = true;

	mShadow.position = CVector2(mPos.x, mAxis);

	mRect.position = mPos;
}

void CBoss::Render(){
	mShadow.Render();
	mRect.Render();
}
