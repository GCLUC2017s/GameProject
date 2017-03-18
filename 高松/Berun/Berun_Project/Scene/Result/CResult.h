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

#define ITEM_IMAGE_MAX 12
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
	CImage *mp_img[ITEM_IMAGE_MAX];
	CVector2D m_pos;
	T_ResultData  *mp_data;
	float m_xSize;
	float m_ySize;
	int m_step;
	int m_corsol[ITEM_TYPE_MAX];
public:
	CResult();
	~CResult();
	void Update();
	void Draw();
};

#endif