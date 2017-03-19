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
#define HUNGRY_S_HIGH_IF mStamina >= PL_ST_X*0.7f	//おなかがいっぱいステータス
#define HUNGRY_S_LOW_IF mStamina <= PL_ST_X*0.2		//おなかが減ったステータス

const float gravity = 0.01;	 //重力

const	 CVector2 first_pos
= CVector2(character_limit_left*0.85f, (character_limit_top + character_limit_bottom) / 2);		//プレイヤーの初期位置

class CPlayer : public CBase {
private:

	CRectangle	mAttackCollision[NORMALATTACK_PATTERN]; //あたり判定だけの四角形

	/*
	自分がどのアニメーションか判断用
	enum文
	*/

	enum EAnime
	{
		E_STAY_L, E_WALK_L,
		E_RUN_L, E_NORMALATTACK_A_L,
		E_NORMALATTACK_B_L, E_NORMALATTACK_C_L,
		E_EAT_L, E_EX01_L,
		E_EX02_L, E_FLAME_L,
		E_JUMP_L, E_BRAKE_L,

		E_STAY_R, E_WALK_R,
		E_RUN_R, E_NORMALATTACK_A_R,
		E_NORMALATTACK_B_R, E_NORMALATTACK_C_R,
		E_EAT_R, E_EX01_R,
		E_EX02_R, E_FLAME_R,
		E_JUMP_R, E_BRAKE_R,



	};

	float mSpeedJump;				//ジャンプのスピード
	float mEx01Speed;				//必殺技の進むスピード
	float mHungryPower;				//おなかが減る減らないの力の変化 += して使う(攻撃力)
	float mHungrySSpp;				//おなかが減る減らないの力の変化 += して使う(スピード)
	bool mEnabledInterval;			//Interval中するとき
	
	
	CVector2 mTarget;
	CVector2 mSuvePos;				//元いた位置の保存
	CVector2 mSaveForword;			//前の右左判断

	/*移動処理*/
	void Move();
	/*走るか否か ※vは方向の値を入れる*/
	void RunWalk(CVector2 v);
	/*BRAKEメソッド*/
	void Brake();
	/*ジャンプの関数*/
	void Jump();
	/*初期のポジションにする関数*/
	void SetPos();
	/*移動しているとき*/
	void EnabledMove();
	/*アニメーションの値を入れて,引数で右左を判断 Rが*/
	void DecisionRL(int R, int L);
	/*BRAKEするか否か*/
	bool EnabledBrake();
	/*攻撃処理メソッド*/
	void PlayerAttack();
	/*アニメーションシーン*/
	void AnimeScene();
	/*能力変化のメソッド*/
	void ChangeStatus();
public:
	/*
	CCameraで使うXY
	*/
	float mVelocity; //移動するときに使う
	static float camera_x;
	static float camera_y;

	CPlayer();
	~CPlayer();
	void Init();
	void Render();
	void Update();


};
#endif

