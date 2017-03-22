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
	m_enemyAppears = rand() % 4;
	m_pos = CVector3D(1200, 0 ,200+50*m_enemyAppears);
	m_enemyType = type;
	m_enemyTime = 0;
	//m_enemyHp->SetColor(1, 0, 0, 1);
	m_chickTime = 0;
		

}
CEnemy::~CEnemy() {

}
void CEnemy::Draw() {

	CCharaBase::Draw();

}
void CEnemy::Contlol() {
	CCharaBase::ResetKey();
	
	
	CVector3D vec = mp_player->GetPos() - m_pos;

	
	if (m_enemyType == 5) {
		m_chickTime += 0.5f;

		if (m_chickTime <= 120) {
			m_attack = true;
		}
		if (m_chickTime >= 120 && m_chickTime <= 400) {
			m_attack = false;
			if (vec.x < -120) {
				m_pos.x -= 3;
			}
			if (vec.x > 120) {
				m_pos.x += 3;
			}
			if (vec.z > 120) {
				m_pos.z += 3;
			}
			if (vec.z < -120) {
				m_pos.z -= 3;
			}
		}
	}
	if (m_enemyType == 4) {
		m_chickTime += 0.5f;
		if (m_chickTime > 80 && m_chickTime <= 100) {
			if (vec.x < -120) {
				m_pos.x -= 4;
			}
			if (vec.x > 120) {
				m_pos.x += 4;
			}
			if (vec.z > 120) {
				m_pos.z += 4;
			}
			if (vec.z < -120) {
				m_pos.z -= 4;
			}
			m_pos.y += 30;
		}
		if (m_chickTime >= 100&&m_chickTime>=120) {
			if (vec.x < -120) {
				m_pos.x -= 4;
			}
			if (vec.x > 120) {
				m_pos.x += 4;
			}
			if (vec.z > 120) {
				m_pos.z += 4;
			}
			if (vec.z < -120) {
				m_pos.z -= 4;
			}
			m_pos.y -= 30;
		}
		if (m_chickTime > 120) {
			m_chickTime = 80;
		}

	}

	if (m_enemyType == 3) {
		m_chickTime+=0.5f;
		if (m_chickTime>80&&m_chickTime <= 400) {
			if (vec.x < -120) {
				m_pos.x -= 1;
			}
			if (vec.x > 120) {
				m_pos.x += 1;
			}
			if (vec.z > 120) {
				m_pos.z += 1;
			}
			if (vec.z < -120) {
				m_pos.z -= 1;
			}
		}
		if (m_chickTime >= 400) {
			m_pos.z -= 2;
			m_pos.x += 1;
			if (m_pos.z<-400) {
				m_chickTime = 400;
				
			}
		}
	}
		if (m_enemyTime > 120 && m_enemyTime < 130) {
			m_left = true;
		}
		m_enemyTime++;
		if (m_enemyTime > 130) {
			m_left = true;
			m_dash = true;
			m_enemyTime = 250;
			m_attack = false;

			if (m_cont <= 100) {
				srand(time(nullptr));
				m_enemyPatarn = rand() % 3;
			}
			if (m_cont >= 100) {
				m_cont = 0;
				m_enemyPatarn = 0;
			}
			if (m_enemyType == 2) {
				if (m_enemyPatarn == 0) {
					if (vec.x < -120) {
						m_pos.x -= 3;
					}
					if (vec.x > 120) {
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
					if (vec.x < 120) {
						m_pos.x -= 1;
					}
					if (vec.x > -120) {
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
					m_enemyTime += 5;
					//	m_attack = true;
					if (vec.x < 120) {
						m_pos.x -= 3;
					}
					if (vec.x > -120) {
						m_pos.x += 3;
					}
					if (vec.z > 120) {
						m_pos.z += 3;
					}
					if (vec.z < -120) {
						m_pos.z -= 3;
					}
				}
			}
		}
	

	
		
	
	//m_enemyHp->SetPos(m_pos.x, m_pos.z);

	
		
	
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


