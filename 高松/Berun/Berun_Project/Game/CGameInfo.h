/**
* @file		CGame.h
* @brief	�Q�[�����Ǘ��N���X
* @author	yuki yamaji
*/

#ifndef GAMEINFO_GUARD
#define GAMEINFO_GUARD

#include "Item/CItem.h"

class CGameInfo
{
private:
	static CItem* mp_instance;
public:
	static CItem* GetInstance();
	static void ClearInstance();
};

#endif