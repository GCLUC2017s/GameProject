
/**
* @file		CEnemyManager.h
* @brief	“GŠÇ—ƒNƒ‰ƒX
* @author	kousei miyata
*/

#ifndef CENEMYMANAGER_GURAD
#define CENEMYMANAGER_GUARD
#define ENEMY_MAX 5//“G‚ÌÅ‘å”
#define ENEMY_DATA 0//“G‚ÌŒ»İ”
#define ENEMY_TIME 120//“G¶¬ˆ—
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