#include"Title.h"
#include"CTexture.h"
#include"CGame.h"

//TitleSceneで表示されるテクスチャの設定。

void Title::init(){

	//ゲームタイトルを表示
	mpTitleLogo = new CTexture();	//テクスチャクラスのインスタンス作成
	mpTitleLogo->load("gameTitle.tga");	//テクスチャファイル読み込み
	//glMatrixMode(GL_PROJECTION);	
	//glLoadIdentity();
	//	 gluOrtho2D(-300.0f, 300.0f, 100.0f, 200.0f);

		 mTitleLogo.setuv(mpTitleLogo, 0, 0, 640, 480);//TGA上の座標

		 mpPleaseKey = new CTexture();	//テクスチャクラスのインスタンス作成
		 mpPleaseKey->load("gameTitle.tga");	//テクスチャファイル読み込み
	//	 glMatrixMode(GL_PROJECTION);
//		 glLoadIdentity();

	//	gluOrtho2D(-120.0f, 140.0f, 120.0f, -140.0f);
		mPleaseKey.setuv(mpPleaseKey, 0, 0, 640, 480);//TGA上の座標

	

}
Title::~Title(){
	if (mpTexture){
		delete mpTexture;
		mpTexture = 0;
	}
}
Title::Title() : mpTexture(0){
	mTitleLogo.setVertex(-7.0f, 2.0f, 2.0, -1.0f);//表示範囲
	mTitleLogo.setColor(1.0f, 1.0f, 1.0f, 1.0f);//色味

	mPleaseKey.setVertex(-5.0f, -2.0f, 0.0f, -3.0f);//表示範囲
	mPleaseKey.setColor(1.0f, 1.0f, 1.0f, 1.0f);

}
void Title::update(){

};
void Title::render(CVector2 pos) {
	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	
	gluOrtho2D(-320.0f, 320.0f, -240.0f, 240.0f);*/

	mTitleLogo.position = pos;
	mTitleLogo.position.y = CGame::mDispCols / 5;

	mPleaseKey.position = pos;
	mPleaseKey.position.y = CGame::mDispCols / 20;

	mTitleLogo.render();
	mPleaseKey.render();
}

void Title::setPos(int row, int col) {

}
