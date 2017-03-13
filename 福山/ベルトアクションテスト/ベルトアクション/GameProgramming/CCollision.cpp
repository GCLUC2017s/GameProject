#include "CCollision.h"
#include <math.h>

/*
�l�p�`1(r1)�Ǝl�p�`2(r2)���d�Ȃ��Ă���ꍇ�A
�d�Ȃ��Ă���ʂ�vec�ɐݒ肵�Atrue��߂��B
�d�Ȃ��Ă��Ȃ��ꍇ�Avec��0��ݒ肵�Afalse��߂��B
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
	//�덷�΍�
	if (vec->x < -0.00001f && vec->y < -0.00001f) {
	//�d�Ȃ��Ă���ꍇ
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
