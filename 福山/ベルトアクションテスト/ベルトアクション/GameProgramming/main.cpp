#include "define.h"
#include "glut.h"
#define _USE_MATH_DEFINES	//数学ライブラリのM_PIを有効にする
#include <math.h>	//数学ライブラリのインクルード
#include <stdio.h>
#include "CStage.h"
#include "CKey.h"
#include "CGame.h"
#include "CGameclear.h"
#include "CGameover.h"
#include "Title.h"
#include "TitleScene.h"

/*

	GameTitle及びResult等の扱いについて。

	GameTitleはGame画面の背景を進行方向Scrollした状態で描画する。
	その要領でゲームセレクトも描画する。
	Result、GameOverも同様にゲーム画面を後ろに描画した状態で描画する。
	アラド戦記のResultと似た要領。


	stageの背景がループするやつでもつくるか。

*/


class CScene{
public:

	CStage stage;
	CGameclear clear;
	Title title;
	TitleScene titlescene;
	CGameover out;


	//	int state;

	//	CScene() : state(0) {}
	CScene() {}


	//Main Routine

	void loop() {
		switch (CGame::status) {
			//タイトルの呼び出しを行う
		case 0:
			titlescene.init();
			CGame::status = 1;
			break;
		case 1:
			titlescene.update();
			if (CKey::push(VK_RETURN)){		//returnキーを押すとゲーム開始。
				CGame::status = 2;
			}
			break;

			//ステージの呼び出しを行う
		case 2:
			stage.init();
			CGame::status = 3;
			break;
		case 3:
			stage.update();
			break;

			//ゲームオーバー画面の呼び出しを行う
		case 4:
			out.init();
			CGame::status = 5;
			break;
		case 5:
			out.update();
			if (CKey::once(VK_RETURN)){		//returnキーを押すとタイトルに戻る。
				CGame::status = 0;
			}
			break;

			//リザルト画面の呼び出し（clear）を行う
		case 6:
			clear.init();
			CGame::status = 7;
			break;
		case 7:
			clear.update();
			if (CKey::once(VK_RETURN)){		//returnキーを押すと戻る。
				CGame::status = 8;
			}

			break;
		case 8:
		

			break;
		case 9:
		


			break;

		};

	}

	void init() {
	}

	void update() {


	}
};
CScene Scene;


/* display関数
1秒間に60回実行される
*/
void display() {
	//画面のクリア
	glClear(GL_COLOR_BUFFER_BIT);
	Scene.loop();
	//画面に表示
	glutSwapBuffers();
}

//関数のプロトタイプ宣言
void reshape(int, int);
void idle();

void main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	//ウィンドウの設定
	glutInitWindowSize(WINDOW_PIXEL_H, WINDOW_PIXEL_V);	//ウィンドウサイズ設定
	glutInitDisplayMode(GLUT_RGBA | GL_DOUBLE);	//ディスプレイモード設定
	glutCreateWindow("Hello GameProgramming");	//ウィンドウ作成
	glClearColor(0.5f, 0.5f, 0.5f, 1.f);	//クリア色をグレーに設定

	//各種関数設定
	glutDisplayFunc(display);	//描画時の関数を指定
	glutReshapeFunc(reshape);	//ウィンドウ変形時の関数を指定
	glutIdleFunc(idle);			//待機時の関数を指定

	//メインループ
	glutMainLoop();

	return;
}

/*ウィンドウサイズ変更時の処理
void reshape(int width, int height)
width:画面幅
height:画面高さ
*/
void reshape(int width, int height) {
	glViewport(0, 0, width, height);	//画面の描画エリアの指定
//	glMatrixMode(GL_PROJECTION);		//行列をプロジェクションモードへ変更
//	gluOrtho2D(-XMAX, XMAX, -YMAX, YMAX);	//画面の座標系を設定
//	gluOrtho2D(-5, 5, -5, 5);	//画面の座標系を設定
	glMatrixMode(GL_MODELVIEW);		//行列をモデルビューモードへ変更
	glLoadIdentity();	//行列を初期化
}

LARGE_INTEGER last_time;	//前回のカウンタ値
//１秒間に６０回描画するように調節する
void idle() {
	LARGE_INTEGER freq;		//一秒当たりのカウンタ数
	LARGE_INTEGER time;		//今回のカウンタ値

	//一秒間のカウンタ数を取得
	QueryPerformanceFrequency(&freq);

	if (last_time.QuadPart == 0) {
		QueryPerformanceCounter(&last_time);
	}
	do{
		//現在のシステムのカウント数を取得
		QueryPerformanceCounter(&time);

		//今のカウント-前回のカウント < 1秒当たりのカウント数を60で割る(1/60秒当たりのカウント数)
	} while (time.QuadPart - last_time.QuadPart < freq.QuadPart / 60);
	last_time = time;

	//描画する関数を呼ぶ
	display();
}
