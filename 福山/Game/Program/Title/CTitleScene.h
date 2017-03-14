#ifndef TITLESCENE_HPP
#define TITLESCENE_HPP

#include "../Define/define.h"
#include "../Title/CTitle.h"
#include"../Map/CMap.h"

class CTitleScene {

public:
	CMap map;
	CTitle title;
	CRectangle mFade;	//アラート表示四角形




	float count;//スクロール演出のため

	int status;

	float FirstX;

	float Save;

	CTitleScene();
	void Init();
	void Update();
	/* 追跡中表示
	*/
	void FadeDisp();
};
#endif