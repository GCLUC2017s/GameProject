
/**
* @file		CEnemyManager.h
* @brief	敵管理クラス
* @author	kousei miyata
*/

#ifndef CENEMYMANAGER_GURAD
#define CENEMYMANAGER_GUARD
#define ENEMY_MAX 5//敵の最大数
#define ENEMY_MAXONE 2//敵の最大数2
#define ENEMY_MAXTWO 4//敵の最大数3
#define ENEMY_DATA 0//敵の現在数
#define ENEMY_TIME 200//敵生成処理
#define ENEMY_COUNT 1

#include"../System/TaskSystem/CTaskManager.h"
#include"../Global.h"
#include "../../System/CharaBase/CCharaBase.h"

class CPlayer;
class CEnemyManager  : public CTask{
private:
	int m_enemyCont;
	int m_enemy;
	int m_enemyType;
	CPlayer *mp_player;
	CImage *m_enemyHp;
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