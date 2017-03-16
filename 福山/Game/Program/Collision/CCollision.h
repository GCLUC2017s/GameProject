#pragma once
#include "../Graphic/CRectangle.h"
#include "../Vector/CVector2.h"

class CCollision {
public:
	static bool collision(CRectangle &r1, CRectangle &r2, CVector2 *vec);
};
