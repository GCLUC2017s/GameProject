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
const float player_limit_left = -MAP_LIMIT_X / 2;				//�o�k���i�߂���(��)
const float player_limit_top = MAP_LIMIT_Y / 4;			   //�o�k���i�߂���(��)
const float player_limit_right = MAP_LIMIT_X / 2;			 //�o�k���i�߂���(�E)
const float player_limit_bottom = -MAP_LIMIT_Y / 2;			//�o�k���i�߂���(��)

const	 CVector2 first_pos
= CVector2(player_limit_left*0.85, (player_limit_top + player_limit_bottom) / 2);		//�v���C���[�̏����ʒu

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
	enum MyEnum
	{
		E_STAY_L,	E_STAY_R,
		E_WALK_L,	E_WALK_R,
		E_RUN_L,	E_RUN_R,
		E_JUMP_L,	E_JUMP_R,
	};

	MyEnum eAnime = E_STAY_R;
	int mSave_eAnime; //���O�̃A�j�����������f�p

	int mFlameCount;		//�t���[�����J�E���g�p
	int mAnime;		//�A�j���[�V�����̃t���[����

	bool mEnabledJump;//�W�����v���Ă���
	float mSpeedJump; //�W�����v�̃X�s�[�h

	CVector2 mTarget;
	CVector2 mSuvePos;//�������ʒu�̕ۑ�

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

