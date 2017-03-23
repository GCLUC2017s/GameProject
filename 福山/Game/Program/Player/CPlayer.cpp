#include "CPlayer.h"
#include "../Key/CKey.h"
#include "../MyNumber/CMyNumber.h"
#include "../CGame/CGame.h"
#include "../Load/CLoadPlayer.h"
#include <math.h>
#define JUMP_FIRST_SPEED				0.2f								//ジャンプのジャンプ力
#define FIRST_R_NO_PL					0.0f								//初めのレンダーのポイント
#define FIRST_U_NO_PL					0.0f								//初めのアップデートのポイント
/*テクスチャサイズ*/
#define SIZE_TEX_PLAYER_BASE_X			-160.0f								//プレイヤーの基本的なテクスチャサイズ X
#define SIZE_TEX_PLAYER_AT_C_X			-180.0f								//プレイヤーのAttack_Cテクスチャサイズ X
#define SIZE_TEX_EAT					-180.0f
#define SIZE_TEX_PLAYER_BASE_Y			160.0f								//プレイヤーの基本的なテクスチャサイズ Y
/*テクスチャ例外*/
#define SIZE_TEX_CUTFLY_X				100.0f								//飛ぶ斬撃のテクスチャサイズX
#define SIZE_TEX_CUTFLY_Y				30.0f								//飛ぶ斬撃のテクスチャサイズY

#define SIZE_TEX_CUTJUMP_X				160.0f								//飛ぶ斬撃のテクスチャサイズX
#define SIZE_TEX_CUTJUMP_Y				160.0f								//飛ぶ斬撃のテクスチャサイズY

#define SLOW_DOWN						 0.005f								//移動の減速スピード
#define WALK_SPEED						 0.05f								//歩くスピード
#define RUN_SPEED						 0.1f								//走るスピード
#define WALK_X							 1.0f								//歩くベクトルX
#define WALK_Y							 0.5f								//歩くベクトルY
#define PATTERN_R						 1.0f								//PATTERNの右
#define PATTERN_L						 2.0f								//PATTERNの左
#define V2_RIGHT						 CVector2(WALK_X, 0.0f)				//右の向き
#define V2_LEFT							 CVector2(-WALK_X, 0.0f)			//左の向き
#define V2_TOP							 CVector2(0.0f, WALK_Y)				//上の向き
#define V2_BOTTOM						 CVector2(0.0f, -WALK_Y)			//下の向き
/*アニメの速さ*///(FPSでわかるようにする)現在10が0.1秒
#define ANIME_TIME_BASE						10								//アニメのループ時間 継続的なもの
#define ANIME_TIME_ATTACK					4								//アニメのループ時間 攻撃のもの
#define ANIME_TIME_EAT						10								//アニメのループ時間 食べる
#define ANIME_TIME_JUMPATTACK				4								//アニメのるーぷ時間 ジャンプATTACK
#define ANIME_TIME_BRAKE					7								//アニメのループ時間 BRAKE
#define ANIME_TIME_JUMP						6								//アニメループ時間 ジャンプ
#define ANIME_TIME_WALK						8 + mHungryStatus				//アニメループ時間　歩く
#define ANIME_TIME_EX01						4								//アニメループ時間 必殺技振り

#define ATTACK_A		mForward.x, SIZE_PLAYER_X, SIZE_PLAYER_Y,2, CVector2(mPos.x+mForward.x*0.1,mPos.y)			//攻撃範囲A
#define ATTACK_B		mForward.x, SIZE_PLAYER_X, SIZE_PLAYER_Y/2,2, CVector2(mPos.x+mForward.x*0.1,mPos.y)			//攻撃範囲B
#define ATTACK_C		mForward.x, SIZE_PLAYER_X+0.5f, SIZE_PLAYER_Y,3, CVector2(mPos.x+mForward.x*0.1,mPos.y)	//攻撃範囲C
#define ATTACK_JUMP		mForward.x, SIZE_PLAYER_X*2 ,SIZE_PLAYER_Y*2,3,\
						CVector2(mPos.x  -mForward.x*1.7f, mPos.y)	//攻撃範囲ジャンプATTACK
