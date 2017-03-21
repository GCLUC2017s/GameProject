#include "CEnemy00.h"
#include "../MyNumber/CMyNumber.h"
#include "../CGame/CGame.h"
#include "stdio.h"
#include <cstdlib>
#include<time.h>
#include<iostream>
#include "CEnemybasetest.h"
#include "../Load/CLoadEnemy00.h"
/*

�����O��

*/
#define FIRST_R_NO_ENEMY00 1						//���߂̃����_�[�̃|�C���g
#define FIRST_U_NO_ENEMY00 1						//���߂̃A�b�v�f�[�g�̃|�C���g
#define SIZE_TEX_ENEMY00_STAY_X 80			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y X
#define SIZE_TEX_ENEMY00_STAY_Y 80			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y Y
#define SIZE_TEX_ENEMY00_WALK_X 80			//�G�l�~�[�̕����e�N�X�`���T�C�Y Y
#define SIZE_TEX_ENEMY00_WALK_Y 80			//�G�l�~�[�̕����p�e�N�X�`���T�C�Y Y
#define SIZE_SHADOW							//�e�̕\��
#define PATTERN_R 1							//PATTERN�̉E
#define PATTERN_L 2							//PATTERN�̍�

#define ANIME_TIME_BASE						EM_ATTCK								//�A�j���̃��[�v���� �p���I�Ȃ���
#define ANIME_TIME_ATTACK					EM_ATTCK								//�A�j���̃��[�v���� �U���̂���

#define WALK_SPEED 0.02f				//�����X�s�[�h
#define WALK_X 2						//�����x�N�g��X
#define WALK_Y 1						//�����x�N�g��Y
#define AT_RANGE		mForward.x, 100, 100,10, mPos      	//�U���͈�
#define ENEMY00_STAY "../CG\\enemy00\\enemy00_stay\\"
#define ENEMY00_WALK "../CG\\enemy00\\enemy00_walk\\"
#define ENEMY00_ATTACK "../CG\\enemy00\\enemy00_attack\\"
#define ENEMY00_DIE "../CG\\enemy00\\enemy00_dai\\"
#include "../Load/CLoadPlayer.h"


