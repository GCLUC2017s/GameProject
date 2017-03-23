/**
*@file	 CEnemy.h
*@brief  “GƒNƒ‰ƒX
*@author Kousei Miyata
*/

#ifndef CENEMY_GURAD
#define CENEMY_GUARD
#include"../Global.h"
#include "../../System/CharaBase/CCharaBase.h"
#define CHICK_TIME (0.5f)
class CPlayer;
class CEnemyManager;



class CEnemy:public CCharaBase {
private:

	//int m_enemytime;
	void Contlol();
	int m_enemyAppears;
	CPlayer *mp_player;
	CImage *m_img;
	int m_enemyType;
	int m_enemyTime;
	int m_enemyPatarn;
	int m_cont;
	float m_chickTime;
public:
	
	CEnemy(int type);
	
	~CEnemy();

//	void Update();
	
	void Draw();
	

	void HitCallBack(CCollisionA * p);
	
};




#endif // CENEMY_GURAD
