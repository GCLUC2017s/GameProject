#include "CTitleScene.h"
#include "../Key/CKey.h"


CTitleScene::CTitleScene() :status(0), Alerttop(0.0f), Alertbottom(0.0f), Alertenabled(true){}

void CTitleScene::Init() {


	status = 0;
	FirstX = -MAP_LIMIT_X / 2.5;

}

void CTitleScene::Update() {


		FirstX += 0.02f;

}



/* alertDisp
�ǐՃ��[�h�̎��ɂ́A��ʂɐԂ݂�t����
*/
void CTitleScene::FadeDisp() {

	mFade.Render();

}