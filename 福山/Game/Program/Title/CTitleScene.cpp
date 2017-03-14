//タイトルのプログラミング
//担当者　高橋弘樹
#include "CTitleScene.h"
#include "../Key/CKey.h"
#include"../Map/CMap.h"

//CScene eSceneNo TITLE

//CTitleScene::CTitleScene(){}

void CTitleScene::Init() {


	FirstX = -MAP_LIMIT_X / 2.5;
	mMap.Init();
	mTitle.Init();
	
	mFade.SetVertex(
		-MAP_LIMIT_X / 2.0,
	     MAP_LIMIT_Y / 2.0,
		 MAP_LIMIT_X / 2.0,
		-MAP_LIMIT_Y / 2.0);
	//黒色に設定
	mFade.SetColor(1.0f, 1.0f, 1.0f, alpha=1.0f);

	//画面の座標系を設定
	glMatrixMode(GL_PROJECTION);	//行列をプロジェクションモードへ変更
	glLoadIdentity();	//行列を初期化
	//	gluOrtho2D(-CGame::mDispCols / 2.0, CGame::mDispCols / 2.0, -CGame::mDispRows / 2.0, CGame::mDispRows / 2.0);
	//表示するエリアを指定
	gluOrtho2D(
		-MAP_LIMIT_X / 2.5,
		MAP_LIMIT_X / 2.5,
		-MAP_LIMIT_Y / 2.0,
		MAP_LIMIT_Y / 2.0);




}

void CTitleScene::Update() {

	//Updateする

	mMap.Update();
	mMap.Render();

	
	mTitle.Render((CVector2(MAP_LIMIT_X / 3.0 + FirstX,
	MAP_LIMIT_X / 2.0 + FirstX - 5.0f)));




	FirstX += 0.02f;



	glMatrixMode(GL_PROJECTION);	//行列をプロジェクションモードへ変更
	glLoadIdentity();	//行列を初期化
	gluOrtho2D(
		-MAP_LIMIT_X / 1.0 + FirstX,
		MAP_LIMIT_X / 1.0 + FirstX,
		-MAP_LIMIT_Y / 1.5,
		MAP_LIMIT_Y / 1.5);


	if (FirstX > MAP_LIMIT_X / 2.5){
	//	alpha = 1.0f;
		FirstX = -MAP_LIMIT_X / 2.5;
	} //マップの端まで行くと最初に戻す。

	//Update終了


	//エンターキーを押したときにシーンをセレクト画面に替える処理を行う。
	if (CKey::push(VK_RETURN)) 
	{
	}


}