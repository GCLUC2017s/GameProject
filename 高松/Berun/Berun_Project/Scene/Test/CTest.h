/**
* @file		CTest.h
* @brief	テスト用シーンクラス
* @author	yuki yamaji
*/

#ifndef  TEST_GUARD
#define  TEST_GUARD

#include "../System/TaskSystem/CTask.h"
#include "../Scene/CScene.h"

class CTest : public CScene
{
private:

public:
	CTest();
	~CTest();
	void Update();
	void Draw();
};

#endif
