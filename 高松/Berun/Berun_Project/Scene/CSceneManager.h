/**
* @file		CSceneManager.h
* @brief	シーン管理クラス
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
	//シーン切り替え（時間、次のシーン）
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