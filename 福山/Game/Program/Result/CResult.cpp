#include "CResult.h"
#include "../CGame/CGame.h"
#include "../Define/define.h"
#define STR_SIZE		     0.3f
#define CONF_TIME_NUM		 1.0f, 1.0f, 1.0f, mRectLogo[_TIME_].triangle1.a		//NUMBERの大きさと色設定(TIME)
#define CONF_KILLS_NUM		 1.0f, 1.0f, 1.0f, mRectLogo[_KILLS_].triangle1.a		//NUMBERの大きさと色設定(KILLS)
#define CONF_SUM_NUM		 1.0f, 1.0f, 1.0f, mRectLogo[_SUM_].triangle1.a		//NUMBERの大きさと色設定(SUM)
/*TEXサイズ*/
#define T_SIZE_CLEAR		0.0f,0.0f,700.0f,70.0f
#define T_SIZE_GAMEOVER		0.0f,0.0f,693.0f,143.0f			//ゲームオーバー
#define T_SIZE_SCORESUM		0.0f,0.0f,250.0f,50.0f
#define T_SIZE_CLEARTIME	0.0f,0.0f,250.0f,50.0f
#define T_SIZE_SUMEVAL		0.0f,0.0f,100.0f,50.0f						//総合評価
#define T_SIZE_SABC			0.0f,0.0f,1200.0f,300.0f						
#define T_SIZE_KILLS		0.0f,0.0f,250.0f,50.0f
#define EVAL_1				300.0f		
#define T_SIZE_S			0.0f,		0.0f,		EVAL_1,				300.0f
#define T_SIZE_A			EVAL_1,		0.0f,		EVAL_1*2.0f,		300.0f
#define T_SIZE_B			EVAL_1*2,	0.0f,		EVAL_1*3.0f,		300.0f
#define T_SIZE_C			EVAL_1*3,	0.0f,		EVAL_1*4.0f,		300.0f
/*四角サイズ*/
#define R_SIZE_STR4			-1.5f,0.5f,1.5f,-0.5f
#define R_SIZE_STR5			-1.0f,0.2f,1.0f,-0.2f
#define R_SIZE_STR6			-1.0f,0.2f,1.2f,-0.2f
#define R_SIZE_SABC			-2.0f,2.0f,2.0f,-2.0f
#define R_SIZE_CLEAR		-5.0f,0.5f,5.0f,-0.5f
#define R_SIZE_GAMEOVER		-5.0f,0.5f,5.0f,-0.5f
#define R_SIZE_FILTER		-DISP_X,DISP_Y,DISP_X,-DISP_Y
#define DOWN_POINT		(int)100
#define TIME_POS		CVector2(CGame::CameraPos().x - DISP_X / 3, DISP_Y / 3 - 1.0f)
#define KILLS_POS		CVector2(CGame::CameraPos().x - DISP_X / 3, - 1.0f)
#define SUM_POS			CVector2(CGame::CameraPos().x- DISP_X / 3,- DISP_Y / 3- 1.0f)

/*四角のポジション*/
#define R_EVAL_POS		CVector2(CGame::CameraPos().x +DISP_X/2,  DISP_Y/ 3)
#define R_SABC_POS		CVector2(CGame::CameraPos().x +DISP_X/2, -DISP_Y / 4)
#define R_CLEAR_POS		CVector2(CGame::CameraPos().x, DISP_Y/2)
#define R_GAMEOVER_POS		CVector2(CGame::CameraPos().x, DISP_Y/2)
#define R_TIME_POS		CVector2(CGame::CameraPos().x- DISP_X / 2, DISP_Y / 3- 1.0f)
#define R_KILLS_POS		CVector2(CGame::CameraPos().x- DISP_X / 2, 0- 1.0f)
#define R_SUM_POS		CVector2(CGame::CameraPos().x- DISP_X / 2,- DISP_Y / 3- 1.0f)
#define R_FILTER_POS	CVector2(CGame::CameraPos().x,0)
/*ＣＬＥＡＲSCORE判定上限*/
#define TIMEMAX		2000
#define SABC_MAX	(ENE00_LIMIT*POINT_00	+	ENE01_LIMIT*POINT_01	+	BOSS_LIMIT*POINT_BOSS	+ TIMEMAX - POINT_PLAYER)
/*カラー設定*/
#define COLLAR4_FIRST		1.0f, 1.0f, 1.0f, 0.0f
/*FILTER a上限*/
#define F_ALFMAX	0.4f
/*フェードスピード*/
#define F_SPEEDBASE	0.01f
#define F_SPEEDLOW	0.0001f
#define F_SPEEDHIGH	0.1f
#define FILE_TEX "../CG\\GameScreen\\"
#include "../Player/CPlayer.h"

