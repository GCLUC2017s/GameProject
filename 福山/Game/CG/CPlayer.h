/*
*プレイヤーのプログラム
*担当者　冨田健斗
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
#define FLAME_LIMIT 6 //フレーム数の上限

class CPlayer : public CBase {
public:

	CRectangle	mPlayer;
	CRectangle  mShadow;
	float		mVelocity;
	CTexture	*mStay_tex[FLAME_LIMIT];
	CTexture	*mWalk_tex[FLAME_LIMIT];

	CPlayer();
	~CPlayer();
	/*
	自分がどのアニメーションか判断用
	enum文
	*/
	enum MyEnum
	{
		E_STAY_L,	E_STAY_R,
		E_WALK_L,	E_WALK_R,
		E_RUN_L,	E_RUN_R,
		E_JUMP_L,	E_JUMP_R,
	};

	MyEnum eAnime = E_STAY_R;
	int save_eAnime; //直前のアニメが何か判断用

	/*
	CCameraで使うXY
	*/
	static float camera_x;
	static float camera_y;

	int mFlame_Count;		//フレーム数カウント用
	int mAnime;		//アニメーションのフレーム数

	bool enabled_jump;//ジャンプいている
	float speed_jump; //ジャンプのスピード

	CVector2 mTarget;
	CVector2 suve_mpos;//元いた位置の保存

	void AnimeFlame();
	void Jump(); 
	void Init();

	void Render();

	void Update();

	void SetPos(int row, int col);
	void SetPos();

};
#endif

