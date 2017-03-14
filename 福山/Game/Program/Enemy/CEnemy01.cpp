#include "CEnemy01.h"
#include "../MyNumber/CMyNumber.h"
#include "../Key/CKey.h" //�����e�X�g���̑���p
/*

�q�R�[�X�P�[�`

*/



#define SIZE_ENEMY00_Y 1  //�G�l�~�[01�̃T�C�Y_Y
#define SIZE_ENEMY00_X 1 //�G�l�~�[01�̃T�C�Y_X

#define HITPOINT_ENEMY00 5					//�G�l�~�[00�̗̑�
#define FIRST_R_NO_PL 1						//���߂̃����_�[�̃|�C���g
#define FIRST_U_NO_PL 1						//���߂̃A�b�v�f�[�g�̃|�C���g
#define SIZE_TEX_ENEMY00_STAY_X 800			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y X
#define SIZE_TEX_ENEMY00_STAY_Y 800			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y Y
#define SIZE_TEX_ENEMY00_WALK_X 800			//�G�l�~�[�̕����e�N�X�`���T�C�Y Y
#define SIZE_TEX_ENEMY00_WALK_Y 800			//�G�l�~�[�̕����p�e�N�X�`���T�C�Y Y
#define SIZE_SHADOW							//�e�̕\��
#define SLOW_DOWN 0.001						//�ړ��̌����X�s�[�h
#define WALK_SPEED 0.07		//�e�X�g�p�ɂ������Ă�				//��s�X�s�[�h
#define WALK_X 2							//��s�x�N�g��X
#define WALK_Y 1							//��s�x�N�g��Y

#define ENEMY01_FLAY "../CG\\enemy01\\enemy01_flay\\"
#define ENEMY01_STAY "../CG\\enemy01\\enemy01_stay\\"
#define ENEMY01_ATTACK "../CG\\enemy01\\enemy01_attack\\"
#define ENEMY01_DIE "../CG\\enemy01\\enemy01_die\\"


void CEnemy01::SetPos(){
	mPos = Enemy_first_pos;
	mAxis = mPos.y;
};

void CEnemy01::Init(){
	SetPos();
	/*�e�N�X�`���ǂݍ���*/
	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = new CTexture();		//�e�N�X�`���N���X�̃C���X�^���X�쐬
		mFlay_tex[i] = new CTexture();		//�e�N�X�`���N���X�̃C���X�^���X�쐬
		mAttack_tex[i] = new CTexture();
		mDie_tex[i] = new CTexture();		
	}

	/*�e�N�X�`���t�@�C���ǂݍ���*/
	mStay_tex[0]->load(ENEMY01_STAY"enemy01_stay_00.tga");
	mStay_tex[1]->load(ENEMY01_STAY"enemy01_stay_01.tga");
	mStay_tex[2]->load(ENEMY01_STAY"enemy01_stay_02.tga");
	mStay_tex[3]->load(ENEMY01_STAY"enemy01_stay_03.tga");
	mStay_tex[4]->load(ENEMY01_STAY"enemy01_stay_04.tga");
	mStay_tex[5]->load(ENEMY01_STAY"enemy01_stay_05.tga");

	mFlay_tex[0]->load(ENEMY01_FLAY"enemy01_flay_00.tga");
	mFlay_tex[1]->load(ENEMY01_FLAY"enemy01_flay_01.tga");
	mFlay_tex[2]->load(ENEMY01_FLAY"enemy01_flay_02.tga");
	mFlay_tex[3]->load(ENEMY01_FLAY"enemy01_flay_03.tga");
	mFlay_tex[4]->load(ENEMY01_FLAY"enemy01_flay_04.tga");
	mFlay_tex[5]->load(ENEMY01_FLAY"enemy01_flay_05.tga");

	mAttack_tex[0]->load(ENEMY01_ATTACK"enemy01_attackR_00.tga");
	mAttack_tex[1]->load(ENEMY01_ATTACK"enemy01_attackR_00.tga");
	mAttack_tex[2]->load(ENEMY01_ATTACK"enemy01_attackR_00.tga");
	mAttack_tex[3]->load(ENEMY01_ATTACK"enemy01_attackR_00.tga");
	mAttack_tex[4]->load(ENEMY01_ATTACK"enemy01_attackR_00.tga");
	mAttack_tex[5]->load(ENEMY01_ATTACK"enemy01_attackR_00.tga");

	mDie_tex[0]->load(ENEMY01_DIE"enemy01_die_00.tga");
	mDie_tex[1]->load(ENEMY01_DIE"enemy01_die_01.tga");
	mDie_tex[2]->load(ENEMY01_DIE"enemy01_die_02.tga");
	mDie_tex[3]->load(ENEMY01_DIE"enemy01_die_03.tga");
	mDie_tex[4]->load(ENEMY01_DIE"enemy01_die_04.tga");
	mDie_tex[5]->load(ENEMY01_DIE"enemy01_die_05.tga");



	/*�e�N�X�`���𒣂�*/
	mEnemy01.SetUv(mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

}

