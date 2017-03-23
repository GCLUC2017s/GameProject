#include"../Title/CTitle.h"
#include"../Graphic/CTexture.h"
#include "../MyNumber/CMyNumber.h"
#include "../CGame/CGame.h"
#define FILE_START	"../CG\\title\\gamestart\\"
#define FILE_TITLE	"../CG\\title\\logo\\"
#define FILE_BERU	"../CG\\title\\title_logo_beru\\"
#define START_X 1600
#define START_Y 800
#define TITLE_X 1600
#define TITLE_Y 400
#define T_BERU_X 800
#define T_BERU_Y 800

//TitleSceneで表示されるテクスチャの設定。
void CBase::AnimeFrame(bool roop, int speed){
	if (roop){
		mFrameCount++;
		if (mFrameCount % speed == 0){
			mAnimeFrame++;

		}
		if (mAnimeFrame >= FRAME_LIMIT || mSaveAnime != mStatus){
			mAnimeFrame = 0;
		}
	}
	else{
		mFrameCount++;
		if (mFrameCount % speed == 0){
			mAnimeFrame++;
		}
		if (mAnimeFrame >= FRAME_LIMIT){
			mAnimeFrame = FRAME_LIMIT - 1; //テクスチャの最大値 = FRAME_LIMITなので ー１
		}
	}

	mSaveAnime = mStatus;
}
void CTitle::Init(){

	//ゲームタイトルを表示
	mpTitleLogo = new CTexture();	//テクスチャクラスのインスタンス作成
	mpTitleLogo->load(FILE_TITLE"title_logo.tga");	//テクスチャファイル読み込み
    mTitleLogo.SetUv(mpTitleLogo, 0, 0, TITLE_X, TITLE_Y);//TGA上の座標

    mpPleaseKey = new CTexture();	//テクスチャクラスのインスタンス作成
	mpPleaseKey->load(FILE_START"title_gamestart.tga");	//テクスチャファイル読み込み
	mPleaseKey.SetUv(mpPleaseKey, 0, 0, START_X, START_Y);//TGA上の座標

	for (int i = 0; i < FRAME_BERU; i++)
	{
		mTexBeru[i] = new CTexture();
	}

	mTexBeru[0]->load(FILE_BERU"title_logo_beru_00.tga");
	mTexBeru[1]->load(FILE_BERU"title_logo_beru_01.tga");
	mTexBeru[2]->load(FILE_BERU"title_logo_beru_02.tga");
	mTexBeru[3]->load(FILE_BERU"title_logo_beru_03.tga");
	mTexBeru[4]->load(FILE_BERU"title_logo_beru_04.tga");
	mTexBeru[5]->load(FILE_BERU"title_logo_beru_05.tga");
	mTexBeru[6]->load(FILE_BERU"title_logo_beru_06.tga");
	mTexBeru[7]->load(FILE_BERU"title_logo_beru_07.tga");
	mTexBeru[8]->load(FILE_BERU"title_logo_beru_08.tga");
	mBeru.SetUv(mTexBeru[0], 0, 0, T_BERU_X, T_BERU_Y);
	

}
CTitle::~CTitle(){
	if (mpTexture){
		delete mpTexture;
		mpTexture = 0;
	}

	CGame::Delete(mTexBeru);
	
}
CTitle::CTitle() : mpTexture(0){
	mMyNumber = E_MTITLE;
	mPriorityR = E_MTITLE;
	mPriorityU = E_MTITLE;

	mTitleLogo.SetVertex(-5.0f, 2.0f, 5.0, -1.0f);//表示範囲
	mTitleLogo.SetColor(1.0f, 1.0f, 1.0f, 1.0f);//色味
	mPleaseKey.SetVertex(-3.0f, -2.0f, 3.0f, -5.0f);//表示範囲
	mPleaseKey.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mPleaseKey.SetVertex(-3.0f, -2.0f, 3.0f, -5.0f);//表示範囲
	mPleaseKey.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mBeru.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mBeru.SetVertex(-5.0f, 5.0f, 5.0f, -5.0f);//表示範囲

}
void CTitle::Update(){

};
void CTitle::Render(CVector2 pos) {


	mTitleLogo.position = pos;
	mTitleLogo.position.y = DISP_Y / 5;

	mPleaseKey.position = pos;
	mPleaseKey.position.y = DISP_Y / 20;

	mBeru.position = CVector2(pos.x +3,pos.y+2.5f);

	mBeru.Render();
	mTitleLogo.Render();
	mPleaseKey.Render();
}
