/**
* @file		CSceneChangeAnimation.h
* @brief	�V�[���؂�ւ��A�j���N���X
*
* @author	yuki yamaji
*/

#ifndef SCENECHANGEANIMATION_GUARD
#define SCENECHANGEANIMATION_GUARD

#include "../stdafx.h"

class CSceneChangeAnimation
{
public:
	enum E_AnimType
	{
		eFade,
	};

private:
	CImage m_image;
	E_AnimType m_type;

public:
	//�V�[���؂�ւ����t�F�[�h�A�E�g����
	CSceneChangeAnimation();
	void SetType(E_AnimType type){m_type = type;} 
	void Draw(float t);
};

#endif