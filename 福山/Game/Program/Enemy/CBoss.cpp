#include "CBoss.h"
#include "../MyNumber/CMyNumber.h"
#include "../Key/CKey.h" //挙動テスト時の操作用

#define SIZE_ENEMY00_Y 3  //エネミー00のサイズ_Y
#define SIZE_ENEMY00_X 3 //エネミー00のサイズ_X

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

#define BOSS_STAY 	 "../CG\\BOSS\\stay\\"
#define BOSS_WALK	 "../CG\\BOSS\\walk\\"
#define BOSS_ATTACK	 "../CG\\BOSS\\Attack\\"
#define BOSS_HATTACK "../CG\\BOSS\\HAttack\\"
#define BOSS_DIE	 "../CG\\BOSS\\die\\"

void CBoss::SetPos(){
	mPos = Enemy_first_pos;
	mAxis = mPos.y;
};

void CBoss::Init(){
	SetPos();
	/*テクスチャ読み込み*/
	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = new CTexture();		//テクスチャクラスのインスタンス作成
		mWalk_tex[i] = new CTexture();		//テクスチャクラスのインスタンス作成
		mAttack_tex[i] = new CTexture();
		mHattack_tex[i] = new CTexture();
		mDie_tex[i] = new CTexture();
	}

	/*テクスチャファイル読み込み*/
	mStay_tex[0]->load(BOSS_STAY "BOSS_stay_00.tga");
	mStay_tex[1]->load(BOSS_STAY "BOSS_stay_01.tga");
	mStay_tex[2]->load(BOSS_STAY "BOSS_stay_02.tga");
	mStay_tex[3]->load(BOSS_STAY "BOSS_stay_03.tga");
	mStay_tex[4]->load(BOSS_STAY "BOSS_stay_04.tga");
	mStay_tex[5]->load(BOSS_STAY "BOSS_stay_05.tga");

	mWalk_tex[0]->load(BOSS_WALK"BOSS_walkR_00.tga");
	mWalk_tex[1]->load(BOSS_WALK"BOSS_walkR_01.tga");
	mWalk_tex[2]->load(BOSS_WALK"BOSS_walkR_02.tga");
	mWalk_tex[3]->load(BOSS_WALK"BOSS_walkR_03.tga");
	mWalk_tex[4]->load(BOSS_WALK"BOSS_walkR_04.tga");
	mWalk_tex[5]->load(BOSS_WALK"BOSS_walkR_05.tga");

	mAttack_tex[0]->load(BOSS_WALK"BOSS_walkR_00.tga");
	mAttack_tex[1]->load(BOSS_WALK"BOSS_walkR_01.tga");
	mAttack_tex[2]->load(BOSS_WALK"BOSS_walkR_02.tga");
	mAttack_tex[3]->load(BOSS_WALK"BOSS_walkR_03.tga");
	mAttack_tex[4]->load(BOSS_WALK"BOSS_walkR_04.tga");
	mAttack_tex[5]->load(BOSS_WALK"BOSS_walkR_05.tga");

	mWalk_tex[0]->load(BOSS_WALK"BOSS_walkR_00.tga");
	mWalk_tex[1]->load(BOSS_WALK"BOSS_walkR_01.tga");
	mWalk_tex[2]->load(BOSS_WALK"BOSS_walkR_02.tga");
	mWalk_tex[3]->load(BOSS_WALK"BOSS_walkR_03.tga");
	mWalk_tex[4]->load(BOSS_WALK"BOSS_walkR_04.tga");
	mWalk_tex[5]->load(BOSS_WALK"BOSS_walkR_05.tga");



	/*テクスチャを張る*/
	mBoss.SetUv(mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

}

CBoss::~CBoss(){
	//特に何もしない
}

//エネミー00描画
CBoss::CBoss() : mVelocity(0), mFlameCount(0){

	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = 0;
	}

	mPriorityR = FIRST_R_NO_PL;			//Renderのナンバー 
	mPriorityU = FIRST_U_NO_PL;			//Updateのナンバー
	mHitPoint = HITPOINT_ENEMY00;		//ＨＰ
	mMyNumber = E_ENEMY00;

	//四角形の頂点設定
	mBoss.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	mShadow.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	//四角形の色を設定
	mBoss.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

}

/*アニメのフレームを動かすメソッド*/ //エネミーによって違う場合があるので画像データ用参照
void CBoss::AnimeFlame(){

	mFlameCount += 1;
	if (mFlameCount % 5 == 0){ //フレーム数=mStay_tex[5]->load(".../.tga");
		mAnime += 1;
	}
	if (mAnime >= FLAME_LIMIT || mSaveAnime != eAnime){
		mAnime = 0;
	}
	mSaveAnime = eAnime;

}


void CBoss::Update(){

	AnimeFlame();
	assert(mAnime <= FLAME_LIMIT); //フレーム数が七を超えるとダメ
	mPriorityR = -mAxis;
	CTaskManager TaskManager;

	//四角形の位置を設定
	mBoss.position = mPos;


	// 右移動
	if (CKey::push('D')) {
		eAnime = E_WALK_R;
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
	if (CKey::push('W') && mAxis < character_limit_top - SIZE_ENEMY00_Y) { //軸が上限に達していないとき
		Walk();
		mForward = CVector2(0.0f, WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;

	}

	//下移動
	if (CKey::push('S') && mAxis > character_limit_bottom + SIZE_ENEMY00_Y) {//軸が上限に達していないとき
		Walk();
		mForward = CVector2(0.0f, -WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;
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
		mPos.x = mBoss.position.x;
	}
	/*あたり判定終了*/

	mBoss.position = mPos;

	/*アニメーションのステータス*/
	switch (eAnime)
	{
		/*待機中*/
	case E_STAY_L:
		mBoss.SetUv(mStay_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_STAY_R:
		mBoss.SetUv(mStay_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*歩き中*/
	case E_WALK_L:
		mBoss.SetUv(mWalk_tex[mAnime], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	case E_WALK_R:
		mBoss.SetUv(mWalk_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	}

}
void CBoss::Render(){
	mBoss.Render();
}
