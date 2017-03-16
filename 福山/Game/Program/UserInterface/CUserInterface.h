#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP
#include "Graphic\CRectangle.h"
#include "Graphic\CTexture.h"

class  CUserinterface
{
public:
	CRectangle  mRect;
	
	CTexture  *mPlayerTex;
	CTexture  *mEnemyTex;

	/*
	自分がどのアニメーションか判断用
	enum文
	*/

	 CUserinterface();
	~ CUserinterface();

	void Init();
	void Update();
	void Render();
};


#endif