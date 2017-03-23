#ifndef CLOWBOSS_HPP
#define CLOWBOSS_HPP


#include "../Base/CBase.h"
#include "../Task/CTaskManager.h"
#include "../Graphic/CRectangle.h"
#include "../Task/CTaskManager.h"
#include "../Define/define.h"


const	 CVector2 LowBoss_first_pos
= CVector2(character_limit_right*0.7f, (character_limit_top + character_limit_bottom) / 2);	//中ボスの初期位置

class  CLowBoss : public CBase
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
		E_DIE_L, E_DIE_R,
		E_LEFT, E_RIGHT
	};

	int AnimePattern;
	int mSaveAnime; //直前のアニメが何か判断用
	int mFrameCount;		//フレーム数カウント用

	int direction;//左右判定

	float rulerR; //エネミーとキャラクターの距離
	float rulerL; //エネミーとキャラクターの距離
	float upruler;
	float downruler;
	float getAxis;
	int motion;
	bool actionflag;

	int pattern;//ランダム用

	void Motion();
	void Walk();
	void AnimeScene();
	void SetPos();

public:
	CLowBoss();
	~CLowBoss();
	void Init();
	void Render();
	void Update();
};
#endif