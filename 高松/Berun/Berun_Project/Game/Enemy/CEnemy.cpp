#include"CEnemy.h"




CEnemy::CEnemy(T_EnemyData *data) {
	
	m_vegetavelenemy= dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Berry_01"));
	
}
CEnemy::~CEnemy() {

}
void CEnemy::Update() {
	m_vegetavelenemy->SetRect(0, 0, 160, 160);
	m_vegetavelenemy->SetSize(16, 16);
	m_vegetavelenemy->SetPos(200, 0);

	m_enemypos.x += 1;
}
void CEnemy::Draw(){
	
	m_vegetavelenemy->Draw();
}