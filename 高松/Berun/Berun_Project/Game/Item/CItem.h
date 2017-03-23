/**
* @file		CItem.h
* @brief	アイテムクラス
* @author	yuki yamaji
*/

#ifndef ITEM_GUARD
#define ITEM_GUARD

#define NOT -1
#define VEGETABLE 0
#define MEET 1
#define FISH 2

#include "../Global.h"
#include "Base/CBase.h"

enum E_Item
{
	eCarrotItem,
	eChickItem,
	eFishItem,
	ePigItem,
	eItemMax,
};

struct T_ItemData
{
	int no;
	int type;
	int cnt;
};

class CItem : public CBase
{
private:
	int  m_itemArray[eItemMax];
	int  m_count;
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