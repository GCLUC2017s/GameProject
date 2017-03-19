#include "CBoss.h"
#include "../MyNumber/CMyNumber.h"
#include "../CGame/CGame.h"
#include <cstdlib>
#include <stdio.h>
#include<time.h>
#include<iostream>
#include "CEnemybasetest.h"
#include "../Load/CLoadBoss.h"
#include "../Load/CLoadPlayer.h"

/*


CKey���g���Ă���������͍���ʂ̏����ɂȂ�܂��B

�����O��

*/

#define SIZE_BOSS_Y 1  //BOSS�̃T�C�Y_Y
#define SIZE_BOSS_X 1 //BOSS�̃T�C�Y_X

#define HITPOINT_BOSS 5					//BOSS�̗̑�
#define FIRST_R_NO_BOSS 1						//���߂̃����_�[�̃|�C���g
#define FIRST_U_NO_BOSS 1						//���߂̃A�b�v�f�[�g�̃|�C���g
#define SIZE_TEX_BOSS_STAY_X 800			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y X
#define SIZE_TEX_BOSS_STAY_Y 800			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y Y
#define SIZE_TEX_BOSS_WALK_X 800			//�G�l�~�[�̕����e�N�X�`���T�C�Y Y
#define SIZE_TEX_BOSS_WALK_Y 800			//�G�l�~�[�̕����p�e�N�X�`���T�C�Y Y
#define SIZE_SHADOW							//�e�̕\��
#define WALK_SPEED 0.04						//�����X�s�[�h
#define WALK_X 2							//�����x�N�g��X
#define WALK_Y 1							//�����x�N�g��Y

#define ANIME_TIME_BASE 6

#define BOSS_STAY 	 "../CG\\BOSS\\stay\\"
#define BOSS_WALK	 "../CG\\BOSS\\walk\\"
#define BOSS_ATTACK	 "../CG\\BOSS\\Attack\\"
#define BOSS_HATTACK "../CG\\BOSS\\HAttack\\"
#define BOSS_DIE	 "../CG\\BOSS\\die\\"


inline void InitRand(){
	srand((unsigned int)time(NULL));
}

void CBoss::SetPos(){
	mPos = Boss_first_pos;
	mAxis = mPos.y;
};


void CBoss::Init(){
	SetPos();

	
	/*�e�N�X�`���𒣂�*/
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mRect.SetUv(CLoadBoss::GetInstance()->mStay_tex[0], 0, 0, SIZE_TEX_BOSS_STAY_X, SIZE_TEX_BOSS_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

}


//BOSS�`��
CBoss::CBoss() : mVelocity(0), mFlameCount(0), actionflag(false), motion(0), direction(1){

	mPriorityR = E_BOSS;			//Render�̃i���o�[ 
	mPriorityU = E_BOSS;			//Update�̃i���o�[
	mHitPoint = HITPOINT_BOSS;		//�g�o
	mMyNumber = E_BOSS;
	mStatus = E_STAY_L;

	//�l�p�`�̒��_�ݒ�
	mRect.SetVertex(SIZE_BOSS_X, SIZE_BOSS_Y, -SIZE_BOSS_X, -SIZE_BOSS_Y);
	mShadow.SetVertex(SIZE_BOSS_X, SIZE_BOSS_Y, -SIZE_BOSS_X, -SIZE_BOSS_Y);

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
		mRect.SetUv(CLoadBoss::GetInstance()->mStay_tex[mAnime], SIZE_TEX_BOSS_STAY_X, 0, 0, SIZE_TEX_BOSS_STAY_Y);
		break;
	case E_STAY_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mStay_tex[mAnime], 0, 0, SIZE_TEX_BOSS_STAY_X, SIZE_TEX_BOSS_STAY_Y);
		break;
		/*������*/
	case E_WALK_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mWalk_tex[mAnime], SIZE_TEX_BOSS_WALK_X, 0, 0, SIZE_TEX_BOSS_WALK_Y);
		break;
	case E_WALK_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mWalk_tex[mAnime], 0, 0, SIZE_TEX_BOSS_WALK_X, SIZE_TEX_BOSS_WALK_Y);
		break;
		/*�U��*/
	case E_ATTACK_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mAttack_tex[mAnime], SIZE_TEX_BOSS_WALK_X, 0, 0, SIZE_TEX_BOSS_WALK_Y);
		break;
	case E_ATTACK_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mAttack_tex[mAnime], 0, 0, SIZE_TEX_BOSS_WALK_X, SIZE_TEX_BOSS_WALK_Y);
		break;
		/*���U��*/
	case E_HATTACK_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mHattack_tex[mAnime], SIZE_TEX_BOSS_WALK_X, 0, 0, SIZE_TEX_BOSS_WALK_Y);
		break;
	case E_HATTACK_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mHattack_tex[mAnime], 0, 0, SIZE_TEX_BOSS_WALK_X, SIZE_TEX_BOSS_WALK_Y);
		break;
		/*���S*/
	case E_DIE_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mDie_tex[mAnime], SIZE_TEX_BOSS_WALK_X, 0, 0, SIZE_TEX_BOSS_WALK_Y);
		break;
	case E_DIE_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadBoss::GetInstance()->mDie_tex[mAnime], 0, 0, SIZE_TEX_BOSS_WALK_X, SIZE_TEX_BOSS_WALK_Y);
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

