#include"../Title/CTitle.h"
#include"../Graphic/CTexture.h"
#include "../MyNumber/CMyNumber.h"
#define FILE_START	"../CG\\title\\gamestart\\"
#define FILE__TITLE	"../CG\\title\\logo\\"
#define START_X 1600
#define START_Y 800
#define TITLE_X 1600
#define TITLE_Y 400

//TitleSceneで表示されるテクスチャの設定。

void CTitle::Init(){

	//ゲームタイトルを表示
	mpTitleLogo = new CTexture();	//テクスチャクラスのインスタンス作成
	mpTitleLogo->load(FILE__TITLE"title_logo.tga");	//テクスチャファイル読み込み
	
		 mTitleLogo.SetUv(mpTitleLogo, 0, 0, TITLE_X, TITLE_Y);//TGA上の座標

		 mpPleaseKey = new CTexture();	//テクスチャクラスのインスタンス作成
		 mpPleaseKey->load(FILE_START"title_gamestart.tga");	//テクスチャファイル読み込み
	
		mPleaseKey.SetUv(mpPleaseKey, 0, 0, START_X, START_Y);//TGA上の座標

	

}
CTitle::~CTitle(){
	if (mpTexture){
		delete mpTexture;
		mpTexture = 0;
	}
}
CTitle::CTitle() : mpTexture(0){
	mMyNumber = E_MTITLE;
	mPriorityR = E_MTITLE;
	mPriorityU = E_MTITLE;

	mTitleLogo.SetVertex(-5.0f, 2.0f, 5.0, -1.0f);//表示範囲
	mTitleLogo.SetColor(1.0f, 1.0f, 1.0f, 1.0f);//色味

	mPleaseKey.SetVertex(-3.0f, -2.0f, 3.0f, -5.0f);//表示範囲
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
