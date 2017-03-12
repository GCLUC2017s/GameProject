#include "CGameMain.h"
#include "define.h"
#include <Windows.h>
#define JUMP_FIRST_SPEED 0.2
#define ENEMYE_ARRAY_SIZE 10 //エネミー数
#define PLAYER_ARRAY_SIZE 10 //プレイヤー数

CGameMain gamemain;

/* display関数
1秒間に60回実行される
*/
void display() {
	//画面のクリア
	glClear(GL_COLOR_BUFFER_BIT);
	gamemain.Update();
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
	glutCreateWindow("はらぺこのベル");	//ウィンドウ作成
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