CEnemy01::~CEnemy01(){
	//���ɉ������Ȃ�
}

//�G�l�~�[00�`��
CEnemy01::CEnemy01() : mVelocity(0), mFlameCount(0){

	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = 0;
	}

	mPriorityR = FIRST_R_NO_PL;			//Render�̃i���o�[ 
	mPriorityU = FIRST_U_NO_PL;			//Update�̃i���o�[
	mHitPoint = HITPOINT_ENEMY00;		//�g�o
	mMyNumber = E_ENEMY00;

	//�l�p�`�̒��_�ݒ�
	mEnemy01.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	mShadow.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	//�l�p�`�̐F��ݒ�
	mEnemy01.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

}

/*�A�j���̃t���[���𓮂������\�b�h*/ //�G�l�~�[�ɂ���ĈႤ�ꍇ������̂ŉ摜�f�[�^�p�Q��
void CEnemy01::AnimeFlame(){

	mFlameCount += 1;
	if (mFlameCount % 5 == 0){ //�t���[����=mStay_tex[5]->load(".../.tga");
		mAnime += 1;
	}
	if (mAnime >= FLAME_LIMIT || mSaveAnime != eAnime){
		mAnime = 0;
	}
	mSaveAnime = eAnime;

}


void CEnemy01::Update(){

	AnimeFlame();
	assert(mAnime <= FLAME_LIMIT); //�t���[���������𒴂���ƃ_��
	mPriorityR = -mAxis;
	CTaskManager TaskManager;

	//�l�p�`�̈ʒu��ݒ�
	mEnemy01.position = mPos;


	// �E�ړ�
	if (CKey::push('D')) {
		eAnime = E_FLAY_R;
		mVelocity = WALK_SPEED;

		mForward = CVector2(WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}
	else{
		if (mSaveAnime == E_FLAY_R){//�ҋ@�� ���O�����̕����łȂ����
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

		eAnime = E_FLAY_L;
		mVelocity = WALK_SPEED;

		mForward = CVector2(-WALK_X, 0.0f);
		mPos += mForward * mVelocity;

	}
	else{ //�ړ����Ă��Ȃ��Ƃ�
		if (mSaveAnime == E_FLAY_L){ //�ҋ@�� ���O���E�̕����łȂ����
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
		mPos.x = mEnemy01.position.x;
	}
	/*�����蔻��I��*/

	mEnemy01.position = mPos;

	/*�A�j���[�V�����̃X�e�[�^�X*/
	switch (eAnime)
	{
		/*�ҋ@��*/
	case E_STAY_L:
		mEnemy01.SetUv(mStay_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_STAY_R:
		mEnemy01.SetUv(mStay_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*������*/
	case E_FLAY_L:
		mEnemy01.SetUv(mFlay_tex[mAnime], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	case E_FLAY_R:
		mEnemy01.SetUv(mFlay_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	}

}
void CEnemy01::Render(){
	mEnemy01.Render();
}
