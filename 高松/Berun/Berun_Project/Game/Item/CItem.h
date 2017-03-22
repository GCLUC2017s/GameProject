/**
* @file		CItem.h
* @brief	アイテムクラス
* @author	yuki yamaji
*/

#ifndef ITEM_GUARD
#define ITEM_GUARD

#include "../Global.h"
#include "Base/CBase.h"

enum E_Item
{
	eCarrotItem,
	eChickItem,
	eFishItem,
	eRiceItem,
	eItemMax,
};

struct T_Item
{
	int type;
	int cnt;
};

class CItem : public CBase
{
private:
	int  m_itemArray[eItemMax];
public:
	CItem();
	~CItem();
	void AddItem(int type, int count)
	{
		m_itemArray[type] += count;
	}
	void ResetItem()
	{
		for (int i = 0; i < eItemMax; i++)
		{
			m_itemArray[i] = 0;
		}
	}
	int GetItem(int type)
	{
		return m_itemArray[type];
	}
	
};
#endif