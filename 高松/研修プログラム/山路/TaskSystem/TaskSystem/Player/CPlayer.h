/**
*@file
*@brief  �v���C���[�N���X
*@author �R�H
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
