

/**
*@file	 CMap.h
*@brief  マップクラス
*@author 宮田
*/
#ifndef CMAP_GURAD
#define CMAP_GURAD
#define SCROLL_SPEED 2//マップスクロール値
#define MAP_DATA 3//マップの数
#define MAP_NUMBER 4
#include "../Global.h"
#include"../System/TaskSystem/CTaskManager.h"


extern char g_stageNumber[MAP_DATA][MAP_NUMBER];

class CMap : public CTask{
private:
	CImage *m_backGroundMorning[MAP_DATA];
	CImage *m_backGroundNoon[MAP_DATA];
	CImage *m_backGroundEvenig[MAP_DATA];
	CImage *m_backGroundNight[MAP_DATA];
	
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
	//void Setstge(E_Stage stage);
};

#endif // !CMAP_GURAD
