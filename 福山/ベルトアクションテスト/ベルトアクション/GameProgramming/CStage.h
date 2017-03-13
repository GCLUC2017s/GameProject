#include "define.h"
#include "CMap.h"
#include "CGoal.h"
#include "CPlayer.h"
#include "CUserInterface.h"
#include "CDownGimmick.h"
#include "CWindmill.h"
#include "CWind.h"
#include "Title.h"
#include"Enemy.h"

class CStage {
public:
	CPlayer mPlayer;
	CMap map;
	Title title;
	Enemy00 mEnemy00;

	CStage();

	//追跡モード時の演出
	int  mAlertCnt;		//アラート制御用カウンタ
	int  mAlertLevel;	//アラート表示用データ
	CRectangle mAlert;	//アラート表示四角形
	bool Alertenabled;


	float Alertbottom, Alerttop;
	float count;//スクロール演出のため
	float first_y; //初めのスクロールのため
	float hoz_y; //ゴールで少し止まるための変数
	float save_player_x; //保存用

	int status;

	float FirstX;

	float Save;



	void init();
	void update();
	/* 追跡中表示
	*/
	void alertDisp();
};
