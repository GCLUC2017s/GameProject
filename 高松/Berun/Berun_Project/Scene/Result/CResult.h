/**
* @file		CResult.h
* @brief	���U���g�V�[���N���X
* @author	
*/

#ifndef RESULT_GUARD
#define RESULT_GUARD

#include "../GLLibrary/CImage.h"
#include "../Global.h"
#include "../CScene.h"


class CResult : public CScene
{
private:
public:
	CResult();
	~CResult();
	void Update();
	void Draw();
};

#endif