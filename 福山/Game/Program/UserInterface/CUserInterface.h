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
	�������ǂ̃A�j���[�V���������f�p
	enum��
	*/

	 CUserinterface();
	~ CUserinterface();

	void Init();
	void Update();
	void Render();
};


#endif