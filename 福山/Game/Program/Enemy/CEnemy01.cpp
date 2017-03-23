#include "CEnemy01.h"
#include "../MyNumber/CMyNumber.h"
#include "stdio.h"
#include <cstdlib>
#include<time.h>
#include<iostream>
#include "CEnemybasetest.h"
#include "../CGame/CGame.h"
#include "../Load/CLoadEnemy01.h"
#include "../Load/CLoadPlayer.h"
/*
�q�R�[�X�P�[�`
*/

/*
CKey���g���Ă���������͍���ʂ̏����ɂȂ�܂��B

�����O��
*/

#define SIZE_ENEMY00_Y 1  //�G�l�~�[01�̃T�C�Y_Y
#define SIZE_ENEMY00_X 1 //�G�l�~�[01�̃T�C�Y_X

#define FIRST_R_NO_PL 1						//���߂̃����_�[�̃|�C���g
#define FIRST_U_NO_PL 1						//���߂̃A�b�v�f�[�g�̃|�C���g
#define SIZE_TEX_ENEMY00_STAY_X 160			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y X
#define SIZE_TEX_ENEMY00_STAY_Y 160		//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y Y
#define SIZE_TEX_ENEMY00_WALK_X 160			//�G�l�~�[�̕����e�N�X�`���T�C�Y Y
#define SIZE_TEX_ENEMY00_WALK_Y 160			//�G�l�~�[�̕����p�e�N�X�`���T�C�Y Y
#define SIZE_SHADOW							//�e�̕\��
#define WALK_SPEED 0.055		//�e�X�g�p�ɂ������Ă�				//��s�X�s�[�h
#define WALK_X 2							//��s�x�N�g��X
#define WALK_Y 1							//��s�x�N�g��Y
#define ANIME_TIME_BASE						6
#define ANIME_TIME_ATTACK					6	

#define ENEMY01_FLAY "../CG\\enemy01\\fly\\"
#define ENEMY01_STAY "../CG\\enemy01\\stay\\"
#define ENEMY01_ATTACK "../CG\\enemy01\\attack\\"
#define ENEMY01_DIE "../CG\\enemy01\\die\\"
#define AT_RANGE01		mForward.x, SIZE_ENEMY01_X, SIZE_ENEMY01_X,10, mPos	//�U���͈�A



void CEnemy01::Init(){
	RandPos(SIZE_ENEMY01_X, SIZE_ENEMY01_Y, &mPos,-DISP_X,DISP_X*10);
	/*�e�N�X�`���𒣂�*/
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mRect.SetUv(CLoadEnemy01::GetInstance()->mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

}



CEnemy01::~CEnemy01(){
}

//�G�l�~�[01�`��
CEnemy01::CEnemy01() : mVelocity(0), mFrameCount(0), actionflag(false), motion(EM_STAY), direction(E_LEFT){
	mPriorityR = E_ENEMY01;			//Render�̃i���o�[ 
	mPriorityU = E_ENEMY01;			//Update�̃i���o�[
	mHitPoint = ENE_HP_X;		//�g�o
	mMyNumber = E_ENEMY01;

	//�l�p�`�̒��_�ݒ�
	mRect.SetVertex(-SIZE_ENEMY00_X, SIZE_ENEMY00_Y, SIZE_ENEMY00_X, -SIZE_ENEMY00_Y);
	mShadow.SetVertex(-SIZE_SHADOW_X, SIZE_SHADOW_Y, SIZE_SHADOW_X, -SIZE_SHADOW_Y);
	//�l�p�`�̐F��ݒ�
	mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

}


void CEnemy01::AnimeScene(){

	/*�A�j���[�V�����̃X�e�[�^�X*/
	switch (mStatus)
	{
		/*�ҋ@��*/
	case E_STAY_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mStay_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_STAY_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mStay_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*������*/
	case E_FLY_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mFly_tex[mAnimeFrame], SIZE_TEX_ENEMY00_WALK_X, 0, 0, SIZE_TEX_ENEMY00_WALK_Y);
		break;
	case E_FLY_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mFly_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_WALK_X, SIZE_TEX_ENEMY00_WALK_Y);
		break;
		/*�U����*/
	case E_ATTACK_R:
		AnimeFrame(true, ANIME_TIME_ATTACK,FRAME_LIMIT9);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mAttack_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_ATTACK_L:
		AnimeFrame(true, ANIME_TIME_ATTACK,FRAME_LIMIT9);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mAttack_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;
		/*���S*/
	case E_DIE_R:
		AnimeFrame(false, ANIME_TIME_BASE,FRAME_LIMIT11);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mDie_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_DIE_L:
		AnimeFrame(false, ANIME_TIME_BASE, FRAME_LIMIT11);
		mRect.SetUv(CLoadEnemy01::GetInstance()->mDie_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;

	}
}

