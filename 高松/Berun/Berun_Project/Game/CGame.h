/**
* @file		CGame.h
* @brief	ゲームシーンクラス
* @author	yuki yamaji
*/

#ifndef GAME_GUARD
#define GAME_GUARD
#include"Map/CMap.h"
#include "../Scene/CScene.h"

class CGame : public CScene
{
private:
public:
	CGame();
	~CGame();
	void Update();
	void Draw();
};

#endif