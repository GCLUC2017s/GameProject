#pragma once
#include "CRectangle.h"
#include "CVector2.h"

class CCollision {
public:
	static bool collision(CRectangle &r1, CRectangle &r2, CVector2 *vec);
};
