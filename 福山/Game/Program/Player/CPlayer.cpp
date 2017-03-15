#include "CPlayer.h"
#include "../Key/CKey.h"
#include "../MyNumber/CMyNumber.h"
#define JUMP_FIRST_SPEED 0.2				//�W�����v�̃W�����v��
#define HITPOINT_PLAYER 10					//�v���C���[�̗̑�
#define FIRST_R_NO_PL 0						//���߂̃����_�[�̃|�C���g
#define FIRST_U_NO_PL 0						//���߂̃A�b�v�f�[�g�̃|�C���g
#define SIZE_TEX_PLAYER_STAY_X 800			//�v���C���[�̑҂��p�e�N�X�`���T�C�Y X
#define SIZE_TEX_PLAYER_STAY_Y 800			//�v���C���[�̑҂��p�e�N�X�`���T�C�Y Y
#define SIZE_TEX_PLAYER_WALK_X 800			//�v���C���[�̕����e�N�X�`���T�C�Y Y
#define SIZE_TEX_PLAYER_WALK_Y 800			//�v���C���[�̕����p�e�N�X�`���T�C�Y Y
#define SIZE_TEX_PLAYER_RUN_X  800			//�v���C���[�̑���p�e�N�X�`���T�C�Y Y
#define SIZE_TEX_PLAYER_RUN_Y  800			//�v���C���[�̑���p�e�N�X�`���T�C�Y Y
#define SLOW_DOWN 0.02						//�ړ��̌����X�s�[�h
#define WALK_SPEED 0.05						//�����X�s�[�h
#define RUN_SPEED 0.1						//����X�s�[�h
#define WALK_X 1							//�����x�N�g��X
#define WALK_Y 0.5							//�����x�N�g��Y
#define PATTERN_R 1							//PATTERN�̉E
#define PATTERN_L 2							//PATTERN�̍�
#define TEX_FILE_PLAYER_STAY			 "../CG\\beru\\beru_stay\\"		//�v���C���[�̃t�@�C���ꏊ�@�҂�
#define TEX_FILE_PLAYER_WALK			 "../CG\\beru\\beru_walk\\"		//�v���C���[�̃t�@�C���ꏊ�@�҂�
#define TEX_FILE_PLAYER_RUN				 "../CG\\beru\\beru_run\\"		//�v���C���[�̃t�@�C���ꏊ�@�҂�
#define TEX_FILE_PLAYER_NormalATTACK_A	 "../CG\\beru\\beru_attackA\\"	//�v���C���[�̃t�@�C���ꏊ�@�ʏ�U��A
#define TEX_FILE_PLAYER_NormalATTACK_B	 "../CG\\beru\\beru_attackB\\"	//�v���C���[�̃t�@�C���ꏊ�@�ʏ�U��B
#define TEX_FILE_PLAYER_NormalATTACK_C	 "../CG\\beru\\beru_attackC\\"	//�v���C���[�̃t�@�C���ꏊ�@�ʏ�U��C
#define TEX_FILE_PLAYER_EX01			 "../CG\\beru\\beru_EX01\\"		//�v���C���[�̃t�@�C���ꏊ�@����
#define TEX_FILE_PLAYER_EX02			 "../CG\\beru\\beru_EX02\\"		//�v���C���[�̃t�@�C���ꏊ�@�p��
#define TEX_FILE_PLAYER_EAT				 "../CG\\beru\\beru_eat\\"		//�v���C���[�̃t�@�C���ꏊ�@�ߐH
#define TEX_FILE_PLAYER_FLAME			 "../CG\\beru\\beru_flame\\"	//�v���C���[�̃t�@�C���ꏊ�@��
#define TEX_FILE_PLAYER_BRAKE			 "../CG\\beru\\beru_brake\\"	//�v���C���[�̃t�@�C���ꏊ�@�u���[�L

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
	mPlayer.SetUv(mStayTex[0], 0, 0, SIZE_TEX_PLAYER_STAY_X,SIZE_TEX_PLAYER_STAY_Y);
	mShadow.SetUv(mShadowTex, 0, 0, SIZE_SHADOW_X, SHADOW_TEX_Y);
	mForward = CVector2(1.0f, 0.0f);
}


CPlayer::~CPlayer() {

}

int CPlayer::DecisionRL(int i){
	if (i / 2  < AnimePattern){
		return  PATTERN_R;
	}
	else
	{
		return	PATTERN_L;
	}
}


//�v���C���[�`��
CPlayer::CPlayer() : mVelocity(0), mSpeedJump(JUMP_FIRST_SPEED),mFlameCount(0){

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
	mShadow.SetColor(0.0f, 0.0f, 0.0f, 0.0f);

}




void CPlayer::Jump(){ //�W�����v�������\�b�h

	mPos.y += mSpeedJump; //��ԏ���
	mSpeedJump -= gravity;//��������


	if (mPos.y < mAxis){//���݂̎��ɂ����Ƃ�
		mPos.y = mAxis; //�������n�ʂ�"Y"�ɖ߂�
		mSpeedJump = JUMP_FIRST_SPEED;
		mEnabledJump = false; //�I��

	}



}

void CPlayer::MovePosAxis(){
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;
}

