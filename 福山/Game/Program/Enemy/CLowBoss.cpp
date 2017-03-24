#include "CLowBoss.h"
#include "../MyNumber/CMyNumber.h"
#include "../CGame/CGame.h"
#include <cstdlib>
#include <stdio.h>
#include<time.h>
#include<iostream>
#include "../Load/CLoadBoss.h"	//�{�X�̕��𗬗p
#include "../Load/CLoadPlayer.h"
#include "../CGame/CGame.h"
#include "../Enemy\CEnemybasetest.h"
/*
�����O��

�X�e�[�^�X�������@�]�͂��܂�ς܂Ȃ��B

*/

#define FIRST_R_NO_LOWBOSS 1						//���߂̃����_�[�̃|�C���g
#define FIRST_U_NO_LOWBOSS 1						//���߂̃A�b�v�f�[�g�̃|�C���g
#define SIZE_TEX_BOSS_STAY_X 320			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y X
#define SIZE_TEX_BOSS_STAY_Y 320			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y Y
#define SIZE_TEX_BOSS_WALK_X 320			//�G�l�~�[�̕����e�N�X�`���T�C�Y Y
#define SIZE_TEX_BOSS_WALK_Y 320			//�G�l�~�[�̕����p�e�N�X�`���T�C�Y Y
#define SIZE_SHADOW							//�e�̕\��
#define WALK_SPEED 0.04						//�����X�s�[�h
#define WALK_X 2							//�����x�N�g��X
#define WALK_Y 1							//�����x�N�g��Y
#define ANIME_TIME_BASE				 6
#define BOSS_STAY 	 "../CG\\BOSS\\stay\\"
#define BOSS_WALK	 "../CG\\BOSS\\walk\\"
#define BOSS_ATTACK	 "../CG\\BOSS\\Attack\\"
#define BOSS_HATTACK "../CG\\BOSS\\HAttack\\"
#define BOSS_DIE	 "../CG\\BOSS\\die\\"

#define LOW_AT		mForward.x, SIZE_BOSS_X*1.5f, SIZE_BOSS_Y,2.445f, mPos      	//�U���͈�


void CLowBoss::SetPos(){
	mPos = LowBoss_first_pos;
	mAxis = mPos.y;
};

void CLowBoss::Init(){
	//SetPos();
	///*�e�N�X�`���𒣂�*/
	//mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	//mRect.SetUv(CLoadBoss::GetInstance()->mStay_tex[0], 0, 0, -SIZE_TEX_BOSS_STAY_X, SIZE_TEX_BOSS_STAY_Y);
	//mForward = CVector2(1.0f, 0.0f);

}

//���{�X
CLowBoss::CLowBoss() : mVelocity(0), mFrameCount(0), actionflag(false), motion(0), direction(E_LEFT){

	SetPos();
	/*�e�N�X�`���𒣂�*/
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mRect.SetUv(CLoadBoss::GetInstance()->mStay_tex[0], 0, 0, -SIZE_TEX_BOSS_STAY_X, SIZE_TEX_BOSS_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);


	mPriorityR = E_LOWBOSS;			//Render�̃i���o�[ 
	mPriorityU = E_LOWBOSS;			//Update�̃i���o�[
	mHitPoint = ENE_HP_X;		//�g�o
	mMyNumber = E_LOWBOSS;
	mStatus = E_STAY_L;

	//�l�p�`�̒��_�ݒ�
	mRect.SetVertex(-SIZE_LOWBOSS_X, SIZE_LOWBOSS_Y, SIZE_LOWBOSS_X, -SIZE_LOWBOSS_Y);	//CBase X,Y�Ƃ���1.5f
	mShadow.SetVertex(-SIZE_SHADOW_X, SIZE_SHADOW_Y, SIZE_SHADOW_X, -SIZE_SHADOW_Y);
	//�l�p�`�̐F��ݒ�
	mRect.SetColor(0.6f, 0.6f, 0.6f, 1.0f);
}	//��͓̂���

