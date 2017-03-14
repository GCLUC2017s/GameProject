#include "CEnemy01.h"
#include "../MyNumber/CMyNumber.h"
#include "../Key/CKey.h" //挙動テスト時の操作用
/*

ヒコースケーチ

*/



#define SIZE_ENEMY00_Y 1  //エネミー01のサイズ_Y
#define SIZE_ENEMY00_X 1 //エネミー01のサイズ_X

#define HITPOINT_ENEMY00 5					//エネミー00の体力
#define FIRST_R_NO_PL 1						//初めのレンダーのポイント
#define FIRST_U_NO_PL 1						//初めのアップデートのポイント
#define SIZE_TEX_ENEMY00_STAY_X 800			//エネミーの待ち姿テクスチャサイズ X
#define SIZE_TEX_ENEMY00_STAY_Y 800			//エネミーの待ち姿テクスチャサイズ Y
#define SIZE_TEX_ENEMY00_WALK_X 800			//エネミーの歩くテクスチャサイズ Y
#define SIZE_TEX_ENEMY00_WALK_Y 800			//エネミーの歩く姿テクスチャサイズ Y
#define SIZE_SHADOW							//影の表示
#define SLOW_DOWN 0.001						//移動の減速スピード
#define WALK_SPEED 0.07		//テスト用にいじってる				//飛行スピード
#define WALK_X 2							//飛行ベクトルX
#define WALK_Y 1							//飛行ベクトルY

#define ENEMY00_FLAY "../CG\\enemy01\\enemy01_flay\\"
#define ENEMY00_STAY "../CG\\enemy01\\enemy01_stay\\"
#define ENEMY00_ATTACK "../CG\\enemy01\\enemy01_attack\\"
#define ENEMY00_DIE "../CG\\enemy01\\enemy01_die\\"
#
void CEnemy01::SetPos(){
	mPos = Enemy_first_pos;
	mAxis = mPos.y;
};

void CEnemy01::Init(){
	SetPos();
	/*テクスチャ読み込み*/
	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = new CTexture();		//テクスチャクラスのインスタンス作成
		mFlay_tex[i] = new CTexture();		//テクスチャクラスのインスタンス作成
		mAttack_tex[i] = new CTexture();
		mDie_tex[i] = new CTexture();		
	}

	/*テクスチャファイル読み込み*/
	mStay_tex[0]->load(ENEMY00_STAY"enemy01_stay_00.tga");
	mStay_tex[1]->load(ENEMY00_STAY"enemy01_stay_01.tga");
	mStay_tex[2]->load(ENEMY00_STAY"enemy01_stay_02.tga");
	mStay_tex[3]->load(ENEMY00_STAY"enemy01_stay_03.tga");
	mStay_tex[4]->load(ENEMY00_STAY"enemy01_stay_04.tga");
	mStay_tex[5]->load(ENEMY00_STAY"enemy01_stay_05.tga");

	mFlay_tex[0]->load(ENEMY00_FLAY"enemy01_flay_00.tga");
	mFlay_tex[1]->load(ENEMY00_FLAY"enemy01_flay_01.tga");
	mFlay_tex[2]->load(ENEMY00_FLAY"enemy01_flay_02.tga");
	mFlay_tex[3]->load(ENEMY00_FLAY"enemy01_flay_03.tga");
	mFlay_tex[4]->load(ENEMY00_FLAY"enemy01_flay_04.tga");
	mFlay_tex[5]->load(ENEMY00_FLAY"enemy01_flay_05.tga");

	mAttack_tex[0]->load(ENEMY00_ATTACK"enemy01_attackR_00.tga");
	mAttack_tex[1]->load(ENEMY00_ATTACK"enemy01_attackR_00.tga");
	mAttack_tex[2]->load(ENEMY00_ATTACK"enemy01_attackR_00.tga");
	mAttack_tex[3]->load(ENEMY00_ATTACK"enemy01_attackR_00.tga");
	mAttack_tex[4]->load(ENEMY00_ATTACK"enemy01_attackR_00.tga");
	mAttack_tex[5]->load(ENEMY00_ATTACK"enemy01_attackR_00.tga");

	mDie_tex[0]->load(ENEMY00_DIE"enemy01_die_00.tga");
	mDie_tex[1]->load(ENEMY00_DIE"enemy01_die_01.tga");
	mDie_tex[2]->load(ENEMY00_DIE"enemy01_die_02.tga");
	mDie_tex[3]->load(ENEMY00_DIE"enemy01_die_03.tga");
	mDie_tex[4]->load(ENEMY00_DIE"enemy01_die_04.tga");
	mDie_tex[5]->load(ENEMY00_DIE"enemy01_die_05.tga");



	/*テクスチャを張る*/
	mEnemy01.SetUv(mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

}

CEnemy01::~CEnemy01(){
	//特に何もしない
}

//エネミー00描画
CEnemy01::CEnemy01() : mVelocity(0), mFlameCount(0){

	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = 0;
	}

	mPriorityR = FIRST_R_NO_PL;			//Renderのナンバー 
	mPriorityU = FIRST_U_NO_PL;			//Updateのナンバー
	mHitPoint = HITPOINT_ENEMY00;		//ＨＰ
	mMyNumber = E_ENEMY00;

	//四角形の頂点設定
	mEnemy01.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	mShadow.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	//四角形の色を設定
	mEnemy01.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

}

/*アニメのフレームを動かすメソッド*/ //エネミーによって違う場合があるので画像データ用参照
void CEnemy01::AnimeFlame(){

	mFlameCount += 1;
	if (mFlameCount % 5 == 0){ //フレーム数=mStay_tex[5]->load(".../.tga");
		mAnime += 1;
	}
	if (mAnime >= FLAME_LIMIT || mSaveAnime != eAnime){
		mAnime = 0;
	}
	mSaveAnime = eAnime;

}


void CEnemy01::Update(){

	AnimeFlame();
	assert(mAnime <= FLAME_LIMIT); //フレーム数が七を超えるとダメ
	mPriorityR = -mAxis;
	CTaskManager TaskManager;

	//四角形の位置を設定
	mEnemy01.position = mPos;


	// 右移動
	if (CKey::push('D')) {
		eAnime = E_FLAY_R;
		mVelocity = WALK_SPEED;

		mForward = CVector2(WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}
	else{
		if (mSaveAnime == E_FLAY_R){//待機中 直前が左の歩きでなければ
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

		eAnime = E_FLAY_L;
		mVelocity = WALK_SPEED;

		mForward = CVector2(-WALK_X, 0.0f);
		mPos += mForward * mVelocity;

	}
	else{ //移動していないとき
		if (mSaveAnime == E_FLAY_L){ //待機中 直前が右の歩きでなければ
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
		mPos.x = mEnemy01.position.x;
	}
	/*あたり判定終了*/

	mEnemy01.position = mPos;

	/*アニメーションのステータス*/
	switch (eAnime)
	{
		/*待機中*/
	case E_STAY_L:
		mEnemy01.SetUv(mStay_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_STAY_R:
		mEnemy01.SetUv(mStay_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*歩き中*/
	case E_FLAY_L:
		mEnemy01.SetUv(mFlay_tex[mAnime], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	case E_FLAY_R:
		mEnemy01.SetUv(mFlay_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	}

}
void CEnemy01::Render(){
	mEnemy01.Render();
}
