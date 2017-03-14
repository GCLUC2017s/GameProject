/**
* @file		CTest.h
* @brief	テスト用シーンクラス
* @author	yuki yamaji
*/

#ifndef  TEST_GUARD
#define  TEST_GUARD

#include "../System/TaskSystem/CTask.h"
#include "../System/TaskSystem/CTaskManager.h"
#include "../Scene/CScene.h"
#include "../Game/CPlayer/CPlayer.h"
#include "../Game/Map/CMap.h"

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
