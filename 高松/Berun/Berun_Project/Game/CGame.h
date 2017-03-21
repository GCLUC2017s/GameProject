/**
* @file		CGame.h
* @brief	ゲームシーンクラス
* @author	yuki yamaji
*/

#ifndef GAME_GUARD
#define GAME_GUARD
#define IMG_ARRAY 3

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
	unsigned int m_step;
public:

	CGame();
	~CGame();
	void Update();
	void Draw();
	static CGame* GetInstance();
	//格納されているものを削除
	static void ClearInstance();
};

#endif