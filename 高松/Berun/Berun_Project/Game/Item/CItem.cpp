#include "CItem.h"


static const T_ItemData g_itmeData[] =
{
	//�i���o�[�A�^�C�v�A������
	{ NOT, NOT, 0},
	{ eCarrotItem, VEGETABLE, 0},
	{ eChickItem, MEET, 0},
	{ eFishItem, FISH, 0 },
	{ ePigItem, MEET, 0 },
};

CItem::CItem()
{
	ResetItem();
}

CItem::~CItem()
{
}

