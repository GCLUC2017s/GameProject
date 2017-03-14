#ifndef CENEMY_GURAD
#define CENEMY_GUARD
#include"../System/Base/CBase.h"
#include"../Global.h"
#include "../Global.h"
#include"../System/TaskSystem/CTaskManager.h"

/**
*@file	 CEnemy.h
*@brief  敵クラス
*@author 宮田
*/



class CEnemy:public CTask {
private:
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
	
	enum E_Enemy 
	{
		eCarrot,//ニンジン
		ePapurika,//ピーマン
		eBerry,//イチゴサングラス空中
		eStrawberry,//イチゴ地上
		eVegetavelboss,//野菜ボス（ウサギ）
		ePig,//豚
		eBird,//鳥
		eMeatboss,//肉ボス（鶏）
		eSquid,//イカ
		eFish,//魚
		eFishboss,//魚介ボス（鮫）
		eRice,//米
		eBread,//パン
		eGrainboss//穀物ボス（茶碗武士）
	};
	int m_enemytime;
	E_Enemy m_enemytype;
public:
		
	CEnemy();
	
	~CEnemy();
	
	void Update();
	
	void Draw();
	

	/*void HitCallback(CBase *b);
	static CEnemy* GetmainEnemy() { return mainEnemy; };
	*/
};




#endif // CENEMY_GURAD