void CEnemy00::Init(){
	RandPos(SIZE_ENEMY00_X, SIZE_ENEMY00_Y, &mPos);
	/*�e�N�X�`���𒣂�*/
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mRect.SetUv(CLoadEnemy00::GetInstance()->mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

	srand((unsigned int)time(NULL));

}



//�G�l�~�[00�`��
CEnemy00::CEnemy00() : mVelocity(0), mFlameCount(0), actionflag(false), motion(EM_STAY), mDirection(1){

	mPriorityR = E_ENEMY00;			//Render�̃i���o�[ 
	mPriorityU = E_ENEMY00;			//Update�̃i���o�[
	mHitPoint = ENE_HP_X;		//�g�o
	mMyNumber = E_ENEMY00;
	mStatus=E_STAY_L;

	//�l�p�`�̒��_�ݒ�
	mRect.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	mShadow.SetVertex(-SIZE_SHADOW_X, SIZE_SHADOW_Y, SIZE_SHADOW_X, -SIZE_SHADOW_Y);
	//�l�p�`�̐F��ݒ�
	mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	
}

CEnemy00::~CEnemy00(){
}

void CEnemy00::AnimeScene(){

	/*�A�j���[�V�����̃X�e�[�^�X*/
	switch (mStatus)
	{
		/*�ҋ@��*/
	case E_STAY_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mStay_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_STAY_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mStay_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*������*/
	case E_WALK_L:
		AnimeFrame(true, ANIME_TIME_BASE);
			mRect.SetUv(CLoadEnemy00::GetInstance()->mWalk_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	case E_WALK_R:
		AnimeFrame(true, ANIME_TIME_BASE);
			mRect.SetUv(CLoadEnemy00::GetInstance()->mWalk_tex[mAnimeFrame], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
		/*�U����*/
	case E_ATTACK_R:
		AnimeFrame(true, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mAttack_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_ATTACK_L:
		AnimeFrame(true, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mAttack_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*���S*/
	case E_DIE_R:
		AnimeFrame(false, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mDie_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_DIE_L:
		AnimeFrame(false, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mDie_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;

	}
}

<<<<<<< HEAD
void CEnemy00::Motion(){
=======
void CEnemy00::Walk(){

	//�i�^�[�Q�b�g���E�ɂ���ꍇ�j
	if (RIGHT_PTT) {
		direction = 0;
		mStatus = E_WALK_R;
		mVelocity = WALK_SPEED;
		mForward = CVector2(WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}
	
	//�i�^�[�Q�b�g�����ɂ���ꍇ�j
	if (LEFT_PTT) {
		direction = 1;
		mStatus = E_WALK_L;
		mVelocity = WALK_SPEED;
		mForward = CVector2(-WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}


	//�i�^�[�Q�b�g����ɂ���ꍇ�j
	if ((CGame::GetPlayerAxis() + CGame::mGetPlayerPos().y) / 2 > mAxis) {
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;

	}

	//�i�^�[�Q�b�g�����ɂ���ꍇ�j
	if ((CGame::GetPlayerAxis() + CGame::mGetPlayerPos().y) / 2 < mAxis) {
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, -WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;
	}


}

void CEnemy00::Update(){
	assert(mAnimeFrame <= FLAME_LIMIT); //�t���[���������𒴂���ƃ_��
	
	mRect.position = mPos;
	//mTargetP��player�ɂ���
	InitRand();
>>>>>>> 97d02c8f7767f6aa041da256200778deabdb8b61





	switch (motion)
	{
	case EM_STAY://�ҋ@
		if (mDirection == E_RIGHT){	//�E����
			mStatus = E_STAY_R;
		}
		else if (mDirection = E_LEFT){	//������

			mStatus = E_STAY_L;
		}

		if (ENEMY_VISI)		//���E���ɂƂ炦����ǂ��Ă���
		{
			motion = EM_WALK;
		}

		break;
	case EM_WALK://����	
		Walk();
		printf("%f,%f\n", rulerR, rulerL);
		if (ATTACK_PTT){//�U�����[�V�����ɕύX
			actionflag = false;
			motion = EM_RANGE;
		}

		break;
	case EM_RANGE://�U���͈͓��ɓ�������

		if (!actionflag){
			pattern = rand() % 3; //0~2�̒��Ń����_���Ńp�^�[����I������B
		
		if (pattern == 0){
			motion = EM_ATTCK;
		}
		else if (pattern == 1){
			actionflag = true;
			motion = EM_BACK_X;
		}
		else if (pattern == 2){

			motion = EM_BACK_Y;
		}

		if (NO_ATTACK_PTT){
			actionflag = false;
			motion = EM_WALK;
		}
		}
		break;

	case EM_DIE://���S
		if (mDirection == E_RIGHT) {
			mStatus = E_DIE_R;
		}
		else if (mDirection == E_LEFT){
			mStatus = E_DIE_L;
		}
		break;

	case EM_BACK_X://���ɓ�����B


		if (mDirection == E_LEFT) {
			mDirection = E_LEFT;
			mVelocity = WALK_SPEED * 3;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;

		}
		else if (mDirection == E_RIGHT){
			mDirection = E_RIGHT;
			mVelocity = -WALK_SPEED * 3;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;
		}

		if (ENEMY_ESCAPE){	//��苗�������ƍēx������Ɍ������Ă���
			actionflag = false; //actionflag��false�ɂ���B
			motion = EM_WALK;
		}

		break;
	case EM_BACK_Y:		//�㉺�ɓ�����


		if (mAxis < getAxis){
			mVelocity = WALK_SPEED * 3;
			mForward = CVector2(0.0f, -WALK_Y);
			mPos += mForward * mVelocity;
			mAxis += mForward.y * mVelocity;
			if (mAxis == character_limit_bottom || mAxis == DOWNAXIS){
				motion = EM_WALK;
				actionflag = false;
				break;
			}
		}
		else if (mAxis >= getAxis){
			mVelocity = WALK_SPEED * 3;
			mForward = CVector2(0.0f, WALK_Y);
			mPos += mForward * mVelocity;
			mAxis += mForward.y * mVelocity;
			if (mAxis == character_limit_top || mAxis == UPAXIS){
				motion = EM_WALK;
				actionflag = false;
				break;
			}
		}

	case EM_ATTCK:		//�U����
		
		if (RIGHT_PTT && !mEnabledAttack) {
			mEnabledAttack = true;
			mStatus = E_ATTACK_R;
		}
		else if (LEFT_PTT && !mEnabledAttack){
			mEnabledAttack = true;
			mStatus = E_ATTACK_L;
		}


		//�U���͈͂Ƃ����蔻��t���O
		Attack(AT_RANGE);
			mEnabledAttack = true;

		//�����ŋ������l�߂�
		if (rulerR > 2 || rulerL >2){
			actionflag = false;
			motion = EM_WALK;
			mEnabledAttack = false;
		}


		break;
	}

	switch (mDirection)
	{
	case E_RIGHT:	//�E����
		break;
	case E_LEFT:	//������
		break;
	}


}


void CEnemy00::Walk(){

	//�i�^�[�Q�b�g���E�ɂ���ꍇ�j
	if (RIGHT_PTT) {
		mDirection = E_RIGHT;
		mStatus = E_WALK_R;
		mVelocity = WALK_SPEED;
		mForward = CVector2(WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}
	
	//�i�^�[�Q�b�g�����ɂ���ꍇ�j
	if (LEFT_PTT) {
		mDirection = E_LEFT;
		mStatus = E_WALK_L;
		mVelocity = WALK_SPEED;
		mForward = CVector2(-WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}


	//�i�^�[�Q�b�g����ɂ���ꍇ�j
	if ((CGame::GetPlayerAxis() + CGame::mGetPlayerPos().y) / 2 > mAxis) {
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;

	}

	//�i�^�[�Q�b�g�����ɂ���ꍇ�j
	if ((CGame::GetPlayerAxis() + CGame::mGetPlayerPos().y) / 2 < mAxis) {
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, -WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;
	}


}


void CEnemy00::Update(){
	mRect.position = mPos;
	//mTargetP��player�ɂ���
	mTargetP = CGame::mGetPlayerPos();
	getAxis = CGame::GetPlayerAxis();
	rulerR = mTargetP.x - mPos.x;	//�v���C���[�Ƃ̋������o��
	rulerL = mPos.x- mTargetP.x;
	if (rulerL<0){				//��Βl�ɂ���
		rulerL = rulerL * -1;
	}
	if (rulerR<0){
		rulerR = rulerR * -1;
	}
	if (mHitPoint <= 0){
		motion = EM_DIE;		//�̗͂��O�Ȃ�DIE����
	}
	mAttackRange.position = mPos;

	AlertHPRect(&mRect, mHitPoint);	//�A���[�g���\�b�h(HP�ω��ɂ�����)
	//���̐ݒ�
	mAxis = mPos.y - SIZE_ENEMY00_Y;
	//�͈͊O����
	LimitDisp(SIZE_ENEMY00_X, SIZE_ENEMY00_Y);
	//�����_�[���Ԑݒ�
	mPriorityR = -mAxis;
	AnimeScene();
	mRect.position = mPos;
	mShadow.position = CVector2(mPos.x, mAxis);


	Motion();		//���[�V�����Ăяo���B

}

void CEnemy00::Render(){
	mShadow.Render();
	mRect.Render();
}
