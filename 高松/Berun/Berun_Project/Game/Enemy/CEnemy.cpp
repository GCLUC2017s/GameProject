#include"CEnemy.h"



/*T_EnemyData g_enemyData[] =
{
	//ID,Å‘åHP,Œ»İHP,UŒ‚—Í,–hŒä—Í,ŒoŒ±’l,ˆÚ“®‘¬“x
	{ 0,0,0,0,0,0,0.0f },
};*/

CEnemy::CEnemy(int type):CCharaBase(type,eUDP_Enemy,eDWP_Enemy)
{
	m_pos = CVector3D(120, 0,0);
	m_enemyHp= dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Meter"));
}
CEnemy::~CEnemy() {

}

void CEnemy::_key() {
	CCharaBase::_key();

	
	m_right =true;
}
/*
void CEnemy::Update() {
	
	if (m_enemytime < 200) {
		m_vegetavelenemy->SetRect(0, 0, 160, 84);
		m_vegetavelenemy->SetSize(160, 84);
		m_vegetavelenemy->SetPos(600, 500);
		m_enemytime++;
	}
	if (m_enemytime >= 200) {
		m_vegetavelenemy->SetRect(0, 0, 160, 160);
		m_vegetavelenemy->SetSize(160, 160);
		m_vegetavelenemy->SetPos(600, 416);
	}
	
	
	
	
}
void CEnemy::Draw(){
	
	m_vegetavelenemy->Draw();
}
*/