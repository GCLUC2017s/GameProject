#include "CPlayer.h"
#include "../Key/CKey.h"
#include "../MyNumber/CMyNumber.h"
#define JUMP_FIRST_SPEED 0.2
#define HITPOINT_PLAYER 10
#define FIRST_R_NO_PL 0 //初めのレンダーのポイント
#define FIRST_U_NO_PL 0 //初めのアップデートのポイント
#define SIZE_TEX_PLAYER_STAY_X 800 //プレイヤーの待ち姿テクスチャサイズ X
#define SIZE_TEX_PLAYER_STAY_Y 800 //プレイヤーの待ち姿テクスチャサイズ Y
#define SIZE_TEX_PLAYER_WALK_X 800 //プレイヤーの歩くテクスチャサイズ Y
#define SIZE_TEX_PLAYER_WALK_Y 800 //プレイヤーの歩く姿テクスチャサイズ Y
#define SIZE_TEX_PLAYER_RUN_X  800 //プレイヤーの走る姿テクスチャサイズ Y
#define SIZE_TEX_PLAYER_RUN_Y  800 //プレイヤーの走る姿テクスチャサイズ Y
#define SLOW_DOWN 0.001
#define WALK_SPEED 0.05
#define RUN_SPEED 0.1
#define WALK_X 2 //歩くベクトルX
#define WALK_Y 1 //歩くベクトルY


const float player_limit_left = -MAP_LIMIT_X / 2;  //ＰＬが進める上限(左)
const float player_limit_top =  MAP_LIMIT_Y / 4;			   //ＰＬが進める上限(上)
const float player_limit_right = MAP_LIMIT_X / 2;  //ＰＬが進める上限(右)
const float player_limit_bottom = -MAP_LIMIT_Y / 2;//ＰＬが進める上限(下)

float CPlayer::camera_x; 
float CPlayer::camera_y;


void CPlayer::SetPos(){
	const CVector2 first_pos = CVector2(MAP_LIMIT_X,
		(player_limit_top + player_limit_bottom) / 2); //上限(X)と上限(Y)
	mPos = first_pos;
	mAxis = mPos.y;

}


void CPlayer::Init() {
	camera_x = mPos.x;
	camera_y = mPos.y;
	/*テクスチャ読み込み*/
	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = new CTexture(); //テクスチャクラスのインスタンス作成
		mWalk_tex[i] = new CTexture(); //テクスチャクラスのインスタンス作成
		mRun_tex[i] = new CTexture();
	}

	/*テクスチャファイル読み込み*/
	mStay_tex[0]->load("../CG\\beru\\beru_stay\\beru_stay_00.tga");
	mStay_tex[1]->load("../CG\\beru\\beru_stay\\beru_stay_01.tga");
	mStay_tex[2]->load("../CG\\beru\\beru_stay\\beru_stay_02.tga");
	mStay_tex[3]->load("../CG\\beru\\beru_stay\\beru_stay_03.tga");
	mStay_tex[4]->load("../CG\\beru\\beru_stay\\beru_stay_04.tga");
	mStay_tex[5]->load("../CG\\beru\\beru_stay\\beru_stay_05.tga");



	mWalk_tex[0]->load("../CG\\beru\\beru_walk\\beru_walk_00.tga");
	mWalk_tex[1]->load("../CG\\beru\\beru_walk\\beru_walk_01.tga");
	mWalk_tex[2]->load("../CG\\beru\\beru_walk\\beru_walk_02.tga");
	mWalk_tex[3]->load("../CG\\beru\\beru_walk\\beru_walk_03.tga");
	mWalk_tex[4]->load("../CG\\beru\\beru_walk\\beru_walk_04.tga");
	mWalk_tex[5]->load("../CG\\beru\\beru_walk\\beru_walk_05.tga");

	mRun_tex[0]->load("../CG/beru/beru_run/beru_run_00.tga");
	mRun_tex[1]->load("../CG/beru/beru_run/beru_run_01.tga");
	mRun_tex[2]->load("../CG/beru/beru_run/beru_run_02.tga");
	mRun_tex[3]->load("../CG/beru/beru_run/beru_run_03.tga");
	mRun_tex[4]->load("../CG/beru/beru_run/beru_run_04.tga");
	mRun_tex[5]->load("../CG/beru/beru_run/beru_run_05.tga");




	/*テクスチャを張る*/
	mPlayer.SetUv(mStay_tex[0], 0, 0, SIZE_TEX_PLAYER_STAY_X,SIZE_TEX_PLAYER_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);
}


CPlayer::~CPlayer() {
}



//プレイヤー描画
CPlayer::CPlayer() : mVelocity(0), speed_jump(JUMP_FIRST_SPEED),mFlame_Count(0){

	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = 0;
	}

	mPriorityR = FIRST_R_NO_PL;			//Renderのナンバー
	mPriorityU = FIRST_U_NO_PL;			//Updateのナンバー
	mHitPoint = HITPOINT_PLAYER;		//ＨＰ
	mMyNumber = E_PLAYER;

	//四角形の頂点設定
	mPlayer.SetVertex(-SIZE_PLAYER_X, SIZE_PLAYER_Y, SIZE_PLAYER_X, -SIZE_PLAYER_Y);
	//四角形の色を設定
	mPlayer.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

}


const float gravity = 0.01;//重力


