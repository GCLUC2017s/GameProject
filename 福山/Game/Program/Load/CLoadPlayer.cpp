#include "CLoadPlayer.h"
#include "../CGame/CGame.h"
#define TEX_FILE_PLAYER_STAY			 "../CG\\beru\\beru_stay\\"			//プレイヤーのファイル場所　待ち
#define TEX_FILE_PLAYER_WALK			 "../CG\\beru\\beru_walk\\"			//プレイヤーのファイル場所　待ち
#define TEX_FILE_PLAYER_RUN				 "../CG\\beru\\beru_run\\"			//プレイヤーのファイル場所　待ち
#define TEX_FILE_PLAYER_NormalATTACK_A	 "../CG\\beru\\beru_attackA\\"		//プレイヤーのファイル場所　通常攻撃A
#define TEX_FILE_PLAYER_NormalATTACK_B	 "../CG\\beru\\beru_attackB\\"		//プレイヤーのファイル場所　通常攻撃B
#define TEX_FILE_PLAYER_NormalATTACK_C	 "../CG\\beru\\beru_attackC\\"		//プレイヤーのファイル場所　通常攻撃C
#define TEX_FILE_PLAYER_JUMPATTACK	     "../CG\\beru\\beru_attackJ\\"		//プレイヤーのファイル場所　ジャンプ攻撃
#define TEX_FILE_PLAYER_EX01			 "../CG\\beru\\beru_EX01\\"			//プレイヤーのファイル場所　消費
#define TEX_FILE_PLAYER_EX02			 "../CG\\beru\\beru_EX02\\"			//プレイヤーのファイル場所　継続
#define TEX_FILE_PLAYER_EAT				 "../CG\\beru\\beru_eat\\"			//プレイヤーのファイル場所　捕食
#define TEX_FILE_PLAYER_FLAME			 "../CG\\beru\\beru_flame\\"		//プレイヤーのファイル場所　炎(オーラ)
#define TEX_FILE_PLAYER_BRAKE			 "../CG\\beru\\beru_brake\\"		//プレイヤーのファイル場所　ブレーキ
#define TEX_FILE_PLAYER_JUMP			 "../CG\\beru\\beru_jump\\"			//プレイヤーのファイル場所　ジャンプ
#define TEX_FILE_SHADOW					 "../CG/shadow/"					//影テクスチャ場所
#define TEX_FILE_CUTFLY					 "../CG\\beru\\beru_Effect\\"			//必殺技飛ぶよう

CLoadPlayer* CLoadPlayer::mLoadPlayer = 0;

//GetInstance
CLoadPlayer* CLoadPlayer::GetInstance() {
	if (mLoadPlayer == 0) {
		mLoadPlayer = new CLoadPlayer();
	}
	return mLoadPlayer;
}

