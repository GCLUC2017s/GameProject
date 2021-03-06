/*
あたり判定のプログラム
担当者　冨田健斗
*/
#ifndef COLLISION_HPP
#define COLLISION_HPP
#include "../Graphic/CRectangle.h"
#include "../Vector/CVector2.h"
#include "../Base/CBase.h"

class CCollision {
public:
	/*base1が攻撃範囲(四角) base2が攻撃を受けるほう rangeが攻撃範囲(軸)*/
	static bool Collision(const CBase &base1,const CBase &base2,const float range);
};

#endif