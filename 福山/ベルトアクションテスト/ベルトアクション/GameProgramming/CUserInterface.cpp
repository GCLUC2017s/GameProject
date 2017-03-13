#include "CUserInterface.h"
#include "CGame.h"

float UserInterface::gaugex;

void UserInterface::init() {

	tex_suuzi = new CTexture();	//テクスチャクラスのインスタンス作製
	tex_suuzi->load("数字.tga");

	tex_moji = new CTexture();	//テクスチャクラスのインスタンス作成
	tex_moji->load("時間制限.tga");	//テクスチャファイル読み込み
	mRect_moji.setuv(tex_moji, 0, 0, 1000, 200);	//テクスチャの使用設定

	tex_window = new CTexture();
	tex_window->load("ゲージ.tga");
	mRect_window.setuv(tex_window, 0, 0, 900, 300);
	
	tex_push = new CTexture();
	tex_push->load("PushKey.tga");
	mRect_push.setuv(tex_push, 0, 0, 400, 300);

	//四角形の頂点設定
	mRect_push.setVertex(-CGame::mDispCols/2.5f, CGame::mDispRows/2.5f,CGame::mDispRows/2.5f, -CGame::mDispCols /2.5f);
	//四角形の色を設定
	mRect_push.setColor(1.0f, 1.0f, 1.0f, 1.0f);

	ena_push = false;
	gaugex = 1.5f;
	strtex = tex_suuzi;
	seisuu = MAX_COUNT;
	syousuu = 0;
	size = 1.0f;

}

UserInterface::~UserInterface() {
	if (mpTexture) {
		//テクスチャを使っていればインスタンス削除
		delete mpTexture;
		mpTexture = 0;
	}
}
UserInterface::UserInterface() : mpTexture(0),seisuu(MAX_COUNT),syousuu(0),size(0.5f){
	gaugex = 1.5f;
	//四角形の頂点設定
	ena_push = false;
	mRect_moji.setVertex(-1.3f, 0.7f, 1.3f, -0.7f);
	//四角形の色を設定
	mRect_moji.setColor(0.8f, 1.0f, 1.0f, 1.0f);

	//四角形の頂点設定
	mRect_window.setVertex(-1.5f, 0.5f, 1.5f, -0.5f);
	//四角形の色を設定
	mRect_window.setColor(1.0f, 1.0f, 1.0f, 1.0f);	

	//四角形の頂点設定
	mRect_gauge.setVertex(-gaugex, 0.5f, gaugex, -0.5f);
	//四角形の色を設定
	mRect_gauge.setColor(0.0f, 0.8f, 0.0f, 1.0f);


}


void UserInterface::update(){
	if (syousuu == 0){	seisuu -= 1;}
	if (syousuu <= 0){	syousuu = 60;}
	if (seisuu < 0)  {	seisuu = MAX_COUNT;}
	syousuu -= 1;
};

void UserInterface::render(CVector2 pos) {
	CVector2 hoz_pos = CVector2(pos.x - 3.5f,pos.y - 1.0f);//保存用&&調整用
	
	//文字列の設定
	if (syousuu >= 10){sprintf(str, "%d.%d", seisuu, syousuu);}
	else{			   sprintf(str, "%d.0%d", seisuu,syousuu);}

	if(seisuu == 10){	mRect_moji.position = CVector2(hoz_pos.x + 1, hoz_pos.y + 0.35f);}
	else{				mRect_moji.position = CVector2(hoz_pos.x , hoz_pos.y + 0.35f);}
	//文字列の描画
	strtex.render(str, CVector2(hoz_pos), 0.6f, 0.7f, 1.0f, 1.0f, 1.0f);
	mRect_moji.render();
	mRect_window.position = hoz_pos;
	mRect_window.position.x = -CGame::mDispCols / 3;
	mRect_gauge.position = CVector2(mRect_window.position.x+gaugex-1.5f,mRect_window.position.y  );
	mRect_gauge.setVertex(-gaugex, 0.5f, gaugex, -0.5f);
	mRect_gauge.render();
	mRect_window.render();
	if (ena_push){
		mRect_push.render();
	}


}

void UserInterface::setPos(int row, int col) {

}