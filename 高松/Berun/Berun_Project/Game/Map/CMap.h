#ifndef CMAP_GURAD
#define CMAP_GURAD
#include "../Global.h"
#include"../System/TaskSystem/CTaskManager.h"

/**
*@file	 CMap.h
*@brief  マップクラス
*@author 宮田
*/

class CMap : public CTask{
private:
	CImage *m_backgroundMorning;
	CImage *m_backgroundAfternoon;
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

public:
	
	CMap();
	~CMap();
	void Update();
	void Draw();
//	void Setstge(E_Stage stage);
};

#endif // !CMAP_GURAD
