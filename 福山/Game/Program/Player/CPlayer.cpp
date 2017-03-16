#include "CPlayer.h"
#include "../Key/CKey.h"
#include "../MyNumber/CMyNumber.h"
#include "../CGame/CGame.h"
#define JUMP_FIRST_SPEED				0.2f								//�W�����v�̃W�����v��
#define HITPOINT_PLAYER					10.0f								//�v���C���[�̗̑�
#define FIRST_R_NO_PL					0.0f								//���߂̃����_�[�̃|�C���g
#define FIRST_U_NO_PL					0.0f								//���߂̃A�b�v�f�[�g�̃|�C���g

#define SIZE_TEX_PLAYER_BASE_X			800.0f								//�v���C���[�̊�{�I�ȃe�N�X�`���T�C�Y X
#define SIZE_TEX_PLAYER_BASE_Y			800.0f								//�v���C���[�̊�{�I�ȃe�N�X�`���T�C�Y Y

#define SLOW_DOWN						 0.01f								//�ړ��̌����X�s�[�h
#define WALK_SPEED						 0.1f								//�����X�s�[�h
#define RUN_SPEED						 0.2f								//����X�s�[�h
#define WALK_X							 1.0f								//�����x�N�g��X
#define WALK_Y							 0.5f								//�����x�N�g��Y
#define PATTERN_R						 1.0f								//PATTERN�̉E
#define PATTERN_L						 2.0f								//PATTERN�̍�
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
#define V2_RIGHT						 CVector2(WALK_X, 0.0f)				//�E�̌���
#define V2_LEFT							 CVector2(-WALK_X, 0.0f)			//���̌���
#define V2_TOP							 CVector2(0.0f, WALK_Y)				//��̌���
#define V2_BOTTOM						 CVector2(0.0f, -WALK_Y)			//���̌���
#define ANIME_TIME_BASE						10								//�A�j���̃��[�v���� �p���I�Ȃ���
#define ANIME_TIME_ATTACK					8								//�A�j���̃��[�v���� �U���̂���
#define ANIME_TIME_BRAKE					7								//�A�j���̃��[�v���� BRAKE

float CPlayer::camera_x;
float CPlayer::camera_y;


void CPlayer::SetPos(){
	CPlayer::mpPlayer = this;
	mPos = first_pos;
	mAxis = mPos.y - SIZE_PLAYER_Y;

}


