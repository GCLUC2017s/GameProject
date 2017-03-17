#include "CItem.h"

CItem* CItem::mp_instance = nullptr;

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
