/**
*@file	 CEnemy.h
*@brief  �G�N���X
*@author Kousei Miyata
*/

#ifndef CENEMY_GURAD
#define CENEMY_GUARD
#include"../Global.h"
#include "../../System/CharaBase/CCharaBase.h"
#define CHICK_TIME			(0.5f)
#define DOWN_TIME			 5.0f

#define RABITTO_CONT		80//�{�X�J�E���g1
#define RABITTO_CONTTWO		160//�{�X�J�E���g2
#define RABITTO_CONTTHREE	430//�{�X�J�E���g3
#define RABITTO_CONTFOUR	480//�{�X�J�E���g4
#define RABITTO_CONTFIVE	600//�{�X�J�E���g5
#define RABITTO_X			4700//�{�XX�����E�l

#define ENEMY_X				4580
#define ENEMY_Z				800
#define ENEMY_CONTONE		300
#define ENEMY_CONTTWO		450
#define ENEMY_CONTTHREE		550
#define ENEMY_CONTFOUR		790
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
	bool m_cont;
	int m_rabittoCont;
	int m_rabittoCont2;
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
