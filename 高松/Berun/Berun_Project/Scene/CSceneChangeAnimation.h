/**
* @file		CSceneChangeAnimation.h
* @brief	シーン切り替えアニメクラス
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
	//シーン切り替え時フェードアウト処理
	CSceneChangeAnimation();
	void SetType(E_AnimType type){m_type = type;} 
	void Draw(float t);
};

#endif