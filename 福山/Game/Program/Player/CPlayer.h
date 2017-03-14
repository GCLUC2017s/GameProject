/*
*プレイヤーのプログラム
*担当者　冨田健斗
*/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "../Base/CBase.h"
#include "../Task/CTaskManager.h"
#include "../Graphic/CRectangle.h"
#include "../Task/CTaskManager.h"
#include "../Define/define.h"

#define FLAME_LIMIT 6 //フレーム数の上限

const float gravity = 0.01;										//重力
const float player_limit_left = -MAP_LIMIT_X / 2;				//ＰＬが進める上限(左)
const float player_limit_top = MAP_LIMIT_Y / 4;			   //ＰＬが進める上限(上)
const float player_limit_right = MAP_LIMIT_X / 2;			 //ＰＬが進める上限(右)
const float player_limit_bottom = -MAP_LIMIT_Y / 2;			//ＰＬが進める上限(下)

const	 CVector2 first_pos
= CVector2(player_limit_left*0.85, (player_limit_top + player_limit_bottom) / 2);		//プレイヤーの初期位置

class CPlayer : public CBase {
private:

	float mVelocity; //移動するときに使う
	CRectangle	mPlayer;
	CRectangle  mShadow;
	CTexture	*mStay_tex[FLAME_LIMIT];
	CTexture	*mWalk_tex[FLAME_LIMIT];
	CTexture	*mRun_tex[FLAME_LIMIT];

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
	int mSave_eAnime; //直前のアニメが何か判断用

	int mFlameCount;		//フレーム数カウント用
	int mAnime;		//アニメーションのフレーム数

	bool mEnabledJump;//ジャンプいている
	float mSpeedJump; //ジャンプのスピード

	CVector2 mTarget;
	CVector2 mSuvePos;//元いた位置の保存

	void Run_Walk();
	void AnimeFlame();
	void Jump(); 
	void SetPos();
public:
	/*
	CCameraで使うXY
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