/*ジャンプ攻撃範囲*/
#define FRAME_JUMPBOTTOM 3													//ジャンプ攻撃下の時のアニメーション
#define EAT_ATTACK		mForward.x, SIZE_PLAYER_X, SIZE_PLAYER_Y,2,CVector2(mPos.x+mForward.x*0.1,mPos.y)	//食べる攻撃
#define EX01_ATTACK		mForward.x, SIZE_PLAYER_X+ fabsf(mEx01Speed), SIZE_PLAYER_Y + fabsf(mEx01Speed),3, CVector2(mPos.x+mEx01Speed,mPos.y) //必殺技範囲
#define EX01_SPEED 0.1f														//必殺技が進むスピード
#define INTERVAL		20.0f												//攻撃後のINTERVALキー入力待ち時間  
#define HUNGRY_SPEED	0.002f												//おなかが減るスピード
#define HUNGRY_SSPP_HIGH	 RUN_SPEED									//おなかが減ってスピードが上がる　+=　して使うもの
#define HUNGRY_SSPP_LOW		-WALK_SPEED*0.5f								//おなかがいっぱい走りにくい 	+=　して使うも
#define HUNGRY_POWER_HIGH	1.2f											//おなかが減って力が出る　*=して使うもの
#define HUNGRY_POWER_LOW	0.8f											//おなかがいっぱい力が出ない　*=して使うもの
#define RIGHT WALK_X														//右
#define LEFT -WALK_X														//左
#define SIZE_ATTACT_C -SIZE_PLAYER_X+0.5f,SIZE_PLAYER_Y,SIZE_PLAYER_X+0.5f,-SIZE_PLAYER_Y
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

	/*テクスチャを張る*/
	mRect.SetUv(CLoadPlayer::GetInstance()->mStayTex[0], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutFlyTex, 0, 0, SIZE_TEX_CUTFLY_X, SIZE_TEX_CUTFLY_Y);
	mForward = CVector2(RIGHT, 0.0f);
}



CPlayer::~CPlayer() {
	


}

//プレイヤー描画
CPlayer::CPlayer() : mVelocity(0), mSpeedJump(JUMP_FIRST_SPEED),mEnabledInterval(false){

	
	mCharaFlag = true;
	mPriorityR = E_PLAYER;			//Renderのナンバー 
	mPriorityU = E_PLAYER;			//Updateのナンバー
	mHitPoint = PL_HP_X;		//ＨＰ
	mStamina = PL_ST_X;			//ST
	mMyNumber = E_PLAYER;
	mStatus = E_STAY_R,
	//四角形の頂点設定
	mRect.SetVertex(-SIZE_PLAYER_X, SIZE_PLAYER_Y, SIZE_PLAYER_X, -SIZE_PLAYER_Y);
	mShadow.SetVertex(-SIZE_SHADOW_X, SIZE_SHADOW_Y, SIZE_SHADOW_X, -SIZE_SHADOW_Y);
	//四角形の色を設定
	mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

}
/*左右判断*/
void CPlayer::DecisionRL(int R, int L){
	
		if (mSaveForword.x == RIGHT || mSaveForword.x == 0){ mStatus = R; }
		if (mSaveForword.x == LEFT){ mStatus = L; }
	
}
/*ジャンプメソッド*/
void CPlayer::Jump(){ //ジャンプ処理メソッド
	/*
	計算
	y = y + v(時間により進んだ距離)
	重力計算
	v = v0 + g*t(どれくらい重力がかかったか)
	*/
	if (CKey::push('C') && !mEnabledJump && !mEnabledAttack) {
		mSpeedJump = JUMP_FIRST_SPEED;
		mAnimeFrame = 0; //ジャンプ初めframe
		mEnabledJump = true; //ジャンプしていないとき
		DecisionRL(E_JUMP_R, E_JUMP_L);
	}

	if (mEnabledJump){
		if (!mEnabledJumpAttack){
			mAnimeFrame = 1; //ジャンプ中間frame
			if (mSpeedJump <= 0){
				mAnimeFrame = 2;
			}
		}
		mPos.y = mPos.y + mSpeedJump; //飛ぶ処理
		mSpeedJump -= gravity;//減速処理
		
		if (mPos.y < mAxis + SIZE_PLAYER_Y){//現在の軸に足がついたとき
			mPos.y = mAxis + SIZE_PLAYER_Y; //元いた地面の"Y"に戻す
			mEnabledJump = false; //終了
		}
	}
}
/*走るか否かメソッド*/
void CPlayer::RunWalk(CVector2 v){
	if (CKey::push(VK_CONTROL)){ //走る時
		mVelocity = RUN_SPEED;
		if(!mEnabledJump)DecisionRL(E_RUN_R, E_RUN_L);
	}
	else{				//歩くとき
		mVelocity = WALK_SPEED;
	}
	
	mForward = v;
	mPos += mForward * (mVelocity+mHungrySSpp);
	mAxis += mForward.y *(mVelocity + mHungrySSpp);
}

