#ifndef CENEMY_GURAD
#define CENEMY_GUARD
#include"../Global.h"
#include "../../System/CharaBase/CCharaBase.h"

/**
*@file	 CEnemy.h
*@brief  �G�N���X
*@author �{�c
*/



class CEnemy:public CCharaBase {
private:
	/*
	//��؁E�ʕ�
	CImage *m_carrot;
	CImage *m_papurika;
	CImage *m_berry;
	CImage *m_strawberry;
	CImage *m_vegetavelBoss;
	//��
	CImage *m_pig;
	CImage *m_bird;
	CImage *m_meatboss;
	//��
	CImage *m_squid;
	CImage *m_fish;
	CImage *m_fishBoss;
	//����
	CImage *m_rice;
	CImage *m_bread;
	CImage *m_grainBoss;
	*/
	enum E_Enemy 
	{
	};

	E_Enemy m_enemytype;
	//int m_enemytime;
	void _key();
public:
		
	CEnemy(int type);
	
	~CEnemy();
	/*
	void Update();
	
	void Draw();
	*/

	/*void HitCallback(CBase *b);
	static CEnemy* GetmainEnemy() { return mainEnemy; };
	*/
};




#endif // CENEMY_GURAD
