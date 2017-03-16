#ifndef COLLISION_HPP
#define COLLISION_HPP
#include "../Graphic/CRectangle.h"
#include "../Vector/CVector2.h"

class CCollision {
public:
	static bool Collision(const CRectangle &r1,const CRectangle &r2);
};

#endif