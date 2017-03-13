/*
*�v���C���[�̃v���O����
*�S���ҁ@�y�c���l
*/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "CBase.h"
#include "CTaskManager.h"
#include"CBase.h"
#include "CRectangle.h"
#include "define.h"
#include "CMyNumber.h"
#define JUMP_FIRST_SPEED 0.2
#define FLAME_LIMIT 6 //�t���[�����̏��

class CPlayer : public CBase {
public:

	CRectangle	mPlayer;
	CRectangle  mShadow;
	float		mVelocity;
	CTexture	*mStay_tex[FLAME_LIMIT];
	CTexture	*mWalk_tex[FLAME_LIMIT];
	CTexture	*mJump_tex[FLAME_LIMIT];
	CTexture	*mRun_tex[FLAME_LIMIT];

	CPlayer();
	~CPlayer();
	/*
	�������ǂ̃A�j���[�V���������f�p
	enum��
	*/
	enum MyEnum
	{
		E_STAY_L,	E_STAY_R,
		E_WALK_L,	E_WALK_R,
		E_RUN_L,	E_RUN_R,
		E_JUMP_L,	E_JUMP_R,
	};

	MyEnum eAnime = E_STAY_R;
	int save_eAnime; //���O�̃A�j�����������f�p

	/*
	CCamera�Ŏg��XY
	*/
	static float camera_x;
	static float camera_y;

	int mFlame_Count;		//�t���[�����J�E���g�p
	int mAnime;		//�A�j���[�V�����̃t���[����

	bool enabled_jump;//�W�����v���Ă���
	float speed_jump; //�W�����v�̃X�s�[�h

	CVector2 mTarget;
	CVector2 suve_mpos;//�������ʒu�̕ۑ�

	void AnimeFlame();
	void Jump(); 
	void Init();

	void Render();

	void Update();

	void SetPos();

};
#endif

