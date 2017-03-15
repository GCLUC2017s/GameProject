#include "CPlayer.h"
#include "../Key/CKey.h"
#include "../MyNumber/CMyNumber.h"
#define JUMP_FIRST_SPEED 0.2				//ジャンプのジャンプ力
#define HITPOINT_PLAYER 10					//プレイヤーの体力
#define FIRST_R_NO_PL 0						//初めのレンダーのポイント
#define FIRST_U_NO_PL 0						//初めのアップデートのポイント

#define SIZE_TEX_PLAYER_BASE_X 800			//プレイヤーの基本的なテクスチャサイズ X
#define SIZE_TEX_PLAYER_BASE_Y 800			//プレイヤーの基本的なテクスチャサイズ Y

#define SLOW_DOWN 0.01						//移動の減速スピード
#define WALK_SPEED 0.1						//歩くスピード
#define RUN_SPEED 0.2						//走るスピード
#define WALK_X 1							//歩くベクトルX
#define WALK_Y 0.5							//歩くベクトルY
#define PATTERN_R 1							//PATTERNの右
#define PATTERN_L 2							//PATTERNの左
#define TEX_FILE_PLAYER_STAY			 "../CG\\beru\\beru_stay\\"		//プレイヤーのファイル場所　待ち
#define TEX_FILE_PLAYER_WALK			 "../CG\\beru\\beru_walk\\"		//プレイヤーのファイル場所　待ち
#define TEX_FILE_PLAYER_RUN				 "../CG\\beru\\beru_run\\"		//プレイヤーのファイル場所　待ち
#define TEX_FILE_PLAYER_NormalATTACK_A	 "../CG\\beru\\beru_attackA\\"	//プレイヤーのファイル場所　通常攻撃A
#define TEX_FILE_PLAYER_NormalATTACK_B	 "../CG\\beru\\beru_attackB\\"	//プレイヤーのファイル場所　通常攻撃B
#define TEX_FILE_PLAYER_NormalATTACK_C	 "../CG\\beru\\beru_attackC\\"	//プレイヤーのファイル場所　通常攻撃C
#define TEX_FILE_PLAYER_EX01			 "../CG\\beru\\beru_EX01\\"		//プレイヤーのファイル場所　消費
#define TEX_FILE_PLAYER_EX02			 "../CG\\beru\\beru_EX02\\"		//プレイヤーのファイル場所　継続
#define TEX_FILE_PLAYER_EAT				 "../CG\\beru\\beru_eat\\"		//プレイヤーのファイル場所　捕食
#define TEX_FILE_PLAYER_FLAME			 "../CG\\beru\\beru_flame\\"	//プレイヤーのファイル場所　炎(オーラ)
#define TEX_FILE_PLAYER_BRAKE			 "../CG\\beru\\beru_brake\\"	//プレイヤーのファイル場所　ブレーキ

float CPlayer::camera_x; 
float CPlayer::camera_y;


void CPlayer::SetPos(){
	mPos = first_pos;
	mAxis = mPos.y - SIZE_PLAYER_Y;

}


