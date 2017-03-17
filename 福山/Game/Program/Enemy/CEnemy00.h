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


#define LEFT_PTT	mTargetP.x<mPos.x	//ターゲットが左にいる
#define RIGHT_PTT	mTargetP.x>mPos.x	//ターゲットが右にいる
#define UP_PTT		mTargetP.y<mPos.y&&mAxis < character_limit_top - SIZE_ENEMY00_Y	//ターゲットが上にいる
#define DOWN_PTT	mTargetP.y>mPos.y&& mAxis > character_limit_bottom + SIZE_ENEMY00_Y	//ターゲットが下にいる
#define ATTACK_PTT   rulerR <3||rulerL <3  // ターゲットが左にいる時の当たり判定
#define NO_ATTACK_PTT   rulerR >3 || rulerL >3  // ターゲットが左にいる時の当たり判定

const	 CVector2 Enemy00_first_pos
= CVector2(character_limit_left*0.55,
		  (character_limit_top + character_limit_bottom) / 2);	//エネミーの初期位置
//現在はマップ自体の左端を見て配置している。

class  CEnemy00 : public CBase
{
private:

	float mVelocity;//移動するときに使う

	CTexture	*mStay_tex[FLAME_LIMIT];
	CTexture	*mWalk_tex[FLAME_LIMIT];
	CTexture	*mAttack_tex[FLAME_LIMIT];
	CTexture	*mDie_tex[FLAME_LIMIT];

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
	//const int mStatus;
	MyEnum eAnime = E_STAY_L;
	int AnimePattern;				//全体のアニメーションパターン
	int mSaveAnime; //直前のアニメが何か判断用
	int mFlameCount;		//フレーム数カウント用
	int mAnime;		//アニメーションのフレーム数
	CVector2 mSuvePos;//元いた位置の保存

	int direction;	

	float rulerR; //エネミーとキャラクターの距離
	float rulerL; //エネミーとキャラクターの距離

	float npNum;
	float npNum2;

	int motion;
	
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