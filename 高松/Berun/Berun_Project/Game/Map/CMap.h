

/**
*@file	 CMap.h
*@brief  マップクラス
*@author Kousei Miyeta
*/
#ifndef CMAP_GURAD
#define CMAP_GURAD
#define SCROLL_SPEED 2//マップスクロール値
#define MAP_DATA 4//マップの数
#define MAP_WITHT 1280//マップの幅


#include "../Global.h"
#include"../System/TaskSystem/CTaskManager.h"
#include "../../System/CharaBase/CCharaBase.h"

struct T_MapData
{
	char imgName[64];
};
struct T_MapDataBack
{
	char imgName[64];
};
class CMap : public CBase{
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
	CImage *m_ground;//仮
	CImage *m_ground2;//仮
	CImage *m_mapRight;//明るさ
	float m_mapTime;//透明度
	E_Stage m_stage;//今の時刻
	E_Stage m_newstage;//次の時刻
	
	T_MapDataBack *map_eDataBack;
	int m_time;
	int m_cont;
public:
	CMap(E_Stage type);
	~CMap();
	void Update();
	void Draw();
	//void Setstge(E_Stage stage);
};


#endif // !CMAP_GURAD
