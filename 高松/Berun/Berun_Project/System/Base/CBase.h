/**
*@file	 CBase.h
*@brief  ���N���X
*@author �R�H
*/

#ifndef BASE_GUARD
#define BASE_GUARD

#include "../stdafx.h"
#include "../Global.h"
#include "../System/TaskSystem/CTask.h"



class CBase : public CTask
{
protected:
	//�d�͗������x
	float m_gravitySpeed;
	//�I�u�W�F�N�g�̍��W���i�[����ϐ�
	CVector3D m_pos;
	//�I�u�W�F�N�g�̑傫�����i�[����ϐ�
	CVector2D m_size;
	//�L�����N�^�[��ID
	int   m_id;
	//�L�����N�^�[�̓����蔻��p��`
	CRect rect;
	static CVector2D m_scroal;
public:
	CVector2D GetScroal() {
		return m_scroal;
	}
	void SetScroal(CVector2D scroal) {
		m_scroal = scroal;
	}

	CBase();
	CBase(unsigned int updatePrio, unsigned int drawPrio);
	~CBase();
	virtual void HitCallBack(CBase * p);
	CVector2D GetScreenPos();
	CVector3D GetPos() {
		return m_pos;
	}
	CRect GetRect()
	{
		return rect;
	}
};
#endif