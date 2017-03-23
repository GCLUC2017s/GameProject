#include "CEnemy00.h"
#include "../MyNumber/CMyNumber.h"
#include "../CGame/CGame.h"
#include "stdio.h"
#include <cstdlib>
#include<time.h>
#include<iostream>
#include "CEnemybasetest.h"
#include "../Load/CLoadEnemy00.h"
#include "../Base/CBase.h"
/*

�����O��

*/
#define FIRST_R_NO_ENEMY00 1						//���߂̃����_�[�̃|�C���g
#define FIRST_U_NO_ENEMY00 1						//���߂̃A�b�v�f�[�g�̃|�C���g
#define SIZE_TEX_ENEMY00_STAY_X 160			//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y X
#define SIZE_TEX_ENEMY00_STAY_Y 160		//�G�l�~�[�̑҂��p�e�N�X�`���T�C�Y Y
#define SIZE_TEX_ENEMY00_WALK_X 160		//�G�l�~�[�̕����e�N�X�`���T�C�Y Y
#define SIZE_TEX_ENEMY00_WALK_Y 160		//�G�l�~�[�̕����p�e�N�X�`���T�C�Y Y
#define SIZE_SHADOW							//�e�̕\��
#define PATTERN_R 1							//PATTERN�̉E
#define PATTERN_L 2							//PATTERN�̍�

#define ANIME_TIME_BASE						6							//�A�j���̃��[�v���� �p���I�Ȃ���
#define ANIME_TIME_ATTACK					6							//�A�j���̃��[�v���� �U���̂���

#define WALK_SPEED 0.02f				//�����X�s�[�h
#define WALK_X 2						//�����x�N�g��X
#define WALK_Y 1						//�����x�N�g��Y

#define AT_RANGE00		mForward.x, SIZE_ENEMY00_X*1.5, SIZE_ENEMY00_Y,2, CVector2(mPos.x+mForward.x*0.1,mPos.y) 

#define ENEMY00_STAY "../CG\\enemy00\\enemy00_stay\\"
#define ENEMY00_WALK "../CG\\enemy00\\enemy00_walk\\"
#define ENEMY00_ATTACK "../CG\\enemy00\\enemy00_attack\\"
#define ENEMY00_DIE "../CG\\enemy00\\enemy00_dai\\"
#include "../Load/CLoadPlayer.h"


void CEnemy00::Init(){
	RandPos(SIZE_ENEMY00_X, SIZE_ENEMY00_Y, &mPos,  DISP_X*3, DISP_X * 10);
	/*�e�N�X�`���𒣂�*/
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mRect.SetUv(CLoadEnemy00::GetInstance()->mStay_tex[0], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
	mForward = CVector2(1.0f, 0.0f);

	srand((unsigned int)time(NULL));

}



//�G�l�~�[00�`��
CEnemy00::CEnemy00() : mVelocity(0), mFrameCount(0), actionflag(false), motion(EM_STAY), direction(E_LEFT), escapetime(0), attacktime(0) {

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
		AnimeFrame(false, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mDie_tex[mAnimeFrame], SIZE_TEX_ENEMY00_STAY_X, 0, 0, SIZE_TEX_ENEMY00_STAY_Y);
		break;
	case E_DIE_L:
		AnimeFrame(false, ANIME_TIME_BASE);
		mRect.SetUv(CLoadEnemy00::GetInstance()->mDie_tex[mAnimeFrame], 0, 0, SIZE_TEX_ENEMY00_STAY_X, SIZE_TEX_ENEMY00_STAY_Y);
		break;

	}
}

