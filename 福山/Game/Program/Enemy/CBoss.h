/*
*ボスエネミーのプログラム
*担当者 冨田健斗&高橋弘樹
*/
#ifndef CBOSS_HPP
#define CBOSS_HPP
#include "../Base/CBase.h"
#include "../Task/CTaskManager.h"
#include "../Graphic/CRectangle.h"
#include "../Task/CTaskManager.h"
#include "../Define/define.h"


#define FLAME_LIMIT 6 //フレーム数の上限

const	 CVector2 Boss_first_pos
= CVector2(character_limit_left*0.55, (character_limit_top + character_limit_bottom) / 2);	//ボスエネミーの初期位置

class  CBoss : public CBase
{
private:

	float mVelocity;//移動するときに使う

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
		E_HATTACK_L, E_HATTACK_R,
		E_DIE_L, E_DIE_R
	};

	int AnimePattern;
	int mSaveAnime; //直前のアニメが何か判断用
	int mFlameCount;		//フレーム数カウント用
	int mAnime;		//アニメーションのフレーム数
	
	int direction;//左右判定

	float rulerR; //エネミーとキャラクターの距離
	float rulerL; //エネミーとキャラクターの距離

	int motion;
	bool actionflag;
	
	int pattern;//ランダム用

	void Walk();
	void AnimeScene();
	void SetPos();

public:
	CBoss();
	~CBoss();
	void Init();
	void Render();
	void Update();

};

#endif