CLoadPlayer::CLoadPlayer()
{


	/*テクスチャ読み込み*/
	for (int i = 0; i < FRAME_LIMIT; i++)
	{
		mStayTex[i] = new CTexture();			//テクスチャクラスのインスタンス作成
		mEx01Tex[i] = new CTexture();			//テクスチャクラスのインスタンス作成
		mEx02Tex[i] = new CTexture();			//テクスチャクラスのインスタンス作成
		mFlameTex[i] = new CTexture();			//テクスチャクラスのインスタンス作成
		mBrakeTex[i] = new CTexture();			//テクスチャクラスのインスタンス作成
		mJumpAttackTex[i] =  new CTexture();			//テクスチャクラスのインスタンス作成
		for (int z = 0; z < NORMALATTACK_PATTERN; z++)
		{
			mNormalAttackTex[z][i] = new CTexture();	//テクスチャクラスのインスタンス作成
		}
	}
	for (int i = 0; i < FRAME_LIMIT8; i++)
	{
		mRunTex[i] = new CTexture();			//テクスチャクラスのインスタンス作成
		mWalkTex[i] = new CTexture();			//テクスチャクラスのインスタンス作成
		mEx01Tex[i] = new CTexture();			//テクスチャクラスのインスタンス作成
	}
	for (int i = 0; i < FRAME_LIMIT3; i++)
	{
		mJumpTex[i] = new CTexture();			//テクスチャクラスのインスタンス作成
		mEatTex[i] = new CTexture();			//テクスチャクラスのインスタンス作成
	}

	mShadowTex = new CTexture();		//テクスチャクラスのインスタンス作成
	mCutFlyTex = new CTexture();
	mCutJumpTex = new CTexture();

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
	mWalkTex[6]->load(TEX_FILE_PLAYER_WALK"beru_walk_06.tga");
	mWalkTex[7]->load(TEX_FILE_PLAYER_WALK"beru_walk_07.tga");
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
	
	/*ジャンプATTACK*/
	mJumpAttackTex[0]->load(TEX_FILE_PLAYER_JUMPATTACK"beru_attackJ_00.tga");
	mJumpAttackTex[1]->load(TEX_FILE_PLAYER_JUMPATTACK"beru_attackJ_01.tga");
	mJumpAttackTex[2]->load(TEX_FILE_PLAYER_JUMPATTACK"beru_attackJ_02.tga");
	mJumpAttackTex[3]->load(TEX_FILE_PLAYER_JUMPATTACK"beru_attackJ_03.tga");
	mJumpAttackTex[4]->load(TEX_FILE_PLAYER_JUMPATTACK"beru_attackJ_04.tga");
	mJumpAttackTex[5]->load(TEX_FILE_PLAYER_JUMPATTACK"beru_attackJ_05.tga");
	/*捕食*/
	mEatTex[0]->load(TEX_FILE_PLAYER_EAT"beru_eat_00.tga");
	mEatTex[1]->load(TEX_FILE_PLAYER_EAT"beru_eat_01.tga");
	mEatTex[2]->load(TEX_FILE_PLAYER_EAT"beru_eat_02.tga");
	/*必殺技(消費)*/
	mEx01Tex[0]->load(TEX_FILE_PLAYER_EX01"beru_EX01_00.tga");
	mEx01Tex[1]->load(TEX_FILE_PLAYER_EX01"beru_EX01_01.tga");
	mEx01Tex[2]->load(TEX_FILE_PLAYER_EX01"beru_EX01_02.tga");
	mEx01Tex[3]->load(TEX_FILE_PLAYER_EX01"beru_EX01_03.tga");
	mEx01Tex[4]->load(TEX_FILE_PLAYER_EX01"beru_EX01_04.tga");
	mEx01Tex[5]->load(TEX_FILE_PLAYER_EX01"beru_EX01_05.tga");
	mEx01Tex[6]->load(TEX_FILE_PLAYER_EX01"beru_EX01_06.tga");
	mEx01Tex[7]->load(TEX_FILE_PLAYER_EX01"beru_EX01_07.tga");
	/*ジャンプ*/
	mJumpTex[0]->load(TEX_FILE_PLAYER_JUMP"beru_jump_00.tga");
	mJumpTex[1]->load(TEX_FILE_PLAYER_JUMP"beru_jump_01.tga");
	mJumpTex[2]->load(TEX_FILE_PLAYER_JUMP"beru_jump_02.tga");
	/*ブレーキ*/
	mBrakeTex[0]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_00.tga");
	mBrakeTex[1]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_01.tga");
	/*影*/
	mShadowTex->load(TEX_FILE_SHADOW"shadow.tga");
	/*飛ぶ斬撃*/
	mCutFlyTex->load(TEX_FILE_CUTFLY"CutFlyEffect.tga");
	mCutJumpTex->load(TEX_FILE_CUTFLY"CutJumpEffect.tga");
}

CLoadPlayer::~CLoadPlayer()
{

	//テクスチャ読み込み
	for (int i = 0; i < FRAME_LIMIT8; i++)//8フレームのもの
	{
		if (i < FRAME_LIMIT3){ //3フレームのもの
			CGame::Delete(&mJumpTex[i]);
			CGame::Delete(&mEatTex[i]);
		}
		if (i < FRAME_LIMIT){//6fフレームのもの
			CGame::Delete(&mStayTex[i]);
			CGame::Delete(&mEx02Tex[i]);
			CGame::Delete(&mFlameTex[i]);
			CGame::Delete(&mBrakeTex[i]);
			CGame::Delete(&mJumpAttackTex[i]);
			for (int z = 0; z < NORMALATTACK_PATTERN; z++) //3段階のもの
			{
				CGame::Delete(&mNormalAttackTex[z][i]);
			}
		}
		//ここから8
		CGame::Delete(&mRunTex[i]);
		CGame::Delete(&mWalkTex[i]);
		CGame::Delete(&mEx01Tex[i]);
	}
	CGame::Delete(&mShadowTex);
	CGame::Delete(&mCutFlyTex);
	CGame::Delete(&mCutJumpTex);
}