CClear::CClear() : mTimePoint(TIMEMAX),mFlagRect(false),mFlagDie(false){
	mMyNumber = E_CLEAR;
	mPriorityR = E_CLEAR;
	mPriorityU = E_CLEAR;
	/*追加*/
	mEvaluationT= new CTexture();
	mClearLoagoT = new CTexture();
	mGameOverLogoT = new CTexture();
	for (int i = 0; i < LOGO_MAX; i++)
	{
		mLogoTex[i] = new CTexture();
	}
	mFilterTex = new CTexture();
	/*ロード*/
	mEvaluationT->load(FILE_TEX"Evaluation.tga");
	mClearLoagoT->load(FILE_TEX"STAG_CLEAR.tga");
	mGameOverLogoT->load(FILE_TEX"GAME_OVER.tga");
	mLogoTex[_TIME_]->load(FILE_TEX"clear_time.tga");
	mLogoTex[_KILLS_]->load(FILE_TEX"Defeated enemy.tga");
	mLogoTex[_SUM_]->load(FILE_TEX"score.tga");
	mLogoTex[_SABC_]->load(FILE_TEX"SABC.tga");
	mFilterTex->load("../CG\\Filter\\filter.tga");
	/*四角を作る*/
	mRectClearLogo.SetVertex(R_SIZE_CLEAR);
	mRectClearLogo.SetColor(COLLAR4_FIRST);
	mRectClearLogo.SetUv(mClearLoagoT,T_SIZE_CLEAR);

	mRectGameOver.SetVertex(R_SIZE_GAMEOVER);
	mRectGameOver.SetColor(COLLAR4_FIRST);
	mRectGameOver.SetUv(mGameOverLogoT, T_SIZE_GAMEOVER);

	mRectEvaluation.SetVertex(R_SIZE_STR4);
	mRectEvaluation.SetColor(COLLAR4_FIRST);
	mRectEvaluation.SetUv(mEvaluationT,T_SIZE_SUMEVAL);

	mRectLogo[_TIME_].SetVertex(R_SIZE_STR5);
	mRectLogo[_TIME_].SetColor(COLLAR4_FIRST);
	mRectLogo[_TIME_].SetUv(mLogoTex[_TIME_],T_SIZE_CLEARTIME);

	mRectLogo[_KILLS_].SetVertex(R_SIZE_STR6);
	mRectLogo[_KILLS_].SetColor(COLLAR4_FIRST);
	mRectLogo[_KILLS_].SetUv(mLogoTex[_KILLS_], T_SIZE_KILLS);

	mRectLogo[_SUM_].SetVertex(R_SIZE_STR5);
	mRectLogo[_SUM_].SetColor(COLLAR4_FIRST);
	mRectLogo[_SUM_].SetUv(mLogoTex[_SUM_],T_SIZE_SCORESUM);

	mRectLogo[_SABC_].SetVertex(R_SIZE_SABC);
	mRectLogo[_SABC_].SetColor(COLLAR4_FIRST);
	mRectLogo[_SABC_].SetUv(mLogoTex[_SABC_], T_SIZE_SABC);

	mRectFilter.SetVertex(R_SIZE_FILTER);
	mRectFilter.SetColor(0.0f, 0.0f, 0.0f, 0.0f);
	mRectFilter.SetUv(mFilterTex, 0,0,10,10);
	
}

CClear::~CClear(){
	
	CGame::Delete(&mEvaluationT);
	CGame::Delete(&mClearLoagoT);
	CGame::Delete(&mGameOverLogoT);
	for (int i = 0; i < LOGO_MAX; i++)
	{
		CGame::Delete(&mLogoTex[i]);
	}
	CGame::Delete(&mFilterTex);
}

