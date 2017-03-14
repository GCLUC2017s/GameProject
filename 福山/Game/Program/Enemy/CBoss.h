/*
*ボスエネミーのプログラム
*担当者 冨田健斗&高橋弘樹
*/
#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "../Base/CBase.h"
#include "../Task/CTaskManager.h"
#include "../Graphic/CRectangle.h"
#include "../Task/CTaskManager.h"
#include "../Define/define.h"
#define FLAME_LIMIT 6 //フレーム数の上限

const	 CVector2 Enemy_first_pos
= CVector2(character_limit_left*0.85, (character_limit_top + character_limit_bottom) / 2);	//ボスエネミーの初期位置

class  CBoss : public CBase
{
private:

	float mVelocity;//移動するときに使う
	CRectangle	mBoss;
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
		E_STAY_L, E_STAY_R,
		E_WALK_L, E_WALK_R,
		E_RUN_L, E_RUN_R
	};

	MyEnum eAnime = E_STAY_R;
	int mSaveAnime; //直前のアニメが何か判断用
	int mFlameCount;		//フレーム数カウント用
	int mAnime;		//アニメーションのフレーム数
	CVector2 mTarget;
	CVector2 mSuvePos;//元いた位置の保存


	void Walk(){};
	void AnimeFlame();
	void SetPos();

public:
	CBoss();
	~CBoss();
	void Init();
	void Render();
	void Update();

};

#endif