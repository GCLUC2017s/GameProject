#include "CBoss.h"
#include "../MyNumber/CMyNumber.h"
#include "../Key/CKey.h" //挙動テスト時の操作用
/*


CKeyを使っている条件文は今後別の処理になります。

高橋弘樹

*/

#define SIZE_BOSS_Y 3  //エネミー00のサイズ_Y
#define SIZE_BOSS_X 3 //エネミー00のサイズ_X

#define HITPOINT_ENEMY00 5					//エネミー00の体力
#define FIRST_R_NO_PL 1						//初めのレンダーのポイント
#define FIRST_U_NO_PL 1						//初めのアップデートのポイント
#define SIZE_TEX_ENEMY00_STAY_X 800			//エネミーの待ち姿テクスチャサイズ X
#define SIZE_TEX_ENEMY00_STAY_Y 800			//エネミーの待ち姿テクスチャサイズ Y
#define SIZE_TEX_ENEMY00_WALK_X 800			//エネミーの歩くテクスチャサイズ Y
#define SIZE_TEX_ENEMY00_WALK_Y 800			//エネミーの歩く姿テクスチャサイズ Y
#define SIZE_SHADOW							//影の表示
#define SLOW_DOWN 0.001						//移動の減速スピード
#define WALK_SPEED 0.04						//歩くスピード
#define WALK_X 2							//歩くベクトルX
#define WALK_Y 1							//歩くベクトルY
#include"../Load/CLoadBoss.h"


void CBoss::SetPos(){
	mPos = Boss_first_pos;
	mAxis = mPos.y;
};

void CBoss::Init(){
	SetPos();

	

	/*テクスチャを張る*/
	mBoss.SetUv(CLoadBoss::GetInstance()->mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

}

CBoss::~CBoss(){
	//特に何もしない
}

//エネミー00描画
CBoss::CBoss() : mVelocity(0), mFlameCount(0){


	mPriorityR = E_BOSS;			//Renderのナンバー 
	mPriorityU = E_BOSS;			//Updateのナンバー
	mHitPoint = HITPOINT_ENEMY00;		//ＨＰ
	mMyNumber = E_BOSS;

	//四角形の頂点設定
	mBoss.SetVertex(SIZE_BOSS_X, SIZE_BOSS_Y, -SIZE_BOSS_X, -SIZE_BOSS_Y);
	mShadow.SetVertex(-SIZE_BOSS_X, SIZE_BOSS_Y, SIZE_BOSS_X, -SIZE_BOSS_Y);
	//四角形の色を設定
	mBoss.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

}

/*アニメのフレームを動かすメソッド*/ //エネミーによって違う場合があるので画像データ用参照
void CBoss::AnimeFrame(){

	mFlameCount += 1;
	if (mFlameCount % 5 == 0){ //フレーム数=mStay_tex[5]->load(".../.tga");
		mAnime += 1;
	}
	if (mAnime >= FRAME_LIMIT || mSaveAnime != eAnime){
		mAnime = 0;
	}
	mSaveAnime = eAnime;

}


void CBoss::Update(){

	AnimeFrame();
	assert(mAnime <= FRAME_LIMIT); //フレーム数が七を超えるとダメ
	mPriorityR = -mAxis;

	//四角形の位置を設定
	mBoss.position = mPos;


	// 右移動
	if (CKey::push('D')) {
		eAnime = E_WALK_R;
		direction = 0;

		mVelocity = WALK_SPEED;

		mForward = CVector2(WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}
	else{
		if (mSaveAnime == E_WALK_R){//待機中 直前が左の歩きでなければ
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


	//左移動
	if (CKey::push('A')) {
		direction = 1;

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


	//上移動
	if (CKey::push('W') && mAxis < character_limit_top - SIZE_BOSS_Y) { //軸が上限に達していないとき
		Walk();
		if (direction == 0){
			eAnime = E_WALK_R;
		}
		else if (direction == 1){
			eAnime = E_WALK_L;

		}
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;

	}

	//下移動
	if (CKey::push('S') && mAxis > character_limit_bottom + SIZE_BOSS_Y) {//軸が上限に達していないとき
		Walk();
		if (direction==0){
			eAnime = E_WALK_R;
		}else if(direction==1){
			eAnime = E_WALK_L;

		}
		
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, -WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;
	}

	//攻撃
	if (CKey::push('X') && direction == 0) {

		eAnime = E_ATTACK_R;
	}
	else if (CKey::push('X') && direction == 1){
		eAnime = E_ATTACK_L;
	}
	


	//強攻撃
	if (CKey::push('C') && direction == 0) {
		
			eAnime = E_HATTACK_R;
		}
	else if (CKey::push('C') && direction == 1){
			eAnime = E_HATTACK_L;
		}




		//死亡
	if (CKey::push('Z') && direction == 0) {

		eAnime = E_DIE_R;
	}
	else if (CKey::push('Z') && direction == 1){
				eAnime = E_DIE_L;
		}

		switch (direction)
		{
		case 0:			//右
			break;
		case 1:			//左
			break;
		}


		/*あたり判定*/
		if (mPos.y > character_limit_top - SIZE_BOSS_Y){  //マップ外に出ると元の位置に戻す(軸)
			mPos.y = character_limit_top - SIZE_BOSS_Y;
			mAxis = mPos.y; //軸をもとに戻す
		}
		if (mPos.y < character_limit_bottom + SIZE_BOSS_Y){  //マップ外に出ると元の位置に戻す(軸)
			mPos.y = character_limit_bottom + SIZE_BOSS_Y;
			mAxis = mPos.y; //軸をもとに戻す
		}

		if (mPos.x >= character_limit_right - SIZE_BOSS_X || mPos.x <= character_limit_left + SIZE_BOSS_X){ //マップ外に出ると元の位置に戻す(X)
			mPos.x = mBoss.position.x;
		}
		/*あたり判定終了*/


		/*アニメーションのステータス*/
		switch (eAnime)
		{
			/*待機中*/
		case E_STAY_L:
			mBoss.SetUv(CLoadBoss::GetInstance()->mStay_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
			break;
		case E_STAY_R:
			mBoss.SetUv(CLoadBoss::GetInstance()->mStay_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
			break;
			/*歩き中*/
		case E_WALK_L:
			mBoss.SetUv(CLoadBoss::GetInstance()->mWalk_tex[mAnime], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
			break;
		case E_WALK_R:
			mBoss.SetUv(CLoadBoss::GetInstance()->mWalk_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
			break;
			/*攻撃*/
		case E_ATTACK_L:
			mBoss.SetUv(CLoadBoss::GetInstance()->mAttack_tex[mAnime], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
			break;
		case E_ATTACK_R:
			mBoss.SetUv(CLoadBoss::GetInstance()->mAttack_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
			break;
			/*強攻撃*/
		case E_HATTACK_L:
			mBoss.SetUv(CLoadBoss::GetInstance()->mHattack_tex[mAnime], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
			break;
		case E_HATTACK_R:
			mBoss.SetUv(CLoadBoss::GetInstance()->mHattack_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
			break;
			/*死亡*/
		case E_DIE_L:
			mBoss.SetUv(CLoadBoss::GetInstance()->mDie_tex[mAnime], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
			break;
		case E_DIE_R:
			mBoss.SetUv(CLoadBoss::GetInstance()->mDie_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
			break;

		}
		mBoss.position = mPos;
	}

void CBoss::Render(){
	mBoss.Render();
}
