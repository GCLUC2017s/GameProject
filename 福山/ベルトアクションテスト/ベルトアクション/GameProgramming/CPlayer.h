#pragma once
#include "CBase.h"
#include "CRectangle.h"


class CPlayer : public CBase {
public:

	CRectangle	m_Player;
	float		mVelocity;
	CTexture	*mpTexture;	//�e�N�X�`���̕ϐ�

	~CPlayer();

	int status;
	int muki;
	int sttime;
	int framecnt;
	int framecnt2;
	int toumeiframe;/*
	int a=0;
	double jump = 1.0;
	
	int jumps=false;*/

	bool enabled_jump;//�W�����v���Ă���
	float speed_jump; //�W�����v�̃X�s�[�h

	CVector2 mTarget;
	CVector2 suve_mpos;//�������ʒu�̕ۑ�

	CPlayer();
	void MethodJump();
	void init();
	void update();
	void render();
	void setPos(int row, int col);

	void setPos();

//	void setPos(int row, int col, CVector2 fwd);

//	CVector2 getPos(int index);
};

