#include "CClear.h"
#include "../CGame/CGame.h"
#include "../Define/define.h"
#define CONF_TIME_NUM		0.2f, 1.0f, 1.0f, 1.0f, 1.0f		//NUMBERÇÃëÂÇ´Ç≥Ç∆êFê›íË(TIME)
#define CONF_KILLS_NUM		0.2f, 1.0f, 1.0f, 1.0f, 1.0f		//NUMBERÇÃëÂÇ´Ç≥Ç∆êFê›íË(KILLS)
#define CONF_SUM_NUM		0.2f, 1.0f, 1.0f, 1.0f, 1.0f		//NUMBERÇÃëÂÇ´Ç≥Ç∆êFê›íË(SUM)
/*TEXÉTÉCÉY*/
#define T_SIZE_CLEAR		0.0f,0.0f,700.0f,70.0f
#define T_SIZE_SCORESUM		0.0f,0.0f,250.0f,50.0f
#define T_SIZE_CLEARTIME	0.0f,0.0f,250.0f,50.0f
#define T_SIZE_SUMEVAL		0.0f,0.0f,100.0f,50.0f						//ëççáï]âø
#define T_SIZE_SABC			0.0f,0.0f,1200.0f,300.0f						
#define T_SIZE_KILLS		0.0f,0.0f,250.0f,50.0f
#define EVAL_1				300.0f		
#define T_SIZE_S			0.0f,		0.0f,		EVAL_1,				300.0f
#define T_SIZE_A			EVAL_1,		0.0f,		EVAL_1*2.0f,		300.0f
#define T_SIZE_B			EVAL_1*2,	0.0f,		EVAL_1*3.0f,		300.0f
#define T_SIZE_C			EVAL_1*3,	0.0f,		EVAL_1*4.0f,		300.0f
/*éläpÉTÉCÉY*/
#define R_SIZE_STR4			-1.5f,0.5f,1.5f,-0.5f
#define R_SIZE_STR5			-1.0f,0.2f,1.0f,-0.2f
#define R_SIZE_STR6			-1.0f,0.2f,1.2f,-0.2f
#define R_SIZE_SABC			-2.0f,2.0f,2.0f,-2.0f
#define R_SIZE_CLEAR		-5.0f,0.5f,5.0f,-0.5f

#define DOWN_POINT		(int)100
#define TIME_POS		CVector2(CPlayer::camera_x - DISP_X / 3, DISP_Y / 3 - 1.0f)
#define KILLS_POS		CVector2(CPlayer::camera_x - DISP_X / 3, - 1.0f)
#define SUM_POS			CVector2(CPlayer::camera_x - DISP_X / 3,- DISP_Y / 3- 1.0f)

/*éläpÇÃÉ|ÉWÉVÉáÉì*/
#define R_EVAL_POS		CVector2(CPlayer::camera_x +DISP_X/2,  DISP_Y/ 3)
#define R_SABC_POS		CVector2(CPlayer::camera_x +DISP_X/2, -DISP_Y / 4)
#define R_CLEAR_POS		CVector2(CPlayer::camera_x , DISP_Y/2)
#define R_TIME_POS		CVector2(CPlayer::camera_x - DISP_X / 2, DISP_Y / 3- 1.0f)
#define R_KILLS_POS		CVector2(CPlayer::camera_x - DISP_X / 2, 0- 1.0f)
#define R_SUM_POS		CVector2(CPlayer::camera_x - DISP_X / 2,- DISP_Y / 3- 1.0f)
/*ÇbÇkÇdÇ`ÇqSCOREîªíËè„å¿*/
#define SABC_MAX	(ENE00_LIMIT*POINT_00	+	ENE01_LIMIT*POINT_01	+	BOSS_LIMIT*POINT_BOSS)


#define FILE_TEX "../CG\\GameScreen\\"
#include "../Player/CPlayer.h"


