/**
* @file		CGame.h
* @brief	ゲームシーンクラス
* @author	yuki yamaji
*/

#ifndef GAME_GUARD
#define GAME_GUARD
#define IMG_ARRAY 4
#define GOAL_POS 5000.0f


#include "../Scene/CScene.h"
#include "CImage.h"


//クラスのプロトタイプ宣言
class CMap;
class CTutorial;
class CPlayer;
class CEnemy;

class CGame : public CScene
{
private:
	static CGame* mp_game;
	CMap	  *mp_map;
	CTutorial *mp_tutorial;
	CPlayer	  *mp_player;
	CEnemy    *mp_enemy;
	CImage    *mp_img[IMG_ARRAY];
	CImage	  *mp_black;
	CImage	  *mp_wordGameOver;
	unsigned int m_step;
	int m_cnt;
	
public:
	bool m_stopScrol;
	CGame();
	~CGame();
	void Update();
	void Draw();
	void GameOver();
	static CGame* GetInstance();
	static void ClearInstance();
};

#endif