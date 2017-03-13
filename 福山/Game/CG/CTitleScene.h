#ifndef TITLESCENE_HPP
#define TITLESCENE_HPP

#include "define.h"
#include "CTitle.h"

class CTitleScene {
public:
	CMap map;
	CTitle title;
	CRectangle mFade;	//アラート表示四角形


	CTitleScene();

	//追跡モード時の演出
	int  mAlertCnt;		//アラート制御用カウンタ
	int  mAlertLevel;	//アラート表示用データ
	bool Alertenabled;


	float Alertbottom, Alerttop;
	float count;//スクロール演出のため
	float save_player_x; //保存用

	int status;

	float FirstX;

	float Save;



	void Init();
	void Update();
	/* 追跡中表示
	*/
	void FadeDisp();
};
#endif