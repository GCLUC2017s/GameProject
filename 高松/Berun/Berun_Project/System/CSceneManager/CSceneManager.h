/**
* @file		CSceneManager.h
* @brief	�V�[���Ǘ��N���X
*
* @author	yuki yamaji
*/

#ifndef SCENEMANAGER_GUARD
#define SCENEMANAGER_GUARD

#include "../CScene/CScene.h"
#include "../CSceneChangeAnimation/CSceneChangeAnimation.h"

enum E_Scene
{
	eSceneTitle,		//�^�C�g���V�[��
	eSceneCharaSelect,	//�L�����Z���N�g�V�[��
	eSceneGame,			//�Q�[���V�[��
	eSceneResult,		//���U���g�V�[��
	eSceneNone,			//�V�[������
};

class CSceneManager
{
private:
	bool m_quit;
	int	 m_quitFlag;
	int  m_quitCnt;
	int  m_quitTime;
	int  m_inCnt;
	int  m_inTime;
	E_Scene m_sceneNum;
	CSceneChangeAnimation m_anim;
	CScene *mp_scene;
	static CSceneManager *mp_sceneManager;
public:
	CSceneManager();
	void ChangeScene();
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

	void Quit(int time)
	{
		m_quit = true;
		m_quitTime = time;
	}

	void SetQuitFlag(int flg) 
	{
		m_quitFlag = flg;
	}

	void ChangeScene(E_Scene scene);
};

#endif