#include "CGameInfo.h"

CItem* CGameInfo::mp_instance = nullptr;

CItem* CGameInfo::GetInstance()
{
	if (mp_instance == nullptr)
	{
		mp_instance = new CItem;
	}
	return mp_instance;
}

void CGameInfo::ClearInstance()
{
	if (mp_instance != nullptr) delete mp_instance;
}
