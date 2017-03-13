#include"CText.h"

void CText::init() {
	mpTexture = new CTexture();	//テクスチャクラスのインスタンス作成
	mpTexture->load("GAMECLEAR.tga");	//テクスチャファイル読み込み
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320.0f, 320.0f, -240.0f, 240.0f);
	mRect.setuv(mpTexture, 0, 0, 670, 480);	//テクスチャの使用設定
}
CText::~CText() {
	if (mpTexture) {
		//テクスチャを使っていればインスタンス削除
		delete mpTexture;
		mpTexture = 0;
	}
}

CText::CText() : mpTexture(0) {
	//四角形の頂点設定
	mRect.setVertex(-5.0f, 4.0f, 5.0f, -4.0f);
	//四角形の色を設定
	mRect.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	mEnabled = false;
}

void CText::update(){
	mRect.position = mPos;
};

void CText::render() {
	//四角形の描画
	if (mEnabled==true){

		mRect.render();
	}
	
}

void CText::setPos(int row, int col) {
	mPos = CGame::getPosition(row, col);
}