#include "CSceneManager.h"
#include "Logo/CLogo.h"
#include "Title/CTitle.h"
#include "CharaSelect/CCharaSelect.h"
#include "../Game/CGame.h"
#include "Result/CResult.h" 

CSceneManager* CSceneManager::mp_sceneManager = nullptr;

CSceneManager::CSceneManager() :  
	m_quit(false),
	m_quitCnt(0),
	m_quitTime(0),
	m_inCnt(0),
	m_inTime(0),
	m_sceneNum(eNone),
	m_nextNum(eNone),
	mp_scene(nullptr)
{
	ChangeScene(eLogo);
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
}

void CSceneManager::Draw()
{
	//シーン更新描画
	mp_scene->Draw();

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
			m_anim.Draw(1.0f - (float)m_inCnt / m_inTime);
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
	case eLogo:
		mp_scene = new CLogo();
		break;
	case eTitle:
		CSound::GetInstance()->GetSound("RESULT_BGM")->Stop();
		mp_scene = new CTitle();
		CSound::GetInstance()->GetSound("TITLE_BGM")->Play(true);
		break;
	case eCharaSelect:
		CSound::GetInstance()->GetSound("TITLE_BGM")->Stop();
		mp_scene = new CCharaSelect();
		CSound::GetInstance()->GetSound("CHARASELECT_BGM")->Play(true);
		break;
	case eGame:
		CSound::GetInstance()->GetSound("CHARASELECT_BGM")->Stop();
		mp_scene = new CGame();
		CSound::GetInstance()->GetSound("AREA_M_BGM")->Play(true);
		break;
	case eResult:
		CSound::GetInstance()->GetSound("AREA_M_BGM")->Stop();
		mp_scene = new CResult();
		CSound::GetInstance()->GetSound("RESULT_BGM")->Play(true);
		break;
	default:
		//デバッグ
		assert(false);
		break;
	}

	m_quit = false;
	m_quitCnt = 0;
	m_quitTime = 0;
}