#pragma once
#include "GL.h"

class CFont {
private:
 HFONT Hfont;
 HDC Hdc;
public:
	CFont(wchar_t *font = L"HG�ۃS�V�b�NM-PRO", int size=24);
	void Draw(int x,int y,float r,float g,float b,char *str);
	void Release();
};