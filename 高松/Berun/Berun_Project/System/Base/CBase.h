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
public:
	CBase();
	~CBase();
	CVector2D GetScreenPos();
};
#endif