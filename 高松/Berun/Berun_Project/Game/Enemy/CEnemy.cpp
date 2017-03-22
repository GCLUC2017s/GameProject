#include"CEnemy.h"
#include "../CPlayer/CPlayer.h"



/*T_EnemyData g_enemyData[] =
{
	//ID,Å‘åHP,Œ»İHP,UŒ‚—Í,–hŒä—Í,ŒoŒ±’l,ˆÚ“®‘¬“x
	{ 0,0,0,0,0,0,0.0f },
};*/


CEnemy::CEnemy(int type):CCharaBase(type,eEnemy,eUDP_Enemy,eDWP_Enemy)
{

	m_pos = CVector3D(1000, 0 ,300);
	m_enemyHp = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Meter"));
	m_enemyTime = 0;
	m_enemyHp->SetColor(1, 0, 0, 1);

	mp_player = CPlayer::mp_player;
	
}
CEnemy::~CEnemy() {

}
void CEnemy::Contlol() {
	CCharaBase::ResetKey();
	m_enemyTime++;
	CVector3D vec = mp_player->GetPos();
	if (eChick) {
		if (m_enemyTime > 120 && m_enemyTime < 200) {
			m_left = true;
		}
		if (m_enemyTime > 200) {
		
			m_dash = true;
			
		}
		
		
//		if (m_enemyTime > 250) ChangeAnimation();
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

