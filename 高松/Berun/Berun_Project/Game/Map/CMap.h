

/**
*@file	 CMap.h
*@brief  �}�b�v�N���X
*@author �{�c
*/
#ifndef CMAP_GURAD
#define CMAP_GURAD
#define SCROLL_SPEED 2//�}�b�v�X�N���[���l
#define MAP_DATA 3//�}�b�v�̐�
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
	CVector2D m_mapPos;//�}�b�v���W�ω�


public:
	CMap();
	~CMap();
	void Update();
	void Draw();
	//void Setstge(E_Stage stage);
};

#endif // !CMAP_GURAD
