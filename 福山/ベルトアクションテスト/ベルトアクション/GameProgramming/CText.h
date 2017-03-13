# pragma once
#include "CRectangle.h"

class CText{
public:
	CRectangle mRect;

	CTexture	*mpTexture;
	~CText();
	
	CText();
	void init();
	void update();
	void render();
	void setPos(int row, int col);
	
};