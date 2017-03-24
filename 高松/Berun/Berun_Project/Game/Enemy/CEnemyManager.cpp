#include"CEnemyManager.h"
#include"CEnemy.h"
#include"../System/CharaBase/CCharaBase.h"
#include"../CPlayer/CPlayer.h"
#include"../CGame.h"


CEnemyManager::CEnemyManager() :CTask(0, 0, 0) {
	m_enemyCont = 0;
	m_enemy = 0;
	mp_player = CPlayer::mp_player;


	m_step = 0;
}
CEnemyManager::~CEnemyManager() {

}

void CEnemyManager::Add(int type) {
	srand(time(nullptr));
	int m_enemyPears = rand() % 4;
	CVector2D sPos = CBase::GetScroal();
	
		CVector3D pos = CVector3D(ENEMY_POS + sPos.x, 0, 250 + (50 * m_enemyPears));
		new CEnemy(type, pos);
}
/*CEnemy* CEnemyManager::Destory(CEnemy *p) {
	delete p;
}*/


void CEnemyManager::Update () {
	CVector3D vec = mp_player->GetPos();
	m_enemyType = 0;
	m_enemy = CTaskManager::GetInstance()->GetCount(eEnemy);
	switch (m_step)
	{
	case 0:
		if (m_enemy < ENEMY_MAXONE) {
			m_enemyCont += ENEMY_COUNT;
			if (m_enemyCont > ENEMY_TIME) {
				m_enemyCont = 0;
				m_enemyType = eCarrot+ rand() % 4;
				m_enemy++;
				Add(m_enemyType);
			}
		}
		if (vec.x > 3800) {
			Add(eVegetavelboss);
			m_step++;
		}
		break;
	case 1:
		if (m_enemy < ENEMY_MAXTWO) {
			m_enemyCont += ENEMY_COUNT;
			if (m_enemyCont > ENEMY_TIME) {
				m_enemyCont = 0;
				m_enemyType = eCarrot + rand() % 4;
				m_enemy++;
				Add(m_enemyType);
			}
		}
		break;
	}

		
	
	

	
}
