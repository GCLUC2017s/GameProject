/**
*@file	 CEnemy.h
*@brief  �G�N���X
*@author �{�c
*/

#ifndef CENEMY_GURAD
#define CENEMY_GUARD
#include"../Global.h"
#include "../../System/CharaBase/CCharaBase.h"





class CEnemy:public CCharaBase {
private:
	//int m_enemytime;
	void Key();
	int m_enemyAppears;
public:
		
	CEnemy(int type);
	
	~CEnemy();
	
	void Update();
	
	void Draw();
	

	/*void HitCallback(CBase *b);
	static CEnemy* GetmainEnemy() { return mainEnemy; };
	*/
};




#endif // CENEMY_GURAD
