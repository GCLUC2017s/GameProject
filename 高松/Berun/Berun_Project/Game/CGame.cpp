#include "CGame.h"
#include "CPlayer/CPlayer.h"


CGame::CGame()
{
	new CMap();
	new CTutorial(g_tutorialDataPath[g_tutorialNo]);
	new CPlayer(ePlayerMan);
	new CEnemy(eCarrot);
	CSound::GetInstance()->GetSound("AREA_M_BGM")->Play();
}

CGame::~CGame()
{
	CSound::GetInstance()->GetSound("AREA_M_BGM")->Stop();
}
void CGame::Update()
{
	/*
	if (mp_tuto->GetEnd())
	{

	}
	*/
}
void CGame::Draw()
{
	
}
/*
CPlayer CGame::GetPlayer(int type)
{
	
	CPlayer mp_player = new CPlayer(type);

	return mp_player;
}

CEnemy CGame::GetEnemy(int type)
{
	CEnemy mp_enemy = new CEnemy(type);

	return mp_enemy;
}
*/
CTutorial CGame::GetTutorial()
{
	CTutorial mp_tuto = CTutorial();
	return mp_tuto;
}
