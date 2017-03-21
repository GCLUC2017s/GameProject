/*
* @file		CCollisionA.h
* @brief	当たり判定クラス
*
* @author	Ryoji Anzai
*/
#ifndef CCOLLISION_INCLUDE_GUARD
#define CCOLLISION_INCLUDE_GUARD

#include "../Global.h"

class CCollisionA
{
protected:
	//キャラクターのタイプ
	int m_type;
	CCollisionA *mp_prev;					//前のアドレスを格納するポインタ
	CCollisionA *mp_next;					//次のアドレスを格納するポインタ
public:
	CCollisionA();
	~CCollisionA();
	virtual bool CheckHit(CCollisionA *t)=0;
	virtual void HitCallBack(CCollisionA * p)=0;
	void SetType(int t) { m_type = t; }
	friend class CCollisionManager;
};
#endif
