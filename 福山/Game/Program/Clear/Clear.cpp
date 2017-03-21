#include "CClearScene.h"
#include "../CGame/CGame.h"
#include "../Define/define.h"
#define 

CClearScene::CClearScene(){

}

CClearScene::~CClearScene(){
}

void CClearScene::Update(){

}
void CClearScene::Render(){

	//•¶š—ñ‚Ìİ’è
	 sprintf(str, "%d.%d", seisuu, syousuu); 

	//•¶š—ñ‚Ì•`‰æ
	mNumber[__].render(str, CVector2(hoz_pos), 0.6f, 0.7f, 1.0f, 1.0f, 1.0f);
}