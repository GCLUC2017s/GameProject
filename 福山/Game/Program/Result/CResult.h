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



class CClear  : public CTask{
private:
	CStringtexture mNumber[NUM_MAX];

	CRectangle mRectEvaluation;
	CRectangle mRectMainLogo;	//ゲームオーバーかゲームクリア
	CRectangle mRectLogo[LOGO_MAX];
	CRectangle mRectFilter;

	CTexture *mEvaluationT;
	CTexture *mLogoTex[LOGO_MAX];
	CTexture *mClearLoagoT;
	CTexture *mGameOverLogoT;
	CTexture *mFilterTex;
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
	bool mFlagRect;				
	bool mFlagDie;
	bool *mFlagEval;			//評価フラグ管理
	void RankDecision(int i); //Clearのランクを決める
	void Die(int i);
	bool FlagCrectA(const CRectangle &rect); //

public:
	void Update();
	void Render();

	CClear();
	~CClear();

};
