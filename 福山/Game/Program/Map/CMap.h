/**/
#ifndef MAP_HPP
#define MAP_HPP
#include "../Define/define.h"
#include "../Graphic/CRectangle.h"
#include <stdio.h>
#include "../Base/CBase.h"


class CMap :public CTask{
private:
	CRectangle mGround;			//”wŒi‚Ì’n–Ê
	CRectangle mSky;		//‹ó
	CRectangle mTree;		//–Ø

	CTexture *mGroundTex; //”wŒi‚ÌƒeƒNƒXƒ`ƒƒ
	CTexture *mSkyTex;
	CTexture *mTreeTex;

public:
	~CMap();
	CMap();

	void Init();
	void Update();
	void Render();
};
#endif