#include "CResult.h"
#include "../CGame/CGame.h"
#include "../Define/define.h"
#define STR_SIZE		     0.3f
#define CONF_TIMENUM		 1.0f, 1.0f, 1.0f, mRectLogo[E_TIME].triangle1.a		//NUMBERの大きさと色設定(TIME)
#define CONF_KILLSNUM		 1.0f, 1.0f, 1.0f, mRectLogo[E_KILLS].triangle1.a		//NUMBERの大きさと色設定(KILLS)
#define CONF_SUMNUM		 1.0f, 1.0f, 1.0f, mRectLogo[E_SUM].triangle1.a		//NUMBERの大きさと色設定(E_SUM)
/*TEXサイズ*/
#define T_SIZE_CLEAR		0.0f,0.0f,700.0f,70.0f
#define T_SIZE_GAMEOVER		0.0f,0.0f,750.0f,150.0f			//ゲームオーバー
#define T_SIZE_SCORE_SUM	0.0f,0.0f,250.0f,50.0f
#define T_SIZE_CLEARTIME	0.0f,0.0f,250.0f,50.0f
#define T_SIZE_SUMEVAL		0.0f,0.0f,400.0f,100.0f						//総合評価
#define T_SIZE_RANK			0.0f,0.0f,1200.0f,300.0f						
#define T_SIZE_KILLS		0.0f,0.0f,250.0f,50.0f
#define T_SIZE_FRAME		0.0f,0.0f,500.0f,300.0f
#define T_SIZE_STORYRESULT  0.0f,0.0f,400.0f,150.0f
#define T_SIZE_TITLERETURN  0.0f,0.0f,400.0f,150.0f
#define EVAL_1				300.0f		

#define T_SIZE_S			0.0f,		0.0f,		EVAL_1,				300.0f
#define T_SIZE_A			EVAL_1,		0.0f,		EVAL_1*2.0f,		300.0f
#define T_SIZE_B			EVAL_1*2,	0.0f,		EVAL_1*3.0f,		300.0f
#define T_SIZE_C			EVAL_1*3,	0.0f,		EVAL_1*4.0f,		300.0f
/*四角サイズ*/
#define R_SIZE_STR4			-1.5f,0.5f,1.5f,-0.5f
#define R_SIZE_STR5			-1.0f,0.3f,1.0f,-0.3f
#define R_SIZE_RANK			-2.0f,2.0f,2.0f,-2.0f
#define R_SIZE_CLEAR		-5.0f,0.5f,5.0f,-0.5f
#define R_SIZE_GAMEOVER		-5.0f,0.5f,5.0f,-0.5f
#define R_SIZE_FILTER		-DISP_X,DISP_Y,DISP_X,-DISP_Y
#define R_SIZE_FRAME		-DISP_X,DISP_Y,DISP_X,-DISP_Y
#define R_SIZE_STORYRESULT  -2.0f,0.5f,2.0f,-0.5f
#define R_SIZE_TITLERETURN  -2.0f,0.5f,2.0f,-0.5f

#define DOWN_POINT		(int)100
/*ポジションせってい*/
#define TIME_POS			CVector2(CGame::CameraPos().x - DISP_X / 3, DISP_Y / 3 - 1.0f)
#define KILLS_POS			CVector2(CGame::CameraPos().x - DISP_X / 3, - 1.0f)
#define SUM_POS				CVector2(CGame::CameraPos().x- DISP_X / 3,- DISP_Y / 3-  1.0f)


