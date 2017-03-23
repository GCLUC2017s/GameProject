#include "CBoss.h"
#include "../MyNumber/CMyNumber.h"
#include "../CGame/CGame.h"
#include <cstdlib>
#include <stdio.h>
#include<time.h>
#include<iostream>
#include "../Load/CLoadBoss.h"
#include "../Load/CLoadPlayer.h"
#include "../CGame/CGame.h"
#include"CEnemybasetest.h"
/*

CKey���g���Ă���������͍���ʂ̏����ɂȂ�܂��B

�����O��

*/

#define FIRST_R_NO_BOSS 1						//���߂̃����_�[�̃|�C���g
#define FIRST_U_NO_BOSS 1						//���߂̃A�b�v�f�[�g�̃|�C���g
#define SIZE_TEX_BOSS_STAY_X 360			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y X
#define SIZE_TEX_BOSS_STAY_Y 360			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y Y
#define SIZE_TEX_BOSS_WALK_X 800			//�G�l�~�[�̕����e�N�X�`���T�C�Y Y
#define SIZE_TEX_BOSS_WALK_Y 800			//�G�l�~�[�̕����p�e�N�X�`���T�C�Y Y
#define SIZE_SHADOW							//�e�̕\��
#define WALK_SPEED 0.04						//�����X�s�[�h
#define WALK_X 2							//�����x�N�g��X
#define WALK_Y 1							//�����x�N�g��Y

#define ANIME_TIME_BASE				 6
#define ANIME_TIME_HATTACK			12

#define BOSS_STAY 	 "../CG\\BOSS\\stay\\"
#define BOSS_WALK	 "../CG\\BOSS\\walk\\"
#define BOSS_ATTACK	 "../CG\\BOSS\\Attack\\"
#define BOSS_HATTACK "../CG\\BOSS\\HAttack\\"
#define BOSS_DIE	 "../CG\\BOSS\\die\\"

#define LOW_AT		mForward.x, SIZE_BOSS_X*1.5f, SIZE_BOSS_Y,1.445f, mPos      	//�U���͈�
#define HIGH_AT		mForward.x, SIZE_BOSS_X*2.5f, SIZE_BOSS_Y,2.5f, mPos      	//�U���͈�
#define MOVE_AT		mForward.x, SIZE_BOSS_X*1.25f, SIZE_BOSS_Y,1.345f, mPos      	//�U���͈�


void CBoss::SetPos(){
	mPos = Boss_first_pos;
	mAxis = mPos.y;
};

