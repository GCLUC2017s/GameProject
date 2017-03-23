#include "CEnemy01.h"
#include "../MyNumber/CMyNumber.h"
#include "stdio.h"
#include <cstdlib>
#include<time.h>
#include<iostream>
#include "CEnemybasetest.h"
#include "../CGame/CGame.h"
#include "../Load/CLoadEnemy01.h"
#include "../Load/CLoadPlayer.h"
/*
ヒコースケーチ
*/

/*
CKeyを使っている条件文は今後別の処理になります。

高橋弘樹
*/

#define SIZE_ENEMY00_Y 1  //エネミー01のサイズ_Y
#define SIZE_ENEMY00_X 1 //エネミー01のサイズ_X

#define FIRST_R_NO_PL 1						//初めのレンダーのポイント
#define FIRST_U_NO_PL 1						//初めのアップデートのポイント
#define SIZE_TEX_ENEMY00_STAY_X 160			//エネミーの待ち姿テクスチャサイズ X
#define SIZE_TEX_ENEMY00_STAY_Y 160		//エネミーの待ち姿テクスチャサイズ Y
#define SIZE_TEX_ENEMY00_WALK_X 160			//エネミーの歩くテクスチャサイズ Y
#define SIZE_TEX_ENEMY00_WALK_Y 160			//エネミーの歩く姿テクスチャサイズ Y
#define SIZE_SHADOW							//影の表示
#define WALK_SPEED 0.055		//テスト用にいじってる				//飛行スピード
#define WALK_X 2							//飛行ベクトルX
#define WALK_Y 1							//飛行ベクトルY
#define ANIME_TIME_BASE						6
#define ANIME_TIME_ATTACK					6	

#define ENEMY01_FLAY "../CG\\enemy01\\fly\\"
#define ENEMY01_STAY "../CG\\enemy01\\stay\\"
#define ENEMY01_ATTACK "../CG\\enemy01\\attack\\"
#define ENEMY01_DIE "../CG\\enemy01\\die\\"
#define AT_RANGE01		mForward.x, SIZE_ENEMY01_X, SIZE_ENEMY01_X,10, mPos	//攻撃範囲A



