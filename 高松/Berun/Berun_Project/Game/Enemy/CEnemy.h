/**
*@file	 CEnemy.h
*@brief  敵クラス
*@author Kousei Miyata
*/

#ifndef CENEMY_GURAD
#define CENEMY_GUARD
#include"../Global.h"
#include "../../System/CharaBase/CCharaBase.h"
#define CHICK_TIME			(0.5f)
#define DOWN_TIME			 5.0f

#define RABBIT_CONT		60//ボスカウント1
#define RABBIT_CONTTWO		80//ボスカウント2
#define RABBIT_CONTTHREE	100//ボスカウント3
#define RABBIT_CONTFOUR		160//ボスカウント４
#define RABBIT_X			4800//ボスX軸限界値


#define ENEMY_HP			1
class CPlayer;
class CEnemyManager;



class CEnemy:public CCharaBase {
private:

	//int m_enemytime;
	void Contlol();
	int m_enemyAppears;
	CCharaBase *m_parent;
	CPlayer *mp_player;
	CImage *m_img;
	int m_enemyType;
	int m_enemyTime;
	int m_enemyPatarn;
	int m_cont;
	int m_rabittoCont;
	int m_rabittoCont2;
	float m_downCont;
	float m_chickTime;

public:
	
	CEnemy(int type,CVector3D pos);
	
	~CEnemy();

//	void Update();
	
	void Draw();
	void Down();
	

	void HitCallBack(CCollisionA * p);
	
};




#endif // CENEMY_GURAD
