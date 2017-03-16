#include"CMap.h"
#include<assert.h>
#include<stdio.h>
#include"../Berun_Project/Global.h"
#include"../System/CharaBase/CCharaBase.h"


static T_MapData g_mapData[] = {
	{"BackGroundMoning",},
	{ "BackGroundNoon", },
	{ "BackGroundEveing", },
	{ "BackGroundNight", },
};
CMap::CMap(E_Stage type) : CTask(eUDP_Map,eDWP_Map){


	assert(MAP_DATA == 4);
	for (int i = 0; i < MAP_DATA; i++) {
		m_backGround[i] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get(g_mapData[i].imgName));
	}
	m_stage = type;
	m_newstage = static_cast<E_Stage>(m_stage + 1);
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
	
	if (HOLD_KEY_RIGHT) {
		m_mapPos.x -= SCROLL_SPEED;
		
	}
	if (HOLD_KEY_LEFT) {
		m_mapPos.x += SCROLL_SPEED;
	}
}

void  CMap::Draw() {

	m_backGround[m_stage]->SetColor(1, 1, 1, 1);
	m_backGround[m_stage]->Draw();

	m_backGround[m_newstage]->SetColor(1, 1, 1, 0.5f);
	m_backGround[m_newstage]->Draw();

		
	}

