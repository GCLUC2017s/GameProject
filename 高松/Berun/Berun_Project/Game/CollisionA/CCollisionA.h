/*
* @file		CCollisionA.h
* @brief	当たり判定クラス
*
* @author	Ryoji Anzai
*/
#ifndef CCOLLISION_INCLUDE_GUARD
#define CCOLISION_INCLUDE_GUARD

#include "../Global.h"
#include "../System/Base/CBase.h"

class CCollisionA
{
private:
public:
	bool CheckHit(CBase *p,CBase *t);
};
#endif
