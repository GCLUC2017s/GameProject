/**
*@file	 CEnemy.h
*@brief  “GƒNƒ‰ƒX
*@author Kousei Miyata
*/

#ifndef CENEMY_GURAD
#define CENEMY_GUARD
#include"../Global.h"
#include "../../System/CharaBase/CCharaBase.h"
class CPlayer;




class CEnemy:public CCharaBase {
private:

	//int m_enemytime;
	void Contlol();
	int m_enemyAppears;
	CPlayer *mp_player;
	int m_enemyTime;

public:
	
	CEnemy(int type);
	
	~CEnemy();

//	void Update();
	
	void Draw();
	

	/*void HitCallback(CBase *b);
	static CEnemy* GetmainEnemy() { return mainEnemy; };
	*/
};




#endif // CENEMY_GURAD
