/*
Result画面
担当者　冨田健斗(ClearResult)
担当者　高橋弘樹(DieResult)
*/

#include  "../Graphic/CRectangle.h"
#include  "../Task/CTask.h"
#include "../Graphic/CStringtexture.h"



#define LOGO_MAX  4
#define NUM_MAX 3



class CResult : public CTask{
private:

	CStringtexture mNumber[NUM_MAX];

	CRectangle mRectEvaluation;
	CRectangle mRectMainLogo;	//ゲームオーバーかゲームクリア
	CRectangle mRectLogo[LOGO_MAX];
	CRectangle mRectFilter;
	CRectangle mRectFrame;
	CRectangle mRectStoryResult;
	CRectangle mRectTitleReturn;

	CTexture *mEvaluationT;
	CTexture *mLogoTex[LOGO_MAX];
	CTexture *mClearLoagoT;
	CTexture *mGameOverLogoT;
	CTexture *mFilterTex;
	CTexture *mFrameTex;
	CTexture *mStoryResultTex;

	///*フェード,フェードアウト,しない簡易シーン管理する*/
	//enum MyFade
	//{
	//	E_FADE, E_FADEOUT, E_NOFADE
	//};
	//MyFade mStarusFade = E_NOFADE;
	/*ロゴの名前*/
	enum MyLogo
	{
		E_KILLS, E_TIME, E_SUM, E_RANK
	};

	char str[NUM_MAX][8];		//NUMBER数 と 格納数
	float Time;					//計測用
	float RectTime;				//四角形のTime
	int mKillPolint;			//倒した数のポイント
	int mTimePoint;				//時間によるPOINT
	bool mFlagDie;
	float mSaveTime;

	void RankDecision(int i); //Clearのランクを決める
	void Die(int i);
	bool FlagCrectA(const CRectangle &rect); //

public:
	static bool mFlagRect; //Resultフラグ
	static float mSaveResultHP;//Result時 HP save
	void Update();
	void Render();
	void Init();
	CResult();
	~CResult();

};
