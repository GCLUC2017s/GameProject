//タイトルのプログラミング
//担当者　高橋弘樹
#include "CTitleScene.h"
#include "../Key/CKey.h"
#include"../Map/CMap.h"
#include "../Player/CPlayer.h"

//CScene eSceneNo TITLE

//CTitleScene::CTitleScene(){}

void CTitleScene::Init() {


	FirstX = first_pos.x;
	mMap.Init();
	mTitle.Init();

}

void CTitleScene::Update() {

	//Updateする

	mMap.Update();
	mMap.Render();

	
	mTitle.Render(CVector2(FirstX,0));

	FirstX += 0.02f;



	glMatrixMode(GL_PROJECTION);	//行列をプロジェクションモードへ変更
	glLoadIdentity();	//行列を初期化
	gluOrtho2D(-DISP_X+ FirstX,DISP_X  + FirstX,-DISP_Y ,DISP_Y);


	if (FirstX > DISP_X / 2.0){
	//	alpha = 1.0f;
		FirstX = first_pos.x;
	} //マップの端まで行くと最初に戻す。

	//Update終了


	//エンターキーを押したときにシーンをセレクト画面に替える処理を行う。
	if (CKey::push(VK_RETURN)) 
	{
		CSceneManager::GetInstance()->ChangeScene(eSceneNo::E_GAMEMAIN);
	}


}