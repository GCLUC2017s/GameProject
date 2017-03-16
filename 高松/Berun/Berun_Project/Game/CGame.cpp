#include "CGame.h"
#include "CPlayer/CPlayer.h"


CGame::CGame()
{

	new CMap();
	//new CTutorial(g_tutorialDataPath[g_tutorialNo]);
	//new CPlayer(ePlayerMan);
	//new CEnemy(eCarrot);
	CSound::GetInstance()->GetSound("AREA_M_BGM")->Play();
}

CGame::~CGame()
{
	CSound::GetInstance()->GetSound("AREA_M_BGM")->Stop();
}
void CGame::Update()
{
}
void CGame::Draw()
{
	
}
/*
CPlayer CGame::GetPlayer()
{
	
	m_player = new CPlayer();

	return m_player;
}

CPlayer CGame::GetEnemy()
{
	m_enemy = new CEnemy();

	return m_enemy;
}

CPlayer CGame::GetMap()
{
	m_map = new CMap();

	return m_map;
}
*/