CClear::CClear() : mTimePoint(2000),mFlagRect(false){
	mMyNumber = E_CLEAR;
	mPriorityR = E_CLEAR;
	mPriorityU = E_CLEAR;
	/*í«â¡*/
	mEvaluationT= new CTexture();
	mClearLoagoT = new CTexture();
	for (int i = 0; i < LOGO_MAX; i++)
	{
		mLogoTex[i] = new CTexture();
	}
	/*ÉçÅ[Éh*/
	mEvaluationT->load(FILE_TEX"Evaluation.tga");
	mClearLoagoT->load(FILE_TEX"STAG_CLEAR.tga");
	mLogoTex[_TIME_]->load(FILE_TEX"clear_time.tga");
	mLogoTex[_KILLS_]->load(FILE_TEX"Defeated enemy.tga");
	mLogoTex[_SUM_]->load(FILE_TEX"score.tga");
	mLogoTex[_SABC_]->load(FILE_TEX"SABC.tga");
	/*éläpÇçÏÇÈ*/
	mRectClearLogo.SetVertex(R_SIZE_CLEAR);
	mRectClearLogo.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mRectClearLogo.SetUv(mClearLoagoT,T_SIZE_CLEAR);

	mRectEvaluation.SetVertex(R_SIZE_STR4);
	mRectEvaluation.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mRectEvaluation.SetUv(mEvaluationT,T_SIZE_SUMEVAL);

	mRectLogoRect[_TIME_].SetVertex(R_SIZE_STR5);
	mRectLogoRect[_TIME_].SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mRectLogoRect[_TIME_].SetUv(mLogoTex[_TIME_],T_SIZE_CLEARTIME);

	mRectLogoRect[_KILLS_].SetVertex(R_SIZE_STR6);
	mRectLogoRect[_KILLS_].SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mRectLogoRect[_KILLS_].SetUv(mLogoTex[_KILLS_], T_SIZE_KILLS);

	mRectLogoRect[_SUM_].SetVertex(R_SIZE_STR5);
	mRectLogoRect[_SUM_].SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mRectLogoRect[_SUM_].SetUv(mLogoTex[_SUM_],T_SIZE_SCORESUM);

	mRectLogoRect[_SABC_].SetVertex(R_SIZE_SABC);
	mRectLogoRect[_SABC_].SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mRectLogoRect[_SABC_].SetUv(mLogoTex[_SABC_], T_SIZE_SABC);
	

}

CClear::~CClear(){
	
	CGame::Delete(&mEvaluationT);
	CGame::Delete(&mClearLoagoT);
	for (int i = 0; i < LOGO_MAX; i++)
	{
		CGame::Delete(&mLogoTex[i]);
	}
}

void CClear::SABC(int i){ //ìGÇì|Ç∑ëOÇ…ä÷êîÇåƒÇ‘
	if (!mFlagRect){
		if (SABC_MAX * 0.8 <= i){
			mRectLogoRect[_SABC_].SetUv(mLogoTex[_SABC_], T_SIZE_S);
		}
		else if (SABC_MAX * 0.6 <= i){
			mRectLogoRect[_SABC_].SetUv(mLogoTex[_SABC_], T_SIZE_A);
		}
		else if (SABC_MAX * 0.4 <= i){
			mRectLogoRect[_SABC_].SetUv(mLogoTex[_SABC_], T_SIZE_B);
		}
		else{
			mRectLogoRect[_SABC_].SetUv(mLogoTex[_SABC_], T_SIZE_C);
		}
		mFlagRect = true;
	}

}

void CClear::Update(){
	/*éûä‘Ç™ÇΩÇ¬Ç…Ç¬ÇÍìæì_å∏ì_*/
	Time  += 0.1f;
	if (Time >= 60){
		mTimePoint -= DOWN_POINT;
		Time = 0;
	}
	if (mTimePoint <= 0){
		mTimePoint = 0;
	}
	//ï∂éöóÒÇÃê›íË
	sprintf_s(str[_TIME_], "%d", mTimePoint);
	/*ìGÇ™éÄñSÇµÇΩéûÇÃìæì_Çí«â¡*/
	CTask *t; //íTçıóp
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
		};
		t = t->next;
	}
	//ï∂éöóÒÇÃê›íË
	sprintf_s(str[_KILLS_], "%d", mKillPolint);
	sprintf_s(str[_SUM_], "%d", (mKillPolint + mTimePoint));

	mRectClearLogo.position = R_CLEAR_POS;
	mRectEvaluation.position = R_EVAL_POS;
	
	mRectLogoRect[_TIME_].position = R_TIME_POS;
	mRectLogoRect[_KILLS_].position = R_KILLS_POS;
	mRectLogoRect[_SUM_].position = R_SUM_POS;
	mRectLogoRect[_SABC_].position = R_SABC_POS;
	

	
}
void CClear::Render(){
	//ï∂éöóÒÇÃï`âÊ ââèoÇ‹ÇæÅ@

	if (mFlagRect){
		mNumber[_TIME_].render(str[_TIME_], TIME_POS, CONF_TIME_NUM);
		mNumber[_KILLS_].render(str[_KILLS_], KILLS_POS, CONF_KILLS_NUM);
		mNumber[_SUM_].render(str[_SUM_], SUM_POS, CONF_SUM_NUM);

		mRectClearLogo.Render();
		mRectEvaluation.Render();
		for (int i = 0; i < LOGO_MAX; i++)
		{
			mRectLogoRect[i].Render();
		}
	}
}