/*移動時のメソッド*/
void CPlayer::Move(){
	CVector2 SavemPos = mPos;		//位置保存
	float  SavemAxis = mAxis;		//位置保存
	// 右移動
	if (CKey::push(RIGHT_KEY)) {
		if (!mEnabledJump)mStatus = E_WALK_R;
		RunWalk(V2_RIGHT);
		mSaveForword = V2_RIGHT;
	}
	//左移動
	if (CKey::push(LEFT_KEY)) {
		if (!mEnabledJump)mStatus = E_WALK_L;
		RunWalk(V2_LEFT);
		mSaveForword = V2_LEFT;
	}
	//上移動
	if (CKey::push(UP_KEY)) { 
		if (!mEnabledJump)DecisionRL(E_WALK_R, E_WALK_L);
		RunWalk(V2_TOP);
	}
	//下移動
	if (CKey::push(DOWN_KEY)) {
		if (!mEnabledJump)DecisionRL(E_WALK_R, E_WALK_L);
		RunWalk(V2_BOTTOM);
	}
	if (mAxis > character_limit_top - SIZE_PLAYER_Y ||
		mAxis + SIZE_PLAYER_Y < character_limit_bottom + SIZE_PLAYER_Y){ //上
		mPos = SavemPos;
		mAxis = SavemAxis;
	}
}

/*ブレーキメソッド*/
void CPlayer::Brake(){
	//ブレーキがかかるとき(走らない歩かないジャンプしない)
	if (!CKey::push(VK_DOWN) && !CKey::push(VK_UP) && !CKey::push(VK_LEFT) && !CKey::push(VK_RIGHT) && mVelocity > 0 
		&& !mEnabledJump && mVelocity != 0 && !mEnabledAttack){
		mVelocity -= SLOW_DOWN;
		DecisionRL(E_BRAKE_R, E_BRAKE_L);
	}
	else if (mVelocity <= 0){
		mVelocity = 0;
	}
	mPos += mForward * mVelocity;
	mAxis += mForward.y * mVelocity;
}

