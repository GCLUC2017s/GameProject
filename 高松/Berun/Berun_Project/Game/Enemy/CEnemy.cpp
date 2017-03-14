#include"CEnemy.h"




CEnemy::CEnemy() :CTask(1),
m_carrot(0),//‰Šú‰»
m_enemytype(eCarrot)//‰Šú‰»
{
	m_enemytime = 0;
	switch (m_enemytype)
	{
	case eCarrot:
		
		m_carrot = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Carrot"));
	
		break;
	
	}
	
	
	
	
	
}
CEnemy::~CEnemy() {

}
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