void CPlayer::Jump(){ //ジャンプ処理メソッド

	mPos.y += speed_jump; //飛ぶ処理
	speed_jump -= gravity;//減速処理


	if (mPos.y < mAxis){//現在の軸についたとき
		mPos.y = mAxis; //元いた地面の"Y"に戻す
		speed_jump = JUMP_FIRST_SPEED;
		enabled_jump = false; //終了

	}



}

/*アニメのフレームを動かすメソッド*/
void CPlayer::AnimeFlame(){

	mFlame_Count += 1;
	if (mFlame_Count % 5 == 0){ //フレーム数
		mAnime += 1;
	}
	if (mAnime >= FLAME_LIMIT || save_eAnime != eAnime){
		mAnime = 0;
	}
	save_eAnime = eAnime;

}

void CPlayer::Update() {
	AnimeFlame();
	assert(mAnime <= FLAME_LIMIT); //フレーム数が七を超えるとダメ
	mPriorityR = mAxis;
	camera_x = mPos.x;
	camera_y = mPos.y;

	//四角形の位置を設定
	mPlayer.position = mPos;


	//移動の処理

	//走るボタン
	
	

	// 右移動
	if (CKey::push(VK_RIGHT)) {			
		if (CKey::push(VK_SHIFT)){ //走る時
			eAnime = E_RUN_R;
			mVelocity = RUN_SPEED;
		}
		else{					   //歩く時
			eAnime = E_WALK_R;
			mVelocity = WALK_SPEED;
		}

		mForward = CVector2(WALK_X, 0.0f);
		mPos += mForward * mVelocity;


	}
	else{
		if (save_eAnime == E_WALK_R ||
			save_eAnime == E_RUN_R){//待機中 直前が左の歩きでなければ
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
	if (CKey::push(VK_LEFT)) { 
		if (CKey::push(VK_SHIFT)){ //走る時
			eAnime = E_RUN_L;
			mVelocity = RUN_SPEED;
		}
		else{					   //歩く時
			eAnime = E_WALK_L;
			mVelocity = WALK_SPEED;
		}
		mForward = CVector2(-WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	
	}else{ //移動していないとき
		if (save_eAnime == E_WALK_L ||
			save_eAnime == E_RUN_L){ //待機中 直前が右の歩きでなければ
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

	//ジャンプ
	if (CKey::push(' ') || enabled_jump) {
		if (!enabled_jump){ //ジャンプしていないとき
			enabled_jump = true;
		}
		Jump();
	}


	//上移動
	if (CKey::push(VK_UP) && mAxis < player_limit_top - SIZE_PLAYER_Y) { //軸が上限に達していないとき
		mForward = CVector2(0.0f, WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;

	}

	//下移動
	if (CKey::push(VK_DOWN) && mAxis > player_limit_bottom + SIZE_PLAYER_Y) {//軸が上限に達していないとき

		mForward = CVector2(0.0f, -WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;

	}




	/*あたり判定*/
	if (mPos.y > player_limit_top - SIZE_PLAYER_Y && !enabled_jump){  //マップ外に出ると元の位置に戻す(軸)
		mPos.y = player_limit_top - SIZE_PLAYER_Y;
		mAxis = mPos.y; //軸をもとに戻す
	}
	if (mPos.y < player_limit_bottom + SIZE_PLAYER_Y){  //マップ外に出ると元の位置に戻す(軸)
		mPos.y = player_limit_bottom + SIZE_PLAYER_Y;
		mAxis = mPos.y; //軸をもとに戻す
	}

	if (mPos.x >= player_limit_right - SIZE_PLAYER_X || mPos.x <= player_limit_left + SIZE_PLAYER_X){ //マップ外に出ると元の位置に戻す(X)
		mPos.x = mPlayer.position.x;
	}
	/*あたり判定終了*/


	//スイッチ

	/*向き
	0がデフォルト
	1が上向き
	2が右向き
	3が下向き
	4が左向き
	*/
	
	//四角形の位置を設定
	mPlayer.position = mPos;
	/*アニメーションのステータス*/

	switch (eAnime)
	{
		/*待機中*/
	case E_STAY_L:
		mPlayer.SetUv(mStay_tex[mAnime],SIZE_TEX_PLAYER_STAY_X, 0, 0, SIZE_TEX_PLAYER_STAY_Y);
		break;
	case E_STAY_R:
		mPlayer.SetUv(mStay_tex[mAnime], 0, 0, SIZE_TEX_PLAYER_STAY_X,SIZE_TEX_PLAYER_STAY_Y);
		break;
		/*歩き中*/
	case E_WALK_L:
		mPlayer.SetUv(mWalk_tex[mAnime], SIZE_TEX_PLAYER_WALK_X, 0, 0, SIZE_TEX_PLAYER_WALK_Y);
		break;
	case E_WALK_R:
		mPlayer.SetUv(mWalk_tex[mAnime], 0, 0, SIZE_TEX_PLAYER_WALK_X, SIZE_TEX_PLAYER_WALK_Y);
		break;
		/*走り中*/
	case E_RUN_L:
		mPlayer.SetUv(mRun_tex[mAnime], SIZE_TEX_PLAYER_RUN_X, 0, 0, SIZE_TEX_PLAYER_RUN_Y);
		break;
	case E_RUN_R:
		mPlayer.SetUv(mRun_tex[mAnime], 0, 0, SIZE_TEX_PLAYER_RUN_X, SIZE_TEX_PLAYER_RUN_Y);
		break;
	}

}

void CPlayer::Render(){
	//プレイヤーの描画
	mPlayer.Render();
}
