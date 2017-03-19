#include "CCollision.h"
#include <math.h>


bool CCollision::Collision(const CBase &base1, const CBase &base2,float range){

	float w_xl1 = base1.mAttackRange.triangle1.x1 + base1.mAttackRange.position.x;
	float w_xr1 = base1.mAttackRange.triangle1.x3 + base1.mAttackRange.position.x;
	float w_yt1 = base1.mAttackRange.triangle1.y1 + base1.mAttackRange.position.y;
	float w_yb1 = base1.mAttackRange.triangle1.y3 + base1.mAttackRange.position.y;
	float w_xl2 = base2.mRect.triangle1.x1 + base2.mRect.position.x;
	float w_xr2 = base2.mRect.triangle1.x3 + base2.mRect.position.x;
	float w_yt2 = base2.mRect.triangle1.y1 + base2.mRect.position.y;
	float w_yb2 = base2.mRect.triangle1.y3 + base2.mRect.position.y;


	if (w_xl1 < w_xr2 && w_xl2 < w_xr1 && w_yt1 > w_yb2 && w_yb1 < w_yt2){
		return true;
	}

	return false;
}