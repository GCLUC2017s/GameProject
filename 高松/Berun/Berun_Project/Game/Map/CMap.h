#ifndef CMAP_GURAD
#define CMAP_GURAD
#define SCROLL_SPEED 2//マップスクロール値
#define MAP_DATA 3//マップの数
#include "../Global.h"
#include"../System/TaskSystem/CTaskManager.h"

/**
*@file	 CMap.h
*@brief  マップクラス
*@author 宮田
*/

class CMap : public CTask{
private:
	CImage *m_backgroundMorning[MAP_DATA];
	
	CImage *m_backgroundEvenig;
	CImage *m_backgroundNight;
	
	enum E_Stage
	{
		eStage1,
		eStage2,
		eStage3,
		eStage4,

	};
	E_Stage m_stage; 
	CVector2D m_mapPos;//マップ座標変化


public:
	
	CMap();
	~CMap();
	void Update();
	void Draw();
//	void Setstge(E_Stage stage);
};

#endif // !CMAP_GURAD
