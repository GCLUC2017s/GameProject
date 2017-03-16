

/**
*@file	 CMap.h
*@brief  マップクラス
*@author 宮田
*/
#ifndef CMAP_GURAD
#define CMAP_GURAD
#define SCROLL_SPEED 2//マップスクロール値
#define MAP_DATA 4//マップの数

#include "../Global.h"
#include"../System/TaskSystem/CTaskManager.h"
#include "../../System/CharaBase/CCharaBase.h"

struct T_MapData
{
	char imgName[64];
};
class CMap : public CTask{
public:
	enum E_Stage
	{
		eStage1,
		eStage2,
		eStage3,
		eStage4,

	};
private:
	CImage *m_backGround[MAP_DATA];
	
	
	E_Stage m_stage;
	E_Stage m_newstage;
	T_MapData *map_eData;
	CVector2D m_mapPos;//マップ座標変化

public:
	CMap(E_Stage type);
	~CMap();
	void Update();
	void Draw();
	//void Setstge(E_Stage stage);
};


#endif // !CMAP_GURAD
