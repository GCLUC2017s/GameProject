#include"CEnemy.h"
#include "../CPlayer/CPlayer.h"



/*T_EnemyData g_enemyData[] =
{
	//ID,最大HP,現在HP,攻撃力,防御力,経験値,移動速度
	{ 0,0,0,0,0,0,0.0f },
};*/


CEnemy::CEnemy(int type):CCharaBase(type,eEnemy,eUDP_Enemy,eDWP_Enemy)
{
	mp_player = CPlayer::mp_player;
	CVector3D vec = mp_player->GetPos() - m_pos;
	srand(time(nullptr));
	
	m_pos = CVector3D(5120/vec.x, 0 ,10+50);
	
	m_enemyTime = 0;
	m_enemyHp->SetColor(1, 0, 0, 1);
	
	
	
}
CEnemy::~CEnemy() {

}
void CEnemy::Contlol() {
	CCharaBase::ResetKey();
	if (m_cont <= 100) {
		srand(time(nullptr));
		m_enemyPatarn = rand()%3;
	}
	if (m_cont >= 100) {
		m_cont = 0;
		m_enemyPatarn = 0;
	}
	m_enemyTime++;
	CVector3D vec = mp_player->GetPos() - m_pos;
	
		if (m_enemyTime > 120 && m_enemyTime < 200) {
			m_left = true;
		}
		
		if (m_enemyTime > 200) {
			m_left = true;
			m_dash = true;
			m_enemyTime = 250;
			if (m_enemyPatarn == 0) {
				if (vec.x < -100) {
					m_pos.x -= 3;
				}
				if (vec.x > 100) {
					m_pos.x += 3;
				}
				if (vec.z > -120) {
					m_pos.z += 3;
				}
				if (vec.z < 120) {
					m_pos.z -= 3;
				}
			}
			if (m_enemyPatarn == 1) {
				if (vec.x < 100) {
					m_pos.x -= 1;
				}
				if (vec.x > -100) {
					m_pos.x += 1;
				}
				if (vec.z > 120) {
					m_pos.z += 1;
				}
				if (vec.z < -120) {
					m_pos.z -= 1;
				}
			}
			if (m_enemyPatarn == 2) {
				m_left = false;
				m_dash = false;
				m_attack = true;
				if (vec.x < -100) {
					m_pos.x -= 3;
				}
				if (vec.x > 100) {
					m_pos.x += 3;
				}
				if (vec.z > -120) {
					m_pos.z += 3;
				}
				if (vec.z < 120) {
					m_pos.z -= 3;
				}
			}

		
			
		}
	

	
		
	
	m_enemyHp->SetPos(m_pos.x, m_pos.z);

	
		
	
	//if()
}

/*void CEnemy::Update() {
	
	if (m_pos.x > -10) {
		if (eCarrot) {
			m_enemyHp->SetPos(m_pos.x, m_pos.z+100);
			
		}
	}
	else {
		
		m_pos.x = 1280;
	}
	if (m_hp < 0) {
		
	}
	
	
}*/
void CEnemy::Draw(){

	CCharaBase::Draw();
	//m_enemyHp->Draw();
}

