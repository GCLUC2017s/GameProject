/*
* @file		CPlayer.h
* @brief	プレーヤー機能
*
* @author	Ryoji Anzai
*/
#ifndef CPLAYER_INCLUDE_GUARD
#define CPLAYER_INCLUDE_GUARD
#include "../Global.h"

#define PLAYER_MOVE 4

class CPlayer
{
	CImage *m_littlePlayerM;
	CImage *m_littlePlayerW;
	CImage *m_stageImage;

	//以下、キャラクターの座標を格納する変数
	int m_playerX;
	int m_playerY;
	//以下、キャラクターの大きさを格納する変数
	int m_playerWidth;
	int m_playerHeight;
	//キャラクターの座標を格納する変数
	CVector2D m_playerPos;
	//キャラクターの大きさを格納する変数
	CVector2D m_playerSize;
	//キャラクターの向きを格納するフラグ(false = 右,true = 左)
	bool m_charaDirection;
public:
	CPlayer();
	~CPlayer();
	void Update();
	void Draw();
};

#endif // !CPLAYER_INCLUDE_GUARD