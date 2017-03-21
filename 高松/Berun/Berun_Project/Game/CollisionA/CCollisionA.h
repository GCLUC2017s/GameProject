/*
* @file		CCollisionA.h
* @brief	�����蔻��N���X
*
* @author	Ryoji Anzai
*/
#ifndef CCOLLISION_INCLUDE_GUARD
#define CCOLLISION_INCLUDE_GUARD

#include "../Global.h"

class CCollisionA
{
protected:
	//�L�����N�^�[�̃^�C�v
	int m_type;
	CCollisionA *mp_prev;					//�O�̃A�h���X���i�[����|�C���^
	CCollisionA *mp_next;					//���̃A�h���X���i�[����|�C���^
public:
	CCollisionA();
	~CCollisionA();
	virtual bool CheckHit(CCollisionA *t)=0;
	virtual void HitCallBack(CCollisionA * p)=0;
	void SetType(int t) { m_type = t; }
	friend class CCollisionManager;
};
#endif
