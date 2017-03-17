#include "CEnemy00.h"
#include "../MyNumber/CMyNumber.h"
#include "../Key/CKey.h" //�����e�X�g���̑���p
#include "../CGame/CGame.h"
#include "stdio.h"
#include "../Enemy/CEnemyPattern.h"
#include <cstdlib>
#define SIZE_ENEMY00_Y 1  //�G�l�~�[00�̃T�C�Y_Y
#define SIZE_ENEMY00_X 1 //�G�l�~�[00�̃T�C�Y_X
/*

�G�l�~�[���v���C���[�̏ꏊ�ɍs���悤�ɐݒ�

���㋓���̒ǉ�


�����O��
*/
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
#define ENEMY00_DIE "../CG\\enemy00\\enemy00_dai\\"



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
	mRect.SetUv(mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

	motion = 0;

}



//�U�����ɂ����Ȃ�ꍇ�ł��E�������Ă��܂��B

//�G�l�~�[00�`��
CEnemy00::CEnemy00() : mVelocity(0), mFlameCount(0), mAnime(E_STAY_L){


	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = 0;
	}

	mPriorityR = FIRST_R_NO_PL;			//Render�̃i���o�[ 
	mPriorityU = FIRST_U_NO_PL;			//Update�̃i���o�[
	mHitPoint = HITPOINT_ENEMY00;		//�g�o
	mMyNumber = E_ENEMY00;

	//�l�p�`�̒��_�ݒ�
	mRect.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	//�l�p�`�̐F��ݒ�
	mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

}

void CEnemy00::SetPos(){
	mPos = Enemy00_first_pos;
	mAxis = mPos.y;
};

CEnemy00::~CEnemy00(){
//���ɉ������Ȃ�
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

	/*
	if���炯�ŉ���
	
	���ʂȏ���������\��
	
	*/

	if (mTargetP.x<0){
		npNum = mTargetP.x * -1; //�}�C�i�X�̏ꍇ�͐����ɂ���
	}
	else{
		npNum = mTargetP.x;
	}
	if (mPos.x<0){

		npNum2 = mPos.x * -1;
	}
	else{
		npNum2 = mPos.x;
	}

	rulerR = mTargetP.x - mPos.x;	//�v���C���[�Ƃ̋��������o��
	rulerL = mPos.x- mTargetP.x;

	
	if (rulerL<0){

		rulerL = rulerL * -1;
	}
	if (rulerR<0){

		rulerR = rulerR * -1;
	}

	printf("L%f\n", rulerL);

	//mTargetP��player�ɂ���
	mTargetP = CGame::mGetPlayerPos();

	//�l�p�`�̈ʒu��ݒ�
	mRect.position = mPos;

	AnimeFlame();
	assert(mAnime <= FLAME_LIMIT); //�t���[���������𒴂���ƃ_��
	mPriorityR = -mAxis;


	
	//�i�^�[�Q�b�g���E�ɂ���ꍇ�j
	if (RIGHT_PTT) {
		direction = 0;
		motion = 1;
		eAnime = E_WALK_R;
		mVelocity = WALK_SPEED;
		mForward = CVector2(WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}
	else if (mHitPoint == 0){
		if (mSaveAnime == E_WALK_R){ //�ҋ@�� ���O���E�̕����łȂ����
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

	//�i�^�[�Q�b�g�����ɂ���ꍇ�j
	if (LEFT_PTT) {
		direction = 1;
		motion = 1;
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

	
	//�i�^�[�Q�b�g����ɂ���ꍇ�j
	if (DOWN_PTT) { //��������ɒB���Ă��Ȃ��Ƃ�
		Walk();
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;

	}
	
	//�i�^�[�Q�b�g�����ɂ���ꍇ�j
	if (UP_PTT) {//��������ɒB���Ă��Ȃ��Ƃ�
		Walk();
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, -WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;
	}
	


	//�U���͈͓��Ƀ^�[�Q�b�g������
	if (ATTACK_PTT) {
		motion = 2;
	}


	if (CKey::push('Z')) {
		eAnime = E_ATTACK_R;
	}

	if (mHitPoint == 0){
		motion = 2;
	}



	switch (motion)
	{
	case 0://�ҋ@
		

		break;

	case 1://����
		//�i�^�[�Q�b�g���E�ɂ���ꍇ�j
	



		break;
	case 2://�U��
		if (RIGHT_PTT) {
			eAnime = E_ATTACK_R;
		}
		else if (LEFT_PTT){
			eAnime = E_ATTACK_L;
		}
		if (NO_ATTACK_PTT){
			motion = 1;
		}
		mAttackRange.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
		mAttackRange.SetColor(1.0f, 1.0f, 0.0f, 1.0f);
		mAttackRange.position = CVector2(mPos.x + 1, mPos.y);
		mAttackRange.position = CVector2(mPos.x - 1, mPos.y);
		mAttackAxis = 10.0f;
		mEnabledAttack = true;
		break;

	case 3://���S
		if (direction == 0) {
			eAnime = E_DIE_R;
		}
		else if (direction == 1){
			eAnime = E_DIE_L;
		}
		break;


	}

	switch (direction)
	{
	case 0:
		break;
	case 1:
		break;
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
		mPos.x = mRect.position.x;
	}

	/*�����蔻��I��*/

	mRect.position = mPos;

	/*�A�j���[�V�����̃X�e�[�^�X*/
	switch (eAnime)
	{
		/*�ҋ@��*/
	case E_STAY_R:
		mRect.SetUv(mStay_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_STAY_L:
		mRect.SetUv(mStay_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*������*/
	case E_WALK_R:
		mRect.SetUv(mWalk_tex[mAnime], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	case E_WALK_L:
		mRect.SetUv(mWalk_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
		break;
		/*�U����*/
	case E_ATTACK_R:
		mRect.SetUv(mAttack_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_ATTACK_L:
		mRect.SetUv(mAttack_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*���S*/
	case E_DIE_R:
		mRect.SetUv(mDie_tex[mAnime], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_DIE_L:
		mRect.SetUv(mDie_tex[mAnime], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;

	}

	if (mHitPoint == 0)mKillFlag = true;

}
void CEnemy00::Render(){
	mRect.Render();
}