void CClear::SABC(int i){ //bossを倒す前に関数を呼ぶ
	if (!mFlagRect){
		if (SABC_MAX * 0.7 <= i){
			mRectLogo[_SABC_].SetUv(mLogoTex[_SABC_], T_SIZE_S);
		}
		else if (SABC_MAX * 0.5 <= i){
			mRectLogo[_SABC_].SetUv(mLogoTex[_SABC_], T_SIZE_A);
		}
		else if (SABC_MAX * 0.3 <= i){
			mRectLogo[_SABC_].SetUv(mLogoTex[_SABC_], T_SIZE_B);
		}
		else{
			mRectLogo[_SABC_].SetUv(mLogoTex[_SABC_], T_SIZE_C);
		}
		sprintf_s(str[_TIME_], "%d", mTimePoint);
		sprintf_s(str[_KILLS_], "%d", mKillPolint);
		sprintf_s(str[_SUM_], "%d", (mKillPolint + mTimePoint));
	}
	mFlagRect = true;
}


void CClear::Die(int i){//キャラが死ぬ前に関数を呼ぶ
	if (!mFlagDie){
		if (SABC_MAX * 0.8 <= i){
			mRectLogo[_SABC_].SetUv(mLogoTex[_SABC_], T_SIZE_S);
		}
		else if (SABC_MAX * 0.6 <= i){
			mRectLogo[_SABC_].SetUv(mLogoTex[_SABC_], T_SIZE_A);
		}
		else if (SABC_MAX * 0.4 <= i){
			mRectLogo[_SABC_].SetUv(mLogoTex[_SABC_], T_SIZE_B);
		}
		else{
			mRectLogo[_SABC_].SetUv(mLogoTex[_SABC_], T_SIZE_C);
		}
		sprintf_s(str[_TIME_], "%d", mTimePoint);
		sprintf_s(str[_KILLS_], "%d", mKillPolint);
		sprintf_s(str[_SUM_], "%d", (mKillPolint + mTimePoint));
	}
	mFlagDie = true;
}



bool CClear::FlagCrectA(const CRectangle &rect){
	if (rect.triangle1.a >= 1.0f){
		return true;
	}
	return false;
}

