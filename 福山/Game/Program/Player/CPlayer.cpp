#include "CPlayer.h"
#include "../Key/CKey.h"
#include "../MyNumber/CMyNumber.h"
#include "../CGame/CGame.h"
#define JUMP_FIRST_SPEED				0.2f								//�W�����v�̃W�����v��
#define FIRST_R_NO_PL					0.0f								//���߂̃����_�[�̃|�C���g
#define FIRST_U_NO_PL					0.0f								//���߂̃A�b�v�f�[�g�̃|�C���g
#define SIZE_TEX_PLAYER_BASE_X			-160.0f								//�v���C���[�̊�{�I�ȃe�N�X�`���T�C�Y X
#define SIZE_TEX_PLAYER_BASE_Y			160.0f								//�v���C���[�̊�{�I�ȃe�N�X�`���T�C�Y Y
#define SLOW_DOWN						 0.005f								//�ړ��̌����X�s�[�h
#define WALK_SPEED						 0.05f								//�����X�s�[�h
#define RUN_SPEED						 0.1f								//����X�s�[�h
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
#define TEX_FILE_PLAYER_JUMP			 "../CG\\beru\\beru_jump\\"			//�v���C���[�̃t�@�C���ꏊ�@�W�����v
#define V2_RIGHT						 CVector2(WALK_X, 0.0f)				//�E�̌���
#define V2_LEFT							 CVector2(-WALK_X, 0.0f)			//���̌���
#define V2_TOP							 CVector2(0.0f, WALK_Y)				//��̌���
#define V2_BOTTOM						 CVector2(0.0f, -WALK_Y)			//���̌���
#define ANIME_TIME_BASE						10								//�A�j���̃��[�v���� �p���I�Ȃ���
#define ANIME_TIME_ATTACK					8								//�A�j���̃��[�v���� �U���̂���
#define ANIME_TIME_BRAKE					7								//�A�j���̃��[�v���� BRAKE
#define ANIME_TIME_JUMP						6								//�A�j�����[�v����
#define RIGHT WALK_X														//�E
#define LEFT -WALK_X														//��
#define ATTACK_A		mForward.x, SIZE_PLAYER_X, SIZE_PLAYER_Y,2, mPos	//�U���͈�A
#define ATTACK_B		mForward.x, SIZE_PLAYER_X, SIZE_PLAYER_Y,2, mPos	//�U���͈�B
#define ATTACK_C		mForward.x, SIZE_PLAYER_X, SIZE_PLAYER_Y,3, mPos	//�U���͈�C
#define EAT_ATTACK		mForward.x, SIZE_PLAYER_X, SIZE_PLAYER_Y,1, mPos	//�H�ׂ�U��
#define EX01_ATTACK		mForward.x, SIZE_PLAYER_X, SIZE_PLAYER_Y+mEx01Speed,3, CVector2(mPos.x+mEx01Speed,mPos.y) //�K�E�Z�͈�
#define EX01_SPEED 0.1f														//�K�E�Z���i�ރX�s�[�h
#define INTERVAL		100.0f												//�U�����INTERVAL�L�[���͑҂�����
#define HUNGRY_SPEED	0.001f												//���Ȃ�������X�s�[�h
#define HUNGRY_SSPP_HIGT	WALK_SPEED*0.1f									//���Ȃ��������ăX�s�[�h���オ��@+=�@���Ďg������
#define HUNGRY_SSPP_LOW		WALK_SPEED*0.1f									//���Ȃ��������ς�����ɂ��� 	+=�@���Ďg����
#define HUNGRY_POWER_HIGH	0.1f											//���Ȃ��������ė͂��o��@+=���Ďg������
#define HUNGRY_POWER_LOW	-0.1f											//���Ȃ��������ς��͂��o�Ȃ��@+=���Ďg������

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
		mJumpTex[i] = new CTexture();			//�e�N�X�`���N���X�̃C���X�^���X�쐬

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
	///*�K�E�Z(�p��)*/
	//mEx02Tex[0]->load(TEX_FILE_PLAYER_EX02"beru_EX02_00.tga");
	//mEx02Tex[1]->load(TEX_FILE_PLAYER_EX02"beru_EX02_01.tga");
	//mEx02Tex[2]->load(TEX_FILE_PLAYER_EX02"beru_EX02_02.tga");
	//mEx02Tex[3]->load(TEX_FILE_PLAYER_EX02"beru_EX02_03.tga");
	//mEx02Tex[4]->load(TEX_FILE_PLAYER_EX02"beru_EX02_04.tga");
	//mEx02Tex[5]->load(TEX_FILE_PLAYER_EX02"beru_EX02_05.tga");
	mJumpTex[0]->load(TEX_FILE_PLAYER_JUMP"beru_jump_00.tga");
	mJumpTex[1]->load(TEX_FILE_PLAYER_JUMP"beru_jump_01.tga");
	mJumpTex[2]->load(TEX_FILE_PLAYER_JUMP"beru_jump_02.tga");
	mJumpTex[3]->load(TEX_FILE_PLAYER_JUMP"beru_jump_03.tga");
	mJumpTex[4]->load(TEX_FILE_PLAYER_JUMP"beru_jump_04.tga");
	mJumpTex[5]->load(TEX_FILE_PLAYER_JUMP"beru_jump_05.tga");
	/*�u���[�L*/
	mBrakeTex[0]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_00.tga");
	mBrakeTex[1]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_01.tga");
	mBrakeTex[2]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_02.tga");
	mBrakeTex[3]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_03.tga");
	mBrakeTex[4]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_04.tga");
	mBrakeTex[5]->load(TEX_FILE_PLAYER_BRAKE"beru_brake_05.tga");
	///*��*/
	//mFlameTex[0]->load(TEX_FILE_PLAYER_FLAME"beru_flame_00.tga");
	//mFlameTex[1]->load(TEX_FILE_PLAYER_FLAME"beru_flame_01.tga");
	//mFlameTex[2]->load(TEX_FILE_PLAYER_FLAME"beru_flame_02.tga");
	//mFlameTex[3]->load(TEX_FILE_PLAYER_FLAME"beru_flame_03.tga");
	//mFlameTex[4]->load(TEX_FILE_PLAYER_FLAME"beru_flame_04.tga");
	//mFlameTex[5]->load(TEX_FILE_PLAYER_FLAME"beru_flame_05.tga");
	///*�e*/
	mShadowTex->load(TEX_FILE_SHADOW"shadow.tga");

	/*�e�N�X�`���𒣂�*/
	mRect.SetUv(mStayTex[0], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
	mShadow.SetUv(mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mForward = CVector2(1.0f, 0.0f);
}



CPlayer::~CPlayer() {
	

	//�e�N�X�`���ǂݍ���
	for (int i = 0; i < FRAME_LIMIT; i++)
	{
		CGame::Delete( &mStayTex[i]);
		CGame::Delete( &mWalkTex[i]);
		CGame::Delete( &mRunTex[i]);
		CGame::Delete( &mEx01Tex[i]);			//�e�N�X�`���N���X�̃C���X�^���X�쐬
		CGame::Delete( &mEx02Tex[i]);			//�e�N�X�`���N���X�̃C���X�^���X�쐬
		CGame::Delete( &mEatTex[i]);
		CGame::Delete( &mFlameTex[i]);
		CGame::Delete( &mBrakeTex[i]);
		CGame::Delete(& mJumpTex[i]);
		for (int z = 0; z < NORMALATTACK_PATTERN; z++)
		{
			CGame::Delete(&mNormalAttackTex[z][i]);	//�e�N�X�`���N���X�̃C���X�^���X�쐬
		}
		CGame::Delete(&mEatTex[i]);

	}

}

//�v���C���[�`��
CPlayer::CPlayer() : mVelocity(0), mSpeedJump(JUMP_FIRST_SPEED),mEnabledInterval(false){

	for (int i = 0; i < FRAME_LIMIT; i++)
	{
		mStayTex[i] = 0;
	}
	mCharaFlag = true;
	mPriorityR = E_PLAYER;			//Render�̃i���o�[ 
	mPriorityU = E_PLAYER;			//Update�̃i���o�[
	mHitPoint = PL_HP_X;		//�g�o
	mStamina = PL_ST_X;			//ST
	mMyNumber = E_PLAYER;
	mStatus = E_STAY_R,
	//�l�p�`�̒��_�ݒ�
	mRect.SetVertex(-SIZE_PLAYER_X, SIZE_PLAYER_Y, SIZE_PLAYER_X, -SIZE_PLAYER_Y);
	mShadow.SetVertex(-SIZE_SHADOW_X, SIZE_SHADOW_Y, SIZE_SHADOW_X, -SIZE_SHADOW_Y);
	//�l�p�`�̐F��ݒ�
	mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mShadow.SetColor(0.5f, 0.5f, 0.5f, 0.7f);

}
/*���E���f*/
void CPlayer::DecisionRL(int R, int L){
	if (mSaveForword.x == RIGHT || mSaveForword.x == 0){ mStatus = R; }
	if (mSaveForword.x == LEFT){ mStatus = L; }
	mAnimeFrame = 0;
}
/*�W�����v���\�b�h*/
void CPlayer::Jump(){ //�W�����v�������\�b�h
	/*
	�v�Z
	y = y + v(���Ԃɂ��i�񂾋���)
	�d�͌v�Z
	v = v0 + g*t(�ǂꂭ�炢�d�͂�����������)
	*/
	if (CKey::push('C') && !mEnabledJump && !mEnabledAttack) {
		mSpeedJump = JUMP_FIRST_SPEED;
		mEnabledJump = true; //�W�����v���Ă��Ȃ��Ƃ�
	}

	if (mEnabledJump){
		mPos.y = mPos.y + mSpeedJump; //��ԏ���
		mSpeedJump -= gravity;//��������
		DecisionRL(E_JUMP_R, E_JUMP_L);

		if (mPos.y < mAxis + SIZE_PLAYER_Y){//���݂̎��ɑ��������Ƃ�
			DecisionRL(E_STAY_R,E_STAY_L);
			mPos.y = mAxis + SIZE_PLAYER_Y; //�������n�ʂ�"Y"�ɖ߂�
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
	else{				//�����Ƃ�
		mVelocity = WALK_SPEED;
		DecisionRL(E_WALK_R, E_WALK_L);
	}
	
	mForward = v;
	mPos += mForward * (mVelocity+mHungrySSpp);
	mAxis += mForward.y * mVelocity;
}

/*�ړ����̃��\�b�h*/
void CPlayer::Move(){
	CVector2 SavemPos = mPos;		//�ʒu�ۑ�
	float  SavemAxis = mAxis;		//�ʒu�ۑ�
	// �E�ړ�
	if (CKey::push(RIGHT_KEY)) {
		mStatus = E_WALK_R;
		RunWalk(V2_RIGHT);
		mSaveForword = V2_RIGHT;
	}
	//���ړ�
	if (CKey::push(LEFT_KEY)) {
		mStatus = E_WALK_L;
		RunWalk(V2_LEFT);
		mSaveForword = V2_LEFT;
	}
	//��ړ�
	if (CKey::push(UP_KEY)) { 
		RunWalk(V2_TOP);
	}
	//���ړ�
	if (CKey::push(DOWN_KEY)) {
		RunWalk(V2_BOTTOM);
	}
	if (mAxis > character_limit_top - SIZE_PLAYER_Y ||
		mAxis + SIZE_PLAYER_Y < character_limit_bottom + SIZE_PLAYER_Y){ //��
		mPos = SavemPos;
		mAxis = SavemAxis;
	}
}

/*�u���[�L���\�b�h*/
void CPlayer::Brake(){
	//�u���[�L��������Ƃ�(����Ȃ������Ȃ��W�����v���Ȃ�)
	if (!CKey::push(VK_DOWN) && !CKey::push(VK_UP) && !CKey::push(VK_LEFT) && !CKey::push(VK_RIGHT) && mVelocity > 0 
		&& !mEnabledJump && mVelocity != 0 && !mEnabledAttack){
		mVelocity -= SLOW_DOWN;
		DecisionRL(E_BRAKE_R, E_BRAKE_L);
	}
	else if (mVelocity <= 0){
		if (!mEnabledInterval)DecisionRL(E_STAY_R, E_STAY_L);
		mVelocity = 0;
	}
	mPos += mForward * mVelocity;
	mAxis += mForward.y * mVelocity;
}
/*NormalAttack���\�b�h*/
void CPlayer::PlayerAttack(){
	//�ʏ�U�� �A�j���؂�ւ�
	switch (mStatus)
	{
	case E_NORMALATTACK_A_R:				//1�i�K��
	case E_NORMALATTACK_A_L:
		if (mAnimeFrame != FRAME_LIMIT - 1){ mEnabledAttack = true; }
		else{ //�A�j���Ōオ������
			mEnabledAttack = false;
			if (FrameTime(INTERVAL)){
				mEnabledInterval = true;
				if (CKey::once('X')){
					mEnabledAttack = true;
					DecisionRL(E_NORMALATTACK_B_R, E_NORMALATTACK_B_L);
				}
			}
			else{
				mEnabledInterval = false;
				DecisionRL(E_STAY_R, E_STAY_L);
			}
		}
		Attack(ATTACK_A);
		break;
	case E_NORMALATTACK_B_R:				//2�i�K��
	case E_NORMALATTACK_B_L:
		if (mAnimeFrame != FRAME_LIMIT - 1){ mEnabledAttack = true; }
		else{ //�A�j���Ōオ������
			mEnabledAttack = false;			 // �U������������@
			if (FrameTime(INTERVAL)){		//Interval
				mEnabledInterval = true;    //�L�[���͑҂�
				if (CKey::once('X')){		
					mEnabledAttack = true;
					DecisionRL(E_NORMALATTACK_C_R, E_NORMALATTACK_C_L);
				}
			}
			else{
				mEnabledInterval = false;
				DecisionRL(E_STAY_R, E_STAY_L);
			}
		}
		
		Attack(ATTACK_B);
		break;
	case E_NORMALATTACK_C_R:				//3�i�K��
	case E_NORMALATTACK_C_L:
		if (mAnimeFrame != FRAME_LIMIT - 1){ mEnabledAttack = true; }
		else{ //�A�j���Ōオ������
			DecisionRL(E_STAY_R, E_STAY_L);
			mEnabledAttack = false;
			mEnabledInterval = false;

		}
		Attack(ATTACK_C);
		break;
	case E_EAT_R:
	case E_EAT_L:
		if (mAnimeFrame != FRAME_LIMIT - 1){ mEnabledAttack = true; }
		else{ //�A�j���Ōオ������
			DecisionRL(E_STAY_R, E_STAY_L);
			mEnabledAttack = false;
			mEnabledEat = false;
		}
		Attack(EAT_ATTACK);
		break;
	case E_EX01_L:
	case E_EX01_R:

		if (mSaveForword.x == RIGHT || mSaveForword.x == 0){ mEx01Speed += EX01_SPEED; }
		if (mSaveForword.x == LEFT){ mEx01Speed -= EX01_SPEED; }
		if (mAnimeFrame != FRAME_LIMIT - 1){ mEnabledAttack = true; }
		else{ //�A�j���Ōオ������
			mEx01Speed = 0;
			DecisionRL(E_STAY_R, E_STAY_L);
			mEnabledAttack = false;
			mEnabledEx01 = false;
		}
		Attack(EX01_ATTACK);
		break;
	default:
		mEnabledAttack = false;
		mEnabledInterval = false;
		if (mStatus != E_BRAKE_R && mStatus != E_BRAKE_L){ //�u���[�L���������Ă��Ȃ��Ƃ�
			/*�ʏ�U�� �U���͂̐ݒ� �t���O��^��*/
			if (CKey::once('X') && !mEnabledAttack){
				mAttackPoint = PL_NORMAL_POWER;
				mAttackPoint += mHungryPower;
				mEnabledAttack = true;
				DecisionRL(E_NORMALATTACK_A_R, E_NORMALATTACK_A_L);
			}
			/*�ߐH�U�� �U���͂̐ݒ� �t���O��^��*/
			if (CKey::once('Z') && !mEnabledAttack){
				mAttackPoint = PL_EAT_POWER;
				mAttackPoint += mHungryPower;
				mEnabledAttack = true;
				mEnabledEat = true;
				DecisionRL(E_EAT_R, E_EAT_L);
			}
			/*�K�E�Z(����)*/
			if (CKey::once('A') && mStamina >= PL_ST_X *0.1){
				mAttackPoint = PL_EX01_POWER;
				mStamina -= PL_ST_X*0.1f;
				mAttackPoint += mHungryPower;
				mEnabledAttack = true;
				mEnabledEx01 = true;
				DecisionRL(E_EX01_R, E_EX01_L);
			}
		}
		break;
	};
}

/*�A�j���[�V�����V�[��*/
void CPlayer::AnimeScene(){
	/*�A�j���[�V�����̃X�e�[�^�X*/
	switch (mStatus)
	{
		/*��*/
	case E_STAY_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(mStayTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_WALK_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(mWalkTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_RUN_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(mRunTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_A_L:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(mNormalAttackTex[0][mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_B_L:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(mNormalAttackTex[1][mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_C_L:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(mNormalAttackTex[2][mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EAT_L:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(mEatTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX01_L:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(mEx01Tex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX02_L:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(mEx02Tex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_FLAME_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(mFlameTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_JUMP_L:
		AnimeFrame(false,ANIME_TIME_JUMP);
		mRect.SetUv(mJumpTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
	case E_BRAKE_L:
		AnimeFrame(false, ANIME_TIME_BRAKE);
		mRect.SetUv(mBrakeTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
		/*�E*/
	case E_STAY_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(mStayTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_WALK_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(mWalkTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_RUN_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(mRunTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_A_R:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(mNormalAttackTex[0][mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X ,SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_B_R:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(mNormalAttackTex[1][mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_C_R:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(mNormalAttackTex[2][mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EAT_R:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(mEatTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX01_R:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(mEx01Tex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX02_R:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(mEx02Tex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_FLAME_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(mFlameTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_JUMP_R:
		AnimeFrame(false, ANIME_TIME_JUMP);
		mRect.SetUv(mJumpTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
	case E_BRAKE_R:
		AnimeFrame(false, ANIME_TIME_BRAKE);
		mRect.SetUv(mBrakeTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	};
}
/*�\�͕ω��̃��\�b�h*/
void CPlayer::ChangeStatus(){

	/*�q�b�g�|�C���g����*/
	/*�X�^�~�i����*/
	if (mStamina <= PL_ST_X && mStamina >= 0){	 //�����Ă���
		mStamina -= HUNGRY_SPEED; 

		/*�X�e�[�^�X�ω�*/
		if (mStamina >= PL_ST_X*0.7f){ //���Ȃ��������ς��X�e�[�^�X
			mHungryPower = HUNGRY_POWER_LOW; mHungrySSpp = HUNGRY_SSPP_LOW; 
		} 
		else if (mStamina <= PL_ST_X*0.2){ //���Ȃ����������X�e�[�^�X
			mHungryPower = HUNGRY_POWER_HIGH; mHungrySSpp = HUNGRY_POWER_HIGH;
		}
		else{									//���� �ω��Ȃ�
			mHungryPower = 0; mHungrySSpp = 0;
		}
		/*�X�e�[�^�X�ω��I��*/
	} 
	else{										 //��������ꍇ
		mStamina = PL_ST_X; 
	} 
	if (mStamina <= 0){							 //�����Ȃ�����ꍇ
		mStamina = 0;							 //����ȏ�X�^�~�i�����炳�Ȃ��悤�ɂ���
		mHitPoint -= HUNGRY_SPEED;
	}
	

}

/*�A�b�v�f�[�g*/
void CPlayer::Update() {
	assert(mAnimeFrame <= FRAME_LIMIT);				//�t���[���������𒴂���ƃ_��
	assert(E_STAY_L <= mStatus && mStatus <= E_BRAKE_R);       //�e�N�X�`���𐳂����ǂݍ��߂Ă��邩�ǂ���
	//�l�p�`�̈ʒu��ݒ�
	mRect.position = mPos;
	printf("move%d\n", mStatus);
	if (!mEnabledAttack){Move();}
	//Brake();
	printf("brake%d\n", mStatus);

	PlayerAttack();
	Jump();
	ChangeStatus();
	AnimeScene();

	LimitDisp(SIZE_PLAYER_X, SIZE_PLAYER_Y);

	mPriorityR = -mAxis;
	camera_x = mPos.x;
	camera_y = mPos.y;

	mRect.position = mPos;
	mShadow.position = CVector2(mPos.x, mAxis);

	if (mHitPoint < 0) {
		//�V�[���Q�[���I�[�o�[
		mHitPoint = 0;
	}
}


void CPlayer::Render(){
	//�v���C���[�̕`��
	mShadow.Render();
	mRect.Render();
	if(mEnabledAttack)mAttackRange.Render();

}
