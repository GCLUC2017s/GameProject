#include "CBoss.h"
#include "../MyNumber/CMyNumber.h"
#include "../Key/CKey.h" //�����e�X�g���̑���p
/*


CKey���g���Ă���������͍���ʂ̏����ɂȂ�܂��B

�����O��

*/

#define SIZE_BOSS_Y 3  //�G�l�~�[00�̃T�C�Y_Y
#define SIZE_BOSS_X 3 //�G�l�~�[00�̃T�C�Y_X

#define HITPOINT_ENEMY00 5					//�G�l�~�[00�̗̑�
#define FIRST_R_NO_PL 1						//���߂̃����_�[�̃|�C���g
#define FIRST_U_NO_PL 1						//���߂̃A�b�v�f�[�g�̃|�C���g
#define SIZE_TEX_ENEMY00_STAY_X 800			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y X
#define SIZE_TEX_ENEMY00_STAY_Y 800			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y Y
#define SIZE_TEX_ENEMY00_WALK_X 800			//�G�l�~�[�̕����e�N�X�`���T�C�Y Y
#define SIZE_TEX_ENEMY00_WALK_Y 800			//�G�l�~�[�̕����p�e�N�X�`���T�C�Y Y
#define SIZE_SHADOW							//�e�̕\��
#define SLOW_DOWN 0.001						//�ړ��̌����X�s�[�h
#define WALK_SPEED 0.04						//�����X�s�[�h
#define WALK_X 2							//�����x�N�g��X
#define WALK_Y 1							//�����x�N�g��Y
#include"../Load/CLoadBoss.h"


void CBoss::SetPos(){
	mPos = Boss_first_pos;
	mAxis = mPos.y;
};

