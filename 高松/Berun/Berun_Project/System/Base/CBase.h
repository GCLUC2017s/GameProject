/**
*@file	 CBase.h
*@brief  基底クラス
*@author 山路
*/

#ifndef BASE_GUARD
#define BASE_GUARD

#include "../stdafx.h"
#include "../Global.h"
#include "../System/TaskSystem/CTask.h"



class CBase : public CTask
{
protected:
	//重力落下速度
	float m_gravitySpeed;
	//オブジェクトの座標を格納する変数
	CVector3D m_pos;
	//オブジェクトの大きさを格納する変数
	CVector2D m_size;
	//キャラクターのID
	int   m_id;
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
	CVector2D GetScreenPos();
	CVector3D GetPos() {
		return m_pos;
	}
};
#endif