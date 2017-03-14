/**
* @file		CResult.h
* @brief	リザルトシーンクラス
* @author	
*/

#ifndef RESULT_GUARD
#define RESULT_GUARD

#include "../Scene/CScene.h"


class CResult : public CScene
{
public:
	CResult();
	~CResult();
	void Update();
	void Draw();
};

#endif