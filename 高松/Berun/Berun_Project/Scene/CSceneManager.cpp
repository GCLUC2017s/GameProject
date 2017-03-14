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
	//�V�[���I��
	switch(m_sceneNum)
	{
	case eLogo:
		ChangeScene(eTitle);
		break;
	//���݂̃V�[�����^�C�g���̏ꍇ
	case eTitle:
		ChangeScene(eCharaSelect);
		break;
	//���݂̃V�[�����L�����Z���N�g�̏ꍇ
	case eCharaSelect:
		ChangeScene(eGame);
		break;
	//���݂̃V�[�����Q�[���̏ꍇ
	case eGame:
		//if(m_quitFlag = 0) ChangeScene(eResult);
		//else if (m_quitFlag = 1)ChangeScene(eTitle);
		break;
	//�V�[�����ݒ肳��Ă��Ȃ��ꍇ
	default:
		//�^�C�g���V�[����
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