#include"CEnemy.h"
#include "../CPlayer/CPlayer.h"
#include"../System/TaskSystem/CTaskManager.h"


/*T_EnemyData g_enemyData[] =
{
	//ID,最大HP,現在HP,攻撃力,防御力,経験値,移動速度
	{ 0,0,0,0,0,0,0.0f },
};*/

CEnemy::CEnemy(int type, CVector3D pos) :CCharaBase(type, eEnemy, eUDP_Enemy, 600 - pos.z)
{
	//CPlayer *p = dynamic_cast<CPlayer*>(CTaskManager::GetInstance()->GetTask(ePlayer));
	//CVector3D vec = p->GetPos() - m_pos;
	mp_player = CPlayer::mp_player;
	m_pos = pos;
	srand(time(nullptr));
	m_enemyType = type;
	m_enemyTime = 0;
	//m_enemyHp->SetColor(1, 0, 0, 1);
	m_chickTime = 0;
	m_rabittoCont = 0;
	m_rabittoCont2 = 0;
	m_cont =0;
	m_downCont = 0;
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

	if (m_hp > 0) {

			if (m_hp > 0) {
				m_rabittoCont++;
			}

			if (m_enemyType == 6) {
				//ボス行動パターン
				
					m_chickTime += CHICK_TIME;
					if (m_rabittoCont <= 10) {
						m_pos = CVector3D(RABBIT_X, 0, 300);
					}

					
					if(m_chickTime>=RABBIT_CONTTWO&&m_chickTime<=RABBIT_CONTTHREE)
						if (vec.x <VEC_XZ) {
							m_left = true;
							m_dash = true;
						}

						if (vec.x > VEC_XXZZ) {
							m_right = true;
							m_dash = true;
						}
						if (vec.z > VEC_XXZZ) {
							m_up = true;
						}
						if (vec.z < VEC_XZ) {
							m_down = true;
						}
					
					if (m_chickTime >= RABBIT_CONTTHREE) {
						m_dash = false;
						m_right = false;
						m_left = false;
						m_up = false;
						m_down = false;
						m_chickTime = 30;
					}
				}
		
		
		

		if (m_enemyType == 5) {
			//豚行動パターン
				m_chickTime += CHICK_TIME;

				if (m_chickTime <= 120) {
					if (vec.x < VEC_XZ) {
						m_left = true;
						m_attack = true;
					}

					if (vec.x > VEC_XXZZ) {
						m_right = true;
						m_attack = true;
					}

				}
				if (m_chickTime >= 120 && m_chickTime <= 160) {
					if (vec.x <VEC_XZ) {
						m_left = true;
					}

					if (vec.x > VEC_XXZZ) {
						m_right = true;
					}
					if (vec.z > VEC_XXZZ) {
						m_up = true;
					}
					if (vec.z < VEC_XZ) {
						m_down = true;
					}
				}
				if (m_chickTime >= 250) {
					m_chickTime = 0;
				}

			}
		









		if (m_enemyType == 4) {
			//魚行動パターン
			m_chickTime += CHICK_TIME;
			if (m_chickTime > 60 && m_chickTime <= 80) {
				if (vec.x < VEC_XZ) {
					m_dash = true;
					m_left = true;
				}
				if (vec.x > VEC_XXZZ) {
					m_dash = true;
					m_right = true;

				}
				if (vec.z >VEC_XXZZ) {
					m_up = true;
				}
				if (vec.z < VEC_XZ) {
					m_down = true;
				}

			}
			if (m_chickTime >= 100 && m_chickTime <= 120) {
				if (vec.x < VEC_XZ) {
					m_dash = true;
					m_left = true;
				}
				if (vec.x > VEC_XXZZ) {
					m_dash = true;
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
			//ひよこ行動パターン
			if (m_chickTime >= 40 && m_chickTime <= 400) {

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
			//ニンジン行動パターン
			m_chickTime += CHICK_TIME;
			if (m_chickTime >= 80 && m_chickTime <= 150) {
				if (vec.x < -120) {
					m_left = true;
				}
				if (vec.x > 140) {
					m_right = true;
				}
				if (vec.z > VEC_XXZZ) {
					m_up = true;
				}
				if (vec.z < VEC_XZ) {
					m_down = true;
				}
			}
			if (m_chickTime >= 150 && m_chickTime <= 170) {
				if (vec.x < VEC_XZ) {
					m_left = true;
				}
				if (vec.x > VEC_XXZZ) {
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
	
	CCharaBase* tt = dynamic_cast<CCharaBase*>(p);
	//もし敵同士が衝突したら
	if (m_type == tt->CheckType())
	{
		printf("好きな処理 \n");
	}
	else if (tt->CheckState() == eState_Attack)
	{
		if(m_pos.x < tt->GetPos().x)	m_damageDirection = true;
		if (m_pos.x > tt->GetPos().x)	m_damageDirection = false;
		m_hp-=ENEMY_HP;
		if (!m_hp)	m_death = true;
		m_damage = true;
	}
}

void CEnemy::Down()
{
	m_downCont += CHANGE_TIME(DOWN_TIME);
	//キャラクターを削除する処理
	if(m_downCont == DOWN_TIME) m_destroyFlg = true;
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


