#include "CEnemy00.h"
#include "../MyNumber/CMyNumber.h"
#include "../CGame/CGame.h"
#include "stdio.h"
#include <cstdlib>
#include<time.h>
#include<iostream>
#include "CEnemybasetest.h"
#include "../Load/CLoadEnemy00.h"

#define SIZE_ENEMY00_Y 1  //�G�l�~�[00�̃T�C�Y_Y
#define SIZE_ENEMY00_X 1 //�G�l�~�[00�̃T�C�Y_X
/*

�����O��

*/
#define HITPOINT_ENEMY00 5					//�G�l�~�[00�̗̑�
#define FIRST_R_NO_ENEMY00 1						//���߂̃����_�[�̃|�C���g
#define FIRST_U_NO_ENEMY00 1						//���߂̃A�b�v�f�[�g�̃|�C���g
#define SIZE_TEX_ENEMY00_STAY_X 80			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y X
#define SIZE_TEX_ENEMY00_STAY_Y 80			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y Y
#define SIZE_TEX_ENEMY00_WALK_X 80			//�G�l�~�[�̕����e�N�X�`���T�C�Y Y
#define SIZE_TEX_ENEMY00_WALK_Y 80			//�G�l�~�[�̕����p�e�N�X�`���T�C�Y Y
#define SIZE_SHADOW							//�e�̕\��
#define PATTERN_R 1							//PATTERN�̉E
#define PATTERN_L 2							//PATTERN�̍�

#define ANIME_TIME_BASE						6								//�A�j���̃��[�v���� �p���I�Ȃ���
#define ANIME_TIME_ATTACK					6								//�A�j���̃��[�v���� �U���̂���

#define WALK_SPEED 0.02f				//�����X�s�[�h
#define WALK_X 2						//�����x�N�g��X
#define WALK_Y 1						//�����x�N�g��Y

#define ENEMY00_STAY "../CG\\enemy00\\enemy00_stay\\"
#define ENEMY00_WALK "../CG\\enemy00\\enemy00_walk\\"
#define ENEMY00_ATTACK "../CG\\enemy00\\enemy00_attack\\"
#define ENEMY00_DIE "../CG\\enemy00\\enemy00_dai\\"
#include "../Load/CLoadPlayer.h"

inline void InitRand(){
	srand((unsigned int)time(NULL));
}

void CEnemy00::SetPos(){
	mPos = Enemy00_first_pos;
	mAxis = mPos.y;
};


void CEnemy00::Init(){
	SetPos();
	
	/*�e�N�X�`���𒣂�*/
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mRect.SetUv(CLoadEnemy00::GetInstance()->mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);


}



//�G�l�~�[00�`��
CEnemy00::CEnemy00() : mVelocity(0), mFlameCount(0), actionflag(false),motion(0),direction(1){


	mPriorityR = E_ENEMY00;			//Render�̃i���o�[ 
	mPriorityU = E_ENEMY00;			//Update�̃i���o�[
	mHitPoint = HITPOINT_ENEMY00;		//�g�o
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
	case E_STAY_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mStay_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_STAY_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mStay_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*������*/
	case E_WALK_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mWalk_tex[mAnimeFrame], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	case E_WALK_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mWalk_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
		break;
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
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mDie_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_DIE_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mDie_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;

	}
}

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

	mTargetP = CGame::mGetPlayerPos();
	float getAxis = CGame::GetPlayerAxis();

	rulerR = mTargetP.x - mPos.x;	//�v���C���[�Ƃ̋������o��
	rulerL = mPos.x- mTargetP.x;

	if (rulerL<0){				//��Βl�ɂ���
		rulerL = rulerL * -1;
	}
	if (rulerR<0){
		rulerR = rulerR * -1;
	}

	mPriorityR = -mAxis;

	/*
	
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
	*/


	if (mHitPoint <= 0){
		motion = 2;		//�̗͂��O�Ȃ�DIE����
	}


	switch (motion)
	{
	case 0://�ҋ@
		if (direction==0){	//�E����
			mStatus = E_STAY_R;
		}
		else if (direction=1){	//������

			mStatus = E_STAY_L;
		}

		if (ENEMY_VISI)		//���E���ɂƂ炦����ǂ��Ă���
		{
			motion = 1;
		}

		break;
	case 1://����	
		Walk();

		if (ATTACK_PTT){//�U�����[�V�����ɕύX
			actionflag = false;
			motion = 2;
		}

		break;
	case 2://�U���͈͓��ɓ�������
		
		if (!actionflag){
			pattern = rand() % 3; //0~2�̒��Ń����_���Ńp�^�[����I������B
		}
			if (pattern == 0){
				motion = 6;
			}
			else if (pattern == 1){
				actionflag = true;
				motion = 4;
			}
			else if (pattern == 2){
	
				motion = 6;
			}

			if (NO_ATTACK_PTT){
				actionflag = false;
				motion = 1;
			}
		
		break;

	case 3://���S
		if (direction == 0) {
			mStatus = E_DIE_R;
		}
		else if (direction == 1){
			mStatus = E_DIE_L;
		}
		break;

	case 4://���ɓ�����B


		if (direction == 1) {
			direction = 1;
			mVelocity = WALK_SPEED*3;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;
		
		}
		else if (direction == 0){
			direction = 0;
			mVelocity = -WALK_SPEED * 3;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;
		}

		if (ENEMY_ESCAPE){	//��苗�������ƍēx������Ɍ������Ă���
			actionflag = false; //actionflag��false�ɂ���B
			motion = 1;
		}

		break;
	case 5:		//���ɓ�����
		
			mVelocity = WALK_SPEED;
			mForward = CVector2(0.0f, -WALK_Y);
			mPos += mForward * mVelocity;
			mAxis += mForward.y * mVelocity;
		
		if (mAxis == character_limit_bottom){

			motion = 1;
			actionflag = false;
		}


		break;

	case 6:		//�U����

		if (RIGHT_PTT && !mEnabledAttack) {
			mEnabledAttack = true;
				mStatus = E_ATTACK_R;
		}
		else if (LEFT_PTT && !mEnabledAttack){
			mEnabledAttack = true;
					mStatus = E_ATTACK_L;			
			}


		/*�͈�*/
		if (mEnabledAttack){
			mAttackRange.SetVertex(-SIZE_PLAYER_X, SIZE_PLAYER_Y, SIZE_PLAYER_X, -SIZE_PLAYER_Y);
			mAttackRange.SetColor(1.0f, 1.0f, 0.0f, 1.0f);
			if (RIGHT_PTT)mAttackRange.position = CVector2(mPos.x + 1, mPos.y);
			if (LEFT_PTT)mAttackRange.position = CVector2(mPos.x - 1, mPos.y);
			mAttackAxis = 3.0f;
		}

		if (mAnimeFrame == FRAME_LIMIT - 1){
			mEnabledAttack = false;//�U���I��
		}

		if (rulerR > 2 || rulerL >2){
			actionflag = false;
			motion = 1;
		}


		break;
	}

	switch (direction)
	{
	case 0:	//�E����
		break;
	case 1:	//������
		break;
	}


	//printf("%d\n", motion);


	LimitDisp(SIZE_ENEMY00_X, SIZE_ENEMY00_Y);
	AnimeScene();
	if(mHitPoint == 0)mKillFlag = true;

	mRect.position = mPos;

	mShadow.position = CVector2(mPos.x, mAxis);


}
void CEnemy00::Render(){
	mShadow.Render();
	mRect.Render();
}
