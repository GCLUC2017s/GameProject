/**
*@file	 CEnemy.h
*@brief  �G�N���X
*@author Kousei Miyata
*/

#ifndef CENEMY_GURAD
#define CENEMY_GUARD
#include"../Global.h"
#include "../../System/CharaBase/CCharaBase.h"
#define CHICK_TIME (0.5f)
#define DOWN_TIME 5.0f
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
	float m_downCont;
	float m_chickTime;
public:
	
	CEnemy(int type);
	
	~CEnemy();

//	void Update();
	
	void Draw();
	void Down();
	

	void HitCallBack(CCollisionA * p);
	
};




#endif // CENEMY_GURAD
