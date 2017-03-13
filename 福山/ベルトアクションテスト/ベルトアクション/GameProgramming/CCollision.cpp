#include "CCollision.h"
#include <math.h>

/*
四角形1(r1)と四角形2(r2)が重なっている場合、
重なっている量をvecに設定し、trueを戻す。
重なっていない場合、vecに0を設定し、falseを戻す。
*/
bool CCollision::collision(CRectangle &r1, CRectangle &r2, CVector2 *vec) {
	float w1 = r1.triangle1.x3;
	float h1 = r1.triangle1.y1;
	float w2 = r2.triangle1.x3;
	float h2 = r2.triangle1.y1;
	float lenX = abs(r2.position.x - r1.position.x);
	float lenY = abs(r2.position.y - r1.position.y);
	vec->x = lenX - w1 - w2;
	vec->y = lenY - h1 - h2;
	//誤差対策
	if (vec->x < -0.00001f && vec->y < -0.00001f) {
	//重なっている場合
		if (r1.position.x > r2.position.x)
			vec->x *= -1.0f;
		if (r1.position.y > r2.position.y)
			vec->y *= -1.0f;
		return true;
	}
	vec->x = 0.0f;
	vec->y = 0.0f;
	return false;
}