void CEnemy01::Init(){
	RandPos(SIZE_ENEMY01_X, SIZE_ENEMY01_Y, &mPos,-DISP_X,DISP_X*10);
	/*テクスチャを張る*/
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mRect.SetUv(CLoadEnemy01::GetInstance()->mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

}



CEnemy01::~CEnemy01(){
}

//エネミー01描画
CEnemy01::CEnemy01() : mVelocity(0), mFrameCount(0), actionflag(false), motion(EM_STAY), direction(E_LEFT){
	mPriorityR = E_ENEMY01;			//Renderのナンバー 
	mPriorityU = E_ENEMY01;			//Updateのナンバー
	mHitPoint = ENE_HP_X;		//ＨＰ
	mMyNumber = E_ENEMY01;

	//四角形の頂点設定
	mRect.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	mShadow.SetVertex(-SIZE_SHADOW_X, SIZE_SHADOW_Y, SIZE_SHADOW_X, -SIZE_SHADOW_Y);
	//四角形の色を設定
	mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

}


void CEnemy01::AnimeScene(){

	/*アニメーションのステータス*/
	switch (mStatus)
	{
		/*待機中*/
	case E_STAY_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mStay_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_STAY_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mStay_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*歩き中*/
	case E_FLY_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mFly_tex[mAnimeFrame], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	case E_FLY_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mFly_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
		break;
		/*攻撃中*/
	case E_ATTACK_R:
		AnimeFrame(true, ANIME_TIME_ATTACK,FRAME_LIMIT9);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mAttack_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_ATTACK_L:
		AnimeFrame(true, ANIME_TIME_ATTACK,FRAME_LIMIT9);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mAttack_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*死亡*/
	case E_DIE_R:
		AnimeFrame(false, ANIME_TIME_BASE,FRAME_LIMIT11);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mDie_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_DIE_L:
		AnimeFrame(false, ANIME_TIME_BASE, FRAME_LIMIT11);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mDie_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;

	}
}

void CEnemy01::Fly(){

	//（ターゲットが右にいる場合）
	if (RIGHT_PTT) {
		direction = E_RIGHT;
		mStatus = E_FLY_R;
		mVelocity = WALK_SPEED;
		mForward = CVector2(WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}

	//（ターゲットが左にいる場合）
	if (LEFT_PTT) {
		direction = E_LEFT;
		mStatus = E_FLY_L;
		mVelocity = WALK_SPEED;
		mForward = CVector2(-WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}


	//（ターゲットが上にいる場合）
	if (getAxis > mAxis) {
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;

	}

	//（ターゲットが下にいる場合）
	if (getAxis< mAxis) {
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, -WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;
	}


}

void CEnemy01::Motion(){

	switch (motion)
	{
	case EM_STAY://待機
		if (direction == E_RIGHT){	//右向き
			mStatus = E_STAY_R;
		}
		else if (direction = E_LEFT){	//左向き

			mStatus = E_STAY_L;
		}

		if (ENEMY_VISI)		//視界内にとらえたら追ってくる
		{
			motion = EM_WALK;
		}

		break;
	case EM_WALK://歩き	
		Fly();

		if (ATTACK_PTTX&&ATTACK_PTTY){//攻撃モーションに変更
			actionflag = false;
			motion = EM_RANGE;
		}

		break;
	case EM_RANGE://攻撃範囲内に入った時

		if (!actionflag){
			pattern = rand() % 4; //0~3の中でランダムでパターンを選択する。
		}
		if (pattern == 0){
			motion = EM_ATTACK;
		}
		else if (pattern == 1){
			actionflag = true;
			motion = EM_BACK_UP;
		}
		else if (pattern == 2){

			motion = EM_BACK_UP;
		}
		else if (pattern == 3){

			motion = EM_BACK_Y;
		}
		
		break;

	case EM_DIE://死亡
		if (direction == E_RIGHT) {
			mStatus = E_DIE_R;
		}
		else if (direction == E_LEFT){
			mStatus = E_DIE_L;
		}
		break;

	case EM_BACK_X://後ろに逃げる。

		if (direction == E_LEFT) {
			direction = E_LEFT;
			mVelocity = WALK_SPEED * 2;	//３倍速で逃げる
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;

		}
		else if (direction == E_RIGHT){
			direction = E_RIGHT;
			mVelocity = -WALK_SPEED * 2;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;
		}

		if (ENEMY_ESCAPE){	//一定距離離れると再度こちらに向かってくる
			actionflag = false; //actionflagをfalseにする。
			motion = EM_WALK;
		}

		break;
	case EM_BACK_UP:		//キャラの後ろに行こうとする

	
		if (direction == E_LEFT) {
			direction = E_LEFT;
			mVelocity = -WALK_SPEED * 2;	//2倍速で回り込む
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;
			if (rulerR >5){
				motion = EM_RANGE;
			}

		}
		else if (direction == E_RIGHT){
			direction = E_RIGHT;
			mVelocity = WALK_SPEED * 2;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;

			if (rulerL >5){
				motion = EM_RANGE;
			}
		}
		if (ENEMY_ESCAPE){	//一定距離離れると再度こちらに向かってくる
			actionflag = false; //actionflagをfalseにする。
			motion = EM_WALK;
		}
		
		break;

	case EM_BACK_Y:	//縦軸をずらそうとする

			mVelocity = WALK_SPEED * 2;	//二倍の速度で下に降りようとする
			mForward = CVector2(0.0f, -WALK_Y);
			mPos += mForward * mVelocity;
			mAxis += mForward.y * mVelocity;
			if (mAxis <= character_limit_bottom+0.7f){
				motion = EM_ATTACK;
				actionflag = false;
				break;
			}
		if (NO_ATTACK_PTTX&&NO_ATTACK_PTTY){
			actionflag = false;
			motion = EM_WALK;
		}

		break;
	case EM_ATTACK:		//攻撃中
		attacktime += ENEMY01_INTERVAL / FPS;
		if (RIGHT_PTT) {
			mEnabledAttack = true;
			mStatus = E_ATTACK_R;
		}
		else{
			mEnabledAttack = true;
			mStatus = E_ATTACK_L;
		}

		/*範囲*/
		Attack(AT_RANGE01);

			mEnabledAttack = true;
		

		/*攻撃範囲に距離を詰める*/
		if (NO_ATTACK_PTTX||NO_ATTACK_PTTY||attacktime>=ENEMY01_INTERVAL){
			attacktime = 0;
			mEnabledAttack = false;
			actionflag = false;
			motion = EM_WALK;
		}
		break;
	}
}

void CEnemy01::Update(){

	mRect.position = mPos;
	mTargetP = CGame::mGetPlayerPos();
	getAxis = CGame::GetPlayerAxis();

	rulerR = mTargetP.x - mPos.x;	//プレイヤーとの距離を出す		//このあたりの処理は全エネミー共通なのでどこかに移したい。
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

	mAttackRange.position = mPos;
	
	AlertHPRect(&mRect, mHitPoint);	//アラートメソッド(HP変化によるもの)
	/*軸の設定*/
	mAxis = mPos.y - SIZE_ENEMY01_Y;
	/*範囲外調整*/
	LimitDisp(SIZE_ENEMY01_X, SIZE_ENEMY01_Y);
	/*レンダー順番設定*/
	mPriorityR = -mAxis;
	AnimeScene();
	mRect.position = mPos;
	mShadow.position = CVector2(mPos.x, mAxis);


}







void CEnemy01::Render(){
	mShadow.Render();
	mRect.Render();
}
