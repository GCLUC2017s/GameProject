#include "CEnemy00.h"
#include "../MyNumber/CMyNumber.h"
#include "../Key/CKey.h" //�����e�X�g���̑���p

#define SIZE_ENEMY00_Y 1  //�G�l�~�[00�̃T�C�Y_Y
#define SIZE_ENEMY00_X 1 //�G�l�~�[00�̃T�C�Y_X

#define HITPOINT_ENEMY00 5					//�G�l�~�[00�̗̑�
#define FIRST_R_NO_PL 1						//���߂̃����_�[�̃|�C���g
#define FIRST_U_NO_PL 1						//���߂̃A�b�v�f�[�g�̃|�C���g
#define SIZE_TEX_ENEMY00_STAY_X 800			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y X
#define SIZE_TEX_ENEMY00_STAY_Y 800			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y Y
#define SIZE_TEX_ENEMY00_WALK_X 800			//�G�l�~�[�̕����e�N�X�`���T�C�Y Y
#define SIZE_TEX_ENEMY00_WALK_Y 800			//�G�l�~�[�̕����p�e�N�X�`���T�C�Y Y
#define SIZE_SHADOW							//�e�̕\��
#define SLOW_DOWN 0.001						//�ړ��̌����X�s�[�h

#define WALK_SPEED 0.05						//�����X�s�[�h
#define WALK_X 2							//�����x�N�g��X
#define WALK_Y 1							//�����x�N�g��Y

#define ENEMY00_STAY "../CG\\enemy00\\enemy00_stay\\"
#define ENEMY00_WALK "../CG\\enemy00\\enemy00_walk\\"
#define ENEMY00_ATTACK "../CG\\enemy00\\enemy00_attack\\"
#define ENEMY00_DIE "../CG\\enemy00\\enemy00_dai\\"


//�U�����ɂ����Ȃ�ꍇ�ł��E�������Ă��܂��B



void CEnemy00::SetPos(){
	mPos = Enemy_first_pos;
	mAxis = mPos.y;
};

void CEnemy00::Init(){
	SetPos();
	/*�e�N�X�`���ǂݍ���*/
	for (int i = 0; i < FLAME_LIMIT; i++)
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

	mDie_tex[0]->load(ENEMY00_DIE"enemy00_dai_00.tga");
	mDie_tex[1]->load(ENEMY00_DIE"enemy00_dai_01.tga");
	mDie_tex[2]->load(ENEMY00_DIE"enemy00_dai_02.tga");
	mDie_tex[3]->load(ENEMY00_DIE"enemy00_dai_03.tga");
	mDie_tex[4]->load(ENEMY00_DIE"enemy00_dai_04.tga");
	mDie_tex[5]->load(ENEMY00_DIE"enemy00_dai_05.tga");



	/*�e�N�X�`���𒣂�*/
	mEnemy00.SetUv(mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

}

CEnemy00::~CEnemy00(){
//���ɉ������Ȃ�
}

//�G�l�~�[00�`��
CEnemy00::CEnemy00() : mVelocity(0), mFlameCount(0){

	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = 0;
	}

	mPriorityR = FIRST_R_NO_PL;			//Render�̃i���o�[ 
	mPriorityU = FIRST_U_NO_PL;			//Update�̃i���o�[
	mHitPoint = HITPOINT_ENEMY00;		//�g�o
	mMyNumber = E_ENEMY00;

	//�l�p�`�̒��_�ݒ�
	mEnemy00.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	mShadow.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	//�l�p�`�̐F��ݒ�
	mEnemy00.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

}

/*�A�j���̃t���[���𓮂������\�b�h*/ //�G�l�~�[�ɂ���ĈႤ�ꍇ������̂ŉ摜�f�[�^�p�Q��
void CEnemy00::AnimeFlame(){

	mFlameCount += 1;
	if (mFlameCount % 5 == 0){ //�t���[����=mStay_tex[5]->load(".../.tga");
		mAnime += 1;
	}
	if (mAnime >= FLAME_LIMIT || mSaveAnime != eAnime){
		mAnime = 0;
	}
	mSaveAnime = eAnime;

}


void CEnemy00::Update(){

	AnimeFlame();
	assert(mAnime <= FLAME_LIMIT); //�t���[���������𒴂���ƃ_��
	mPriorityR = -mAxis;
	CTaskManager TaskManager;

	//�l�p�`�̈ʒu��ݒ�
	mEnemy00.position = mPos;


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




	
		
		if (mSaveAnime == E_WALK_L&&E_STAY_L&&E_ATTACK_L&&E_DIE_L){		//���O���������̃A�N�V�����̏ꍇ
			if (CKey::once('X')) { //�e�X�g�p�@�蓮�U��L
				eAnime = E_ATTACK_L;
			}
			if (CKey::once('Z')) {//�e�X�g�p�@�蓮���QL
				eAnime = E_DIE_L;
			}

		}
		else{
			if (CKey::once('X')) { //�e�X�g�p�@�蓮�U��R
				eAnime = E_ATTACK_R;
			}
			if (CKey::once('Z')) {//�e�X�g�p�@�蓮���QR
				eAnime = E_DIE_R;
			}
			
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
		mPos.x = mEnemy00.position.x;
	}
	/*�����蔻��I��*/

	mEnemy00.position = mPos;

	/*�A�j���[�V�����̃X�e�[�^�X*/
	switch (eAnime)
	{
		/*�ҋ@��*/
	case E_STAY_R:
		mEnemy00.SetUv(mStay_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_STAY_L:
		mEnemy00.SetUv(mStay_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*������*/
	case E_WALK_R:
		mEnemy00.SetUv(mWalk_tex[mAnime], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	case E_WALK_L:
		mEnemy00.SetUv(mWalk_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
		break;
		/*�U����*/
	case E_ATTACK_R:
		mEnemy00.SetUv(mAttack_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		printf("A�E�ł�\n");
		break;
	case E_ATTACK_L:
		mEnemy00.SetUv(mAttack_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		printf("A���ł�\n");
		break;
		/*���S*/
	case E_DIE_R:
		mEnemy00.SetUv(mDie_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		printf("D�E�ł�\n");
		break;
	case E_DIE_L:
		mEnemy00.SetUv(mDie_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		printf("D���ł�\n");
		break;

	}


}
void CEnemy00::Render(){
	mEnemy00.Render();
}