void CBoss::Update(){
	assert(mAnime <= FLAME_LIMIT); //�t���[���������𒴂���ƃ_��
	mRect.position = mPos;

	InitRand();
	mTargetP = CGame::mGetPlayerPos();
	float getAxis = CGame::GetPlayerAxis();

	mPriorityR = -mAxis;

	rulerR = mTargetP.x - mPos.x;	//�v���C���[�Ƃ̋������o��
	rulerL = mPos.x - mTargetP.x;

	if (rulerL < 0){				//��Βl�ɂ���
		rulerL = rulerL * -1;
	}
	if (rulerR < 0){
		rulerR = rulerR * -1;
	}

	if (mHitPoint <= 0){
		motion = 2;		//�̗͂��O�Ȃ�DIE����
	}

	switch (motion)
	{
	case 0://�ҋ@
		if (direction == 0){	//�E����
			mStatus = E_STAY_R;
		}
		else if (direction = 1){	//������

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
		if (HATTACK_PTT){
			actionflag = false;
			motion = 2;
		}

		break;
	case 2://�U���͈͓��ɓ�������
		if (ATTACK_PTT){
			if (!actionflag){
				pattern = rand() % 6; //0~2�̒��Ń����_���Ńp�^�[����I������B
			}
			if (pattern == 0){
				mEnabledAttack = true;
				motion = 6;
			}
			else if (pattern == 1){
				actionflag = true;
				motion = 4;
			}
			else if (pattern == 2){
				motion = 6;
			}
			else if (pattern == 3){
				motion = 4;
			}
			else if (pattern == 4){
				motion = 6;
			}
			else if (pattern == 5){
				motion = 6;
			}
		}

		//���U���͈͓̔�
		if (HATTACK_PTT){
			if (!actionflag){
				pattern = rand() % 3; //0~2�̒��Ń����_���Ńp�^�[����I������B
			}
			if (pattern == 0){
				mEnabledAttack = true;
				motion = 7;
			}
			else if (pattern == 1){
				actionflag = true;
				motion = 4;
			}
			else if (pattern == 2){
				mEnabledAttack = true;
				motion = 6;
			}
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
			motion = 1;
		}

		break;
	case 5:		//�U�������Ȃ���߂Â��Ă���
		Walk();
		if (RIGHT_PTT && !mEnabledAttack) {
			mStatus = E_ATTACK_R;
		}
		else if (LEFT_PTT && !mEnabledAttack){
			mStatus = E_ATTACK_L;
		}
		/*�͈�*/
		if (mEnabledAttack){
			mAttackRange.SetVertex(-SIZE_PLAYER_X, SIZE_PLAYER_Y, SIZE_PLAYER_X, -SIZE_PLAYER_Y);
			mAttackRange.SetColor(1.0f, 1.0f, 0.0f, 1.0f);
			if (RIGHT_PTT)mAttackRange.position = CVector2(mPos.x + 1, mPos.y);
			if (LEFT_PTT)mAttackRange.position = CVector2(mPos.x - 1, mPos.y);
			mAttackAxis = 2.0f;
		}
		if (mAnimeFrame == FRAME_LIMIT - 1){
			mEnabledAttack = false;//�U���I��
		}
		if (rulerR > 2 || rulerL > 2){
			actionflag = false;
			motion = 1;
		}
		break;

	case 6:		//�U����

		if (RIGHT_PTT && !mEnabledAttack) {
			mStatus = E_ATTACK_R;
		}
		else if (LEFT_PTT && !mEnabledAttack){
			mStatus = E_ATTACK_L;
		}
		/*�͈�*/
		if (mEnabledAttack){
			mAttackRange.SetVertex(-SIZE_PLAYER_X, SIZE_PLAYER_Y, SIZE_PLAYER_X, -SIZE_PLAYER_Y);
			mAttackRange.SetColor(1.0f, 1.0f, 0.0f, 1.0f);
			if (RIGHT_PTT)mAttackRange.position = CVector2(mPos.x + 1, mPos.y);
			if (LEFT_PTT)mAttackRange.position = CVector2(mPos.x - 1, mPos.y);
			mAttackAxis = 2.0f;
		}
		if (mAnimeFrame == FRAME_LIMIT - 1){
			mEnabledAttack = false;//�U���I��
		}
		if (rulerR > 2 || rulerL > 2){
			actionflag = false;
			motion = 1;
		}
		break;
	case 7:
		if (RIGHT_PTT && !mEnabledAttack) {
			mStatus = E_HATTACK_R;
		}
		else if (LEFT_PTT && !mEnabledAttack){
			mStatus = E_HATTACK_L;
		}
		/*�͈�*/
		if (mEnabledAttack){
			mAttackRange.SetVertex(-SIZE_PLAYER_X, SIZE_PLAYER_Y, SIZE_PLAYER_X, -SIZE_PLAYER_Y);
			mAttackRange.SetColor(1.0f, 1.0f, 0.0f, 1.0f);
			if (RIGHT_PTT)mAttackRange.position = CVector2(mPos.x + 1, mPos.y);
			if (LEFT_PTT)mAttackRange.position = CVector2(mPos.x - 1, mPos.y);
			mAttackAxis = 4.0f;
		}
		if (mAnimeFrame == FRAME_LIMIT - 1){
			mEnabledAttack = false;//�U���I��
		}
		if (rulerR > 2 || rulerL > 2){
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
	LimitDisp(SIZE_BOSS_X, SIZE_BOSS_Y);	//�����蔻��
	AnimeScene();
	if (mHitPoint == 0)mKillFlag = true;

	mShadow.position = CVector2(mPos.x, mAxis);

	mRect.position = mPos;
}

void CBoss::Render(){
	mShadow.Render();
	mRect.Render();
}
