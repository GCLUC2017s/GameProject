#pragma once
#include"CBase.h"
#include"CRectangle.h"
#include"CMap.h"

class Title :public CBase{
public:

	CRectangle mTitleLogo;
	CRectangle mPleaseKey;
	CTexture	*mpTexture;
	CTexture	*mpTitleLogo;
	CTexture	*mpPleaseKey;


	~Title();

	Title();
	void init();
	void update();

	void render(CVector2 pos);

	void setPos(int row, int col);

};
