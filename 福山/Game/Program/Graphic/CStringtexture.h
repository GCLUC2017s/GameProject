/*
数字専門の文字プログラム

冨田健斗
*/
#ifndef STRINGTEX_HPP
#define STRINGTEX_HPP
#include"CTexture.h"
#include "../Vector/CVector2.h"

class CStringtexture{
public:
	CTexture* mPtexture;
	CStringtexture();
	~CStringtexture();
	
	void render(char* pstr, CVector2 pos, float size, float r, float g, float b, float a);
};
#endif 