void CEnemy01::Fly(){

	//�i�^�[�Q�b�g���E�ɂ���ꍇ�j
	if (RIGHT_PTT) {
		direction = E_RIGHT;
		mStatus = E_FLY_R;
		mVelocity = WALK_SPEED;
		mForward = CVector2(WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}

	//�i�^�[�Q�b�g�����ɂ���ꍇ�j
	if (LEFT_PTT) {
		direction = E_LEFT;
		mStatus = E_FLY_L;
		mVelocity = WALK_SPEED;
		mForward = CVector2(-WALK_X, 0.0f);
		mPos += mForward * mVelocity;
	}


	//�i�^�[�Q�b�g����ɂ���ꍇ�j
	if (getAxis > mAxis) {
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;

	}

	//�i�^�[�Q�b�g�����ɂ���ꍇ�j
	if (getAxis< mAxis) {
		mVelocity = WALK_SPEED;
		mForward = CVector2(0.0f, -WALK_Y);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;
	}


}

void CEnemy01::Motion(){

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
		Fly();

		if (ATTACK_PTTX&&ATTACK_PTTY){//�U�����[�V�����ɕύX
			actionflag = false;
			motion = EM_RANGE;
		}

		break;
	case EM_RANGE://�U���͈͓��ɓ�������

		if (!actionflag){
			pattern = rand() % 4; //0~3�̒��Ń����_���Ńp�^�[����I������B
		}
		if (pattern == 0){
			motion = EM_ATTACK;
		}
		else if (pattern == 1){
			actionflag = true;
			motion = EM_BACK_UP;
		}
		else if (pattern == 2){

			motion = EM_BACK_UP;
		}
		else if (pattern == 3){

			motion = EM_BACK_Y;
		}
		
		break;

	case EM_DIE://���S
		if (direction == E_RIGHT) {
			mStatus = E_DIE_R;
		}
		else if (direction == E_LEFT){
			mStatus = E_DIE_L;
		}
		break;

	case EM_BACK_X://���ɓ�����B

		if (direction == E_LEFT) {
			direction = E_LEFT;
			mVelocity = WALK_SPEED * 2;	//�R�{���œ�����
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;

		}
		else if (direction == E_RIGHT){
			direction = E_RIGHT;
			mVelocity = -WALK_SPEED * 2;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;
		}

		if (ENEMY_ESCAPE){	//��苗�������ƍēx������Ɍ������Ă���
			actionflag = false; //actionflag��false�ɂ���B
			motion = EM_WALK;
		}

		break;
	case EM_BACK_UP:		//�L�����̌��ɍs�����Ƃ���

	
		if (direction == E_LEFT) {
			direction = E_LEFT;
			mVelocity = -WALK_SPEED * 2;	//2�{���ŉ�荞��
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;
			if (rulerR >5){
				motion = EM_RANGE;
			}

		}
		else if (direction == E_RIGHT){
			direction = E_RIGHT;
			mVelocity = WALK_SPEED * 2;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;

			if (rulerL >5){
				motion = EM_RANGE;
			}
		}
		if (ENEMY_ESCAPE){	//��苗�������ƍēx������Ɍ������Ă���
			actionflag = false; //actionflag��false�ɂ���B
			motion = EM_WALK;
		}
		
		break;

	case EM_BACK_Y:	//�c�������炻���Ƃ���

			mVelocity = WALK_SPEED * 2;	//��{�̑��x�ŉ��ɍ~��悤�Ƃ���
			mForward = CVector2(0.0f, -WALK_Y);
			mPos += mForward * mVelocity;
			mAxis += mForward.y * mVelocity;
			if (mAxis <= character_limit_bottom+0.7f){
				motion = EM_ATTACK;
				actionflag = false;
				break;
			}
		if (NO_ATTACK_PTTX&&NO_ATTACK_PTTY){
			actionflag = false;
			motion = EM_WALK;
		}

		break;
	case EM_ATTACK:		//�U����
		attacktime += ENEMY01_INTERVAL / FPS;
		if (RIGHT_PTT) {
			mEnabledAttack = true;
			mStatus = E_ATTACK_R;
		}
		else{
			mEnabledAttack = true;
			mStatus = E_ATTACK_L;
		}

		/*�͈�*/
		Attack(AT_RANGE01);

			mEnabledAttack = true;
		

		/*�U���͈͂ɋ������l�߂�*/
		if (NO_ATTACK_PTTX||NO_ATTACK_PTTY||attacktime>=ENEMY01_INTERVAL){
			attacktime = 0;
			mEnabledAttack = false;
			actionflag = false;
			motion = EM_WALK;
		}
		break;
	}
}

void CEnemy01::Update(){

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
		motion = EM_DIE;		//�̗͂��O�Ȃ�DIE����
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

	mAttackRange.position = mPos;
	
	AlertHPRect(&mRect, mHitPoint);	//�A���[�g���\�b�h(HP�ω��ɂ�����)
	/*���̐ݒ�*/
	mAxis = mPos.y - SIZE_ENEMY01_Y;
	/*�͈͊O����*/
	LimitDisp(SIZE_ENEMY01_X, SIZE_ENEMY01_Y);
	/*�����_�[���Ԑݒ�*/
	mPriorityR = -mAxis;
	AnimeScene();
	mRect.position = mPos;
	mShadow.position = CVector2(mPos.x, mAxis);


}







void CEnemy01::Render(){
	mShadow.Render();
	mRect.Render();
}
