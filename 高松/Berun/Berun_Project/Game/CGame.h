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
	//static CPlayer *m_player;
	//static CEnemy  *m_enemy;
public:
	CGame();
	~CGame();
	void Update();
	void Draw();
	//CPlayer GetPlayer(int type);
	//CEnemy GetEnemy(int type);
};

#endif