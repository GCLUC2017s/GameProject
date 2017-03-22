/*
タイトルクラス
担当者　高橋弘樹 && 冨田健斗
*/
#pragma once
#include"../Base/CBase.h"
#include"../Graphic/CRectangle.h"
#include"../Map/CMap.h"
#include "../Task/CTask.h"

class CTitle :public CTask{
public:

	CRectangle mTitleLogo;
	CRectangle mPleaseKey;
	CTexture	*mpTexture;
	CTexture	*mpTitleLogo;
	CTexture	*mpPleaseKey;


	~CTitle();

	CTitle();
	void Init();
	void Update();

	void Render(CVector2 pos);


};
