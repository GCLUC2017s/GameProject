#include "CMap.h"
#include  <Windows.h>
#include "../Define/define.h"
#include "../MyNumber/CMyNumber.h"
#define FIRST_R_NO_BG -100 //背景のレンダー初期設定
#define FIRST_U_NO_BG -100 //背景のアップデータ初期設定
#define FILE_BG_GROUND		"../CG/background/ground/"
#define FILE_BG_SKY			"../CG/background/sky/"
#define FILE_BG_TREE		"../CG/background/tree/"
#define BG_SIZE_X 1600
#define BG_SIZE_Y 400


void CMap::Init() {
	mGroundTex = new CTexture;
	mSkyTex = new CTexture;
	mTreeTex = new CTexture;

	mGroundTex->load(FILE_BG_GROUND"ground_background.tga");
	mSkyTex->load(FILE_BG_SKY"sky_background.tga");
	mTreeTex->load(FILE_BG_TREE"background_tree.tga");

	const float area_top = MAP_LIMIT_Y / 8;
	const float area_bottom = -MAP_LIMIT_Y / 2;
	const float area_x = MAP_LIMIT_X / 2;

	mGround.SetVertex(-area_x, area_top, area_x, area_bottom);
	mGround.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mGround.SetUv(mGroundTex, 0, 0, BG_SIZE_X, BG_SIZE_Y);

	mSky.SetVertex(-area_x, area_top, area_x, area_bottom);
	mSky.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mSky.SetUv(mSkyTex, 0, 0, BG_SIZE_X, BG_SIZE_Y);
	
	mTree.SetVertex(-area_x, area_top, area_x, area_bottom);
	mTree.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mTree.SetUv(mTreeTex, 0, 0, BG_SIZE_X, BG_SIZE_Y);


}

CMap::~CMap() {
	if (mGroundTex){
		delete mGroundTex;
		mGroundTex = 0;
	}

}
CMap::CMap() :mGroundTex(0) {
	
		mPriorityR = E_BACKGROWND;		//レンダー順番の初期設定
		mPriorityU = E_BACKGROWND;		//アップデータ順番の初期設定
		mMyNumber = E_BACKGROWND;		//属性の設定
	
}



void CMap::Update() {

}

/* render
マップの四角形を描画する
*/

void CMap::Render() {
	mGround.Render();
	mSky.Render();
	mTree.Render();
}