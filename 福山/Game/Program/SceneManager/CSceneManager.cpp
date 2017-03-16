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

CSceneManager* CSceneManager::mSceneManager = 0;

//GetInstance
CSceneManager* CSceneManager::GetInstance() {
	if (mSceneManager == 0) {
		mSceneManager = new CSceneManager();
	}
	return mSceneManager;
}

//KILL処理
void CSceneManager::DeleteScene(){
	if (mSceneManager)
		delete mSceneManager;
	mSceneManager = 0;
}

void CSceneManager::ChangeScene(eSceneNo SceneNo) {

	DeleteScene();		//KILL

	switch (SceneNo) {

		//タイトルの呼び出しを行う
	case E_TITLE:
		mSceneManager = new CTitleScene;

		break;
		//セレクト画面の呼び出しを行う

	case E_SELECT:
		//ゲーム画面に飛ばします


		break;
		//ゲームメインの呼び出しを行う

	case E_GAMEMAIN:

		break;
		//ゲームクリア画面の呼び出しを行う

	case E_GAMECLEAR:

		break;
		//ゲームオーバー画面の呼び出しを行う

	case E_GAMEOVER:

		break;


	};
}

void CSceneManager::SceneMain(){

	CSceneManager::GetInstance()->ChangeScene(CScene::E_TITLE);
	for (int i = 0; i < 10; i++) {
		CSceneManager::GetInstance()->Update();
		CSceneManager::GetInstance()->Update();
	}
	CSceneManager::GetInstance()->DeleteScene();


	getchar();

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