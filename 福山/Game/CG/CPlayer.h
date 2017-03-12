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
#define JUMP_FIRST_SPEED 0.2
#define ANIME_PLAYER 6

class CPlayer : public CBase {
public:

	CRectangle	mPlayer;
	float		mVelocity;
	CTexture	*mStay_tex[ANIME_PLAYER];
	CTexture	*mWalk_tex[ANIME_PLAYER];


	CPlayer();
	~CPlayer();

	int status;
	int sttime;
	int framecnt;
	int framecnt2;
	int toumeiframe;

	bool enabled_jump;//�W�����v���Ă���
	float speed_jump; //�W�����v�̃X�s�[�h

	CVector2 mTarget;
	CVector2 suve_mpos;//�������ʒu�̕ۑ�

	void Jump(); 
	void Init();

	void Render();

	void Update();

	void SetPos(int row, int col);
	void SetPos();

};
#endif

