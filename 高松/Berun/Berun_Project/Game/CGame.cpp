#include "CGame.h"
#include "CPlayer/CPlayer.h"


CGame::CGame() : mp_player(nullptr),m_step(0)
{

	new CMap(CMap::eStage1);
	mp_tutorial=new CTutorial(g_tutorialDataPath[g_tutorialNo]);
	
}

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
			mp_player=new CPlayer(g_tutorialNo);
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
	if (mp_player) {
		CVector3D m_playerPos = mp_player->GetPos();
		CVector2D m_screen = CVector2D(m_playerPos.x - 640, 0);
		if (m_screen.x < 0) m_screen.x = 0;
		if (m_screen.x > 2400) m_screen.x = 2400;
		mp_player->SetScroal(m_screen);

	}
}
