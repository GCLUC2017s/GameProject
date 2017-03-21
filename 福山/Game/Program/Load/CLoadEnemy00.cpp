#include "CLoadEnemy00.h"
#include "../CGame/CGame.h"

#define HITPOINT_ENEMY00 5					//�G�l�~�[00�̗̑�
#define FIRST_R_NO_PL 1						//���߂̃����_�[�̃|�C���g
#define FIRST_U_NO_PL 1						//���߂̃A�b�v�f�[�g�̃|�C���g
#define SIZE_TEX_ENEMY00_STAY_X 80			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y X
#define SIZE_TEX_ENEMY00_STAY_Y 80			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y Y
#define SIZE_TEX_ENEMY00_WALK_X 80			//�G�l�~�[�̕����e�N�X�`���T�C�Y Y
#define SIZE_TEX_ENEMY00_WALK_Y 80			//�G�l�~�[�̕����p�e�N�X�`���T�C�Y Y
#define SIZE_SHADOW							//�e�̕\��
#define SLOW_DOWN 0.001f						//�ړ��̌����X�s�[�h
#define PATTERN_R 1							//PATTERN�̉E
#define PATTERN_L 2							//PATTERN�̍�

#define WALK_SPEED 0.02f				//�����X�s�[�h
#define WALK_X 2						//�����x�N�g��X
#define WALK_Y 1						//�����x�N�g��Y

#define ENEMY00_STAY "../CG\\enemy00\\enemy00_stay\\"
#define ENEMY00_WALK "../CG\\enemy00\\enemy00_walk\\"
#define ENEMY00_ATTACK "../CG\\enemy00\\enemy00_attack\\"

#define ENEMY00_DIE "../CG\\enemy00\\enemy00_die\\"


CLoadEnemy00* CLoadEnemy00::mLoadEnemy00 = 0;

//GetInstance
CLoadEnemy00* CLoadEnemy00::GetInstance() {
	if (mLoadEnemy00 == 0) {
		mLoadEnemy00 = new CLoadEnemy00();
	}
	return mLoadEnemy00;
}

CLoadEnemy00::CLoadEnemy00()
{

	/*�e�N�X�`���ǂݍ���*/
	for (int i = 0; i < FRAME_LIMIT; i++)
	{
		mStay_tex[i] = new CTexture();		//�e�N�X�`���N���X�̃C���X�^���X�쐬
		mWalk_tex[i] = new CTexture();		//�e�N�X�`���N���X�̃C���X�^���X�쐬
		mAttack_tex[i] = new CTexture();		//�e�N�X�`���N���X�̃C���X�^���X�쐬
		mDie_tex[i] = new CTexture();
	}

	/*�e�N�X�`���t�@�C���ǂݍ���*/
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

	mDie_tex[0]->load(ENEMY00_DIE"enemy00_die_00.tga");
	mDie_tex[1]->load(ENEMY00_DIE"enemy00_die_01.tga");
	mDie_tex[2]->load(ENEMY00_DIE"enemy00_die_02.tga");
	mDie_tex[3]->load(ENEMY00_DIE"enemy00_die_03.tga");
	mDie_tex[4]->load(ENEMY00_DIE"enemy00_die_04.tga");
	mDie_tex[5]->load(ENEMY00_DIE"enemy00_die_05.tga");


}

CLoadEnemy00::~CLoadEnemy00()
{

	//�e�N�X�`���ǂݍ���
	for (int i = 0; i < FRAME_LIMIT; i++)
	{
		CGame::Delete(&mStay_tex[i]);
		CGame::Delete(&mWalk_tex[i]);
		CGame::Delete(&mAttack_tex[i]);
		CGame::Delete(&mDie_tex[i]);

	}
}