void CPlayer::Init() {
	SetPos();
	camera_x = mPos.x;
	camera_y = mPos.y;
	/*�e�N�X�`���ǂݍ���*/
	for (int i = 0; i < FRAME_LIMIT; i++)
	{
		mStayTex[i] = new CTexture();			//�e�N�X�`���N���X�̃C���X�^���X�쐬
		mWalkTex[i] = new CTexture();			//�e�N�X�`���N���X�̃C���X�^���X�쐬
		mRunTex[i] = new CTexture();			//�e�N�X�`���N���X�̃C���X�^���X�쐬
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

	mShadowTex = new CTexture();		//�e�N�X�`���N���X�̃C���X�^���X�쐬

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
	/*����*/
	mRunTex[0]->load(TEX_FILE_PLAYER_RUN"beru_run_00.tga");
	mRunTex[1]->load(TEX_FILE_PLAYER_RUN"beru_run_01.tga");
	mRunTex[2]->load(TEX_FILE_PLAYER_RUN"beru_run_02.tga");
	mRunTex[3]->load(TEX_FILE_PLAYER_RUN"beru_run_03.tga");
	mRunTex[4]->load(TEX_FILE_PLAYER_RUN"beru_run_04.tga");
	mRunTex[5]->load(TEX_FILE_PLAYER_RUN"beru_run_05.tga");
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
	mEatTex[3]->load(TEX_FILE_PLAYER_EAT"beru_eat_03.tga");
	mEatTex[4]->load(TEX_FILE_PLAYER_EAT"beru_eat_04.tga");
	mEatTex[5]->load(TEX_FILE_PLAYER_EAT"beru_eat_05.tga");
	/*�K�E�Z(����)*/
	mEx01Tex[0]->load(TEX_FILE_PLAYER_EX01"beru_EX01_00.tga");
	mEx01Tex[1]->load(TEX_FILE_PLAYER_EX01"beru_EX01_01.tga");
	mEx01Tex[2]->load(TEX_FILE_PLAYER_EX01"beru_EX01_02.tga");
	mEx01Tex[3]->load(TEX_FILE_PLAYER_EX01"beru_EX01_03.tga");
	mEx01Tex[4]->load(TEX_FILE_PLAYER_EX01"beru_EX01_04.tga");
	mEx01Tex[5]->load(TEX_FILE_PLAYER_EX01"beru_EX01_05.tga");
	/*�K�E�Z(�p��)*/
	mEx02Tex[0]->load(TEX_FILE_PLAYER_EX02"beru_EX02_00.tga");
	mEx02Tex[1]->load(TEX_FILE_PLAYER_EX02"beru_EX02_01.tga");
	mEx02Tex[2]->load(TEX_FILE_PLAYER_EX02"beru_EX02_02.tga");
	mEx02Tex[3]->load(TEX_FILE_PLAYER_EX02"beru_EX02_03.tga");
	mEx02Tex[4]->load(TEX_FILE_PLAYER_EX02"beru_EX02_04.tga");
	mEx02Tex[5]->load(TEX_FILE_PLAYER_EX02"beru_EX02_05.tga");
	/*�u���[�L*/
	mBrakeTex[0]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_00.tga");
	mBrakeTex[1]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_01.tga");
	mBrakeTex[2]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_02.tga");
	mBrakeTex[3]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_03.tga");
	mBrakeTex[4]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_04.tga");
	mBrakeTex[5]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_05.tga");
	/*��*/
	mFlameTex[0]->load(TEX_FILE_PLAYER_FLAME"beru_flame_00.tga");
	mFlameTex[1]->load(TEX_FILE_PLAYER_FLAME"beru_flame_01.tga");
	mFlameTex[2]->load(TEX_FILE_PLAYER_FLAME"beru_flame_02.tga");
	mFlameTex[3]->load(TEX_FILE_PLAYER_FLAME"beru_flame_03.tga");
	mFlameTex[4]->load(TEX_FILE_PLAYER_FLAME"beru_flame_04.tga");
	mFlameTex[5]->load(TEX_FILE_PLAYER_FLAME"beru_flame_05.tga");
	/*�e*/
	mShadowTex->load(TEX_FILE_SHADOW"shadow.tga");

	/*�e�N�X�`���𒣂�*/
	mPlayer.SetUv(mStayTex[0], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
	mShadow.SetUv(mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mForward = CVector2(1.0f, 0.0f);
}
void CPlayer::Delete(CTexture *t){
	if (t){
		delete t;
		t = 0;
	}
}

CPlayer::~CPlayer() {

	/*�e�N�X�`���ǂݍ���*/
	for (int i = 0; i < FRAME_LIMIT; i++)
	{
		Delete(mStayTex[i]);
		Delete(mWalkTex[i]);
		Delete(mRunTex[i]);
		Delete(mEx01Tex[i]);			//�e�N�X�`���N���X�̃C���X�^���X�쐬
		Delete(mEx02Tex[i]);			//�e�N�X�`���N���X�̃C���X�^���X�쐬
		Delete(mEatTex[i]);
		Delete(mFlameTex[i]);
		Delete(mBrakeTex[i]);

		for (int z = 0; z < NORMALATTACK_PATTERN; z++)
		{
			Delete(mNormalAttackTex[z][i]);	//�e�N�X�`���N���X�̃C���X�^���X�쐬
		}
		Delete(mEatTex[i]);

	}
}

//�v���C���[�`��
CPlayer::CPlayer() : mVelocity(0), mEnabledNormalAttack(false), mSpeedJump(JUMP_FIRST_SPEED), mStatus(E_STAY_R), AnimePattern(E_BRAKE_R), mIntervalCount(0){

	for (int i = 0; i < FRAME_LIMIT; i++)
	{
		mStayTex[i] = 0;
	}

	mPriorityR = FIRST_R_NO_PL;			//Render�̃i���o�[ 
	mPriorityU = FIRST_U_NO_PL;			//Update�̃i���o�[
	mHitPoint = HITPOINT_PLAYER;		//�g�o
	mMyNumber = E_PLAYER;

	//�l�p�`�̒��_�ݒ�
	mPlayer.SetVertex(-SIZE_PLAYER_X, SIZE_PLAYER_Y, SIZE_PLAYER_X, -SIZE_PLAYER_Y);
	mShadow.SetVertex(-SIZE_SHADOW_X, SIZE_SHADOW_Y, SIZE_SHADOW_X, -SIZE_SHADOW_Y);
	//�l�p�`�̐F��ݒ�
	mPlayer.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mShadow.SetColor(0.5f, 0.5f, 0.5f, 0.7f);

}

/*�E�����f���\�b�h*/
void CPlayer::DecisionRL(int R, int L){
	if (mStatus  < AnimePattern / 2){
		(int)mStatus = R;
	}
	else
	{
		(int)mStatus = L;
	}
}
/*�W�����v���\�b�h*/
void CPlayer::Jump(){ //�W�����v�������\�b�h
	/*
	�v�Z
	y = y + v(���Ԃɂ��i�񂾋���)
	�d�͌v�Z
	v = v0 + g*t(�ǂꂭ�炢�d�͂�����������)
	*/
	if (CKey::push(' ') || mEnabledJump) {
		if (!mEnabledJump && !mEnabledNormalAttack)	mEnabledJump = true; //�W�����v���Ă��Ȃ��Ƃ�
	}

	if (mEnabledJump){
		mPos.y = mPos.y + mSpeedJump; //��ԏ���
		mSpeedJump -= gravity;//��������


		if (mPos.y < mAxis + SIZE_PLAYER_Y){//���݂̎��ɑ��������Ƃ�
			mPos.y = mAxis + SIZE_PLAYER_Y; //�������n�ʂ�"Y"�ɖ߂�
			mSpeedJump = JUMP_FIRST_SPEED;
			mEnabledJump = false; //�I��
		}
	}
}
/*���邩�ۂ����\�b�h*/
void CPlayer::RunWalk(CVector2 v){
	if (CKey::push(VK_CONTROL)){ //���鎞
		mVelocity = RUN_SPEED;
		DecisionRL(E_RUN_R, E_RUN_L);
	}
	else{				
			DecisionRL(E_WALK_R, E_WALK_L);
			mVelocity = WALK_SPEED;
	}
	
	mForward = v;
}
/*�A�j���̃t���[���𓮂������\�b�h*/ //�G�l�~�[�ɂ���ĈႤ�ꍇ������̂ŉ摜�f�[�^�p�Q��
void CPlayer::AnimeFrame(bool roop,int speed){
	if (roop){
		mFrameCount++;
		if (mFrameCount % speed == 0){
			mAnimeFrame++;
		}
		if (mAnimeFrame >= FRAME_LIMIT || mSaveAnime != mStatus){
			mAnimeFrame = 0;
		}
		mSaveAnime = mStatus;
	}
	else{						
		mFrameCount++;
		if (mFrameCount % speed == 0){
			mAnimeFrame++;
		}
		if (mAnimeFrame >= FRAME_LIMIT){
			mAnimeFrame = FRAME_LIMIT - 1; //�e�N�X�`���̍ő�l = FRAME_LIMIT�Ȃ̂� �[�P
		}
		mSaveAnime = mStatus;
	}
}
/*�ړ����̃��\�b�h*/
void CPlayer::Move(){
	CVector2 SavemPos = mPos;		//�ʒu�ۑ�
	float  SavemAxis = mAxis;		//�ʒu�ۑ�
	// �E�ړ�
	if (CKey::push(VK_RIGHT)) {
		(int)mStatus = E_WALK_R;
		RunWalk(V2_RIGHT);
	}
	//���ړ�
	if (CKey::push(VK_LEFT)) {
		(int)mStatus = E_WALK_L;
		RunWalk(V2_LEFT);
	}
	//��ړ�
	if (CKey::push(VK_UP)) { //��������ɒB���Ă��Ȃ��Ƃ�
		RunWalk(V2_TOP);
	}
	//���ړ�
	if (CKey::push(VK_DOWN)) {//��������ɒB���Ă��Ȃ��Ƃ�
		RunWalk(V2_BOTTOM);
	}

	//BRAKE
	Brake();
	if (mAxis > character_limit_top - SIZE_PLAYER_Y){ //��
		mPos = SavemPos;
		mAxis = SavemAxis;
	}
	else{
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;
	}
}
	

	
/*�u���[�L���\�b�h*/
void CPlayer::Brake(){
	//�u���[�L��������Ƃ�(����Ȃ������Ȃ��W�����v���Ȃ�)
	if (!CKey::push(VK_DOWN) && !CKey::push(VK_UP) && !CKey::push(VK_LEFT) && !CKey::push(VK_RIGHT) &&
		mVelocity > 0 && !mEnabledJump){
		mVelocity -= SLOW_DOWN;
		DecisionRL(E_BRAKE_R, E_BRAKE_L);
	}
	else if (mVelocity < 0){
		DecisionRL(E_STAY_R, E_STAY_L);
		mVelocity = 0;
	}
}
/*NormalAttack���\�b�h*/
void CPlayer::NormalAttack(){
	/*�͈�*/

	//�ʏ�U��
	if (CKey::push('X') && !mEnabledNormalAttack){
		mEnabledNormalAttack = true;
		DecisionRL(E_NORMALATTACK_A_L, E_NORMALATTACK_A_L);
	}


	if (mEnabledNormalAttack){//�U�����Ă���Ƃ�
		if (mAnimeFrame == FRAME_LIMIT - 1){
			mEnabledNormalAttack = false;//�U���I��
			DecisionRL(E_STAY_R, E_STAY_L);
		}
	}


}
/*�A�b�v�f�[�g*/
void CPlayer::Update() {
	assert(mAnimeFrame <= FRAME_LIMIT);				//�t���[���������𒴂���ƃ_��
	assert(E_STAY_L <= mStatus <= E_BRAKE_R);       //�e�N�X�`���𐳂����ǂݍ��߂Ă��邩�ǂ���
	//�l�p�`�̈ʒu��ݒ�
	mPlayer.position = mPos;

	if (!mEnabledNormalAttack)	Move(); 

	NormalAttack();

	Jump();

	/*�A�j���[�V�����̃X�e�[�^�X*/
	switch (mStatus)
	{
		/*��*/
	case E_STAY_L:
		AnimeFrame(true,ANIME_TIME_BASE);
		mPlayer.SetUv(mStayTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_WALK_L:
		AnimeFrame(true,ANIME_TIME_BASE);
		mPlayer.SetUv(mWalkTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_RUN_L:
		AnimeFrame(true,ANIME_TIME_BASE);
		mPlayer.SetUv(mRunTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_A_L:
		AnimeFrame(false,ANIME_TIME_ATTACK);
		mPlayer.SetUv(mNormalAttackTex[0][mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_B_L:
		AnimeFrame(false,ANIME_TIME_ATTACK);
		mPlayer.SetUv(mNormalAttackTex[1][mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_C_L:
		AnimeFrame(false,ANIME_TIME_ATTACK);
		mPlayer.SetUv(mNormalAttackTex[2][mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EAT_L:
		AnimeFrame(false,ANIME_TIME_ATTACK);
		mPlayer.SetUv(mEatTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX01_L:
		AnimeFrame(false,ANIME_TIME_ATTACK);
		mPlayer.SetUv(mEx01Tex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX02_L:
		AnimeFrame(false,ANIME_TIME_ATTACK);
		mPlayer.SetUv(mEx02Tex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_FLAME_L:
		AnimeFrame(true,ANIME_TIME_BASE);
		mPlayer.SetUv(mFlameTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_BRAKE_L:
		AnimeFrame(false,ANIME_TIME_BRAKE);
		mPlayer.SetUv(mBrakeTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
		/*�E*/
	case E_STAY_R:
		AnimeFrame(true,ANIME_TIME_BASE);
		mPlayer.SetUv(mStayTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_WALK_R:
		AnimeFrame(true,ANIME_TIME_BASE);
		mPlayer.SetUv(mWalkTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_RUN_R:
		AnimeFrame(true,ANIME_TIME_BASE);
		mPlayer.SetUv(mRunTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_A_R:
		AnimeFrame(false,ANIME_TIME_ATTACK);
		mPlayer.SetUv(mNormalAttackTex[0][mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_B_R:
		AnimeFrame(false,ANIME_TIME_ATTACK);
		mPlayer.SetUv(mNormalAttackTex[1][mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_C_R:
		AnimeFrame(false,ANIME_TIME_ATTACK);
		mPlayer.SetUv(mNormalAttackTex[2][mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EAT_R:
		AnimeFrame(false,ANIME_TIME_ATTACK);
		mPlayer.SetUv(mEatTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX01_R:
		AnimeFrame(false,ANIME_TIME_ATTACK);
		mPlayer.SetUv(mEx01Tex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX02_R:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mPlayer.SetUv(mEx02Tex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_FLAME_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mPlayer.SetUv(mFlameTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_BRAKE_R:
		AnimeFrame(false, ANIME_TIME_BRAKE);
		mPlayer.SetUv(mBrakeTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	};


	/*�����蔻��*/
	if (mAxis > character_limit_top - SIZE_PLAYER_Y && !mEnabledJump){  //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(��)
		mPos.y = character_limit_top;
		mAxis = mPos.y - SIZE_PLAYER_Y; //�������Ƃɖ߂�
	}
	if (mAxis + SIZE_PLAYER_Y < character_limit_bottom + SIZE_PLAYER_Y){  //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(��)
		mPos.y = character_limit_bottom+SIZE_PLAYER_Y;
		mAxis = mPos.y - SIZE_PLAYER_Y; //�������Ƃɖ߂�
	}

	if (mPos.x >= character_limit_right - SIZE_PLAYER_X || mPos.x <= character_limit_left + SIZE_PLAYER_X){ //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(X)
		mPos.x = mPlayer.position.x;
	}
	/*�����蔻��I��*/


	mPriorityR = -mAxis;
	camera_x = mPos.x;
	camera_y = mPos.y;

	mPlayer.position = mPos;
	mShadow.position = CVector2(mPos.x, mAxis);
}


void CPlayer::Render(){
	//�v���C���[�̕`��
	mShadow.Render();
	mPlayer.Render();

}
