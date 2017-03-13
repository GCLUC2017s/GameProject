#include "CDownGimmick.h"
#include "CGame.h"

int CDownGimmick::rowsuu;

void CDownGimmick::init() {
	mpTexture = new CTexture();	//テクスチャクラスのインスタンス作成
	mpTexture->load("足場マップチップ.tga");	//テクスチャファイル読み込み
	mRect_left.setuv(mpTexture, 0, 0, 100, 100);	//テクスチャの使用設定
	mRect_right.setuv(mpTexture, 0, 0, 100, 100);	//テクスチャの使用設定

	//四角形の頂点設定
	mRect_left.setVertex(-0.5f, 0.5f, 0.5f, -0.5f);
	mRect_right.setVertex(-0.5f, 0.5f, 0.5f, -0.5f);

	enabled = false;
	go_enabld = false;
	plusx = 0.0f;
	speed = 0.0f;
	rowsuu = 0;
	  
}

CDownGimmick::~CDownGimmick() {
	if (mpTexture) {
		//テクスチャを使っていればインスタンス削除
		delete mpTexture;
		mpTexture = 0;
	}
}

CDownGimmick::CDownGimmick() : mpTexture(0), speed(0.0f), plusx(0.0f), enabled(false){
	rowsuu = 0;

	//四角形の頂点設定
	mRect_left.setVertex(-0.5f, 0.5f, 0.5f, -0.5f);
	mRect_right.setVertex(-0.5f, 0.5f, 0.5f, -0.5f);
	//四角形の色を設定
	mRect_left.setColor(1.0f, 0.0f, 0.0f, 1.0f);
	mRect_right.setColor(0.0f, 1.0f, 0.0f, 1.0f);

}


void CDownGimmick::update(){


	if (enabled){ //しまっいるとき
		if (CGame::getIndex(hozleftpos) != CGame::getIndex(leftpos)){
			speed -= 0.002f;
			plusx -= speed;
			leftpos.x -= speed;
			rightpos.x += speed;
		}
		else
		{
			leftpos = hozleftpos;
			rightpos = hozrightpos;
			enabled = false;
			go_enabld = false;
		}
	}
	else{ //閉まっていないとき

		if (CGame::getIndex(middlepos) > CGame::getIndex(leftpos)){ //真ん中に行くまで
			speed += 0.002f;
			plusx += speed;
			leftpos.x += speed;
			rightpos.x -= speed;
		}
		else 
		{
			enabled = true;//閉まっている
			if (rowsuu < CGame::mMapRows - 4){ //downgimmick分まで行数カウント
				rowsuu += 1; //ここをカウントしてdowngimmickを増やしている 
				if (rowsuu >= CGame::mMapRows - 4){ //rowsuuが配列数を超えた場合
					rowsuu = CGame::mMapRows - 4;
				}
			}
		}
	}

		mRect_left.position = leftpos;
		mRect_right.position = rightpos;

		mRect_left.setVertex(-0.5f - plusx, 0.5f, 0.5f, -0.5f);
		mRect_right.setVertex(-0.5f, 0.5f, 0.5f + plusx, -0.5f);

};

void CDownGimmick::render() {
	//四角形の描画
	mRect_left.render();
	mRect_right.render();
}

void CDownGimmick::setPos(int row, int col) {

	leftpos = CGame::getPosition(row, col);
	rightpos = CGame::getPosition(row, col + CGame::mMapCols-1);
	middlepos = CGame::getPosition(row, col + CGame::mMapCols / 2);
	hozleftpos = leftpos;
	hozrightpos = rightpos;

	mRect_left.position = leftpos;
	mRect_right.position = rightpos;
}