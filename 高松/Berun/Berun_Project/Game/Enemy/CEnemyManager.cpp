#include"CEnemyManager.h"
#include"CEnemy.h"
#include"../System/CharaBase/CCharaBase.h"
#include"../CPlayer/CPlayer.h"




CEnemyManager::CEnemyManager():CTask(0,0) {
	m_enemyCont = 0;
	m_enemy = 0;
	mp_player = CPlayer::mp_player;

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
	CVector3D vec = mp_player->GetPos();//��
	
	m_enemyType= rand() % 3;
	if(vec.x>640){
		//
		if (m_enemy < ENEMY_MAX) {
		m_enemyCont += ENEMY_COUNT;
		if (m_enemyCont > ENEMY_TIME) {
			m_enemyCont = 0;

			m_enemy++;
			Add(m_enemyType+2);
		}
	}

	}
}