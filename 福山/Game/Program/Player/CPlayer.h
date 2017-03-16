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

#define NORMALATTACK_PATTERN 3 //通常攻撃のパターン

const float gravity = 0.01;	 //重力

const	 CVector2 first_pos
= CVector2(character_limit_left*0.85, (character_limit_top + character_limit_bottom) / 2);		//プレイヤーの初期位置

class CPlayer : public CBase {
private:

	float mVelocity; //移動するときに使う
	CRectangle  mShadow;
	CRectangle	mAttackCollision[NORMALATTACK_PATTERN]; //あたり判定だけの四角形
	CTexture	*mStayTex[FRAME_LIMIT];									//待ちテクスチャ
	CTexture	*mWalkTex[FRAME_LIMIT];									//歩くテクスチャ
	CTexture	*mRunTex[FRAME_LIMIT];									//走るテクスチャ
	CTexture	*mNormalAttackTex[NORMALATTACK_PATTERN][FRAME_LIMIT];	//通常攻撃テクスチャ
	CTexture	*mEatTex[FRAME_LIMIT];									//捕食テクスチャ
	CTexture	*mEx01Tex[FRAME_LIMIT];									//必殺技(消費)テクスチャ									
	CTexture	*mEx02Tex[FRAME_LIMIT];									//必殺技(継続)テクスチャ
	CTexture	*mFlameTex[FRAME_LIMIT];								//炎テクスチャ
	CTexture	*mBrakeTex[FRAME_LIMIT];								//ブレーキテクスチャ
	CTexture	*mShadowTex;											//影テクスチャチャ

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
		E_BRAKE_L,

		E_STAY_R, E_WALK_R,
		E_RUN_R, E_NORMALATTACK_A_R,
		E_NORMALATTACK_B_R, E_NORMALATTACK_C_R,
		E_EAT_R, E_EX01_R,
		E_EX02_R, E_FLAME_R,
		E_BRAKE_R,



	};

	int mAnimePattern;				//全体のアニメーションパターン大きさ
	bool mEnabledJump;				//ジャンプいている
	bool mEnabledNormalAttack;		//通常攻撃しているかいないか
	float mSpeedJump;				//ジャンプのスピード
	float mIntervalCount;			//Interval関数カウント用

	CVector2 mTarget;
	CVector2 mSuvePos;				//元いた位置の保存

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
	/*テクスチャデリート*/
	void Delete(CTexture *t);
	/*BRAKEするか否か*/
	bool EnabledBrake();
	/*NormalAttackメソッド*/
	void NormalAttack();
	
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

