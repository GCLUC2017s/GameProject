#include "CGame.h"
#include "CPlayer/CPlayer.h"
#include "../Game/Tutorial/CTutorial.h"
#include "../Game/Map/CMap.h"
#include "../Game/Enemy/CEnemy.h"
#include "../Game/CollisionA/CCollisionA.h"
#include "../Scene/CSceneManager.h"

CGame::CGame() : mp_player(nullptr),m_step(0)
{
	mp_img[0] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Pos"));
	mp_img[1] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PosGauge"));
	mp_img[2] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Gauge"));
	new CMap(CMap::eStage1);
	mp_tutorial=new CTutorial(g_tutorialDataPath[g_tutorialNo]);
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
	{
		if (mp_tutorial->GetEnd())
		{
			mp_enemy = new CEnemy(eChick);
			mp_player = new CPlayer(g_tutorialNo);
			m_step++;
			mp_tutorial->SetDestroyFlag(true);
			CVector3D p = mp_player->GetPos();
			mp_img[0]->SetPos(285+p.x, 588);
			mp_img[1]->SetPos(285, 625);
			mp_img[2]->SetPos(294, 599);
			mp_img[0]->SetSize(85, 100);
			mp_img[1]->SetSize(690, 90);
			mp_img[2]->SetSize(700, 100);
		}
		break;
	}
	case 1:
	{
		CVector3D p = mp_player->GetPos();
		if (p.x > 1200.0f)
		{
			CSceneManager::GetInstance()->Quit(60, eResult);
			m_step++;
		}
		break;
	}
	case 2:
	default:
		break;
	}
	CTaskManager::GetInstance()->UpdateAll();
	CTaskManager::GetInstance()->DestroyAppoint();
}
void CGame::Draw()
{
	CTaskManager::GetInstance()->DrawAll();
	if (mp_player) {
		CVector3D m_playerPos = mp_player->GetPos();
		CVector2D m_screen = CVector2D(m_playerPos.x - 640, 0);
		if (m_screen.x < 0) m_screen.x = 0;
		if (m_screen.x > 5120) m_screen.x = 5120;
		mp_player->SetScroal(m_screen);

		CCollisionA::CheckHit(mp_player, mp_enemy);
	}

	if (mp_player)
	{
		for (int i = 0; i < IMG_ARRAY; i++)
		{
			mp_img[i]->Draw();
		}
	}
	
}