/*NormalAttackメソッド*/
void CPlayer::PlayerAttack(){
	//通常攻撃 アニメ切り替え
	switch (mStatus)
	{
	case E_NORMALATTACK_A_R:				//1段階目
	case E_NORMALATTACK_A_L:
		if (mAnimeFrame != FRAME_LIMIT - 1){ mEnabledAttack = true; }
		else{ //アニメ最後が来たら
			mEnabledAttack = false;
			if (FrameTime(INTERVAL)){
				mEnabledInterval = true;
				if (CKey::once('X')){
					mAnimeFrame = 0;
					mEnabledAttack = true;
					DecisionRL(E_NORMALATTACK_B_R, E_NORMALATTACK_B_L);
				}
			}
			else{
				mEnabledInterval = false;
			}
		}
		Attack(ATTACK_A);
		break;
	case E_NORMALATTACK_B_R:				//2段階目
	case E_NORMALATTACK_B_L:
		if (mAnimeFrame != FRAME_LIMIT - 1){ mEnabledAttack = true; }
		else{ //アニメ最後が来たら
			mEnabledAttack = false;			 // 攻撃判定を消す　
			if (FrameTime(INTERVAL)){		//Interval
				mEnabledInterval = true;    //キー入力待ち
				if (CKey::once('X')){		
					mAnimeFrame = 0;
					mEnabledAttack = true;
					DecisionRL(E_NORMALATTACK_C_R, E_NORMALATTACK_C_L);
				}
			}
			else{
				mEnabledInterval = false;
			}
		}
		
		Attack(ATTACK_B);
		break;
	case E_NORMALATTACK_C_R:				//3段階目
	case E_NORMALATTACK_C_L:
		mRect.SetVertex(SIZE_ATTACT_C);
		if (mAnimeFrame != FRAME_LIMIT - 1){ mEnabledAttack = true; }
		else{ //アニメ最後が来たら
			mRect.SetVertex(-SIZE_PLAYER_X, SIZE_PLAYER_Y, SIZE_PLAYER_X, -SIZE_PLAYER_X);
			mEnabledAttack = false;
			mEnabledInterval = false;

		}
		Attack(ATTACK_C);
		break;
	case E_JUMPATTACK_R:
	case E_JUMPATTACK_L:
		if (mAnimeFrame != FRAME_LIMIT - 1){
			mEnabledAttack = true;
			mEnabledJumpAttack = true;
		}
		else{ //アニメ最後が来たら
			mEnabledAttack = false;
			mEnabledJumpAttack = false;
		}
		Attack(ATTACK_JUMP);
		AtJumpAnime();
		break;
	case E_EAT_R:
	case E_EAT_L:
		if (mAnimeFrame != FRAME_LIMIT3 - 1){ mEnabledAttack = true; }
		else{ //アニメ最後が来たら
			mEnabledAttack = false;
			mEnabledEat = false;
		}
		Attack(EAT_ATTACK);
		break;
	case E_EX01_L:
	case E_EX01_R:
		
		if (mSaveForword.x == RIGHT || mSaveForword.x == 0){ mEx01Speed += EX01_SPEED; }
		if (mSaveForword.x == LEFT){ mEx01Speed -= EX01_SPEED; }
		if (mAnimeFrame != FRAME_LIMIT8 - 1){ mEnabledAttack = true; }
		else{ //アニメ最後が来たら
			mEx01Speed = 0;
			mEnabledAttack = false;
			mEnabledEx01 = false;
		}
		Attack(EX01_ATTACK);
		break;
	default:
		mEnabledAttack = false;
		mEnabledInterval = false;
		if (mStatus != E_BRAKE_R && mStatus != E_BRAKE_L){ //ブレーキがかかっていないとき
			/*通常攻撃 攻撃力の設定 フラグを真に*/
			if (CKey::once('X') && !mEnabledAttack){

					mAttackPoint = PL_NORMAL_POWER;
					mAnimeFrame = 0;
					mAttackPoint = mAttackPoint *mHungryPower;
					mEnabledAttack = true;
					DecisionRL(E_NORMALATTACK_A_R, E_NORMALATTACK_A_L);
					if (mEnabledJump){


						mAttackPoint = PL_JUMP_AT_POWER;
						mAnimeFrame = 0;
						mAttackPoint = mAttackPoint *mHungryPower;
						mEnabledAttack = true;
						mEnabledJumpAttack = true;
						DecisionRL(E_JUMPATTACK_R, E_JUMPATTACK_L);
					}
			}
			/*捕食攻撃 攻撃力の設定 フラグを真に*/
			if (CKey::once('Z') && !mEnabledAttack){
				mAttackPoint = PL_EAT_POWER;		
				mAnimeFrame = 0;
				mAttackPoint = mAttackPoint *mHungryPower;
				mEnabledAttack = true;
				mEnabledEat = true;
				DecisionRL(E_EAT_R, E_EAT_L);
			}
			/*必殺技(消費)*/
			if (CKey::once('A') && mStamina >= PL_ST_X *0.1){
				mAnimeFrame = 0;
				mAttackPoint = PL_EX01_POWER;
				mStamina -= PL_ST_X*0.1f;
				mAttackPoint = mAttackPoint *mHungryPower;
				mEnabledAttack = true;
				mEnabledEx01 = true;
				DecisionRL(E_EX01_R, E_EX01_L);
			}
		}
		break;
	};
}

/*
(アニメーション)未実装のもの
BRAKE,EX02,
NORMALATAKKU_,C
FLERM
*/
#define FRAME_CUTDOWN 2 //↓斬撃アニメFRAME
#define FRAME_CUTRETURN 4//斬撃アニメ返り
#define FRAME_CUTUP 5

