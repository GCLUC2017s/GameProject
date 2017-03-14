#include "CSceneManager.h"
#include "CCamera.h"
#include "../Scene/Logo/CLogo.h"
#include "../Scene/Title/CTitle.h"
#include "../Scene/CharaSelect/CCharaSelect.h"
#include "../Game/CGame.h"

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

void CSceneManager::ChangeScene()
{	
	//シーン選択
	switch(m_sceneNum)
	{
	case eLogo:
		ChangeScene(eTitle);
		break;
	//現在のシーンがタイトルの場合
	case eTitle:
		ChangeScene(eCharaSelect);
		break;
	//現在のシーンがキャラセレクトの場合
	case eCharaSelect:
		ChangeScene(eGame);
		break;
	//現在のシーンがゲームの場合
	case eGame:
		//if(m_quitFlag = 0) ChangeScene(eResult);
		//else if (m_quitFlag = 1)ChangeScene(eTitle);
		break;
	//シーンが設定されていない場合
	default:
		//タイトルシーンへ
		ChangeScene(eLogo);
		break;
	}
}

void CSceneManager::Update()
{
	if(m_quit) 
	{
		m_quitCnt++;
		if(m_quitCnt > m_quitTime)
		{
			ChangeScene();
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
		break;
	}

	m_quit = false;
	m_quitCnt = 0;
	m_quitTime = 0;
}