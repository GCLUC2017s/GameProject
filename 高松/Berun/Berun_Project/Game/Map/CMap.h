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
	CImage *m_background;
	CImage *m_wood;
	
	enum stagehaikei
	{
		eStage1,
		eStage2,
		eStage3,
		eStage4,

	};
public:
	CMap();
	~CMap();
	void Update();
	void Draw();

};

#endif // !CMAP_GURAD
