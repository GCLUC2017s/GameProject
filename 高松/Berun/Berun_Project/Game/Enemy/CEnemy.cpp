#include"CEnemy.h"
#include "../CPlayer/CPlayer.h"
#include"../System/TaskSystem/CTaskManager.h"


/*T_EnemyData g_enemyData[] =
{
	//ID,ç≈ëÂHP,åªç›HP,çUåÇóÕ,ñhå‰óÕ,åoå±íl,à⁄ìÆë¨ìx
	{ 0,0,0,0,0,0,0.0f },
};*/


CEnemy::CEnemy(int type):CCharaBase(type,eEnemy,eUDP_Enemy,eDWP_Enemy)
{
	//CPlayer *p = dynamic_cast<CPlayer*>(CTaskManager::GetInstance()->GetTask(ePlayer));
	//CVector3D vec = p->GetPos() - m_pos;
	mp_player = CPlayer::mp_player;
	
	srand(time(nullptr));
	m_enemyAppears = rand() % 4;
	m_pos = CVector3D(1200+m_scroal.x, 0 ,200+50*m_enemyAppears);
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
	if (mp_player->GetDeath()) return;

	if (m_hp <= 0) {
		m_death = true;
	}

	if (m_hp > 0) {

		if (m_enemyType == 5) {
			m_chickTime += CHICK_TIME;

			if (m_chickTime <= 120) {
				if (vec.x < 20) {
					m_left = true;
				}

				if (vec.x > -20) {
					m_right = true;
				}
				m_attack = true;
			}
			if (m_chickTime >= 120 && m_chickTime <= 160) {
				if (vec.x < 20) {
					m_left = true;
				}

				if (vec.x > -20) {
					m_right = true;
				}
				if (vec.z > -20) {
					m_up = true;
				}
				if (vec.z < 20) {
					m_down = true;
				}
			}
			if (m_chickTime >= 250) {
				m_chickTime = 0;
			}

		}









		if (m_enemyType == 4) {

			m_chickTime += CHICK_TIME;
			if (m_chickTime > 80 && m_chickTime <= 100) {
				if (vec.x < 20) {
					m_left = true;
				}
				if (vec.x > -20) {
					m_right = true;

				}
				if (vec.z > -20) {
					m_up = true;
				}
				if (vec.z < 20) {
					m_down = true;
				}

			}
			if (m_chickTime >= 100 && m_chickTime <= 120) {
				if (vec.x < 20) {
					m_left = true;
				}
				if (vec.x > -20) {
					m_right = true;

				}
				m_jump = true;
			}
			if (m_chickTime >= 140) {
				m_chickTime = 0;
			}

		}




		if (m_enemyType == 3) {
			m_chickTime += CHICK_TIME;

			if (m_chickTime >= 80 && m_chickTime <= 400) {

				if (vec.x < -110) {

					m_left = true;
				}
				if (vec.x > 140) {
					m_right = true;
				}
				if (vec.z > -100) {
					m_up = true;
				}
				if (vec.z < 100) {
					m_down = true;
				}
			}
			if (m_chickTime >= 400) {
				if (vec.x < 0) {
					m_right = true;
				}

				if (m_chickTime > 450) {
					m_chickTime = 80;

				}
			}
		}

		if (m_enemyType == 2) {

			m_chickTime += CHICK_TIME;
			if (m_chickTime >= 80 && m_chickTime <= 150) {
				if (vec.x < -120) {
					m_left = true;
				}
				if (vec.x > 140) {
					m_right = true;
				}
				if (vec.z > -20) {
					m_up = true;
				}
				if (vec.z < 20) {
					m_down = true;
				}
			}
			if (m_chickTime >= 150 && m_chickTime <= 170) {
				if (vec.x < 20) {
					m_left = true;
				}
				if (vec.x > -20) {
					m_right = true;
				}
				m_jump = true;
			}
			if (m_chickTime >= 170 && m_chickTime <= 190) {
				m_right = true;

			}
			if (m_chickTime >= 250) {
				m_chickTime = 0;
			}
		}
	}
}
	

		void CEnemy::HitCallBack(CCollisionA * p)
		{
			CCharaBase::HitCallBack(p);
			CCharaBase* tt = dynamic_cast<CCharaBase*>(p);

			if (m_state != eState_Attack && tt)
			{
				if (!m_damage)
				{
					//HPÇå∏ÇÁÇ∑èàóù
					m_hp--;
					m_hp -= tt->GetAttack();
					if (m_pos.x < tt->GetPos().x)	m_damageDirection = true;
					if (m_pos.x > tt->GetPos().x)	m_damageDirection = false;
				}
				m_damage = true;
			}
		}
	
	
		
	
	//m_enemyHp->SetPos(m_pos.x, m_pos.z);

	
		
	
	//if()


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


