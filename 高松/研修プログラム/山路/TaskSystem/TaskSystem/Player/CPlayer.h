/**
*@file
*@brief  プレイヤークラス
*@author 山路
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "../Task/CTask.h"

class CPlayer : public CTask
{
public:
	CPlayer();
	~CPlayer();
	void Update();
	void Render();
};

#endif 
