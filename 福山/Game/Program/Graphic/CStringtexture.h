#pragma once
#include"../Graphic/CTexture.h"
#include"../Vector/CVector2.h"

class CStringtexture{
public:
	CTexture* ptexture;
	CStringtexture() :ptexture(0){}
	CStringtexture(CTexture* pt) :ptexture(pt){}
	
	void render(char* pstr, CVector2 pos, float size, float r, float g, float b, float a);
};