#pragma once
#include "GL.h"

class CFont {
private:
 HFONT Hfont;
 HDC Hdc;
public:
	CFont(wchar_t *font = L"�l�r�S�V�b�N", int size=24);
	void Draw(int x,int y,float r,float g,float b,char *str);
	void Release();
};