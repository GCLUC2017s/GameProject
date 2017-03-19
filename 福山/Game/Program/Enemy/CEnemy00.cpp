#include "CEnemy00.h"
#include "../MyNumber/CMyNumber.h"
#include "../CGame/CGame.h"
#include "stdio.h"
#include <cstdlib>
#include<time.h>
#include<iostream>
#include "CEnemybasetest.h"
#include "../Load/CLoadEnemy00.h"

#define SIZE_ENEMY00_Y 1  //エネミー00のサイズ_Y
#define SIZE_ENEMY00_X 1 //エネミー00のサイズ_X
/*

高橋弘樹

*/
#define HITPOINT_ENEMY00 5					//エネミー00の体力
#define FIRST_R_NO_ENEMY00 1						//初めのレンダーのポイント
#define FIRST_U_NO_ENEMY00 1						//初めのアップデートのポイント
#define SIZE_TEX_ENEMY00_STAY_X 80			//エネミーの待ち姿テクスチャサイズ X
#define SIZE_TEX_ENEMY00_STAY_Y 80			//エネミーの待ち姿テクスチャサイズ Y
#define SIZE_TEX_ENEMY00_WALK_X 80			//エネミーの歩くテクスチャサイズ Y
#define SIZE_TEX_ENEMY00_WALK_Y 80			//エネミーの歩く姿テクスチャサイズ Y
#define SIZE_SHADOW							//影の表示
#define PATTERN_R 1							//PATTERNの右
#define PATTERN_L 2							//PATTERNの左

#define ANIME_TIME_BASE						6								//アニメのループ時間 継続的なもの
#define ANIME_TIME_ATTACK					6								//アニメのループ時間 攻撃のもの

#define WALK_SPEED 0.02f				//歩くスピード
#define WALK_X 2						//歩くベクトルX
#define WALK_Y 1						//歩くベクトルY

#define ENEMY00_STAY "../CG\\enemy00\\enemy00_stay\\"
#define ENEMY00_WALK "../CG\\enemy00\\enemy00_walk\\"
#define ENEMY00_ATTACK "../CG\\enemy00\\enemy00_attack\\"
#define ENEMY00_DIE "../CG\\enemy00\\enemy00_dai\\"
#include "../Load/CLoadPlayer.h"

inline void InitRand(){
	srand((unsigned int)time(NULL));
}

void CEnemy00::SetPos(){
	mPos = Enemy00_first_pos;
	mAxis = mPos.y;
};


void CEnemy00::Init(){
	SetPos();
	
	/*テクスチャを張る*/
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mRect.SetUv(CLoadEnemy00::GetInstance()->mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);


}



//エネミー00描画
CEnemy00::CEnemy00() : mVelocity(0), mFlameCount(0), actionflag(false),motion(0),direction(1){


	mPriorityR = E_ENEMY00;			//Renderのナンバー 
	mPriorityU = E_ENEMY00;			//Updateのナンバー
	mHitPoint = HITPOINT_ENEMY00;		//ＨＰ
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
	case E_STAY_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mStay_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_STAY_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mStay_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*歩き中*/
	case E_WALK_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mWalk_tex[mAnimeFrame], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	case E_WALK_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mWalk_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
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
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mDie_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_DIE_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mDie_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;

	}
}

