#pragma once
#include "define.h"
#include "CRectangle.h"
#include <stdio.h>
#include "CBase.h"

class CMap :public CBase{
public:

	CRectangle BGrect; //�w�i��rect
	CTexture *BackGround;

	~CMap();
	CMap();

	void Init();
	void Update();
	void Render();
};