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
= CVector2(character_limit_left*0.85f, (character_limit_top + character_limit_bottom) / 2);		//�v���C���[�̏����ʒu


class CPlayer : public CBase {
private:

	CRectangle	mAttackCollision[NORMALATTACK_PATTERN]; //�����蔻�肾���̎l�p�`

	CTexture	*mStayTex[FRAME_LIMIT];									//�҂��e�N�X�`��
	CTexture	*mWalkTex[FRAME_LIMIT];									//�����e�N�X�`��
	CTexture	*mRunTex[FRAME_LIMIT];									//����e�N�X�`��
	CTexture	*mNormalAttackTex[NORMALATTACK_PATTERN][FRAME_LIMIT];	//�ʏ�U���e�N�X�`��
	CTexture	*mEatTex[FRAME_LIMIT];									//�ߐH�e�N�X�`��
	CTexture	*mEx01Tex[FRAME_LIMIT];									//�K�E�Z(����)�e�N�X�`��									
	CTexture	*mEx02Tex[FRAME_LIMIT];									//�K�E�Z(�p��)�e�N�X�`��
	CTexture	*mFlameTex[FRAME_LIMIT];								//���e�N�X�`��
	CTexture	*mBrakeTex[FRAME_LIMIT];								//�u���[�L�e�N�X�`��
	CTexture	*mJumpTex[FRAME_LIMIT];												//�W�����v�e�N�X�`��
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
		E_JUMP_L, E_BRAKE_L,

		E_STAY_R, E_WALK_R,
		E_RUN_R, E_NORMALATTACK_A_R,
		E_NORMALATTACK_B_R, E_NORMALATTACK_C_R,
		E_EAT_R, E_EX01_R,
		E_EX02_R, E_FLAME_R,
		E_JUMP_R, E_BRAKE_R,



	};

	float mSpeedJump;				//�W�����v�̃X�s�[�h
	float mEx01Speed;				//�K�E�Z�̐i�ރX�s�[�h
	float mHungryPower;				//���Ȃ������錸��Ȃ��̗͂̕ω� += ���Ďg��(�U����)
	float mHungrySSpp;				//���Ȃ������錸��Ȃ��̗͂̕ω� += ���Ďg��(�X�s�[�h)
	bool mEnabledInterval;			//Interval������Ƃ�
	
	
	CVector2 mTarget;
	CVector2 mSuvePos;				//�������ʒu�̕ۑ�
	CVector2 mSaveForword;			//�O�̉E�����f

	/*�ړ�����*/
	void Move();
	/*���邩�ۂ� ��v�͕����̒l������*/
	void RunWalk(CVector2 v);
	/*BRAKE���\�b�h*/
	void Brake();
	/*�W�����v�̊֐�*/
	void Jump();
	/*�����̃|�W�V�����ɂ���֐�*/
	void SetPos();
	/*�ړ����Ă���Ƃ�*/
	void EnabledMove();
	/*�A�j���[�V�����̒l������,�����ŉE���𔻒f R��*/
	void DecisionRL(int R, int L);
	/*BRAKE���邩�ۂ�*/
	bool EnabledBrake();
	/*�U���������\�b�h*/
	void PlayerAttack();
	/*�A�j���[�V�����V�[��*/
	void AnimeScene();
	/*�\�͕ω��̃��\�b�h*/
	void ChangeStatus();
public:
	/*
	CCamera�Ŏg��XY
	*/

	float mVelocity; //�ړ�����Ƃ��Ɏg��
	static float camera_x;
	static float camera_y;

	CPlayer();
	~CPlayer();
	void Init();
	void Render();
	void Update();


};
#endif

