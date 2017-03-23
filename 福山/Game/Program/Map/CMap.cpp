#include "CMap.h"
#include  <Windows.h>
#include "../Define/define.h"
#include "../MyNumber/CMyNumber.h"
#include "../Player/CPlayer.h"
#include  "../CGame/CGame.h"
#define FILE_BG_GROUND		"../CG\\background\\ground\\"
#define FILE_BG_SKY			"../CG\\background\\sky\\"
#define FILE_BG_TREE		"../CG\\background/tree\\"

#define TEX_SIZE_TREE_X 3200
#define TEX_SIZE_TREE_Y 2400

#define TEX_SIZE_SKY_X 1400
#define TEX_SIZE_SKY_Y 600

#define TEX_SIZE_GROWND_X 800
#define TEX_SIZE_GROWND_Y 200

#define SC_SPEED 0.5f

/*現在調整中*/

void CMap::Init() {

	mGroundTex = new CTexture();
	
	mSkyTex = new CTexture();
	mTreeTex = new CTexture();

	mGroundTex->load(FILE_BG_GROUND"ground_background.tga");
	mSkyTex->load(FILE_BG_SKY"sky_background.tga");
	mTreeTex->load(FILE_BG_TREE"tree_background.tga");

	mSky.SetVertex(-DISP_X, DISP_Y, DISP_X*10, 0);
	mSky.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mSky.SetUv(mSkyTex, 0, 0, TEX_SIZE_SKY_X, TEX_SIZE_SKY_Y);
	

	for (int i = 0; i < TREE_MAX; i++)
	{

		mGround[i].SetVertex(-DISP_X, 0, DISP_X, character_limit_bottom);
		mGround[i].SetColor(1.0f, 1.0f, 1.0f, 1.0f);
		mGround[i].SetUv(mGroundTex, 0, 0, TEX_SIZE_GROWND_X, TEX_SIZE_GROWND_Y);
		mGround[i].position.x = first_pos.x + (DISP_X * 2)* i;
		mTree[i].SetVertex(-DISP_X, DISP_Y, DISP_X, -0);
		mTree[i].SetColor(1.0f, 1.0f, 1.0f, 1.0f);
		mTree[i].SetUv(mTreeTex, 0, 0, TEX_SIZE_TREE_X, TEX_SIZE_TREE_Y);
		mTree[i].position.x = first_pos.x + (DISP_X * 2)* i;

		
	}

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
	mSky.SetUv(mSkyTex, mLeftSc, 0, mRightSc, TEX_SIZE_SKY_Y);
}

/* render
マップの四角形を描画する
*/

void CMap::Render() {
	mSky.Render();
	for (int i = 0; i < TREE_MAX; i++){
		mTree[i].Render();
		mTree[i].Render();
		mGround[i].Render();

	}

}