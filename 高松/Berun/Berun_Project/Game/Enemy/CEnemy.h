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
