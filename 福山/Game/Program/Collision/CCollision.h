/*
�����蔻��̃v���O����
�S���ҁ@�y�c���l
*/
#ifndef COLLISION_HPP
#define COLLISION_HPP
#include "../Graphic/CRectangle.h"
#include "../Vector/CVector2.h"
#include "../Base/CBase.h"

class CCollision {
public:
	/*base1���U���͈�(�l�p) base2���U�����󂯂�ق� range���U���͈�(��)*/
	static bool Collision(const CBase &base1,const CBase &base2,const float range);
};

#endif