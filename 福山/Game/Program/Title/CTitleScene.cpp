#include "CTitleScene.h"
#include "../Key/CKey.h"


CTitleScene::CTitleScene() :status(0){}

void CTitleScene::Init() {


	status = 0;
	FirstX = -MAP_LIMIT_X / 2.5;

}

void CTitleScene::Update() {


		FirstX += 0.02f;

}



/* alertDisp
追跡モードの時には、画面に赤みを付ける
*/
void CTitleScene::FadeDisp() {

	mFade.Render();

}