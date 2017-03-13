#include "CWindmill.h"
#include "CGame.h"
#include <math.h>

void CWindmill::init() {
	mpTexture = new CTexture();	//テクスチャクラスのインスタンス作成
	mpTexture->load("風車.tga");	//テクスチャファイル読み込み
	mRect_spin.degree = 0;
	//四角形の頂点
	mRect_rod.setuv(mpTexture, 0, 200, 200, 400);	//テクスチャの使用設定
	mRect_spin.setuv(mpTexture, 0, 0, 200, 200);	//テクスチャの使用設定
}

CWindmill::~CWindmill() {
	if (mpTexture) {
		//テクスチャを使っていればインスタンス削除
		delete mpTexture;
		mpTexture = 0;
	}
}

CWindmill::CWindmill() : mpTexture(0){
	mRect_spin.degree = 0;
	//四角形の頂点設定
	mRect_rod.setVertex(-0.5f, 0.0f, 0.5f, -2.0f);
	mRect_spin.setVertex(-1.0f, 1.0f, 1.0f, -1.0f);
	//四角形の色を設定
	mRect_rod.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	mRect_spin.setColor(1.0f, 1.0f, 1.0f, 1.0f);
}


void CWindmill::update(){
	mRect_rod.position = mPos;
	mRect_spin.position = mPos;

 	mRect_spin.degree -= 5;
	mRect_spin.degree %= 360;

};

void CWindmill::render() {
	//四角形の描画
	mRect_rod.render();
	mRect_spin.render();
}

void CWindmill::setPos(int row, int col) {
	mPos = CGame::getPosition(row, col);
	mRect_rod.position = mPos;
	mRect_spin.position = mPos;

}