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
#define TEX_SIZE_TREE_X 3200
#define TEX_SIZE_TREE_Y 2400

#define TEX_SIZE_SKY_X 1600
#define TEX_SIZE_SKY_Y 800

#define TEX_SIZE_GROWND_X 1600
#define TEX_SIZE_GROWND_Y 400
#define SC_SPEED 0.5f



void CMap::Init() {
	mGroundTex = new CTexture;
	mSkyTex = new CTexture;
	mTreeTex = new CTexture;

	mGroundTex->load(FILE_BG_GROUND"background_ground.tga");
	mSkyTex->load(FILE_BG_SKY"sky_background.tga");
	mTreeTex->load(FILE_BG_TREE"tree_background.tga");

	mGround.SetVertex(-DISP_X, 0, DISP_X*10,character_limit_bottom);
	mGround.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mGround.SetUv(mGroundTex, 0, 0, TEX_SIZE_GROWND_X, TEX_SIZE_GROWND_Y);

	mSky.SetVertex(-DISP_X, DISP_Y, DISP_X*10, 0);
	mSky.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mSky.SetUv(mSkyTex, 0, 0, TEX_SIZE_SKY_X, TEX_SIZE_SKY_X);
	
	for (int i = 0; i < TREE_NUM; i++)
	{
		mTree[i].SetVertex(-DISP_X, DISP_Y, DISP_X, -0);
		mTree[i].SetColor(1.0f, 1.0f, 1.0f, 1.0f);
		mTree[i].SetUv(mTreeTex, 0, 0, TEX_SIZE_TREE_X, TEX_SIZE_TREE_Y);
		mTree[i].position.x = first_pos.x + (DISP_X * 2)* i;
		printf("%f\n", mTree[i].position.x);

	}

	mGround.position.x = first_pos.x;
	mSky.position.x = first_pos.x;

}

CMap::~CMap() {
	CGame::Delete(&mGroundTex);
	CGame::Delete(&mSkyTex);
	CGame::Delete(&mTreeTex);
}
CMap::CMap() :mGroundTex(0), mFlagSc(false), mLeftSc(0), mRightSc(TEX_SIZE_GROWND_X){
	
		mPriorityR = E_BACKGROWND;		//レンダー順番の初期設定
		mPriorityU = E_BACKGROWND;		//アップデータ順番の初期設定
		mMyNumber = E_BACKGROWND;		//属性の設定
	
}



void CMap::Update() { //雲を動かす処理
	if (mFlagSc){
		mRightSc += SC_SPEED;
		mLeftSc += SC_SPEED;
		if (mRightSc >= TEX_SIZE_GROWND_X){
			mLeftSc = 0;
			mRightSc = TEX_SIZE_GROWND_X;
			mFlagSc = false;
		}
	}
	else{
		mRightSc += SC_SPEED;
		mLeftSc += SC_SPEED;
		if (mLeftSc >= TEX_SIZE_GROWND_X){
			mLeftSc = TEX_SIZE_GROWND_X;
			mRightSc = 0;
			mFlagSc = true;
		}
	}
	mSky.SetUv(mSkyTex, mLeftSc, 0, mRightSc, TEX_SIZE_GROWND_Y);
}

/* render
マップの四角形を描画する
*/

void CMap::Render() {
	mSky.Render();
	for (int i = 0; i < TREE_NUM; i++)
	{
		mTree[i].Render();
	}
	mGround.Render();

}