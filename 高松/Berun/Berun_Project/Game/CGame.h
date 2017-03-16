/**
* @file		CGame.h
* @brief	ゲームシーンクラス
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
	//static CPlayer *mp_player;
	//static CEnemy  *mp_enemy;
	static CTutorial *mp_tuto;
public:
	CGame();
	~CGame();
	void Update();
	void Draw();
	//CPlayer GetPlayer(int type);
	//CEnemy GetEnemy(int type);
	CTutorial GetTutorial();
};

#endif