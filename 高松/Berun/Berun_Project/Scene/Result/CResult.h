/**
* @file		CResult.h
* @brief	リザルトシーンクラス
* @author	yuki yamaji
*/

#ifndef RESULT_GUARD
#define RESULT_GUARD


#include "CImage.h"
#include "../CScene.h"
#include "../Game/Item/CItem.h"

#define RESULT_IMAGE_MAX 29
#define ITEM_TYPE_MAX 16
#define BAG_MAX 5

//画像データ
enum E_ResultData
{
	eResultBackGround,
	eClear,
	eSelect,
	eItem,
	eArrow,
	eItemselect,

	eSelectStart,

	eCraft = eSelectStart,
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

	eSelectEnd = eItem16,

	eRankDraw,

	eRankA = eRankDraw,
	eRankB,
	eRankC,
	eRankS,
	eRank,
	eRankEnd = eRank,

	eResultTitle,

	eMax,
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
	float  m_xSize;
	float  m_ySize;
	int    m_corsol;
	int    m_box[BAG_MAX];
	bool   m_imgFlg;
public:
	CResult();
	~CResult();
	void Update();
	void Draw();
	void DarkenColor();
	void SelectItem(int box, T_ItemData &item);
};

#endif