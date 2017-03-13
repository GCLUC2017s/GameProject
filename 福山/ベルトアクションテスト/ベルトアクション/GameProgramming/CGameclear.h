#pragma once
#include"CBase.h"
#include"CRectangle.h"

class CGameclear :public CBase{
public:

	CRectangle clear;

	CTexture	*mpTexture;

	~CGameclear(){};


	CGameclear(){};
	void init();
	void update();
	void render();
};
