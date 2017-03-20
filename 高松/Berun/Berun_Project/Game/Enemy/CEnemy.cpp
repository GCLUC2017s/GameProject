#include"CEnemy.h"



/*T_EnemyData g_enemyData[] =
{
	//ID,Å‘åHP,Œ»İHP,UŒ‚—Í,–hŒä—Í,ŒoŒ±’l,ˆÚ“®‘¬“x
	{ 0,0,0,0,0,0,0.0f },
};*/


CEnemy::CEnemy(int type):CCharaBase(type,eUDP_Enemy,eDWP_Enemy)
{
	m_pos = CVector3D(300, 0 ,300);
	m_enemyHp= dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Meter"));
	
	m_enemyHp->SetColor(1, 0, 0, 1);
	
}
CEnemy::~CEnemy() {

}
void CEnemy::Key() {

	CCharaBase::Key();
}

/*void CEnemy::Update() {
	
	if (m_pos.x > -10) {
		if (eCarrot) {
			m_enemyHp->SetPos(m_pos.x, m_pos.z+100);
			m_pos.x -=  2;
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

