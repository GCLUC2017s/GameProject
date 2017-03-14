/**
* @file		CSceneManager.h
* @brief	シーン管理クラス
*
* @author	yuki yamaji
*/

#ifndef SCENEMANAGER_GUARD
#define SCENEMANAGER_GUARD

#include "CScene.h"
#include "CSceneChangeAnimation.h"

enum E_Scene
{
	eLogo,			//ロゴシーン
	eTitle,			//タイトルシーン
	eCharaSelect,	//キャラセレクトシーン
	eGame,			//ゲームシーン
	eResult,		//リザルトシーン
	eNone,			//シーン無し
};

class CSceneManager
{
private:
	bool m_quit;        //シーン切り替えフラグ
	int	 m_quitFlag;	//シーン切り替え分岐フラグ
	int  m_quitCnt;		//シーンアウトタイミング
	int  m_quitTime;	
	int  m_inCnt;		//シーンインタイミング
	int  m_inTime;		
	E_Scene m_sceneNum;
	CSceneChangeAnimation m_anim;
	CScene *mp_scene;
	static CSceneManager *mp_sceneManager;
public:
	CSceneManager();
	void ChangeScene();
	virtual void Update();
	virtual void Draw();

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