/**
* @file		CScene.h
* @brief	�V�[�����N���X
* @author	yuki yamaji
*/

#ifndef SCENE_GUARD
#define SCENE_GUARD

class CScene 
{
public:
	CScene() 
	{
	}
	virtual ~CScene() 
	{
	}
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

#endif