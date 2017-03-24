#include"CEnemyManager.h"
#include"CEnemy.h"
#include"../System/CharaBase/CCharaBase.h"
#include"../CPlayer/CPlayer.h"
#include"../CGame.h"


CEnemyManager::CEnemyManager() :CTask(0, 0, 0) {
	m_enemyCont = 0;
	m_enemy = 0;
	mp_player = CPlayer::mp_player;

	
	
}
CEnemyManager::~CEnemyManager() {

}

void CEnemyManager::Add(int type) {
	
	int enemyAppears = rand() % 4;
	CVector2D sPos = CBase::GetScroal();
	CVector3D pos = CVector3D(1100 + (sPos.x *enemyAppears), 0, 250 + (50 * enemyAppears));
	new CEnemy(type,pos);
}
/*CEnemy* CEnemyManager::Destory(CEnemy *p) {
	delete p;
}*/


void CEnemyManager::Update () {
	CVector3D vec = mp_player->GetPos();
	m_enemyType = 0;
	
	

		if (m_enemy < ENEMY_MAXONE) {
			if (vec.x > 400&&vec.x<1200) {
					m_enemyCont += ENEMY_COUNT;
					if (m_enemyCont > ENEMY_TIME) {
						m_enemyCont = 0;
						m_enemy++;
						Add(m_enemyType + 2 + m_enemy);
						
						
					}
				
			}
		}
	
	
	if (vec.x > 1200 && vec.x < 1700) {
		m_enemy = 0;
		m_enemyType = 0;
	}
	if (vec.x>1700&&m_enemyType<2200) {
		
		if (m_enemy < ENEMY_MAXTWO) {
			m_enemyCont += ENEMY_COUNT;
			if (m_enemyCont > ENEMY_TIME) {
				m_enemyCont = 0;

				m_enemy++;
				Add(m_enemyType + 3+m_enemy);
			}
		}
	}
	if (vec.x > 2200 && vec.x < 2200) {
		m_enemy = 0;
		m_enemyType = 0;
	}
	if (vec.x > 3700) {
		if (m_enemy < ENEMY_MAX) {
			m_enemy++;
			
			Add(m_enemyType + 4+m_enemy);
		}
	}
}