CLowBoss::~CLowBoss(){

}

void CLowBoss::AnimeScene(){
	/*�A�j���[�V�����̃X�e�[�^�X*/
	switch (mStatus)
	{
		/*�ҋ@��*/
	case E_STAY_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mStay_tex[mAnimeFrame], 0, 0, SIZE_TEX_BOSS_STAY_X, SIZE_TEX_BOSS_STAY_Y);
		break;
	case E_STAY_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mStay_tex[mAnimeFrame], SIZE_TEX_BOSS_STAY_X, 0, 0, SIZE_TEX_BOSS_STAY_Y);
		break;
		/*������*/
	case E_WALK_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mWalk_tex[mAnimeFrame], 0, 0, SIZE_TEX_BOSS_WALK_X, SIZE_TEX_BOSS_WALK_Y);
		break;
	case E_WALK_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mWalk_tex[mAnimeFrame], SIZE_TEX_BOSS_WALK_X, 0, 0, SIZE_TEX_BOSS_WALK_Y);
		break;
		/*�U��*/
	case E_ATTACK_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mAttack_tex[mAnimeFrame], 0, 0, SIZE_TEX_BOSS_WALK_X, SIZE_TEX_BOSS_WALK_Y);
		break;
	case E_ATTACK_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mAttack_tex[mAnimeFrame], SIZE_TEX_BOSS_WALK_X, 0, 0, SIZE_TEX_BOSS_WALK_Y);
		break;
		/*���S*/
	case E_DIE_L:
		AnimeFrame(false, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mDie_tex[mAnimeFrame], 0, 0, SIZE_TEX_BOSS_WALK_X, SIZE_TEX_BOSS_WALK_Y);
		break;
	case E_DIE_R:
		AnimeFrame(false, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mDie_tex[mAnimeFrame], SIZE_TEX_BOSS_WALK_X, 0, 0, SIZE_TEX_BOSS_WALK_Y);
		break;

	}
}

