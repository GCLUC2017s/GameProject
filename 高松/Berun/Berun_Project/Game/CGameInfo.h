/**
* @file		CGame.h
* @brief	ゲーム情報管理クラス
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