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

#define FLAME_LIMIT 6 //�t���[�����̏��


const float gravity = 0.01;										//�d��

const	 CVector2 first_pos
= CVector2(character_limit_left*0.85, (character_limit_top + character_limit_bottom) / 2);		//�v���C���[�̏����ʒu

class CPlayer : public CBase {
private:

	float mVelocity; //�ړ�����Ƃ��Ɏg��
	CRectangle	mPlayer;
	CRectangle  mShadow;
	CTexture	*mStay_tex[FLAME_LIMIT];
	CTexture	*mWalk_tex[FLAME_LIMIT];
	CTexture	*mRun_tex[FLAME_LIMIT];

	/*
	�������ǂ̃A�j���[�V���������f�p
	enum��
	*/
	enum EAnime
	{
		E_STAY_L,	E_JUMP_L,
		E_WALK_L,	E_RUN_L,	
		E_RUN_R,	E_JUMP_R,
		E_WALK_R,	E_STAY_R,
	};

	EAnime eAnime = E_STAY_R;
	int AnimePattern = sizeof(EAnime);
	int mSaveAnime; //���O�̃A�j�����������f�p

	int mFlameCount;		//�t���[�����J�E���g�p
	int mAnime;		//�A�j���[�V�����̃t���[����

	bool mEnabledJump;//�W�����v���Ă���
	float mSpeedJump; //�W�����v�̃X�s�[�h

	CVector2 mTarget;
	CVector2 mSuvePos;//�������ʒu�̕ۑ�

	void MovePosAxis();
	int DecisionRL(int i); //�A�j���[�V�����̒l������,�Ԃ�l�ŉE���𔻒f
	void Run_Walk();
	void AnimeFlame();
	void Jump(); 
	void SetPos();
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

