/**
* @file		CResult.h
* @brief	リザルトシーンクラス
* @author	yuki yamaji
*/

#ifndef RESULT_GUARD
#define RESULT_GUARD

#include "../GLLibrary/CImage.h"
#include "../Global.h"
#include "../CScene.h"
#include "../Game/Item/CItem.h"

#define RESULT_IMAGE_MAX 29
#define ITEM_TYPE_MAX 16

enum E_ResultData
{
	eResultBackGround,
	eClear,
	eRankA,
	eRankB,
	eRankC,
	eRankS,
	eRank,
	eSelect,
	eItem,
	eArrow,
	eCraft,
	eItemselect,
	eResultTitle,
	eItem1,
	eItem2,
	eItem3,
	eItem4,
	eItem5,
	eItem6,
	eItem7,
	eItem8,
	eItem9,
	eItem10,
	eItem11,
	eItem12,
	eItem13,
	eItem14,
	eItem15,
	eItem16,
	eMax,
};

enum E_SelectData
{
	eSelectTitle,
	eSelectCraft,
	eSelectUdon,
	eSelectBread,
	eSelectRice,
	eSelectMeet,
	eSelectCheese,
	eSelectChicken,
	eSelectPork,
	eSelectEgg,
	eSelectOil,
	eSelectMilk,
	eSelectCarrot,
	eSelectStrawberry,
	eSelectApple,
	eSelectPaprika,
	eSelectFish,
	eSelectSquid,
	eFull,
};

struct T_ResultData 
{
	float xSize;	
	float ySize;
	CVector2D pos;
};

class CResult : public CScene
{
private:
	CImage *mp_img[RESULT_IMAGE_MAX];
	CVector2D m_pos;
	T_ResultData  *mp_data;
	float m_xSize;
	float m_ySize;
	int	  m_step;
	int   m_corsol;
	//int m_select;
	char  m_str[64];
public:
	CResult();
	~CResult();
	void Update();
	void Draw();
};

#endif