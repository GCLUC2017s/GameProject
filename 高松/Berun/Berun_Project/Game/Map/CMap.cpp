#include"CMap.h"


CMap::CMap() : CTask(0,0),
m_backgroundMorning(0),//‰Šú‰»
m_backgroundAfternoon(0),
m_backgroundEvenig(0),
m_backgroundNight(0),
m_stage(eStage1)
{
	
	switch (m_stage)
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
	}
	
}
CMap::~CMap() {


}
void CMap::Update() {

	m_backgroundMorning->SetRect(0,0,1280,768);
	m_backgroundAfternoon->SetRect(0, 0, 1280, 768);
	m_backgroundEvenig->SetRect(0, 0, 1280, 768);
	m_backgroundNight->SetRect(0, 0, 1280, 768);
}

void  CMap::Draw() {

	m_backgroundMorning->Draw();
	m_backgroundAfternoon->Draw();
	m_backgroundEvenig->Draw();
	m_backgroundNight->Draw();
}