/*四角のポジション*/
#define R_EVAL_POS		CVector2(CGame::CameraPos().x +DISP_X/2,  DISP_Y/ 3)
#define R_RANK_POS		CVector2(CGame::CameraPos().x +DISP_X/2, -DISP_Y / 4)
#define R_MAIN_POS		CVector2(CGame::CameraPos().x, DISP_Y/1.5f)
#define R_TIME_POS		CVector2(CGame::CameraPos().x- DISP_X / 2, DISP_Y / 3- 1.0f)
#define R_KILLS_POS		CVector2(CGame::CameraPos().x- DISP_X / 2, 0- 1.0f)
#define R_SUM_POS		CVector2(CGame::CameraPos().x- DISP_X / 2,- DISP_Y / 3- 1.0f)
#define R_FILTER_POS	CVector2(CGame::CameraPos().x,0)
#define R_STORYRESULT_POS	CVector2(CGame::CameraPos().x,DISP_Y-1.0f)
#define R_FRAME_POS	    CVector2(CGame::CameraPos().x,0)
/*ＣＬＥＡＲSCORE判定上限*/
#define TIMEMAX		2000
#define RANK_MAX	(ENE00_LIMIT*POINT_00	+	ENE01_LIMIT*POINT_01	+	BOSS_LIMIT*POINT_BOSS	+ TIMEMAX)
/*カラー設定*/
#define COLLAR4_FIRST		1.0f, 1.0f, 1.0f, 0.0f
/*FILTER a上限*/
#define F_ALFMAX	0.4f
#define F_DIEALFMAX	0.5f
/*フェードスピード*/
#define F_SPEEDBASE	0.01f
#define F_SPEEDLOW	0.0001f
#define F_SPEEDHIGH	0.1f
/*タイム時間*/
#define DOWNSCORE_TIME 10 //10秒に一回スコアをダウンさせる
#define FILE_TEX "../CG\\GameScreen\\"
#include "../Player/CPlayer.h"
#include "../Key/CKey.h"
#include "../SceneManager/CSceneManager.h"

bool CResult::mFlagRect;
float CResult::mSaveResultHP;

void CResult::Init(){
	
}

CResult::CResult() : mTimePoint(TIMEMAX), mFlagDie(false){
	mFlagRect = false;
	Time = 0;					//計測用
	RectTime = 0;				//四角形のTime
	mKillPolint = 0;			//倒した数のポイント	
	mSaveTime = 0;

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
	mFrameTex = new CTexture();
	mStoryResultTex = new CTexture();
	/*ロード*/
	mEvaluationT->load(FILE_TEX"Evaluation.tga");
	mClearLoagoT->load(FILE_TEX"STAG_CLEAR.tga");
	mGameOverLogoT->load(FILE_TEX"GAMEOVER.tga");
	mLogoTex[E_TIME]->load(FILE_TEX"clear_time.tga");
	mLogoTex[E_KILLS]->load(FILE_TEX"Defeated enemy.tga");
	mLogoTex[E_SUM]->load(FILE_TEX"score.tga");
	mLogoTex[E_RANK]->load(FILE_TEX"SABC.tga");
	mFrameTex->load(FILE_TEX"clear.tga");
	mStoryResultTex->load(FILE_TEX"StoryResult.tga");

	mFilterTex->load("../CG\\Filter\\filter.tga");
	/*四角を作る*/
	mRectMainLogo.SetVertex(R_SIZE_CLEAR);
	mRectMainLogo.SetColor(COLLAR4_FIRST);
	mRectMainLogo.SetUv(mClearLoagoT, T_SIZE_CLEAR);

	mRectEvaluation.SetVertex(R_SIZE_STR4);
	mRectEvaluation.SetColor(COLLAR4_FIRST);
	mRectEvaluation.SetUv(mEvaluationT,T_SIZE_SUMEVAL);

	mRectLogo[E_TIME].SetVertex(R_SIZE_STR5);
	mRectLogo[E_TIME].SetColor(COLLAR4_FIRST);
	mRectLogo[E_TIME].SetUv(mLogoTex[E_TIME],T_SIZE_CLEARTIME);

	mRectLogo[E_KILLS].SetVertex(R_SIZE_STR5);
	mRectLogo[E_KILLS].SetColor(COLLAR4_FIRST);
	mRectLogo[E_KILLS].SetUv(mLogoTex[E_KILLS], T_SIZE_KILLS);

	mRectLogo[E_SUM].SetVertex(R_SIZE_STR5);
	mRectLogo[E_SUM].SetColor(COLLAR4_FIRST);
	mRectLogo[E_SUM].SetUv(mLogoTex[E_SUM],T_SIZE_SCORE_SUM);

	mRectLogo[E_RANK].SetVertex(R_SIZE_RANK);
	mRectLogo[E_RANK].SetColor(COLLAR4_FIRST);
	mRectLogo[E_RANK].SetUv(mLogoTex[E_RANK], T_SIZE_RANK);

	mRectFilter.SetVertex(R_SIZE_FILTER);
	mRectFilter.SetColor(0.0f, 0.0f, 0.0f, 0.0f);
	mRectFilter.SetUv(mFilterTex, 0,0,10,10);

	mRectFrame.SetVertex(R_SIZE_FRAME);
	mRectFrame.SetColor(COLLAR4_FIRST);
	mRectFrame.SetUv(mFrameTex,T_SIZE_FRAME);

	mRectStoryResult.SetVertex(R_SIZE_STORYRESULT);
	mRectStoryResult.SetColor(COLLAR4_FIRST);
	mRectStoryResult.SetUv(mStoryResultTex, T_SIZE_STORYRESULT);
	

	mRectTitleReturn.SetVertex(R_SIZE_TITLERETURN);
	mRectTitleReturn.SetColor(COLLAR4_FIRST);
	mRectTitleReturn.SetUv(mStoryResultTex, T_SIZE_TITLERETURN);
	
}