void CEnemy00::Walk(){

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

void CEnemy00::Motion(){

	switch (motion)
	{
	case EM_STAY://�ҋ@
	{
		pattern = rand() % 4;//����s����4������o��
		
		if (direction == E_RIGHT){	//�E����
			mStatus = E_STAY_R;
		}
		else if (direction = E_LEFT){	//������

			mStatus = E_STAY_L;
		}

		if (ENEMY_VISI)		//���E���ɂƂ炦����ǂ��Ă���(�����I�ȏ���s���̊J�n)
		
			if (pattern == 0){
				motion = EM_WALK;	//�ʏ�̃E�H�[�N����ɓ���
			
			}
			if (pattern == 1){
				motion = EM_BACK_Y;
			
			}
			if (pattern == 2){
				motion = EM_Slanting;
			
			}
			if (pattern == 3){
				motion = EM_BACK_X;
		
			}
	
	
		}

		break;
	case EM_WALK://����	
		Walk();

		if (ATTACK_PTTX&&ATTACK_PTTY){//�U�����[�V�����ɕύX
			actionflag = false;
			motion = EM_RANGE;
		}

		break;
	case EM_RANGE://�U���͈͓��ɓ�������

			if (!actionflag){
				pattern = rand() % 3; //0~2�̒��Ń����_���Ńp�^�[����I������B

				if (pattern == 0 && ATTACK_PTTY){
					motion = EM_ATTACK;
					delay = 0;
				}
				else if (pattern == 1){
					actionflag = true;
					motion = EM_BACK_X;
					delay = 0;
				}
				else if (pattern == 2){
					motion = EM_BACK_Y;
					delay = 0;
				}

				if (NO_ATTACK_PTTX&&NO_ATTACK_PTTY){
					actionflag = false;
					motion = EM_WALK;
					delay = 0;
				}
			
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
		escapetime += ESCAPE_TIME / FPS;
		

		if (direction == E_LEFT) {
			direction = E_LEFT;
			mVelocity = WALK_SPEED * 3;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;

		}
		else if (direction == E_RIGHT){
			direction = E_RIGHT;
			mVelocity = -WALK_SPEED * 3;
			mForward = CVector2(WALK_X, 0.0f);
			mPos += mForward * mVelocity;
		}

		if (escapetime>=ESCAPE_TIME){	//��苗�������ƍēx������Ɍ������Ă���
			escapetime = 0;
			motion = EM_WALK;
		}

		break;
	case EM_BACK_Y:		//�㉺�ɓ�����
	
	
		if (mAxis < getAxis){
			mVelocity = WALK_SPEED * 3;
			mForward = CVector2(0.0f, -WALK_Y);
			mPos += mForward * mVelocity;
			mAxis += mForward.y * mVelocity;
			if (mAxis == character_limit_bottom){
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
			if (mAxis == character_limit_top){
				motion = EM_WALK;
				actionflag = false;
				break;
			}
		}

	case EM_ATTACK:		//�U����
		attacktime += ENEMY00_INTERVAL / FPS;

		if (attacktime < ENEMY00_INTERVAL){
			if (RIGHT_PTT) {
				actionflag = true;
				mEnabledAttack = true;
				mStatus = E_ATTACK_R;
			}
			else if (LEFT_PTT){
				actionflag = true;
				mEnabledAttack = true;
				mStatus = E_ATTACK_L;
			}
		}
		//�U���͈͂Ƃ����蔻��t���O

		if (NO_ATTACK_PTTX){
			actionflag = false;
			motion = EM_WALK;
			mEnabledAttack = false;
		}
		if (NO_ATTACK_PTTY || attacktime >= ENEMY00_INTERVAL + ENEMY00_DELAY){
			attacktime = 0;
			actionflag = false;
			motion = EM_RANGE;
			mEnabledAttack = false;
		}
		Attack(AT_RANGE00);
		break;

	case EM_Slanting:
		escapetime += ESCAPE_TIME / FPS;

		if (direction == E_LEFT) {
			direction = E_LEFT;
			mVelocity = WALK_SPEED * 1.5f;
			mForward = CVector2(WALK_X, WALK_Y);
			mPos += mForward * mVelocity;

		}
		else if (direction == E_RIGHT){
			direction = E_RIGHT;
			mVelocity = -WALK_SPEED * 1.5f;
			mForward = CVector2(WALK_X, -WALK_Y);
			mPos += mForward * mVelocity;
		}

		if (ENEMY_ESCAPE || escapetime >= ESCAPE_TIME){	//��苗�������ƍēx������Ɍ������Ă���
			escapetime = 0;
			motion = EM_WALK;
		}





		break;
	}

}

void CEnemy00::Update(){
	mRect.position = mPos;
	//mTargetP��player�ɂ���
	mTargetP = CGame::mGetPlayerPos();
	getAxis = CGame::GetPlayerAxis();
	
	rulerR = mTargetP.x - mPos.x;	//�v���C���[�Ƃ̋������o��		//���̂�����̏����͑S�G�l�~�[���ʂȂ̂łǂ����Ɉڂ������B
	rulerL = mPos.x- mTargetP.x;
	if (rulerL<0){				//��Βl�ɂ���
		rulerL = rulerL * -1;
	}
	if (rulerR<0){
		rulerR = rulerR * -1;
	}
	
	upruler = mTargetP.y-mPos.y;
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
