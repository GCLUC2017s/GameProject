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
	
	m_enemyHp->SetColor(1, 0, 0, 1);

	mp_player = CPlayer::mp_player;
	
}
CEnemy::~CEnemy() {

}
void CEnemy::Contlol() {
	CCharaBase::ResetKey();
	
	m_enemyHp->SetPos(m_pos.x, m_pos.z);

	if (m_pos.x <= 300) {
		m_pos.x -= 1;
	}
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
	m_enemyHp->Draw();
}