CResult::~CResult(){
	
	CGame::Delete(&mEvaluationT);
	CGame::Delete(&mClearLoagoT);
	CGame::Delete(&mGameOverLogoT);
	for (int i = 0; i < LOGO_MAX; i++)
	{
		CGame::Delete(&mLogoTex[i]);
	}
	CGame::Delete(&mFilterTex);
	CGame::Delete(&mFrameTex);
	CGame::Delete(&mStoryResultTex);
}


void CResult::RankDecision(int i){ //bossを倒す前に関数を呼ぶ
	if (!mFlagRect){
		if (RANK_MAX * 0.7 <= i){
			mRectLogo[E_RANK].SetUv(mLogoTex[E_RANK], T_SIZE_S);
		}
		else if (RANK_MAX * 0.5 <= i){
			mRectLogo[E_RANK].SetUv(mLogoTex[E_RANK], T_SIZE_A);
		}
		else if (RANK_MAX * 0.3 <= i){
			mRectLogo[E_RANK].SetUv(mLogoTex[E_RANK], T_SIZE_B);
		}
		else{
			mRectLogo[E_RANK].SetUv(mLogoTex[E_RANK], T_SIZE_C);
		}

			sprintf_s(str[E_TIME], "%d", mTimePoint);
			sprintf_s(str[E_KILLS], "%d", mKillPolint);
			sprintf_s(str[E_SUM], "%d", (mKillPolint + mTimePoint));
		
		CPlayer *pl;
		pl = dynamic_cast<CPlayer*>(CGame::getStatus(E_PLAYER));
		mSaveResultHP = pl->mHitPoint;
	}
	mFlagRect = true;
}

bool CResult::FlagCrectA(const CRectangle &rect){
	if (rect.triangle1.a >= 1.0f){
		return true;
	}
	return false;
}

