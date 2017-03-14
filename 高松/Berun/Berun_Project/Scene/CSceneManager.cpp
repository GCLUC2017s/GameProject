#include "CSceneManager.h"

CSceneManager* CSceneManager::mp_sceneManager = nullptr;

CSceneManager::CSceneManager() :  
	m_quit(false),
	m_quitCnt(0),
	m_quitTime(0),
	m_inCnt(0),
	m_inTime(0),
	m_sceneNum(eNone),
	mp_scene(nullptr)
{
	ChangeScene();
}


void CSceneManager::Update()
{
	if(m_quit) 
	{
		m_quitCnt++;
		if(m_quitCnt > m_quitTime)
		{
			ChangeScene(m_nextNum);
		}
	}
	//シーン更新処理
	mp_scene->Update();
	CTaskManager::GetInstance()->UpdateAll();
	CTaskManager::GetInstance()->DestroyAppoint();
}

void CSceneManager::Draw()
{
	//シーン更新描画
	mp_scene->Draw();

	CTaskManager::GetInstance()->DrawAll();

	if(m_quit)
	{
		//シーンアウト
		m_anim.Draw((float)m_quitCnt / m_quitTime);
	}
	else 
	{
		//シーンイン
		if(m_inCnt < m_inTime) 
		{
			m_inCnt++;
			m_anim.Draw(1.0 - (float)m_inCnt / m_inTime);
		}
	}

}

void CSceneManager::ChangeScene(E_Scene scene)
{
	if(mp_scene) 
	{
		m_inTime = m_quitTime;
		delete mp_scene;
	}
	else 
	{
		m_inTime = 0;
	}

	m_sceneNum = scene;

	switch(m_sceneNum)
	{
	case eTest:
		mp_scene = new CTest();
		break;
	case eLogo:
		mp_scene = new CLogo();
		break;
	case eTitle:
		mp_scene = new CTitle();
		break;
	case eCharaSelect:
		mp_scene = new CCharaSelect();
		break;
	case eGame:
		mp_scene = new CGame();
		break;
		/*
	case eResult:
		mp_scene = new CResult();
		break;
		*/
	default:
		//デバッグ
		assert(false);
		break;
	}

	m_quit = false;
	m_quitCnt = 0;
	m_quitTime = 0;
}