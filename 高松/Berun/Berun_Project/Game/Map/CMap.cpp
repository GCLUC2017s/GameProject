#include"CMap.h"
#include<assert.h>
#include<stdio.h>
#include"../Berun_Project/Global.h"
#include"../System/CharaBase/CCharaBase.h"

CMap::CMap() : CTask(eUDP_Map,eDWP_Map),

m_stage(eStage1)
{

	
	
	

	switch (m_stage)
	{
	case eStage1:
		m_backGroundMorning[MAP_DATA] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("BackGroundMoning"));
		break;
	case eStage2:
		m_backGroundNoon[MAP_DATA]= dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("BackGroundNoon"));
		break;
	case eStage3:
		m_backGroundEvenig[MAP_DATA] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("BackGroundEvenig"));
		break;
	case eStage4:
		m_backGroundNight[MAP_DATA] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("BackGroundNight"));
		break;
	}
	m_mapPos.x = 1280;
	m_mapPos.y = 0;
}
CMap::~CMap() {


}
void CMap::Update() {
	
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
	for (int i = 0; i < MAP_DATA; i++) {
		switch (m_stage)//‰¼,
		{
		case eStage1:
			m_backGroundMorning[MAP_DATA]->SetPos(m_mapPos.x - 1280 * i, m_mapPos.y);
			m_backGroundMorning[MAP_DATA]->Draw();
			break;
		case eStage2:
			m_backGroundNoon[MAP_DATA]->SetPos(m_mapPos.x - 1280 * i, m_mapPos.y);
			m_backGroundNoon[MAP_DATA]->Draw();
			break;
		case eStage3:
			m_backGroundEvenig[MAP_DATA]->SetPos(m_mapPos.x - 1280 * i, m_mapPos.y);
			m_backGroundEvenig[MAP_DATA]->Draw();
			break;
		case eStage4:
			m_backGroundNight[MAP_DATA]->SetPos(m_mapPos.x - 1280 * i, m_mapPos.y);
			m_backGroundNight[MAP_DATA]->Draw();
			break;

		}
		
		
	}
		//m_backGroundNoon[MAP_DATA]->Draw();
		//m_backGroundEvenig[MAP_DATA]->Draw();
		//m_backGroundNight[MAP_DATA]->Draw();
	}

