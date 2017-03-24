
/**
* @file		CEnemyManager.h
* @brief	�G�Ǘ��N���X
* @author	kousei miyata
*/

#ifndef CENEMYMANAGER_GURAD
#define CENEMYMANAGER_GUARD
#define ENEMY_MAX 1//�G�̍ő吔
#define ENEMY_MAXONE 5//�G�̍ő吔2
#define ENEMY_MAXTWO 3//�G�̍ő吔3
#define ENEMY_DATA 0//�G�̌��ݐ�
#define ENEMY_TIME 200//�G��������
#define ENEMY_COUNT 1
#define ENEMY_POS 1100


#include"../System/TaskSystem/CTaskManager.h"
#include"../Global.h"
#include "../../System/CharaBase/CCharaBase.h"

class CPlayer;
class CEnemyManager  : public CTask{
private:
	int m_cont;
	int m_enemyCont;
	int m_enemy;
	int m_enemyType;
	CPlayer *mp_player;
	CImage *m_enemyHp;
	int m_step;
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