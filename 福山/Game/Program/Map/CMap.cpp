#include "CMap.h"
#include  <Windows.h>
#include "../Define/define.h"
#include "../MyNumber/CMyNumber.h"
#define FIRST_R_NO_BG -100 //背景のレンダー初期設定
#define FIRST_U_NO_BG -100 //背景のアップデータ初期設定

void CMap::Init() {
	BackGround = new CTexture;

	BackGround->load("../CG\\background\\ground\\ground_background.tga");

	const float area_top = MAP_LIMIT_Y / 8;
	const float area_bottom = -MAP_LIMIT_Y / 2;
	const float area_x = MAP_LIMIT_X / 2;

	BGrect.SetVertex(-area_x, area_top, area_x, area_bottom);
	BGrect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	BGrect.SetUv(BackGround,0,0,1600,400);



}

CMap::~CMap() {
	if (BackGround){
		delete BackGround;
		BackGround = 0;
	}

}
CMap::CMap() : BackGround(0) {
	
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
	BGrect.Render();
}