#include "CGame.h"
#include "CPlayer/CPlayer.h"


CGame::CGame() : m_step(0)
{

new CMap(CMap::eStage2);
	new CTutorial(g_tutorialDataPath[g_tutorialNo]);
	new CPlayer(ePlayerMan);
	new CEnemy(eCarrot);}

CGame::~CGame()
{
}
void CGame::Update() 
{
switch (m_step)
	{
	case 0:
		if (mp_tutorial->GetEnd())
		{
			new CPlayer(g_tutorialNo);
			new CEnemy(eCarrot);
			m_step++;
			mp_tutorial->SetDestroyFlag(true);
		}
	case 1:

	default:
		break;
	}}
void CGame::Draw()
{


}
