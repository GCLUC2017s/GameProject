#include "CItem.h"

CItem* CItem::mp_instance = nullptr;

/*
static const T_Item g_itmeData[] =
{
	{ eCarrotItem, 0},
	{ eChickItem,  0},
};
*/

CItem::CItem()
{
	ResetItem();
}

CItem::~CItem()
{
}

CItem* CItem::GetInstance()
{
	if (mp_instance == nullptr)
	{
		mp_instance = new CItem;
	}
	return mp_instance;
}

void CItem::ClearInstance()
{
	if (mp_instance != nullptr) delete mp_instance;
}