#ifndef CENEMY_GURAD
#define CENEMY_GUARD
#include"../System/Base/CBase.h"
#include"../Global.h"

/**
*@file	 CEnemy.h
*@brief  敵クラス
*@author 宮田
*/



class CEnemy:public CBase {
private:
	
	CImage *m_vegetavelenemy;
	enum vegetavelenemy //ステージ１野菜・果物敵
	{
		carrot,//ニンジン
		papurika,//ピーマン
		berry,//イチゴ空中
		strawberry//イチゴ地上
	};
	CVector3D m_enemypos;
public:
	


	static CEnemy* mainEnemy;		
	CEnemy(T_EnemyData *data);
	
	~CEnemy();
	
	void Update();
	
	void Draw();
	

	/*void HitCallback(CBase *b);
	static CEnemy* GetmainEnemy() { return mainEnemy; };
	*/
};




#endif // CENEMY_GURAD
