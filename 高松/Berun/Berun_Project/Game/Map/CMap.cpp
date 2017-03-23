#include"CMap.h"
#include<assert.h>
#include<stdio.h>
#include"../Berun_Project/Global.h"
#include"../System/CharaBase/CCharaBase.h"

//背景（朝、昼、夕、夜,朝）時間変化する画像
const static T_MapData g_mapDataBack[]{
	{ "BackGroundMoningBack", },
	{ "BackGroundNoonBack", },
	{ "BackGroundEveingBack", },
	{ "BackGroundNightBack", },
	{ "BackGroundMoningBack2", },
};



CMap::CMap(E_Stage type) : CBase(eMap,eUDP_Map, eDWP_Map) {

	m_mapTime = 0;
	for (int i = 0; i < MAP_DATA; i++) {
		m_backGround[i] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get(g_mapDataBack[i].imgName));


	}
	m_ground[0] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("BackGroundMoning2"));
	m_ground[1] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("BackGroundMoning3"));
	
	m_stage = type;

	m_newstage = static_cast<E_Stage>(m_stage + 1);
	m_pos = CVector3D(0, 0, 0);
	m_cont = 0;
}
CMap::~CMap() {
	//ポインタの場合はデストラクトを作る
	//ポインタじゃなかったら自動的に呼ばれる
}

void CMap::Update() {
	
	m_mapTime += MAP_TIME;

	if (m_mapTime >MAP_CHANGE) {
		m_mapTime = 0;
		m_cont = (m_cont + 1) % (int)STAGE_COUNT;
		m_stage = m_newstage;
		m_newstage = static_cast<E_Stage>((m_newstage + 1)%(int)STAGE_COUNT);


		/*if (m_cont <= STAGE_COUNT) {
			m_cont++;
			m_mapTime = 0;
			m_stage = static_cast<E_Stage>(m_stage + 1);
			m_newstage = static_cast<E_Stage>(m_stage + 1);
		}
		if (m_cont >= STAGE_COUNT) {
			m_stage = static_cast<E_Stage>(m_stage * 0);
			m_newstage = static_cast<E_Stage>(m_newstage * 0 + 1);
			m_cont = 0;
			m_mapTime = 0;


		}*/



	}
	CVector2D m_mapScreen = GetScroal();
	m_mapScreen.x = (int)m_mapScreen.x % MAP_WIDTH;
	if (m_cont == 3) {

	}
	m_backGround[m_newstage]->SetColor(1, 1, 1, m_mapTime);
	m_backGround[m_newstage]->SetPos(0, 0);

	m_backGround[m_stage]->SetColor(1, 1, 1, 1 - m_mapTime);
	m_backGround[m_stage]->SetPos(0, 0);

	//m_mapRight->SetColor(1, 0, 0, 0.5f);
	//	m_mapRight->SetPos(-m_mapScreen.x + MAP_WITHT*i, -m_mapScreen.y);
	//	m_mapRight->Draw();

	m_ground[0]->SetColor(1, 1, 1, 1);
	m_ground[0]->SetPos(-m_mapScreen.x, -m_mapScreen.y);

	m_ground[1]->SetColor(1, 1, 1, 1);
	m_ground[1]->SetPos(-m_mapScreen.x + MAP_WIDTH, -m_mapScreen.y);
}


void  CMap::Draw() {

	//	m_backGround[m_newstage]->SetColor(1, 1, 1, m_mapTime);
	//m_backGround[m_newstage]->SetPos(0, 0);
	//m_backGround[m_newstage]->Draw();
	m_backGround[m_newstage]->Draw();
	m_backGround[m_stage]->Draw();
	for(int i=0;i <MAP_GROUND;i++)
	m_ground[i]->Draw();
	
}


