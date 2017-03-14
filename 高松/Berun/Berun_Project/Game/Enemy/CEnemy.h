#ifndef CENEMY_GURAD
#define CENEMY_GUARD
#include"../Global.h"
#include "../../System/CharaBase/CCharaBase.h"

/**
*@file	 CEnemy.h
*@brief  敵クラス
*@author 宮田
*/



class CEnemy:public CCharaBase {
private:
	/*
	//野菜・果物
	CImage *m_carrot;
	CImage *m_papurika;
	CImage *m_berry;
	CImage *m_strawberry;
	CImage *m_vegetavelBoss;
	//肉
	CImage *m_pig;
	CImage *m_bird;
	CImage *m_meatboss;
	//魚
	CImage *m_squid;
	CImage *m_fish;
	CImage *m_fishBoss;
	//穀物
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
