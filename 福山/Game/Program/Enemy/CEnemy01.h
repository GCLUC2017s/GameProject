/*
*エネミーのプログラム
*担当者 冨田健斗&高橋弘樹
*/
#ifndef CENEMY01_HPP
#define CENEMY01_HPP
#include "../Base/CBase.h"
#include "../Task/CTaskManager.h"
#include "../Graphic/CRectangle.h"
#include "../Task/CTaskManager.h"
#include "../Define/define.h"
#define FLAME_LIMIT 6 //フレーム数の上限

const	 CVector2 Enemy_first_pos
= CVector2(character_limit_left*0.85, (character_limit_top + character_limit_bottom) / 2);	//エネミーの初期位置

class  CEnemy01 : public CBase
{
private:

	float mVelocity;//移動するときに使う
	CRectangle	mEnemy01;
	CRectangle  mShadow;
	CTexture	*mStay_tex[FLAME_LIMIT];
	CTexture	*mFlay_tex[FLAME_LIMIT];
	CTexture	*mAttack_tex[FLAME_LIMIT];
	CTexture	*mDie_tex[FLAME_LIMIT];
	/*
	自分がどのアニメーションか判断用
	enum文
	*/
	enum MyEnum
	{
		E_STAY_L, E_STAY_R,
		E_FLAY_L, E_FLAY_R,
		E_RUN_L, E_RUN_R,
		E_ATTACK_L, E_ATTACK_R,
		E_DIE_L, E_DIE_R
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
	CEnemy01();
	~CEnemy01();
	void Init();
	void Render();
	void Update();

};

#endif