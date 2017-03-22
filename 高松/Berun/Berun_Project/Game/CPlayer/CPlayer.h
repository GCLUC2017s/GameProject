/*
* @file		CPlayer.h
* @brief	プレーヤー機能
*
* @author	Ryoji Anzai
*/
#ifndef CPLAYER_INCLUDE_GUARD
#define CPLAYER_INCLUDE_GUARD
#include "../Global.h"
#include "../../System/CharaBase/CCharaBase.h"

#define PLAYER_MOVE 4
#define WALK_SPEED 1
#define DASH_SPEED 2

class CPlayer : public CCharaBase
{
	void Contlol();
	CImage *mp_hp;
	CImage *mp_sp;
	CImage *mp_shadow;
public:
	static CPlayer* mp_player;
	CPlayer(int type);
	~CPlayer();
//	void Update();
	void Draw();
	void HitCallBack();
};

#endif // !CPLAYER_INCLUDE_GUARD