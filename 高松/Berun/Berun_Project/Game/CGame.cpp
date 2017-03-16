#include "CGame.h"
#include "CPlayer/CPlayer.h"


CGame::CGame() : m_step(0)
{
	mp_map = new CMap();
	mp_tutorial = new CTutorial(g_tutorialDataPath[g_tutorialNo]);
	
	CSound::GetInstance()->GetSound("AREA_M_BGM")->Play();
}

CGame::~CGame()
{
	CSound::GetInstance()->GetSound("AREA_M_BGM")->Stop();
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
	}
}
void CGame::Draw()
{
	
}
