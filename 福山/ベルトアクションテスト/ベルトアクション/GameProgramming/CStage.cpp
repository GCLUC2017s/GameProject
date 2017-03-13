#include "CStage.h"
#include "CGame.h"
#include "CKey.h"



CStage::CStage() :status(0),Alerttop(0.0f),Alertbottom(0.0f),Alertenabled(true){}

void CStage::init() {

	CGame::mMapCols = MAP_COLS;		//マップサイズの設定（列数）
	CGame::mMapRows = MAP_ROWS;		//マップサイズの設定（行数）
//	CGame::mDispCols = 30;
//	CGame::mDispRows = 30;


		CGame::mDispCols = 640*0.012;	//表示エリアのサイズ設定（列数）
		CGame::mDispRows = 480*0.012;	//表示エリアのサイズ設定（行数）


	mPlayer.init();
	mPlayer.setPos();
	mEnemy00.init();
	mEnemy00.setPos();

	map.init();
	title.init();


	status = 0;
	FirstX = -MAP_LIMIT_X / 2.5;

	//enemy.mpPlayer = &player;
	//sasori.init();	//サソリの初期化
	//sasori.setPos(4, 9, CVector2(0.0f, 1.0f));	//サソリの配置


	//プレイヤーの配置


	mAlertCnt = 0;		//アラート制御カウンタを初期化
	mAlertLevel = 0;	//アラートレベル設定
	//アラート表示の大きさをマップ全体に設定
	mAlert.setVertex(
		-CGame::mMapCols / 2.0,
		Alerttop,
		CGame::mMapCols / 2.0,
		Alertbottom);
	//半透明の赤色に設定
	mAlert.setColor(1.0f, 0.0f, 0.0f, 0.5f);

	//画面の座標系を設定
	glMatrixMode(GL_PROJECTION);	//行列をプロジェクションモードへ変更
	glLoadIdentity();	//行列を初期化
//	gluOrtho2D(-CGame::mDispCols / 2.0, CGame::mDispCols / 2.0, -CGame::mDispRows / 2.0, CGame::mDispRows / 2.0);
	//表示するエリアを指定
	gluOrtho2D(
		-CGame::mDispCols / 2.5+mPlayer.mPos.x,
		CGame::mDispCols / 2.5 + mPlayer.mPos.x,
		-CGame::mDispRows / 2.0 ,
		CGame::mDispRows / 2.0 );
		
}

void CStage::update() {

	//enemy.update();
	//sasori.update();
	map.update();
	mPlayer.update();
	mEnemy00.update();

	map.render();

	mPlayer.m_Player.position = mPlayer.mPos;
	mPlayer.render();

	mEnemy00.m_Enemy00.position = mEnemy00.mPos;
	mEnemy00.render();


	if (CKey::push(VK_RETURN)) {
	
		mEnemy00.init();
		mEnemy00.update();
		mEnemy00.setPos();
		mEnemy00.m_Enemy00.position = mEnemy00.mPos;
		mEnemy00.render();

	}


			//表示するエリアを指定
			gluOrtho2D(
				-CGame::mDispCols / 2.0 + Save,
				CGame::mDispCols / 2.0 + Save,
				-CGame::mDispRows / 2.5,
				CGame::mDispRows / 2.5);

			//画面の座標系を設定
			glMatrixMode(GL_PROJECTION);	//行列をプロジェクションモードへ変更
			glLoadIdentity();	//行列を初期化
			//	gluOrtho2D(-CGame::mDispCols / 2.0, CGame::mDispCols / 2.0, -CGame::mDispRows / 2.0, CGame::mDispRows / 2.0);
			const float camera_x = CGame::mDispCols;
			const float camera_y = CGame::mDispRows;
			const float area_x = MAP_LIMIT_X / 2;
			//表示するエリアを指定
			if (-area_x <= -camera_x + mPlayer.mPos.x+2 &&
				area_x >= camera_x + mPlayer.mPos.x+2){

				save_player_x = mPlayer.mPos.x+2;

				gluOrtho2D(
					-camera_x + mPlayer.mPos.x+2,
					camera_x + mPlayer.mPos.x+2,
					-camera_y,
					camera_y);
			}
			else{
				gluOrtho2D(
					-camera_x + save_player_x,
					camera_x + save_player_x,
					-camera_y,
					camera_y);
			}

		}



	/*
	//画面の座標系を設定
	glMatrixMode(GL_PROJECTION);	//行列をプロジェクションモードへ変更
	glLoadIdentity();	//行列を初期化
	//	gluOrtho2D(-CGame::mDispCols / 2.0, CGame::mDispCols / 2.0, -CGame::mDispRows / 2.0, CGame::mDispRows / 2.0);
    const float camera_x = CGame::mDispCols;
	const float camera_y = CGame::mDispRows;
	const float area_x = MAP_LIMIT_X / 2;
	//表示するエリアを指定
	if (-area_x <=  -camera_x+player.mPos.x &&
	     area_x >= camera_x + player.mPos.x){

		save_player_x = player.mPos.x;

		gluOrtho2D(
			-camera_x + player.mPos.x,
			camera_x + player.mPos.x,
			-camera_y,
			camera_y);
	}
	else{
		gluOrtho2D(
			-camera_x + save_player_x,
			camera_x +  save_player_x ,
			-camera_y,
			camera_y);
	}
	*/




/* alertDisp
追跡モードの時には、画面に赤みを付ける
*/
void CStage::alertDisp() {

}
