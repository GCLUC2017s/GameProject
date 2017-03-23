/*
�L�����N�^�[�̃x�[�X�N���X
�S���ҁ@�y�c���l
*/
#ifndef BASE_HPP
#define BASE_HPP

#define SIZE_PLAYER_Y 1.0f							//�v���C���[�̃T�C�Y_Y
#define SIZE_PLAYER_X 0.8f						//�v���C���[�̃T�C�Y_X
#define SIZE_LOWBOSS_X 2.5f
#define SIZE_LOWBOSS_Y 2.5f

#define SIZE_ENEMY00_Y 1  //�G�l�~�[00�̃T�C�Y_Y
#define SIZE_ENEMY00_X 1 //�G�l�~�[00�̃T�C�Y_X
#define SIZE_ENEMY01_Y 1 //�G�l�~�[01�̃T�C�Y_Y
#define SIZE_ENEMY01_X 1 //�G�l�~�[01�̃T�C�Y_X
#define SIZE_BOSS_Y 3    //�G�l�~�[00�̃T�C�Y_Y
#define SIZE_BOSS_X 3    //�G�l�~�[00�̃T�C�Y_X
#define CAL_ENEMY00	0.2f  //�G�l�~�[�̃J�����[
#define CAL_ENEMY01 0.3f
#define CAL_BOSS	10
#define SIZE_SHADOW_X *mRect.mRRight*0.5f						//�e�̃T�C�YX
#define SIZE_SHADOW_Y *mRect.mRLeft	*0.2f					//�e�̃T�C�YY
#define SHADOW_TEX_X			70.f				//�e�̃e�N�X�`����X
#define SHADOW_TEX_Y			20.f				//�e�̃e�N�X�`����Y

#define PL_HP_X 2.0f //�Q�[�Wx�@ //HP�͂����炩��g���悤��(�����l)
#define PL_HP_Y 0.15f//�Q�[�Wy
#define PL_ST_X PL_HP_X*1.3	 //�Q�[�Wx
#define PL_ST_Y 0.45f//�Q�[�Wy
#define PL_ST_FR_Y 0.3f//�Q�[�Wy

#define SIZE_PL_FRAME_X PL_HP_X //�t���[���w
#define SIZE_PL_FRAME_Y 0.2f  //�t���[��Y			

#define ENE_HP_X 2.0f			//�G�l�~�[gauge�@(�����l)
#define ENE_HP_Y 0.2f			//�G�l�~�[gauge

#define SIZE_EN_FRAME_X ENE_HP_X*0.9			//�G�l�~�[�̃t���[��
#define SIZE_EN_FRAME_Y 0.15f			//�G�l�~�[�̃t���[��

#define SIZE_BOSS_FRAME_X	2.0f		
#define SIZE_BOSS_FRAME_Y	0.2f			
/*�o�k�`�x�d�q�̍U����*/
#define PL_NORMAL_POWER 0.05f
#define PL_JUMP_AT_POWER 0.07f
#define PL_EAT_POWER	0.06f
#define PL_EX01_POWER	0.15f
/*�G�l�~�[�̍U����*/
#define ENE00_POWER		0.0000000005f
#define ENE01_POWER		0.0000000005f
#define BOSS_JAB_POWER	0.001f
#define BOSS_HIGH_POWER	0.002f
/*�o�n�h�m�s*/
#define POINT_00		(int)100
#define POINT_01		(int)200
#define POINT_BOSS		(int)1000
#define POINT_PLAYER	(int)-2000
/*�G�l�~�[��*/
#define ENE00_LIMIT	3
#define ENE01_LIMIT	3
#define BOSS_LIMIT	1

#define TEX_FILE_SHADOW		"../CG/shadow/"		//�e�̃t�@�C���ꏊ
#include "../Task/CTask.h"
#include "../Vector/CVector2.h"
#include "../Define/define.h"
#include "../Graphic/CRectangle.h"
#include <time.h>

/*
�g����

CTask�ɂ��鏑���Ă���

int mPriorityR; //Rander()�̃i���o�[
int mPriorityU;//Update()�̃i���o�[

CBase ���p��������̂ɂ͕K������邱��
���������������̂ق�

*/


