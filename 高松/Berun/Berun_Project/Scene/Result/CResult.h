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

#define RESULT_IMAGE_MAX 13
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
	int m_step;
	int m_corsol;
	//int m_select;
public:
	CResult();
	~CResult();
	void Update();
	void Draw();
};

#endif