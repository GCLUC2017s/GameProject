#include "CGame.h"
#include "CPlayer/CPlayer.h"
#include "../Game/Tutorial/CTutorial.h"
#include "../Game/Map/CMap.h"
#include "../Game/Enemy/CEnemy.h"
#include "../Game/CollisionManager/CollisionManager.h"
#include "../Scene/CSceneManager.h"
#include"../Game/Enemy/CEnemyManager.h"

CGame* CGame::mp_game = nullptr;

CGame::CGame() : mp_player(nullptr),m_step(0),m_cnt(0)
{
	mp_img[0] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("GameStart"));
	mp_img[1] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Pos"));
	mp_img[2] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PosGauge"));
	mp_img[3] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Gauge"));
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
	{
		if (mp_tutorial->GetEnd())
		{	
			mp_player = new CPlayer(g_tutorialNo);
			new CEnemyManager();
			mp_enemy = new CEnemy(eChick);
			mp_tutorial->SetDestroyFlag(true);
			m_step++;
		}
		break;
	}
	case 1:
	{
		m_cnt++;
		CVector3D p = mp_player->GetPos();
		if (p.x > GOAL_POS)
		{
			CSceneManager::GetInstance()->Quit(60, eResult);
		}
		break;
	}
	default:
		break;
	}
	CCollisionManager::GetInstance()->UnRegistAll();
	CTaskManager::GetInstance()->DestroyAppoint();
	CTaskManager::GetInstance()->UpdateAll();
	CCollisionManager::GetInstance()->CheckHitAll();
}
void CGame::Draw()
{
	CTaskManager::GetInstance()->DrawAll();
	if (mp_player)
	{
		CVector3D m_playerPos = mp_player->GetPos();
		CVector2D m_screen = CVector2D(m_playerPos.x - 640, 0);
		float pos = m_playerPos.x / GOAL_POS;
		if(m_playerPos.x > 70 && m_playerPos.x < GOAL_POS) mp_img[1]->SetPos(pos * 650 + 250, 588);
		mp_img[2]->SetPos(280, 625);
		mp_img[3]->SetPos(294, 599);
		mp_img[1]->SetSize(85, 100);
		mp_img[2]->SetSize(700, 90);
		mp_img[3]->SetSize(700, 100);
		if (m_screen.x < 0) m_screen.x = 0;
		if (m_screen.x > 5120) m_screen.x = 5120;
		mp_player->SetScroal(m_screen);
		for (int i = 1; i < IMG_ARRAY; i++)
		{
			mp_img[i]->Draw();
		}
		
		if (mp_tutorial->GetEnd() && m_cnt < 60)
		{
			mp_img[0]->SetPos(280,310);
			mp_img[0]->SetSize(700, 150);
			mp_img[0]->Draw();
		}
	}
}

CGame * CGame::GetInstance()
{
	if (mp_game == nullptr)
	{
		mp_game = new CGame();
	}

	return mp_game;
}

void CGame::ClearInstance()
{
	if (mp_game != nullptr) delete mp_game;
}
