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
#define SIZE_TEX_ENEMY00_STAY_X 800			//エネミーの待ち姿テクスチャサイズ X
#define SIZE_TEX_ENEMY00_STAY_Y 800		//エネミーの待ち姿テクスチャサイズ Y
#define SIZE_TEX_ENEMY00_WALK_X 800			//エネミーの歩くテクスチャサイズ Y
#define SIZE_TEX_ENEMY00_WALK_Y 800			//エネミーの歩く姿テクスチャサイズ Y
#define SIZE_SHADOW							//影の表示
#define WALK_SPEED 0.07		//テスト用にいじってる				//飛行スピード
#define WALK_X 2							//飛行ベクトルX
#define WALK_Y 1							//飛行ベクトルY
#define ANIME_TIME_BASE						EM_ATTCK
#define ANIME_TIME_ATTACK					EM_ATTCK	

#define ENEMY01_FLAY "../CG\\enemy01\\fly\\"
#define ENEMY01_STAY "../CG\\enemy01\\stay\\"
#define ENEMY01_ATTACK "../CG\\enemy01\\attack\\"
#define ENEMY01_DIE "../CG\\enemy01\\die\\"
#define AT_RANGE01		mForward.x, 100, 100,10, mPos	//攻撃範囲A

inline void InitRand(){
	srand((unsigned int)time(NULL));
}


void CEnemy01::Init(){
	RandPos(SIZE_ENEMY01_X, SIZE_ENEMY01_Y, &mPos);
	/*テクスチャを張る*/
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mRect.SetUv(CLoadEnemy01::GetInstance()->mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

}



CEnemy01::~CEnemy01(){
}

//エネミー01描画
CEnemy01::CEnemy01() : mVelocity(0), mFlameCount(0), actionflag(false), motion(0), direction(1){
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
		AnimeFrame(true, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mAttack_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_ATTACK_L:
		AnimeFrame(true, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mAttack_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*死亡*/
	case E_DIE_R:
		AnimeFrame(false, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mDie_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_DIE_L:
		AnimeFrame(false, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mDie_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;

	}
}

void CEnemy01::Fly(){

	//（ターゲットが右にいる場合）
	if (RIGHT_PTT) {
		direction = 0;
		mStatus = E_FLY_R;
		mVelocity = WALK_SPEED;
		mForward = CVector2(WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}

	//（ターゲットが左にいる場合）
	if (LEFT_PTT) {
		direction = 1;
		mStatus = E_FLY_L;
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
void CEnemy01::Update(){
	assert(mAnimeFrame <= FLAME_LIMIT); //フレーム数が七を超えるとダメ

	mRect.position = mPos;
	InitRand();

	mTargetP = CGame::mGetPlayerPos();

	rulerR = mTargetP.x - mPos.x;	//プレイヤーとの距離を出す
	rulerL = mPos.x - mTargetP.x;

	if (rulerL<0){				//絶対値にする
		rulerL = rulerL * -1;
	}
	if (rulerR<0){
		rulerR = rulerR * -1;
	}

	if (mHitPoint <= 0){
		motion = EM_DIE;		//体力が０ならDIEする
	}

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
		Fly();

		if (ATTACK_PTT){//攻撃モーションに変更
			actionflag = false;
			motion = EM_RANGE;
		}

		break;
	case EM_RANGE://攻撃範囲内に入った時

		if (!actionflag){
			pattern = rand() % EM_BACK_X; //0~2の中でランダムでパターンを選択する。
		}
		if (pattern == 0){
			motion = EM_ATTCK;
		}
		else if (pattern == 1){
			actionflag = true;
			motion = EM_BACK_Y;
		}
		else if (pattern == 2){

			motion = EM_BACK_Y;
		}
		else if (pattern == EM_DIE){

			motion = EM_ATTCK;
		}

		if (NO_ATTACK_PTT){
			actionflag = false;
			motion = EM_STAY;
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
			mVelocity = WALK_SPEED * EM_DIE;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;

		}
		else if (direction == 0){
			direction = 0;
			mVelocity = -WALK_SPEED * EM_DIE;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;
		}

		if (ENEMY_ESCAPE){	//一定距離離れると再度こちらに向かってくる
			actionflag = false; //actionflagをfalseにする。
			motion = EM_WALK;
		}

		break;
	case EM_BACK_Y:		//キャラの後ろに行こうとする


		if (direction == 1) {
			direction = 1;
			mVelocity = -WALK_SPEED * EM_DIE;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;
			if (rulerR >EM_BACK_Y){
				motion = EM_RANGE;
			}

		}
		else if (direction == 0){
			direction = 0;
			mVelocity = WALK_SPEED * EM_DIE;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;

			if (rulerL >EM_BACK_Y){
				motion = EM_RANGE;
			}
		}




		break;

	case EM_ATTCK:		//攻撃中

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
		if (mAnimeFrame == int(FRAME_LIMIT /2)){ //攻撃が中間に来たときのみあたり判定のフラグを立てる
			mEnabledAttack = true;//攻撃終了
		}
		else{
			mEnabledAttack = false;
		}
		/*攻撃範囲に距離を詰める*/
		if (rulerR > 2 || rulerL >2){
			actionflag = false;
			motion = EM_WALK;
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
