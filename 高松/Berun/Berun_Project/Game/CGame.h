/**
* @file		CGame.h
* @brief	�Q�[���V�[���N���X
* @author	yuki yamaji
*/

#ifndef GAME_GUARD
#define GAME_GUARD
#include"Map/CMap.h"
#include"Enemy/CEnemy.h"
#include "../Scene/CScene.h"
#include "../Game/Tutorial/CTutorial.h"

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