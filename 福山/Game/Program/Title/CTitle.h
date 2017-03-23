/*
タイトルクラス
担当者　高橋弘樹 && 冨田健斗
*/
#ifndef TITLE_HPP
#define TITLE_HPP
#include"../Base/CBase.h"
#include"../Graphic/CRectangle.h"
#include"../Map/CMap.h"
#include "../Task/CTask.h"
#define FRAME_BERU 9

class CTitle :public CTask{
public:

	CRectangle mTitleLogo;
	CRectangle mPleaseKey;
	CRectangle mBeru;
	CTexture	*mpTexture;
	CTexture	*mpTitleLogo;
	CTexture	*mpPleaseKey;
	CTexture	*mTexBeru[FRAME_BERU];

	~CTitle();
	CTitle();
	void Init();
	void Update();
	void Render(CVector2 pos);


};
#endif