class CBase : public CTask{
private:

	float mFrameTime;				//bool �֐�	 FrameTie�v�Z�p
	int mFrameCount;				//���݂̃t���[����
	/*�A���[�g�֐��p*/
	float mSaveAlertHitoPoint;		//�A���[�g�p
	float mAlertCount;				//�A���[�g�J�E���g
	bool FlagAlertSetHp;			//�A���[�gHP�̏����ݒ�p

public:
	CTexture	*mShadowTex;		//�e�e�N�X�`���`��
	CVector2 mPos;					//�ʒu
	CVector2 mForward;				//����
	CRectangle  mRect;				//�摜�p
	CRectangle  mShadow;			//�e
	CRectangle mAttackRange;		//�U���͈͂̎l�p�`

	bool mEnabledEat;				//�L���t���O�@�H�ׂ�(�v���C���[)
	bool mEnabledEaten;				//�L���t���O �H�ׂ�ꂽ(�G�l�~�[)
	bool mEnabledAttack;		    //�U�����Ă��邩�ۂ�
	bool mEnabledJump;				//�W�����v���Ă���
	bool mEnabledEx01;				//�K�E�Z(����)
	bool mEnabledPoint;				//�|�C���g���Z���ꂽ���f

	float mHitPoint;				//�q�b�g�|�C���g
	float mAttackPoint;				//�U����
	float mStamina;					//�X�^�~�i

	int mSaveAnime;                 //�O�̃A�j���[�V�������ǂꂾ���������f�p
	float mAttackAxis;				//�U���̎��͈�
	bool mEnabledUi;			    //UI�����Ă���Ƃ� true
	int mAnimeFrame;				//�A�j���̃t���[����
	float mAxis;					//���@�g�����@mPos��'Y'��������(�W�����v�̎��ȂǁC�ړ��ȊO��'Y'�͑�����Ȃ�)
	int mStatus;					//���݉������Ă��邩�X�e�[�^�X
	static int kazu;				//�f�o�b�O�p					

	CVector2 mTargetP;  //�v���C���[�|�W�V�����̎擾�p
	
	CBase() : mEnabledEat(false),mEnabledEaten(false),mAxis(0), mHitPoint(0), mEnabledAttack(false), mAttackPoint(0.01f), mEnabledPoint(false), FlagAlertSetHp(false){
		mCharaFlag = true;
		mShadow.SetColor(0.5f, 0.5f, 0.5f, 0.4f);
		kazu += 1;
		srand(time(NULL));
	}

	/*�A�j���̃t���[�����v�Z�p  roop��true�Ȃ烋�[�v���� speed = Roop��Speed Frame = �t���[����*/
	void AnimeFrame(bool roop, int speed);
	/*�I�[�_�[���������̂Œǉ�*/
	void AnimeFrame(bool roop, int speed,int frame);
	/*�g���� sizex,sizey�ɉ摜�̃T�C�Y������*/
	void LimitDisp(int sizex, int sizey);
	/*�����_��pos����*/
	void RandLimitDisp(int sizex, int sizey,int limitleft,int limitright);
	/*
	�U���͈͂����߂�
	�x�[�X�ɂ���ϐ����g��
	float Forword�͌��݂̌���������
	0�ȏ�@���@�E
	0�����@��  ��
	float x , y , mAxis �͍U���͈� ,Cvector2�́@������pos������
	*/
	void Attack(float Forword, float x, float y, float mAxis, CVector2 &mPos);
	/*��]rect�֐�*/
	void TurnRect(CRectangle *rect);
	void JumpAttack(float Forword, float x, float y, float mAxis, CVector2 &mPos);
	bool FrameTime(float time);
	void RandPos(int x, int y, CVector2 *mPos,int limitleft ,int limitright);		//�|�W�V�����������_���ɂ���	�T�C�Y��x,y�ɓ��Ă͂߂�
	/*HP�ɂ��A���[�g�֐�*/
	void AlertHPRect(CRectangle *rect,float &Hp);

};
#endif
