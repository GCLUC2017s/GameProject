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
	//�V�[���I��
	switch(m_sceneNum)
	{
	//���݂̃V�[�����^�C�g���̏ꍇ
	case eSceneTitle:
		ChangeScene(eSceneCharaSelect);
		break;
	//���݂̃V�[�����L�����Z���N�g�̏ꍇ
	case eSceneCharaSelect:
		ChangeScene(eSceneGame);
		break;
	//���݂̃V�[�����Q�[���̏ꍇ
	case eSceneGame:
		ChangeScene(eSceneResult);
		//ChangeScene(eSceneTitle);
		break;
	//�V�[�����ݒ肳��Ă��Ȃ��ꍇ
	default:
		//�^�C�g���V�[����
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
	//�V�[���X�V����
	mp_scene->Update();
}

void CSceneManager::Draw()
{
	//�V�[���X�V�`��
	mp_scene->Draw();

	if(m_quit)
	{
		//�V�[���A�E�g
		m_anim.Draw((float)m_quitCnt / m_quitTime);
	}
	else 
	{
		//�V�[���C��
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