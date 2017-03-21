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
	void Key();
	CImage *mp_hp;
	CImage *mp_sp;
public:
	CPlayer(int type);
	~CPlayer();
//	void Update();
	void Draw();
	void HitCallBack(CCollisionA * p);
};

#endif // !CPLAYER_INCLUDE_GUARD