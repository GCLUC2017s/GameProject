#ifndef TITLESCENE_HPP
#define TITLESCENE_HPP

#include "define.h"
#include "CMap.h"
#include "CGoal.h"
#include "CPlayer.h"
#include "CUserInterface.h"
#include "CDownGimmick.h"
#include "CWindmill.h"
#include "CWind.h"
#include "Title.h"

class TitleScene {
public:
	CPlayer mPlayer;
	CMap map;
	Title title;
	CRectangle mFade;	//アラート表示四角形


	TitleScene();

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



	void init();
	void update();
	/* 追跡中表示
	*/
	void FadeDisp();
};
#endif