#include "CEnemy00.h"
#include "../MyNumber/CMyNumber.h"
#include "../Key/CKey.h" //挙動テスト時の操作用

#define SIZE_ENEMY00_Y 1  //エネミー00のサイズ_Y
#define SIZE_ENEMY00_X 1 //エネミー00のサイズ_X

#define HITPOINT_ENEMY00 5					//エネミー00の体力
#define FIRST_R_NO_PL 1						//初めのレンダーのポイント
#define FIRST_U_NO_PL 1						//初めのアップデートのポイント
#define SIZE_TEX_ENEMY00_STAY_X 800			//エネミーの待ち姿テクスチャサイズ X
#define SIZE_TEX_ENEMY00_STAY_Y 800			//エネミーの待ち姿テクスチャサイズ Y
#define SIZE_TEX_ENEMY00_WALK_X 800			//エネミーの歩くテクスチャサイズ Y
#define SIZE_TEX_ENEMY00_WALK_Y 800			//エネミーの歩く姿テクスチャサイズ Y
#define SIZE_SHADOW							//影の表示
#define SLOW_DOWN 0.001						//移動の減速スピード

#define WALK_SPEED 0.05						//歩くスピード
#define WALK_X 2							//歩くベクトルX
#define WALK_Y 1							//歩くベクトルY

#define ENEMY00_STAY "../CG\\enemy00\\enemy00_stay\\"
#define ENEMY00_WALK "../CG\\enemy00\\enemy00_walk\\"
#define ENEMY00_ATTACK "../CG\\enemy00\\enemy00_attack\\"
#define ENEMY00_DIE "../CG\\enemy00\\enemy00_dai\\"


//攻撃時にいかなる場合でも右を向いてしまう。



void CEnemy00::SetPos(){
	mPos = Enemy_first_pos;
	mAxis = mPos.y;
};

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
	mEnemy00.SetUv(mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

}

CEnemy00::~CEnemy00(){
//特に何もしない
}

//エネミー00描画
CEnemy00::CEnemy00() : mVelocity(0), mFlameCount(0){

	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = 0;
	}

	mPriorityR = FIRST_R_NO_PL;			//Renderのナンバー 
	mPriorityU = FIRST_U_NO_PL;			//Updateのナンバー
	mHitPoint = HITPOINT_ENEMY00;		//ＨＰ
	mMyNumber = E_ENEMY00;

	//四角形の頂点設定
	mEnemy00.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	mShadow.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	//四角形の色を設定
	mEnemy00.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

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

	AnimeFlame();
	assert(mAnime <= FLAME_LIMIT); //フレーム数が七を超えるとダメ
	mPriorityR = -mAxis;
	CTaskManager TaskManager;

	//四角形の位置を設定
	mEnemy00.position = mPos;


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




	
		
		if (mSaveAnime == E_WALK_L&&E_STAY_L&&E_ATTACK_L&&E_DIE_L){		//直前が左向きのアクションの場合
			if (CKey::once('X')) { //テスト用　手動攻撃L
				eAnime = E_ATTACK_L;
			}
			if (CKey::once('Z')) {//テスト用　手動自害L
				eAnime = E_DIE_L;
			}

		}
		else{
			if (CKey::once('X')) { //テスト用　手動攻撃R
				eAnime = E_ATTACK_R;
			}
			if (CKey::once('Z')) {//テスト用　手動自害R
				eAnime = E_DIE_R;
			}
			
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
		mPos.x = mEnemy00.position.x;
	}
	/*あたり判定終了*/

	mEnemy00.position = mPos;

	/*アニメーションのステータス*/
	switch (eAnime)
	{
		/*待機中*/
	case E_STAY_R:
		mEnemy00.SetUv(mStay_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_STAY_L:
		mEnemy00.SetUv(mStay_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*歩き中*/
	case E_WALK_R:
		mEnemy00.SetUv(mWalk_tex[mAnime], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	case E_WALK_L:
		mEnemy00.SetUv(mWalk_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
		break;
		/*攻撃中*/
	case E_ATTACK_R:
		mEnemy00.SetUv(mAttack_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		printf("A右です\n");
		break;
	case E_ATTACK_L:
		mEnemy00.SetUv(mAttack_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		printf("A左です\n");
		break;
		/*死亡*/
	case E_DIE_R:
		mEnemy00.SetUv(mDie_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		printf("D右です\n");
		break;
	case E_DIE_L:
		mEnemy00.SetUv(mDie_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		printf("D左です\n");
		break;

	}


}
void CEnemy00::Render(){
	mEnemy00.Render();
}
