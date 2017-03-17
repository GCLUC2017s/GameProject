#include "CGame.h"
#include "CPlayer/CPlayer.h"
#include "../Game/Tutorial/CTutorial.h"
#include "../Game/Map/CMap.h"
#include "../Game/Enemy/CEnemy.h"

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
		break;
	case 1:
		break;
	default:
		break;
	}}
void CGame::Draw()
{
	if (mp_player) {
		CVector3D m_playerPos = mp_player->GetPos();
		CVector2D m_screen = CVector2D(m_playerPos.x - 640, 0);
		if (m_screen.x < 0) m_screen.x = 0;
		if (m_screen.x > 5120) m_screen.x = 5120;
		mp_player->SetScroal(m_screen);

	}
}
