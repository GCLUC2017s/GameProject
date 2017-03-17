

/**
*@file	 CMap.h
*@brief  �}�b�v�N���X
*@author Kousei Miyeta
*/
#ifndef CMAP_GURAD
#define CMAP_GURAD
#define SCROLL_SPEED 2//�}�b�v�X�N���[���l
#define MAP_DATA 4//�}�b�v�̐�
#define MAP_WITHT 1280//�}�b�v�̕�


#include "../Global.h"
#include"../System/TaskSystem/CTaskManager.h"
#include "../../System/CharaBase/CCharaBase.h"

struct T_MapData
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
	
	
	E_Stage m_stage;
	E_Stage m_newstage;
	T_MapData *map_eData;
	

public:
	CMap(E_Stage type);
	~CMap();
	void Update();
	void Draw();
	//void Setstge(E_Stage stage);
};


#endif // !CMAP_GURAD
