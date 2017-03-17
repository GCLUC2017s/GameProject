#include"../Title/CTitle.h"
#include"../Graphic/CTexture.h"
#include "../MyNumber/CMyNumber.h"

//TitleSceneで表示されるテクスチャの設定。

void CTitle::Init(){

	//ゲームタイトルを表示
	mpTitleLogo = new CTexture();	//テクスチャクラスのインスタンス作成
	mpTitleLogo->load("gameTitle.tga");	//テクスチャファイル読み込み
	
		 mTitleLogo.SetUv(mpTitleLogo, 0, 0, 640, 480);//TGA上の座標

		 mpPleaseKey = new CTexture();	//テクスチャクラスのインスタンス作成
		 mpPleaseKey->load("gameTitle.tga");	//テクスチャファイル読み込み
	
		mPleaseKey.SetUv(mpPleaseKey, 0, 0, 640, 480);//TGA上の座標

	

}
CTitle::~CTitle(){
	if (mpTexture){
		delete mpTexture;
		mpTexture = 0;
	}
}
CTitle::CTitle() : mpTexture(0){
	mMyNumber = E_TITLE;
	mPriorityR = E_TITLE;
	mPriorityU = E_TITLE;

	mTitleLogo.SetVertex(-7.0f, 2.0f, 2.0, -1.0f);//表示範囲
	mTitleLogo.SetColor(1.0f, 1.0f, 1.0f, 1.0f);//色味

	mPleaseKey.SetVertex(-5.0f, -2.0f, 0.0f, -3.0f);//表示範囲
	mPleaseKey.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

}
void CTitle::Update(){

};
void CTitle::Render(CVector2 pos) {


	mTitleLogo.position = pos;
	mTitleLogo.position.y = DISP_Y / 5;

	mPleaseKey.position = pos;
	mPleaseKey.position.y = DISP_Y / 20;

	mTitleLogo.Render();
	mPleaseKey.Render();
}
