/*
”šê–å‚Ì•¶šƒvƒƒOƒ‰ƒ€

•y“cŒ’“l
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