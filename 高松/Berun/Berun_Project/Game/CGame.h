/**
* @file		CGame.h
* @brief	ゲームシーンクラス
* @author	yuki yamaji
*/

#ifndef GAME_GUARD
#define GAME_GUARD

#include "../Scene/CScene.h"

//クラスのプロトタイプ宣言
class CMap;
class CTutorial;
class CPlayer;

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