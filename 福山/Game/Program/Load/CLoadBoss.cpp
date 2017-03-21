#include "CLoadBoss.h"
#include "../CGame/CGame.h"
#define BOSS_STAY 	 "../CG\\BOSS\\stay\\"
#define BOSS_WALK	 "../CG\\BOSS\\walk\\"
#define BOSS_ATTACK	 "../CG\\BOSS\\Attack\\"
#define BOSS_HATTACK "../CG\\BOSS\\HAttack\\"
#define BOSS_DIE	 "../CG\\BOSS\\die\\"


CLoadBoss* CLoadBoss::mLoadBoss = 0;

//GetInstance
CLoadBoss* CLoadBoss::GetInstance() {
	if (mLoadBoss == 0) {
		mLoadBoss = new CLoadBoss();
	}
	return mLoadBoss;
}


CLoadBoss::CLoadBoss(){
	/*テクスチャ読み込み*/
	for (int i = 0; i < FRAME_LIMIT; i++)
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

	mWalk_tex[0]->load(BOSS_WALK"BOSS_walk_00.tga");
	mWalk_tex[1]->load(BOSS_WALK"BOSS_walk_01.tga");
	mWalk_tex[2]->load(BOSS_WALK"BOSS_walk_02.tga");
	mWalk_tex[3]->load(BOSS_WALK"BOSS_walk_03.tga");
	mWalk_tex[4]->load(BOSS_WALK"BOSS_walk_04.tga");
	mWalk_tex[5]->load(BOSS_WALK"BOSS_walk_05.tga");

	mAttack_tex[0]->load(BOSS_ATTACK"BOSS_Attack_00.tga");
	mAttack_tex[1]->load(BOSS_ATTACK"BOSS_Attack_01.tga");
	mAttack_tex[2]->load(BOSS_ATTACK"BOSS_Attack_02.tga");
	mAttack_tex[3]->load(BOSS_ATTACK"BOSS_Attack_03.tga");
	mAttack_tex[4]->load(BOSS_ATTACK"BOSS_Attack_04.tga");
	mAttack_tex[5]->load(BOSS_ATTACK"BOSS_Attack_05.tga");
	/*未実装*/
/*
	mHattack_tex[0]->load(BOSS_HATTACK"BOSS_HAttack_00.tga");
	mHattack_tex[1]->load(BOSS_HATTACK"BOSS_HAttack_01.tga");
	mHattack_tex[2]->load(BOSS_HATTACK"BOSS_HAttack_02.tga");
	mHattack_tex[3]->load(BOSS_HATTACK"BOSS_HAttack_03.tga");
	mHattack_tex[4]->load(BOSS_HATTACK"BOSS_HAttack_04.tga");
	mHattack_tex[5]->load(BOSS_HATTACK"BOSS_HAttack_05.tga");*/


	mDie_tex[0]->load(BOSS_DIE"BOSS_die_0.tga");
	mDie_tex[1]->load(BOSS_DIE"BOSS_die_1.tga");
	mDie_tex[2]->load(BOSS_DIE"BOSS_die_2.tga");
	mDie_tex[3]->load(BOSS_DIE"BOSS_die_3.tga");
	mDie_tex[4]->load(BOSS_DIE"BOSS_die_4.tga");
	mDie_tex[5]->load(BOSS_DIE"BOSS_die_5.tga");

}
CLoadBoss::~CLoadBoss(){

	//テクスチャ読み込み
	for (int i = 0; i < FRAME_LIMIT; i++)
	{
		CGame::Delete(&mStay_tex[i]);
		CGame::Delete(&mWalk_tex[i]);
		CGame::Delete(&mAttack_tex[i]);
		CGame::Delete(&mHattack_tex[i]);
		CGame::Delete(&mDie_tex[i]);

	}
}