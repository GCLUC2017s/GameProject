#include "CEnemy00.h"
#include "../MyNumber/CMyNumber.h"
#include "../Key/CKey.h" //挙動テスト時の操作用
#include "../CGame/CGame.h"
#include "stdio.h"
#include "../Enemy/CEnemyPattern.h"
#include <cstdlib>
#define SIZE_ENEMY00_Y 1  //エネミー00のサイズ_Y
#define SIZE_ENEMY00_X 1 //エネミー00のサイズ_X
/*

エネミーがプレイヤーの場所に行くように設定

今後挙動の追加


高橋弘樹
*/
#define HITPOINT_ENEMY00 5					//エネミー00の体力
#define FIRST_R_NO_PL 1						//初めのレンダーのポイント
#define FIRST_U_NO_PL 1						//初めのアップデートのポイント
#define SIZE_TEX_ENEMY00_STAY_X 80			//エネミーの待ち姿テクスチャサイズ X
#define SIZE_TEX_ENEMY00_STAY_Y 80			//エネミーの待ち姿テクスチャサイズ Y
#define SIZE_TEX_ENEMY00_WALK_X 80			//エネミーの歩くテクスチャサイズ Y
#define SIZE_TEX_ENEMY00_WALK_Y 80			//エネミーの歩く姿テクスチャサイズ Y
#define SIZE_SHADOW							//影の表示
#define SLOW_DOWN 0.001f						//移動の減速スピード
#define PATTERN_R 1							//PATTERNの右
#define PATTERN_L 2							//PATTERNの左

#define WALK_SPEED 0.02f				//歩くスピード
#define WALK_X 2						//歩くベクトルX
#define WALK_Y 1						//歩くベクトルY

#define ENEMY00_STAY "../CG\\enemy00\\enemy00_stay\\"
#define ENEMY00_WALK "../CG\\enemy00\\enemy00_walk\\"
#define ENEMY00_ATTACK "../CG\\enemy00\\enemy00_attack\\"
#define ENEMY00_DIE "../CG\\enemy00\\enemy00_dai\\"



void CEnemy00::Init(){
	SetPos();
	/*テクスチャ読み込み*/
	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = new CTexture();		//テクスチャクラスのインスタンス作成
		mWalk_tex[i] = new CTexture();		//テクスチャクラスのインスタンス作成
		mAttack_tex[i] = new CTexture();		//テクスチャクラスのインスタンス作成
		mDie_tex[i] = new CTexture();
	}

	/*テクスチャファイル読み込み*/
	mStay_tex[0]->load(ENEMY00_STAY"enemy00_stay_00.tga");
	mStay_tex[1]->load(ENEMY00_STAY"enemy00_stay_01.tga");
	mStay_tex[2]->load(ENEMY00_STAY"enemy00_stay_02.tga");
	mStay_tex[3]->load(ENEMY00_STAY"enemy00_stay_03.tga");
	mStay_tex[4]->load(ENEMY00_STAY"enemy00_stay_04.tga");
	mStay_tex[5]->load(ENEMY00_STAY"enemy00_stay_05.tga");
			

	mWalk_tex[0]->load(ENEMY00_WALK"enemy00_walk_00.tga");
	mWalk_tex[1]->load(ENEMY00_WALK"enemy00_walk_01.tga");
	mWalk_tex[2]->load(ENEMY00_WALK"enemy00_walk_02.tga");
	mWalk_tex[3]->load(ENEMY00_WALK"enemy00_walk_03.tga");
	mWalk_tex[4]->load(ENEMY00_WALK"enemy00_walk_04.tga");
	mWalk_tex[5]->load(ENEMY00_WALK"enemy00_walk_05.tga");

	mAttack_tex[0]->load(ENEMY00_ATTACK"enemy00_attack_00.tga");
	mAttack_tex[1]->load(ENEMY00_ATTACK"enemy00_attack_01.tga");
	mAttack_tex[2]->load(ENEMY00_ATTACK"enemy00_attack_02.tga");
	mAttack_tex[3]->load(ENEMY00_ATTACK"enemy00_attack_03.tga");
	mAttack_tex[4]->load(ENEMY00_ATTACK"enemy00_attack_04.tga");
	mAttack_tex[5]->load(ENEMY00_ATTACK"enemy00_attack_05.tga");

	mDie_tex[0]->load(ENEMY00_DIE"enemy00_dai_00.tga");
	mDie_tex[1]->load(ENEMY00_DIE"enemy00_dai_01.tga");
	mDie_tex[2]->load(ENEMY00_DIE"enemy00_dai_02.tga");
	mDie_tex[3]->load(ENEMY00_DIE"enemy00_dai_03.tga");
	mDie_tex[4]->load(ENEMY00_DIE"enemy00_dai_04.tga");
	mDie_tex[5]->load(ENEMY00_DIE"enemy00_dai_05.tga");



	/*テクスチャを張る*/
	mRect.SetUv(mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

	motion = 0;

}



//攻撃時にいかなる場合でも右を向いてしまう。