void CClear::Update(){
	/*時間がたつにつれ得点減点*/
	Time  += 0.1f;
	if (Time >= 60){
		mTimePoint -= DOWN_POINT;
		Time = 0;
	}
	if (mTimePoint <= 0){
		mTimePoint = 0;
	}
	//文字列の設定
	/*敵が死亡した時の得点を追加*/
	CTask *t; //探索用
	t = CTaskManager::GetInstance()->mRoot;
	while (t != 0)
	{
		CBase *b = (CBase*)t;
		switch (t->mMyNumber)
		{
		case E_ENEMY00:;
			if (b->mHitPoint <= 0 && !b->mEnabledPoint){
				mKillPolint += POINT_00; 
				b->mEnabledPoint = true; 
			} 
			break;
		case E_ENEMY01:
			if (b->mHitPoint <= 0 && !b->mEnabledPoint){ 
				mKillPolint += POINT_01;
				b->mEnabledPoint = true;
			}
			break;
		case E_BOSS:
			if (b->mHitPoint <= 0 && !b->mEnabledPoint){ 
				mKillPolint += POINT_BOSS;
				b->mEnabledPoint = true;
				SABC((mKillPolint + mTimePoint));
			}
			break;
		case E_PLAYER:

			if (b->mHitPoint <= 0 && !b->mEnabledPoint &&!mFlagRect){
				mKillPolint += POINT_PLAYER;
				b->mEnabledPoint = true;
				Die((mKillPolint + mTimePoint));
			}

			break;
		};
		t = t->next;
	}

	/*演出面*/
	mRectClearLogo.position = R_CLEAR_POS;
	mRectGameOver.position = R_GAMEOVER_POS;
	mRectEvaluation.position = R_EVAL_POS;
	
	mRectLogo[_TIME_].position = R_TIME_POS;
	mRectLogo[_KILLS_].position = R_KILLS_POS;
	mRectLogo[_SUM_].position = R_SUM_POS;
	mRectLogo[_SABC_].position = R_SABC_POS;
	mRectFilter.position = R_FILTER_POS;

	mNumber[_TIME_].render(str[_TIME_], TIME_POS, STR_SIZE, CONF_TIME_NUM);
	mNumber[_KILLS_].render(str[_KILLS_], KILLS_POS, STR_SIZE, CONF_KILLS_NUM);
	mNumber[_SUM_].render(str[_SUM_], SUM_POS, STR_SIZE, CONF_SUM_NUM);

	if (mFlagRect){ //フラグが立った時にフェード開始
		CGame::Fade(F_SPEEDBASE, &mRectClearLogo,1.0f);
		if (FlagCrectA(mRectClearLogo)){					//CLEAR表示で
			CGame::Fade(F_SPEEDBASE, &mRectFilter, F_ALFMAX);
			CGame::Fade(F_SPEEDBASE, &mRectLogo[_TIME_], 1.0f);
		}
		if (FlagCrectA(mRectLogo[_TIME_])){					//時間表示で
			CGame::Fade(F_SPEEDBASE, &mRectLogo[_KILLS_], 1.0f);
		}
		if (FlagCrectA(mRectLogo[_KILLS_])){				//倒した数表示で
			CGame::Fade(F_SPEEDBASE, &mRectLogo[_SUM_], 1.0f);
		}
		if (FlagCrectA(mRectLogo[_SUM_])){					//スコア合計表示で
			CGame::Fade(F_SPEEDBASE, &mRectEvaluation, 1.0f);
		}
		if (FlagCrectA(mRectEvaluation)){					//評価表示で
			CGame::Fade(F_SPEEDBASE, &mRectLogo[_SABC_], 1.0f);
		}
	}
	if (mFlagDie){ //フラグが立った時にフェード開始
		CGame::Fade(F_SPEEDBASE, &mRectGameOver, 1.0f);
		if (FlagCrectA(mRectGameOver)){					//CLEAR表示で
			CGame::Fade(F_SPEEDBASE, &mRectFilter, F_ALFMAX);
			CGame::Fade(F_SPEEDBASE, &mRectLogo[_TIME_], 1.0f);
		}
		if (FlagCrectA(mRectLogo[_TIME_])){					//時間表示で
			CGame::Fade(F_SPEEDBASE, &mRectLogo[_KILLS_], 1.0f);
		}
		if (FlagCrectA(mRectLogo[_KILLS_])){				//倒した数表示で
			CGame::Fade(F_SPEEDBASE, &mRectLogo[_SUM_], 1.0f);
		}
		if (FlagCrectA(mRectLogo[_SUM_])){					//スコア合計表示で
			CGame::Fade(F_SPEEDBASE, &mRectEvaluation, 1.0f);
		}
		if (FlagCrectA(mRectEvaluation)){					//評価表示で
			CGame::Fade(F_SPEEDBASE, &mRectLogo[_SABC_], 1.0f);
		}
	}
	
	
}
void CClear::Render(){
	//文字列の描画 演出まだ　

	mRectFilter.Render();
	if (mFlagRect){
		if (FlagCrectA(mRectLogo[_TIME_]))mNumber[_TIME_].render(str[_TIME_], TIME_POS, STR_SIZE, CONF_TIME_NUM);
		if (FlagCrectA(mRectLogo[_KILLS_]))mNumber[_KILLS_].render(str[_KILLS_], KILLS_POS, STR_SIZE, CONF_KILLS_NUM);
		if (FlagCrectA(mRectLogo[_SUM_]))mNumber[_SUM_].render(str[_SUM_], SUM_POS, STR_SIZE, CONF_SUM_NUM);
		
		mRectClearLogo.Render();
		mRectEvaluation.Render();
		for (int i = 0; i < LOGO_MAX; i++)
		{
				mRectLogo[i].Render(); 
		}
	}
	if (mFlagDie && !mFlagRect){
		if (FlagCrectA(mRectLogo[_KILLS_]))mNumber[_KILLS_].render(str[_KILLS_], KILLS_POS, STR_SIZE, CONF_KILLS_NUM);
		if (FlagCrectA(mRectLogo[_SUM_]))mNumber[_SUM_].render(str[_SUM_], SUM_POS, STR_SIZE, CONF_SUM_NUM);

		mRectGameOver.Render();
		mRectEvaluation.Render();
		for (int i = 0; i < LOGO_MAX; i++)
		{
			mRectLogo[i].Render();
		}
	}





}