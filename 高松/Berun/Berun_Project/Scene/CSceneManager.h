/**
* @file		CSceneManager.h
* @brief	�V�[���Ǘ��N���X
* @author	yuki yamaji
*/

#ifndef SCENEMANAGER_GUARD
#define SCENEMANAGER_GUARD

#include "CScene.h"
#include "CSceneChangeAnimation.h"

enum E_Scene
{
	eLogo,			//���S�V�[��
	eTitle,			//�^�C�g���V�[��
	eCharaSelect,	//�L�����Z���N�g�V�[��
	eGame,			//�Q�[���V�[��
	eResult,		//���U���g�V�[��
	eNone,			//�V�[������
};

class CSceneManager
{
private:
	bool m_quit;        //�V�[���؂�ւ��t���O
	int	 m_quitFlag;	//�V�[���؂�ւ�����t���O
	int  m_quitCnt;		//�V�[���A�E�g�^�C�~���O
	int  m_quitTime;	
	int  m_inCnt;		//�V�[���C���^�C�~���O
	int  m_inTime;		
	E_Scene m_sceneNum;
	E_Scene m_nextNum;
	CSceneChangeAnimation m_anim;
	CScene *mp_scene;
	static CSceneManager *mp_sceneManager;
public:
	CSceneManager();
	void Update();
	void Draw();

	static CSceneManager *GetInstance()
	{
		if(!mp_sceneManager) 
		{
			mp_sceneManager = new CSceneManager();
		}
		return mp_sceneManager;
	}
	//�V�[���؂�ւ��i���ԁA���̃V�[���j
	void Quit(int time, E_Scene scene)
	{
		m_quit = true;
		m_quitTime = time;
		m_nextNum = scene;
	}

	void SetQuitFlag(int flg) 
	{
		m_quitFlag = flg;
	}

	void ChangeScene(E_Scene scene);
};

#endif