void CResult::Update(){
	/*時間がたつにつれ得点減点*/
	Time  += DOWNSCORE_TIME / FPS;
	if (Time >= DOWNSCORE_TIME){
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
				RankDecision((mKillPolint + mTimePoint));
			}
			break;
		case E_PLAYER:

			if (b->mHitPoint <= 0 && !b->mEnabledPoint &&!mFlagRect){
				mKillPolint += POINT_PLAYER;
				b->mEnabledPoint = true;
				mFlagDie = true;
				mKillPolint *= 0.1f;
				mTimePoint *= 0.1f;
				RankDecision((mKillPolint + mTimePoint));
			}

			break;
		};
		t = t->next;
	}

	/*演出面*/
	mRectMainLogo.position = R_MAIN_POS;
	mRectEvaluation.position = R_EVAL_POS;
	
	mRectLogo[E_TIME].position = R_TIME_POS;
	mRectLogo[E_KILLS].position = R_KILLS_POS;
	mRectLogo[E_SUM].position = R_SUM_POS;
	mRectLogo[E_RANK].position = R_RANK_POS;
	mRectFilter.position = R_FILTER_POS;
	mRectStoryResult.position = R_STORYRESULT_POS;
	mRectFrame.position = R_FRAME_POS;

	mNumber[E_TIME].render(str[E_TIME], TIME_POS, STR_SIZE, CONF_TIMENUM);
	mNumber[E_KILLS].render(str[E_KILLS], KILLS_POS, STR_SIZE, CONF_KILLSNUM);
	mNumber[E_SUM].render(str[E_SUM], SUM_POS, STR_SIZE, CONF_SUMNUM);

	if (mFlagRect){ //フラグが立った時にフェード開始
		if (mFlagDie){
			mRectMainLogo.SetUv(mGameOverLogoT, T_SIZE_GAMEOVER); 
		}
		CGame::Fade(F_SPEEDBASE, &mRectMainLogo, 1.0f);
		if (FlagCrectA(mRectMainLogo)){					//CLEAR表示で
			if (mFlagDie){
				CGame::Fade(F_SPEEDBASE, &mRectFilter, F_ALFMAX);
				mRectFilter.triangle1.r = 0.2f;
				mRectFilter.triangle2.r = 0.2f;
			}
			else{ CGame::Fade(F_SPEEDBASE, &mRectFilter, F_DIEALFMAX); }
			CGame::Fade(F_SPEEDBASE, &mRectLogo[E_TIME], 1.0f);
			CGame::Fade(F_SPEEDBASE, &mRectFrame, 1.0f);
			CGame::Fade(F_SPEEDBASE, &mRectStoryResult, 1.0f);
		}
		if (FlagCrectA(mRectLogo[E_TIME])){					//時間表示で
			CGame::Fade(F_SPEEDBASE, &mRectLogo[E_KILLS], 1.0f);
		}
		if (FlagCrectA(mRectLogo[E_KILLS])){				//倒した数表示で
			CGame::Fade(F_SPEEDBASE, &mRectLogo[E_SUM], 1.0f);
		}
		if (FlagCrectA(mRectLogo[E_SUM])){					//スコア合計表示で
			CGame::Fade(F_SPEEDBASE, &mRectEvaluation, 1.0f);
		}
		if (FlagCrectA(mRectEvaluation)){					//評価表示で
			CGame::Fade(F_SPEEDBASE, &mRectLogo[E_RANK], 1.0f);
		}


		if (CGame::FlagTime(3, FPS, &mSaveTime)){

			if (FlagCrectA(mRectLogo[E_RANK])){

				CGame::FadeOut(F_SPEEDBASE, &mRectFrame);
				CGame::FadeOut(F_SPEEDBASE, &mRectStoryResult);
				CGame::FadeOut(F_SPEEDBASE, &mRectMainLogo);
				CGame::FadeOut(F_SPEEDBASE, &mRectEvaluation);
				for (int i = 0; i < LOGO_MAX; i++)
				{
					CGame::FadeOut(F_SPEEDBASE, &mRectLogo[i]);
				}

				////エンターキーを押したときにシーンをセレクト画面に替える処理を行う。
				//if (CKey::push(VK_RETURN))
				//{
				//	CTaskManager::GetInstance()->mFlagAllkill = true;
				//	CSceneManager::GetInstance()->ChangeScene(eSceneNo::E_TITLE);
				//}
			}
		}
	}
	
}
void CResult::Render(){
	//文字列の描画 演出まだ　

	mRectFilter.Render();
	if (mFlagRect){
		if (FlagCrectA(mRectLogo[E_TIME]))mNumber[E_TIME].render(str[E_TIME], TIME_POS, STR_SIZE, CONF_TIMENUM);
		if (FlagCrectA(mRectLogo[E_KILLS]))mNumber[E_KILLS].render(str[E_KILLS], KILLS_POS, STR_SIZE, CONF_KILLSNUM);
		if (FlagCrectA(mRectLogo[E_SUM]))mNumber[E_SUM].render(str[E_SUM], SUM_POS, STR_SIZE, CONF_SUMNUM);
		if (!mFlagDie){
			mRectFrame.Render();
			mRectStoryResult.Render();
		}
		mRectMainLogo.Render();
		mRectEvaluation.Render();
		for (int i = 0; i < LOGO_MAX; i++)
		{
				mRectLogo[i].Render(); 
		}
	}
}