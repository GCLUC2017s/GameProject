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
	mp_black = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Black"));
	mp_wordGameOver = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("GameOver"));
	new CMap(CMap::eStage1);
	mp_tutorial=new CTutorial(g_tutorialDataPath[g_tutorialNo]);
	m_stopScrol = false;
}

CGame::~CGame()
{
	CTaskManager::GetInstance()->KillAll();
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
			mp_enemy = new CEnemy(eVegetavelboss);
			mp_tutorial->SetKill();
			mp_img[0]->SetPos(280, 310);
			mp_img[0]->SetSize(700, 150);
			m_step++;
		}
		break;
	}
	case 1:
	{
	
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
	CTaskManager::GetInstance()->KillAppoint();
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

		if (m_stopScrol == false) {
			if (m_screen.x < 0) m_screen.x = 0;
			if (m_screen.x > 3840) m_screen.x = 3840;
			mp_player->SetScroal(m_screen);
		}
		m_cnt++;
		for (int i = 1; i < IMG_ARRAY; i++)
		{
			mp_img[i]->Draw();
		}
		
		if (m_cnt < 60)
		{
			mp_img[0]->Draw();
		}
		//死亡フラグが立っていれば、ゲームオーバーの処理
		if (mp_player->GetDeath()) GameOver();
	}
}
void CGame::GameOver()
{
	mp_black->SetColor(HALF_ALPHA);
	mp_wordGameOver->SetPos(300, 300);
	mp_wordGameOver->SetSize(700, 300);
	mp_black->Draw();
	mp_wordGameOver->Draw();
	if(PUSH_KEY_ENTER)		CSceneManager::GetInstance()->Quit(60, eTitle);
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
