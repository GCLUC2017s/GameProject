#include "CGame.h"
#include "CPlayer/CPlayer.h"


CGame::CGame()
{

	new CMap();
	new CTutorial(g_tutorialDataPath[g_tutorialNo]);
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
CPlayer CGame::GetPlayer(int type)
{
	
	m_player = new CPlayer(type);

	return m_player;
}

CEnemy CGame::GetEnemy(int type)
{
	m_enemy = new CEnemy(type);

	return m_enemy;
}

*/
