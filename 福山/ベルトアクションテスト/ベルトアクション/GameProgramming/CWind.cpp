#include "CWind.h"
#include "CGame.h"
#include <math.h>
#include "CKey.h"
#include "CUserInterface.h"

void CWind::init() {
	for (int i = 0; i < WIND_NUM; i++){
		//四角形の頂点設定
		mRect[i].setVertex(-0.5f, 0.5f, 0.5f, -0.5f);
		//四角形の色を設定
		mRect[i].setColor(1.0f, 1.0f, 1.0f, 1.0f);
	}

	enabled = false;
	ena_mp = true;
	count = 0;
}

CWind::~CWind() {
	if (mpTexture) {
		//テクスチャを使っていればインスタンス削除
		delete mpTexture;
		mpTexture = 0;
	}
}

CWind::CWind() : mpTexture(0){
	for (int i = 0; i < WIND_NUM; i++)
	{
		//四角形の頂点設定
		mRect[i].setVertex(-0.5f, 0.5f, 0.5f, -0.5f);
		//四角形の色を設定
		mRect[i].setColor(1.0f, 1.0f, 1.0f, 1.0f);
	}
}


void CWind::update(CPlayer *pl){
	for (int i = 0; i < WIND_NUM; i++)
	{
		mRect[i].setVertex(-0.5f, 0.5f, 0.5f, -0.5f);
		mPos[i] = pl->mPos + pl->mForward;

	}


	if (CKey::push(VK_RETURN) && ena_mp){
		enabled = true;
		for (int i = 0; i < WIND_NUM; i++)
		{
			if (count > i * 2){
				if (pl->mForward.y == 0.0f && pl->mForward.x != 0.0f){
					hoz_forward = pl->mForward;
					mPos[i] = mPos[i] + hoz_forward*i;
					mRect[i].setVertex(-0.5f, 0.5f + i, 0.5f, -0.5f - i);
				}
				else{
					mPos[i] = mPos[i] + hoz_forward*(i + 1);
					mPos[i].y = mPos[i].y - 1;
					mRect[i].setVertex(-0.5f, 0.5f + i, 0.5f, -0.5f - i);
				}
			}
		}
		count += 1;
		UserInterface::gaugex -= 0.02f;
		if (UserInterface::gaugex < 0.0f){ ena_mp = false; }
	}
	else{
		ena_mp = false;
		count = 0;
		enabled = false;
		if (UserInterface::gaugex < 1.5f){ UserInterface::gaugex += 0.02f; }else{ ena_mp = true; }
	}


	for (int i = 0; i < WIND_NUM; i++)
	{

		mRect[i].position = mPos[i];

	}
};

void CWind::render() {
	if (enabled){
		for (int i = 0; i < WIND_NUM; i++)
		{
			//四角形の描画
			mRect[i].render();
		}
	}
}

void CWind::setPos(CVector2 pos) {

}