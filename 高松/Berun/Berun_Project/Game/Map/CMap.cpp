#include"CMap.h"


CMap::CMap() : CTask(eUDP_Map,eDWP_Map),

m_stage(eStage1)
{
	m_backgroundMorning[MAP_DATA] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("BackGround"));
	
	/*switch (m_stage)
	{
	case eStage1:
		m_backgroundMorning = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("BackGround"));
		break;
	case eStage2:
		m_backgroundAfternoon = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("BackGround2"));
		break;
	case eStage3:
		m_backgroundEvenig= dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("BackGround3"));
		break;
	case eStage4:
		m_backgroundNight= dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("BackGround4"));
		break;
	}*/
	m_mapPos.x = 1280;
	m_mapPos.y = 0;
}
CMap::~CMap() {


}
void CMap::Update() {

	m_backgroundMorning[MAP_DATA]->SetRect(0,0,1280,768);
	
//	m_backgroundEvenig->SetRect(0, 0, 1280, 768);
//	m_backgroundNight->SetRect(0, 0, 1280, 768);
	m_backgroundMorning[MAP_DATA]->SetPos(m_mapPos.x - 1280, m_mapPos.y);
	
	if (m_mapPos.x == 0) {
		m_mapPos.x = 1280;
	}
	if (m_mapPos.x == 1280) {
		m_mapPos.x == 0;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eRight)) {
		m_mapPos.x -= SCROLL_SPEED;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft)) {
		m_mapPos.x += SCROLL_SPEED;
	}
}

void  CMap::Draw() {
	for (int i = 0; i < 3; i++) {
		m_backgroundMorning[MAP_DATA]->Draw();
	}
//	m_backgroundEvenig->Draw();
//	m_backgroundNight->Draw();
}