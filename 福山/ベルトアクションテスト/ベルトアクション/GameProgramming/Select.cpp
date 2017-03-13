#include"Select.h"
#include"CTexture.h"

void StageSelect::init(){
	//ゲームタイトルを表示
	mpTexture = new CTexture();	//テクスチャクラスのインスタンス作成
	mpTexture->load("gameTitle.tga");	//テクスチャファイル読み込み
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-300.0f, 300.0f, 100.0f, 200.0f);
	mStageNo0.setVertex(-300.0f, 200.0f, 300.0, 100.0f);//表示範囲
	mStageNo0.setColor(1.0f, 1.0f, 1.0f, 1.0f);//色味
	mStageNo0.setuv(mpTexture, 0, 0, 640, 480);//TGA上の座標


	//押してほしいキーを表示する。
	mpTexture = new CTexture();	//テクスチャクラスのインスタンス作成
	mpTexture->load("gameTitle.tga");	//テクスチャファイル読み込み
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-120.0f, 140.0f, 120.0f, -140.0f);
	mStageNo1.setVertex(-200.0f, -100.0f, 200.0f, -200.0f);//表示範囲
	mStageNo1.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	mStageNo1.setuv(mpTexture, 0, 0, 640, 480);//TGA上の座標



	//押してほしいキーを表示する。
	mpTexture = new CTexture();	//テクスチャクラスのインスタンス作成
	mpTexture->load("gameTitle.tga");	//テクスチャファイル読み込み
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-120.0f, 140.0f, 120.0f, -140.0f);
	mStageNo2.setVertex(-200.0f, -100.0f, 200.0f, -200.0f);//表示範囲
	mStageNo2.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	mStageNo2.setuv(mpTexture, 0, 0, 640, 480);//TGA上の座標




}



void StageSelect::update(){
	render();
};
void StageSelect::render() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320.0f, 320.0f, -240.0f, 240.0f);
	mStageNo0.render();
	mStageNo1.render();
	mStageNo2.render();
}