void CLowBoss::Walk(){
	//�i�^�[�Q�b�g���E�ɂ���ꍇ�j
	if (RIGHT_PTT) {
		direction = E_RIGHT;
		mStatus = E_WALK_R;
		mVelocity = WALK_SPEED;
		mForward = CVector2(WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}
	//�i�^�[�Q�b�g�����ɂ���ꍇ�j
	if (LEFT_PTT) {
		direction = E_LEFT;
		mStatus = E_WALK_L;
		mVelocity = WALK_SPEED;
		mForward = CVector2(-WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}
	//�i�^�[�Q�b�g����ɂ���ꍇ�j
	if (getAxis-1.5f > mAxis) {
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

void CLowBoss::Motion(){

	switch (motion)
	{
	case EM_STAY://�ҋ@
		if (direction == E_RIGHT){	//�E����
			mStatus = E_STAY_R;
		}
		else if (direction = E_LEFT){	//������

			mStatus = E_STAY_L;
		}
		if (ENEMY_VISI)		//���E���ɂƂ炦����ǂ��Ă���
		{
			motion = EM_WALK;
		}
		break;
	case EM_WALK://����	
		Walk();
		if (ATTACK_PTTX&&ATTACK_BOSS_Y){//�U�����[�V�����ɕύX
			actionflag = false;
			motion = EM_RANGE;
		}
		break;
	case EM_RANGE://�U���͈͓��ɓ�������

		if (!actionflag){
			pattern = rand() % 3; //0~2�̒��Ń����_���Ńp�^�[����I������B
		}
		if (pattern == 0){
			motion = EM_ATTACK;
		}
		if (pattern == 1){
			actionflag = true;
			motion = EM_BACK_X;
		}
		if (pattern == 2){
			actionflag = true;
			motion = EM_ATTACK;
		}

		if (NO_ATTACK_BOSS){
			actionflag = false;
			motion = EM_WALK;
		}
		break;
	case EM_DIE://���S
		if (direction == E_RIGHT) {
			mEnabledAttack = true;
			mEnabledAttack = false;
			mStatus = E_DIE_R;
		}
		else if (direction == E_LEFT){
			mEnabledAttack = true;
			mEnabledAttack = false;
			mStatus = E_DIE_L;
		}
		break;

	case EM_BACK_X://���ɓ�����B
		if (direction == E_LEFT) {
			direction = E_LEFT;
			mVelocity = WALK_SPEED *1.5f;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;

		}
		else if (direction == E_RIGHT){
			direction = E_RIGHT;
			mVelocity = -WALK_SPEED*1.5f;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;
		}

		if (ENEMY_ESCAPE){	//��苗�������ƍēx������Ɍ������Ă���
			actionflag = false; //actionflag��false�ɂ���B
			motion = EM_WALK;
		}

		break;
	case EM_ATTACK:		//�U����
		//���[�V�����ݒ�
		if (RIGHT_PTT&&ENEMY_LIVE) {
			mEnabledAttack = true;
			mStatus = E_ATTACK_R;
		}
		else if (LEFT_PTT&&ENEMY_LIVE){
			mEnabledAttack = true;
			mStatus = E_ATTACK_L;
		}
		//�͈�
		Attack(LOW_AT);
		///�p���`�̍Ō�ɂ����蔻��
		/*�͈͓��ɋ߂Â�*/
		if (NO_ATTACK_BOSS){
			actionflag = false;
			mEnabledAttack = false;
			motion = EM_WALK;
		}
		break;


	}
}

void CLowBoss::Update(){
	mRect.position = mPos;
	mTargetP = CGame::mGetPlayerPos();
	getAxis = CGame::GetPlayerAxis();
	rulerR = mTargetP.x - mPos.x;	//�v���C���[�Ƃ̋������o��		//���̂�����̏����͑S�G�l�~�[���ʂȂ̂łǂ����Ɉڂ������B
	rulerL = mPos.x - mTargetP.x;
	if (rulerL<0){				//��Βl�ɂ���
		rulerL = rulerL * -1;
	}
	if (rulerR<0){
		rulerR = rulerR * -1;
	}
	upruler = mTargetP.y - mPos.y;
	downruler = mPos.y - mTargetP.y;
	if (upruler<0){				//��Βl�ɂ���
		upruler = upruler * -1;
	}
	if (downruler<0){
		downruler = downruler * -1;
	}

	if (mHitPoint <= 0){

		motion = EM_DIE;
		if (direction == E_RIGHT) {
			mStatus = E_DIE_R;
		
		}
		else if (direction == E_LEFT){
			mStatus = E_DIE_L;
			
		}
	}
	if (mEnabledEaten){		//�H�ׂ�ꂽ�����
		//���o�����Ă���������(��)�g��k������if(�T�C�Y��0�ȉ��̎�killFlag�𗧂Ă�Ȃ�)
		mKillFlag = true;
	}

	switch (direction)
	{
	case E_RIGHT:	//�E����
		break;
	case E_LEFT:	//������
		break;
	}
	Motion();

	AlertHPRect(&mRect, mHitPoint);	//�A���[�g���\�b�h(HP�ω��ɂ�����)
	/*���̐ݒ�*/
	mAxis = mPos.y - SIZE_LOWBOSS_Y;
	mAttackRange.position = mPos;
	/*�͈͊O����*/
	LimitDisp(SIZE_LOWBOSS_X, SIZE_LOWBOSS_Y);
	/*�����_�[���Ԑݒ�*/
	mPriorityR = -mAxis;
	LimitDisp(SIZE_LOWBOSS_X, SIZE_LOWBOSS_Y);	//�����蔻��
	AnimeScene();
	mShadow.position = CVector2(mPos.x, mAxis+0.8f);

	mRect.position = mPos;
}

void CLowBoss::Render(){

	mShadow.Render();
	mRect.Render();
}
