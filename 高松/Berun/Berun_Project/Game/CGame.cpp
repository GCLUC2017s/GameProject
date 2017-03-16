#include "CGame.h"
#include "CPlayer/CPlayer.h"


CGame::CGame()
{

	new CMap();
	new CTutorial(g_tutorialDataPath[g_tutorialNo]);
	new CPlayer(ePlayerMan);
	//new CEnemy(eCarrot);
}

CGame::~CGame()
{
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
