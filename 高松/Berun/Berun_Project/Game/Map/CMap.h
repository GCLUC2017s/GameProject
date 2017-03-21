

/**
*@file	 CMap.h
*@brief  �}�b�v�N���X
*@author Kousei Miyeta
*/
#ifndef CMAP_GURAD
#define CMAP_GURAD
#define SCROLL_SPEED 2//�}�b�v�X�N���[���l
#define MAP_DATA 5//�}�b�v�̐�
#define MAP_WITHT 1280//�}�b�v�̕�
#define MAP_GROUND 2


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
class CMap : public CBase {
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
	CImage *m_ground[MAP_GROUND];



	float m_mapTime;//�����x
	E_Stage m_stage;//���̎���
	E_Stage m_newstage;//���̎���
	E_Stage m_stage2;
	E_Stage m_newstage2;

	T_MapDataBack *map_eDataBack;
	T_MapData *map_eData;
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