/*
*エネミーのプログラム
*担当者 冨田健斗&高橋弘樹
*/
#ifndef CENEMY00_HPP
#define CENEMY00_HPP
#include "../Base/CBase.h"
#include "../Task/CTaskManager.h"
#include "../Graphic/CRectangle.h"
#include "../Task/CTaskManager.h"
#include "../Define/define.h"
#include"../Player/CPlayer.h"

#define FLAME_LIMIT 6 //フレーム数の上限

const	 CVector2 Enemy_first_pos
= CVector2(character_limit_left*0.75,
		  (character_limit_top + character_limit_bottom) / 2);	//エネミーの初期位置
//現在はマップ自体の左端を見て配置している。

class  CEnemy00 : public CBase
{
private:

	float mVelocity;//移動するときに使う
	CRectangle	mEnemy00;
	CTexture	*mStay_tex[FLAME_LIMIT];
	CTexture	*mWalk_tex[FLAME_LIMIT];
	CTexture	*mAttack_tex[FLAME_LIMIT];
	CTexture	*mDie_tex[FLAME_LIMIT];

	CPlayer		*mPlayer;

	/*
	自分がどのアニメーションか判断用
	enum文
	*/
	enum MyEnum
	{
		E_STAY_L, E_STAY_R,
		E_WALK_L, E_WALK_R,
		E_RUN_L, E_RUN_R,
		E_ATTACK_L, E_ATTACK_R,
		E_DIE_L, E_DIE_R
	};

	MyEnum eAnime = E_STAY_L;
	int mSaveAnime; //直前のアニメが何か判断用
	int mFlameCount;		//フレーム数カウント用
	int mAnime;		//アニメーションのフレーム数
	CVector2 mTargetX;
	CVector2 mSuvePos;//元いた位置の保存
	
	
	void Walk(){};
	void AnimeFlame();
	void SetPos();

public:
	CEnemy00();
	~CEnemy00();
	void Init();
	void Render();
	void Update();

};

#endif