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



class CClear  : public CTask{
private:
	CStringtexture mNumber[NUM_MAX];

	CRectangle mRectEvaluation;
	CRectangle mRectMainLogo;	//�Q�[���I�[�o�[���Q�[���N���A
	CRectangle mRectLogo[LOGO_MAX];
	CRectangle mRectFilter;

	CTexture *mEvaluationT;
	CTexture *mLogoTex[LOGO_MAX];
	CTexture *mClearLoagoT;
	CTexture *mGameOverLogoT;
	CTexture *mFilterTex;
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
	bool mFlagRect;				
	bool mFlagDie;
	bool *mFlagEval;			//�]���t���O�Ǘ�
	void RankDecision(int i); //Clear�̃����N�����߂�
	void Die(int i);
	bool FlagCrectA(const CRectangle &rect); //

public:
	void Update();
	void Render();

	CClear();
	~CClear();

};
