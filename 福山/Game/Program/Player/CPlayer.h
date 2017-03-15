/*
*�v���C���[�̃v���O����
*�S���ҁ@�y�c���l
*/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "../Base/CBase.h"
#include "../Task/CTaskManager.h"
#include "../Graphic/CRectangle.h"
#include "../Task/CTaskManager.h"
#include "../Define/define.h"
#define NORMALATTACK_PATTERN 3 //�ʏ�U���̃p�^�[��

const float gravity = 0.01;	 //�d��

const	 CVector2 first_pos
= CVector2(character_limit_left*0.85, (character_limit_top + character_limit_bottom) / 2);		//�v���C���[�̏����ʒu

class CPlayer : public CBase {
private:

	float mVelocity; //�ړ�����Ƃ��Ɏg��
	CRectangle	mPlayer;
	CRectangle  mShadow;

	CTexture	*mStayTex[FRAME_LIMIT];									//�҂��e�N�X�`��
	CTexture	*mWalkTex[FRAME_LIMIT];									//�����e�N�X�`��
	CTexture	*mRunTex[FRAME_LIMIT];									//����e�N�X�`��
	CTexture	*mNormalAttackTex[NORMALATTACK_PATTERN][FRAME_LIMIT];	//�ʏ�U���e�N�X�`��
	CTexture	*mEatTex[FRAME_LIMIT];									//�ߐH�e�N�X�`��
	CTexture	*mEx01Tex[FRAME_LIMIT];									//�K�E�Z(����)�e�N�X�`��									
	CTexture	*mEx02Tex[FRAME_LIMIT];									//�K�E�Z(�p��)�e�N�X�`��
	CTexture	*mFlameTex[FRAME_LIMIT];								//���e�N�X�`��
	CTexture	*mBrakeTex[FRAME_LIMIT];								//�u���[�L�e�N�X�`��
	CTexture	*mShadowTex;											//�e�e�N�X�`���`��

	/*
	�������ǂ̃A�j���[�V���������f�p
	enum��
	*/

	enum EAnime
	{
		E_STAY_L, E_WALK_L,
		E_RUN_L, E_NORMALATTACK_A_L,
		E_NORMALATTACK_B_L, E_NORMALATTACK_C_L,
		E_EAT_L, E_EX01_L,
		E_EX02_L, E_FLAME_L,
		E_BRAKE_L,

		E_STAY_R, E_WALK_R,
		E_RUN_R, E_NORMALATTACK_A_R,
		E_NORMALATTACK_B_R, E_NORMALATTACK_C_R,
		E_EAT_R, E_EX01_R,
		E_EX02_R, E_FLAME_R,
		E_BRAKE_R,



	};

	int mStatus;
	int AnimePattern;				//�S�̂̃A�j���[�V�����p�^�[���傫��
	bool mEnabledJump;				//�W�����v���Ă���
	bool mEnabledNormalAttack;		//�ʏ�U�����Ă��邩���Ȃ���
	float mSpeedJump;				//�W�����v�̃X�s�[�h
	float mIntervalCount;			//Interval�֐��J�E���g�p

	CVector2 mTarget;
	CVector2 mSuvePos;				//�������ʒu�̕ۑ�

	/*�A�j���̃t���[�����v�Z�p �t���[�����𔻒f����^������*/
	void AnimeFlame();
	/*�ړ�������Axis���ς��Ƃ��Ɏg�p����*/
	void MovePosAxis();
	/*���������邩��m��֐�*/
	void Run_Walk();
	/*�W�����v�̊֐�*/
	void Jump();
	/*�����̃|�W�V�����ɂ���֐�*/
	void SetPos();
	/*�ړ����Ă���Ƃ�*/
	bool Move();
	/*�A�j���[�V�����̒l������,�Ԃ�l�ŉE���𔻒f*/
	void DecisionRL(int R,int L);
public:
	/*
	CCamera�Ŏg��XY
	*/
	static float camera_x;
	static float camera_y;

	CPlayer();
	~CPlayer();
	void Init();
	void Render();
	void Update();


};
#endif

