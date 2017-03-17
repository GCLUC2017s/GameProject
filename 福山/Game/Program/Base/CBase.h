/*
�S���ҁ@�y�c���l�@&&
*/
#ifndef BASE_HPP
#define BASE_HPP

#define SIZE_PLAYER_Y 1.0f*2							//�v���C���[�̃T�C�Y_Y
#define SIZE_PLAYER_X 0.8f*2						//�v���C���[�̃T�C�Y_X
#define SIZE_SHADOW_X 0.4f						//�e�̃T�C�YX
#define SIZE_SHADOW_Y 0.4f						//�e�̃T�C�YY
#define SHADOW_TEX_X			70.f				//�e�̃e�N�X�`����X
#define SHADOW_TEX_Y			20.f				//�e�̃e�N�X�`����Y



#define PL_HP_X 2.0f //�Q�[�Wx�@
#define PL_HP_Y 0.15f//�Q�[�Wy

#define SIZE_PL_FRAME_X 2.2f //�t���[���w
#define SIZE_PL_FRAME_Y 0.2f //�t���[��Y			

#define ENE_HP_X 2.0f			//�G�l�~�[gauge
#define ENE_HP_Y 0.15f			//�G�l�~�[gauge

#define SIZE_EN_FRAME_X 1.0f			//�G�l�~�[�̃t���[��
#define SIZE_EN_FRAME_X 1.0f			//�G�l�~�[�̃t���[��

#define SIZE_BOSS_FRAME_X	2.0f		
#define SIZE_BOSS_FRAME_Y	0.2f			



#define TEX_FILE_SHADOW		"../CG/shadow/"		//�e�̃t�@�C���ꏊ
#define FRAME_LIMIT 6							//�A�j���̃t���[����(�����^)		
#include "../Task/CTask.h"
#include "../Vector/CVector2.h"
#include "../Define/define.h"
#include "../Graphic/CRectangle.h"


const float character_limit_left = -MAP_LIMIT_X / 2;			//�i�߂���(��)
const float character_limit_top = MAP_LIMIT_Y / 4;			   //�i�߂���(��)
const float character_limit_right = MAP_LIMIT_X / 2;		 //�i�߂���(�E)
const float character_limit_bottom = -MAP_LIMIT_Y / 2;		//�i�߂���(��)


/*
�g����

CTask�ɂ��鏑���Ă���

int mPriorityR; //Rander()�̃i���o�[
int mPriorityU;//Update()�̃i���o�[

CBase ���p��������̂ɂ͕K������邱��
���������������̂ق�

*/


class CBase : public CTask{
public:
	CVector2 mPos;					//�ʒu
	CVector2 mForward;				//����
	CRectangle mRect;				//�摜�p
	CRectangle mAttackRange;		//�U���͈͂̎l�p�`
	bool mEnabled;					//�L���t���O
	float mHitPoint;				//�q�b�g�|�C���g
	bool mEnabledAttack;		    //�U�����Ă��邩�ۂ�
	int mSaveAnime;                 //�O�̃A�j���[�V�������ǂꂾ���������f�p
	int mFrameCount;				//���݂̃t���[����
	float mAttackAxis;				//�U���̎��͈�
	bool mEnabledUi;					//UI�����Ă���Ƃ� true
	int mAnimeFrame;				//�A�j���̃t���[����
	float mAxis;					//���@�g�����@mPos��'Y'��������(�W�����v�̎��ȂǁC�ړ��ȊO��'Y'�͑�����Ȃ�)
	int mAlertCnt;					//
	int mStatus;
	bool mEnabledJump;				//�W�����v���Ă���

	
	CBase() : mEnabled(true), mAlertCnt(0), mAxis(0), mHitPoint(0), mEnabledAttack(false),mEnabledUi(true){
		mCharaFlag = true;
	}

	/*�A�j���̃t���[�����v�Z�p  roop��true�Ȃ烋�[�v���� speed = Roop��Speed*/
	void AnimeFrame(bool roop, int speed);
	/*�g���� sizex,sizey�ɉ摜�̃T�C�Y������*/
	void LimitDisp(int sizex, int sizey);

};
#endif
