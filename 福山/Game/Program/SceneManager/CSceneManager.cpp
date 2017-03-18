//シーンのプログラミング（シーンマネージャー）
/*
シーンとシーンマネージャーを合体

現在はまだ動作には干渉させていない。

シーンマネージャーとシーンに分離予定

*/

//担当者　高橋弘樹				動作テスト　未実行
#include "../Scene/CScene.h"
#include "../Title/CTitleScene.h"
#include"CSceneManager.h"
#include "../GameMain/CGameMain.h"
#include "../Key/CKey.h"

CSceneManager* CSceneManager::mSceneManager = 0;

CScene* mScene=0;

//GetInstance
CSceneManager* CSceneManager::GetInstance() {
	if (mSceneManager == 0) {
		mSceneManager = new CSceneManager();
	}
	return mSceneManager;
}

//KILL処理
void CSceneManager::DeleteScene(){
	if (mScene)
		delete mScene;
	mScene = 0;
}

void CSceneManager::ChangeScene(eSceneNo SceneNo) {

	DeleteScene();		//KILL

	switch (SceneNo) {

		//タイトルの呼び出しを行う
	case eSceneNo::E_TITLE:
		mScene = new CTitleScene;
		mScene->Init();

		break;
		//セレクト画面の呼び出しを行う

	case eSceneNo::E_SELECT:
		//ゲーム画面に飛ばします


		break;
		//ゲームメインの呼び出しを行う

	case eSceneNo::E_GAMEMAIN:
		mScene = new CGameMain;
		

		break;
		//ゲームクリア画面の呼び出しを行う

	case eSceneNo::E_GAMECLEAR:

		break;
		//ゲームオーバー画面の呼び出しを行う

	case eSceneNo::E_GAMEOVER:

		break;


	};
}

void CSceneManager::SceneMain(){
	switch (status)
	{
	case 0:

		CSceneManager::GetInstance()->ChangeScene(eSceneNo::E_TITLE);

		status = 1;
		break;
	case 1:

		mScene->Update();

		break;
	}

}

/*
作動用

//初期シーンの指定
CScene::GetInstance()->ChangeScene(CScene::E_TITLE);

//シーンのアップデート
CScene::GetInstance()->Update();

//シーンのデリート
CScene::GetInstance()->DeleteScene();



*/