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
#define TEX_FILE_PLAYER_STAY "../CG\\beru\\beru_stay\\"  //�v���C���[�̃t�@�C���ꏊ�@�҂�
#define TEX_FILE_PLAYER_WALK "../CG\\beru\\beru_walk\\"  //�v���C���[�̃t�@�C���ꏊ�@�҂�
#define TEX_FILE_PLAYER_RUN "../CG\\beru\\beru_run\\"  //�v���C���[�̃t�@�C���ꏊ�@�҂�

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
	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = new CTexture();		//�e�N�X�`���N���X�̃C���X�^���X�쐬
		mWalk_tex[i] = new CTexture();		//�e�N�X�`���N���X�̃C���X�^���X�쐬
		mRun_tex[i] = new CTexture();		//�e�N�X�`���N���X�̃C���X�^���X�쐬
	}

	/*�e�N�X�`���t�@�C���ǂݍ���*/
	mStay_tex[0]->load(TEX_FILE_PLAYER_STAY"beru_stay_00.tga");
	mStay_tex[1]->load(TEX_FILE_PLAYER_STAY"beru_stay_01.tga");
	mStay_tex[2]->load(TEX_FILE_PLAYER_STAY"beru_stay_02.tga");
	mStay_tex[3]->load(TEX_FILE_PLAYER_STAY"beru_stay_03.tga");
	mStay_tex[4]->load(TEX_FILE_PLAYER_STAY"beru_stay_04.tga");
	mStay_tex[5]->load(TEX_FILE_PLAYER_STAY"beru_stay_05.tga");

	mWalk_tex[0]->load(TEX_FILE_PLAYER_WALK"beru_walk_00.tga");
	mWalk_tex[1]->load(TEX_FILE_PLAYER_WALK"beru_walk_01.tga");
	mWalk_tex[2]->load(TEX_FILE_PLAYER_WALK"beru_walk_02.tga");
	mWalk_tex[3]->load(TEX_FILE_PLAYER_WALK"beru_walk_03.tga");
	mWalk_tex[4]->load(TEX_FILE_PLAYER_WALK"beru_walk_04.tga");
	mWalk_tex[5]->load(TEX_FILE_PLAYER_WALK"beru_walk_05.tga");

	mRun_tex[0]->load(TEX_FILE_PLAYER_RUN"beru_run_00.tga");
	mRun_tex[1]->load(TEX_FILE_PLAYER_RUN"beru_run_01.tga");
	mRun_tex[2]->load(TEX_FILE_PLAYER_RUN"beru_run_02.tga");
	mRun_tex[3]->load(TEX_FILE_PLAYER_RUN"beru_run_03.tga");
	mRun_tex[4]->load(TEX_FILE_PLAYER_RUN"beru_run_04.tga");
	mRun_tex[5]->load(TEX_FILE_PLAYER_RUN"beru_run_05.tga");




	/*�e�N�X�`���𒣂�*/
	mPlayer.SetUv(mStay_tex[0], 0, 0, SIZE_TEX_PLAYER_STAY_X,SIZE_TEX_PLAYER_STAY_Y);
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

	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = 0;
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
	if (mAnime >= FLAME_LIMIT || mSaveAnime != eAnime){
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
	assert(mAnime <= FLAME_LIMIT); //�t���[���������𒴂���ƃ_��
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
		mPlayer.SetUv(mStay_tex[mAnime],SIZE_TEX_PLAYER_STAY_X, 0, 0, SIZE_TEX_PLAYER_STAY_Y);
		break;
	case E_STAY_R:
		mPlayer.SetUv(mStay_tex[mAnime], 0, 0, SIZE_TEX_PLAYER_STAY_X,SIZE_TEX_PLAYER_STAY_Y);
		break;
		/*������*/
	case E_WALK_L:
		mPlayer.SetUv(mWalk_tex[mAnime], SIZE_TEX_PLAYER_WALK_X, 0, 0, SIZE_TEX_PLAYER_WALK_Y);
		break;
	case E_WALK_R:
		mPlayer.SetUv(mWalk_tex[mAnime], 0, 0, SIZE_TEX_PLAYER_WALK_X, SIZE_TEX_PLAYER_WALK_Y);
		break;
		/*���蒆*/
	case E_RUN_L:
		mPlayer.SetUv(mRun_tex[mAnime], SIZE_TEX_PLAYER_RUN_X, 0, 0, SIZE_TEX_PLAYER_RUN_Y);
		break;
	case E_RUN_R:
		mPlayer.SetUv(mRun_tex[mAnime], 0, 0, SIZE_TEX_PLAYER_RUN_X, SIZE_TEX_PLAYER_RUN_Y);
		break;
	}

}

void CPlayer::Render(){
	//�v���C���[�̕`��
	mShadow.Render();
	mPlayer.Render();

}
