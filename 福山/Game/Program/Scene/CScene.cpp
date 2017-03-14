//シーンのプログラミング（シーンマネージャー）
//担当者　高橋弘樹				動作テスト　未実行
#include "../Scene/CScene.h"
#include "../Title/CTitleScene.h"

CScene *m_currScene;

CScene *CScene::mScene = new CScene();

void CScene::ChangeScene(eSceneNo no)
{
	mNextStatus = no;
}

void CScene::Update() {

	delete(m_currScene);

	switch (mNextStatus) {

		//タイトルの呼び出しを行う
	case E_TITLE:
		m_currScene = new CTitleScene;


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
