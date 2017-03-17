/**
* @file		CGame.h
* @brief	ゲームシーンクラス
* @author	yuki yamaji
*/

#ifndef GAME_GUARD
#define GAME_GUARD
#include"Map/CMap.h"
#include"Enemy/CEnemy.h"
#include"CPlayer/CPlayer.h"
#include "../Scene/CScene.h"
#include "../Game/Tutorial/CTutorial.h"

class CGame : public CScene
{
private:
	CMap		*mp_map;
	CTutorial	*mp_tutorial;
	CPlayer		*mp_player;
	unsigned int m_step;
public:

	CGame();
	~CGame();
	void Update();
	void Draw();
};

#endif