/*�A�j���̃t���[���𓮂������\�b�h*/
void CPlayer::AnimeFlame(){

	mFlameCount += 1;
	if (mFlameCount % 5 == 0){ //�t���[����
		mAnime += 1;
	}
	if (mAnime >= FRAME_LIMIT || mSaveAnime != eAnime){
		mAnime = 0;
	}
	mSaveAnime = eAnime;

}
void CPlayer::Run_Walk(){
	if (CKey::push(VK_CONTROL)){ //���鎞
		mVelocity = RUN_SPEED;
		if (DecisionRL(eAnime) == PATTERN_L){
			eAnime = E_RUN_L;
		}
		else{
			eAnime = E_RUN_R;
		}
	}
	else{					   //������
		if (DecisionRL(eAnime) == PATTERN_L){
			eAnime = E_WALK_L;
		}
		else{
			eAnime = E_WALK_R;
		}
		mVelocity = WALK_SPEED;
	}
}
void CPlayer::Update() {
	AnimeFlame();
	assert(mAnime <= FRAME_LIMIT); //�t���[���������𒴂���ƃ_��
	mPriorityR = -mAxis;
	CTaskManager TaskManager;
	camera_x = mPos.x;
	camera_y = mPos.y;

	//�l�p�`�̈ʒu��ݒ�
	mPlayer.position = mPos;


	//�ړ��̏���

	//����{�^��
	
	

	// �E�ړ�
	if (CKey::push(VK_RIGHT)) {		
		Run_Walk();
		mForward = CVector2(WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}
	else{
		if (mSaveAnime == E_WALK_R ||
			mSaveAnime == E_RUN_R){//�ҋ@�� ���O�����̕����łȂ����
			eAnime = E_STAY_R;
		}
		if (mVelocity > 0){
			mVelocity -= SLOW_DOWN;
			MovePosAxis();
		}
		else{
			mVelocity = 0;
		}
	}

	//���ړ�
	if (CKey::push(VK_LEFT)) { 
		Run_Walk();
		mForward = CVector2(-WALK_X, 0.0f);
		mPos += mForward * mVelocity;

	
	}else{ //�ړ����Ă��Ȃ��Ƃ�
		if (mSaveAnime == E_WALK_L ||
			mSaveAnime == E_RUN_L){ //�ҋ@�� ���O���E�̕����łȂ����
			eAnime = E_STAY_L;
		}
		if (mVelocity > 0){ 
			mVelocity -= SLOW_DOWN;
			MovePosAxis();
		}
		else{
			mVelocity = 0;
		}

	}

	//�W�����v
	if (CKey::push(' ') || mEnabledJump) {
		if (!mEnabledJump){ //�W�����v���Ă��Ȃ��Ƃ�
			mEnabledJump = true;
		}
		Jump();
	}


	//��ړ�
	if (CKey::push(VK_UP) && mAxis < character_limit_top - SIZE_PLAYER_Y) { //��������ɒB���Ă��Ȃ��Ƃ�
		Run_Walk();
		mForward = CVector2(0.0f, WALK_Y);
		MovePosAxis();
	}

	//���ړ�
	if (CKey::push(VK_DOWN) && mAxis > character_limit_bottom + SIZE_PLAYER_Y) {//��������ɒB���Ă��Ȃ��Ƃ�
		Run_Walk();
		mForward = CVector2(0.0f, -WALK_Y);
		MovePosAxis();
	}



	/*�����蔻��*/
	if (mPos.y > character_limit_top - SIZE_PLAYER_Y&& !mEnabledJump){  //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(��)
		mPos.y = character_limit_top - SIZE_PLAYER_Y;
		mAxis = mPos.y - SIZE_PLAYER_Y; //�������Ƃɖ߂�
	}
	if (mPos.y < character_limit_bottom + SIZE_PLAYER_Y){  //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(��)
		mPos.y = character_limit_bottom + SIZE_PLAYER_Y;
		mAxis = mPos.y - SIZE_PLAYER_Y; //�������Ƃɖ߂�
	}

	if (mPos.x >= character_limit_right - SIZE_PLAYER_X || mPos.x <= character_limit_left + SIZE_PLAYER_X){ //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(X)
		mPos.x = mPlayer.position.x;
	}
	/*�����蔻��I��*/

	mPlayer.position = mPos;
	mShadow.position = CVector2(mPos.x,mAxis);

	/*�A�j���[�V�����̃X�e�[�^�X*/
	switch (eAnime)
	{
		/*�ҋ@��*/
	case E_STAY_L:
		mPlayer.SetUv(mStayTex[mAnime],SIZE_TEX_PLAYER_STAY_X, 0, 0, SIZE_TEX_PLAYER_STAY_Y);
		break;
	case E_STAY_R:
		mPlayer.SetUv(mStayTex[mAnime], 0, 0, SIZE_TEX_PLAYER_STAY_X,SIZE_TEX_PLAYER_STAY_Y);
		break;
		/*������*/
	case E_WALK_L:
		mPlayer.SetUv(mWalkTex[mAnime], SIZE_TEX_PLAYER_WALK_X, 0, 0, SIZE_TEX_PLAYER_WALK_Y);
		break;
	case E_WALK_R:
		mPlayer.SetUv(mWalkTex[mAnime], 0, 0, SIZE_TEX_PLAYER_WALK_X, SIZE_TEX_PLAYER_WALK_Y);
		break;
		/*���蒆*/
	case E_RUN_L:
		mPlayer.SetUv(mRunTex[mAnime], SIZE_TEX_PLAYER_RUN_X, 0, 0, SIZE_TEX_PLAYER_RUN_Y);
		break;
	case E_RUN_R:
		mPlayer.SetUv(mRunTex[mAnime], 0, 0, SIZE_TEX_PLAYER_RUN_X, SIZE_TEX_PLAYER_RUN_Y);
		break;
	}

}

void CPlayer::Render(){
	//�v���C���[�̕`��
	mShadow.Render();
	mPlayer.Render();

}
