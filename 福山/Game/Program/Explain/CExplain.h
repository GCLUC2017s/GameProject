#ifndef CEXPLAIN_HPP
#define CEXPLAIN_HPP

#include"../Base/CBase.h"
#include"../Graphic/CRectangle.h"
#include "../Task/CTask.h"

class CExplain :public CTask{
public:

	CRectangle mText1;
	CRectangle mText2;
	CRectangle mText3;
	CRectangle mTextBox;
	CRectangle mBackBlack;

	CTexture	*mpTexture;

	CTexture	*mpText1;
	CTexture	*mpText2;
	CTexture	*mpText3;
	CTexture	*mpTextBox;

	int pattern;	//現在どういう状況か？　タイトルか説明か
	int textpattern;
	bool patternflag;

	~CExplain();

	CExplain();
	void Init();
	void Update();

	void Render(CVector2 pos);
};
#endif