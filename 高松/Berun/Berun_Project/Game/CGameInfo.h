/**
* @file		CGame.h
* @brief	ƒQ[ƒ€î•ñŠÇ—ƒNƒ‰ƒX
* @author	yuki yamaji
*/

#ifndef GAMEINFO_GUARD
#define GAMEINFO_GUARD

#define ITEM_MAX 16

#include "Item/CItem.h"



class CGameInfo
{
private:
	static CItem* mp_instance;
	int m_itemCnt[ITEM_MAX];
public:
	static CItem* GetInstance();
	static void ClearInstance();
	void CntUpItem(int type);
};

#endif