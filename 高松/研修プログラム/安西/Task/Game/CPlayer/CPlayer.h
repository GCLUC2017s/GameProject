/**
* @file		CPlayer.h
* @brief	主人公の機能
*
* @author	ryoji anzai
*/

#ifndef PLAYER_GUARD
#define PLAYER_GUARD

#include "../../System/CTask/CTask.h"



class CPlayer : public CTask
{

public:
	CPlayer();
	~CPlayer();
	void Update();
	void Render();

};

#endif // !PLAYER_GUARD