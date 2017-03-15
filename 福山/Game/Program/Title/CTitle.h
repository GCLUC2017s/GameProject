#pragma once
#include"../Base/CBase.h"
#include"../Graphic/CRectangle.h"
#include"../Map/CMap.h"
#include "../Task/CTask.h"

class CTitle :public CTask{
private:

	CRectangle mTitleLogo;
	CRectangle mPleaseKey;
	CTexture	*mpTexture;
	CTexture	*mpTitleLogo;
	CTexture	*mpPleaseKey;

public:

	~CTitle();

	CTitle();
	void Init();
	void Update();

	void Render(CVector2 pos);


};
