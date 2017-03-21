#include"CEnemyManager.h"
#include"CEnemy.h"
#include"../System/CharaBase/CCharaBase.h"




CEnemyManager::CEnemyManager():CTask(0,0) {
	m_enemyCont = 0;
	m_enemy = 0;
}
CEnemyManager::~CEnemyManager() {

}

void CEnemyManager::Add(int type) {
	new CEnemy(type);

}
/*CEnemy* CEnemyManager::Destory(CEnemy *p) {
	delete p;
}*/


void CEnemyManager::Update () {

	m_enemyCont += ENEMY_COUNT;
	if (m_enemyCont > ENEMY_TIME) {
		if (m_enemy < ENEMY_MAX) {
			m_enemyCont = 0;

			m_enemy++;
			Add(eChick);
		}


	}
}