void CEnemy00::Walk(){

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

void CEnemy00::Update(){
	assert(mAnimeFrame <= FLAME_LIMIT); //フレーム数が七を超えるとダメ
	
	mRect.position = mPos;
	//mTargetPをplayerにする
	InitRand();

	mTargetP = CGame::mGetPlayerPos();
	float getAxis = CGame::GetPlayerAxis();

	rulerR = mTargetP.x - mPos.x;	//プレイヤーとの距離を出す
	rulerL = mPos.x- mTargetP.x;

	if (rulerL<0){				//絶対値にする
		rulerL = rulerL * -1;
	}
	if (rulerR<0){
		rulerR = rulerR * -1;
	}

	mPriorityR = -mAxis;

	/*
	
	//（ターゲットが右にいる場合）
	if (RIGHT_PTT) {
		direction = 0;
		motion = 1;
		eAnime = E_WALK_R;
		mVelocity = WALK_SPEED;
		mForward = CVector2(WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}
	else if (mHitPoint == 0){
		if (mSaveAnime == E_WALK_R){ //待機中 直前が右の歩きでなければ
			eAnime = E_STAY_R;
		}
		if (mVelocity > 0){
			mVelocity -= SLOW_DOWN;
			mPos += mForward * mVelocity;
		}
		else{
			mVelocity = 0;
		}
	}

	//（ターゲットが左にいる場合）
	if (LEFT_PTT) {
		direction = 1;
		motion = 1;
		eAnime = E_WALK_L;
		mVelocity = WALK_SPEED;

		mForward = CVector2(-WALK_X, 0.0f);
		mPos += mForward * mVelocity;

	}
	else{ //移動していないとき
		if (mSaveAnime == E_WALK_L){ //待機中 直前が右の歩きでなければ
			eAnime = E_STAY_L;
		}
		if (mVelocity > 0){
			mVelocity -= SLOW_DOWN;
			mPos += mForward * mVelocity;
		}
		else{
			mVelocity = 0;
		}

	}

	
	//（ターゲットが上にいる場合）
	if (DOWN_PTT) { //軸が上限に達していないとき
		Walk();
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;

	}
	
	//（ターゲットが下にいる場合）
	if (UP_PTT) {//軸が上限に達していないとき
		Walk();
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, -WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;
	}
	*/


	if (mHitPoint <= 0){
		motion = 2;		//体力が０ならDIEする
	}


	switch (motion)
	{
	case 0://待機
		if (direction==0){	//右向き
			mStatus = E_STAY_R;
		}
		else if (direction=1){	//左向き

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

		break;
	case 2://攻撃範囲内に入った時
		
		if (!actionflag){
			pattern = rand() % 3; //0~2の中でランダムでパターンを選択する。
		}
			if (pattern == 0){
				motion = 6;
			}
			else if (pattern == 1){
				actionflag = true;
				motion = 4;
			}
			else if (pattern == 2){
	
				motion = 6;
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
			mVelocity = WALK_SPEED*3;
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
	case 5:		//下に逃げる
		
			mVelocity = WALK_SPEED;
			mForward = CVector2(0.0f, -WALK_Y);
			mPos += mForward * mVelocity;
			mAxis += mForward.y * mVelocity;
		
		if (mAxis == character_limit_bottom){

			motion = 1;
			actionflag = false;
		}


		break;

	case 6:		//攻撃中

		if (RIGHT_PTT && !mEnabledAttack) {
			mEnabledAttack = true;
				mStatus = E_ATTACK_R;
		}
		else if (LEFT_PTT && !mEnabledAttack){
			mEnabledAttack = true;
					mStatus = E_ATTACK_L;			
			}


		/*範囲*/
		if (mEnabledAttack){
			mAttackRange.SetVertex(-SIZE_PLAYER_X, SIZE_PLAYER_Y, SIZE_PLAYER_X, -SIZE_PLAYER_Y);
			mAttackRange.SetColor(1.0f, 1.0f, 0.0f, 1.0f);
			if (RIGHT_PTT)mAttackRange.position = CVector2(mPos.x + 1, mPos.y);
			if (LEFT_PTT)mAttackRange.position = CVector2(mPos.x - 1, mPos.y);
			mAttackAxis = 3.0f;
		}

		if (mAnimeFrame == FRAME_LIMIT - 1){
			mEnabledAttack = false;//攻撃終了
		}

		if (rulerR > 2 || rulerL >2){
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


	//printf("%d\n", motion);


	LimitDisp(SIZE_ENEMY00_X, SIZE_ENEMY00_Y);
	AnimeScene();
	if(mHitPoint == 0)mKillFlag = true;

	mRect.position = mPos;

	mShadow.position = CVector2(mPos.x, mAxis);


}
void CEnemy00::Render(){
	mShadow.Render();
	mRect.Render();
}
