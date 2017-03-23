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

enum E_ItemImg
{
	Udon,
	Squid,
	Oil,
	Apple,
	Egg,
	Bread,
	Rice,
	Cheese,
	Pork,
	Meet,
	Fish,
	Chicken,
	Paprika,
	Milk,
	Carrot,
	Strawberry,
	ItemMax,
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
	CImage *m_imgArray[ItemMax];
	int  m_itemArray[ItemMax];
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
		for (int i = 0; i < ItemMax; i++)
		{
			m_itemArray[i] = 0;
		}
	}
	//ゲーム中に落とすアイテム
	int GetItem(int type)
	{
		return m_itemArray[type];
	}
	
};
#endif