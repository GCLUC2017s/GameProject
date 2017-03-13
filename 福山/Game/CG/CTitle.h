#pragma once
#include"CBase.h"
#include"CRectangle.h"
#include"CMap.h"

class CTitle :public CBase{
public:

	CRectangle mTitleLogo;
	CRectangle mPleaseKey;
	CTexture	*mpTexture;
	CTexture	*mpTitleLogo;
	CTexture	*mpPleaseKey;


	~CTitle();

	CTitle();
	void Init();
	void Update();

	void Render(CVector2 pos);


};
