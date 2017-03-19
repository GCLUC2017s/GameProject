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

#define HITPOINT_ENEMY00 6					//エネミー01の体力
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
#define ANIME_TIME_BASE						6
#define ANIME_TIME_ATTACK					6	

#define ENEMY01_FLAY "../CG\\enemy01\\fly\\"
#define ENEMY01_STAY "../CG\\enemy01\\stay\\"
#define ENEMY01_ATTACK "../CG\\enemy01\\attack\\"
#define ENEMY01_DIE "../CG\\enemy01\\die\\"


inline void InitRand(){
	srand((unsigned int)time(NULL));
}


void CEnemy01::SetPos(){
	mPos = Enemy01_first_pos;
	mAxis = mPos.y;
};

void CEnemy01::Init(){
	SetPos();

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
	mHitPoint = HITPOINT_ENEMY00;		//ＨＰ
	mMyNumber = E_ENEMY01;

	//四角形の頂点設定
	mRect.SetVertex(SIZE_ENEMY00_X, SIZE_ENEMY00_Y, -SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
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
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mDie_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_DIE_L:
		AnimeFrame(true, ANIME_TIME_BASE);
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

	mPriorityR = -mAxis;
	rulerR = mTargetP.x - mPos.x;	//プレイヤーとの距離を出す
	rulerL = mPos.x - mTargetP.x;

	if (rulerL<0){				//絶対値にする
		rulerL = rulerL * -1;
	}
	if (rulerR<0){
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
		Fly();

		if (ATTACK_PTT){//攻撃モーションに変更
			actionflag = false;
			motion = 2;
		}

		break;
	case 2://攻撃範囲内に入った時

		if (!actionflag){
			pattern = rand() % 4; //0~2の中でランダムでパターンを選択する。
		}
		if (pattern == 0){
			motion = 6;
		}
		else if (pattern == 1){
			actionflag = true;
			motion = 5;
		}
		else if (pattern == 2){

			motion = 5;
		}
		else if (pattern == 3){

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
	case 5:		//キャラの後ろに行こうとする


		if (direction == 1) {
			direction = 1;
			mVelocity = -WALK_SPEED * 3;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;
			if (rulerR >5){
				motion = 2;
			}

		}
		else if (direction == 0){
			direction = 0;
			mVelocity = WALK_SPEED * 3;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;

			if (rulerL >5){
				motion = 2;
			}
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
	if (mHitPoint == 0)mKillFlag = true;

	mRect.position = mPos;
	mShadow.position = CVector2(mPos.x, mAxis);


}







void CEnemy01::Render(){
	mShadow.Render();
	mRect.Render();
}
