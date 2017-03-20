#include  "../Graphic/CRectangle.h"
#include  "../Task/CTask.h"
#include "../Graphic/CStringtexture.h"
#define _KILLS_	0
#define _TIME_	1
#define _SUM_	2
#define _SABC_	3

#define LOGO_MAX  4
#define NUM_MAX 3



class CClear  : public CTask{
private:
	CStringtexture mNumber[NUM_MAX];

	CRectangle mRectEvaluation;
	CRectangle mRectClearLogo;
	CRectangle mRectLogo[LOGO_MAX];

	CTexture *mEvaluationT;
	CTexture *mLogoTex[LOGO_MAX];
	CTexture *mClearLoagoT;

	char str[NUM_MAX][8];		//NUMBER�� �� �i�[��
	float Time;					//�v���p
	float RectTime;				//�l�p�`��Time
	int mKillPolint;			//�|�������̃|�C���g
	int mTimePoint;				//���Ԃɂ��POINT
	bool mFlagRect;				
	bool *mFlagEval;			//�]���t���O�Ǘ�
	void SABC(int i);
	bool FlagCrectA(const CRectangle &rect); //

public:
	void Update();
	void Render();

	CClear();
	~CClear();

};
