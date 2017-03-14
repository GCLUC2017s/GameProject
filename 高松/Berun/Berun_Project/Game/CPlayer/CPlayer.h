/*
* @file		CPlayer.h
* @brief	プレーヤー機能
*
* @author	Ryoji Anzai
*/
#ifndef CPLAYER_INCLUDE_GUARD
#define CPLAYER_INCLUDE_GUARD
#include "../Global.h"
#include "../System/CharaBase/CCharaBase.h"

#define PLAYER_MOVE 4

class CPlayer : public CCharaBase
{
	T_PlayerData *mp_pData;
	
public:
	CPlayer(int type);
	~CPlayer();
//	void Update();
//	void Draw();
};

#endif // !CPLAYER_INCLUDE_GUARD