void CPlayer::AtJumpAnime(){
	if (mAnimeFrame == FRAME_CUTDOWN){
		if (mForward.x == LEFT){ mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutJumpTex, SIZE_TEX_CUTJUMP_X, 0, 0, SIZE_TEX_CUTJUMP_Y); }//斬撃()
		if (mForward.x == RIGHT){ mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutJumpTex, 0, 0, SIZE_TEX_CUTJUMP_X, SIZE_TEX_CUTJUMP_Y); }//斬撃()
	}
	if (mAnimeFrame == FRAME_CUTRETURN){
		if (mForward.x == RIGHT){ mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutJumpTex, SIZE_TEX_CUTJUMP_X, 0, 0, SIZE_TEX_CUTJUMP_Y); }//斬撃()
		if (mForward.x == LEFT){ mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutJumpTex, 0, 0, SIZE_TEX_CUTJUMP_X, SIZE_TEX_CUTJUMP_Y); }//斬撃()
	}
	if (mAnimeFrame == FRAME_CUTUP){
		if (mForward.x == RIGHT){ mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutJumpTex, SIZE_TEX_CUTJUMP_X, SIZE_TEX_CUTJUMP_Y,0 , 0); }//斬撃()
		if (mForward.x == LEFT){ mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutJumpTex, 0, SIZE_TEX_CUTJUMP_Y, SIZE_TEX_CUTJUMP_X, 0); }//斬撃()
	}
}
/*アニメーションシーン*/
void CPlayer::AnimeScene(){
	
	/*アニメーションのステータス*/
	switch (mStatus)
	{
		/*左*/
	case E_STAY_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadPlayer::GetInstance()->mStayTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_WALK_L:
		AnimeFrame(true, ANIME_TIME_WALK,FRAME_LIMIT8);
		mRect.SetUv(CLoadPlayer::GetInstance()->mWalkTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_RUN_L:
		AnimeFrame(true, ANIME_TIME_BASE,FRAME_LIMIT8);
		mRect.SetUv(CLoadPlayer::GetInstance()->mRunTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_A_L:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mNormalAttackTex[0][mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_B_L:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mNormalAttackTex[1][mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_C_L:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mNormalAttackTex[2][mAnimeFrame], SIZE_TEX_PLAYER_AT_C_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_JUMPATTACK_L:
		AnimeFrame(false, ANIME_TIME_JUMPATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mJumpAttackTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EAT_L:
		AnimeFrame(false, ANIME_TIME_EAT, FRAME_LIMIT3);
		mRect.SetUv(CLoadPlayer::GetInstance()->mEatTex[mAnimeFrame], SIZE_TEX_EAT, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX01_L:
		AnimeFrame(false, ANIME_TIME_EX01, FRAME_LIMIT8);
		mRect.SetUv(CLoadPlayer::GetInstance()->mEx01Tex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX02_L:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mEx02Tex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_FLAME_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadPlayer::GetInstance()->mFlameTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_JUMP_L://特殊なのでジャンプメソッドで処理
		mRect.SetUv(CLoadPlayer::GetInstance()->mJumpTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_BRAKE_L:
		AnimeFrame(false, ANIME_TIME_BRAKE,FRAME_LIMIT2);
		mRect.SetUv(CLoadPlayer::GetInstance()->mBrakeTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
		/*右*/
	case E_STAY_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadPlayer::GetInstance()->mStayTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_WALK_R:
		AnimeFrame(true, ANIME_TIME_WALK,FRAME_LIMIT8);
		mRect.SetUv(CLoadPlayer::GetInstance()->mWalkTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_RUN_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadPlayer::GetInstance()->mRunTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_A_R:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mNormalAttackTex[0][mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_B_R:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mNormalAttackTex[1][mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_C_R:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mNormalAttackTex[2][mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_JUMPATTACK_R:
		AnimeFrame(false, ANIME_TIME_JUMPATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mJumpAttackTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EAT_R:
		AnimeFrame(false, ANIME_TIME_ATTACK,FRAME_LIMIT3);

		mRect.SetUv(CLoadPlayer::GetInstance()->mEatTex[mAnimeFrame], 0, 0, SIZE_TEX_EAT, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX01_R:
		AnimeFrame(false, ANIME_TIME_EX01, FRAME_LIMIT8);
		mRect.SetUv(CLoadPlayer::GetInstance()->mEx01Tex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX02_R:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mEx02Tex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_FLAME_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadPlayer::GetInstance()->mFlameTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_JUMP_R://特殊なのでジャンプメソッドで処理
		mRect.SetUv(CLoadPlayer::GetInstance()->mJumpTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_AT_C_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_BRAKE_R:
		AnimeFrame(false, ANIME_TIME_BRAKE,FRAME_LIMIT2);
		mRect.SetUv(CLoadPlayer::GetInstance()->mBrakeTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	};
	
	if (!mEnabledJumpAttack){
		if (mForward.x == LEFT){ mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutFlyTex, SIZE_TEX_CUTFLY_X, 0, 0, SIZE_TEX_CUTFLY_Y); }//斬撃()
		if (mForward.x == RIGHT){ mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutFlyTex, 0, 0, SIZE_TEX_CUTFLY_X, SIZE_TEX_CUTFLY_Y); }//斬撃()
	}
}
/*能力変化のメソッド*/
void CPlayer::ChangeStatus(){

	/*ヒットポイント処理*/
	/*スタミナ処理*/
	if (mStamina <= PL_ST_X && mStamina >= 0){	  //減っていく
		mStamina -= HUNGRY_SPEED; 

		/*ステータス変化*/
		if (HUNGRY_S_HIGH_IF){ 
			mHungryPower = HUNGRY_POWER_LOW; mHungrySSpp = HUNGRY_SSPP_LOW; //おなか一杯減少
			mHungryStatus = E_HIGH;
		} 
		else if (HUNGRY_S_LOW_IF){ 
			mHungryPower = HUNGRY_POWER_HIGH; mHungrySSpp = HUNGRY_SSPP_HIGH;//おなかすいた上昇
			mRect.triangle1.r = 0.4f;
			mRect.triangle2.r = 0.4f;
			mRect.triangle1.g = 0.4f;
			mRect.triangle2.g = 0.4f;
			mHungryStatus = E_LOW;
		}
		else{									 //中間 変化なし
			mHungryPower = 0; mHungrySSpp = 0;
			mHungryStatus = E_NORMAL;
		}
		/*ステータス変化終了*/
	} 
	else{										 //多すぎる場合
		mStamina = PL_ST_X; 
	} 
	if (mStamina <= 0){							 //すくなすぎる場合
		mStamina = 0;							 //これ以上スタミナを減らさないようにする
		mHitPoint -= HUNGRY_SPEED;
	}
	

}

/*アップデート*/
void CPlayer::Update() {
	assert(mAnimeFrame <= FRAME_LIMIT8);				//フレーム数が七を超えるとダメ
	//assert(E_STAY_L <= mStatus && mStatus <= E_BRAKE_R);       //テクスチャを正しく読み込めているかどうか
	//四角形の位置を設定
	mAttackRange.position = mPos;
	if (mHitPoint > 0){ //HPがあるとき
		mRect.position = mPos;
		if (!mEnabledAttack){ Move(); }	//移動メソッド
		Brake();						//ブレーキメソッド
		Jump();							//ジャンプメソッド
		PlayerAttack();					//アタックメソッド
		AnimeScene();					//アニメメソッド
		AlertHPRect(&mRect, mHitPoint);	//アラートメソッド(HP変化によるもの)
		ChangeStatus();					//能力変化メソッド
	}
	if (!mEnabledInterval && mStatus != E_STAY_L && mStatus != E_STAY_R && mVelocity <= 0 && !mEnabledJump && !mEnabledAttack){
		DecisionRL(E_STAY_R, E_STAY_L);
	}

	LimitDisp(SIZE_PLAYER_X, SIZE_PLAYER_Y);

	mPriorityR = -mAxis;
	camera_x = mPos.x;
	camera_y = mPos.y;
	mRect.position = mPos;
	mShadow.position = CVector2(mPos.x, mAxis);

	const float fade_speed = 0.01f;
	if (mHitPoint <= 0) {
		//シーンゲームオーバーいこう
		CGame::FadeOut(fade_speed,&mRect);
	}
	if (mRect.triangle1.a <= 0){ //フェードアウトが終了したらKILLする
		mKillFlag = true;
	}
}


void CPlayer::Render(){
	//プレイヤーの描画
	mShadow.Render();
	mRect.Render();
	if (mEnabledAttack && !mEnabledEat){
		mAttackRange.Render();
	}
	

}
