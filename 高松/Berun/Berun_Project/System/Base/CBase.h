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
public:
	CBase();
	~CBase();
	CVector2D GetScreenPos();
};
#endif