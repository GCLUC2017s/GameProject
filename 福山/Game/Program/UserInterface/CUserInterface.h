#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP
#include "../Graphic/CRectangle.h"
#include "../Graphic/CTexture.h"
#include "../Task/CTask.h"
#include "../Define/define.h"

class  CUserinterface : public CTask
{
private:

	CRectangle  mGaugePl;
	CRectangle  mFramePl;

	CRectangle mGaugeEne;
	CRectangle mFrameEne;

	CTexture  *mPlayerGageTex;
	CTexture  *mPlyerFrameTex;

	CTexture  *mEnemyGageTex;
	CTexture  *mEnemyFrameTex;

	CVector2 mPos;
	float savex;

	const float area_x = MAP_LIMIT_X / 2;
	

public:
	/*
	自分がどのアニメーションか判断用
	enum文
	*/

	 CUserinterface();
	~ CUserinterface();

	void Update();
	void Render();
};


#endif