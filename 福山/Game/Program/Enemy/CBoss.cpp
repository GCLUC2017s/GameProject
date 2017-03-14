#include "CBoss.h"
#include "../MyNumber/CMyNumber.h"
#include "../Key/CKey.h" //�����e�X�g���̑���p

#define SIZE_ENEMY00_Y 3  //�G�l�~�[00�̃T�C�Y_Y
#define SIZE_ENEMY00_X 3 //�G�l�~�[00�̃T�C�Y_X

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

#define BOSS_STAY 	 "../CG\\BOSS\\stay\\"
#define BOSS_WALK	 "../CG\\BOSS\\walk\\"
#define BOSS_ATTACK	 "../CG\\BOSS\\Attack\\"
#define BOSS_HATTACK "../CG\\BOSS\\HAttack\\"
#define BOSS_DIE	 "../CG\\BOSS\\die\\"

void CBoss::SetPos(){
	mPos = Enemy_first_pos;
	mAxis = mPos.y;
};

void CBoss::Init(){
	SetPos();
	/*�e�N�X�`���ǂݍ���*/
	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = new CTexture();		//�e�N�X�`���N���X�̃C���X�^���X�쐬
		mWalk_tex[i] = new CTexture();		//�e�N�X�`���N���X�̃C���X�^���X�쐬
		mAttack_tex[i] = new CTexture();
		mHattack_tex[i] = new CTexture();
		mDie_tex[i] = new CTexture();
	}

	/*�e�N�X�`���t�@�C���ǂݍ���*/
	mStay_tex[0]->load(BOSS_STAY "BOSS_stay_00.tga");
	mStay_tex[1]->load(BOSS_STAY "BOSS_stay_01.tga");
	mStay_tex[2]->load(BOSS_STAY "BOSS_stay_02.tga");
	mStay_tex[3]->load(BOSS_STAY "BOSS_stay_03.tga");
	mStay_tex[4]->load(BOSS_STAY "BOSS_stay_04.tga");
	mStay_tex[5]->load(BOSS_STAY "BOSS_stay_05.tga");

	mWalk_tex[0]->load(BOSS_WALK"BOSS_walkR_00.tga");
	mWalk_tex[1]->load(BOSS_WALK"BOSS_walkR_01.tga");
	mWalk_tex[2]->load(BOSS_WALK"BOSS_walkR_02.tga");
	mWalk_tex[3]->load(BOSS_WALK"BOSS_walkR_03.tga");
	mWalk_tex[4]->load(BOSS_WALK"BOSS_walkR_04.tga");
	mWalk_tex[5]->load(BOSS_WALK"BOSS_walkR_05.tga");

	mAttack_tex[0]->load(BOSS_WALK"BOSS_walkR_00.tga");
	mAttack_tex[1]->load(BOSS_WALK"BOSS_walkR_01.tga");
	mAttack_tex[2]->load(BOSS_WALK"BOSS_walkR_02.tga");
	mAttack_tex[3]->load(BOSS_WALK"BOSS_walkR_03.tga");
	mAttack_tex[4]->load(BOSS_WALK"BOSS_walkR_04.tga");
	mAttack_tex[5]->load(BOSS_WALK"BOSS_walkR_05.tga");

	mWalk_tex[0]->load(BOSS_WALK"BOSS_walkR_00.tga");
	mWalk_tex[1]->load(BOSS_WALK"BOSS_walkR_01.tga");
	mWalk_tex[2]->load(BOSS_WALK"BOSS_walkR_02.tga");
	mWalk_tex[3]->load(BOSS_WALK"BOSS_walkR_03.tga");
	mWalk_tex[4]->load(BOSS_WALK"BOSS_walkR_04.tga");
	mWalk_tex[5]->load(BOSS_WALK"BOSS_walkR_05.tga");



	/*�e�N�X�`���𒣂�*/
	mBoss.SetUv(mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

}

CBoss::~CBoss(){
	//���ɉ������Ȃ�
}

//�G�l�~�[00�`��
CBoss::CBoss() : mVelocity(0), mFlameCount(0){

	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = 0;
	}

	mPriorityR = FIRST_R_NO_PL;			//Render�̃i���o�[ 
	mPriorityU = FIRST_U_NO_PL;			//Update�̃i���o�[
	mHitPoint = HITPOINT_ENEMY00;		//�g�o
	mMyNumber = E_ENEMY00;

	//�l�p�`�̒��_�ݒ�
	mBoss.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	mShadow.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	//�l�p�`�̐F��ݒ�
	mBoss.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

}

/*�A�j���̃t���[���𓮂������\�b�h*/ //�G�l�~�[�ɂ���ĈႤ�ꍇ������̂ŉ摜�f�[�^�p�Q��
void CBoss::AnimeFlame(){

	mFlameCount += 1;
	if (mFlameCount % 5 == 0){ //�t���[����=mStay_tex[5]->load(".../.tga");
		mAnime += 1;
	}
	if (mAnime >= FLAME_LIMIT || mSaveAnime != eAnime){
		mAnime = 0;
	}
	mSaveAnime = eAnime;

}


void CBoss::Update(){

	AnimeFlame();
	assert(mAnime <= FLAME_LIMIT); //�t���[���������𒴂���ƃ_��
	mPriorityR = -mAxis;
	CTaskManager TaskManager;

	//�l�p�`�̈ʒu��ݒ�
	mBoss.position = mPos;


	// �E�ړ�
	if (CKey::push('D')) {
		eAnime = E_WALK_R;
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
	if (CKey::push('W') && mAxis < character_limit_top - SIZE_ENEMY00_Y) { //��������ɒB���Ă��Ȃ��Ƃ�
		Walk();
		mForward = CVector2(0.0f, WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;

	}

	//���ړ�
	if (CKey::push('S') && mAxis > character_limit_bottom + SIZE_ENEMY00_Y) {//��������ɒB���Ă��Ȃ��Ƃ�
		Walk();
		mForward = CVector2(0.0f, -WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;
	}




	/*�����蔻��*/
	if (mPos.y > character_limit_top - SIZE_ENEMY00_Y){  //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(��)
		mPos.y = character_limit_top - SIZE_ENEMY00_Y;
		mAxis = mPos.y; //�������Ƃɖ߂�
	}
	if (mPos.y < character_limit_bottom + SIZE_ENEMY00_Y){  //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(��)
		mPos.y = character_limit_bottom + SIZE_ENEMY00_Y;
		mAxis = mPos.y; //�������Ƃɖ߂�
	}

	if (mPos.x >= character_limit_right - SIZE_ENEMY00_X || mPos.x <= character_limit_left + SIZE_ENEMY00_X){ //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(X)
		mPos.x = mBoss.position.x;
	}
	/*�����蔻��I��*/

	mBoss.position = mPos;

	/*�A�j���[�V�����̃X�e�[�^�X*/
	switch (eAnime)
	{
		/*�ҋ@��*/
	case E_STAY_L:
		mBoss.SetUv(mStay_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_STAY_R:
		mBoss.SetUv(mStay_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*������*/
	case E_WALK_L:
		mBoss.SetUv(mWalk_tex[mAnime], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	case E_WALK_R:
		mBoss.SetUv(mWalk_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	}

}
void CBoss::Render(){
	mBoss.Render();
}
