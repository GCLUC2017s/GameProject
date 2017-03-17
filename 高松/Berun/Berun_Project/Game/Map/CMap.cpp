#include"CMap.h"
#include<assert.h>
#include<stdio.h>
#include"../Berun_Project/Global.h"
#include"../System/CharaBase/CCharaBase.h"


static T_MapDataBack g_mapDataBack[]{
	{ "BackGroundMoningBack", },
	{ "BackGroundNoonBack", },
	{ "BackGroundEveingBack", },
	{ "BackGroundNightBack", },
};


CMap::CMap(E_Stage type) : CBase(eUDP_Map, eDWP_Map) {

	m_mapTime = 0;
	for (int i = 0; i < MAP_DATA; i++) {
		m_backGround[i] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get(g_mapDataBack[i].imgName));
	}

	m_ground = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("BackGround"));
	m_ground2 = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("BackGround2"));
	m_mapRight= dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Back_03"));
	m_stage = type;
	m_newstage= static_cast<E_Stage>(m_stage + 1);
	m_pos = CVector3D(0, 0, 0);
	m_cont = 0;
}
CMap::~CMap() {
}
void CMap::Update() {
	//ポインタの場合はデストラクトを作る
	//ポインタじゃなかったら自動的に呼ばれる
	
	m_mapTime += 0.05f;
	if (m_mapTime > 2.0f) {
	if (m_cont <= 3) {
		m_cont++;
		m_mapTime = 0;
		m_stage = static_cast<E_Stage>(m_stage + 1);
		m_newstage = static_cast<E_Stage>(m_stage + 1);
		}
	if (m_cont >= 3) {
		m_mapTime = 0;
		if (m_mapTime <= 2.0f) {
			m_mapTime += 0.05;
			m_stage = static_cast<E_Stage>(m_stage);
			m_newstage = static_cast<E_Stage>(m_stage - 3);
		}
		else {
			m_cont = 0;
			m_mapTime = 0;
			m_stage = static_cast<E_Stage>(m_stage + 1);
			m_newstage = static_cast<E_Stage>(m_stage + 1);
		}

	}
	
		
	

			
		}

	
		CVector2D m_mapScreen = GetScroal();
		m_mapScreen.x = (int)m_mapScreen.x % MAP_WITHT;
		if (m_cont == 3) {

		}
		m_backGround[m_newstage]->SetColor(1, 1, 1, m_mapTime);
		m_backGround[m_newstage]->SetPos(0, 0);

		m_backGround[m_stage]->SetColor(1, 1, 1, 1 - m_mapTime);
		m_backGround[m_stage]->SetPos(0, 0);

		//m_mapRight->SetColor(1, 0, 0, 0.5f);
		//	m_mapRight->SetPos(-m_mapScreen.x + MAP_WITHT*i, -m_mapScreen.y);
		//	m_mapRight->Draw();
	for (int i = 0; i < 2; i++) {
		m_ground->SetColor(1, 1, 1, 1);
		m_ground->SetPos(-m_mapScreen.x + MAP_WITHT*i, -m_mapScreen.y);
		m_ground2->SetPos(-m_mapScreen.x, -m_mapScreen.y);
		}
}

void  CMap::Draw() {
	
	//	m_backGround[m_newstage]->SetColor(1, 1, 1, m_mapTime);
		//m_backGround[m_newstage]->SetPos(0, 0);
		//m_backGround[m_newstage]->Draw();
		m_backGround[m_newstage]->Draw();
		m_backGround[m_stage]->Draw();
		m_ground->Draw();
		m_ground2->Draw();
}


