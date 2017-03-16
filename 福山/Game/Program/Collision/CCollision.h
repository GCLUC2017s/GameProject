#ifndef COLLISION_HPP
#define COLLISION_HPP
#include "../Graphic/CRectangle.h"
#include "../Vector/CVector2.h"

class CCollision {
public:
	static bool mCollision(CRectangle &r1, CRectangle &r2);
};

#endif