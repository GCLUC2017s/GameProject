#include "CLoadEnemy01.h"
#include "../CGame/CGame.h"
#define ENEMY01_Fly "../CG\\enemy01\\walk\\"
#define ENEMY01_STAY "../CG\\enemy01\\stay\\"
#define ENEMY01_ATTACK "../CG\\enemy01\\attack\\"
#define ENEMY01_DIE "../CG\\enemy01\\die\\"

CLoadEnemy01* CLoadEnemy01::mLoadEnemy01 = 0;

//GetInstance
CLoadEnemy01* CLoadEnemy01::GetInstance() {
	if (mLoadEnemy01 == 0) {
		mLoadEnemy01 = new CLoadEnemy01();
	}
	return mLoadEnemy01;
}

CLoadEnemy01::CLoadEnemy01(){
	/*テクスチャ読み込み*/
	for (int i = 0; i < FRAME_LIMIT; i++)
	{
		mStay_tex[i] = new CTexture();		//テクスチャクラスのインスタンス作成
		mFly_tex[i] = new CTexture();		//テクスチャクラスのインスタンス作成

	}
	for (int i = 0; i < FRAME_LIMIT9; i++){
		mAttack_tex[i] = new CTexture();

	}
	for (int i = 0; i < FRAME_LIMIT11; i++)
	{
		mDie_tex[i] = new CTexture();
	}
	/*テクスチャファイル読み込み*/
	mStay_tex[0]->load(ENEMY01_STAY"enemy01_stay_00.tga");
	mStay_tex[1]->load(ENEMY01_STAY"enemy01_stay_01.tga");
	mStay_tex[2]->load(ENEMY01_STAY"enemy01_stay_02.tga");
	mStay_tex[3]->load(ENEMY01_STAY"enemy01_stay_03.tga");
	mStay_tex[4]->load(ENEMY01_STAY"enemy01_stay_04.tga");
	mStay_tex[5]->load(ENEMY01_STAY"enemy01_stay_05.tga");

	mFly_tex[0]->load(ENEMY01_Fly"enemy01_walk_00.tga");
	mFly_tex[1]->load(ENEMY01_Fly"enemy01_walk_01.tga");
	mFly_tex[2]->load(ENEMY01_Fly"enemy01_walk_02.tga");
	mFly_tex[3]->load(ENEMY01_Fly"enemy01_walk_03.tga");
	mFly_tex[4]->load(ENEMY01_Fly"enemy01_walk_04.tga");
	mFly_tex[5]->load(ENEMY01_Fly"enemy01_walk_05.tga");

	mAttack_tex[0]->load(ENEMY01_ATTACK"enemy01_attack_00.tga");
	mAttack_tex[1]->load(ENEMY01_ATTACK"enemy01_attack_01.tga");
	mAttack_tex[2]->load(ENEMY01_ATTACK"enemy01_attack_02.tga");
	mAttack_tex[3]->load(ENEMY01_ATTACK"enemy01_attack_03.tga");
	mAttack_tex[4]->load(ENEMY01_ATTACK"enemy01_attack_04.tga");
	mAttack_tex[5]->load(ENEMY01_ATTACK"enemy01_attack_05.tga");
	mAttack_tex[6]->load(ENEMY01_ATTACK"enemy01_attack_06.tga");
	mAttack_tex[7]->load(ENEMY01_ATTACK"enemy01_attack_07.tga");
	mAttack_tex[8]->load(ENEMY01_ATTACK"enemy01_attack_08.tga");

	mDie_tex[0]->load(ENEMY01_DIE"enemy01_die_00.tga");
	mDie_tex[1]->load(ENEMY01_DIE"enemy01_die_01.tga");
	mDie_tex[2]->load(ENEMY01_DIE"enemy01_die_02.tga");
	mDie_tex[3]->load(ENEMY01_DIE"enemy01_die_03.tga");
	mDie_tex[4]->load(ENEMY01_DIE"enemy01_die_04.tga");
	mDie_tex[5]->load(ENEMY01_DIE"enemy01_die_05.tga");
	mDie_tex[6]->load(ENEMY01_DIE"enemy01_die_06.tga");
	mDie_tex[7]->load(ENEMY01_DIE"enemy01_die_07.tga");
	mDie_tex[8]->load(ENEMY01_DIE"enemy01_die_08.tga");
	mDie_tex[9]->load(ENEMY01_DIE"enemy01_die_09.tga");
	mDie_tex[10]->load(ENEMY01_DIE"enemy01_die_10.tga");
}

CLoadEnemy01::~CLoadEnemy01()
{

	//テクスチャ読み込み
	for (int i = 0; i < FRAME_LIMIT; i++)
	{
		CGame::Delete(&mStay_tex[i]);
		CGame::Delete(&mFly_tex[i]);
	}
	for (int i = 0; i < FRAME_LIMIT9; i++)
	{
		CGame::Delete(&mAttack_tex[i]);
	}
	for (int i = 0; i < FRAME_LIMIT11; i++)
	{
		CGame::Delete(&mDie_tex[i]);
	}
}