void CBoss::Init(){
	SetPos();
	/*�e�N�X�`���𒣂�*/
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mRect.SetUv(CLoadBoss::GetInstance()->mStay_tex[0], 0, 0, -SIZE_TEX_BOSS_STAY_X, SIZE_TEX_BOSS_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

}

//BOSS�`��
CBoss::CBoss() : mVelocity(0), mFrameCount(0), actionflag(false), motion(0), direction(0){

	/*�e�N�X�`���𒣂�*/
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mRect.SetUv(CLoadBoss::GetInstance()->mStay_tex[0], 0, 0, -SIZE_TEX_BOSS_STAY_X, SIZE_TEX_BOSS_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);
	mPriorityR = E_BOSS;			//Render�̃i���o�[ 
	mPriorityU = E_BOSS;			//Update�̃i���o�[
	mHitPoint = ENE_HP_X;		//�g�o
	mMyNumber = E_BOSS;
	mStatus = E_STAY_L;

	//�l�p�`�̒��_�ݒ�
	mRect.SetVertex(-SIZE_BOSS_X, SIZE_BOSS_Y, SIZE_BOSS_X, -SIZE_BOSS_Y);
	mShadow.SetVertex(-SIZE_SHADOW_X, SIZE_SHADOW_Y, SIZE_SHADOW_X, -SIZE_SHADOW_Y);
	//�l�p�`�̐F��ݒ�
	mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
}

CBoss::~CBoss(){


}

void CBoss::AnimeScene(){
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
		AnimeFrame(false, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mAttack_tex[mAnimeFrame], 0, 0, SIZE_TEX_BOSS_WALK_X, SIZE_TEX_BOSS_WALK_Y);
		break;
	case E_ATTACK_R:
		AnimeFrame(false, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mAttack_tex[mAnimeFrame], SIZE_TEX_BOSS_WALK_X, 0, 0, SIZE_TEX_BOSS_WALK_Y);
		break;
		/*���U��*/
	case E_HATTACK_L:
		AnimeFrame(false, ANIME_TIME_HATTACK);
		mRect.SetUv(CLoadBoss::GetInstance()->mHattack_tex[mAnimeFrame], 0, 0, SIZE_TEX_BOSS_WALK_X, SIZE_TEX_BOSS_WALK_Y);
		break;
	case E_HATTACK_R:
		AnimeFrame(false, ANIME_TIME_HATTACK);
		mRect.SetUv(CLoadBoss::GetInstance()->mHattack_tex[mAnimeFrame], SIZE_TEX_BOSS_WALK_X, 0, 0, SIZE_TEX_BOSS_WALK_Y);
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

void CBoss::Walk(){
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

void CBoss::Motion(){

	switch (motion)
	{
	case EM_STAY://�ҋ@
		if (direction == 0){	//�E����
			mStatus = E_STAY_R;
		}
		else if (direction = 1){	//������

			mStatus = E_STAY_L;
		}
		if (ENEMY_VISI)		//���E���ɂƂ炦����ǂ��Ă���
		{
			motion = EM_WALK;
		}
		break;
	case EM_WALK://����	
		Walk();
		if (ATTACK_PTTX){//�U�����[�V�����ɕύX
			actionflag = false;
			motion = EM_RANGE;
		}
		if (HATTACK_PTT){
			actionflag = false;
			motion = EM_RANGE;
		}

		break;
	case EM_RANGE://�U���͈͓��ɓ�������
		if (ATTACK_PTTX){
			if (!actionflag){
				pattern = rand() % 6; //0~2�̒��Ń����_���Ńp�^�[����I������B
			}
			if (pattern == 0){
				motion = EM_ATTACK;
			}
			else if (pattern == 1){
				actionflag = true;
				motion = EM_BACK_X;
			}
			else{
				motion = EM_ATTACK;
			}
		}

		////���U���͈͓̔�(������)�u���b�V���A�b�v
		//if (HATTACK_PTT){
		//	if (!actionflag){
		//		pattern = rand() % 3; //0~2�̒��Ń����_���Ńp�^�[����I������B
		//	}
		//	if (pattern == 0){
		//		motion = EM_HIGH_AT;
		//	}
		//	else if (pattern == 1){
		//		actionflag = true;
		//		motion = EM_BACK_X;
		//	}
		//	else if (pattern == 2){
		//		motion = EM_ATTCK;
		//	}
		//}
		if (NO_ATTACK_PTTX){
			actionflag = false;
			motion = EM_WALK;
		}
		break;
	case EM_DIE://���S
		if (direction == 0) {
			mStatus = E_DIE_R;
		}
		else if (direction == 1){
			mStatus = E_DIE_L;
		}
		break;

	case EM_BACK_X://���ɓ�����B
		if (direction == 1) {
			direction = 1;
			mVelocity = WALK_SPEED * 3;
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
			motion = EM_WALK;
		}

		break;
	case EM_ATTACK:		//�U����
		/*���[�V�����ݒ�*/
		if (RIGHT_PTT) {
			mStatus = E_ATTACK_R;
		}
		else{
			mStatus = E_ATTACK_L;
		}
		/*�͈�*/
		Attack(LOW_AT);
		///�p���`�̍Ō�ɂ����蔻��
		mEnabledAttack = true;
		/*�͈͓��ɋ߂Â�*/
		if (rulerR > 2 || rulerL > 2){
			actionflag = false;
			mEnabledAttack = false;
			motion = EM_WALK;
		}
		break;

	case EM_HIGH_AT:
		/*���[�V�����ݒ�*/
		if (RIGHT_PTT) {
			mStatus = E_HATTACK_R;
		}
		else{
			mStatus = E_HATTACK_L;
		}
		/*�͈͐ݒ�*/
		Attack(HIGH_AT);
		if (mAnimeFrame == FRAME_LIMIT - 1){	//�p���`�̍Ō�ɂ����蔻��
			mEnabledAttack = true;//�U���I��
			motion = EM_RANGE;				//���G
		}
		else{
			mEnabledAttack = false;
		}
		break;


	}
}

void CBoss::Update(){
	mRect.position = mPos;

	mTargetP = CGame::mGetPlayerPos();
	getAxis = CGame::GetPlayerAxis();

	rulerR = mTargetP.x - mPos.x;	//�v���C���[�Ƃ̋������o��
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
		motion = EM_DIE;		//�̗͂��O�Ȃ�DIE����
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
	mAxis = mPos.y - SIZE_BOSS_Y;
	mAttackRange.position = mPos;
	/*�͈͊O����*/
	LimitDisp(SIZE_BOSS_X, SIZE_BOSS_Y);
	/*�����_�[���Ԑݒ�*/
	mPriorityR = -mAxis;
	LimitDisp(SIZE_BOSS_X, SIZE_BOSS_Y);	//�����蔻��
	AnimeScene();
	mShadow.position = CVector2(mPos.x, mAxis);

	mRect.position = mPos;
}

void CBoss::Render(){

	mShadow.Render();
	mRect.Render();
}
