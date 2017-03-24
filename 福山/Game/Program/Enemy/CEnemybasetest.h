#ifndef CENEMYBASETEST_HPP
#define CENEMYBASETEST_HPP

#include "../Base/CBase.h"
#include "../CGame/CGame.h"

#define LEFT_PTT	(mTargetP.x<mPos.x)	//ターゲットが左にいる
#define RIGHT_PTT	(mTargetP.x>mPos.x)	//ターゲットが右にいる
#define UP_PTT		(getAxis>mPos.y)	//ターゲットが上にいる
#define DOWN_PTT	(getAxis<mPos.y)	//ターゲットが下にいる


#define ATTACK_PTTX   (rulerR <1.0f||rulerL <1.0f)  // ターゲットとの距離が数値以下の時に攻撃動作に変更をする。
#define ATTACK_BOSS   (rulerR <4||rulerL <4)  // ターゲットとの距離が数値以下の時に攻撃モーションに変更する。
#define ATTACK_PTTY   (upruler<0.5f||downruler<0.5f)  // Y軸の攻撃判定。
#define ATTACK_BOSS_Y   (upruler<2.1f||downruler<2.0f)  // Y軸の攻撃判定

#define ATTACK_PTT01_Y   (upruler<0.5f||downruler<1.0f)  // Y軸の攻撃判定。
#define HATTACK_PTT  (rulerR<4||rulerR<4)

#define ENEMY_VISI   (rulerR <6||rulerL <6)  // エネミーの視界を６に設定。

#define ENEMY_ESCAPE   (rulerR >3||rulerL >3)  //一定距離近づいた時に逃げる距離
#define BOSS_ESCAPE   (rulerR >5||rulerL >5)  //一定距離近づいた時に逃げる距離

#define NO_ATTACK_PTTX   (rulerR >1.5f || rulerL >1.5f)  // ターゲットが当たり判定外の時の判定
#define NO_ATTACK_BOSS   (rulerR >4 || rulerL >4) 
#define RUSH_BOSS   (rulerR >2 || rulerL >2) //ボスのラッシュ攻撃。範囲外ならラッシュ。

#define NO_ATTACK_PTTY   (upruler>1||downruler>1)  // Y軸の攻撃判定。

#define ENEMY_LIVE (mHitPoint>0)


#define ESCAPE_TIME			 (float) 2 
#define ESCAPE_TIME_BOSS		 (float) 1
#define ENEMY00_INTERVAL (float) 1 //インターバルを１秒に設定。
#define ENEMY00_DELAY (float) 1 //インターバルを１秒に設定。
#define ENEMY01_INTERVAL (float) 1
#define BOSS_INTERVAL	 (float) 1

	/*変数が変化する場合はこちらで判断*/
	enum EMotion{
		EM_STAY, EM_WALK,
		EM_RANGE, EM_DIE,
		EM_BACK_X, EM_BACK_Y,EM_MOVE_AT = 5,
		EM_ATTACK, EM_HIGH_AT,
		EM_LOW_AT,EM_BACK_UP,
		EM_UP,EM_DOWN,
		EM_Slanting
	};
#endif