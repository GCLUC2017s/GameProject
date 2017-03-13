#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "CBase.h"
#include "CRectangle.h"


class Enemy00 : public CBase {
public:

	CRectangle	m_Enemy00;
	float		mVelocity;
	CTexture	*mpTexture;	//テクスチャの変数

	~Enemy00();

	int status;
	int muki;
	int sttime;
	int framecnt;
	int framecnt2;
	int toumeiframe;

	bool enabled_jump;//ジャンプしている
	float speed_jump; //ジャンプのスピード

	CVector2 mTarget;
	CVector2 suve_mpos;//元いた位置の保存

	Enemy00();
	void MethodJump();
	void init();
	void update();
	void render();
	void setPos(int row, int col);

	void setPos();

	//	void setPos(int row, int col, CVector2 fwd);

	//	CVector2 getPos(int index);
};
#endif