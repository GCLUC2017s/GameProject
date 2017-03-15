//シーンのプログラミング（シーンマネージャー）
/*
シーンとシーンマネージャーを合体

現在はまだ動作には干渉させていない。

*/

//担当者　高橋弘樹				動作テスト　未実行
#include "../Scene/CScene.h"
#include "../Title/CTitleScene.h"

CScene* CScene::mScene = 0;

//GetInstance
CScene* CScene::GetInstance() {
	if (mScene == 0) {
		mScene = new CScene();
	}
	return mScene;
}

//KILL処理
void CScene::DeleteScene(){
	if	  (mScene)
	delete mScene;
	mScene = 0;
}

void CScene::ChangeScene(eSceneNo SceneNo) {

	DeleteScene();		//KILL

	switch (SceneNo) {

		//タイトルの呼び出しを行う
	case E_TITLE:
		mScene = new CTitleScene;

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
/*
作動用

	//初期シーンの指定
	CScene::GetInstance()->ChangeScene(CScene::E_TITLE);

	//シーンのアップデート
	CScene::GetInstance()->Update();

	//シーンのデリート
	CScene::GetInstance()->DeleteScene();



*/