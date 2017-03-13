#pragma once
#include "CBase.h"
#include "CRectangle.h"


class CPlayer : public CBase {
public:

	CRectangle	m_Player;
	float		mVelocity;
	CTexture	*mpTexture;	//テクスチャの変数

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

	bool enabled_jump;//ジャンプいている
	float speed_jump; //ジャンプのスピード

	CVector2 mTarget;
	CVector2 suve_mpos;//元いた位置の保存

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

