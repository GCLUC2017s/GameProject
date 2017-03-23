#include"CEnemyManager.h"
#include"CEnemy.h"
#include"../System/CharaBase/CCharaBase.h"
#include"../CPlayer/CPlayer.h"
#include"../CGame.h"


CEnemyManager::CEnemyManager() :CTask(0, 0, 0) {
	m_enemyCont = 0;
	m_enemy = 0;
	mp_player = CPlayer::mp_player;
	//m_enemyHp = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Meter"));
	
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
	CVector3D vec = mp_player->GetPos();//‰¼
	
	m_enemyType= rand() % 4;
	if(vec.x>800&&vec.x<1200){
	
		if (m_enemy < ENEMY_MAXONE) {
		m_enemyCont += ENEMY_COUNT;
		if (m_enemyCont > ENEMY_TIME) {
			m_enemyCont = 0;
			
			m_enemy++;
			Add(m_enemyType+2);
		}
	}
	}
	if (vec.x > 1250 && vec.x < 1400) {
		m_enemy = 0;
	}
	if (vec.x>1500&&vec.x>2400) {
		
		if (m_enemy < ENEMY_MAXTWO) {
			m_enemyCont += ENEMY_COUNT;
			if (m_enemyCont > ENEMY_TIME) {
				m_enemyCont = 0;

				m_enemy++;
				Add(m_enemyType + 2);
			}
		}
	}
	if (vec.x > 4200) {
		if (m_enemyCont == 0) {
			m_enemyType = 6;
			Add(m_enemyType);
			m_enemyCont+=1;
			
		}
	}
}