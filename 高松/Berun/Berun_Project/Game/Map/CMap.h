

/**
*@file	 CMap.h
*@brief  �}�b�v�N���X
*@author Kousei Miyeta
*/
#ifndef CMAP_GURAD
#define CMAP_GURAD
#define SCROLL_SPEED 2//�}�b�v�X�N���[���l
#define MAP_DATA 5//�}�b�v�̔w�i��
#define MAP_WIDTH 1280//�}�b�v�̕�
#define MAP_GROUND 2//�}�b�v�̓��摜��
#define MAP_TIME 0.003f//�}�b�v�̕ω�����
#define MAP_CHANGE 2.0f//�}�b�v�̐؂�ւ�����

#include "../Global.h"
#include"../../System/TaskSystem/CTaskManager.h"
#include "../../System/CharaBase/CCharaBase.h"

struct T_MapData
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
		STAGE_COUNT
	};
private:
	CImage *m_backGround[MAP_DATA];
	CImage *m_ground[MAP_GROUND];



	float m_mapTime;//�����x
	E_Stage m_stage;//���̎���
	E_Stage m_newstage;//���̎���
	

	
	
	int m_cont;
public:
	CMap(E_Stage type);
	~CMap();
	void Update();
	void Draw();
	//void Setstge(E_Stage stage);
};


#endif // !CMAP_GURAD