#pragma once
#include"CBase.h"
#include"CRectangle.h"

class StageSelect :public CBase{
public:

	CRectangle mStageSelect;

	CRectangle mStageView;

	CRectangle mStageSelectRank;

	CRectangle mStageNo0;

	CRectangle mStageNo1;

	CRectangle mStageNo2;
	
	CRectangle mStageNo3;

	CTexture	*mpTexture;

	~StageSelect(){};


	StageSelect(){};
	void init();
	void update();
	void render();
};
