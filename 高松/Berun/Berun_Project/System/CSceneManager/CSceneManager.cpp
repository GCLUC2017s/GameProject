#include "CSceneManager.h"
#include "CCamera.h"

CSceneManager* CSceneManager::mp_sceneManager = nullptr;

CSceneManager::CSceneManager() :  
	m_quit(false),
	m_quitCnt(0),
	m_quitTime(0),
	m_inCnt(0),
	m_inTime(0),
	m_sceneNum(eSceneNone),
	mp_scene(nullptr)
{
	ChangeScene();
}

void CSceneManager::ChangeScene()
{	
	//シーン選択
	switch(m_sceneNum)
	{
	//現在のシーンがタイトルの場合
	case eSceneTitle:
		ChangeScene(eSceneCharaSelect);
		break;
	//現在のシーンがキャラセレクトの場合
	case eSceneCharaSelect:
		ChangeScene(eSceneGame);
		break;
	//現在のシーンがゲームの場合
	case eSceneGame:
		ChangeScene(eSceneResult);
		//ChangeScene(eSceneTitle);
		break;
	//シーンが設定されていない場合
	default:
		//タイトルシーンへ
		ChangeScene(eSceneTitle);
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

	/*
	switch(m_sceneNum)
	{
	case eSceneTitle:
		p_scene = new CTitle();
		break;
	case eSceneGame:
		p_scene = new CGame();
		break;
	case eSceneScenario:
		p_scene = new CScenario();
		break;
	default:
		break;
	}
	*/

	m_quit = false;
	m_quitCnt = 0;
	m_quitTime = 0;
}