void CPlayer::Init() {
	SetPos();
	camera_x = mPos.x;
	camera_y = mPos.y;
	/*テクスチャ読み込み*/
	for (int i = 0; i < FRAME_LIMIT; i++)
	{
		mStayTex[i] = new CTexture();			//テクスチャクラスのインスタンス作成
		mWalkTex[i] = new CTexture();			//テクスチャクラスのインスタンス作成
		mRunTex[i] = new CTexture();			//テクスチャクラスのインスタンス作成
		mEx01Tex[i] = new CTexture();			//テクスチャクラスのインスタンス作成
		mEx02Tex[i] = new CTexture();			//テクスチャクラスのインスタンス作成
		mEatTex[i] = new CTexture();			//テクスチャクラスのインスタンス作成
		mFlameTex[i] = new CTexture();			//テクスチャクラスのインスタンス作成
		mBrakeTex[i] = new CTexture();			//テクスチャクラスのインスタンス作成

		for (int z = 0; z < NORMALATTACK_PATTERN; z++)
		{
			mNormalAttackTex[z][i] = new CTexture();	//テクスチャクラスのインスタンス作成
		}
		mEatTex[i] = new CTexture();

	}
	
	mShadowTex = new CTexture();		//テクスチャクラスのインスタンス作成

	/*テクスチャファイル読み込み*/
	/*待ち*/
	mStayTex[0]->load(TEX_FILE_PLAYER_STAY"beru_stay_00.tga");
	mStayTex[1]->load(TEX_FILE_PLAYER_STAY"beru_stay_01.tga");
	mStayTex[2]->load(TEX_FILE_PLAYER_STAY"beru_stay_02.tga");
	mStayTex[3]->load(TEX_FILE_PLAYER_STAY"beru_stay_03.tga");
	mStayTex[4]->load(TEX_FILE_PLAYER_STAY"beru_stay_04.tga");
	mStayTex[5]->load(TEX_FILE_PLAYER_STAY"beru_stay_05.tga");
	/*歩く*/
	mWalkTex[0]->load(TEX_FILE_PLAYER_WALK"beru_walk_00.tga");
	mWalkTex[1]->load(TEX_FILE_PLAYER_WALK"beru_walk_01.tga");
	mWalkTex[2]->load(TEX_FILE_PLAYER_WALK"beru_walk_02.tga");
	mWalkTex[3]->load(TEX_FILE_PLAYER_WALK"beru_walk_03.tga");
	mWalkTex[4]->load(TEX_FILE_PLAYER_WALK"beru_walk_04.tga");
	mWalkTex[5]->load(TEX_FILE_PLAYER_WALK"beru_walk_05.tga");
	/*走る*/
	mRunTex[0]->load(TEX_FILE_PLAYER_RUN"beru_run_00.tga");
	mRunTex[1]->load(TEX_FILE_PLAYER_RUN"beru_run_01.tga");
	mRunTex[2]->load(TEX_FILE_PLAYER_RUN"beru_run_02.tga");
	mRunTex[3]->load(TEX_FILE_PLAYER_RUN"beru_run_03.tga");
	mRunTex[4]->load(TEX_FILE_PLAYER_RUN"beru_run_04.tga");
	mRunTex[5]->load(TEX_FILE_PLAYER_RUN"beru_run_05.tga");
	/*通常A*/
	mNormalAttackTex[0][0]->load(TEX_FILE_PLAYER_NormalATTACK_A"beru_attackA_00.tga");
	mNormalAttackTex[0][1]->load(TEX_FILE_PLAYER_NormalATTACK_A"beru_attackA_01.tga");
	mNormalAttackTex[0][2]->load(TEX_FILE_PLAYER_NormalATTACK_A"beru_attackA_02.tga");
	mNormalAttackTex[0][3]->load(TEX_FILE_PLAYER_NormalATTACK_A"beru_attackA_03.tga");
	mNormalAttackTex[0][4]->load(TEX_FILE_PLAYER_NormalATTACK_A"beru_attackA_04.tga");
	mNormalAttackTex[0][5]->load(TEX_FILE_PLAYER_NormalATTACK_A"beru_attackA_05.tga");
	/*通常B*/
	mNormalAttackTex[1][0]->load(TEX_FILE_PLAYER_NormalATTACK_B"beru_attackB_00.tga");
	mNormalAttackTex[1][1]->load(TEX_FILE_PLAYER_NormalATTACK_B"beru_attackB_01.tga");
	mNormalAttackTex[1][2]->load(TEX_FILE_PLAYER_NormalATTACK_B"beru_attackB_02.tga");
	mNormalAttackTex[1][3]->load(TEX_FILE_PLAYER_NormalATTACK_B"beru_attackB_03.tga");
	mNormalAttackTex[1][4]->load(TEX_FILE_PLAYER_NormalATTACK_B"beru_attackB_04.tga");
	mNormalAttackTex[1][5]->load(TEX_FILE_PLAYER_NormalATTACK_B"beru_attackB_05.tga");
	/*通常C*/
	mNormalAttackTex[2][0]->load(TEX_FILE_PLAYER_NormalATTACK_C"beru_attackC_00.tga");
	mNormalAttackTex[2][1]->load(TEX_FILE_PLAYER_NormalATTACK_C"beru_attackC_01.tga");
	mNormalAttackTex[2][2]->load(TEX_FILE_PLAYER_NormalATTACK_C"beru_attackC_02.tga");
	mNormalAttackTex[2][3]->load(TEX_FILE_PLAYER_NormalATTACK_C"beru_attackC_03.tga");
	mNormalAttackTex[2][4]->load(TEX_FILE_PLAYER_NormalATTACK_C"beru_attackC_04.tga");
	mNormalAttackTex[2][5]->load(TEX_FILE_PLAYER_NormalATTACK_C"beru_attackC_05.tga");
	/*捕食*/
	mEatTex[0]->load(TEX_FILE_PLAYER_EAT"beru_eat_00.tga");
	mEatTex[1]->load(TEX_FILE_PLAYER_EAT"beru_eat_01.tga");
	mEatTex[2]->load(TEX_FILE_PLAYER_EAT"beru_eat_02.tga");
	mEatTex[3]->load(TEX_FILE_PLAYER_EAT"beru_eat_03.tga");
	mEatTex[4]->load(TEX_FILE_PLAYER_EAT"beru_eat_04.tga");
	mEatTex[5]->load(TEX_FILE_PLAYER_EAT"beru_eat_05.tga");
	/*必殺技(消費)*/
	mEx01Tex[0]->load(TEX_FILE_PLAYER_EX01"beru_EX01_00.tga");
	mEx01Tex[1]->load(TEX_FILE_PLAYER_EX01"beru_EX01_01.tga");
	mEx01Tex[2]->load(TEX_FILE_PLAYER_EX01"beru_EX01_02.tga");
	mEx01Tex[3]->load(TEX_FILE_PLAYER_EX01"beru_EX01_03.tga");
	mEx01Tex[4]->load(TEX_FILE_PLAYER_EX01"beru_EX01_04.tga");
	mEx01Tex[5]->load(TEX_FILE_PLAYER_EX01"beru_EX01_05.tga");
	/*必殺技(継続)*/
	mEx02Tex[0]->load(TEX_FILE_PLAYER_EX02"beru_EX02_00.tga");
	mEx02Tex[1]->load(TEX_FILE_PLAYER_EX02"beru_EX02_01.tga");
	mEx02Tex[2]->load(TEX_FILE_PLAYER_EX02"beru_EX02_02.tga");
	mEx02Tex[3]->load(TEX_FILE_PLAYER_EX02"beru_EX02_03.tga");
	mEx02Tex[4]->load(TEX_FILE_PLAYER_EX02"beru_EX02_04.tga");
	mEx02Tex[5]->load(TEX_FILE_PLAYER_EX02"beru_EX02_05.tga");
	/*ブレーキ*/
	mBrakeTex[0]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_00.tga");
	mBrakeTex[1]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_01.tga");
	mBrakeTex[2]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_02.tga");
	mBrakeTex[3]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_03.tga");
	mBrakeTex[4]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_04.tga");
	mBrakeTex[5]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_05.tga");
	/*炎*/
	mFlameTex[0]->load(TEX_FILE_PLAYER_FLAME"beru_flame_00.tga");
	mFlameTex[1]->load(TEX_FILE_PLAYER_FLAME"beru_flame_01.tga");
	mFlameTex[2]->load(TEX_FILE_PLAYER_FLAME"beru_flame_02.tga");
	mFlameTex[3]->load(TEX_FILE_PLAYER_FLAME"beru_flame_03.tga");
	mFlameTex[4]->load(TEX_FILE_PLAYER_FLAME"beru_flame_04.tga");
	mFlameTex[5]->load(TEX_FILE_PLAYER_FLAME"beru_flame_05.tga");
	/*影*/
	mShadowTex->load(TEX_FILE_SHADOW"shadow.tga");

	/*テクスチャを張る*/
	mPlayer.SetUv(mStayTex[0], 0, 0, SIZE_TEX_PLAYER_BASE_X,SIZE_TEX_PLAYER_BASE_Y);
	mShadow.SetUv(mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mForward = CVector2(1.0f, 0.0f);
}


CPlayer::~CPlayer() {

}


//プレイヤー描画
CPlayer::CPlayer() : mVelocity(0),mEnabledNormalAttack(false), mSpeedJump(JUMP_FIRST_SPEED),mStatus(E_STAY_R),AnimePattern(E_BRAKE_R),mIntervalCount(0){

	for (int i = 0; i < FRAME_LIMIT; i++)
	{
		mStayTex[i] = 0;
	}

	mPriorityR = FIRST_R_NO_PL;			//Renderのナンバー 
	mPriorityU = FIRST_U_NO_PL;			//Updateのナンバー
	mHitPoint = HITPOINT_PLAYER;		//ＨＰ
	mMyNumber = E_PLAYER;

	//四角形の頂点設定
	mPlayer.SetVertex(-SIZE_PLAYER_X, SIZE_PLAYER_Y, SIZE_PLAYER_X, -SIZE_PLAYER_Y);
	mShadow.SetVertex(-SIZE_SHADOW_X, SIZE_SHADOW_Y, SIZE_SHADOW_X, -SIZE_SHADOW_Y);
	//四角形の色を設定
	mPlayer.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mShadow.SetColor(0.5f, 0.5f, 0.5f, 0.7f);

}



void CPlayer::DecisionRL(int R,int L){
	if (mStatus  < AnimePattern / 2){
		mStatus = R;
	}
	else
	{
		mStatus = L;
	}
}


void CPlayer::Jump(){ //ジャンプ処理メソッド
	/*
	計算
	y = y + v(時間により進んだ距離) 
	重力計算
	v = v0 + g*t(どれくらい重力がかかったか)
	*/

	mPos.y = mPos.y + mSpeedJump; //飛ぶ処理
	mSpeedJump -= gravity;//減速処理


	if (mPos.y < mAxis + SIZE_PLAYER_Y){//現在の軸に足がついたとき
		mPos.y = mAxis + SIZE_PLAYER_Y; //元いた地面の"Y"に戻す
		mSpeedJump = JUMP_FIRST_SPEED;
		mEnabledJump = false; //終了

	}



}

void CPlayer::MovePosAxis(){
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;
}


void CPlayer::Run_Walk(){
	if (CKey::push(VK_CONTROL)){ //走る時
		mVelocity = RUN_SPEED;
		DecisionRL(E_RUN_R, E_RUN_L);
	}
	else{					   //歩く時
		DecisionRL(E_WALK_R, E_WALK_L);
		mVelocity = WALK_SPEED;
	}
}

/*アニメのフレームを動かすメソッド*/ //エネミーによって違う場合があるので画像データ用参照

void CPlayer::AnimeFlame(){
	if (!mEnabledNormalAttack){//通常攻撃していない時
		mFlameCount += 1;
		if (mFlameCount % 8 == 0){
			mAnimeFrame += 1;
		}
		if (mAnimeFrame >= FRAME_LIMIT || mSaveAnime != mStatus){
			mAnimeFrame = 0;
		}
		mSaveAnime = mStatus;
	}
	else{						//通常攻撃していないとき
		mAnimeFrame++;
		if (mFlameCount % 8 == 0){
			mAnimeFrame += 1;
		}
		if (mAnimeFrame >= FRAME_LIMIT || mSaveAnime != mStatus){
			mAnimeFrame = 0;
		}
		mSaveAnime = mStatus;
	}
}

bool CPlayer::Move(){
	// 右移動
	if (CKey::push(VK_RIGHT)) {
		mStatus = E_WALK_R;
		Run_Walk();
		mForward = CVector2(WALK_X, 0.0f);
		mPos += mForward * mVelocity;
		return true;
	}
	else{
		DecisionRL(E_BRAKE_R, E_BRAKE_L);
		DecisionRL(E_STAY_R, E_STAY_L);
	}

	//左移動
	if (CKey::push(VK_LEFT)) {
		mStatus = E_WALK_L;
		Run_Walk();
		mForward = CVector2(-WALK_X, 0.0f);
		mPos += mForward * mVelocity;
		return true;
	}
	else{
		DecisionRL(E_BRAKE_R, E_BRAKE_L);
		if (mVelocity == 0){
			DecisionRL(E_STAY_R, E_STAY_L);
		}
	}

	//上移動
	if (CKey::push(VK_UP) && mAxis < character_limit_top - SIZE_PLAYER_Y) { //軸が上限に達していないとき
		Run_Walk();
		mForward = CVector2(0.0f, WALK_Y);
		MovePosAxis();
		return true;
	}
	else{
		DecisionRL(E_BRAKE_R, E_BRAKE_L);
		if (mVelocity == 0){
			DecisionRL(E_STAY_R, E_STAY_L);
		}
	}

	//下移動
	if (CKey::push(VK_DOWN) && mAxis > character_limit_bottom) {//軸が上限に達していないとき
		Run_Walk();
		mForward = CVector2(0.0f, -WALK_Y);
		MovePosAxis();
		return true;
	}
	else{
		DecisionRL(E_BRAKE_R, E_BRAKE_L);
		if (mVelocity == 0){
			DecisionRL(E_STAY_R, E_STAY_L);
		}
	}
	return false;
}


void CPlayer::Update() {
	AnimeFlame();
	assert(mAnimeFrame <= FRAME_LIMIT); //フレーム数が七を超えるとダメ

	//四角形の位置を設定
	mPlayer.position = mPos;

	if (!mEnabledNormalAttack){
		//移動の処理
		Move();
	}
	//ジャンプ
	if (CKey::push(' ') || mEnabledJump) {
		if (!mEnabledJump && !mEnabledNormalAttack){ //ジャンプしていないとき
			mEnabledJump = true;
		}
		Jump();
	}

	//通常攻撃
	if (CKey::push('X')){
		mEnabledNormalAttack = true;
		DecisionRL(E_NORMALATTACK_A_L, E_NORMALATTACK_A_L);
	}
	
	/*アニメーションのステータス*/
	switch (mStatus)
	{
		/*左*/
	case E_STAY_L:
		mPlayer.SetUv(mStayTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_WALK_L:
		mPlayer.SetUv(mWalkTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_RUN_L:
		mPlayer.SetUv(mRunTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;






		/*攻撃 A B C*/
	case E_NORMALATTACK_A_L:
		if (mAnimeFrame < FRAME_LIMIT){
			mPlayer.SetUv(mNormalAttackTex[0][mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		}
		else{
			//10フレーム以内にキー入力で次に移動
			if (mIntervalCount <= 10){
				DecisionRL(E_NORMALATTACK_B_R, E_NORMALATTACK_B_L);
			}
			else{
				DecisionRL(E_STAY_R, E_STAY_L);
			}
			mIntervalCount++;
		}
		break;

	case E_NORMALATTACK_B_L:
		if (mAnimeFrame < FRAME_LIMIT){
			mPlayer.SetUv(mNormalAttackTex[1][mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		}
		else{
			//10フレーム以内にキー入力で次に移動
			if (mIntervalCount <= 10){
				DecisionRL(E_NORMALATTACK_B_R, E_NORMALATTACK_B_L);
			}
			else{
				DecisionRL(E_STAY_R, E_STAY_L);
			}
			mIntervalCount++;
		}
		break;

	case E_NORMALATTACK_C_L:
		if (mAnimeFrame == FRAME_LIMIT){
			mPlayer.SetUv(mNormalAttackTex[2][mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		}
		else{
			DecisionRL(E_STAY_R, E_STAY_L);
		}
		mIntervalCount++;

		break;








	case E_EAT_L:
		mPlayer.SetUv(mEatTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX01_L:
		mPlayer.SetUv(mEx01Tex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX02_L:
		mPlayer.SetUv(mEx02Tex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_FLAME_L:
		mPlayer.SetUv(mFlameTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_BRAKE_L:
		mVelocity -= SLOW_DOWN;
		mPos += mForward * mVelocity;
		if (mVelocity < 0){
			mVelocity = 0;
			DecisionRL(E_STAY_R, E_STAY_L);
		}
		mPlayer.SetUv(mBrakeTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;














		/*右*/
	case E_STAY_R:

		mPlayer.SetUv(mStayTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_WALK_R:
		mPlayer.SetUv(mWalkTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_RUN_R:
		mPlayer.SetUv(mRunTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;













		/*通常攻撃ABC*/
	case E_NORMALATTACK_A_R:
		if (mAnimeFrame < FRAME_LIMIT){
			mPlayer.SetUv(mNormalAttackTex[0][mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		}
		else{
			//10フレーム以内にキー入力で次に移動
			if (mIntervalCount <= 10){
				DecisionRL(E_NORMALATTACK_B_R, E_NORMALATTACK_B_L);
			}
			else{
				DecisionRL(E_STAY_R, E_STAY_L);
				mIntervalCount = 0;
			}
			mIntervalCount++;
		}

		break;


	case E_NORMALATTACK_B_R:
		if (mAnimeFrame < FRAME_LIMIT){
			mPlayer.SetUv(mNormalAttackTex[1][mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		}
		else{
			//10フレーム以内にキー入力で次に移動
			if (mIntervalCount <= 10){
				DecisionRL(E_NORMALATTACK_C_R, E_NORMALATTACK_C_L);
			}
			else{
				DecisionRL(E_STAY_R, E_STAY_L);
				mIntervalCount = 0;
			}
			mIntervalCount++;
		}
		break;



	case E_NORMALATTACK_C_R:
		if (mAnimeFrame < FRAME_LIMIT){
			mPlayer.SetUv(mNormalAttackTex[2][mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		}
		else
		{
			DecisionRL(E_STAY_R, E_STAY_L);
		}
		break;











	case E_EAT_R:
		mPlayer.SetUv(mEatTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX01_R:
		mPlayer.SetUv(mEx01Tex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX02_R:
		mPlayer.SetUv(mEx02Tex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_FLAME_R:
		mPlayer.SetUv(mFlameTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_BRAKE_R:

		mVelocity -= SLOW_DOWN;
		mPos += mForward * mVelocity;
		if (mVelocity < 0){
			mVelocity = 0;
			DecisionRL(E_STAY_R, E_STAY_L);
		}
		mPlayer.SetUv(mBrakeTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	};


		/*あたり判定*/
		if (mAxis > character_limit_top - SIZE_PLAYER_Y && !mEnabledJump){  //マップ外に出ると元の位置に戻す(軸)
			mPos.y = character_limit_top;
			mAxis = mPos.y - SIZE_PLAYER_Y; //軸をもとに戻す
		}
		if (mAxis < character_limit_bottom - SIZE_PLAYER_Y){  //マップ外に出ると元の位置に戻す(軸)
			mPos.y = character_limit_bottom;
			mAxis = mPos.y - SIZE_PLAYER_Y; //軸をもとに戻す
		}

		if (mPos.x >= character_limit_right - SIZE_PLAYER_X || mPos.x <= character_limit_left + SIZE_PLAYER_X){ //マップ外に出ると元の位置に戻す(X)
			mPos.x = mPlayer.position.x;
		}
		/*あたり判定終了*/



		mPriorityR = -mAxis;
		camera_x = mPos.x;
		camera_y = mPos.y;

		mPlayer.position = mPos;
		mShadow.position = CVector2(mPos.x, mAxis);
	}

void CPlayer::Render(){
	//プレイヤーの描画
	mShadow.Render();
	mPlayer.Render();

}
