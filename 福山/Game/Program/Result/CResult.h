/*
Result���
�S���ҁ@�y�c���l(ClearResult)
�S���ҁ@�����O��(DieResult)
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
	CRectangle mRectMainLogo;	//�Q�[���I�[�o�[���Q�[���N���A
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
	/*���S�̖��O*/
	enum MyLogo
	{
		E_KILLS, E_TIME, E_SUM, E_RANK
	};

	char str[NUM_MAX][8];		//NUMBER�� �� �i�[��
	float Time;					//�v���p
	float RectTime;				//�l�p�`��Time
	int mKillPolint;			//�|�������̃|�C���g
	int mTimePoint;				//���Ԃɂ��POINT
	bool mFlagDie;
	float mSaveTime;

	void RankDecision(int i); //Clear�̃����N�����߂�
	void Die(int i);
	bool FlagCrectA(const CRectangle &rect); //

public:
	static bool mFlagRect; //Result�t���O
	static float mSaveResultHP;//Result�� HP save
	void Update();
	void Render();
	void Init();
	CResult();
	~CResult();

};
