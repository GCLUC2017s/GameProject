
/**
* @file		CEnemyManager.h
* @brief	敵管理クラス
* @author	kousei miyata
*/
#include"../System/TaskSystem/CTaskManager.h"
#ifndef CENEMYMANAGER_GURAD
#define CENEMYMANAGER_GUARD
#define ENEMY_MAX 5//敵の最大数
#define ENEMY_DATA 0//敵の現在数
#define ENEMY_TIME 120//敵生成処理
#define ENEMY_COUNT 1


class CEnemyManager  : public CTask{
	int m_enemyCont;
	int m_enemy;
//	static CEnemyManager* m_instance;
public:

	CEnemyManager();

	~CEnemyManager();

	void Add(int type);

//	static CEnemyManager* GetInstance();

//	CEnemy* Destory(CEnemy *p);
	void Update();
//	void Draw();
};




#endif //  CENEMYMANAGER_GUARD