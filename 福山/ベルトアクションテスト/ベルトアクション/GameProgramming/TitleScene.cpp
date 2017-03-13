#include "TitleScene.h"
#include "CGame.h"
#include "CKey.h"


//未解決

//最初の読み込みが不自然


TitleScene::TitleScene() :status(0), Alerttop(0.0f), Alertbottom(0.0f), Alertenabled(true){}

void TitleScene::init() {

	CGame::mMapCols = MAP_COLS;		//マップサイズの設定（列数）
	CGame::mMapRows = MAP_ROWS;		//マップサイズの設定（行数）
	//	CGame::mDispCols = 30;
	//	CGame::mDispRows = 30;


	CGame::mDispCols = 640 * 0.012;	//表示エリアのサイズ設定（列数）
	CGame::mDispRows = 480 * 0.012;	//表示エリアのサイズ設定（行数）


	mPlayer.init();
	mPlayer.setPos();
	map.init();
	title.init();




	status = 0;
	FirstX = -MAP_LIMIT_X / 2.5;
	count = mPlayer.mPos.y;


	mAlertCnt = 0;		//アラート制御カウンタを初期化
	mAlertLevel = 0;	//アラートレベル設定
	//アラート表示の大きさをマップ全体に設定
	mFade.setVertex(
		-CGame::mMapCols / 2.0,
		CGame::mMapRows / 2.0,
		CGame::mMapCols / 2.0,
		-CGame::mMapRows / 2.0);
	//黒色に設定
	mFade.setColor(1.0f, 1.0f, 1.0f, 1.0f);

	//画面の座標系を設定
	glMatrixMode(GL_PROJECTION);	//行列をプロジェクションモードへ変更
	glLoadIdentity();	//行列を初期化
	//	gluOrtho2D(-CGame::mDispCols / 2.0, CGame::mDispCols / 2.0, -CGame::mDispRows / 2.0, CGame::mDispRows / 2.0);
	//表示するエリアを指定
	gluOrtho2D(
		-CGame::mDispCols / 2.5 + mPlayer.mPos.x,
		CGame::mDispCols / 2.5 + mPlayer.mPos.x,
		-CGame::mDispRows / 2.0,
		CGame::mDispRows / 2.0);

}

void TitleScene::update() {


	//enemy.update();
	//sasori.update();
	map.update();
	mPlayer.update();
	map.render();

	title.render((CVector2(CGame::mDispCols / 3.0 + FirstX,
		CGame::mDispCols / 2.0 + FirstX - 5.0f)));


	//mPlayer.player.position = mPlayer.mPos;
	//mPlayer.render();

		FirstX += 0.02f;
		//画面の座標系を設定
		glMatrixMode(GL_PROJECTION);	//行列をプロジェクションモードへ変更
		glLoadIdentity();	//行列を初期化
			//表示するエリアを指定
			gluOrtho2D(
				-CGame::mDispCols / 1.0 + FirstX,
				CGame::mDispCols / 1.0 + FirstX,
				-CGame::mDispRows / 1.5,
				CGame::mDispRows / 1.5);

			if (FirstX > MAP_LIMIT_X / 2.5){ 
		
				FirstX = -MAP_LIMIT_X / 2.5;

			} //ゴールまでスクロールでゲームに戻る
		
}



/* alertDisp
追跡モードの時には、画面に赤みを付ける
*/
void TitleScene::FadeDisp() {

	mFade.render();

}