//エネミー00描画
CEnemy00::CEnemy00() : mVelocity(0), mFlameCount(0), mAnime(E_STAY_L){


	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = 0;
	}

	mPriorityR = FIRST_R_NO_PL;			//Renderのナンバー 
	mPriorityU = FIRST_U_NO_PL;			//Updateのナンバー
	mHitPoint = HITPOINT_ENEMY00;		//ＨＰ
	mMyNumber = E_ENEMY00;

	//四角形の頂点設定
	mRect.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	//四角形の色を設定
	mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

}

void CEnemy00::SetPos(){
	mPos = Enemy00_first_pos;
	mAxis = mPos.y;
};

CEnemy00::~CEnemy00(){
//特に何もしない
}
/*アニメのフレームを動かすメソッド*/ //エネミーによって違う場合があるので画像データ用参照
void CEnemy00::AnimeFlame(){

	mFlameCount += 1;
	if (mFlameCount % 5 == 0){ //フレーム数=mStay_tex[5]->load(".../.tga");
		mAnime += 1;
	}
	if (mAnime >= FLAME_LIMIT || mSaveAnime != eAnime){
		mAnime = 0;
	}
	mSaveAnime = eAnime;

}


void CEnemy00::Update(){

	/*
	ifだらけで汚い
	
	無駄な処理がある可能性
	
	*/

	if (mTargetP.x<0){
		npNum = mTargetP.x * -1; //マイナスの場合は正数にする
	}
	else{
		npNum = mTargetP.x;
	}
	if (mPos.x<0){

		npNum2 = mPos.x * -1;
	}
	else{
		npNum2 = mPos.x;
	}

	rulerR = mTargetP.x - mPos.x;	//プレイヤーとの距離感を出す
	rulerL = mPos.x- mTargetP.x;

	
	if (rulerL<0){

		rulerL = rulerL * -1;
	}
	if (rulerR<0){

		rulerR = rulerR * -1;
	}

	printf("L%f\n", rulerL);

	//mTargetPをplayerにする
	mTargetP = CGame::mGetPlayerPos();

	//四角形の位置を設定
	mRect.position = mPos;

	AnimeFlame();
	assert(mAnime <= FLAME_LIMIT); //フレーム数が七を超えるとダメ
	mPriorityR = -mAxis;


	
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
	


	//攻撃範囲内にターゲットが来た
	if (ATTACK_PTT) {
		motion = 2;
	}


	if (CKey::push('Z')) {
		eAnime = E_ATTACK_R;
	}

	if (mHitPoint == 0){
		motion = 2;
	}



	switch (motion)
	{
	case 0://待機
		

		break;

	case 1://歩き
		//（ターゲットが右にいる場合）
	



		break;
	case 2://攻撃
		if (RIGHT_PTT) {
			eAnime = E_ATTACK_R;
		}
		else if (LEFT_PTT){
			eAnime = E_ATTACK_L;
		}
		if (NO_ATTACK_PTT){
			motion = 1;
		}
		mAttackRange.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
		mAttackRange.SetColor(1.0f, 1.0f, 0.0f, 1.0f);
		mAttackRange.position = CVector2(mPos.x + 1, mPos.y);
		mAttackRange.position = CVector2(mPos.x - 1, mPos.y);
		mAttackAxis = 10.0f;
		mEnabledAttack = true;
		break;

	case 3://死亡
		if (direction == 0) {
			eAnime = E_DIE_R;
		}
		else if (direction == 1){
			eAnime = E_DIE_L;
		}
		break;


	}

	switch (direction)
	{
	case 0:
		break;
	case 1:
		break;
	}

	

	/*あたり判定*/
	if (mPos.y > character_limit_top - SIZE_ENEMY00_Y){  //マップ外に出ると元の位置に戻す(軸)
		mPos.y = character_limit_top - SIZE_ENEMY00_Y;
		mAxis = mPos.y; //軸をもとに戻す
	}
	if (mPos.y < character_limit_bottom + SIZE_ENEMY00_Y){  //マップ外に出ると元の位置に戻す(軸)
		mPos.y = character_limit_bottom + SIZE_ENEMY00_Y;
		mAxis = mPos.y; //軸をもとに戻す
	}

	if (mPos.x >= character_limit_right - SIZE_ENEMY00_X || mPos.x <= character_limit_left + SIZE_ENEMY00_X){ //マップ外に出ると元の位置に戻す(X)
		mPos.x = mRect.position.x;
	}

	/*あたり判定終了*/

	mRect.position = mPos;

	/*アニメーションのステータス*/
	switch (eAnime)
	{
		/*待機中*/
	case E_STAY_R:
		mRect.SetUv(mStay_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_STAY_L:
		mRect.SetUv(mStay_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*歩き中*/
	case E_WALK_R:
		mRect.SetUv(mWalk_tex[mAnime], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	case E_WALK_L:
		mRect.SetUv(mWalk_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
		break;
		/*攻撃中*/
	case E_ATTACK_R:
		mRect.SetUv(mAttack_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_ATTACK_L:
		mRect.SetUv(mAttack_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*死亡*/
	case E_DIE_R:
		mRect.SetUv(mDie_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_DIE_L:
		mRect.SetUv(mDie_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;

	}

	if (mHitPoint == 0)mKillFlag = true;

}
void CEnemy00::Render(){
	mRect.Render();
}
