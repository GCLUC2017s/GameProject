#include "CGoal.h"
#include "CGame.h"

void CGoal::init() {
	mpTexture = new CTexture();	//テクスチャクラスのインスタンス作成
	mpTexture->load("tobira.tga");	//テクスチャファイル読み込み
	mRect.setuv(mpTexture, 0, 0, 100, 100);	//テクスチャの使用設定
}

CGoal::~CGoal() {
	if (mpTexture) {
		//テクスチャを使っていればインスタンス削除
		delete mpTexture;
		mpTexture = 0;
	}
}

CGoal::CGoal() : mpTexture(0) {
	//四角形の頂点設定
	mRect.setVertex(-0.5f, 0.5f, 0.5f, -0.5f);
	//四角形の色を設定
	mRect.setColor(1.0f, 1.0f, 1.0f, 1.0f);
}


void CGoal::update(){
	mRect.position = mPos;
};

void CGoal::render() {
	//四角形の描画
	if (mEnabled == true){ mRect.render(); }
}

void CGoal::setPos(int row, int col) {
	mPos = CGame::getPosition(row, col);
}