#include "CMap.h"
#include  <Windows.h>
#include "../Define/define.h"
#include "../MyNumber/CMyNumber.h"
#include "../Player/CPlayer.h"
#include  "../CGame/CGame.h"
#define FIRST_R_NO_BG -100 //背景のレンダー初期設定
#define FIRST_U_NO_BG -100 //背景のアップデータ初期設定
#define FILE_BG_GROUND		"../CG/background/ground/"
#define FILE_BG_SKY			"../CG/background/sky/"
#define FILE_BG_TREE		"../CG/background/tree/"
#define BG_SIZE_X 1600
#define BG_SIZE_Y 400
#define SC_SPEED 0.5f



void CMap::Init() {
	mGroundTex = new CTexture;
	mSkyTex = new CTexture;
	mTreeTex = new CTexture;

	mGroundTex->load(FILE_BG_GROUND"ground_background.tga");
	mSkyTex->load(FILE_BG_SKY"sky_background.tga");
	mTreeTex->load(FILE_BG_TREE"background_tree.tga");

	mGround.SetVertex(-DISP_X, 0, DISP_X*10,character_limit_bottom);
	mGround.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mGround.SetUv(mGroundTex, 0, 0, BG_SIZE_X, BG_SIZE_Y);

	mSky.SetVertex(-DISP_X, DISP_Y, DISP_X*10, 0);
	mSky.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mSky.SetUv(mSkyTex, 0, 0, BG_SIZE_X, BG_SIZE_Y);
	
	mTree.SetVertex(-DISP_X, DISP_Y, DISP_X*10, -0);
	mTree.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mTree.SetUv(mTreeTex, 0, 0, BG_SIZE_X, BG_SIZE_Y);

	mGround.position.x = first_pos.x;
	mTree.position.x = first_pos.x;
	mSky.position.x = first_pos.x;

}

CMap::~CMap() {
	CGame::Delete(&mGroundTex);
	CGame::Delete(&mSkyTex);
	CGame::Delete(&mTreeTex);
}
CMap::CMap() :mGroundTex(0),mFlagSc(false),mLeftSc(0),mRightSc(BG_SIZE_X){
	
		mPriorityR = E_BACKGROWND;		//レンダー順番の初期設定
		mPriorityU = E_BACKGROWND;		//アップデータ順番の初期設定
		mMyNumber = E_BACKGROWND;		//属性の設定
	
}



void CMap::Update() {
	if (mFlagSc){
		mRightSc += SC_SPEED;
		mLeftSc += SC_SPEED;
		if (mRightSc >= BG_SIZE_X){
			mLeftSc = 0;
			mRightSc = BG_SIZE_X;
			mFlagSc = false;
		}
	}
	else{
		mRightSc += SC_SPEED;
		mLeftSc += SC_SPEED;
		if (mLeftSc >= BG_SIZE_X){
			mLeftSc = BG_SIZE_X;
			mRightSc = 0;
			mFlagSc = true;
		}
	}
	mSky.SetUv(mSkyTex, mLeftSc, 0, mRightSc, BG_SIZE_Y);
}

/* render
マップの四角形を描画する
*/

void CMap::Render() {
	mSky.Render();
	mTree.Render();
	mGround.Render();

}