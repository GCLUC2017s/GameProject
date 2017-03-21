#ifndef CENEMYBASETEST_HPP
#define CENEMYBASETEST_HPP

#include "../Base/CBase.h"
#include "../CGame/CGame.h"

#define LEFT_PTT	(mTargetP.x<mPos.x)	//ターゲットが左にいる
#define RIGHT_PTT	(mTargetP.x>mPos.x)	//ターゲットが右にいる
#define UP_PTT		(mTargetP.y<mPos.y)	//ターゲットが上にいる
#define DOWN_PTT	(mTargetP.y>mPos.y)	//ターゲットが下にいる


#define ATTACK_PTT   (rulerR <2||rulerL <2)  // ターゲットとの距離が数値以下の時に攻撃をする。

#define HATTACK_PTT  (rulerR<4||rulerR<4)

#define ENEMY_VISI   (rulerR <6||rulerL <6)  // エネミーの視界を６に設定。
#define ENEMY_ESCAPE   (rulerR >5||rulerL >5)  //一定距離近づいた時に逃げる距離
#define DOWNAXIS	(getAxis-2)
#define UPAXIS		(getAxis+2)
#define NO_ATTACK_PTT   (rulerR >3 || rulerL >3)  // ターゲットが当たり判定外の時の判定

	/*変数が変化する場合はこちらで判断*/
	enum EMotion{
		EM_STAY, EM_WALK,
		EM_RANGE, EM_DIE,
		EM_BACK_X, EM_BACK_Y,EM_MOVE_AT = 5,
		EM_ATTCK, EM_HIGH_AT,
		EM_LOW_AT

	};
#endif