void CBoss::Init(){
	SetPos();

	

	/*�e�N�X�`���𒣂�*/
	mBoss.SetUv(CLoadBoss::GetInstance()->mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

}

CBoss::~CBoss(){
	//���ɉ������Ȃ�
}

//�G�l�~�[00�`��
CBoss::CBoss() : mVelocity(0), mFlameCount(0){


	mPriorityR = E_BOSS;			//Render�̃i���o�[ 
	mPriorityU = E_BOSS;			//Update�̃i���o�[
	mHitPoint = HITPOINT_ENEMY00;		//�g�o
	mMyNumber = E_BOSS;

	//�l�p�`�̒��_�ݒ�
	mBoss.SetVertex(SIZE_BOSS_X, SIZE_BOSS_Y, -SIZE_BOSS_X, -SIZE_BOSS_Y);
	mShadow.SetVertex(-SIZE_BOSS_X, SIZE_BOSS_Y, SIZE_BOSS_X, -SIZE_BOSS_Y);
	//�l�p�`�̐F��ݒ�
	mBoss.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

}

/*�A�j���̃t���[���𓮂������\�b�h*/ //�G�l�~�[�ɂ���ĈႤ�ꍇ������̂ŉ摜�f�[�^�p�Q��
void CBoss::AnimeFrame(){

	mFlameCount += 1;
	if (mFlameCount % 5 == 0){ //�t���[����=mStay_tex[5]->load(".../.tga");
		mAnime += 1;
	}
	if (mAnime >= FRAME_LIMIT || mSaveAnime != eAnime){
		mAnime = 0;
	}
	mSaveAnime = eAnime;

}


void CBoss::Update(){

	AnimeFrame();
	assert(mAnime <= FRAME_LIMIT); //�t���[���������𒴂���ƃ_��
	mPriorityR = -mAxis;

	//�l�p�`�̈ʒu��ݒ�
	mBoss.position = mPos;


	// �E�ړ�
	if (CKey::push('D')) {
		eAnime = E_WALK_R;
		direction = 0;

		mVelocity = WALK_SPEED;

		mForward = CVector2(WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}
	else{
		if (mSaveAnime == E_WALK_R){//�ҋ@�� ���O�����̕����łȂ����
			eAnime = E_STAY_R;
		}
		if (mVelocity > 0){
			mVelocity -= SLOW_DOWN;
			mPos += mForward * mVelocity;
		}
		else{
			mVelocity = 0;
		}
	}


	//���ړ�
	if (CKey::push('A')) {
		direction = 1;

		eAnime = E_WALK_L;
		mVelocity = WALK_SPEED;

		mForward = CVector2(-WALK_X, 0.0f);
		mPos += mForward * mVelocity;

	}
	else{ //�ړ����Ă��Ȃ��Ƃ�
		if (mSaveAnime == E_WALK_L){ //�ҋ@�� ���O���E�̕����łȂ����
			eAnime = E_STAY_L;
		}
		if (mVelocity > 0){
			mVelocity -= SLOW_DOWN;
			mPos += mForward * mVelocity;
		}
		else{
			mVelocity = 0;
		}

	}


	//��ړ�
	if (CKey::push('W') && mAxis < character_limit_top - SIZE_BOSS_Y) { //��������ɒB���Ă��Ȃ��Ƃ�
		Walk();
		if (direction == 0){
			eAnime = E_WALK_R;
		}
		else if (direction == 1){
			eAnime = E_WALK_L;

		}
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;

	}

	//���ړ�
	if (CKey::push('S') && mAxis > character_limit_bottom + SIZE_BOSS_Y) {//��������ɒB���Ă��Ȃ��Ƃ�
		Walk();
		if (direction==0){
			eAnime = E_WALK_R;
		}else if(direction==1){
			eAnime = E_WALK_L;

		}
		
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, -WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;
	}

	//�U��
	if (CKey::push('X') && direction == 0) {

		eAnime = E_ATTACK_R;
	}
	else if (CKey::push('X') && direction == 1){
		eAnime = E_ATTACK_L;
	}
	


	//���U��
	if (CKey::push('C') && direction == 0) {
		
			eAnime = E_HATTACK_R;
		}
	else if (CKey::push('C') && direction == 1){
			eAnime = E_HATTACK_L;
		}




		//���S
	if (CKey::push('Z') && direction == 0) {

		eAnime = E_DIE_R;
	}
	else if (CKey::push('Z') && direction == 1){
				eAnime = E_DIE_L;
		}

		switch (direction)
		{
		case 0:			//�E
			break;
		case 1:			//��
			break;
		}


		/*�����蔻��*/
		if (mPos.y > character_limit_top - SIZE_BOSS_Y){  //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(��)
			mPos.y = character_limit_top - SIZE_BOSS_Y;
			mAxis = mPos.y; //�������Ƃɖ߂�
		}
		if (mPos.y < character_limit_bottom + SIZE_BOSS_Y){  //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(��)
			mPos.y = character_limit_bottom + SIZE_BOSS_Y;
			mAxis = mPos.y; //�������Ƃɖ߂�
		}

		if (mPos.x >= character_limit_right - SIZE_BOSS_X || mPos.x <= character_limit_left + SIZE_BOSS_X){ //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(X)
			mPos.x = mBoss.position.x;
		}
		/*�����蔻��I��*/


		/*�A�j���[�V�����̃X�e�[�^�X*/
		switch (eAnime)
		{
			/*�ҋ@��*/
		case E_STAY_L:
			mBoss.SetUv(CLoadBoss::GetInstance()->mStay_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
			break;
		case E_STAY_R:
			mBoss.SetUv(CLoadBoss::GetInstance()->mStay_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
			break;
			/*������*/
		case E_WALK_L:
			mBoss.SetUv(CLoadBoss::GetInstance()->mWalk_tex[mAnime], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
			break;
		case E_WALK_R:
			mBoss.SetUv(CLoadBoss::GetInstance()->mWalk_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
			break;
			/*�U��*/
		case E_ATTACK_L:
			mBoss.SetUv(CLoadBoss::GetInstance()->mAttack_tex[mAnime], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
			break;
		case E_ATTACK_R:
			mBoss.SetUv(CLoadBoss::GetInstance()->mAttack_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
			break;
			/*���U��*/
		case E_HATTACK_L:
			mBoss.SetUv(CLoadBoss::GetInstance()->mHattack_tex[mAnime], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
			break;
		case E_HATTACK_R:
			mBoss.SetUv(CLoadBoss::GetInstance()->mHattack_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
			break;
			/*���S*/
		case E_DIE_L:
			mBoss.SetUv(CLoadBoss::GetInstance()->mDie_tex[mAnime], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
			break;
		case E_DIE_R:
			mBoss.SetUv(CLoadBoss::GetInstance()->mDie_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
			break;

		}
		mBoss.position = mPos;
	}

void CBoss::Render(){
	mBoss.Render();
}
