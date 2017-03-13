#pragma once
#include"CBase.h"
#include"CRectangle.h"

class CGameover :public CBase{
public:

	CRectangle gameover;

	CTexture	*mpTexture;

	~CGameover(){};


	CGameover(){};
	void init();
	void update();
	void render();
};
