#ifndef MAP_HPP
#define MAP_HPP
#include "../Define/define.h"
#include "../Graphic/CRectangle.h"
#include <stdio.h>
#include "../Base/CBase.h"

class CMap :public CBase{
public:
	CRectangle BGrect; //”wŒi‚Ìrect
	CTexture *BackGround;


	~CMap();
	CMap();

	void Init();
	void Update();
	void Render();
};
#endif