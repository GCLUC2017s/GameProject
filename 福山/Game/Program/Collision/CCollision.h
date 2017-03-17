/*
‚ ‚½‚è”»’è‚ÌƒvƒƒOƒ‰ƒ€
’S“–Ò@•y“cŒ’“l
*/
#ifndef COLLISION_HPP
#define COLLISION_HPP
#include "../Graphic/CRectangle.h"
#include "../Vector/CVector2.h"
#include "../Base/CBase.h"

class CCollision {
public:
	/*base1‚ªUŒ‚”ÍˆÍ(lŠp) base2‚ªUŒ‚‚ğó‚¯‚é‚Ù‚¤ range‚ªUŒ‚”ÍˆÍ(²)*/
	static bool Collision(const CBase &base1,const CBase &base2,const float range);
};

#endif