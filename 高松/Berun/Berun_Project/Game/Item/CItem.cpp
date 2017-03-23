#include "CItem.h"


static const T_ItemData g_itmeData[] =
{
	//ナンバー、タイプ、所持数
	{ NOT, NOT, 0},
	{ Carrot, VEGETABLE, 0},
	{ Chicken, MEET, 0},
	{ Fish, FISH, 0 },
	{ Pork, MEET, 0 },
};

CItem::CItem()
{
	ResetItem();
}

CItem::~CItem()
{
}

