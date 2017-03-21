#include "CLoadPlayer.h"
#include "../CGame/CGame.h"
#define TEX_FILE_PLAYER_STAY			 "../CG\\beru\\beru_stay\\"			//�v���C���[�̃t�@�C���ꏊ�@�҂�
#define TEX_FILE_PLAYER_WALK			 "../CG\\beru\\beru_walk\\"			//�v���C���[�̃t�@�C���ꏊ�@�҂�
#define TEX_FILE_PLAYER_RUN				 "../CG\\beru\\beru_run\\"			//�v���C���[�̃t�@�C���ꏊ�@�҂�
#define TEX_FILE_PLAYER_NormalATTACK_A	 "../CG\\beru\\beru_attackA\\"		//�v���C���[�̃t�@�C���ꏊ�@�ʏ�U��A
#define TEX_FILE_PLAYER_NormalATTACK_B	 "../CG\\beru\\beru_attackB\\"		//�v���C���[�̃t�@�C���ꏊ�@�ʏ�U��B
#define TEX_FILE_PLAYER_NormalATTACK_C	 "../CG\\beru\\beru_attackC\\"		//�v���C���[�̃t�@�C���ꏊ�@�ʏ�U��C
#define TEX_FILE_PLAYER_EX01			 "../CG\\beru\\beru_EX01\\"			//�v���C���[�̃t�@�C���ꏊ�@����
#define TEX_FILE_PLAYER_EX02			 "../CG\\beru\\beru_EX02\\"			//�v���C���[�̃t�@�C���ꏊ�@�p��
#define TEX_FILE_PLAYER_EAT				 "../CG\\beru\\beru_eat\\"			//�v���C���[�̃t�@�C���ꏊ�@�ߐH
#define TEX_FILE_PLAYER_FLAME			 "../CG\\beru\\beru_flame\\"		//�v���C���[�̃t�@�C���ꏊ�@��(�I�[��)
#define TEX_FILE_PLAYER_BRAKE			 "../CG\\beru\\beru_brake\\"		//�v���C���[�̃t�@�C���ꏊ�@�u���[�L
#define TEX_FILE_PLAYER_JUMP			 "../CG\\beru\\beru_jump\\"			//�v���C���[�̃t�@�C���ꏊ�@�W�����v
#define TEX_FILE_SHADOW					 "../CG/shadow/"					//�e�e�N�X�`���ꏊ
#define TEX_FILE_CUTFLY					 "../CG\\beru\\beru_Effect\\"			//�K�E�Z��Ԃ悤

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


	/*�e�N�X�`���ǂݍ���*/
	for (int i = 0; i < FRAME_LIMIT; i++)
	{
		mStayTex[i] = new CTexture();			//�e�N�X�`���N���X�̃C���X�^���X�쐬
		mEx01Tex[i] = new CTexture();			//�e�N�X�`���N���X�̃C���X�^���X�쐬
		mEx02Tex[i] = new CTexture();			//�e�N�X�`���N���X�̃C���X�^���X�쐬
		mEatTex[i] = new CTexture();			//�e�N�X�`���N���X�̃C���X�^���X�쐬
		mFlameTex[i] = new CTexture();			//�e�N�X�`���N���X�̃C���X�^���X�쐬
		mBrakeTex[i] = new CTexture();			//�e�N�X�`���N���X�̃C���X�^���X�쐬
		for (int z = 0; z < NORMALATTACK_PATTERN; z++)
		{
			mNormalAttackTex[z][i] = new CTexture();	//�e�N�X�`���N���X�̃C���X�^���X�쐬
		}
		mEatTex[i] = new CTexture();

	}
	for (int i = 0; i < FRAME_LIMIT8; i++)
	{
		mRunTex[i] = new CTexture();			//�e�N�X�`���N���X�̃C���X�^���X�쐬
		mWalkTex[i] = new CTexture();			//�e�N�X�`���N���X�̃C���X�^���X�쐬
	}
	for (int i = 0; i < 3; i++)//JUMP�@EAT
	{
		mJumpTex[i] = new CTexture();			//�e�N�X�`���N���X�̃C���X�^���X�쐬

	}

	mShadowTex = new CTexture();		//�e�N�X�`���N���X�̃C���X�^���X�쐬
	mCutFlyTex = new CTexture();
	/*�e�N�X�`���t�@�C���ǂݍ���*/
	/*�҂�*/
	mStayTex[0]->load(TEX_FILE_PLAYER_STAY"beru_stay_00.tga");
	mStayTex[1]->load(TEX_FILE_PLAYER_STAY"beru_stay_01.tga");
	mStayTex[2]->load(TEX_FILE_PLAYER_STAY"beru_stay_02.tga");
	mStayTex[3]->load(TEX_FILE_PLAYER_STAY"beru_stay_03.tga");
	mStayTex[4]->load(TEX_FILE_PLAYER_STAY"beru_stay_04.tga");
	mStayTex[5]->load(TEX_FILE_PLAYER_STAY"beru_stay_05.tga");

	/*����*/
	mWalkTex[0]->load(TEX_FILE_PLAYER_WALK"beru_walk_00.tga");
	mWalkTex[1]->load(TEX_FILE_PLAYER_WALK"beru_walk_01.tga");
	mWalkTex[2]->load(TEX_FILE_PLAYER_WALK"beru_walk_02.tga");
	mWalkTex[3]->load(TEX_FILE_PLAYER_WALK"beru_walk_03.tga");
	mWalkTex[4]->load(TEX_FILE_PLAYER_WALK"beru_walk_04.tga");
	mWalkTex[5]->load(TEX_FILE_PLAYER_WALK"beru_walk_05.tga");
	mWalkTex[6]->load(TEX_FILE_PLAYER_WALK"beru_walk_06.tga");
	mWalkTex[7]->load(TEX_FILE_PLAYER_WALK"beru_walk_07.tga");
	/*����*/
	mRunTex[0]->load(TEX_FILE_PLAYER_RUN"beru_run_00.tga");
	mRunTex[1]->load(TEX_FILE_PLAYER_RUN"beru_run_01.tga");
	mRunTex[2]->load(TEX_FILE_PLAYER_RUN"beru_run_02.tga");
	mRunTex[3]->load(TEX_FILE_PLAYER_RUN"beru_run_03.tga");
	mRunTex[4]->load(TEX_FILE_PLAYER_RUN"beru_run_04.tga");
	mRunTex[5]->load(TEX_FILE_PLAYER_RUN"beru_run_05.tga");
	mRunTex[6]->load(TEX_FILE_PLAYER_RUN"beru_run_06.tga");
	mRunTex[7]->load(TEX_FILE_PLAYER_RUN"beru_run_07.tga");
	/*�ʏ�A*/
	mNormalAttackTex[0][0]->load(TEX_FILE_PLAYER_NormalATTACK_A"beru_attackA_00.tga");
	mNormalAttackTex[0][1]->load(TEX_FILE_PLAYER_NormalATTACK_A"beru_attackA_01.tga");
	mNormalAttackTex[0][2]->load(TEX_FILE_PLAYER_NormalATTACK_A"beru_attackA_02.tga");
	mNormalAttackTex[0][3]->load(TEX_FILE_PLAYER_NormalATTACK_A"beru_attackA_03.tga");
	mNormalAttackTex[0][4]->load(TEX_FILE_PLAYER_NormalATTACK_A"beru_attackA_04.tga");
	mNormalAttackTex[0][5]->load(TEX_FILE_PLAYER_NormalATTACK_A"beru_attackA_05.tga");
	/*�ʏ�B*/
	mNormalAttackTex[1][0]->load(TEX_FILE_PLAYER_NormalATTACK_B"beru_attackB_00.tga");
	mNormalAttackTex[1][1]->load(TEX_FILE_PLAYER_NormalATTACK_B"beru_attackB_01.tga");
	mNormalAttackTex[1][2]->load(TEX_FILE_PLAYER_NormalATTACK_B"beru_attackB_02.tga");
	mNormalAttackTex[1][3]->load(TEX_FILE_PLAYER_NormalATTACK_B"beru_attackB_03.tga");
	mNormalAttackTex[1][4]->load(TEX_FILE_PLAYER_NormalATTACK_B"beru_attackB_04.tga");
	mNormalAttackTex[1][5]->load(TEX_FILE_PLAYER_NormalATTACK_B"beru_attackB_05.tga");
	/*�ʏ�C*/
	mNormalAttackTex[2][0]->load(TEX_FILE_PLAYER_NormalATTACK_C"beru_attackC_00.tga");
	mNormalAttackTex[2][1]->load(TEX_FILE_PLAYER_NormalATTACK_C"beru_attackC_01.tga");
	mNormalAttackTex[2][2]->load(TEX_FILE_PLAYER_NormalATTACK_C"beru_attackC_02.tga");
	mNormalAttackTex[2][3]->load(TEX_FILE_PLAYER_NormalATTACK_C"beru_attackC_03.tga");
	mNormalAttackTex[2][4]->load(TEX_FILE_PLAYER_NormalATTACK_C"beru_attackC_04.tga");
	mNormalAttackTex[2][5]->load(TEX_FILE_PLAYER_NormalATTACK_C"beru_attackC_05.tga");
	/*�ߐH*/
	mEatTex[0]->load(TEX_FILE_PLAYER_EAT"beru_eat_00.tga");
	mEatTex[1]->load(TEX_FILE_PLAYER_EAT"beru_eat_01.tga");
	mEatTex[2]->load(TEX_FILE_PLAYER_EAT"beru_eat_02.tga");
	/*�K�E�Z(����)*/
	mEx01Tex[0]->load(TEX_FILE_PLAYER_EX01"beru_EX01_00.tga");
	mEx01Tex[1]->load(TEX_FILE_PLAYER_EX01"beru_EX01_01.tga");
	mEx01Tex[2]->load(TEX_FILE_PLAYER_EX01"beru_EX01_02.tga");
	mEx01Tex[3]->load(TEX_FILE_PLAYER_EX01"beru_EX01_03.tga");
	mEx01Tex[4]->load(TEX_FILE_PLAYER_EX01"beru_EX01_04.tga");
	mEx01Tex[5]->load(TEX_FILE_PLAYER_EX01"beru_EX01_05.tga");
	/*�W�����v*/
	mJumpTex[0]->load(TEX_FILE_PLAYER_JUMP"beru_jump_00.tga");
	mJumpTex[1]->load(TEX_FILE_PLAYER_JUMP"beru_jump_01.tga");
	mJumpTex[2]->load(TEX_FILE_PLAYER_JUMP"beru_jump_02.tga");
	/*�u���[�L*/
	mBrakeTex[0]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_00.tga");
	mBrakeTex[1]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_01.tga");
	mBrakeTex[2]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_02.tga");
	mBrakeTex[3]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_03.tga");
	mBrakeTex[4]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_04.tga");
	mBrakeTex[5]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_05.tga");
	/*�e*/
	mShadowTex->load(TEX_FILE_SHADOW"shadow.tga");
	/*��Ԏa��*/
	mCutFlyTex->load(TEX_FILE_CUTFLY"CutFlyEffect.tga");
}

CLoadPlayer::~CLoadPlayer()
{

	//�e�N�X�`���ǂݍ���
	for (int i = 0; i < FRAME_LIMIT; i++)
	{
		CGame::Delete(&mStayTex[i]);
		CGame::Delete(&mWalkTex[i]);
		CGame::Delete(&mRunTex[i]);
		CGame::Delete(&mEx01Tex[i]);
		CGame::Delete(&mEx02Tex[i]);
		CGame::Delete(&mEatTex[i]);
		CGame::Delete(&mFlameTex[i]);
		CGame::Delete(&mBrakeTex[i]);
		CGame::Delete(&mJumpTex[i]);
		for (int z = 0; z < NORMALATTACK_PATTERN; z++)
		{
			CGame::Delete(&mNormalAttackTex[z][i]);
		}
		CGame::Delete(&mEatTex[i]);
	}
	CGame::Delete(&mShadowTex);
	CGame::Delete(&mCutFlyTex);
}